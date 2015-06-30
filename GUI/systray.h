#ifndef SYSTRAY_H
#define SYSTRAY_H

#include <QWidget>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QLayout>
#include <QRect>
#include <QDesktopWidget>

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

    ~systray();

public slots:
    void foo();
    void kapatiyoruz();

private:
    Ui::systray *ui;
};

#endif // SYSTRAY_H
