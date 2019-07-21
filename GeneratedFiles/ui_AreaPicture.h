/********************************************************************************
** Form generated from reading UI file 'AreaPicture.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AREAPICTURE_H
#define UI_AREAPICTURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AreaPicture
{
public:
    QLabel *label;
    QLabel *label_2;
    QScrollArea *Before;
    QWidget *scrollAreaWidgetContents;
    QScrollArea *After;
    QWidget *scrollAreaWidgetContents_2;
    QListView *listView;

    void setupUi(QWidget *AreaPicture)
    {
        if (AreaPicture->objectName().isEmpty())
            AreaPicture->setObjectName(QStringLiteral("AreaPicture"));
        AreaPicture->resize(1425, 853);
        label = new QLabel(AreaPicture);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(280, 90, 71, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(10);
        label->setFont(font);
        label_2 = new QLabel(AreaPicture);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(1020, 90, 81, 31));
        label_2->setFont(font);
        Before = new QScrollArea(AreaPicture);
        Before->setObjectName(QStringLiteral("Before"));
        Before->setGeometry(QRect(40, 150, 550, 500));
        Before->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 548, 498));
        Before->setWidget(scrollAreaWidgetContents);
        After = new QScrollArea(AreaPicture);
        After->setObjectName(QStringLiteral("After"));
        After->setGeometry(QRect(740, 150, 550, 500));
        After->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 548, 498));
        After->setWidget(scrollAreaWidgetContents_2);
        listView = new QListView(AreaPicture);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(0, 0, 1431, 851));
        listView->setStyleSheet(QStringLiteral("border-image: url(:/TrafficCon/image/back2.jpg);"));
        listView->raise();
        label->raise();
        label_2->raise();
        Before->raise();
        After->raise();

        retranslateUi(AreaPicture);

        QMetaObject::connectSlotsByName(AreaPicture);
    } // setupUi

    void retranslateUi(QWidget *AreaPicture)
    {
        AreaPicture->setWindowTitle(QApplication::translate("AreaPicture", "AreaPicture", Q_NULLPTR));
        label->setText(QApplication::translate("AreaPicture", "\350\260\203\346\216\247\345\211\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("AreaPicture", "\350\260\203\346\216\247\345\220\216", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AreaPicture: public Ui_AreaPicture {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AREAPICTURE_H
