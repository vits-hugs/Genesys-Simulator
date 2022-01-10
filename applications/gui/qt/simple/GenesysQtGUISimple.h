/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GenesysQtGUI.h
 * Author: rlcancian
 *
 * Created on 20 de maio de 2021, 14:37
 */

// no ubuntu, instalar libqt5webkit5-dev
// sudo apt-get install libqt5webkit5-dev

#ifndef GENESYSQTGUISIMPLE_H
#define GENESYSQTGUISIMPLE_H

#include "../../../GenesysApplication_if.h"

class GenesysQtGUISimple : public GenesysApplication_if {
public:
	GenesysQtGUISimple();
public:
	virtual int main(int argc, char** argv);
private:

};

#endif /* GENESYSQTGUISIMPLE_H */

