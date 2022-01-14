/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Smart_Process.h
 * Author: rlcancian
 *
 * Created on 3 de Setembro de 2019, 18:34
 */

#ifndef SMART_PROCESS_H
#define SMART_PROCESS_H

#include "../../applications/BaseConsoleGenesysApplication.h"

class Smart_Process : public BaseConsoleGenesysApplication {
public:
	Smart_Process();
public:
	virtual int main(int argc, char** argv);
};

#endif /* SMART_PROCESS_H */

