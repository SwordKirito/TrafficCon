#pragma execution_character_set("utf-8")
#include "getavi.h"
int tishi = 0;
getavi::getavi(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("��ȡ��Ƶ");
	//this->setFixedSize(this->width(), this->height());
	this->setWindowIcon(QIcon("image/head.png"));
}

getavi::~getavi()
{
}

void getavi::button3() {
	tishi = (ui.lineEdit->text()).toInt();
	QMessageBox::information(this, tr("��ʾ"), tr("  ���  "));
}
void getavi::button4() {
	tishi = 10;
	QMessageBox::information(this, tr("��ʾ"), tr("��ʾֵĬ������Ϊ10"));
}

  void getavi::button1() {
	  num++;
	  stringstream str;
	  str << "self"<<num;
	//�򿪵�������ͷ
	cv::VideoCapture cap(0);
	if (!cap.isOpened())
	{
		QMessageBox::information(NULL, "Title", "�޷��������", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		cv::waitKey(0);
		return;
	}

	//���cap�ķֱ���
	int w = static_cast<int>(cap.get(CV_CAP_PROP_FRAME_WIDTH));
	int h = static_cast<int>(cap.get(CV_CAP_PROP_FRAME_HEIGHT));
	cv::Size videoSize(w, h);
	cv::VideoWriter writer(str.str()+".avi", CV_FOURCC('M', 'J', 'P', 'G'), 25, videoSize);

	cv::Mat frame;
	int key;//��¼���̰���
	char startOrStop = 1;//0  ��ʼ¼����Ƶ�� 1 ����¼����Ƶ
	char flag = 0;//����¼�Ʊ�־ 0-����¼�ƣ� 1-����¼��

	while (1)
	{
		cap >> frame;
		key = cv::waitKey(100);
		if (key == 32)//���¿ո�ʼ¼�ơ���ͣ¼��   ���������л�
		{
			startOrStop = 1 - startOrStop;
			if (startOrStop == 0)
			{
				flag = 1;
			}
		}
		if (key == 27)//����ESC�˳��������򣬱�����Ƶ�ļ�������
		{
			ui.label->setText("���¼��");
		
			break;
		}

		if (startOrStop == 0 && flag == 1)
		{
			writer << frame;
			ui.label->setText("����¼��");
			//	cout << "recording" << endl;
		}
		else if (startOrStop == 1)
		{
			flag = 0;
			ui.label->setText("�ȴ���ʼ");
			//	cout << "end recording" << endl;

		}
		imshow("picture", frame);
	}
	cap.release();
	writer.release();
	cv::destroyAllWindows();

}
  void getavi::button2() {
	  num++;
	  stringstream str;
	  str  << num;
	  int time = 1;
	  stringstream outstr;
	  ofstream outfile("C:/Users/Sword.Kirito/source/repos/TrafficCon/TrafficCon/"+str.str()+".txt", ios::in | ios::out | ios::binary);
	  //�򿪵�������ͷ
	  cv::VideoCapture cap(0);
	  if (!cap.isOpened())
	  {
		  QMessageBox::information(NULL, "Title", "�޷��������", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		 // cout << "error" << endl;
		  cv::waitKey(0);
		  return;
	  }

	  //���cap�ķֱ���
	  int w = static_cast<int>(cap.get(CV_CAP_PROP_FRAME_WIDTH));
	  int h = static_cast<int>(cap.get(CV_CAP_PROP_FRAME_HEIGHT));
	  cv::Size videoSize(w, h);
	  cv::VideoWriter writer("timeself"+str.str()+".avi", CV_FOURCC('M', 'J', 'P', 'G'), 25, videoSize);

	  cv::Mat frame;
	  int key;//��¼���̰���
	  char startOrStop = 1;//0  ��ʼ¼����Ƶ�� 1 ����¼����Ƶ
	  char flag = 0;//����¼�Ʊ�־ 0-����¼�ƣ� 1-����¼��

	  while (1)
	  {
		  cap >> frame;
		  key = cv::waitKey(100);
		  if (key == 32)//���¿ո�ʼ¼�ơ���ͣ¼��   ���������л�
		  {
			  startOrStop = 1 - startOrStop;
			  if (startOrStop == 0)
			  {
				  flag = 1;
			  }
		  }
		  if (key == 27)//����ESC�˳��������򣬱�����Ƶ�ļ�������
		  {
			  	ui.label->setText("���ʶ��");
			   outfile.close();
			   break;
		  }

		  if (startOrStop == 0 && flag == 1)
		  {

			  writer << frame;
			  	ui.label->setText("����ʶ��");
			//  cout << "recording" << endl;
				imwrite("2.jpg", frame);
			  cv::Mat image = cv::imread("2.jpg");
			  //	i = i + 1;
				  // 1. ����HOG����  
			  cv::HOGDescriptor hog; // ����Ĭ�ϲ���  
			  // 2. ����SVM������  
			  hog.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());   // �����Ѿ�ѵ���õ����˼�������  
			  // 3. �ڲ���ͼ���ϼ����������  
			  std::vector<cv::Rect> regions;
			  hog.detectMultiScale(image, regions, 0, cv::Size(8, 8), cv::Size(32, 32), 1.05, 1);
			  // ��ʾ  
			  int j = 0;
			  for (size_t i = 0; i < regions.size(); i++)
			  {
				  cv::rectangle(image, regions[i], cv::Scalar(0, 0, 255), 2);
				  j++;
			  }
			  
			  if (j >= tishi) {
				  Beep(500, 500);
				//  cout << 'a';
			  }
			  
			  outfile << j << " ";
			  outfile << "\r\n";
			  if (j >= tishi) {
				  outstr << "��" << time << "ʱ�̴����У� " << j << "����" << "(ע�⣡���������趨ֵ)"<<endl;
			  }
			  else {
				  outstr << "��" << time << "ʱ�̴����У� " << j << "����" << endl;
			  }
			  time++;
		  }
		  else if (startOrStop == 1)
		  {
			  flag = 0;
			 	ui.label->setText("�ȴ���ʼ");
		  }
		  imshow("picture", frame);
	  }
	  ui.textBrowser->setText(QString::fromStdString(outstr.str()));
	  cap.release();
	  writer.release();
	  cv::destroyAllWindows();

  }