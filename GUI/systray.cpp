#include "systray.h"
#include "ui_systray.h"
#include "qcustomplot.h"
#define MAX(a,b) (((a)>(b))?(a):(b))


FILE* txf;
FILE* rxf;
pthread_attr_t attr;
pthread_t th;
pthread_mutex_t mutex;
pthread_mutexattr_t mattr;
int tx1,tx2,rx1,rx2,rxMax,txMax;
QLinkedList<int> systray::y1;
QLinkedList<int> systray::y2;

void* watch(void* args){
    while(1){
        pthread_mutex_lock(&mutex);
        txf=fopen("/sys/class/net/wlan0/statistics/tx_bytes","r");
        fscanf(txf,"%d",&tx2);
        rxf=fopen("/sys/class/net/wlan0/statistics/rx_bytes","r");
        fscanf(rxf,"%d",&rx2);
        txMax=MAX(txMax,tx2-tx1);
        rxMax=MAX(rxMax,rx2-rx1);
        systray::y1.push_back(rx2-rx1);
        systray::y2.push_back(tx2-tx1);
        tx1=tx2;
        rx1=rx2;
        systray::y1.removeFirst();
        systray::y2.removeFirst();
        fclose(txf);
        fclose(rxf);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return NULL;
}


systray::systray(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::systray){   
    QRect rec = QApplication::desktop()->screenGeometry();
    this->move(rec.width()-this->width()/2,rec.height()/2-this->height());
    ui->setupUi(this);
    txf=fopen("/sys/class/net/wlan0/statistics/tx_bytes","r");
    fscanf(txf,"%d",&tx2);
    rxf=fopen("/sys/class/net/wlan0/statistics/rx_bytes","r");
    fscanf(rxf,"%d",&rx2);
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
    pthread_attr_init(&attr);
    pthread_mutex_init(&mutex, &mattr );
    for (int i=0; i<101; ++i){
      x.push_back(i);
      y1.append(0);
      y2.append(0);
    }
    pthread_create(&th, &attr,watch, NULL );
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(refresh()));
    timer->start(1000);
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
    // create graph and assign data to it:
    ui->customPlot->addGraph();
    ui->widget->addGraph();
    pthread_mutex_lock(&mutex);
    ui->widget->graph(0)->setData(x,y1);
    ui->customPlot->graph(0)->setData(x, y2);
    pthread_mutex_unlock(&mutex);
    // give the axes some labels:
    ui->widget->xAxis->setLabel("time");
    ui->widget->yAxis->setLabel("received");
    ui->customPlot->xAxis->setLabel("time");
    ui->customPlot->yAxis->setLabel("transmitted");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(0, 100);
    ui->customPlot->yAxis->setRange(0, 5*txMax/4);
    ui->customPlot->replot();
    ui->widget->xAxis->setRange(0, 100);
    ui->widget->yAxis->setRange(0, 5*rxMax/4);
    ui->widget->replot();
}
void systray::kapatiyoruz(){
    exit(EXIT_SUCCESS);
}

systray::~systray(){
    delete ui;
}
