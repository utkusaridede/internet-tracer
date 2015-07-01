#include "systray.h"
#include "ui_systray.h"
#include "qcustomplot.h"

systray::systray(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::systray){   
    QRect rec = QApplication::desktop()->screenGeometry();
    this->move(rec.width()-this->width()/2,rec.height()/2-this->height());
    ui->setupUi(this);
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
}



void systray::foo(){
    if(on_top){
        this->hide();
    }else{
        for (int i=0; i<101; ++i)
        {
          x.push_back( i/50.0 - 1); // x goes from -1 to 1
          y.push_back( x[i]*x[i] ); // let's plot a quadratic function
        }
        // create graph and assign data to it:
        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(x, y);
        // give the axes some labels:
        ui->customPlot->xAxis->setLabel("x");
        ui->customPlot->yAxis->setLabel("y");
        // set axes ranges, so we see all data:
        ui->customPlot->xAxis->setRange(-1, 1);
        ui->customPlot->yAxis->setRange(0, 1);
        ui->customPlot->replot();
        this->show();
    }
    on_top = !on_top;
}

void systray::kapatiyoruz(){
    exit(EXIT_SUCCESS);
}

systray::~systray(){
    delete ui;
}
