/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.h to edit this template
 */

/* 
 * File:   simpleMainWindow.h
 * Author: rlcancian
 *
 * Created on 10 de janeiro de 2022, 15:22
 */

#ifndef _SIMPLEMAINWINDOW_H
#define _SIMPLEMAINWINDOW_H

#include "ui_simpleMainWindow.h"

class simpleMainWindow : public QMainWindow {
	Q_OBJECT
public:
	simpleMainWindow();
	virtual ~simpleMainWindow();
private:
	Ui::simpleMainWindow widget;
};

#endif /* _SIMPLEMAINWINDOW_H */
