#pragma once

#include <QWidget>
#include "ui_ShowPic.h"
#include "AreaPicture.h"
#include <QIntValidator>
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
//using namespace cv;
class ShowPic : public QWidget
{
	Q_OBJECT

public:
	ShowPic(QWidget *parent = Q_NULLPTR);
	~ShowPic();
	QIntValidator* intval;
	string photostr;
	string type;
	void  gettype(string);
private:
	Ui::ShowPic ui;
private slots:
	void ShowPicture();
};
