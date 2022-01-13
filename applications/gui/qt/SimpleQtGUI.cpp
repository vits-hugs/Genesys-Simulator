/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SimpleQtGUI.cpp
 * Author: rlcancian
 * 
 * Created on 11 de Janeiro de 2021, 15:56
 */

#include "SimpleQtGUI.h"
#include "SimpleGUI_QtCreator/SimpleGUI/mainwindow.h"

#include <QApplication>

SimpleQtGUI::SimpleQtGUI() {
}

/**
 * This is the main function of the application. 
 * It instanciates the simulator, builds a simulation model and then simulate that model.
 */


int SimpleQtGUI::main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	MainWindow w;
	w.showMaximized(); //.show();
	return a.exec();
}

