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

#ifndef GENESYSQTGUI_H
#define GENESYSQTGUI_H

#include "../../GenesysApplication_if.h"
class GenesysQtGUI: public GenesysApplication_if {
public:
    GenesysQtGUI();
public:
	virtual int main(int argc, char** argv);
private:

};

#endif /* GENESYSQTGUI_H */

