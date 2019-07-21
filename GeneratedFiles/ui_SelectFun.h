/********************************************************************************
** Form generated from reading UI file 'SelectFun.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTFUN_H
#define UI_SELECTFUN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QColumnView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectFun
{
public:
    QPushButton *SelectVideo;
    QPushButton *SimuCon;
    QPushButton *getavi;
    QColumnView *columnView;
    QLabel *label;

    void setupUi(QWidget *SelectFun)
    {
        if (SelectFun->objectName().isEmpty())
            SelectFun->setObjectName(QStringLiteral("SelectFun"));
        SelectFun->resize(713, 472);
        SelectFun->setCursor(QCursor(Qt::PointingHandCursor));
        SelectFun->setLayoutDirection(Qt::LeftToRight);
        SelectFun->setAutoFillBackground(false);
        SelectFun->setStyleSheet(QStringLiteral(""));
        SelectVideo = new QPushButton(SelectFun);
        SelectVideo->setObjectName(QStringLiteral("SelectVideo"));
        SelectVideo->setGeometry(QRect(100, 100, 131, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(10);
        SelectVideo->setFont(font);
        SelectVideo->setCursor(QCursor(Qt::PointingHandCursor));
        SelectVideo->setStyleSheet(QLatin1String("background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));\n"
"border:1px solid black;\n"
""));
        SimuCon = new QPushButton(SelectFun);
        SimuCon->setObjectName(QStringLiteral("SimuCon"));
        SimuCon->setGeometry(QRect(480, 100, 131, 41));
        SimuCon->setFont(font);
        SimuCon->setStyleSheet(QStringLiteral("background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));"));
        getavi = new QPushButton(SelectFun);
        getavi->setObjectName(QStringLiteral("getavi"));
        getavi->setGeometry(QRect(290, 350, 131, 41));
        getavi->setFont(font);
        getavi->setStyleSheet(QStringLiteral("background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));"));
        getavi->setIconSize(QSize(24, 24));
        columnView = new QColumnView(SelectFun);
        columnView->setObjectName(QStringLiteral("columnView"));
        columnView->setGeometry(QRect(0, 0, 711, 471));
        columnView->setStyleSheet(QStringLiteral("border-image: url(:/TrafficCon/image/background.jpg);"));
        label = new QLabel(SelectFun);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(230, 130, 261, 211));
        label->setStyleSheet(QStringLiteral("border-image: url(:/TrafficCon/image/first.png);"));
        columnView->raise();
        SelectVideo->raise();
        SimuCon->raise();
        getavi->raise();
        label->raise();

        retranslateUi(SelectFun);
        QObject::connect(SimuCon, SIGNAL(clicked()), SelectFun, SLOT(On_SimuCon_Clicked()));
        QObject::connect(SelectVideo, SIGNAL(clicked()), SelectFun, SLOT(On_SelectVideo_Clicked()));
        QObject::connect(getavi, SIGNAL(clicked()), SelectFun, SLOT(getavi_Clicked()));

        QMetaObject::connectSlotsByName(SelectFun);
    } // setupUi

    void retranslateUi(QWidget *SelectFun)
    {
        SelectFun->setWindowTitle(QApplication::translate("SelectFun", "SelectFun", Q_NULLPTR));
        SelectVideo->setText(QApplication::translate("SelectFun", "\351\200\211 \346\213\251 \350\247\206 \351\242\221", Q_NULLPTR));
        SimuCon->setText(QApplication::translate("SelectFun", "\351\242\204\346\265\213\345\210\206\346\236\220", Q_NULLPTR));
        getavi->setText(QApplication::translate("SelectFun", "\345\256\236 \346\227\266 \350\247\206 \351\242\221", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SelectFun: public Ui_SelectFun {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTFUN_H
