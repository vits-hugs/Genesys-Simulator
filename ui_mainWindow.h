/********************************************************************************
** Form generated from reading UI file 'mainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWindow
{
public:
    QAction *actionNew;
    QAction *actionLoad;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionStart;
    QAction *actionStep;
    QAction *actionStop;
    QAction *actionPause;
    QAction *actionResume;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QMenuBar *menubar;
    QMenu *menuModelo;
    QMenu *menuSimulation;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mainWindow)
    {
        if (mainWindow->objectName().isEmpty())
            mainWindow->setObjectName(QString::fromUtf8("mainWindow"));
        mainWindow->resize(800, 600);
        mainWindow->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        actionNew = new QAction(mainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionLoad = new QAction(mainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionSave = new QAction(mainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionExit = new QAction(mainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionStart = new QAction(mainWindow);
        actionStart->setObjectName(QString::fromUtf8("actionStart"));
        actionStep = new QAction(mainWindow);
        actionStep->setObjectName(QString::fromUtf8("actionStep"));
        actionStop = new QAction(mainWindow);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        actionPause = new QAction(mainWindow);
        actionPause->setObjectName(QString::fromUtf8("actionPause"));
        actionResume = new QAction(mainWindow);
        actionResume->setObjectName(QString::fromUtf8("actionResume"));
        centralwidget = new QWidget(mainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        mainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 24));
        menuModelo = new QMenu(menubar);
        menuModelo->setObjectName(QString::fromUtf8("menuModelo"));
        menuSimulation = new QMenu(menubar);
        menuSimulation->setObjectName(QString::fromUtf8("menuSimulation"));
        mainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(mainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        mainWindow->setStatusBar(statusbar);

        menubar->addAction(menuModelo->menuAction());
        menubar->addAction(menuSimulation->menuAction());
        menuModelo->addAction(actionNew);
        menuModelo->addAction(actionLoad);
        menuModelo->addAction(actionSave);
        menuModelo->addSeparator();
        menuModelo->addAction(actionExit);
        menuSimulation->addAction(actionStart);
        menuSimulation->addAction(actionStep);
        menuSimulation->addAction(actionStop);
        menuSimulation->addSeparator();
        menuSimulation->addAction(actionPause);
        menuSimulation->addAction(actionResume);

        retranslateUi(mainWindow);

        QMetaObject::connectSlotsByName(mainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *mainWindow)
    {
        mainWindow->setWindowTitle(QCoreApplication::translate("mainWindow", "GenESyS", nullptr));
        actionNew->setText(QCoreApplication::translate("mainWindow", "New", nullptr));
        actionLoad->setText(QCoreApplication::translate("mainWindow", "Load", nullptr));
        actionSave->setText(QCoreApplication::translate("mainWindow", "Save", nullptr));
        actionExit->setText(QCoreApplication::translate("mainWindow", "Exit", nullptr));
        actionStart->setText(QCoreApplication::translate("mainWindow", "Start", nullptr));
        actionStep->setText(QCoreApplication::translate("mainWindow", "Step", nullptr));
        actionStop->setText(QCoreApplication::translate("mainWindow", "Stop", nullptr));
        actionPause->setText(QCoreApplication::translate("mainWindow", "Pause", nullptr));
        actionResume->setText(QCoreApplication::translate("mainWindow", "Resume", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("mainWindow", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("mainWindow", "Tab 2", nullptr));
        menuModelo->setTitle(QCoreApplication::translate("mainWindow", "Model", nullptr));
        menuSimulation->setTitle(QCoreApplication::translate("mainWindow", "Simulation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainWindow: public Ui_mainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
