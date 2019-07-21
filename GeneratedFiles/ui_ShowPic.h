/********************************************************************************
** Form generated from reading UI file 'ShowPic.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWPIC_H
#define UI_SHOWPIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowPic
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *Choose;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *ShowPic)
    {
        if (ShowPic->objectName().isEmpty())
            ShowPic->setObjectName(QStringLiteral("ShowPic"));
        ShowPic->resize(489, 257);
        label = new QLabel(ShowPic);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(260, 40, 81, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(10);
        label->setFont(font);
        lineEdit = new QLineEdit(ShowPic);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(360, 40, 113, 41));
        lineEdit->setFont(font);
        Choose = new QPushButton(ShowPic);
        Choose->setObjectName(QStringLiteral("Choose"));
        Choose->setGeometry(QRect(310, 150, 111, 41));
        label_2 = new QLabel(ShowPic);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 0, 241, 251));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/TrafficCon/image/\345\244\232\351\227\250\351\244\220\345\216\205\345\271\263\351\235\242\345\233\276.jfif);"));
        label_3 = new QLabel(ShowPic);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(270, 90, 171, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        label_3->setFont(font1);
        label_3->setFrameShape(QFrame::Panel);
        label_3->setFrameShadow(QFrame::Sunken);
        label_3->setLineWidth(0);

        retranslateUi(ShowPic);
        QObject::connect(Choose, SIGNAL(clicked()), ShowPic, SLOT(ShowPicture()));

        QMetaObject::connectSlotsByName(ShowPic);
    } // setupUi

    void retranslateUi(QWidget *ShowPic)
    {
        ShowPic->setWindowTitle(QApplication::translate("ShowPic", "ShowPic", Q_NULLPTR));
        label->setText(QApplication::translate("ShowPic", "\351\200\211\346\213\251\345\205\245\345\217\243\357\274\232", Q_NULLPTR));
        Choose->setText(QApplication::translate("ShowPic", "\347\241\256 \350\256\244", Q_NULLPTR));
        label_2->setText(QString());
        label_3->setText(QApplication::translate("ShowPic", "\350\276\223\345\205\2450\345\215\263\344\270\272\346\200\273\344\275\223\346\203\205\345\206\265", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ShowPic: public Ui_ShowPic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWPIC_H
