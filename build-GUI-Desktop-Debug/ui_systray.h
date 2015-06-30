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
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_systray
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *systray)
    {
        if (systray->objectName().isEmpty())
            systray->setObjectName(QString::fromUtf8("systray"));
        systray->resize(400, 300);
        horizontalLayout = new QHBoxLayout(systray);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(systray);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(systray);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(systray);

        QMetaObject::connectSlotsByName(systray);
    } // setupUi

    void retranslateUi(QWidget *systray)
    {
        systray->setWindowTitle(QApplication::translate("systray", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("systray", "HA BURAYA GRAFIK KOYACAUK", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("systray", "HA  BURAYA BAGLI OLANLARI YAZACAUK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class systray: public Ui_systray {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTRAY_H
