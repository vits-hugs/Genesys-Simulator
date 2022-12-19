#include "mainwindow.h"
#include <QApplication>

#include "../../../GenesysApplication_if.h"
#include "../../../TraitsApp.h"

//*************************************************************
// Configure the app: GUI (true) or TerminalApplication (false)
bool runGUI = false;
//*************************************************************

int mainGraphicQtApp(int argc, char *argv[]) {
	QApplication a(argc, argv);
	MainWindow w;
	w.showMaximized(); //.show();
	return a.exec();
}

int mainTerminalApp(int argc, char *argv[]) {
	GenesysApplication_if *app = new TraitsApp<GenesysApplication_if>::Application();
	return app->main(argc, argv);
}

int main(int argc, char *argv[]) {
	if (runGUI) {
		return mainGraphicQtApp(argc, argv);
	} else {
		return mainTerminalApp(argc, argv);
	}
}

