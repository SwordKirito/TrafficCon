/********************************************************************************
** Form generated from reading UI file 'simuCon.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMUCON_H
#define UI_SIMUCON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_simuCon
{
public:
    QLabel *label;
    QPushButton *Imsure;
    QLabel *label_2;
    QLineEdit *peoplenum;
    QLineEdit *staytime;
    QLabel *label_3;
    QLineEdit *timenum;
    QListView *listView;

    void setupUi(QWidget *simuCon)
    {
        if (simuCon->objectName().isEmpty())
            simuCon->setObjectName(QStringLiteral("simuCon"));
        simuCon->resize(732, 459);
        label = new QLabel(simuCon);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 130, 241, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(12);
        label->setFont(font);
        Imsure = new QPushButton(simuCon);
        Imsure->setObjectName(QStringLiteral("Imsure"));
        Imsure->setGeometry(QRect(290, 290, 141, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(10);
        Imsure->setFont(font1);
        Imsure->setStyleSheet(QLatin1String("background-color: rgb(144, 255, 255);\n"
"border-color: rgb(190, 255, 232);\n"
""));
        label_2 = new QLabel(simuCon);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 210, 281, 51));
        label_2->setFont(font);
        peoplenum = new QLineEdit(simuCon);
        peoplenum->setObjectName(QStringLiteral("peoplenum"));
        peoplenum->setGeometry(QRect(380, 130, 201, 51));
        peoplenum->setFont(font);
        peoplenum->setStyleSheet(QStringLiteral("border-color: rgb(202, 202, 202);"));
        peoplenum->setCursorPosition(0);
        peoplenum->setClearButtonEnabled(false);
        staytime = new QLineEdit(simuCon);
        staytime->setObjectName(QStringLiteral("staytime"));
        staytime->setGeometry(QRect(380, 210, 201, 51));
        staytime->setFont(font);
        label_3 = new QLabel(simuCon);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(100, 60, 261, 51));
        label_3->setFont(font);
        label_3->setFrameShape(QFrame::Panel);
        label_3->setFrameShadow(QFrame::Sunken);
        label_3->setLineWidth(0);
        timenum = new QLineEdit(simuCon);
        timenum->setObjectName(QStringLiteral("timenum"));
        timenum->setGeometry(QRect(380, 60, 201, 51));
        timenum->setFont(font);
        listView = new QListView(simuCon);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(0, 0, 731, 461));
        listView->setStyleSheet(QStringLiteral("border-image: url(:/TrafficCon/image/back2.jpg);"));
        listView->raise();
        label->raise();
        Imsure->raise();
        label_2->raise();
        peoplenum->raise();
        staytime->raise();
        label_3->raise();
        timenum->raise();

        retranslateUi(simuCon);
        QObject::connect(Imsure, SIGNAL(clicked()), simuCon, SLOT(ShowRes()));

        QMetaObject::connectSlotsByName(simuCon);
    } // setupUi

    void retranslateUi(QWidget *simuCon)
    {
        simuCon->setWindowTitle(QApplication::translate("simuCon", "simuCon", Q_NULLPTR));
        label->setText(QApplication::translate("simuCon", "\347\251\272\351\227\264\346\234\200\345\244\247\345\256\271\351\207\217(\344\272\272)\357\274\232", Q_NULLPTR));
        Imsure->setText(QApplication::translate("simuCon", "\347\241\256  \350\256\244", Q_NULLPTR));
        label_2->setText(QApplication::translate("simuCon", "\351\242\204\350\256\241\347\255\211\345\276\205\346\227\266\351\227\264(\347\247\222)\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("simuCon", "\351\234\200\350\246\201\345\210\206\346\236\220\350\207\263\345\207\240\346\227\266\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class simuCon: public Ui_simuCon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMUCON_H
