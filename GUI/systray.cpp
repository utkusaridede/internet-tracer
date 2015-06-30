#include "systray.h"
#include "ui_systray.h"

systray::systray(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::systray)
{
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
