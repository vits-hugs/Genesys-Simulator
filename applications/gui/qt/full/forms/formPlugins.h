/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   formPlugins.h
 * Author: rlcancian
 *
 * Created on 22 de julho de 2021, 12:47
 */

#ifndef _FORMPLUGINS_H
#define _FORMPLUGINS_H

#include "ui_formPlugins.h"

class formPlugins : public QDialog {
	Q_OBJECT
public:
	formPlugins();
	virtual ~formPlugins();
private:
	Ui::formPlugins widget;
};

#endif /* _FORMPLUGINS_H */
