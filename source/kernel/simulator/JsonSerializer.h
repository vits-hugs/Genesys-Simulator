/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   JsonSerializer.h
 * Author: rlcancian
 *
 * Created on 4 de agosto de 2022, 13:03
 */

#ifndef JSONSERIALIZER_H
#define JSONSERIALIZER_H


#include <unordered_map>

#include "ModelSerializer.h"
#include "Model.h"


class JsonSerializer : public ModelSerializer {
public:
    explicit JsonSerializer(Model *model);

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
#endif /* JSONSERIALIZER_H */

