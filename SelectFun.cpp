#include "SelectFun.h"

SelectFun::SelectFun(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromLocal8Bit("Ñ¡Ôñ¹¦ÄÜ"));
	this->setFixedSize(this->width(), this->height());
	this->setWindowIcon(QIcon("image/head.png"));
}

SelectFun::~SelectFun()
{
}

void SelectFun::On_SelectVideo_Clicked() {
	selvid = new SelectVideoFun();
	selvid->show();
}

void SelectFun::On_SimuCon_Clicked() {
	simcon = new simuCon();
	//simcon->getNum(selvid->num);
	simcon->show();

}
void SelectFun::getavi_Clicked() {
	Getavi = new getavi();
	Getavi->show();

}
