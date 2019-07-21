#include "TrafficCon.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	TrafficCon w;
	w.show();
	return a.exec();
}
