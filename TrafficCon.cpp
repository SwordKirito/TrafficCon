#include "TrafficCon.h"


TrafficCon::TrafficCon(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromLocal8Bit("Ð£Ô°Óµ¶Â±ÜÃâÏµÍ³"));
	this->setWindowIcon(QIcon("image/head.png"));
	this->setFixedSize(this->width(),this->height());
}

void TrafficCon::On_Enter_Clicked() {
	this->hide();
	selfun = new SelectFun();
	selfun->show();
}
