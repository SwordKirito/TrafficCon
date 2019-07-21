/********************************************************************************
** Form generated from reading UI file 'ConMessage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONMESSAGE_H
#define UI_CONMESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConMessage
{
public:
    QPushButton *WaitPeople;
    QPushButton *WaitTime;
    QPushButton *Detail;
    QTextBrowser *textBrowser;
    QLabel *label;

    void setupUi(QWidget *ConMessage)
    {
        if (ConMessage->objectName().isEmpty())
            ConMessage->setObjectName(QStringLiteral("ConMessage"));
        ConMessage->resize(764, 620);
        WaitPeople = new QPushButton(ConMessage);
        WaitPeople->setObjectName(QStringLiteral("WaitPeople"));
        WaitPeople->setGeometry(QRect(30, 30, 151, 41));
        WaitTime = new QPushButton(ConMessage);
        WaitTime->setObjectName(QStringLiteral("WaitTime"));
        WaitTime->setGeometry(QRect(30, 100, 151, 41));
        Detail = new QPushButton(ConMessage);
        Detail->setObjectName(QStringLiteral("Detail"));
        Detail->setGeometry(QRect(30, 170, 151, 41));
        textBrowser = new QTextBrowser(ConMessage);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(200, 30, 521, 551));
        label = new QLabel(ConMessage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 310, 151, 261));
        label->setStyleSheet(QStringLiteral("border-image: url(:/TrafficCon/image/kenan.jpg);"));

        retranslateUi(ConMessage);
        QObject::connect(WaitPeople, SIGNAL(clicked()), ConMessage, SLOT(OnPeople()));
        QObject::connect(WaitTime, SIGNAL(clicked()), ConMessage, SLOT(OnTime()));
        QObject::connect(Detail, SIGNAL(clicked()), ConMessage, SLOT(ShowDetail()));

        QMetaObject::connectSlotsByName(ConMessage);
    } // setupUi

    void retranslateUi(QWidget *ConMessage)
    {
        ConMessage->setWindowTitle(QApplication::translate("ConMessage", "ConMessage", Q_NULLPTR));
        WaitPeople->setText(QApplication::translate("ConMessage", "\350\260\203\346\216\247\345\211\215\345\220\216\344\272\272\346\225\260\345\257\271\346\257\224", Q_NULLPTR));
        WaitTime->setText(QApplication::translate("ConMessage", "\350\260\203\346\216\247\345\211\215\345\220\216\346\227\266\351\225\277\345\257\271\346\257\224", Q_NULLPTR));
        Detail->setText(QApplication::translate("ConMessage", "\350\260\203\346\216\247\346\230\216\347\273\206", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ConMessage: public Ui_ConMessage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONMESSAGE_H
