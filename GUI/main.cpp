#include "systray.h"
#include <QApplication>
#include <systray.h>
int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    systray w;
    w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint |  Qt::WindowStaysOnTopHint );
    return a.exec();
}
