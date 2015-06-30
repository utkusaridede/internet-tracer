/********************************************************************************
** Form generated from reading UI file 'systray.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTRAY_H
#define UI_SYSTRAY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_systray
{
public:

    void setupUi(QWidget *systray)
    {
        if (systray->objectName().isEmpty())
            systray->setObjectName(QString::fromUtf8("systray"));
        systray->resize(400, 300);

        retranslateUi(systray);

        QMetaObject::connectSlotsByName(systray);
    } // setupUi

    void retranslateUi(QWidget *systray)
    {
        systray->setWindowTitle(QApplication::translate("systray", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class systray: public Ui_systray {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTRAY_H
