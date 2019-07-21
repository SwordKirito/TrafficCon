#pragma execution_character_set("utf-8")
#include "getavi.h"
int tishi = 0;
getavi::getavi(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("获取视频");
	//this->setFixedSize(this->width(), this->height());
	this->setWindowIcon(QIcon("image/head.png"));
}

getavi::~getavi()
{
}

void getavi::button3() {
	tishi = (ui.lineEdit->text()).toInt();
	QMessageBox::information(this, tr("提示"), tr("  完成  "));
}
void getavi::button4() {
	tishi = 10;
	QMessageBox::information(this, tr("提示"), tr("提示值默认设置为10"));
}

  void getavi::button1() {
	  num++;
	  stringstream str;
	  str << "self"<<num;
	//打开电脑摄像头
	cv::VideoCapture cap(0);
	if (!cap.isOpened())
	{
		QMessageBox::information(NULL, "Title", "无法打开摄像机", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		cv::waitKey(0);
		return;
	}

	//获得cap的分辨率
	int w = static_cast<int>(cap.get(CV_CAP_PROP_FRAME_WIDTH));
	int h = static_cast<int>(cap.get(CV_CAP_PROP_FRAME_HEIGHT));
	cv::Size videoSize(w, h);
	cv::VideoWriter writer(str.str()+".avi", CV_FOURCC('M', 'J', 'P', 'G'), 25, videoSize);

	cv::Mat frame;
	int key;//记录键盘按键
	char startOrStop = 1;//0  开始录制视频； 1 结束录制视频
	char flag = 0;//正在录制标志 0-不在录制； 1-正在录制

	while (1)
	{
		cap >> frame;
		key = cv::waitKey(100);
		if (key == 32)//按下空格开始录制、暂停录制   可以来回切换
		{
			startOrStop = 1 - startOrStop;
			if (startOrStop == 0)
			{
				flag = 1;
			}
		}
		if (key == 27)//按下ESC退出整个程序，保存视频文件到磁盘
		{
			ui.label->setText("完成录制");
		
			break;
		}

		if (startOrStop == 0 && flag == 1)
		{
			writer << frame;
			ui.label->setText("正在录制");
			//	cout << "recording" << endl;
		}
		else if (startOrStop == 1)
		{
			flag = 0;
			ui.label->setText("等待开始");
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
	  //打开电脑摄像头
	  cv::VideoCapture cap(0);
	  if (!cap.isOpened())
	  {
		  QMessageBox::information(NULL, "Title", "无法打开摄像机", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		 // cout << "error" << endl;
		  cv::waitKey(0);
		  return;
	  }

	  //获得cap的分辨率
	  int w = static_cast<int>(cap.get(CV_CAP_PROP_FRAME_WIDTH));
	  int h = static_cast<int>(cap.get(CV_CAP_PROP_FRAME_HEIGHT));
	  cv::Size videoSize(w, h);
	  cv::VideoWriter writer("timeself"+str.str()+".avi", CV_FOURCC('M', 'J', 'P', 'G'), 25, videoSize);

	  cv::Mat frame;
	  int key;//记录键盘按键
	  char startOrStop = 1;//0  开始录制视频； 1 结束录制视频
	  char flag = 0;//正在录制标志 0-不在录制； 1-正在录制

	  while (1)
	  {
		  cap >> frame;
		  key = cv::waitKey(100);
		  if (key == 32)//按下空格开始录制、暂停录制   可以来回切换
		  {
			  startOrStop = 1 - startOrStop;
			  if (startOrStop == 0)
			  {
				  flag = 1;
			  }
		  }
		  if (key == 27)//按下ESC退出整个程序，保存视频文件到磁盘
		  {
			  	ui.label->setText("完成识别");
			   outfile.close();
			   break;
		  }

		  if (startOrStop == 0 && flag == 1)
		  {

			  writer << frame;
			  	ui.label->setText("正在识别");
			//  cout << "recording" << endl;
				imwrite("2.jpg", frame);
			  cv::Mat image = cv::imread("2.jpg");
			  //	i = i + 1;
				  // 1. 定义HOG对象  
			  cv::HOGDescriptor hog; // 采用默认参数  
			  // 2. 设置SVM分类器  
			  hog.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());   // 采用已经训练好的行人检测分类器  
			  // 3. 在测试图像上检测行人区域  
			  std::vector<cv::Rect> regions;
			  hog.detectMultiScale(image, regions, 0, cv::Size(8, 8), cv::Size(32, 32), 1.05, 1);
			  // 显示  
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
				  outstr << "第" << time << "时刻存在有： " << j << "个人" << "(注意！！！超出设定值)"<<endl;
			  }
			  else {
				  outstr << "第" << time << "时刻存在有： " << j << "个人" << endl;
			  }
			  time++;
		  }
		  else if (startOrStop == 1)
		  {
			  flag = 0;
			 	ui.label->setText("等待开始");
		  }
		  imshow("picture", frame);
	  }
	  ui.textBrowser->setText(QString::fromStdString(outstr.str()));
	  cap.release();
	  writer.release();
	  cv::destroyAllWindows();

  }