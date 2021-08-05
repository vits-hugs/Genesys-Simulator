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

#include <iostream>
#include "Traits.h"
#include <experimental/filesystem>
#include <sys/stat.h>

/*
 * This is the MAIN application of GenESyS. It just calls the Application specificied on the configuration/traits file.
 */
int main(int argc, char** argv) {
    /*
    std::string argv_str(argv[0]);
    std::string base = argv_str.substr(0, argv_str.find_last_of("/"));
    //std::string path = std::experimental::filesystem::current_path();
    
    std::string pathExec = getRunningPath();
    const std::string pathFromExecToPlugin = "/../../../plugins/components";
    std::string dir = pathExec + pathFromExecToPlugin;
    std::vector<std::string> files = listFiles(dir, ".h", S_IFREG); // S_IFREG & S_IFDIR
    for (unsigned int i = 0; i < files.size(); i++) {
        std::cout << files[i] << std::endl;
    } 
     */  
    // do not change it. Set you own application in Traits file => Traits<GenesysApplication_if>::Application
    GenesysApplication_if *app = new Traits<GenesysApplication_if>::Application();
    int res = app->main(argc, argv);
    // that's all folks!!
    //std::cout << "Press ENTER to quit...";
    //std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
    return res;
}
