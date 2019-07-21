#pragma once

#include <QWidget>
#include "ui_getavi.h"
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
//#include<QMessageBox>
#include<Windows.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//#include<dos.h>
//#include<stdio.h>
using namespace std;
//using namespace cv;
class getavi : public QWidget
{
	Q_OBJECT

public:
	getavi(QWidget *parent = Q_NULLPTR);
	~getavi();

private:
	Ui::getavi ui;
	int num=0;
	
private slots:
     void button1();
	 void button2();
	 
	 void button3();
	 void button4();
	 
};
