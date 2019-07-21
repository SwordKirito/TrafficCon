/********************************************************************************
** Form generated from reading UI file 'TrafficCon.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAFFICCON_H
#define UI_TRAFFICCON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrafficConClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *Enter;
    QListView *listView;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *TrafficConClass)
    {
        if (TrafficConClass->objectName().isEmpty())
            TrafficConClass->setObjectName(QStringLiteral("TrafficConClass"));
        TrafficConClass->setWindowModality(Qt::WindowModal);
        TrafficConClass->setEnabled(true);
        TrafficConClass->resize(969, 673);
        TrafficConClass->setLayoutDirection(Qt::LeftToRight);
        TrafficConClass->setAutoFillBackground(false);
        TrafficConClass->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(TrafficConClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(-10, 60, 941, 411));
        label->setStyleSheet(QString::fromUtf8("\n"
"image: url(:/TrafficCon/image/\344\272\272\346\265\2012.jpg);"));
        Enter = new QPushButton(centralWidget);
        Enter->setObjectName(QStringLiteral("Enter"));
        Enter->setGeometry(QRect(370, 440, 201, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(14);
        Enter->setFont(font);
        Enter->setStyleSheet(QLatin1String("\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 189, 131, 245), stop:1 rgba(255, 255, 255, 255));\n"
"\n"
""));
        listView = new QListView(centralWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(0, -10, 971, 661));
        listView->setStyleSheet(QStringLiteral("border-image: url(:/TrafficCon/image/background.jpg);"));
        TrafficConClass->setCentralWidget(centralWidget);
        listView->raise();
        label->raise();
        Enter->raise();
        menuBar = new QMenuBar(TrafficConClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 969, 23));
        TrafficConClass->setMenuBar(menuBar);

        retranslateUi(TrafficConClass);
        QObject::connect(Enter, SIGNAL(clicked()), TrafficConClass, SLOT(On_Enter_Clicked()));

        QMetaObject::connectSlotsByName(TrafficConClass);
    } // setupUi

    void retranslateUi(QMainWindow *TrafficConClass)
    {
        TrafficConClass->setWindowTitle(QApplication::translate("TrafficConClass", "TrafficCon", Q_NULLPTR));
        label->setText(QString());
        Enter->setText(QApplication::translate("TrafficConClass", "\350\277\233     \345\205\245", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TrafficConClass: public Ui_TrafficConClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAFFICCON_H
