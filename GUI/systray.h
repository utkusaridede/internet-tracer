#ifndef SYSTRAY_H
#define SYSTRAY_H

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
    static QLinkedList<int> y1;
    static QLinkedList<int> y2;
    QTimer *timer;
    ~systray();

public slots:
    void foo();
    void kapatiyoruz();
    void refresh();

private:
    Ui::systray *ui;
};

#endif // SYSTRAY_H
