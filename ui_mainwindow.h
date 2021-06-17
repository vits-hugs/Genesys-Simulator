/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
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
    QAction *actionClose;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionExit;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionFind;
    QAction *actionReplace;
    QAction *actionGroup;
    QAction *actionZoom_In;
    QAction *actionZoom_Out;
    QAction *actionZoom_Factor;
    QAction *actionGrid;
    QAction *actionSnap;
    QAction *actionInput_Analyser;
    QAction *actionOutput_Analyser;
    QAction *actionScenario_Manager;
    QAction *actionOptimizaton;
    QAction *actionPreferences;
    QAction *actionCheck_Model;
    QAction *actionStart;
    QAction *actionStep;
    QAction *actionStop;
    QAction *actionRun_Control;
    QAction *actionComponents;
    QAction *actionElements;
    QAction *actionModels;
    QAction *actionConsole;
    QAction *actionProperties;
    QAction *actionEditor;
    QAction *actionDocumentation;
    QAction *actionSupport;
    QAction *actionAbout;
    QAction *actionTop;
    QAction *actionBottom;
    QAction *actionInformation;
    QAction *actionReport;
    QAction *actionComponents_2;
    QAction *actionElements_2;
    QAction *actionTrace;
    QAction *actionEvents;
    QAction *actionPause;
    QAction *actionExit_2;
    QAction *actionPlugins;
    QAction *actionPreferences_2;
    QAction *actionModels_2;
    QAction *actionExperiments;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidgetModels;
    QWidget *tabModel1;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *graphicsView;
    QWidget *tabModel2;
    QHBoxLayout *horizontalLayout_2;
    QMenuBar *menuBar;
    QMenu *menuEdit;
    QMenu *menuModel;
    QMenu *menuWindow;
    QMenu *menuHelp;
    QMenu *menuView;
    QMenu *menuArrange;
    QMenu *menuSimulator;
    QToolBar *toolBarModel;
    QStatusBar *statusBar;
    QToolBar *toolBarEdit;
    QToolBar *toolBar;
    QToolBar *toolBarSimulator;
    QDockWidget *dockWidgetComponents;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget_ComponentPlugins;
    QDockWidget *dockWidgetProperties;
    QWidget *dockWidgetContents_3;
    QVBoxLayout *verticalLayout_3;
    QTableView *tableView_Properties;
    QDockWidget *dockWidgetConsole;
    QWidget *dockWidgetContents_4;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *textEdit_Console;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents_5;
    QVBoxLayout *verticalLayout_5;
    QTextEdit *textEdit_Report;
    QDockWidget *dockWidgetExperiments;
    QWidget *dockWidgetContents_6;
    QListWidget *listWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1082, 619);
        MainWindow->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rec/resources/icons/pack2/png/24x24/60.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/rec/resources/icons/pack2/png/24x24/52.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionClose->setEnabled(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Close.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose->setIcon(icon2);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave->setEnabled(true);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon3);
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionSave_as->setEnabled(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/rec/resources/icons/pack2/png/24x24/86.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_as->setIcon(icon4);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Door.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon5);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        actionUndo->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon6);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        actionRedo->setEnabled(false);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon7);
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        actionCut->setEnabled(false);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon8);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        actionCopy->setEnabled(false);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon9);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        actionPaste->setEnabled(false);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon10);
        actionFind = new QAction(MainWindow);
        actionFind->setObjectName(QString::fromUtf8("actionFind"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Find.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFind->setIcon(icon11);
        actionReplace = new QAction(MainWindow);
        actionReplace->setObjectName(QString::fromUtf8("actionReplace"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/View.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReplace->setIcon(icon12);
        actionGroup = new QAction(MainWindow);
        actionGroup->setObjectName(QString::fromUtf8("actionGroup"));
        actionZoom_In = new QAction(MainWindow);
        actionZoom_In->setObjectName(QString::fromUtf8("actionZoom_In"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Zoom.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoom_In->setIcon(icon13);
        actionZoom_Out = new QAction(MainWindow);
        actionZoom_Out->setObjectName(QString::fromUtf8("actionZoom_Out"));
        actionZoom_Out->setIcon(icon13);
        actionZoom_Factor = new QAction(MainWindow);
        actionZoom_Factor->setObjectName(QString::fromUtf8("actionZoom_Factor"));
        actionZoom_Factor->setIcon(icon13);
        actionGrid = new QAction(MainWindow);
        actionGrid->setObjectName(QString::fromUtf8("actionGrid"));
        actionSnap = new QAction(MainWindow);
        actionSnap->setObjectName(QString::fromUtf8("actionSnap"));
        actionInput_Analyser = new QAction(MainWindow);
        actionInput_Analyser->setObjectName(QString::fromUtf8("actionInput_Analyser"));
        actionOutput_Analyser = new QAction(MainWindow);
        actionOutput_Analyser->setObjectName(QString::fromUtf8("actionOutput_Analyser"));
        actionScenario_Manager = new QAction(MainWindow);
        actionScenario_Manager->setObjectName(QString::fromUtf8("actionScenario_Manager"));
        actionOptimizaton = new QAction(MainWindow);
        actionOptimizaton->setObjectName(QString::fromUtf8("actionOptimizaton"));
        actionPreferences = new QAction(MainWindow);
        actionPreferences->setObjectName(QString::fromUtf8("actionPreferences"));
        actionCheck_Model = new QAction(MainWindow);
        actionCheck_Model->setObjectName(QString::fromUtf8("actionCheck_Model"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/rec/resources/icons/pack2/png/24x24/58.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCheck_Model->setIcon(icon14);
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName(QString::fromUtf8("actionStart"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Play.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStart->setIcon(icon15);
        actionStep = new QAction(MainWindow);
        actionStep->setObjectName(QString::fromUtf8("actionStep"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Next track.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStep->setIcon(icon16);
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon17);
        actionRun_Control = new QAction(MainWindow);
        actionRun_Control->setObjectName(QString::fromUtf8("actionRun_Control"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Tune.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRun_Control->setIcon(icon18);
        actionComponents = new QAction(MainWindow);
        actionComponents->setObjectName(QString::fromUtf8("actionComponents"));
        actionElements = new QAction(MainWindow);
        actionElements->setObjectName(QString::fromUtf8("actionElements"));
        actionModels = new QAction(MainWindow);
        actionModels->setObjectName(QString::fromUtf8("actionModels"));
        actionConsole = new QAction(MainWindow);
        actionConsole->setObjectName(QString::fromUtf8("actionConsole"));
        actionProperties = new QAction(MainWindow);
        actionProperties->setObjectName(QString::fromUtf8("actionProperties"));
        actionEditor = new QAction(MainWindow);
        actionEditor->setObjectName(QString::fromUtf8("actionEditor"));
        actionDocumentation = new QAction(MainWindow);
        actionDocumentation->setObjectName(QString::fromUtf8("actionDocumentation"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Help book.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDocumentation->setIcon(icon19);
        actionSupport = new QAction(MainWindow);
        actionSupport->setObjectName(QString::fromUtf8("actionSupport"));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSupport->setIcon(icon20);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Help book 3d.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon21);
        actionTop = new QAction(MainWindow);
        actionTop->setObjectName(QString::fromUtf8("actionTop"));
        actionBottom = new QAction(MainWindow);
        actionBottom->setObjectName(QString::fromUtf8("actionBottom"));
        actionInformation = new QAction(MainWindow);
        actionInformation->setObjectName(QString::fromUtf8("actionInformation"));
        actionInformation->setEnabled(true);
        actionReport = new QAction(MainWindow);
        actionReport->setObjectName(QString::fromUtf8("actionReport"));
        actionComponents_2 = new QAction(MainWindow);
        actionComponents_2->setObjectName(QString::fromUtf8("actionComponents_2"));
        actionElements_2 = new QAction(MainWindow);
        actionElements_2->setObjectName(QString::fromUtf8("actionElements_2"));
        actionTrace = new QAction(MainWindow);
        actionTrace->setObjectName(QString::fromUtf8("actionTrace"));
        actionEvents = new QAction(MainWindow);
        actionEvents->setObjectName(QString::fromUtf8("actionEvents"));
        actionPause = new QAction(MainWindow);
        actionPause->setObjectName(QString::fromUtf8("actionPause"));
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/rec/resources/icons/pack3/png/24x24/Pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPause->setIcon(icon22);
        actionExit_2 = new QAction(MainWindow);
        actionExit_2->setObjectName(QString::fromUtf8("actionExit_2"));
        actionPlugins = new QAction(MainWindow);
        actionPlugins->setObjectName(QString::fromUtf8("actionPlugins"));
        actionPreferences_2 = new QAction(MainWindow);
        actionPreferences_2->setObjectName(QString::fromUtf8("actionPreferences_2"));
        actionModels_2 = new QAction(MainWindow);
        actionModels_2->setObjectName(QString::fromUtf8("actionModels_2"));
        actionExperiments = new QAction(MainWindow);
        actionExperiments->setObjectName(QString::fromUtf8("actionExperiments"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidgetModels = new QTabWidget(centralWidget);
        tabWidgetModels->setObjectName(QString::fromUtf8("tabWidgetModels"));
        tabWidgetModels->setTabPosition(QTabWidget::North);
        tabWidgetModels->setTabShape(QTabWidget::Rounded);
        tabWidgetModels->setTabsClosable(true);
        tabWidgetModels->setMovable(true);
        tabModel1 = new QWidget();
        tabModel1->setObjectName(QString::fromUtf8("tabModel1"));
        horizontalLayout = new QHBoxLayout(tabModel1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        graphicsView = new QGraphicsView(tabModel1);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setFrameShape(QFrame::WinPanel);

        horizontalLayout->addWidget(graphicsView);

        tabWidgetModels->addTab(tabModel1, QString());
        tabModel2 = new QWidget();
        tabModel2->setObjectName(QString::fromUtf8("tabModel2"));
        horizontalLayout_2 = new QHBoxLayout(tabModel2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tabWidgetModels->addTab(tabModel2, QString());

        gridLayout->addWidget(tabWidgetModels, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1082, 21));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuModel = new QMenu(menuBar);
        menuModel->setObjectName(QString::fromUtf8("menuModel"));
        menuModel->setEnabled(true);
        menuWindow = new QMenu(menuBar);
        menuWindow->setObjectName(QString::fromUtf8("menuWindow"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuArrange = new QMenu(menuView);
        menuArrange->setObjectName(QString::fromUtf8("menuArrange"));
        menuSimulator = new QMenu(menuBar);
        menuSimulator->setObjectName(QString::fromUtf8("menuSimulator"));
        MainWindow->setMenuBar(menuBar);
        toolBarModel = new QToolBar(MainWindow);
        toolBarModel->setObjectName(QString::fromUtf8("toolBarModel"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBarModel);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBarEdit = new QToolBar(MainWindow);
        toolBarEdit->setObjectName(QString::fromUtf8("toolBarEdit"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBarEdit);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBarSimulator = new QToolBar(MainWindow);
        toolBarSimulator->setObjectName(QString::fromUtf8("toolBarSimulator"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBarSimulator);
        dockWidgetComponents = new QDockWidget(MainWindow);
        dockWidgetComponents->setObjectName(QString::fromUtf8("dockWidgetComponents"));
        dockWidgetComponents->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget_ComponentPlugins = new QListWidget(dockWidgetContents);
        listWidget_ComponentPlugins->setObjectName(QString::fromUtf8("listWidget_ComponentPlugins"));

        verticalLayout->addWidget(listWidget_ComponentPlugins);

        dockWidgetComponents->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidgetComponents);
        dockWidgetProperties = new QDockWidget(MainWindow);
        dockWidgetProperties->setObjectName(QString::fromUtf8("dockWidgetProperties"));
        dockWidgetProperties->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QString::fromUtf8("dockWidgetContents_3"));
        verticalLayout_3 = new QVBoxLayout(dockWidgetContents_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tableView_Properties = new QTableView(dockWidgetContents_3);
        tableView_Properties->setObjectName(QString::fromUtf8("tableView_Properties"));
        tableView_Properties->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableView_Properties->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        verticalLayout_3->addWidget(tableView_Properties);

        dockWidgetProperties->setWidget(dockWidgetContents_3);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidgetProperties);
        dockWidgetConsole = new QDockWidget(MainWindow);
        dockWidgetConsole->setObjectName(QString::fromUtf8("dockWidgetConsole"));
        dockWidgetConsole->setFloating(false);
        dockWidgetConsole->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetConsole->setAllowedAreas(Qt::AllDockWidgetAreas);
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QString::fromUtf8("dockWidgetContents_4"));
        verticalLayout_4 = new QVBoxLayout(dockWidgetContents_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        textEdit_Console = new QTextEdit(dockWidgetContents_4);
        textEdit_Console->setObjectName(QString::fromUtf8("textEdit_Console"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit_Console->sizePolicy().hasHeightForWidth());
        textEdit_Console->setSizePolicy(sizePolicy);
        textEdit_Console->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        textEdit_Console->setLineWrapMode(QTextEdit::NoWrap);
        textEdit_Console->setReadOnly(true);
        textEdit_Console->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout_4->addWidget(textEdit_Console);

        dockWidgetConsole->setWidget(dockWidgetContents_4);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidgetConsole);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidget->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents_5 = new QWidget();
        dockWidgetContents_5->setObjectName(QString::fromUtf8("dockWidgetContents_5"));
        verticalLayout_5 = new QVBoxLayout(dockWidgetContents_5);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        textEdit_Report = new QTextEdit(dockWidgetContents_5);
        textEdit_Report->setObjectName(QString::fromUtf8("textEdit_Report"));
        sizePolicy.setHeightForWidth(textEdit_Report->sizePolicy().hasHeightForWidth());
        textEdit_Report->setSizePolicy(sizePolicy);
        textEdit_Report->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        verticalLayout_5->addWidget(textEdit_Report);

        dockWidget->setWidget(dockWidgetContents_5);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidget);
        dockWidgetExperiments = new QDockWidget(MainWindow);
        dockWidgetExperiments->setObjectName(QString::fromUtf8("dockWidgetExperiments"));
        dockWidgetContents_6 = new QWidget();
        dockWidgetContents_6->setObjectName(QString::fromUtf8("dockWidgetContents_6"));
        listWidget = new QListWidget(dockWidgetContents_6);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 181, 61));
        listWidget->setAutoFillBackground(false);
        dockWidgetExperiments->setWidget(dockWidgetContents_6);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidgetExperiments);

        menuBar->addAction(menuSimulator->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuModel->menuAction());
        menuBar->addAction(menuWindow->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addSeparator();
        menuEdit->addAction(actionFind);
        menuEdit->addAction(actionReplace);
        menuWindow->addAction(actionComponents);
        menuWindow->addAction(actionElements);
        menuWindow->addAction(actionModels);
        menuWindow->addAction(actionConsole);
        menuWindow->addAction(actionProperties);
        menuWindow->addAction(actionEditor);
        menuHelp->addAction(actionDocumentation);
        menuHelp->addAction(actionSupport);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout);
        menuView->addAction(actionZoom_In);
        menuView->addAction(actionZoom_Out);
        menuView->addAction(actionZoom_Factor);
        menuView->addSeparator();
        menuView->addAction(actionGrid);
        menuView->addAction(actionSnap);
        menuView->addSeparator();
        menuView->addAction(menuArrange->menuAction());
        menuView->addAction(actionGroup);
        menuArrange->addAction(actionTop);
        menuArrange->addAction(actionBottom);
        menuSimulator->addSeparator();
        menuSimulator->addAction(actionPlugins);
        menuSimulator->addAction(actionExperiments);
        menuSimulator->addAction(actionModels_2);
        menuSimulator->addSeparator();
        menuSimulator->addAction(actionPreferences_2);
        menuSimulator->addSeparator();
        menuSimulator->addAction(actionExit_2);
        toolBarModel->addAction(actionNew);
        toolBarModel->addAction(actionOpen);
        toolBarModel->addAction(actionClose);
        toolBarModel->addAction(actionSave);
        toolBarModel->addAction(actionSave_as);
        toolBarModel->addSeparator();
        toolBarModel->addAction(actionExit);
        toolBarEdit->addAction(actionUndo);
        toolBarEdit->addAction(actionRedo);
        toolBarEdit->addSeparator();
        toolBarEdit->addAction(actionCut);
        toolBarEdit->addAction(actionCopy);
        toolBarEdit->addAction(actionPaste);
        toolBarEdit->addSeparator();
        toolBarEdit->addAction(actionFind);
        toolBarEdit->addAction(actionReplace);
        toolBar->addAction(actionZoom_In);
        toolBar->addAction(actionZoom_Out);
        toolBar->addAction(actionZoom_Factor);
        toolBarSimulator->addAction(actionStart);
        toolBarSimulator->addAction(actionPause);
        toolBarSimulator->addAction(actionStep);
        toolBarSimulator->addAction(actionStop);
        toolBarSimulator->addAction(actionRun_Control);

        retranslateUi(MainWindow);

        tabWidgetModels->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "GenESyS -- Generic and Expansible System Simulator", nullptr));
        actionNew->setText(QApplication::translate("MainWindow", "New", nullptr));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("MainWindow", "New simulation model", nullptr));
#endif // QT_NO_TOOLTIP
        actionOpen->setText(QApplication::translate("MainWindow", "Open", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionClose->setText(QApplication::translate("MainWindow", "Close", nullptr));
#ifndef QT_NO_SHORTCUT
        actionClose->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave_as->setText(QApplication::translate("MainWindow", "Save all", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave_as->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_NO_SHORTCUT
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+F4", nullptr));
#endif // QT_NO_SHORTCUT
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", nullptr));
#ifndef QT_NO_SHORTCUT
        actionUndo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_NO_SHORTCUT
        actionRedo->setText(QApplication::translate("MainWindow", "Redo", nullptr));
#ifndef QT_NO_SHORTCUT
        actionRedo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+Z", nullptr));
#endif // QT_NO_SHORTCUT
        actionCut->setText(QApplication::translate("MainWindow", "Cut", nullptr));
#ifndef QT_NO_SHORTCUT
        actionCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_NO_SHORTCUT
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", nullptr));
#ifndef QT_NO_SHORTCUT
        actionCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", nullptr));
#ifndef QT_NO_SHORTCUT
        actionPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_NO_SHORTCUT
        actionFind->setText(QApplication::translate("MainWindow", "Find", nullptr));
#ifndef QT_NO_SHORTCUT
        actionFind->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_NO_SHORTCUT
        actionReplace->setText(QApplication::translate("MainWindow", "Replace", nullptr));
#ifndef QT_NO_SHORTCUT
        actionReplace->setShortcut(QApplication::translate("MainWindow", "Ctrl+H", nullptr));
#endif // QT_NO_SHORTCUT
        actionGroup->setText(QApplication::translate("MainWindow", "Group", nullptr));
        actionZoom_In->setText(QApplication::translate("MainWindow", "Zoom In", nullptr));
#ifndef QT_NO_SHORTCUT
        actionZoom_In->setShortcut(QApplication::translate("MainWindow", "Ctrl+=", nullptr));
#endif // QT_NO_SHORTCUT
        actionZoom_Out->setText(QApplication::translate("MainWindow", "Zoom Out", nullptr));
#ifndef QT_NO_SHORTCUT
        actionZoom_Out->setShortcut(QApplication::translate("MainWindow", "Ctrl+-", nullptr));
#endif // QT_NO_SHORTCUT
        actionZoom_Factor->setText(QApplication::translate("MainWindow", "Zoom Factor", nullptr));
        actionGrid->setText(QApplication::translate("MainWindow", "Grid", nullptr));
        actionSnap->setText(QApplication::translate("MainWindow", "Snap", nullptr));
        actionInput_Analyser->setText(QApplication::translate("MainWindow", "Input Analyser", nullptr));
        actionOutput_Analyser->setText(QApplication::translate("MainWindow", "Output Analyser", nullptr));
        actionScenario_Manager->setText(QApplication::translate("MainWindow", "Scenario Manager", nullptr));
        actionOptimizaton->setText(QApplication::translate("MainWindow", "Optimizaton", nullptr));
        actionPreferences->setText(QApplication::translate("MainWindow", "Preferences", nullptr));
        actionCheck_Model->setText(QApplication::translate("MainWindow", "Check", nullptr));
#ifndef QT_NO_SHORTCUT
        actionCheck_Model->setShortcut(QApplication::translate("MainWindow", "F4", nullptr));
#endif // QT_NO_SHORTCUT
        actionStart->setText(QApplication::translate("MainWindow", "Start", nullptr));
#ifndef QT_NO_SHORTCUT
        actionStart->setShortcut(QApplication::translate("MainWindow", "F5", nullptr));
#endif // QT_NO_SHORTCUT
        actionStep->setText(QApplication::translate("MainWindow", "Step", nullptr));
#ifndef QT_NO_SHORTCUT
        actionStep->setShortcut(QApplication::translate("MainWindow", "F7", nullptr));
#endif // QT_NO_SHORTCUT
        actionStop->setText(QApplication::translate("MainWindow", "Stop", nullptr));
#ifndef QT_NO_SHORTCUT
        actionStop->setShortcut(QApplication::translate("MainWindow", "F10", nullptr));
#endif // QT_NO_SHORTCUT
        actionRun_Control->setText(QApplication::translate("MainWindow", "Settings", nullptr));
        actionComponents->setText(QApplication::translate("MainWindow", "Plugins", nullptr));
        actionElements->setText(QApplication::translate("MainWindow", "Experiments", nullptr));
        actionModels->setText(QApplication::translate("MainWindow", "Models", nullptr));
        actionConsole->setText(QApplication::translate("MainWindow", "Console", nullptr));
        actionProperties->setText(QApplication::translate("MainWindow", "Properties", nullptr));
        actionEditor->setText(QApplication::translate("MainWindow", "Reports", nullptr));
        actionDocumentation->setText(QApplication::translate("MainWindow", "Documentation", nullptr));
#ifndef QT_NO_SHORTCUT
        actionDocumentation->setShortcut(QApplication::translate("MainWindow", "F1", nullptr));
#endif // QT_NO_SHORTCUT
        actionSupport->setText(QApplication::translate("MainWindow", "Support", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSupport->setShortcut(QApplication::translate("MainWindow", "Ctrl+F1", nullptr));
#endif // QT_NO_SHORTCUT
        actionAbout->setText(QApplication::translate("MainWindow", "About...", nullptr));
#ifndef QT_NO_SHORTCUT
        actionAbout->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+F1", nullptr));
#endif // QT_NO_SHORTCUT
        actionTop->setText(QApplication::translate("MainWindow", "Top", nullptr));
        actionBottom->setText(QApplication::translate("MainWindow", "Bottom", nullptr));
        actionInformation->setText(QApplication::translate("MainWindow", "Information", nullptr));
        actionReport->setText(QApplication::translate("MainWindow", "Report", nullptr));
        actionComponents_2->setText(QApplication::translate("MainWindow", "Components", nullptr));
        actionElements_2->setText(QApplication::translate("MainWindow", "Elements", nullptr));
        actionTrace->setText(QApplication::translate("MainWindow", "Trace", nullptr));
        actionEvents->setText(QApplication::translate("MainWindow", "Events", nullptr));
        actionPause->setText(QApplication::translate("MainWindow", "Pause", nullptr));
        actionExit_2->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        actionPlugins->setText(QApplication::translate("MainWindow", "Plugins", nullptr));
        actionPreferences_2->setText(QApplication::translate("MainWindow", "Preferences", nullptr));
        actionModels_2->setText(QApplication::translate("MainWindow", "Models", nullptr));
        actionExperiments->setText(QApplication::translate("MainWindow", "Experiments", nullptr));
        tabWidgetModels->setTabText(tabWidgetModels->indexOf(tabModel1), QApplication::translate("MainWindow", "Model 1", nullptr));
        tabWidgetModels->setTabText(tabWidgetModels->indexOf(tabModel2), QApplication::translate("MainWindow", "Model 2", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", nullptr));
        menuModel->setTitle(QApplication::translate("MainWindow", "Model", nullptr));
        menuWindow->setTitle(QApplication::translate("MainWindow", "Window", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
        menuView->setTitle(QApplication::translate("MainWindow", "View", nullptr));
        menuArrange->setTitle(QApplication::translate("MainWindow", "Arrange", nullptr));
        menuSimulator->setTitle(QApplication::translate("MainWindow", "Simulator", nullptr));
        toolBarEdit->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
        toolBarSimulator->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", nullptr));
        dockWidgetComponents->setWindowTitle(QApplication::translate("MainWindow", "Plugins", nullptr));
        dockWidgetProperties->setWindowTitle(QApplication::translate("MainWindow", "Properties", nullptr));
        dockWidgetConsole->setWindowTitle(QApplication::translate("MainWindow", "Traces", nullptr));
        dockWidget->setWindowTitle(QApplication::translate("MainWindow", "Reports", nullptr));
        dockWidgetExperiments->setWindowTitle(QApplication::translate("MainWindow", "Experiments", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
