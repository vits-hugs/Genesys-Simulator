/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GenesysQtGUI.cpp
 * Author: rlcancian
 * 
 * Created on 20 de maio de 2021, 14:37
 */

#include "GenesysQtGUIFull.h"
#include <QApplication>
#include "mainWindow/mainwindow.h"

GenesysQtGUIFull::GenesysQtGUIFull() {
}

int GenesysQtGUIFull::main(int argc, char** argv) {
	QApplication app(argc, argv);
	MainWindow w;
	w.show();
	return app.exec();
}
