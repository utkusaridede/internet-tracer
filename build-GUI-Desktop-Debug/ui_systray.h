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
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_systray
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QCustomPlot *widget;
    QLabel *down;
    QLabel *bestdown;
    QCustomPlot *customPlot;
    QLabel *up;
    QLabel *bestup;

    void setupUi(QWidget *systray)
    {
        if (systray->objectName().isEmpty())
            systray->setObjectName(QString::fromUtf8("systray"));
        systray->resize(466, 309);
        horizontalLayout = new QHBoxLayout(systray);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QCustomPlot(systray);
        widget->setObjectName(QString::fromUtf8("widget"));
        down = new QLabel(widget);
        down->setObjectName(QString::fromUtf8("down"));
        down->setGeometry(QRect(10, 100, 61, 21));
        bestdown = new QLabel(widget);
        bestdown->setObjectName(QString::fromUtf8("bestdown"));
        bestdown->setGeometry(QRect(350, 10, 57, 15));

        verticalLayout->addWidget(widget);

        customPlot = new QCustomPlot(systray);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        up = new QLabel(customPlot);
        up->setObjectName(QString::fromUtf8("up"));
        up->setGeometry(QRect(10, 100, 61, 21));
        bestup = new QLabel(customPlot);
        bestup->setObjectName(QString::fromUtf8("bestup"));
        bestup->setGeometry(QRect(350, 10, 57, 15));

        verticalLayout->addWidget(customPlot);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(systray);

        QMetaObject::connectSlotsByName(systray);
    } // setupUi

    void retranslateUi(QWidget *systray)
    {
        systray->setWindowTitle(QApplication::translate("systray", "Form", 0, QApplication::UnicodeUTF8));
        down->setText(QApplication::translate("systray", "TextLabel", 0, QApplication::UnicodeUTF8));
        bestdown->setText(QApplication::translate("systray", "TextLabel", 0, QApplication::UnicodeUTF8));
        up->setText(QApplication::translate("systray", "TextLabel", 0, QApplication::UnicodeUTF8));
        bestup->setText(QApplication::translate("systray", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class systray: public Ui_systray {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTRAY_H
