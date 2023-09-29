//
// Created by vitorh on 16/11/23.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "CollectorOutputAnalyser.h"


void CollectorOutputAnalyser::setReplicationNumber(int replicationNumber) {
    _readPos = 0;
    _replicationNumber = replicationNumber;
    _datavector.clear();
    std::ifstream arquivo(_filename); // Abre o arquivo para leitura
    bool start=false;
    if (arquivo.is_open()) { // Verifica se o arquivo foi aberto com sucesso
        std::string linha;

        // Lê cada linha do arquivo
        while (std::getline(arquivo, linha)) {
            if(linha.empty() || linha[0] == '#') {
                if(start==true && (linha.find("#Replication")!= std::string::npos)) {
                    arquivo.close();
                    return;
                }
                if(!linha.compare("#ReplicationNumber=" + std::to_string(_replicationNumber))){
                    start=true;
                }

                continue;
            }

            if(start){
                std::istringstream iss(linha);
                double time,valor;
                Data data;
                if(linha.find(' ') != std::string::npos){
                    iss >> time >>valor;
                    data.value = valor;
                    data.time = time;
                } else {
                    iss >> valor;
                    data.value = valor;
                    data.time = -1;

                }

                _datavector.push_back(data);

            }


        }
        if(!start) {
            throw std::runtime_error("Replicação não encontrada");
        }

    } else {
        throw std::runtime_error("Arquivo não encontrado");
    }
}

double CollectorOutputAnalyser::getValue(unsigned int rank) {
    return _datavector[rank].value;
}

double CollectorOutputAnalyser::getSize() {
    return _datavector.size();
}

void CollectorOutputAnalyser::seekFirstValue() {
    _readPos = 0;
}

double CollectorOutputAnalyser::getNextValue() {
    return _datavector[_readPos++].value;
}

std::string CollectorOutputAnalyser::getDataFilename() {
    return _filename;
}

void CollectorOutputAnalyser::setDataFilename(std::string filename) {
    _filename = filename;
    setReplicationNumber(_replicationNumber);
}

void CollectorOutputAnalyser::clear() {
    _datavector.clear();
    _readPos = 0;
    if (_clearHandler != nullptr) {
        _clearHandler();
    }
}

void CollectorOutputAnalyser::addValue(double value, double weight) {
    _datavector.push_back({value,weight});
    if (_addValueHandler != nullptr) {
        _addValueHandler(value, weight);
    }
}

double CollectorOutputAnalyser::getLastValue() {
    return _datavector[_datavector.size()-1].value;
}

unsigned long CollectorOutputAnalyser::numElements() {
    return _datavector.size();
}

void CollectorOutputAnalyser::setAddValueHandler(CollectorAddValueHandler addValueHandler) {
    _addValueHandler = addValueHandler;
}

void CollectorOutputAnalyser::setClearHandler(CollectorClearHandler clearHandler) {
    _clearHandler = clearHandler;
}

std::vector<CollectorOutputAnalyser::Data>::iterator CollectorOutputAnalyser::begin() {
    return _datavector.begin();
}

std::vector<CollectorOutputAnalyser::Data>::iterator CollectorOutputAnalyser::end() {
    return _datavector.end();
}

void CollectorOutputAnalyser::sort() {
    std::sort(begin(),end());
}

std::string CollectorOutputAnalyser::toString() const {
    std::stringstream oss;
    oss << std::fixed << std::setprecision(3);
    oss << "[ ";
     for (auto entry : _datavector) {
         oss << entry.value << " ";
     }
    oss << "]";
    return oss.str();
}

CollectorDatafile_if *CollectorOutputAnalyser::clone() const {
    return new CollectorOutputAnalyser(*this);
}

