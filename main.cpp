/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/* 
 * File:   main.cpp
 * Author: rafael.luiz.cancian
 *
 * Created on 21 de Junho de 2018, 12:47
 */

/* The DEVELOPMENT2021 branch */

#include <iostream>
#include "Traits.h"
#include <experimental/filesystem>
#include <sys/stat.h>
#include <thread>

/*!
 * This is the MAIN application of GenESyS. It just calls the Application specificied on the configuration/traits file.
 * This file should NOT be changed. Configure the application to be executed using Traits<GenesysApplication_if>
 */
int main(int argc, char** argv) {
	// do not change it. Set you own application in Traits file => Traits<GenesysApplication_if>::Application
	GenesysApplication_if *app = new Traits<GenesysApplication_if>::Application();
	int res = app->main(argc, argv);
	// that's all folks!!
	std::cout << "Press ENTER to quit...";
	std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
	return res;
}
