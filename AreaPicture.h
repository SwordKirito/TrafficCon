#pragma once

#include <QWidget>
#include "ui_AreaPicture.h"
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

class AreaPicture : public QWidget
{
	Q_OBJECT

public:
	AreaPicture(QWidget *parent = Q_NULLPTR);
	~AreaPicture();
	void getPhotostr(string m);
	void gettype1(string);

private:
	Ui::AreaPicture ui;
	string photostr;
	string typestr;
};
