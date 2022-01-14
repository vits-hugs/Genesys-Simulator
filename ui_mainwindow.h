/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionStart;
    QAction *actionStep;
    QAction *actionStop;
    QAction *actionPause;
    QAction *actionResume;
    QAction *actionClose;
    QAction *actionCheck;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *tabWidgetModel;
    QWidget *tabModel;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit_Model;
    QWidget *tabSimulation;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *textEdit_Simulation;
    QWidget *tabReport;
    QHBoxLayout *horizontalLayout_4;
    QTextEdit *textEdit_Reports;
    QMenuBar *menubar;
    QMenu *menuModel;
    QMenu *menuSimulation;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QDockWidget *dockWidgetConsole;
    QWidget *dockWidgetContentsConsole;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit_Console;
    QDockWidget *dockWidgetPlugins;
    QWidget *dockWidgetContentsPlugin;
    QHBoxLayout *horizontalLayout_5;
    QListWidget *listWidget_Plugins;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(877, 606);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons2/resources/icons/pack2/ico/6.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setDockNestingEnabled(true);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/new document.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon1);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/upload.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon2);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/download.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon3);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/exit.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon4);
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName(QString::fromUtf8("actionStart"));
        actionStart->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/play.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionStart->setIcon(icon5);
        actionStep = new QAction(MainWindow);
        actionStep->setObjectName(QString::fromUtf8("actionStep"));
        actionStep->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/next track.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionStep->setIcon(icon6);
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        actionStop->setEnabled(false);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/stop.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon7);
        actionPause = new QAction(MainWindow);
        actionPause->setObjectName(QString::fromUtf8("actionPause"));
        actionPause->setEnabled(false);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/pause.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionPause->setIcon(icon8);
        actionResume = new QAction(MainWindow);
        actionResume->setObjectName(QString::fromUtf8("actionResume"));
        actionResume->setEnabled(false);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/fast-forward.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionResume->setIcon(icon9);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionClose->setEnabled(false);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/close.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose->setIcon(icon10);
        actionCheck = new QAction(MainWindow);
        actionCheck->setObjectName(QString::fromUtf8("actionCheck"));
        actionCheck->setEnabled(false);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/yes.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionCheck->setIcon(icon11);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tabWidgetModel = new QTabWidget(centralwidget);
        tabWidgetModel->setObjectName(QString::fromUtf8("tabWidgetModel"));
        tabWidgetModel->setEnabled(false);
        QFont font;
        font.setPointSize(12);
        tabWidgetModel->setFont(font);
        tabModel = new QWidget();
        tabModel->setObjectName(QString::fromUtf8("tabModel"));
        horizontalLayout = new QHBoxLayout(tabModel);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        textEdit_Model = new QTextEdit(tabModel);
        textEdit_Model->setObjectName(QString::fromUtf8("textEdit_Model"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Courier"));
        font1.setPointSize(12);
        textEdit_Model->setFont(font1);
        textEdit_Model->setLineWidth(3);
        textEdit_Model->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        textEdit_Model->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        textEdit_Model->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextEditable|Qt::TextEditorInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout->addWidget(textEdit_Model);

        tabWidgetModel->addTab(tabModel, QString());
        tabSimulation = new QWidget();
        tabSimulation->setObjectName(QString::fromUtf8("tabSimulation"));
        horizontalLayout_3 = new QHBoxLayout(tabSimulation);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        textEdit_Simulation = new QTextEdit(tabSimulation);
        textEdit_Simulation->setObjectName(QString::fromUtf8("textEdit_Simulation"));
        QFont font2;
        font2.setPointSize(10);
        textEdit_Simulation->setFont(font2);
        textEdit_Simulation->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_3->addWidget(textEdit_Simulation);

        tabWidgetModel->addTab(tabSimulation, QString());
        tabReport = new QWidget();
        tabReport->setObjectName(QString::fromUtf8("tabReport"));
        horizontalLayout_4 = new QHBoxLayout(tabReport);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        textEdit_Reports = new QTextEdit(tabReport);
        textEdit_Reports->setObjectName(QString::fromUtf8("textEdit_Reports"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Courier 10 Pitch"));
        font3.setPointSize(10);
        textEdit_Reports->setFont(font3);
        textEdit_Reports->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_4->addWidget(textEdit_Reports);

        tabWidgetModel->addTab(tabReport, QString());

        horizontalLayout_2->addWidget(tabWidgetModel);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 877, 24));
        menuModel = new QMenu(menubar);
        menuModel->setObjectName(QString::fromUtf8("menuModel"));
        menuSimulation = new QMenu(menubar);
        menuSimulation->setObjectName(QString::fromUtf8("menuSimulation"));
        menuSimulation->setEnabled(false);
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        dockWidgetConsole = new QDockWidget(MainWindow);
        dockWidgetConsole->setObjectName(QString::fromUtf8("dockWidgetConsole"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dockWidgetConsole->sizePolicy().hasHeightForWidth());
        dockWidgetConsole->setSizePolicy(sizePolicy);
        dockWidgetConsole->setMinimumSize(QSize(100, 100));
        dockWidgetConsole->setBaseSize(QSize(100, 100));
        dockWidgetConsole->setAutoFillBackground(false);
        dockWidgetConsole->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetConsole->setAllowedAreas(Qt::BottomDockWidgetArea|Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContentsConsole = new QWidget();
        dockWidgetContentsConsole->setObjectName(QString::fromUtf8("dockWidgetContentsConsole"));
        verticalLayout = new QVBoxLayout(dockWidgetContentsConsole);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEdit_Console = new QTextEdit(dockWidgetContentsConsole);
        textEdit_Console->setObjectName(QString::fromUtf8("textEdit_Console"));
        textEdit_Console->setFont(font2);
        textEdit_Console->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout->addWidget(textEdit_Console);

        dockWidgetConsole->setWidget(dockWidgetContentsConsole);
        MainWindow->addDockWidget(Qt::BottomDockWidgetArea, dockWidgetConsole);
        dockWidgetPlugins = new QDockWidget(MainWindow);
        dockWidgetPlugins->setObjectName(QString::fromUtf8("dockWidgetPlugins"));
        sizePolicy.setHeightForWidth(dockWidgetPlugins->sizePolicy().hasHeightForWidth());
        dockWidgetPlugins->setSizePolicy(sizePolicy);
        dockWidgetPlugins->setMinimumSize(QSize(100, 109));
        dockWidgetPlugins->setBaseSize(QSize(100, 100));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/component.ico"), QSize(), QIcon::Normal, QIcon::Off);
        dockWidgetPlugins->setWindowIcon(icon12);
        dockWidgetPlugins->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetPlugins->setAllowedAreas(Qt::BottomDockWidgetArea|Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContentsPlugin = new QWidget();
        dockWidgetContentsPlugin->setObjectName(QString::fromUtf8("dockWidgetContentsPlugin"));
        horizontalLayout_5 = new QHBoxLayout(dockWidgetContentsPlugin);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        listWidget_Plugins = new QListWidget(dockWidgetContentsPlugin);
        listWidget_Plugins->setObjectName(QString::fromUtf8("listWidget_Plugins"));
        listWidget_Plugins->setFont(font2);

        horizontalLayout_5->addWidget(listWidget_Plugins);

        dockWidgetPlugins->setWidget(dockWidgetContentsPlugin);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, dockWidgetPlugins);
        QWidget::setTabOrder(textEdit_Model, textEdit_Simulation);
        QWidget::setTabOrder(textEdit_Simulation, textEdit_Reports);
        QWidget::setTabOrder(textEdit_Reports, tabWidgetModel);

        menubar->addAction(menuModel->menuAction());
        menubar->addAction(menuSimulation->menuAction());
        menuModel->addAction(actionNew);
        menuModel->addSeparator();
        menuModel->addAction(actionOpen);
        menuModel->addAction(actionSave);
        menuModel->addAction(actionClose);
        menuModel->addSeparator();
        menuModel->addAction(actionCheck);
        menuModel->addSeparator();
        menuModel->addAction(actionExit);
        menuSimulation->addAction(actionStart);
        menuSimulation->addAction(actionStep);
        menuSimulation->addAction(actionStop);
        menuSimulation->addSeparator();
        menuSimulation->addAction(actionPause);
        menuSimulation->addAction(actionResume);
        toolBar->addAction(actionNew);
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionSave);
        toolBar->addAction(actionClose);
        toolBar->addAction(actionCheck);
        toolBar->addAction(actionExit);
        toolBar->addAction(actionStart);
        toolBar->addAction(actionStep);
        toolBar->addAction(actionStop);
        toolBar->addAction(actionPause);
        toolBar->addAction(actionResume);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        tabWidgetModel->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "GenESyS - Generic and Expansible System Simulator", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        actionStep->setText(QCoreApplication::translate("MainWindow", "Step", nullptr));
        actionStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        actionPause->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        actionResume->setText(QCoreApplication::translate("MainWindow", "Resume", nullptr));
        actionClose->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        actionCheck->setText(QCoreApplication::translate("MainWindow", "Check", nullptr));
        tabWidgetModel->setTabText(tabWidgetModel->indexOf(tabModel), QCoreApplication::translate("MainWindow", "Model", nullptr));
        tabWidgetModel->setTabText(tabWidgetModel->indexOf(tabSimulation), QCoreApplication::translate("MainWindow", "Simulation", nullptr));
        tabWidgetModel->setTabText(tabWidgetModel->indexOf(tabReport), QCoreApplication::translate("MainWindow", "Reports", nullptr));
        menuModel->setTitle(QCoreApplication::translate("MainWindow", "Model", nullptr));
        menuSimulation->setTitle(QCoreApplication::translate("MainWindow", "Simulation", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
        dockWidgetConsole->setWindowTitle(QCoreApplication::translate("MainWindow", "Console", nullptr));
        dockWidgetPlugins->setWindowTitle(QCoreApplication::translate("MainWindow", "Plugins", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
