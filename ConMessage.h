#pragma once


#include <QWidget>
#include "ui_ConMessage.h"
#include "ShowPic.h"
#include <qtextcodec.h>
#include <string>
#include <QString>
#include <QTimer>
#include <QImage>
#include <QFileDialog>
#include <string>
#include <iostream>  
#include <stdio.h>
#include<sstream>
#include<fstream>
#include<stdlib.h>
#include<qmessagebox.h>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


using namespace std;
//using namespace  cv;

class ConMessage : public QWidget
{
	Q_OBJECT

public:
	ConMessage(QWidget *parent = Q_NULLPTR);
	~ConMessage();
	void gettiao(string);

private:
	Ui::ConMessage ui;
	ShowPic* onpeople;
	ShowPic* ontimes;
	string mes;

private slots:
	void OnPeople();
	void OnTime();
	void ShowDetail();
};
