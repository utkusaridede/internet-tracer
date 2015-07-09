/********************************************************************************
** Form generated from reading UI file 'log.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOG_H
#define UI_LOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_log
{
public:
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *log)
    {
        if (log->objectName().isEmpty())
            log->setObjectName(QString::fromUtf8("log"));
        log->resize(400, 300);
        verticalLayout = new QVBoxLayout(log);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textBrowser = new QTextBrowser(log);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        buttonBox = new QDialogButtonBox(log);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(log);
        QObject::connect(buttonBox, SIGNAL(accepted()), log, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), log, SLOT(reject()));

        QMetaObject::connectSlotsByName(log);
    } // setupUi

    void retranslateUi(QDialog *log)
    {
        log->setWindowTitle(QApplication::translate("log", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class log: public Ui_log {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOG_H
