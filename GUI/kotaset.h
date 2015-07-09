#ifndef KOTASET_H
#define KOTASET_H

#include <QDialog>
#include <stdlib.h>


namespace Ui {
class kotaset;
}

class kotaset : public QDialog
{
    Q_OBJECT

public:
    explicit kotaset(QWidget *parent = 0,double* kota=0);
    double* pkota;
    ~kotaset();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::kotaset *ui;
};

#endif // KOTASET_H
