#pragma once

#include <QWidget>
#include "ui_SelectVideoFun.h"

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

class SelectVideoFun : public QWidget
{
	Q_OBJECT

public:
	string filename;
	SelectVideoFun(QWidget *parent = Q_NULLPTR);
	~SelectVideoFun();
	 int num;
	 stringstream  mingxi;
	 long currentFrame;
	 int j;
	 long totalFrameNumber=0;
	// QString currentPath;
	

private:
	Ui::SelectVideoFun ui;
private slots:
	void getVideoPath();
	void dealVideo();
	void showDetail();
	void showPic();
};
