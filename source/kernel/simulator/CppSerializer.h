/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   CppSerializer.h
 * Author: rlcancian
 *
 * Created on 4 de agosto de 2022, 13:04
 */

#ifndef CPPSERIALIZER_H
#define CPPSERIALIZER_H

c
#include <unordered_map>

#include "ModelSerializer.h"
#include "Model.h"


class CppSerializer : public ModelSerializer {
public:
    explicit CppSerializer(Model *model);

public: // ModelSerializer interface
    PersistenceRecord* newPersistenceRecord() override;
    bool dump(std::ostream& output) override;
    bool load(std::istream& input) override;
    bool get(const std::string& name, PersistenceRecord *entry) override;
    bool put(const std::string name, const std::string type, const Util::identification id, PersistenceRecord *fields) override;
    int for_each(std::function<int(const std::string&)> delegate) override;

private:
    Model *_model{};
    std::unordered_map<std::string, std::unique_ptr<PersistenceRecord>> _metaobjects{};
    std::unordered_map<std::string, std::unique_ptr<PersistenceRecord>> _components{};
};


#endif /* CPPSERIALIZER_H */

