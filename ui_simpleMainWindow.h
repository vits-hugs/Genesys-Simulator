/********************************************************************************
** Form generated from reading UI file 'simpleMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMPLEMAINWINDOW_H
#define UI_SIMPLEMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_simpleMainWindow
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
    QMenuBar *menubar;
    QMenu *menuModel;
    QMenu *menuSimulation;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_2;
    QTreeView *treeView;

    void setupUi(QMainWindow *simpleMainWindow)
    {
        if (simpleMainWindow->objectName().isEmpty())
            simpleMainWindow->setObjectName(QString::fromUtf8("simpleMainWindow"));
        simpleMainWindow->resize(793, 483);
        actionNew = new QAction(simpleMainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionLoad = new QAction(simpleMainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionSave = new QAction(simpleMainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionExit = new QAction(simpleMainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionStart = new QAction(simpleMainWindow);
        actionStart->setObjectName(QString::fromUtf8("actionStart"));
        actionStep = new QAction(simpleMainWindow);
        actionStep->setObjectName(QString::fromUtf8("actionStep"));
        actionStop = new QAction(simpleMainWindow);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        actionPause = new QAction(simpleMainWindow);
        actionPause->setObjectName(QString::fromUtf8("actionPause"));
        actionResume = new QAction(simpleMainWindow);
        actionResume->setObjectName(QString::fromUtf8("actionResume"));
        centralwidget = new QWidget(simpleMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        simpleMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(simpleMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 793, 24));
        menuModel = new QMenu(menubar);
        menuModel->setObjectName(QString::fromUtf8("menuModel"));
        menuSimulation = new QMenu(menubar);
        menuSimulation->setObjectName(QString::fromUtf8("menuSimulation"));
        simpleMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(simpleMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        simpleMainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(simpleMainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        simpleMainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        dockWidget = new QDockWidget(simpleMainWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidget->setFloating(false);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        dockWidget->setWidget(dockWidgetContents);
        simpleMainWindow->addDockWidget(Qt::BottomDockWidgetArea, dockWidget);
        dockWidget_2 = new QDockWidget(simpleMainWindow);
        dockWidget_2->setObjectName(QString::fromUtf8("dockWidget_2"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        treeView = new QTreeView(dockWidgetContents_2);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(0, 0, 111, 121));
        dockWidget_2->setWidget(dockWidgetContents_2);
        simpleMainWindow->addDockWidget(Qt::LeftDockWidgetArea, dockWidget_2);

        menubar->addAction(menuModel->menuAction());
        menubar->addAction(menuSimulation->menuAction());
        menuModel->addAction(actionNew);
        menuModel->addAction(actionLoad);
        menuModel->addAction(actionSave);
        menuModel->addSeparator();
        menuModel->addAction(actionExit);
        menuSimulation->addAction(actionStart);
        menuSimulation->addAction(actionStep);
        menuSimulation->addAction(actionStop);
        menuSimulation->addSeparator();
        menuSimulation->addAction(actionPause);
        menuSimulation->addAction(actionResume);

        retranslateUi(simpleMainWindow);

        QMetaObject::connectSlotsByName(simpleMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *simpleMainWindow)
    {
        simpleMainWindow->setWindowTitle(QCoreApplication::translate("simpleMainWindow", "simpleMainWindow", nullptr));
        actionNew->setText(QCoreApplication::translate("simpleMainWindow", "New", nullptr));
        actionLoad->setText(QCoreApplication::translate("simpleMainWindow", "Load", nullptr));
        actionSave->setText(QCoreApplication::translate("simpleMainWindow", "Save", nullptr));
        actionExit->setText(QCoreApplication::translate("simpleMainWindow", "Exit", nullptr));
        actionStart->setText(QCoreApplication::translate("simpleMainWindow", "Start", nullptr));
        actionStep->setText(QCoreApplication::translate("simpleMainWindow", "Step", nullptr));
        actionStop->setText(QCoreApplication::translate("simpleMainWindow", "Stop", nullptr));
        actionPause->setText(QCoreApplication::translate("simpleMainWindow", "Pause", nullptr));
        actionResume->setText(QCoreApplication::translate("simpleMainWindow", "Resume", nullptr));
        menuModel->setTitle(QCoreApplication::translate("simpleMainWindow", "Model", nullptr));
        menuSimulation->setTitle(QCoreApplication::translate("simpleMainWindow", "Simulation", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("simpleMainWindow", "toolBar", nullptr));
        dockWidget->setWindowTitle(QCoreApplication::translate("simpleMainWindow", "Console", nullptr));
        dockWidget_2->setWindowTitle(QCoreApplication::translate("simpleMainWindow", "Plugins", nullptr));
    } // retranslateUi

};

namespace Ui {
    class simpleMainWindow: public Ui_simpleMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLEMAINWINDOW_H
