#include "mainwindow.h"
#include <QApplication>


#include "../../../GenesysApplication_if.h"
#include "../../../TraitsApp.h"


int mainGraphicQtApp(int argc, char *argv[]) {
	QApplication a(argc, argv);
	MainWindow w;
	w.showMaximized(); //.show();
	return a.exec();
}

int mainTerminalApp(int argc, char *argv[]) {
	GenesysApplication_if *app = new TraitsApp<GenesysApplication_if>::Application();
	int res = app->main(argc, argv);
	return res;

}

int main(int argc, char *argv[]) {
	bool runGUI = true;
	if (runGUI) {
		return mainGraphicQtApp(argc, argv);
	} else {
		return mainTerminalApp(argc, argv);
	}
}

