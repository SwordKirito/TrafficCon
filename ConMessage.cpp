#pragma execution_character_set("utf-8")
#include "ConMessage.h"

ConMessage::ConMessage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("µ÷¿ØÃ÷Ï¸");
	this->setFixedSize(this->width(), this->height());
	this->setWindowIcon(QIcon("image/head.png"));
}

ConMessage::~ConMessage()
{
}
void ConMessage::OnPeople() {
	string peoples = "pep";
	onpeople = new ShowPic();
	onpeople->show();
	onpeople->gettype(peoples);
}

void ConMessage::OnTime() {
	string times = "time";
	ontimes = new ShowPic();
	ontimes->show();
	ontimes->gettype(times);
}
void ConMessage::gettiao(string j) {
	mes = j;
}

void ConMessage::ShowDetail() {

	QString str = QString::fromStdString(mes);

	ui.textBrowser->setText(str);

}
