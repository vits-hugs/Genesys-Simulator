/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ModelPersistenceDefaultImpl2.h
 * Author: rlcancian
 *
 * Created on 4 de agosto de 2022, 12:56
 */

#ifndef MODELPERSISTENCEDEFAULTIMPL2_H
#define MODELPERSISTENCEDEFAULTIMPL2_H

#include "ModelPersistence_if.h"
#include "Model.h"


class ModelPersistenceDefaultImpl2 : public ModelPersistence_if {
public:
	ModelPersistenceDefaultImpl2(Model* model);

public: // ModelPersistence_if interface
	bool save(std::string filename) override;
	bool load(std::string filename) override;
	bool hasChanged() override;
	bool getOption(ModelPersistence_if::Options option) override;
	void setOption(ModelPersistence_if::Options option, bool value) override;
	std::string getFormatedField(PersistenceRecord *fields) override;

private:
	Model* _model;
	unsigned short _options{0};
	bool _dirty{false};
};


#endif /* MODELPERSISTENCEDEFAULTIMPL2_H */

