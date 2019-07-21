#pragma once

#include <QWidget>
#include "ui_SelectFun.h"
#include "SelectVideoFun.h"
#include "simuCon.h"
#include "getavi.h"

class SelectFun : public QWidget
{
	Q_OBJECT

public:
	SelectFun(QWidget *parent = Q_NULLPTR);
	~SelectFun();

private:
	Ui::SelectFun ui;
	SelectVideoFun* selvid;
	simuCon* simcon;
	getavi* Getavi;
private slots:
	void On_SelectVideo_Clicked();
	void On_SimuCon_Clicked();
	void getavi_Clicked();
};
