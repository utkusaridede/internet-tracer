#include "systray.h"
#include "ui_systray.h"
#include "qcustomplot.h"
#include "kotaset.h"



double dataCommand(const char* command){
    double q;
    sqlite3 *db;
    sqlite3_stmt *res;
    int rc = sqlite3_open("memory", &db);
    rc = sqlite3_prepare_v2(db,command , -1, &res, 0);
    rc = sqlite3_step(res);

     if (rc == SQLITE_ROW) {
        q= sqlite3_column_double(res, 0);
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
    tx1=tx2; rx1=rx2; dxt=txMax=0; dxr=rxMax=0;
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
    //ui->tab->
    FILE* best=fopen("best","r");
    fscanf(best,"%lf %lf %lf",&bestDown,&bestUp,&kota);
    fclose(best);
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t  );
    int date = ((now->tm_year + 1900)*10000 + (now->tm_mon+1)*100 );
    int oc = date+100;
    char command1[100];
    char command2[100];
    command1[0]=0;
    command2[0]=0;
    sprintf(command1,"select sum(down) from gunluk where date>%d and date<%d",date,oc);
    sprintf(command2,"select sum(up) from gunluk where date>%d and date<%d",date,oc);
    qDebug()<<command1;
    rxt = dataCommand(command1);
    txt = dataCommand(command2);
    qDebug()<<rxt;
    qDebug()<<txt;
    qDebug()<<kota;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(refresh()));
    timer->start(1000);
    uyarmadik=true;
    d=0;u=0;

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
    struct tm * m;
    struct tm * n;
    txf=fopen("/sys/class/net/wlan0/statistics/tx_bytes","r");
    rxf=fopen("/sys/class/net/wlan0/statistics/rx_bytes","r");
    fscanf(rxf,"%lld",&rx2);
    fscanf(txf,"%lld",&tx2);
    double rx= (double) (rx2-rx1) / KILO;
    double tx= (double) (tx2-tx1) / KILO;
    txMax=MAX(txMax,tx);
    rxMax=MAX(rxMax,rx);
    if(bestDown<rxMax && difftime(time(0),d)>10){
        d =time(0);
        QMessageBox uy(this);
        uy.warning(NULL,"Milletce alkisliyoruz","En yuksek indirme oranina ulasildi!!");
        uy.setStandardButtons(QMessageBox::Ok);
        uy.show();

    }
    bestDown=MAX(rxMax,bestDown);

    if(bestUp<txMax && difftime(time(0),u)>10){
        u = time(0);
        QMessageBox u(this);
        u.warning(NULL,"Milletce alkisliyoruz","En yuksek gonderme oranina ulasildi!!");
        u.setStandardButtons(QMessageBox::Ok);
        u.show();
    }\
    bestUp=MAX(txMax,bestUp);
    txt+=tx;
    rxt+=rx;
    dxr+=rx;
    dxt+=tx;
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


std::string bokcuk(std::string s){
    for(int i=0;i<s.length();i++){
        if(s[i]==',') s[i]='.';
    }
    return s;
}


void systray::kapatiyoruz(){
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t  );
    int date = ((now->tm_year + 1900)*10000 + (now->tm_mon+1)*100 + now->tm_mday);
    qDebug()<<date;
    std::string command1=std::string("insert or ignore into gunluk values(")+std::to_string(date)+std::string(",0,0);");
    std::string command2="update gunluk set down=((select down from gunluk where date="+std::to_string(date)+")+"+std::to_string(dxr)+") where date="+std::to_string(date)+";";
    std::string command3="update gunluk set up=((select up from gunluk where date="+std::to_string(date)+")+"+std::to_string(dxr)+") where date="+std::to_string(date)+";";
    //sprintf(command1,"insert or ignore into gunluk values(%d,0,0);",date);
    // sprintf(command2,"update gunluk set down=((select down from gunluk where date=%d)+%lf) where date=%d;",date,dxr,date);
    //sprintf(command3,"update gunluk set up=((select up from gunluk where date=%d)+%lf) where date=%d;",date,dxt,date);
    //qDebug()<<command2;
    command2=bokcuk(command2);
    command3=bokcuk(command3);
    qDebug()<<command2.c_str();
    dataCommand(command1.c_str());
    dataCommand(command2.c_str());
    dataCommand(command3.c_str());
    FILE* best=fopen("best","w");
    fprintf(best,"%lf %lf %lf",bestDown,bestUp,kota);
    fclose(best);
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
