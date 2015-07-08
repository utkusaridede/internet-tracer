/********************************************************************************
** Form generated from reading UI file 'kotaset.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KOTASET_H
#define UI_KOTASET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_kotaset
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QDialog *kotaset)
    {
        if (kotaset->objectName().isEmpty())
            kotaset->setObjectName(QString::fromUtf8("kotaset"));
        kotaset->resize(410, 140);
        buttonBox = new QDialogButtonBox(kotaset);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 90, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(kotaset);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(110, 50, 261, 23));
        label = new QLabel(kotaset);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 51, 81, 20));

        retranslateUi(kotaset);
        QObject::connect(buttonBox, SIGNAL(accepted()), kotaset, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), kotaset, SLOT(reject()));

        QMetaObject::connectSlotsByName(kotaset);
    } // setupUi

    void retranslateUi(QDialog *kotaset)
    {
        kotaset->setWindowTitle(QApplication::translate("kotaset", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("kotaset", "Quota", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class kotaset: public Ui_kotaset {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KOTASET_H
