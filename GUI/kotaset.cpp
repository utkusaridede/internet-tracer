#include "kotaset.h"
#include "ui_kotaset.h"
#include "systray.h"
#include <QDebug>
kotaset::kotaset(QWidget *parent,double* kota) :
    QDialog(parent),
    ui(new Ui::kotaset)
{
    ui->setupUi(this);
    pkota=kota;
    ui->lineEdit->setText(QString::number(*kota));
}

kotaset::~kotaset(){
    delete ui;
}

void kotaset::on_buttonBox_accepted()
{
    *pkota=ui->lineEdit->text().toDouble();
}
