/********************************************************************************
** Form generated from reading UI file 'getavi.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETAVI_H
#define UI_GETAVI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_getavi
{
public:
    QPushButton *button_1;
    QPushButton *button_2;
    QLabel *label;
    QLabel *label_2;
    QTextBrowser *textBrowser;
    QLabel *label_3;
    QListView *listView;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *getavi)
    {
        if (getavi->objectName().isEmpty())
            getavi->setObjectName(QStringLiteral("getavi"));
        getavi->resize(844, 702);
        button_1 = new QPushButton(getavi);
        button_1->setObjectName(QStringLiteral("button_1"));
        button_1->setGeometry(QRect(630, 150, 140, 60));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        button_1->setFont(font);
        button_2 = new QPushButton(getavi);
        button_2->setObjectName(QStringLiteral("button_2"));
        button_2->setGeometry(QRect(470, 150, 140, 60));
        button_2->setFont(font);
        label = new QLabel(getavi);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(280, 150, 181, 71));
        label->setFrameShape(QFrame::Panel);
        label->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(getavi);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 150, 141, 61));
        label_2->setFont(font);
        label_2->setLineWidth(0);
        textBrowser = new QTextBrowser(getavi);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(70, 280, 661, 411));
        label_3 = new QLabel(getavi);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(300, 230, 171, 51));
        label_3->setFont(font);
        label_3->setFrameShape(QFrame::Panel);
        label_3->setFrameShadow(QFrame::Sunken);
        label_3->setLineWidth(0);
        listView = new QListView(getavi);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(0, -10, 851, 711));
        listView->setStyleSheet(QStringLiteral("border-image: url(:/TrafficCon/image/back3.jpg);"));
        label_4 = new QLabel(getavi);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(120, 60, 181, 61));
        label_4->setFont(font);
        lineEdit = new QLineEdit(getavi);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(290, 70, 161, 50));
        pushButton = new QPushButton(getavi);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(460, 80, 112, 34));
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(getavi);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(580, 80, 112, 34));
        pushButton_2->setFont(font);
        listView->raise();
        button_1->raise();
        button_2->raise();
        label->raise();
        label_2->raise();
        textBrowser->raise();
        label_3->raise();
        label_4->raise();
        lineEdit->raise();
        pushButton->raise();
        pushButton_2->raise();

        retranslateUi(getavi);
        QObject::connect(button_1, SIGNAL(clicked()), getavi, SLOT(button1()));
        QObject::connect(button_2, SIGNAL(clicked()), getavi, SLOT(button2()));
        QObject::connect(pushButton, SIGNAL(clicked()), getavi, SLOT(button3()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), getavi, SLOT(button4()));

        QMetaObject::connectSlotsByName(getavi);
    } // setupUi

    void retranslateUi(QWidget *getavi)
    {
        getavi->setWindowTitle(QApplication::translate("getavi", "getavi", Q_NULLPTR));
        button_1->setText(QApplication::translate("getavi", "\347\224\237 \346\210\220 \350\247\206 \351\242\221", Q_NULLPTR));
        button_2->setText(QApplication::translate("getavi", "\345\256\236 \346\227\266 \350\216\267 \345\217\226", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QApplication::translate("getavi", "\346\221\204 \345\275\261 \346\234\272 \347\212\266 \346\200\201\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("getavi", "\345\256\236 \346\227\266 \350\216\267 \345\217\226 \346\230\216 \347\273\206", Q_NULLPTR));
        label_4->setText(QApplication::translate("getavi", "\350\257\267\350\256\276\345\256\232\346\234\200\345\244\247\346\217\220\351\206\222\344\272\272\346\225\260\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("getavi", "\347\241\256\350\256\244", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("getavi", "\350\256\276\344\270\272\351\273\230\350\256\244\345\200\274", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class getavi: public Ui_getavi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETAVI_H
