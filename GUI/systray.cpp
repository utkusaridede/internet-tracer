#include "systray.h"
#include "ui_systray.h"
#include "qcustomplot.h"
#include "kotaset.h"
#include <sqlite3.h>
#include <stdio.h>


double* dataCommand(const char* command){
    double* q=new double[4];
    sqlite3 *db;
    sqlite3_stmt *res;
    int rc = sqlite3_open("memory", &db);
    rc = sqlite3_prepare_v2(db,command , -1, &res, 0);
    rc = sqlite3_step(res);

    if (rc == SQLITE_ROW) {
        for(int i=1;i<5;i++)
            q[i-1]= sqlite3_column_double(res, i);
    }

    sqlite3_finalize(res);
    sqlite3_close(db);
    return q;
}

systray::systray(QWidget *parent)
:QWidget(parent),
ui(new Ui::systray){
    badges[0]=QPixmap("b1.png").scaled(45,45,Qt::KeepAspectRatio);
    badges[1]=QPixmap("b2.png");
    badges[2]=QPixmap("b3.png");
    badges[3]=QPixmap("b4.png");
    QRect rec = QApplication::desktop()->screenGeometry();
    this->move(rec.width()-this->width()/2,rec.height()/2-this->height());
    ui->setupUi(this);
    ui->kotagecme->setText("False");
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
    FILE* q=fopen("kota","r");
    fscanf(q,"%lf",&kota);
    fclose(q);
    double* data = dataCommand("select * from t3 where date=20150808");
    bestUp=data[0];
    bestDown=data[1];
    txt=data[2];
    rxt=data[3];
    qDebug()<<bestUp;
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
    if(bestDown<rxMax){
        bestDown=rxMax;
        QMessageBox uy(this);
        uy.warning(NULL,"Milletce alkisliyoruz","En yuksek indirme oranina ulasildi!!");
        uy.setStandardButtons(QMessageBox::Ok);
        uy.show();

    }
    if(bestUp<txMax){
        bestUp=txMax;
        QMessageBox u(this);
        u.warning(NULL,"Milletce alkisliyoruz","En yuksek gonderme oranina ulasildi!!");
        u.setStandardButtons(QMessageBox::Ok);
        u.show();
    }
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
        ui->kotagecme->setText("True");
    }

  ///////////index isleri

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
    ui->downbadge->setPixmap(badges[indexR]);
    ui->upbadge->setPixmap(badges[indexT]);
    ui->downT->setText(QString::number(rxt));
    ui->upT->setText(QString::number(txt));
    ui->kota->setText(QString::number(kota));
    ui->bestdown->setText(QString::number( bestDown ) );
    ui->bestup->setText(QString::number(bestUp));
    ui->customPlot->addGraph();
    ui->dgraph->addGraph();
    ui->dgraph->graph(0)->setData(x,y1,fact[indexR]);
    ui->down->setText(QString::number(y1.last()/fact[indexR]));
    ui->customPlot->graph(0)->setData(x, y2,fact[indexT]);
    ui->up->setText(QString::number(y2.last()/fact[indexT]));
    // give the axes some labels:
    ui->dgraph->xAxis->setLabel("time (second)");
    QString rec("received " + birim[indexR]);
    ui->dgraph->yAxis->setLabel(rec);
    ui->customPlot->xAxis->setLabel("time (seconds)");
    QString trans("transmitted "+birim[indexT]);
    ui->customPlot->yAxis->setLabel(trans);
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(0, 100);
    ui->customPlot->yAxis->setRange(0, txMax/fact[indexT] );
    ui->customPlot->replot();
    ui->dgraph->xAxis->setRange(0, 100);
    ui->dgraph->yAxis->setRange(0, rxMax/fact[indexR]);
    ui->dgraph->replot();
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

void systray::on_setKota_clicked(){
    kotaset* k=new kotaset(NULL,&kota);
    k->exec();
    delete(k);
}
