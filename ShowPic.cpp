//#pragma execution_character_set("utf-8")
#include "ShowPic.h"

ShowPic::ShowPic(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromLocal8Bit("展示成果"));
	this->setFixedSize(this->width(), this->height());
	this->setWindowIcon(QIcon("image/head.png"));
	intval = new QIntValidator(0, 10, this);
	ui.lineEdit->setValidator(intval);

}

ShowPic::~ShowPic()
{
}
void ShowPic::ShowPicture() {
	stringstream str1;
	int numen;
	numen = ui.lineEdit->text().toInt();
	str1 << numen;
	photostr = str1.str();
	AreaPicture* ans;
 	ans = new AreaPicture();
	ans->gettype1(type);
	ans->getPhotostr(photostr);
	
       ans->show();
	
	
}
void ShowPic::gettype(string n) {
	type = n;

}