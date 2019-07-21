#include "TrafficCon.h"


TrafficCon::TrafficCon(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromLocal8Bit("У԰ӵ�±���ϵͳ"));
	this->setWindowIcon(QIcon("image/head.png"));
	this->setFixedSize(this->width(),this->height());
}

void TrafficCon::On_Enter_Clicked() {
	this->hide();
	selfun = new SelectFun();
	selfun->show();
}
