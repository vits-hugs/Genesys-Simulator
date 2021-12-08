/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
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
    QAction *actionPreferences_2;
    QAction *actionModels_2;
    QAction *actionExperiments;
    QAction *actionConnect;
    QAction *actionZoom_In_2;
    QAction *actionZoom_Out_2;
    QAction *actionZoom_Facot;
    QAction *actionGrid_2;
    QAction *actionSnap_2;
    QAction *actionArranje;
    QAction *actionGroup_2;
    QAction *actionPlugins_2;
    QAction *actionInformation_2;
    QAction *actionSimulation;
    QAction *actionComponents_3;
    QAction *actionElements_3;
    QAction *actionLoad;
    QAction *actionSave_2;
    QAction *actionEvents_Diagram;
    QAction *actionArranje_2;
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
    QMenu *menuView_2;
    QMenu *menuWindow;
    QMenu *menuHelp;
    QMenu *menuSimulator;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QDockWidget *dockWidgetPlugins;
    QWidget *dockWidgetPlugins_2;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget_Plugins;
    QDockWidget *dockWidgetProperties;
    QWidget *dockWidgetContents_Properties;
    QVBoxLayout *verticalLayout_3;
    QTableView *tableView_Properties;
    QDockWidget *dockWidgetConsole;
    QWidget *dockWidgetContents_Console;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *textEdit_Console;
    QDockWidget *dockWidgetReports;
    QWidget *dockWidgetContents_Reports;
    QVBoxLayout *verticalLayout_5;
    QTextEdit *textEdit_Report;
    QDockWidget *dockWidgetExperiments;
    QWidget *dockWidgetContents_Experiments;
    QListWidget *listWidget_Experiments;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1273, 724);
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
        actionPreferences_2 = new QAction(MainWindow);
        actionPreferences_2->setObjectName(QString::fromUtf8("actionPreferences_2"));
        actionModels_2 = new QAction(MainWindow);
        actionModels_2->setObjectName(QString::fromUtf8("actionModels_2"));
        actionExperiments = new QAction(MainWindow);
        actionExperiments->setObjectName(QString::fromUtf8("actionExperiments"));
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        actionZoom_In_2 = new QAction(MainWindow);
        actionZoom_In_2->setObjectName(QString::fromUtf8("actionZoom_In_2"));
        actionZoom_Out_2 = new QAction(MainWindow);
        actionZoom_Out_2->setObjectName(QString::fromUtf8("actionZoom_Out_2"));
        actionZoom_Facot = new QAction(MainWindow);
        actionZoom_Facot->setObjectName(QString::fromUtf8("actionZoom_Facot"));
        actionGrid_2 = new QAction(MainWindow);
        actionGrid_2->setObjectName(QString::fromUtf8("actionGrid_2"));
        actionSnap_2 = new QAction(MainWindow);
        actionSnap_2->setObjectName(QString::fromUtf8("actionSnap_2"));
        actionArranje = new QAction(MainWindow);
        actionArranje->setObjectName(QString::fromUtf8("actionArranje"));
        actionGroup_2 = new QAction(MainWindow);
        actionGroup_2->setObjectName(QString::fromUtf8("actionGroup_2"));
        actionPlugins_2 = new QAction(MainWindow);
        actionPlugins_2->setObjectName(QString::fromUtf8("actionPlugins_2"));
        actionInformation_2 = new QAction(MainWindow);
        actionInformation_2->setObjectName(QString::fromUtf8("actionInformation_2"));
        actionSimulation = new QAction(MainWindow);
        actionSimulation->setObjectName(QString::fromUtf8("actionSimulation"));
        actionComponents_3 = new QAction(MainWindow);
        actionComponents_3->setObjectName(QString::fromUtf8("actionComponents_3"));
        actionElements_3 = new QAction(MainWindow);
        actionElements_3->setObjectName(QString::fromUtf8("actionElements_3"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionSave_2 = new QAction(MainWindow);
        actionSave_2->setObjectName(QString::fromUtf8("actionSave_2"));
        actionEvents_Diagram = new QAction(MainWindow);
        actionEvents_Diagram->setObjectName(QString::fromUtf8("actionEvents_Diagram"));
        actionArranje_2 = new QAction(MainWindow);
        actionArranje_2->setObjectName(QString::fromUtf8("actionArranje_2"));
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
        graphicsView->setFrameShadow(QFrame::Sunken);
        graphicsView->setLineWidth(2);
        graphicsView->setMidLineWidth(1);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        QBrush brush(QColor(238, 238, 238, 255));
        brush.setStyle(Qt::SolidPattern);
        graphicsView->setBackgroundBrush(brush);
        graphicsView->setDragMode(QGraphicsView::NoDrag);

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
        menuBar->setGeometry(QRect(0, 0, 1273, 24));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuModel = new QMenu(menuBar);
        menuModel->setObjectName(QString::fromUtf8("menuModel"));
        menuModel->setEnabled(true);
        menuView_2 = new QMenu(menuModel);
        menuView_2->setObjectName(QString::fromUtf8("menuView_2"));
        menuWindow = new QMenu(menuBar);
        menuWindow->setObjectName(QString::fromUtf8("menuWindow"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuSimulator = new QMenu(menuBar);
        menuSimulator->setObjectName(QString::fromUtf8("menuSimulator"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        dockWidgetPlugins = new QDockWidget(MainWindow);
        dockWidgetPlugins->setObjectName(QString::fromUtf8("dockWidgetPlugins"));
        dockWidgetPlugins->setAutoFillBackground(false);
        dockWidgetPlugins->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetPlugins_2 = new QWidget();
        dockWidgetPlugins_2->setObjectName(QString::fromUtf8("dockWidgetPlugins_2"));
        verticalLayout = new QVBoxLayout(dockWidgetPlugins_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget_Plugins = new QListWidget(dockWidgetPlugins_2);
        listWidget_Plugins->setObjectName(QString::fromUtf8("listWidget_Plugins"));

        verticalLayout->addWidget(listWidget_Plugins);

        dockWidgetPlugins->setWidget(dockWidgetPlugins_2);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, dockWidgetPlugins);
        dockWidgetProperties = new QDockWidget(MainWindow);
        dockWidgetProperties->setObjectName(QString::fromUtf8("dockWidgetProperties"));
        dockWidgetProperties->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents_Properties = new QWidget();
        dockWidgetContents_Properties->setObjectName(QString::fromUtf8("dockWidgetContents_Properties"));
        verticalLayout_3 = new QVBoxLayout(dockWidgetContents_Properties);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tableView_Properties = new QTableView(dockWidgetContents_Properties);
        tableView_Properties->setObjectName(QString::fromUtf8("tableView_Properties"));
        tableView_Properties->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableView_Properties->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        verticalLayout_3->addWidget(tableView_Properties);

        dockWidgetProperties->setWidget(dockWidgetContents_Properties);
        MainWindow->addDockWidget(Qt::RightDockWidgetArea, dockWidgetProperties);
        dockWidgetConsole = new QDockWidget(MainWindow);
        dockWidgetConsole->setObjectName(QString::fromUtf8("dockWidgetConsole"));
        dockWidgetConsole->setFloating(false);
        dockWidgetConsole->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetConsole->setAllowedAreas(Qt::AllDockWidgetAreas);
        dockWidgetContents_Console = new QWidget();
        dockWidgetContents_Console->setObjectName(QString::fromUtf8("dockWidgetContents_Console"));
        verticalLayout_4 = new QVBoxLayout(dockWidgetContents_Console);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        textEdit_Console = new QTextEdit(dockWidgetContents_Console);
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

        dockWidgetConsole->setWidget(dockWidgetContents_Console);
        MainWindow->addDockWidget(Qt::BottomDockWidgetArea, dockWidgetConsole);
        dockWidgetReports = new QDockWidget(MainWindow);
        dockWidgetReports->setObjectName(QString::fromUtf8("dockWidgetReports"));
        dockWidgetReports->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents_Reports = new QWidget();
        dockWidgetContents_Reports->setObjectName(QString::fromUtf8("dockWidgetContents_Reports"));
        verticalLayout_5 = new QVBoxLayout(dockWidgetContents_Reports);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        textEdit_Report = new QTextEdit(dockWidgetContents_Reports);
        textEdit_Report->setObjectName(QString::fromUtf8("textEdit_Report"));
        sizePolicy.setHeightForWidth(textEdit_Report->sizePolicy().hasHeightForWidth());
        textEdit_Report->setSizePolicy(sizePolicy);
        textEdit_Report->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        verticalLayout_5->addWidget(textEdit_Report);

        dockWidgetReports->setWidget(dockWidgetContents_Reports);
        MainWindow->addDockWidget(Qt::BottomDockWidgetArea, dockWidgetReports);
        dockWidgetExperiments = new QDockWidget(MainWindow);
        dockWidgetExperiments->setObjectName(QString::fromUtf8("dockWidgetExperiments"));
        dockWidgetContents_Experiments = new QWidget();
        dockWidgetContents_Experiments->setObjectName(QString::fromUtf8("dockWidgetContents_Experiments"));
        dockWidgetContents_Experiments->setMinimumSize(QSize(0, 144));
        listWidget_Experiments = new QListWidget(dockWidgetContents_Experiments);
        listWidget_Experiments->setObjectName(QString::fromUtf8("listWidget_Experiments"));
        listWidget_Experiments->setGeometry(QRect(10, 10, 201, 161));
        listWidget_Experiments->setAutoFillBackground(false);
        dockWidgetExperiments->setWidget(dockWidgetContents_Experiments);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, dockWidgetExperiments);

        menuBar->addAction(menuSimulator->menuAction());
        menuBar->addAction(menuEdit->menuAction());
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
        menuModel->addAction(actionInformation_2);
        menuModel->addAction(actionSimulation);
        menuModel->addSeparator();
        menuModel->addAction(actionComponents_3);
        menuModel->addAction(actionElements_3);
        menuModel->addSeparator();
        menuModel->addAction(actionSave_2);
        menuModel->addSeparator();
        menuModel->addAction(menuView_2->menuAction());
        menuView_2->addAction(actionZoom_In_2);
        menuView_2->addAction(actionZoom_Out_2);
        menuView_2->addAction(actionZoom_Facot);
        menuView_2->addSeparator();
        menuView_2->addAction(actionGrid_2);
        menuView_2->addAction(actionSnap_2);
        menuView_2->addSeparator();
        menuView_2->addAction(actionArranje);
        menuView_2->addAction(actionGroup_2);
        menuWindow->addAction(actionComponents);
        menuWindow->addAction(actionElements);
        menuWindow->addAction(actionProperties);
        menuWindow->addAction(actionEditor);
        menuWindow->addAction(actionConsole);
        menuWindow->addSeparator();
        menuWindow->addAction(actionModels);
        menuWindow->addSeparator();
        menuWindow->addAction(actionArranje_2);
        menuHelp->addAction(actionDocumentation);
        menuHelp->addAction(actionSupport);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout);
        menuSimulator->addSeparator();
        menuSimulator->addAction(actionPlugins_2);
        menuSimulator->addAction(actionExperiments);
        menuSimulator->addAction(actionModels_2);
        menuSimulator->addSeparator();
        menuSimulator->addAction(actionPreferences_2);
        menuSimulator->addSeparator();
        menuSimulator->addAction(actionExit_2);
        toolBar->addAction(actionZoom_Out);
        toolBar->addAction(actionZoom_Factor);

        retranslateUi(MainWindow);

        tabWidgetModels->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "GenESyS -- Generic and Expansible System Simulator", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
#if QT_CONFIG(tooltip)
        actionNew->setToolTip(QCoreApplication::translate("MainWindow", "New simulation model", nullptr));
#endif // QT_CONFIG(tooltip)
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionClose->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
#if QT_CONFIG(shortcut)
        actionClose->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+W", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_as->setText(QCoreApplication::translate("MainWindow", "Save all", nullptr));
#if QT_CONFIG(shortcut)
        actionSave_as->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+F4", nullptr));
#endif // QT_CONFIG(shortcut)
        actionUndo->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
#if QT_CONFIG(shortcut)
        actionUndo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRedo->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
#if QT_CONFIG(shortcut)
        actionRedo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCut->setText(QCoreApplication::translate("MainWindow", "Cut", nullptr));
#if QT_CONFIG(shortcut)
        actionCut->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCopy->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
#if QT_CONFIG(shortcut)
        actionCopy->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPaste->setText(QCoreApplication::translate("MainWindow", "Paste", nullptr));
#if QT_CONFIG(shortcut)
        actionPaste->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFind->setText(QCoreApplication::translate("MainWindow", "Find", nullptr));
#if QT_CONFIG(shortcut)
        actionFind->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        actionReplace->setText(QCoreApplication::translate("MainWindow", "Replace", nullptr));
#if QT_CONFIG(shortcut)
        actionReplace->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+H", nullptr));
#endif // QT_CONFIG(shortcut)
        actionGroup->setText(QCoreApplication::translate("MainWindow", "Group", nullptr));
        actionZoom_In->setText(QCoreApplication::translate("MainWindow", "Zoom In", nullptr));
#if QT_CONFIG(shortcut)
        actionZoom_In->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+=", nullptr));
#endif // QT_CONFIG(shortcut)
        actionZoom_Out->setText(QCoreApplication::translate("MainWindow", "Zoom Out", nullptr));
#if QT_CONFIG(shortcut)
        actionZoom_Out->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+-", nullptr));
#endif // QT_CONFIG(shortcut)
        actionZoom_Factor->setText(QCoreApplication::translate("MainWindow", "Zoom Factor", nullptr));
        actionGrid->setText(QCoreApplication::translate("MainWindow", "Grid", nullptr));
        actionSnap->setText(QCoreApplication::translate("MainWindow", "Snap", nullptr));
        actionInput_Analyser->setText(QCoreApplication::translate("MainWindow", "Input Analyser", nullptr));
        actionOutput_Analyser->setText(QCoreApplication::translate("MainWindow", "Output Analyser", nullptr));
        actionScenario_Manager->setText(QCoreApplication::translate("MainWindow", "Scenario Manager", nullptr));
        actionOptimizaton->setText(QCoreApplication::translate("MainWindow", "Optimizaton", nullptr));
        actionPreferences->setText(QCoreApplication::translate("MainWindow", "Preferences", nullptr));
        actionCheck_Model->setText(QCoreApplication::translate("MainWindow", "Check", nullptr));
#if QT_CONFIG(shortcut)
        actionCheck_Model->setShortcut(QCoreApplication::translate("MainWindow", "F4", nullptr));
#endif // QT_CONFIG(shortcut)
        actionStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
#if QT_CONFIG(shortcut)
        actionStart->setShortcut(QCoreApplication::translate("MainWindow", "F5", nullptr));
#endif // QT_CONFIG(shortcut)
        actionStep->setText(QCoreApplication::translate("MainWindow", "Step", nullptr));
#if QT_CONFIG(shortcut)
        actionStep->setShortcut(QCoreApplication::translate("MainWindow", "F7", nullptr));
#endif // QT_CONFIG(shortcut)
        actionStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
#if QT_CONFIG(shortcut)
        actionStop->setShortcut(QCoreApplication::translate("MainWindow", "F10", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRun_Control->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        actionComponents->setText(QCoreApplication::translate("MainWindow", "Plugins", nullptr));
        actionElements->setText(QCoreApplication::translate("MainWindow", "Experiments", nullptr));
        actionModels->setText(QCoreApplication::translate("MainWindow", "Models", nullptr));
        actionConsole->setText(QCoreApplication::translate("MainWindow", "Console", nullptr));
        actionProperties->setText(QCoreApplication::translate("MainWindow", "Properties", nullptr));
        actionEditor->setText(QCoreApplication::translate("MainWindow", "Reports", nullptr));
        actionDocumentation->setText(QCoreApplication::translate("MainWindow", "Documentation", nullptr));
#if QT_CONFIG(shortcut)
        actionDocumentation->setShortcut(QCoreApplication::translate("MainWindow", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSupport->setText(QCoreApplication::translate("MainWindow", "Support", nullptr));
#if QT_CONFIG(shortcut)
        actionSupport->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+F1", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About...", nullptr));
#if QT_CONFIG(shortcut)
        actionAbout->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+F1", nullptr));
#endif // QT_CONFIG(shortcut)
        actionTop->setText(QCoreApplication::translate("MainWindow", "Top", nullptr));
        actionBottom->setText(QCoreApplication::translate("MainWindow", "Bottom", nullptr));
        actionInformation->setText(QCoreApplication::translate("MainWindow", "Information", nullptr));
        actionReport->setText(QCoreApplication::translate("MainWindow", "Report", nullptr));
        actionComponents_2->setText(QCoreApplication::translate("MainWindow", "Components", nullptr));
        actionElements_2->setText(QCoreApplication::translate("MainWindow", "Elements", nullptr));
        actionTrace->setText(QCoreApplication::translate("MainWindow", "Trace", nullptr));
        actionEvents->setText(QCoreApplication::translate("MainWindow", "Events", nullptr));
        actionPause->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        actionExit_2->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionPreferences_2->setText(QCoreApplication::translate("MainWindow", "Preferences", nullptr));
        actionModels_2->setText(QCoreApplication::translate("MainWindow", "Models", nullptr));
        actionExperiments->setText(QCoreApplication::translate("MainWindow", "Experiments", nullptr));
        actionConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        actionZoom_In_2->setText(QCoreApplication::translate("MainWindow", "Zoom In", nullptr));
        actionZoom_Out_2->setText(QCoreApplication::translate("MainWindow", "Zoom Out", nullptr));
        actionZoom_Facot->setText(QCoreApplication::translate("MainWindow", "Zoom Facot", nullptr));
        actionGrid_2->setText(QCoreApplication::translate("MainWindow", "Grid", nullptr));
        actionSnap_2->setText(QCoreApplication::translate("MainWindow", "Snap", nullptr));
        actionArranje->setText(QCoreApplication::translate("MainWindow", "Arranje", nullptr));
        actionGroup_2->setText(QCoreApplication::translate("MainWindow", "Group", nullptr));
        actionPlugins_2->setText(QCoreApplication::translate("MainWindow", "Plugins", nullptr));
        actionInformation_2->setText(QCoreApplication::translate("MainWindow", "Information", nullptr));
        actionSimulation->setText(QCoreApplication::translate("MainWindow", "Simulation", nullptr));
        actionComponents_3->setText(QCoreApplication::translate("MainWindow", "Components", nullptr));
        actionElements_3->setText(QCoreApplication::translate("MainWindow", "Elements", nullptr));
        actionLoad->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        actionSave_2->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionEvents_Diagram->setText(QCoreApplication::translate("MainWindow", "Events Diagram", nullptr));
        actionArranje_2->setText(QCoreApplication::translate("MainWindow", "Arranje", nullptr));
        tabWidgetModels->setTabText(tabWidgetModels->indexOf(tabModel1), QCoreApplication::translate("MainWindow", "Model 1", nullptr));
        tabWidgetModels->setTabText(tabWidgetModels->indexOf(tabModel2), QCoreApplication::translate("MainWindow", "Model 2", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuModel->setTitle(QCoreApplication::translate("MainWindow", "Model", nullptr));
        menuView_2->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        menuWindow->setTitle(QCoreApplication::translate("MainWindow", "Window", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuSimulator->setTitle(QCoreApplication::translate("MainWindow", "Simulator", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
        dockWidgetPlugins->setWindowTitle(QCoreApplication::translate("MainWindow", "Plugins", nullptr));
        dockWidgetProperties->setWindowTitle(QCoreApplication::translate("MainWindow", "Properties", nullptr));
        dockWidgetConsole->setWindowTitle(QCoreApplication::translate("MainWindow", "Traces", nullptr));
        dockWidgetReports->setWindowTitle(QCoreApplication::translate("MainWindow", "Reports", nullptr));
        dockWidgetExperiments->setWindowTitle(QCoreApplication::translate("MainWindow", "Experiments", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
