#include "systray.h"
#include "ui_systray.h"
#include "qcustomplot.h"



systray::systray(QWidget *parent)
:QWidget(parent),
ui(new Ui::systray){
    QRect rec = QApplication::desktop()->screenGeometry();
    this->move(rec.width()-this->width()/2,rec.height()/2-this->height());
    ui->setupUi(this);
    txf=fopen("/sys/class/net/wlan0/statistics/tx_bytes","r");
    fscanf(txf,"%lld",&tx2);
    rxf=fopen("/sys/class/net/wlan0/statistics/rx_bytes","r");
    fscanf(rxf,"%lld",&rx2);
    tx1=tx2; rx1=rx2; txMax=0; rxMax=0;
    icon = new QSystemTrayIcon(this);
    icon->setIcon(QIcon("downloadIcon.png"));
    menu = new QMenu(this);
    kapat=new QAction(this);
    kapat->setText("kapat");
    connect(kapat, SIGNAL(triggered()), this, SLOT(kapatiyoruz()));
    menu->addAction(kapat);
    connect(icon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(foo()));
    icon->setContextMenu(menu);
    on_top=false;
    icon->show();
    for (int i=0; i<101; ++i){
      x.push_back(i);
      y1.append(0);
      y2.append(0);
    }
    FILE* best=fopen("best","r");
    fscanf(best,"%lf %lf %lf %lf %lf",&bestDown,&bestUp,&txt,&rxt,&kota);
    fclose(best);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(refresh()));
    timer->start(1000);
    uyarmadik=true;
}

void systray::foo(){
    if(on_top){
        this->hide();
    }else{
        refresh();
        this->show();
    }
    on_top = !on_top;
}

void systray::refresh(){
    //Read data
    txf=fopen("/sys/class/net/wlan0/statistics/tx_bytes","r");
    rxf=fopen("/sys/class/net/wlan0/statistics/rx_bytes","r");
    fscanf(rxf,"%lld",&rx2);
    fscanf(txf,"%lld",&tx2);
    double rx= (double) (rx2-rx1) / KILO;
    double tx= (double) (tx2-tx1) / KILO;
    txMax=MAX(txMax,tx);
    rxMax=MAX(rxMax,rx);
    bestDown=MAX(bestDown,rxMax);
    bestUp=MAX(bestUp,txMax);
    txt+=tx;
    rxt+=rx;
    y1.push_back(rx);
    y2.push_back(tx);
    tx1=tx2;
    rx1=rx2;
    y1.removeFirst();
    y2.removeFirst();
    //Kotayi gectik mi
    if(uyarmadik && kota < rxt){
        QMessageBox uyari(this);
        uyari.warning(NULL,"Kota asimi","Kotayi gectik hocam biraz dikkat");
        uyari.setStandardButtons(QMessageBox::Ok);
        uyari.show();
        uyarmadik=false;
    }

    //KB MB mevzusu
    int indexR=0;
    int indexT=0;
    if(txMax>=GIGA){
        indexT=3;
    }else if(txMax>=MEGA){
        indexT=2;
    }else if(txMax>=KILO){
        indexT=1;
    }

    if(rxMax>=GIGA){
        indexR=3;
    }else if(rxMax>=MEGA){
        indexR=2;
    }else if(rxMax>=KILO){
        indexR=1;
    }

    // create graph and assign data to it:
    ui->bestdown->setText(QString::number( bestDown ) );
    ui->bestup->setText(QString::number(bestUp));
    ui->customPlot->addGraph();
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x,y1,fact[indexR]);
    ui->down->setText(QString::number(y1.last()/fact[indexR]));
    ui->customPlot->graph(0)->setData(x, y2,fact[indexT]);
    ui->up->setText(QString::number(y2.last()/fact[indexT]));
    // give the axes some labels:
    ui->widget->xAxis->setLabel("time (second)");
    QString rec("received " + birim[indexR]);
    ui->widget->yAxis->setLabel(rec);
    ui->customPlot->xAxis->setLabel("time (seconds)");
    QString trans("transmitted "+birim[indexT]);
    ui->customPlot->yAxis->setLabel(trans);
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(0, 100);
    ui->customPlot->yAxis->setRange(0, txMax/fact[indexT] );
    ui->customPlot->replot();
    ui->widget->xAxis->setRange(0, 100);
    ui->widget->yAxis->setRange(0, rxMax/fact[indexR]);
    ui->widget->replot();
    fclose(txf);
    fclose(rxf);
}
void systray::kapatiyoruz(){
    FILE* best=fopen("best","w");
    fprintf(best,"%lf %lf %lf %lf %lf",bestDown,bestUp,txt,rxt,kota);
    fclose(best);
    fclose(txf);
    fclose(rxf);
    exit(EXIT_SUCCESS);
}

systray::~systray(){
    kapatiyoruz();
    delete ui;
}
