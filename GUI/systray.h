#ifndef SYSTRAY_H
#define SYSTRAY_H

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MEGA 1000000
#define KILO 1000
#define GIGA 1000000000


#include <QWidget>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QLayout>
#include <QRect>
#include <QDesktopWidget>
#include <QVector>
#include <QLinkedList>
#include <cstdio>
#include <QTimer>
#include <pthread.h>
#include <unistd.h>

namespace Ui {
class systray;
}

class systray : public QWidget
{
    Q_OBJECT

public:
    explicit systray(QWidget *parent = 0);
    QSystemTrayIcon* icon;
    QMenu* menu;
    QAction* kapat;
    bool on_top;
    QVector<double> x;
    QLinkedList<double> y1;
    QLinkedList<double> y2;
    FILE* txf;
    FILE* rxf;
    long long int tx1,tx2,rx1,rx2;
    double rxMax,txMax,frx,ftx,rxt,txt;
    QTimer *timer;
    QString birim[4]={"(KB)","(MB)","(GB)","(TB)"};
    int  fact[4]={1,KILO,MEGA ,GIGA};
    double  bestDown,bestUp;
    double kota;

    ~systray();

public slots:
    void foo();
    void kapatiyoruz();
    void refresh();

private:
    Ui::systray *ui;
};

#endif // SYSTRAY_H
