#pragma execution_character_set("utf-8")
#include "SelectVideoFun.h"
#include <qdir.h>

SelectVideoFun::SelectVideoFun(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("ѡ����Ƶ");
	this->setFixedSize(this->width(), this->height());
	this->setWindowIcon(QIcon("image/head.png"));
	num = 0;
	ui.tabWidget->setCurrentIndex(1);	
	QString text = QDir::currentPath();
}

SelectVideoFun::~SelectVideoFun()
{
}
void SelectVideoFun::getVideoPath() {
	num++;
	QString file_name = QFileDialog::getOpenFileName(this, "ѡ����Ƶ", ".", tr("Video File(*.avi *.mp4 *.h264)"));
	ui.lineEdit->setText(file_name);
	filename = file_name.toStdString();
}

void SelectVideoFun::dealVideo() {	
//	string path = currentPath.toStdString();
	QMessageBox::information(NULL, "Title", "���ڴ���", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	//ui.label_3->setText("���ڴ������Ժ�....");
	stringstream strnum;
	strnum << num;
	stringstream strnum1;
	strnum1 << filename;
	//��ȡ��Ƶ�ļ�
	cv::VideoCapture cap(strnum1.str());
	totalFrameNumber = 0;
	//��ȡ��Ƶ��֡��
	totalFrameNumber = cap.get(CV_CAP_PROP_FRAME_COUNT);
	cv::Mat frame;
	bool flags = true;
	 currentFrame = 1;

	while (flags) {
		//��ȡ��Ƶÿһ֡
		cap.read(frame);
		stringstream str;
		str << "/"<<currentFrame << ".jpg";

		//����ÿ1֡��ȡһ��֡
		if (currentFrame % 1 == 0 && currentFrame != 0) {
			//��֡ת��ͼƬ���
			imwrite("C:/Users/Sword.Kirito/source/repos/TrafficCon/TrafficCon/yuanphoto/"+strnum.str() + str.str(), frame);

		}
		//��������
		if (currentFrame >= totalFrameNumber) {
			flags = false;
		}
		currentFrame++;
	}

	
	QMessageBox::information(NULL, "Title", "��ɴ���", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
  //	ui.label_3->setText("");
	
}

void SelectVideoFun::showDetail() {
//	string path = currentPath.toStdString();
	if(num==0)
		QMessageBox::information(NULL, "Title", "���ȴ�����Ƶ", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	else {
		int *pepnum = new int[totalFrameNumber];
		stringstream strnum2;
		strnum2 << num;
		for (int i = 1; i <=totalFrameNumber; i++) {
			stringstream str2;
			str2 << "/" << i << ".jpg";
		 cv::Mat image = cv::imread("C:/Users/Sword.Kirito/source/repos/TrafficCon/TrafficCon/yuanphoto/" + strnum2.str() + str2.str());
			// 1. ����HOG����  
			cv::HOGDescriptor hog; // ����Ĭ�ϲ���  
			// 2. ����SVM������  
			hog.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());   // �����Ѿ�ѵ���õ����˼�������  

			// 3. �ڲ���ͼ���ϼ����������  
			std::vector<cv::Rect> regions;
			hog.detectMultiScale(image, regions, 0, cv::Size(8, 8), cv::Size(32, 32), 1.05, 1);
			// ��ʾ  
			j = 0;
			for (size_t i = 0; i < regions.size(); i++)
			{
				cv::rectangle(image, regions[i], cv::Scalar(0, 0, 255), 2);
				j++;
			}
			pepnum[i] = j;
			imwrite("C:/Users/Sword.Kirito/source/repos/TrafficCon/TrafficCon/shibiephoto/" + strnum2.str() + str2.str(), image);
			mingxi << "��" << i << "ʱ�������Ϊ��" << j << "\n";

		}
		ofstream outfile("C:/Users/Sword.Kirito/source/repos/TrafficCon/TrafficCon/txt/" + strnum2.str() + ".txt", ios::in | ios::out | ios::binary);

		for (int i = 1; i < totalFrameNumber; i++)
		{
			outfile << pepnum[i] << " ";
			outfile << "\r\n";
		}
		outfile.close();
		//
		ui.textBrowser->setText(QString::fromStdString(mingxi.str()));
		QMessageBox::information(NULL, "Title", "��ɻ�ȡ��Ϣ", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	}
}


void SelectVideoFun::showPic() {
//	string path = currentPath.toStdString();
	stringstream strnum;
	strnum << num;
	string picnam;
	picnam = ui.spinBox->text().toStdString()+ ".jpg";
	cv::Mat image;
	image = cv::imread("C:/Users/Sword.Kirito/source/repos/TrafficCon/TrafficCon/yuanphoto/"+strnum.str()+"/"+picnam);
	cvtColor(image, image, CV_BGR2RGB);
	cv::resize(image, image, cv::Size(400, 390));
	QImage img = QImage((const unsigned char*)(image.data), image.cols, image.rows, QImage::Format_RGB888);
	QLabel* label;
	label = new QLabel();
	label->setPixmap(QPixmap::fromImage(img));
	label->resize(QSize(img.width(), img.height()));
	ui.scrollArea->setWidget(label);
cv:: Mat image1;
image1 = cv:: imread("C:/Users/Sword.Kirito/source/repos/TrafficCon/TrafficCon/shibiephoto/" + strnum.str() + "/" + picnam);
	cvtColor(image1, image1, CV_BGR2RGB);
	cv::resize(image1, image1, cv::Size(400, 390));
	QImage img1 = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, QImage::Format_RGB888);
	QLabel* label1;
	label1 = new QLabel();
	label1->setPixmap(QPixmap::fromImage(img1));
	label1->resize(QSize(img1.width(), img1.height()));
	ui.scrollArea_2->setWidget(label1);
	
}