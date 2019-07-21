/********************************************************************************
** Form generated from reading UI file 'SelectVideoFun.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTVIDEOFUN_H
#define UI_SELECTVIDEOFUN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectVideoFun
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QPushButton *deal;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *show;
    QSpinBox *spinBox;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label;
    QLabel *label_2;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *tab_2;
    QTextBrowser *textBrowser;
    QPushButton *showde;
    QListView *listView;

    void setupUi(QWidget *SelectVideoFun)
    {
        if (SelectVideoFun->objectName().isEmpty())
            SelectVideoFun->setObjectName(QStringLiteral("SelectVideoFun"));
        SelectVideoFun->resize(1103, 805);
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(10);
        SelectVideoFun->setFont(font);
        pushButton = new QPushButton(SelectVideoFun);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(100, 40, 171, 41));
        lineEdit = new QLineEdit(SelectVideoFun);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(270, 40, 611, 41));
        deal = new QPushButton(SelectVideoFun);
        deal->setObjectName(QStringLiteral("deal"));
        deal->setGeometry(QRect(880, 40, 151, 41));
        tabWidget = new QTabWidget(SelectVideoFun);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(100, 110, 941, 641));
        tabWidget->setStyleSheet(QStringLiteral(""));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        show = new QPushButton(tab);
        show->setObjectName(QStringLiteral("show"));
        show->setGeometry(QRect(370, 40, 121, 41));
        spinBox = new QSpinBox(tab);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(490, 40, 71, 41));
        scrollArea = new QScrollArea(tab);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(40, 170, 401, 391));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 399, 389));
        scrollArea->setWidget(scrollAreaWidgetContents);
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(190, 100, 61, 41));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(640, 110, 91, 31));
        scrollArea_2 = new QScrollArea(tab);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(480, 170, 400, 391));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 398, 389));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        textBrowser = new QTextBrowser(tab_2);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(20, 100, 871, 461));
        showde = new QPushButton(tab_2);
        showde->setObjectName(QStringLiteral("showde"));
        showde->setGeometry(QRect(390, 30, 151, 51));
        tabWidget->addTab(tab_2, QString());
        listView = new QListView(SelectVideoFun);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(-10, 0, 1111, 811));
        listView->setStyleSheet(QStringLiteral("border-image: url(:/TrafficCon/image/back3.jpg);"));
        listView->raise();
        tabWidget->raise();
        pushButton->raise();
        lineEdit->raise();
        deal->raise();
        QWidget::setTabOrder(pushButton, lineEdit);
        QWidget::setTabOrder(lineEdit, deal);
        QWidget::setTabOrder(deal, textBrowser);
        QWidget::setTabOrder(textBrowser, tabWidget);
        QWidget::setTabOrder(tabWidget, spinBox);
        QWidget::setTabOrder(spinBox, show);
        QWidget::setTabOrder(show, scrollArea);
        QWidget::setTabOrder(scrollArea, scrollArea_2);

        retranslateUi(SelectVideoFun);
        QObject::connect(pushButton, SIGNAL(clicked()), SelectVideoFun, SLOT(getVideoPath()));
        QObject::connect(deal, SIGNAL(clicked()), SelectVideoFun, SLOT(dealVideo()));
        QObject::connect(show, SIGNAL(clicked()), SelectVideoFun, SLOT(showPic()));
        QObject::connect(showde, SIGNAL(clicked()), SelectVideoFun, SLOT(showDetail()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(SelectVideoFun);
    } // setupUi

    void retranslateUi(QWidget *SelectVideoFun)
    {
        SelectVideoFun->setWindowTitle(QApplication::translate("SelectVideoFun", "SelectVideoFun", Q_NULLPTR));
        pushButton->setText(QApplication::translate("SelectVideoFun", "\351\200\211\346\213\251\350\247\206\351\242\221\346\226\207\344\273\266", Q_NULLPTR));
        deal->setText(QApplication::translate("SelectVideoFun", "\345\244\204\347\220\206\350\247\206\351\242\221", Q_NULLPTR));
        show->setText(QApplication::translate("SelectVideoFun", "\346\230\276  \347\244\272", Q_NULLPTR));
        label->setText(QApplication::translate("SelectVideoFun", "\345\244\204\347\220\206\345\211\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("SelectVideoFun", "\345\244\204\347\220\206\345\220\216", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("SelectVideoFun", "\345\244\204\347\220\206\347\273\223\346\236\234", Q_NULLPTR));
        showde->setText(QApplication::translate("SelectVideoFun", "\346\230\276\347\244\272\345\210\206\346\236\220\346\230\216\347\273\206", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("SelectVideoFun", "\347\273\237\350\256\241\346\230\216\347\273\206", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SelectVideoFun: public Ui_SelectVideoFun {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTVIDEOFUN_H
