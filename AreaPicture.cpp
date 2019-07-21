#include "AreaPicture.h"

AreaPicture::AreaPicture(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromLocal8Bit("½á¹ûÍ¼"));
	this->setWindowIcon(QIcon("image/head.png"));
}

AreaPicture::~AreaPicture()
{
}
void AreaPicture::gettype1(string k) {
	typestr = k;
}
void AreaPicture::getPhotostr(string m) {
	photostr = m;
	cv::Mat image1;

	image1 = cv::imread("C:/Users/Sword.Kirito/source/repos/TrafficCon/TrafficCon/tiaokongphoto/"+photostr+typestr+".jpg");
	cvtColor(image1, image1, CV_BGR2RGB);
	cv::resize(image1, image1, cv::Size(800, 600));
	QImage img1 = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, QImage::Format_RGB888);
	QLabel* label1;
	label1 = new QLabel();
	label1->setPixmap(QPixmap::fromImage(img1));
	label1->resize(QSize(img1.width(), img1.height()));
	ui.Before->setWidget(label1);
	cv::Mat image;
	image = cv::imread("C:/Users/Sword.Kirito/source/repos/TrafficCon/TrafficCon/tiaokongphoto/"+photostr+"after"+typestr+".jpg");
	cvtColor(image, image, CV_BGR2RGB);
	cv::resize(image, image, cv::Size(800, 600));
	QImage img = QImage((const unsigned char*)(image.data), image.cols, image.rows, QImage::Format_RGB888);
	QLabel* label;
	label = new QLabel();
	label->setPixmap(QPixmap::fromImage(img));
	label->resize(QSize(img.width(), img.height()));
	ui.After->setWidget(label);
}
