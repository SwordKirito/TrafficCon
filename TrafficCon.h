#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TrafficCon.h"
#include "SelectFun.h"

class TrafficCon : public QMainWindow
{
	Q_OBJECT

public:
	TrafficCon(QWidget *parent = Q_NULLPTR);

private:
	Ui::TrafficConClass ui;
	SelectFun*  selfun;
private slots:
	void On_Enter_Clicked();
};
