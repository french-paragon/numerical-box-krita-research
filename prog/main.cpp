#include "mainwindow.h"
#include <QApplication>

#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << "getValueFromText" << std::endl;

	QApplication a(argc, argv);
	MainWindow* w = new MainWindow();
	w->show();

	int code = a.exec();

	delete w;

	return code;
}
