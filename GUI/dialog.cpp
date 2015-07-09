#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QFile f("../daemon/data/log");
    QTextStream ts(&f);
    ui->textBrowser->setText(ts.readAll());
}

Dialog::~Dialog()
{
    delete ui;
}
