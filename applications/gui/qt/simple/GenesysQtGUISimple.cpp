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

#include "GenesysQtGUISimple.h"
#include <QApplication>
#include "simpleMainWindow.h"

GenesysQtGUISimple::GenesysQtGUISimple() {
}

int GenesysQtGUISimple::main(int argc, char** argv) {
	QApplication app(argc, argv);
	simpleMainWindow w;
	w.show();
	return app.exec();
}
