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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ModelGraphicsView.h"

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
    QAction *actionAbout;
    QAction *actionLicence;
    QAction *actionGet_Involved;
    QAction *actionGrid;
    QAction *actionSnap;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionFind;
    QAction *actionReplace;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionRule;
    QAction *actionGuides;
    QAction *actionZoom_In;
    QAction *actionZoom_Out;
    QAction *actionZoom_All;
    QAction *actionLine;
    QAction *actionRectangle;
    QAction *actionEllipse;
    QAction *actionClock;
    QAction *actionVariable;
    QAction *actionAttribute;
    QAction *actionExpression;
    QAction *actionResource;
    QAction *actionQueue;
    QAction *actionStation;
    QAction *actionConnect;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidgetCentral;
    QWidget *tabModel;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabWidget_Model;
    QWidget *tabModelText;
    QVBoxLayout *verticalLayout_4;
    QWidget *tabModelGraphic;
    QVBoxLayout *verticalLayout_6;
    QScrollArea *scrollArea_Graphic;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_ModelGraphic;
    QHBoxLayout *horizontalLayout;
    QLabel *label_Zoom;
    QSlider *horizontalSlider_Zoom;
    QCheckBox *checkBox_ShowElements;
    QCheckBox *checkBox_ShowInternals;
    QCheckBox *checkBox_ShowLevels;
    QCheckBox *checkBox_ShowRecursive;
    QPushButton *pushButton_Export;
    QWidget *tabModelGraphicEdit;
    QVBoxLayout *verticalLayout_14;
    ModelGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelMousePos;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QSlider *horizontalSlider_ZoomGraphical;
    QSpacerItem *horizontalSpacer_3;
    QWidget *tabDebug;
    QVBoxLayout *verticalLayout_9;
    QTabWidget *tabWidget_Debug;
    QWidget *tab_Debug_Breakpoints;
    QVBoxLayout *verticalLayout_10;
    QTableWidget *tableWidget_Breakpoints;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_Breakpoint_Insert;
    QPushButton *pushButton_Breakpoint_Remove;
    QSpacerItem *horizontalSpacer;
    QWidget *tab_Debug_Variables;
    QVBoxLayout *verticalLayout_13;
    QTableWidget *tableWidget_Variables;
    QWidget *tabDebug_Entities;
    QVBoxLayout *verticalLayout_12;
    QTableWidget *tableWidget_Entities;
    QWidget *tabSimulation;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget_Simulation;
    QWidget *tab_Simulation_Trace;
    QVBoxLayout *verticalLayout_7;
    QTextEdit *textEdit_Simulation;
    QWidget *tab_Simulation_Event;
    QVBoxLayout *verticalLayout_8;
    QTableWidget *tableWidget_Simulation_Event;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *label_ReplicationNum;
    QLabel *label;
    QProgressBar *progressBarSimulation;
    QWidget *tabReport;
    QVBoxLayout *verticalLayout_11;
    QTabWidget *tabWidget_Report;
    QWidget *tabReportTextr;
    QVBoxLayout *verticalLayout_15;
    QTextEdit *textEdit_Reports;
    QWidget *tabReportGraphics;
    QMenuBar *menubar;
    QMenu *menuModel;
    QMenu *menuSimulation;
    QMenu *menuAbout;
    QMenu *menuView;
    QMenu *menuZoom;
    QMenu *menuDraw;
    QMenu *menuAnime;
    QMenu *menuEdit;
    QStatusBar *statusbar;
    QToolBar *toolBarModel;
    QDockWidget *dockWidgetConsole;
    QWidget *dockWidgetContentsConsole;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit_Console;
    QDockWidget *dockWidgetPlugins;
    QWidget *dockWidgetContentsPlugin;
    QHBoxLayout *horizontalLayout_2;
    QTreeWidget *treeWidget_Plugins;
    QDockWidget *dockWidgetPropertyEditor;
    QWidget *dockWidgetContents;
    QHBoxLayout *horizontalLayout_4;
    QTreeView *treeViewPropertyEditor;
    QToolBar *toolBarGraphicalModel;
    QToolBar *toolBarEdit;
    QToolBar *toolBarView;
    QToolBar *toolBarSimulation;
    QToolBar *toolBarAbout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1231, 640);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/genesysico.gif"), QSize(), QIcon::Normal, QIcon::Off);
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
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/icons1/resources/icons/pack1/ico/106.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon12);
        actionLicence = new QAction(MainWindow);
        actionLicence->setObjectName(QString::fromUtf8("actionLicence"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/icons2/resources/icons/pack2/ico/28.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionLicence->setIcon(icon13);
        actionGet_Involved = new QAction(MainWindow);
        actionGet_Involved->setObjectName(QString::fromUtf8("actionGet_Involved"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/user group.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionGet_Involved->setIcon(icon14);
        actionGrid = new QAction(MainWindow);
        actionGrid->setObjectName(QString::fromUtf8("actionGrid"));
        actionGrid->setCheckable(true);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/question.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionGrid->setIcon(icon15);
        actionSnap = new QAction(MainWindow);
        actionSnap->setObjectName(QString::fromUtf8("actionSnap"));
        actionSnap->setCheckable(true);
        actionSnap->setIcon(icon15);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/undo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon16);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/redo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon17);
        actionFind = new QAction(MainWindow);
        actionFind->setObjectName(QString::fromUtf8("actionFind"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/find.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionFind->setIcon(icon18);
        actionReplace = new QAction(MainWindow);
        actionReplace->setObjectName(QString::fromUtf8("actionReplace"));
        actionReplace->setIcon(icon18);
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/cut.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon19);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/copy.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon20);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/paste.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon21);
        actionRule = new QAction(MainWindow);
        actionRule->setObjectName(QString::fromUtf8("actionRule"));
        actionRule->setCheckable(true);
        actionRule->setIcon(icon15);
        actionGuides = new QAction(MainWindow);
        actionGuides->setObjectName(QString::fromUtf8("actionGuides"));
        actionGuides->setCheckable(true);
        actionGuides->setIcon(icon15);
        actionZoom_In = new QAction(MainWindow);
        actionZoom_In->setObjectName(QString::fromUtf8("actionZoom_In"));
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/icons2/resources/icons/pack2/ico/83.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoom_In->setIcon(icon22);
        actionZoom_Out = new QAction(MainWindow);
        actionZoom_Out->setObjectName(QString::fromUtf8("actionZoom_Out"));
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/icons2/resources/icons/pack2/ico/82.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoom_Out->setIcon(icon23);
        actionZoom_All = new QAction(MainWindow);
        actionZoom_All->setObjectName(QString::fromUtf8("actionZoom_All"));
        QIcon icon24;
        icon24.addFile(QString::fromUtf8(":/icons2/resources/icons/pack2/ico/84.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoom_All->setIcon(icon24);
        actionLine = new QAction(MainWindow);
        actionLine->setObjectName(QString::fromUtf8("actionLine"));
        actionLine->setIcon(icon15);
        actionRectangle = new QAction(MainWindow);
        actionRectangle->setObjectName(QString::fromUtf8("actionRectangle"));
        actionRectangle->setIcon(icon15);
        actionEllipse = new QAction(MainWindow);
        actionEllipse->setObjectName(QString::fromUtf8("actionEllipse"));
        actionEllipse->setIcon(icon15);
        actionClock = new QAction(MainWindow);
        actionClock->setObjectName(QString::fromUtf8("actionClock"));
        actionClock->setIcon(icon15);
        actionVariable = new QAction(MainWindow);
        actionVariable->setObjectName(QString::fromUtf8("actionVariable"));
        actionVariable->setIcon(icon15);
        actionAttribute = new QAction(MainWindow);
        actionAttribute->setObjectName(QString::fromUtf8("actionAttribute"));
        actionAttribute->setIcon(icon15);
        actionExpression = new QAction(MainWindow);
        actionExpression->setObjectName(QString::fromUtf8("actionExpression"));
        actionExpression->setIcon(icon15);
        actionResource = new QAction(MainWindow);
        actionResource->setObjectName(QString::fromUtf8("actionResource"));
        actionResource->setIcon(icon15);
        actionQueue = new QAction(MainWindow);
        actionQueue->setObjectName(QString::fromUtf8("actionQueue"));
        actionQueue->setIcon(icon15);
        actionStation = new QAction(MainWindow);
        actionStation->setObjectName(QString::fromUtf8("actionStation"));
        actionStation->setIcon(icon15);
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        QIcon icon25;
        icon25.addFile(QString::fromUtf8(":/mxgraph/resources/icons/pack4/iconsMxGraph/vertical.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect->setIcon(icon25);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidgetCentral = new QTabWidget(centralwidget);
        tabWidgetCentral->setObjectName(QString::fromUtf8("tabWidgetCentral"));
        tabWidgetCentral->setEnabled(false);
        QFont font;
        font.setPointSize(12);
        tabWidgetCentral->setFont(font);
        tabModel = new QWidget();
        tabModel->setObjectName(QString::fromUtf8("tabModel"));
        verticalLayout_3 = new QVBoxLayout(tabModel);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tabWidget_Model = new QTabWidget(tabModel);
        tabWidget_Model->setObjectName(QString::fromUtf8("tabWidget_Model"));
        tabWidget_Model->setTabPosition(QTabWidget::East);
        tabModelText = new QWidget();
        tabModelText->setObjectName(QString::fromUtf8("tabModelText"));
        verticalLayout_4 = new QVBoxLayout(tabModelText);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        QIcon icon26;
        icon26.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/text.ico"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget_Model->addTab(tabModelText, icon26, QString());
        tabModelGraphic = new QWidget();
        tabModelGraphic->setObjectName(QString::fromUtf8("tabModelGraphic"));
        verticalLayout_6 = new QVBoxLayout(tabModelGraphic);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        scrollArea_Graphic = new QScrollArea(tabModelGraphic);
        scrollArea_Graphic->setObjectName(QString::fromUtf8("scrollArea_Graphic"));
        scrollArea_Graphic->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_Graphic->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 849, 386));
        verticalLayout_5 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_ModelGraphic = new QLabel(scrollAreaWidgetContents);
        label_ModelGraphic->setObjectName(QString::fromUtf8("label_ModelGraphic"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(3);
        sizePolicy.setHeightForWidth(label_ModelGraphic->sizePolicy().hasHeightForWidth());
        label_ModelGraphic->setSizePolicy(sizePolicy);
        label_ModelGraphic->setAutoFillBackground(true);
        label_ModelGraphic->setFrameShadow(QFrame::Plain);

        verticalLayout_5->addWidget(label_ModelGraphic);

        scrollArea_Graphic->setWidget(scrollAreaWidgetContents);

        verticalLayout_6->addWidget(scrollArea_Graphic);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_Zoom = new QLabel(tabModelGraphic);
        label_Zoom->setObjectName(QString::fromUtf8("label_Zoom"));

        horizontalLayout->addWidget(label_Zoom);

        horizontalSlider_Zoom = new QSlider(tabModelGraphic);
        horizontalSlider_Zoom->setObjectName(QString::fromUtf8("horizontalSlider_Zoom"));
        horizontalSlider_Zoom->setEnabled(false);
        horizontalSlider_Zoom->setMaximum(100);
        horizontalSlider_Zoom->setValue(50);
        horizontalSlider_Zoom->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider_Zoom);

        checkBox_ShowElements = new QCheckBox(tabModelGraphic);
        checkBox_ShowElements->setObjectName(QString::fromUtf8("checkBox_ShowElements"));
        checkBox_ShowElements->setChecked(false);

        horizontalLayout->addWidget(checkBox_ShowElements);

        checkBox_ShowInternals = new QCheckBox(tabModelGraphic);
        checkBox_ShowInternals->setObjectName(QString::fromUtf8("checkBox_ShowInternals"));
        checkBox_ShowInternals->setChecked(false);

        horizontalLayout->addWidget(checkBox_ShowInternals);

        checkBox_ShowLevels = new QCheckBox(tabModelGraphic);
        checkBox_ShowLevels->setObjectName(QString::fromUtf8("checkBox_ShowLevels"));

        horizontalLayout->addWidget(checkBox_ShowLevels);

        checkBox_ShowRecursive = new QCheckBox(tabModelGraphic);
        checkBox_ShowRecursive->setObjectName(QString::fromUtf8("checkBox_ShowRecursive"));

        horizontalLayout->addWidget(checkBox_ShowRecursive);

        pushButton_Export = new QPushButton(tabModelGraphic);
        pushButton_Export->setObjectName(QString::fromUtf8("pushButton_Export"));

        horizontalLayout->addWidget(pushButton_Export);


        verticalLayout_6->addLayout(horizontalLayout);

        tabWidget_Model->addTab(tabModelGraphic, icon25, QString());
        tabModelGraphicEdit = new QWidget();
        tabModelGraphicEdit->setObjectName(QString::fromUtf8("tabModelGraphicEdit"));
        verticalLayout_14 = new QVBoxLayout(tabModelGraphicEdit);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        graphicsView = new ModelGraphicsView(tabModelGraphicEdit);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        verticalLayout_14->addWidget(graphicsView);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        labelMousePos = new QLabel(tabModelGraphicEdit);
        labelMousePos->setObjectName(QString::fromUtf8("labelMousePos"));
        QFont font1;
        font1.setPointSize(10);
        labelMousePos->setFont(font1);

        horizontalLayout_5->addWidget(labelMousePos);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        label_3 = new QLabel(tabModelGraphicEdit);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        horizontalSlider_ZoomGraphical = new QSlider(tabModelGraphicEdit);
        horizontalSlider_ZoomGraphical->setObjectName(QString::fromUtf8("horizontalSlider_ZoomGraphical"));
        horizontalSlider_ZoomGraphical->setMinimum(1);
        horizontalSlider_ZoomGraphical->setMaximum(1000);
        horizontalSlider_ZoomGraphical->setSingleStep(1);
        horizontalSlider_ZoomGraphical->setValue(500);
        horizontalSlider_ZoomGraphical->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(horizontalSlider_ZoomGraphical);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_14->addLayout(horizontalLayout_5);

        QIcon icon27;
        icon27.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/diagram.ico"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget_Model->addTab(tabModelGraphicEdit, icon27, QString());

        verticalLayout_3->addWidget(tabWidget_Model);

        QIcon icon28;
        icon28.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/list.ico"), QSize(), QIcon::Normal, QIcon::On);
        tabWidgetCentral->addTab(tabModel, icon28, QString());
        tabDebug = new QWidget();
        tabDebug->setObjectName(QString::fromUtf8("tabDebug"));
        verticalLayout_9 = new QVBoxLayout(tabDebug);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        tabWidget_Debug = new QTabWidget(tabDebug);
        tabWidget_Debug->setObjectName(QString::fromUtf8("tabWidget_Debug"));
        tabWidget_Debug->setTabPosition(QTabWidget::East);
        tab_Debug_Breakpoints = new QWidget();
        tab_Debug_Breakpoints->setObjectName(QString::fromUtf8("tab_Debug_Breakpoints"));
        verticalLayout_10 = new QVBoxLayout(tab_Debug_Breakpoints);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        tableWidget_Breakpoints = new QTableWidget(tab_Debug_Breakpoints);
        if (tableWidget_Breakpoints->columnCount() < 3)
            tableWidget_Breakpoints->setColumnCount(3);
        tableWidget_Breakpoints->setObjectName(QString::fromUtf8("tableWidget_Breakpoints"));
        tableWidget_Breakpoints->setEnabled(false);
        tableWidget_Breakpoints->setColumnCount(3);
        tableWidget_Breakpoints->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));

        verticalLayout_10->addWidget(tableWidget_Breakpoints);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        pushButton_Breakpoint_Insert = new QPushButton(tab_Debug_Breakpoints);
        pushButton_Breakpoint_Insert->setObjectName(QString::fromUtf8("pushButton_Breakpoint_Insert"));

        horizontalLayout_6->addWidget(pushButton_Breakpoint_Insert);

        pushButton_Breakpoint_Remove = new QPushButton(tab_Debug_Breakpoints);
        pushButton_Breakpoint_Remove->setObjectName(QString::fromUtf8("pushButton_Breakpoint_Remove"));

        horizontalLayout_6->addWidget(pushButton_Breakpoint_Remove);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);


        verticalLayout_10->addLayout(horizontalLayout_6);

        QIcon icon29;
        icon29.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/abort.ico"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget_Debug->addTab(tab_Debug_Breakpoints, icon29, QString());
        tab_Debug_Variables = new QWidget();
        tab_Debug_Variables->setObjectName(QString::fromUtf8("tab_Debug_Variables"));
        verticalLayout_13 = new QVBoxLayout(tab_Debug_Variables);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        tableWidget_Variables = new QTableWidget(tab_Debug_Variables);
        if (tableWidget_Variables->columnCount() < 3)
            tableWidget_Variables->setColumnCount(3);
        tableWidget_Variables->setObjectName(QString::fromUtf8("tableWidget_Variables"));
        tableWidget_Variables->setEnabled(false);
        tableWidget_Variables->setColumnCount(3);
        tableWidget_Variables->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));

        verticalLayout_13->addWidget(tableWidget_Variables);

        QIcon icon30;
        icon30.addFile(QString::fromUtf8(":/icons1/resources/icons/pack1/ico/35.ico"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget_Debug->addTab(tab_Debug_Variables, icon30, QString());
        tabDebug_Entities = new QWidget();
        tabDebug_Entities->setObjectName(QString::fromUtf8("tabDebug_Entities"));
        verticalLayout_12 = new QVBoxLayout(tabDebug_Entities);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        tableWidget_Entities = new QTableWidget(tabDebug_Entities);
        if (tableWidget_Entities->columnCount() < 3)
            tableWidget_Entities->setColumnCount(3);
        tableWidget_Entities->setObjectName(QString::fromUtf8("tableWidget_Entities"));
        tableWidget_Entities->setEnabled(false);
        tableWidget_Entities->setColumnCount(3);
        tableWidget_Entities->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));

        verticalLayout_12->addWidget(tableWidget_Entities);

        QIcon icon31;
        icon31.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/yellow pin.ico"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget_Debug->addTab(tabDebug_Entities, icon31, QString());

        verticalLayout_9->addWidget(tabWidget_Debug);

        tabWidgetCentral->addTab(tabDebug, QString());
        tabSimulation = new QWidget();
        tabSimulation->setObjectName(QString::fromUtf8("tabSimulation"));
        verticalLayout_2 = new QVBoxLayout(tabSimulation);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tabWidget_Simulation = new QTabWidget(tabSimulation);
        tabWidget_Simulation->setObjectName(QString::fromUtf8("tabWidget_Simulation"));
        tabWidget_Simulation->setTabPosition(QTabWidget::East);
        tab_Simulation_Trace = new QWidget();
        tab_Simulation_Trace->setObjectName(QString::fromUtf8("tab_Simulation_Trace"));
        verticalLayout_7 = new QVBoxLayout(tab_Simulation_Trace);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        textEdit_Simulation = new QTextEdit(tab_Simulation_Trace);
        textEdit_Simulation->setObjectName(QString::fromUtf8("textEdit_Simulation"));
        textEdit_Simulation->setFont(font1);
        textEdit_Simulation->setLineWrapMode(QTextEdit::NoWrap);
        textEdit_Simulation->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout_7->addWidget(textEdit_Simulation);

        QIcon icon32;
        icon32.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/movie.ico"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget_Simulation->addTab(tab_Simulation_Trace, icon32, QString());
        tab_Simulation_Event = new QWidget();
        tab_Simulation_Event->setObjectName(QString::fromUtf8("tab_Simulation_Event"));
        verticalLayout_8 = new QVBoxLayout(tab_Simulation_Event);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        tableWidget_Simulation_Event = new QTableWidget(tab_Simulation_Event);
        if (tableWidget_Simulation_Event->columnCount() < 3)
            tableWidget_Simulation_Event->setColumnCount(3);
        tableWidget_Simulation_Event->setObjectName(QString::fromUtf8("tableWidget_Simulation_Event"));
        tableWidget_Simulation_Event->setFont(font1);
        tableWidget_Simulation_Event->setWordWrap(false);
        tableWidget_Simulation_Event->setRowCount(0);
        tableWidget_Simulation_Event->setColumnCount(3);

        verticalLayout_8->addWidget(tableWidget_Simulation_Event);

        QIcon icon33;
        icon33.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/table.ico"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget_Simulation->addTab(tab_Simulation_Event, icon33, QString());

        verticalLayout_2->addWidget(tabWidget_Simulation);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(tabSimulation);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        label_ReplicationNum = new QLabel(tabSimulation);
        label_ReplicationNum->setObjectName(QString::fromUtf8("label_ReplicationNum"));

        horizontalLayout_3->addWidget(label_ReplicationNum);

        label = new QLabel(tabSimulation);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        progressBarSimulation = new QProgressBar(tabSimulation);
        progressBarSimulation->setObjectName(QString::fromUtf8("progressBarSimulation"));
        progressBarSimulation->setValue(0);

        horizontalLayout_3->addWidget(progressBarSimulation);


        verticalLayout_2->addLayout(horizontalLayout_3);

        QIcon icon34;
        icon34.addFile(QString::fromUtf8(":/icons2/resources/icons/pack2/ico/19.ico"), QSize(), QIcon::Normal, QIcon::On);
        tabWidgetCentral->addTab(tabSimulation, icon34, QString());
        tabReport = new QWidget();
        tabReport->setObjectName(QString::fromUtf8("tabReport"));
        verticalLayout_11 = new QVBoxLayout(tabReport);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        tabWidget_Report = new QTabWidget(tabReport);
        tabWidget_Report->setObjectName(QString::fromUtf8("tabWidget_Report"));
        tabWidget_Report->setTabPosition(QTabWidget::East);
        tabReportTextr = new QWidget();
        tabReportTextr->setObjectName(QString::fromUtf8("tabReportTextr"));
        verticalLayout_15 = new QVBoxLayout(tabReportTextr);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        textEdit_Reports = new QTextEdit(tabReportTextr);
        textEdit_Reports->setObjectName(QString::fromUtf8("textEdit_Reports"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Courier 10 Pitch"));
        font2.setPointSize(10);
        textEdit_Reports->setFont(font2);
        textEdit_Reports->setLineWrapMode(QTextEdit::NoWrap);
        textEdit_Reports->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout_15->addWidget(textEdit_Reports);

        tabWidget_Report->addTab(tabReportTextr, icon26, QString());
        tabReportGraphics = new QWidget();
        tabReportGraphics->setObjectName(QString::fromUtf8("tabReportGraphics"));
        QIcon icon35;
        icon35.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/stock graph.ico"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget_Report->addTab(tabReportGraphics, icon35, QString());

        verticalLayout_11->addWidget(tabWidget_Report);

        QIcon icon36;
        icon36.addFile(QString::fromUtf8(":/icons2/resources/icons/pack2/ico/16.ico"), QSize(), QIcon::Normal, QIcon::On);
        tabWidgetCentral->addTab(tabReport, icon36, QString());

        gridLayout->addWidget(tabWidgetCentral, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1231, 24));
        menuModel = new QMenu(menubar);
        menuModel->setObjectName(QString::fromUtf8("menuModel"));
        menuSimulation = new QMenu(menubar);
        menuSimulation->setObjectName(QString::fromUtf8("menuSimulation"));
        menuSimulation->setEnabled(false);
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuZoom = new QMenu(menuView);
        menuZoom->setObjectName(QString::fromUtf8("menuZoom"));
        menuDraw = new QMenu(menuView);
        menuDraw->setObjectName(QString::fromUtf8("menuDraw"));
        menuAnime = new QMenu(menuView);
        menuAnime->setObjectName(QString::fromUtf8("menuAnime"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBarModel = new QToolBar(MainWindow);
        toolBarModel->setObjectName(QString::fromUtf8("toolBarModel"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBarModel);
        dockWidgetConsole = new QDockWidget(MainWindow);
        dockWidgetConsole->setObjectName(QString::fromUtf8("dockWidgetConsole"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dockWidgetConsole->sizePolicy().hasHeightForWidth());
        dockWidgetConsole->setSizePolicy(sizePolicy1);
        dockWidgetConsole->setMinimumSize(QSize(100, 109));
        dockWidgetConsole->setMaximumSize(QSize(524287, 200));
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
        textEdit_Console->setFont(font1);
        textEdit_Console->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout->addWidget(textEdit_Console);

        dockWidgetConsole->setWidget(dockWidgetContentsConsole);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, dockWidgetConsole);
        dockWidgetPlugins = new QDockWidget(MainWindow);
        dockWidgetPlugins->setObjectName(QString::fromUtf8("dockWidgetPlugins"));
        sizePolicy1.setHeightForWidth(dockWidgetPlugins->sizePolicy().hasHeightForWidth());
        dockWidgetPlugins->setSizePolicy(sizePolicy1);
        dockWidgetPlugins->setBaseSize(QSize(100, 100));
        QIcon icon37;
        icon37.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/component.ico"), QSize(), QIcon::Normal, QIcon::Off);
        dockWidgetPlugins->setWindowIcon(icon37);
        dockWidgetPlugins->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetPlugins->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContentsPlugin = new QWidget();
        dockWidgetContentsPlugin->setObjectName(QString::fromUtf8("dockWidgetContentsPlugin"));
        horizontalLayout_2 = new QHBoxLayout(dockWidgetContentsPlugin);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        treeWidget_Plugins = new QTreeWidget(dockWidgetContentsPlugin);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget_Plugins->setHeaderItem(__qtreewidgetitem);
        treeWidget_Plugins->setObjectName(QString::fromUtf8("treeWidget_Plugins"));
        treeWidget_Plugins->setDragEnabled(true);
        treeWidget_Plugins->setDragDropMode(QAbstractItemView::DragDrop);
        treeWidget_Plugins->setDefaultDropAction(Qt::CopyAction);
        treeWidget_Plugins->setAlternatingRowColors(true);
        treeWidget_Plugins->setIndentation(6);
        treeWidget_Plugins->setSortingEnabled(true);
        treeWidget_Plugins->setAnimated(false);
        treeWidget_Plugins->setWordWrap(true);
        treeWidget_Plugins->header()->setVisible(false);

        horizontalLayout_2->addWidget(treeWidget_Plugins);

        dockWidgetPlugins->setWidget(dockWidgetContentsPlugin);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, dockWidgetPlugins);
        dockWidgetPropertyEditor = new QDockWidget(MainWindow);
        dockWidgetPropertyEditor->setObjectName(QString::fromUtf8("dockWidgetPropertyEditor"));
        dockWidgetPropertyEditor->setFloating(false);
        dockWidgetPropertyEditor->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetPropertyEditor->setAllowedAreas(Qt::BottomDockWidgetArea|Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        horizontalLayout_4 = new QHBoxLayout(dockWidgetContents);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        treeViewPropertyEditor = new QTreeView(dockWidgetContents);
        treeViewPropertyEditor->setObjectName(QString::fromUtf8("treeViewPropertyEditor"));

        horizontalLayout_4->addWidget(treeViewPropertyEditor);

        dockWidgetPropertyEditor->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, dockWidgetPropertyEditor);
        toolBarGraphicalModel = new QToolBar(MainWindow);
        toolBarGraphicalModel->setObjectName(QString::fromUtf8("toolBarGraphicalModel"));
        toolBarGraphicalModel->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolBarGraphicalModel->setFloatable(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBarGraphicalModel);
        MainWindow->insertToolBarBreak(toolBarGraphicalModel);
        toolBarEdit = new QToolBar(MainWindow);
        toolBarEdit->setObjectName(QString::fromUtf8("toolBarEdit"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBarEdit);
        toolBarView = new QToolBar(MainWindow);
        toolBarView->setObjectName(QString::fromUtf8("toolBarView"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBarView);
        toolBarSimulation = new QToolBar(MainWindow);
        toolBarSimulation->setObjectName(QString::fromUtf8("toolBarSimulation"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBarSimulation);
        toolBarAbout = new QToolBar(MainWindow);
        toolBarAbout->setObjectName(QString::fromUtf8("toolBarAbout"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBarAbout);
        QWidget::setTabOrder(textEdit_Reports, tabWidgetCentral);

        menubar->addAction(menuModel->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuSimulation->menuAction());
        menubar->addAction(menuAbout->menuAction());
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
        menuAbout->addAction(actionAbout);
        menuAbout->addAction(actionLicence);
        menuAbout->addAction(actionGet_Involved);
        menuView->addAction(actionGrid);
        menuView->addAction(actionRule);
        menuView->addAction(actionSnap);
        menuView->addAction(actionGuides);
        menuView->addSeparator();
        menuView->addAction(actionConnect);
        menuView->addSeparator();
        menuView->addAction(menuDraw->menuAction());
        menuView->addAction(menuAnime->menuAction());
        menuView->addSeparator();
        menuView->addAction(menuZoom->menuAction());
        menuZoom->addAction(actionZoom_In);
        menuZoom->addAction(actionZoom_Out);
        menuZoom->addAction(actionZoom_All);
        menuDraw->addAction(actionLine);
        menuDraw->addAction(actionRectangle);
        menuDraw->addAction(actionEllipse);
        menuAnime->addAction(actionClock);
        menuAnime->addAction(actionVariable);
        menuAnime->addAction(actionAttribute);
        menuAnime->addAction(actionExpression);
        menuAnime->addAction(actionResource);
        menuAnime->addAction(actionQueue);
        menuAnime->addAction(actionStation);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addSeparator();
        menuEdit->addAction(actionFind);
        toolBarModel->addAction(actionNew);
        toolBarModel->addAction(actionOpen);
        toolBarModel->addAction(actionSave);
        toolBarModel->addAction(actionClose);
        toolBarModel->addSeparator();
        toolBarModel->addAction(actionCheck);
        toolBarModel->addSeparator();
        toolBarModel->addAction(actionExit);
        toolBarGraphicalModel->addSeparator();
        toolBarGraphicalModel->addAction(actionGrid);
        toolBarGraphicalModel->addAction(actionRule);
        toolBarGraphicalModel->addAction(actionSnap);
        toolBarGraphicalModel->addAction(actionGuides);
        toolBarGraphicalModel->addSeparator();
        toolBarGraphicalModel->addAction(actionConnect);
        toolBarGraphicalModel->addSeparator();
        toolBarGraphicalModel->addAction(actionLine);
        toolBarGraphicalModel->addAction(actionRectangle);
        toolBarGraphicalModel->addAction(actionEllipse);
        toolBarGraphicalModel->addSeparator();
        toolBarGraphicalModel->addAction(actionClock);
        toolBarGraphicalModel->addAction(actionVariable);
        toolBarGraphicalModel->addAction(actionAttribute);
        toolBarGraphicalModel->addAction(actionExpression);
        toolBarEdit->addAction(actionUndo);
        toolBarEdit->addAction(actionRedo);
        toolBarEdit->addSeparator();
        toolBarEdit->addAction(actionCut);
        toolBarEdit->addAction(actionCopy);
        toolBarEdit->addAction(actionPaste);
        toolBarView->addAction(actionZoom_In);
        toolBarView->addAction(actionZoom_Out);
        toolBarView->addAction(actionZoom_All);
        toolBarSimulation->addAction(actionStart);
        toolBarSimulation->addAction(actionStep);
        toolBarSimulation->addAction(actionStop);
        toolBarSimulation->addAction(actionPause);
        toolBarSimulation->addAction(actionResume);
        toolBarAbout->addAction(actionAbout);
        toolBarAbout->addAction(actionLicence);
        toolBarAbout->addAction(actionGet_Involved);

        retranslateUi(MainWindow);

        tabWidgetCentral->setCurrentIndex(0);
        tabWidget_Model->setCurrentIndex(2);
        tabWidget_Debug->setCurrentIndex(0);
        tabWidget_Simulation->setCurrentIndex(0);
        tabWidget_Report->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "GenESyS - Generic and Expansible System Simulator", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
#if QT_CONFIG(tooltip)
        actionNew->setToolTip(QCoreApplication::translate("MainWindow", "New Model", nullptr));
#endif // QT_CONFIG(tooltip)
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
#if QT_CONFIG(tooltip)
        actionOpen->setToolTip(QCoreApplication::translate("MainWindow", "Open Model", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
#if QT_CONFIG(tooltip)
        actionSave->setToolTip(QCoreApplication::translate("MainWindow", "Save Model", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(tooltip)
        actionExit->setToolTip(QCoreApplication::translate("MainWindow", "Exit Genesys", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
#if QT_CONFIG(tooltip)
        actionStart->setToolTip(QCoreApplication::translate("MainWindow", "Start Simulation", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionStart->setShortcut(QCoreApplication::translate("MainWindow", "F5", nullptr));
#endif // QT_CONFIG(shortcut)
        actionStep->setText(QCoreApplication::translate("MainWindow", "Step", nullptr));
#if QT_CONFIG(tooltip)
        actionStep->setToolTip(QCoreApplication::translate("MainWindow", "Step Simulation", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionStep->setShortcut(QCoreApplication::translate("MainWindow", "F6", nullptr));
#endif // QT_CONFIG(shortcut)
        actionStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
#if QT_CONFIG(tooltip)
        actionStop->setToolTip(QCoreApplication::translate("MainWindow", "Stop Simulation", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionStop->setShortcut(QCoreApplication::translate("MainWindow", "F7", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPause->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
#if QT_CONFIG(tooltip)
        actionPause->setToolTip(QCoreApplication::translate("MainWindow", "Pause Simulation", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionPause->setShortcut(QCoreApplication::translate("MainWindow", "F8", nullptr));
#endif // QT_CONFIG(shortcut)
        actionResume->setText(QCoreApplication::translate("MainWindow", "Resume", nullptr));
#if QT_CONFIG(tooltip)
        actionResume->setToolTip(QCoreApplication::translate("MainWindow", "Resume Simulation", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionResume->setShortcut(QCoreApplication::translate("MainWindow", "F9", nullptr));
#endif // QT_CONFIG(shortcut)
        actionClose->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
#if QT_CONFIG(tooltip)
        actionClose->setToolTip(QCoreApplication::translate("MainWindow", "Close Model", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionClose->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+W", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCheck->setText(QCoreApplication::translate("MainWindow", "Check", nullptr));
#if QT_CONFIG(tooltip)
        actionCheck->setToolTip(QCoreApplication::translate("MainWindow", "Check Model", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionCheck->setShortcut(QCoreApplication::translate("MainWindow", "F4", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "Genesys", nullptr));
#if QT_CONFIG(tooltip)
        actionAbout->setToolTip(QCoreApplication::translate("MainWindow", "About Genesys", nullptr));
#endif // QT_CONFIG(tooltip)
        actionLicence->setText(QCoreApplication::translate("MainWindow", "Licence", nullptr));
#if QT_CONFIG(tooltip)
        actionLicence->setToolTip(QCoreApplication::translate("MainWindow", "About Licence", nullptr));
#endif // QT_CONFIG(tooltip)
        actionGet_Involved->setText(QCoreApplication::translate("MainWindow", "Get Involved", nullptr));
#if QT_CONFIG(tooltip)
        actionGet_Involved->setToolTip(QCoreApplication::translate("MainWindow", "Get Involved in Genesys", nullptr));
#endif // QT_CONFIG(tooltip)
        actionGrid->setText(QCoreApplication::translate("MainWindow", "Grid", nullptr));
        actionSnap->setText(QCoreApplication::translate("MainWindow", "Snap", nullptr));
        actionUndo->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
#if QT_CONFIG(shortcut)
        actionUndo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRedo->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
#if QT_CONFIG(shortcut)
        actionRedo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Y", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFind->setText(QCoreApplication::translate("MainWindow", "Find", nullptr));
#if QT_CONFIG(shortcut)
        actionFind->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        actionReplace->setText(QCoreApplication::translate("MainWindow", "Replace", nullptr));
#if QT_CONFIG(shortcut)
        actionReplace->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
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
        actionRule->setText(QCoreApplication::translate("MainWindow", "Rule", nullptr));
        actionGuides->setText(QCoreApplication::translate("MainWindow", "Guides", nullptr));
        actionZoom_In->setText(QCoreApplication::translate("MainWindow", "Zoom In", nullptr));
#if QT_CONFIG(shortcut)
        actionZoom_In->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+=", nullptr));
#endif // QT_CONFIG(shortcut)
        actionZoom_Out->setText(QCoreApplication::translate("MainWindow", "Zoom Out", nullptr));
#if QT_CONFIG(shortcut)
        actionZoom_Out->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+-", nullptr));
#endif // QT_CONFIG(shortcut)
        actionZoom_All->setText(QCoreApplication::translate("MainWindow", "Zoom All", nullptr));
#if QT_CONFIG(shortcut)
        actionZoom_All->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+0", nullptr));
#endif // QT_CONFIG(shortcut)
        actionLine->setText(QCoreApplication::translate("MainWindow", "Line", nullptr));
        actionRectangle->setText(QCoreApplication::translate("MainWindow", "Rectangle", nullptr));
        actionEllipse->setText(QCoreApplication::translate("MainWindow", "Ellipse", nullptr));
        actionClock->setText(QCoreApplication::translate("MainWindow", "Clock", nullptr));
        actionVariable->setText(QCoreApplication::translate("MainWindow", "Variable", nullptr));
        actionAttribute->setText(QCoreApplication::translate("MainWindow", "Attribute", nullptr));
        actionExpression->setText(QCoreApplication::translate("MainWindow", "Expression", nullptr));
        actionResource->setText(QCoreApplication::translate("MainWindow", "Resource", nullptr));
        actionQueue->setText(QCoreApplication::translate("MainWindow", "Queue", nullptr));
        actionStation->setText(QCoreApplication::translate("MainWindow", "Station", nullptr));
        actionConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        tabWidget_Model->setTabText(tabWidget_Model->indexOf(tabModelText), QCoreApplication::translate("MainWindow", "Text", nullptr));
        label_ModelGraphic->setText(QString());
        label_Zoom->setText(QCoreApplication::translate("MainWindow", "  Zoom:", nullptr));
        checkBox_ShowElements->setText(QCoreApplication::translate("MainWindow", "Show elements", nullptr));
        checkBox_ShowInternals->setText(QCoreApplication::translate("MainWindow", "Show internals", nullptr));
        checkBox_ShowLevels->setText(QCoreApplication::translate("MainWindow", "Show Levels", nullptr));
        checkBox_ShowRecursive->setText(QCoreApplication::translate("MainWindow", "Recursive", nullptr));
        pushButton_Export->setText(QCoreApplication::translate("MainWindow", "Export", nullptr));
        tabWidget_Model->setTabText(tabWidget_Model->indexOf(tabModelGraphic), QCoreApplication::translate("MainWindow", "Image", nullptr));
        labelMousePos->setText(QCoreApplication::translate("MainWindow", "<-,->", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Zoom:", nullptr));
        tabWidget_Model->setTabText(tabWidget_Model->indexOf(tabModelGraphicEdit), QCoreApplication::translate("MainWindow", "Graphic", nullptr));
        tabWidgetCentral->setTabText(tabWidgetCentral->indexOf(tabModel), QCoreApplication::translate("MainWindow", "Model", nullptr));
#if QT_CONFIG(tooltip)
        tabWidgetCentral->setTabToolTip(tabWidgetCentral->indexOf(tabModel), QCoreApplication::translate("MainWindow", "Model in Genesys Simulation Language", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_Breakpoint_Insert->setText(QCoreApplication::translate("MainWindow", "Insert", nullptr));
        pushButton_Breakpoint_Remove->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        tabWidget_Debug->setTabText(tabWidget_Debug->indexOf(tab_Debug_Breakpoints), QCoreApplication::translate("MainWindow", "Breakpoints", nullptr));
        tabWidget_Debug->setTabText(tabWidget_Debug->indexOf(tab_Debug_Variables), QCoreApplication::translate("MainWindow", "Variables", nullptr));
        tabWidget_Debug->setTabText(tabWidget_Debug->indexOf(tabDebug_Entities), QCoreApplication::translate("MainWindow", "Entities", nullptr));
        tabWidgetCentral->setTabText(tabWidgetCentral->indexOf(tabDebug), QCoreApplication::translate("MainWindow", "Debug", nullptr));
        tabWidget_Simulation->setTabText(tabWidget_Simulation->indexOf(tab_Simulation_Trace), QCoreApplication::translate("MainWindow", "Trace", nullptr));
        tabWidget_Simulation->setTabText(tabWidget_Simulation->indexOf(tab_Simulation_Event), QCoreApplication::translate("MainWindow", "Events", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Replication ", nullptr));
        label_ReplicationNum->setText(QCoreApplication::translate("MainWindow", "1/1", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", ":", nullptr));
        tabWidgetCentral->setTabText(tabWidgetCentral->indexOf(tabSimulation), QCoreApplication::translate("MainWindow", "Simulation", nullptr));
        tabWidget_Report->setTabText(tabWidget_Report->indexOf(tabReportTextr), QCoreApplication::translate("MainWindow", "Text", nullptr));
        tabWidget_Report->setTabText(tabWidget_Report->indexOf(tabReportGraphics), QCoreApplication::translate("MainWindow", "Graphics", nullptr));
        tabWidgetCentral->setTabText(tabWidgetCentral->indexOf(tabReport), QCoreApplication::translate("MainWindow", "Reports", nullptr));
        menuModel->setTitle(QCoreApplication::translate("MainWindow", "Model", nullptr));
        menuSimulation->setTitle(QCoreApplication::translate("MainWindow", "Simulation", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        menuZoom->setTitle(QCoreApplication::translate("MainWindow", "Zoom", nullptr));
        menuDraw->setTitle(QCoreApplication::translate("MainWindow", "Draw", nullptr));
        menuAnime->setTitle(QCoreApplication::translate("MainWindow", "Anime", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        toolBarModel->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
        dockWidgetConsole->setWindowTitle(QCoreApplication::translate("MainWindow", "Console", nullptr));
        dockWidgetPlugins->setWindowTitle(QCoreApplication::translate("MainWindow", "Plugins", nullptr));
        dockWidgetPropertyEditor->setWindowTitle(QCoreApplication::translate("MainWindow", "Property Editor", nullptr));
        toolBarGraphicalModel->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBarGraphicalModel", nullptr));
        toolBarEdit->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_2", nullptr));
        toolBarView->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_3", nullptr));
        toolBarSimulation->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_4", nullptr));
        toolBarAbout->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_5", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
