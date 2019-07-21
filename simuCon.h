#pragma once

#include <QWidget>
#include "ui_simuCon.h"
#include "ConMessage.h"
#include <QIntValidator>
#include <iostream>  
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include<sstream>
#include<fstream>
#include<stdlib.h>
#include <math.h>

#define  x_lowest 0.1		//������͹���ʱ�� (Сʱ�� 
#define  TIME 3600			//����һ��Сʱ 
#define  ENTRENCE 3600
#define  epsilon 1		//����һ����Сֵ 
#define  _MAX 9999		//����һ������ֵ 

using namespace std;
//using namespace cv;

class simuCon : public QWidget
{
	Q_OBJECT

public:

	simuCon(QWidget *parent = Q_NULLPTR);
	~simuCon();

	QIntValidator* intval;
	QIntValidator* intval_2;
	void getNum(int);



private:
	int num;
   
	Ui::simuCon ui;
	ConMessage * conmes;


private slots:
	void ShowRes();
};
