/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Smart_HoldSignal.h
 * Author: rlcancian
 *
 * Created on 3 de Setembro de 2019, 18:34
 */

#ifndef SMART_HOLDSIGNAL_H
#define SMART_HOLDSIGNAL_H

#include "../../../BaseGenesysTerminalApplication.h"

class Smart_HoldSignal : public BaseConsoleGenesysApplication {
public:
	Smart_HoldSignal();
public:
	virtual int main(int argc, char** argv);
};

#endif /* SMART_HOLDSIGNAL_H */

