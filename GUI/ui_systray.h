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
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_systray
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QLabel *kota;
    QPushButton *setKota;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QLabel *upT;
    QLabel *downT;
    QLabel *label_4;
    QLabel *label_3;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *bestdown;
    QLabel *label_2;
    QLabel *downbadge;
    QLabel *bestup;
    QLabel *upbadge;
    QLabel *kotagecme;
    QLabel *label_6;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_3;
    QCustomPlot *dgraph;
    QLabel *down;
    QWidget *tab_2;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_2;
    QCustomPlot *customPlot;
    QLabel *up;
    QWidget *tab_4;

    void setupUi(QWidget *systray)
    {
        if (systray->objectName().isEmpty())
            systray->setObjectName(QString::fromUtf8("systray"));
        systray->resize(460, 802);
        verticalLayoutWidget = new QWidget(systray);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(290, 470, 151, 80));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        kota = new QLabel(verticalLayoutWidget);
        kota->setObjectName(QString::fromUtf8("kota"));

        verticalLayout_2->addWidget(kota);

        setKota = new QPushButton(verticalLayoutWidget);
        setKota->setObjectName(QString::fromUtf8("setKota"));

        verticalLayout_2->addWidget(setKota);

        groupBox = new QGroupBox(systray);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 560, 271, 80));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(-1, -1, 0, -1);
        upT = new QLabel(groupBox);
        upT->setObjectName(QString::fromUtf8("upT"));

        gridLayout_3->addWidget(upT, 1, 2, 1, 1);

        downT = new QLabel(groupBox);
        downT->setObjectName(QString::fromUtf8("downT"));

        gridLayout_3->addWidget(downT, 1, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 0, 2, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(systray);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 450, 271, 101));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        bestdown = new QLabel(groupBox_2);
        bestdown->setObjectName(QString::fromUtf8("bestdown"));

        gridLayout_2->addWidget(bestdown, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        downbadge = new QLabel(groupBox_2);
        downbadge->setObjectName(QString::fromUtf8("downbadge"));

        gridLayout_2->addWidget(downbadge, 0, 2, 1, 1);

        bestup = new QLabel(groupBox_2);
        bestup->setObjectName(QString::fromUtf8("bestup"));

        gridLayout_2->addWidget(bestup, 1, 1, 1, 1);

        upbadge = new QLabel(groupBox_2);
        upbadge->setObjectName(QString::fromUtf8("upbadge"));

        gridLayout_2->addWidget(upbadge, 1, 2, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        kotagecme = new QLabel(systray);
        kotagecme->setObjectName(QString::fromUtf8("kotagecme"));
        kotagecme->setGeometry(QRect(350, 610, 51, 20));
        label_6 = new QLabel(systray);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(340, 580, 81, 16));
        layoutWidget = new QWidget(systray);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 441, 431));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(layoutWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_3 = new QHBoxLayout(tab);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        dgraph = new QCustomPlot(tab);
        dgraph->setObjectName(QString::fromUtf8("dgraph"));
        down = new QLabel(dgraph);
        down->setObjectName(QString::fromUtf8("down"));
        down->setGeometry(QRect(10, 130, 61, 21));
        down->raise();
        tabWidget->raise();

        horizontalLayout_3->addWidget(dgraph);

        tabWidget->addTab(tab, QString());
        dgraph->raise();
        layoutWidget->raise();
        dgraph->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        tabWidget_2 = new QTabWidget(layoutWidget);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        horizontalLayout_2 = new QHBoxLayout(tab_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        customPlot = new QCustomPlot(tab_3);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        up = new QLabel(customPlot);
        up->setObjectName(QString::fromUtf8("up"));
        up->setGeometry(QRect(10, 120, 61, 31));

        horizontalLayout_2->addWidget(customPlot);

        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget_2->addTab(tab_4, QString());

        verticalLayout->addWidget(tabWidget_2);


        retranslateUi(systray);

        QMetaObject::connectSlotsByName(systray);
    } // setupUi

    void retranslateUi(QWidget *systray)
    {
        systray->setWindowTitle(QApplication::translate("systray", "Form", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("systray", "Quota", 0, QApplication::UnicodeUTF8));
        kota->setText(QApplication::translate("systray", "TextLabel", 0, QApplication::UnicodeUTF8));
        setKota->setText(QApplication::translate("systray", "Set Quota", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("systray", "Totals", 0, QApplication::UnicodeUTF8));
        upT->setText(QApplication::translate("systray", "TextLabel", 0, QApplication::UnicodeUTF8));
        downT->setText(QApplication::translate("systray", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("systray", "Total Upload", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("systray", "Total Download", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("systray", "Bests", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("systray", "Best Download:", 0, QApplication::UnicodeUTF8));
        bestdown->setText(QApplication::translate("systray", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("systray", "Best Upload:s", 0, QApplication::UnicodeUTF8));
        downbadge->setText(QApplication::translate("systray", "TextLabel", 0, QApplication::UnicodeUTF8));
        bestup->setText(QApplication::translate("systray", "TextLabel", 0, QApplication::UnicodeUTF8));
        upbadge->setText(QApplication::translate("systray", "TextLabel", 0, QApplication::UnicodeUTF8));
        kotagecme->setText(QApplication::translate("systray", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("systray", "Quota Exceeded", 0, QApplication::UnicodeUTF8));
        down->setText(QApplication::translate("systray", "TextLabel", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("systray", "Tab 1", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("systray", "Tab 2", 0, QApplication::UnicodeUTF8));
        up->setText(QApplication::translate("systray", "TextLabel", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("systray", "Tab 1", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("systray", "Tab 2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class systray: public Ui_systray {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTRAY_H
