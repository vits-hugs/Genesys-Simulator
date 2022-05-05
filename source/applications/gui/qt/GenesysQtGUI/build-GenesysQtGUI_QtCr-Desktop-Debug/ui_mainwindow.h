/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <CodeEditor.h>
#include <ModelGraphicsView.h>
#include <PropertyEditor.h>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFrame>
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
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
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
    QAction *actionExpression;
    QAction *actionResource;
    QAction *actionQueue;
    QAction *actionStation;
    QAction *actionConnect;
    QAction *actionComponent_Breakpoint;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_7;
    QSplitter *splitter;
    ModelGraphicsView *graphicsView;
    QTabWidget *tabWidgetCentral;
    QWidget *tabCentralModel;
    QVBoxLayout *verticalLayout_12;
    QTabWidget *tabWidgetModel;
    QWidget *tabModelSimLanguage;
    QVBoxLayout *verticalLayout_15;
    CodeEditor *TextCodeEditor;
    QWidget *tabModelCpp;
    QVBoxLayout *verticalLayout_13;
    CodeEditor *plainTextEditCppCode;
    QWidget *tabModelDiagram;
    QVBoxLayout *verticalLayout_4;
    QFrame *frame;
    QVBoxLayout *verticalLayout_11;
    QScrollArea *scrollArea_Graphic;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_ModelGraphic;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox_ShowElements;
    QCheckBox *checkBox_ShowInternals;
    QCheckBox *checkBox_ShowLevels;
    QCheckBox *checkBox_ShowRecursive;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Export;
    QWidget *tabModelComponents;
    QVBoxLayout *verticalLayout_3;
    QTreeWidget *treeWidgetComponents;
    QWidget *tabModelDataDefinitions;
    QVBoxLayout *verticalLayout_2;
    QTreeWidget *treeWidgetDataDefnitions;
    QWidget *tabCentralSimulation;
    QVBoxLayout *verticalLayout_6;
    QTabWidget *tabWidgetSimulation;
    QWidget *tabDebugBreakpoints;
    QVBoxLayout *verticalLayout_8;
    QTableWidget *tableWidget_Breakpoints;
    QWidget *tabDebugVariables;
    QVBoxLayout *verticalLayout_14;
    QTableWidget *tableWidget_Variables;
    QWidget *tabDebugEntities;
    QVBoxLayout *verticalLayout_16;
    QTableWidget *tableWidget_Entities;
    QWidget *tabDebugTraces;
    QVBoxLayout *verticalLayout_17;
    QTextEdit *textEdit_Simulation;
    QWidget *tabDebugEvents;
    QVBoxLayout *verticalLayout_9;
    QTableWidget *tableWidget_Simulation_Event;
    QWidget *tabCentralWidget;
    QVBoxLayout *verticalLayout_10;
    QTabWidget *tabWidgetReports;
    QWidget *tabReportsReports;
    QVBoxLayout *verticalLayout_18;
    QTextEdit *textEdit_Reports;
    QWidget *TabReportsResults;
    QWidget *tabReportsPlots;
    QHBoxLayout *horizontalLayoutZoomReplication;
    QLabel *labelMousePos;
    QFrame *line;
    QLabel *label_3;
    QSlider *horizontalSlider_ZoomGraphical;
    QFrame *line_2;
    QLabel *label_2;
    QLabel *label_ReplicationNum;
    QLabel *label;
    QProgressBar *progressBarSimulation;
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
    PropertyEditor *treeViewPropertyEditor;
    QToolBar *toolBarGraphicalModel;
    QToolBar *toolBarEdit;
    QToolBar *toolBarView;
    QToolBar *toolBarSimulation;
    QToolBar *toolBarAbout;
    QToolBar *toolBarAnimation;

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
        actionStart->setEnabled(true);
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
        icon15.addFile(QString::fromUtf8(":/resources/ToolBar/_grade.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actionGrid->setIcon(icon15);
        actionSnap = new QAction(MainWindow);
        actionSnap->setObjectName(QString::fromUtf8("actionSnap"));
        actionSnap->setCheckable(true);
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/question.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionSnap->setIcon(icon16);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/undo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon17);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/redo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon18);
        actionFind = new QAction(MainWindow);
        actionFind->setObjectName(QString::fromUtf8("actionFind"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/find.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionFind->setIcon(icon19);
        actionReplace = new QAction(MainWindow);
        actionReplace->setObjectName(QString::fromUtf8("actionReplace"));
        actionReplace->setIcon(icon19);
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/cut.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon20);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/copy.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon21);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/paste.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon22);
        actionRule = new QAction(MainWindow);
        actionRule->setObjectName(QString::fromUtf8("actionRule"));
        actionRule->setCheckable(true);
        actionRule->setIcon(icon16);
        actionGuides = new QAction(MainWindow);
        actionGuides->setObjectName(QString::fromUtf8("actionGuides"));
        actionGuides->setCheckable(true);
        actionGuides->setIcon(icon16);
        actionZoom_In = new QAction(MainWindow);
        actionZoom_In->setObjectName(QString::fromUtf8("actionZoom_In"));
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/icons2/resources/icons/pack2/ico/83.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoom_In->setIcon(icon23);
        actionZoom_Out = new QAction(MainWindow);
        actionZoom_Out->setObjectName(QString::fromUtf8("actionZoom_Out"));
        QIcon icon24;
        icon24.addFile(QString::fromUtf8(":/icons2/resources/icons/pack2/ico/82.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoom_Out->setIcon(icon24);
        actionZoom_All = new QAction(MainWindow);
        actionZoom_All->setObjectName(QString::fromUtf8("actionZoom_All"));
        QIcon icon25;
        icon25.addFile(QString::fromUtf8(":/icons2/resources/icons/pack2/ico/84.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoom_All->setIcon(icon25);
        actionLine = new QAction(MainWindow);
        actionLine->setObjectName(QString::fromUtf8("actionLine"));
        QIcon icon26;
        icon26.addFile(QString::fromUtf8(":/resources/ToolBar/_linha.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actionLine->setIcon(icon26);
        actionRectangle = new QAction(MainWindow);
        actionRectangle->setObjectName(QString::fromUtf8("actionRectangle"));
        QIcon icon27;
        icon27.addFile(QString::fromUtf8(":/resources/ToolBar/_retang.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actionRectangle->setIcon(icon27);
        actionEllipse = new QAction(MainWindow);
        actionEllipse->setObjectName(QString::fromUtf8("actionEllipse"));
        QIcon icon28;
        icon28.addFile(QString::fromUtf8(":/resources/ToolBar/_elipse.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actionEllipse->setIcon(icon28);
        actionClock = new QAction(MainWindow);
        actionClock->setObjectName(QString::fromUtf8("actionClock"));
        QIcon icon29;
        icon29.addFile(QString::fromUtf8(":/resources/ToolBar/_relogio.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actionClock->setIcon(icon29);
        actionVariable = new QAction(MainWindow);
        actionVariable->setObjectName(QString::fromUtf8("actionVariable"));
        QIcon icon30;
        icon30.addFile(QString::fromUtf8(":/resources/ToolBar/_animvalor.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actionVariable->setIcon(icon30);
        actionExpression = new QAction(MainWindow);
        actionExpression->setObjectName(QString::fromUtf8("actionExpression"));
        actionExpression->setIcon(icon30);
        actionResource = new QAction(MainWindow);
        actionResource->setObjectName(QString::fromUtf8("actionResource"));
        actionResource->setIcon(icon16);
        actionQueue = new QAction(MainWindow);
        actionQueue->setObjectName(QString::fromUtf8("actionQueue"));
        QIcon icon31;
        icon31.addFile(QString::fromUtf8(":/resources/ToolBar/_animfila.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actionQueue->setIcon(icon31);
        actionStation = new QAction(MainWindow);
        actionStation->setObjectName(QString::fromUtf8("actionStation"));
        actionStation->setIcon(icon16);
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        QIcon icon32;
        icon32.addFile(QString::fromUtf8(":/mxgraph/resources/icons/pack4/iconsMxGraph/vertical.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect->setIcon(icon32);
        actionComponent_Breakpoint = new QAction(MainWindow);
        actionComponent_Breakpoint->setObjectName(QString::fromUtf8("actionComponent_Breakpoint"));
        QIcon icon33;
        icon33.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/abort.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionComponent_Breakpoint->setIcon(icon33);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_7 = new QVBoxLayout(centralwidget);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        graphicsView = new ModelGraphicsView(splitter);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(4);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setFrameShape(QFrame::Box);
        graphicsView->setFrameShadow(QFrame::Sunken);
        graphicsView->setLineWidth(2);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        splitter->addWidget(graphicsView);
        tabWidgetCentral = new QTabWidget(splitter);
        tabWidgetCentral->setObjectName(QString::fromUtf8("tabWidgetCentral"));
        QFont font;
        font.setPointSize(10);
        tabWidgetCentral->setFont(font);
        tabWidgetCentral->setTabPosition(QTabWidget::West);
        tabWidgetCentral->setTabShape(QTabWidget::Triangular);
        tabWidgetCentral->setTabBarAutoHide(true);
        tabCentralModel = new QWidget();
        tabCentralModel->setObjectName(QString::fromUtf8("tabCentralModel"));
        verticalLayout_12 = new QVBoxLayout(tabCentralModel);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        tabWidgetModel = new QTabWidget(tabCentralModel);
        tabWidgetModel->setObjectName(QString::fromUtf8("tabWidgetModel"));
        tabWidgetModel->setTabPosition(QTabWidget::North);
        tabWidgetModel->setTabShape(QTabWidget::Triangular);
        tabWidgetModel->setTabBarAutoHide(true);
        tabModelSimLanguage = new QWidget();
        tabModelSimLanguage->setObjectName(QString::fromUtf8("tabModelSimLanguage"));
        verticalLayout_15 = new QVBoxLayout(tabModelSimLanguage);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        TextCodeEditor = new CodeEditor(tabModelSimLanguage);
        TextCodeEditor->setObjectName(QString::fromUtf8("TextCodeEditor"));

        verticalLayout_15->addWidget(TextCodeEditor);

        tabWidgetModel->addTab(tabModelSimLanguage, QString());
        tabModelCpp = new QWidget();
        tabModelCpp->setObjectName(QString::fromUtf8("tabModelCpp"));
        verticalLayout_13 = new QVBoxLayout(tabModelCpp);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        plainTextEditCppCode = new CodeEditor(tabModelCpp);
        plainTextEditCppCode->setObjectName(QString::fromUtf8("plainTextEditCppCode"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Courier 10 Pitch"));
        font1.setPointSize(10);
        plainTextEditCppCode->setFont(font1);

        verticalLayout_13->addWidget(plainTextEditCppCode);

        tabWidgetModel->addTab(tabModelCpp, QString());
        tabModelDiagram = new QWidget();
        tabModelDiagram->setObjectName(QString::fromUtf8("tabModelDiagram"));
        verticalLayout_4 = new QVBoxLayout(tabModelDiagram);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        frame = new QFrame(tabModelDiagram);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_11 = new QVBoxLayout(frame);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        scrollArea_Graphic = new QScrollArea(frame);
        scrollArea_Graphic->setObjectName(QString::fromUtf8("scrollArea_Graphic"));
        scrollArea_Graphic->setAutoFillBackground(true);
        scrollArea_Graphic->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_Graphic->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 831, 139));
        verticalLayout_5 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_ModelGraphic = new QLabel(scrollAreaWidgetContents);
        label_ModelGraphic->setObjectName(QString::fromUtf8("label_ModelGraphic"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(3);
        sizePolicy1.setHeightForWidth(label_ModelGraphic->sizePolicy().hasHeightForWidth());
        label_ModelGraphic->setSizePolicy(sizePolicy1);
        label_ModelGraphic->setAutoFillBackground(true);
        label_ModelGraphic->setFrameShadow(QFrame::Plain);
        label_ModelGraphic->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_ModelGraphic);

        scrollArea_Graphic->setWidget(scrollAreaWidgetContents);

        verticalLayout_11->addWidget(scrollArea_Graphic);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        checkBox_ShowElements = new QCheckBox(frame);
        checkBox_ShowElements->setObjectName(QString::fromUtf8("checkBox_ShowElements"));
        checkBox_ShowElements->setChecked(true);

        horizontalLayout->addWidget(checkBox_ShowElements);

        checkBox_ShowInternals = new QCheckBox(frame);
        checkBox_ShowInternals->setObjectName(QString::fromUtf8("checkBox_ShowInternals"));
        checkBox_ShowInternals->setChecked(true);

        horizontalLayout->addWidget(checkBox_ShowInternals);

        checkBox_ShowLevels = new QCheckBox(frame);
        checkBox_ShowLevels->setObjectName(QString::fromUtf8("checkBox_ShowLevels"));
        checkBox_ShowLevels->setChecked(true);

        horizontalLayout->addWidget(checkBox_ShowLevels);

        checkBox_ShowRecursive = new QCheckBox(frame);
        checkBox_ShowRecursive->setObjectName(QString::fromUtf8("checkBox_ShowRecursive"));
        checkBox_ShowRecursive->setChecked(true);

        horizontalLayout->addWidget(checkBox_ShowRecursive);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_Export = new QPushButton(frame);
        pushButton_Export->setObjectName(QString::fromUtf8("pushButton_Export"));

        horizontalLayout->addWidget(pushButton_Export);


        verticalLayout_11->addLayout(horizontalLayout);


        verticalLayout_4->addWidget(frame);

        tabWidgetModel->addTab(tabModelDiagram, QString());
        tabModelComponents = new QWidget();
        tabModelComponents->setObjectName(QString::fromUtf8("tabModelComponents"));
        verticalLayout_3 = new QVBoxLayout(tabModelComponents);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        treeWidgetComponents = new QTreeWidget(tabModelComponents);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(3, QString::fromUtf8("4"));
        __qtreewidgetitem->setText(2, QString::fromUtf8("3"));
        __qtreewidgetitem->setText(1, QString::fromUtf8("2"));
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidgetComponents->setHeaderItem(__qtreewidgetitem);
        treeWidgetComponents->setObjectName(QString::fromUtf8("treeWidgetComponents"));
        treeWidgetComponents->setAutoScrollMargin(8);
        treeWidgetComponents->setRootIsDecorated(true);
        treeWidgetComponents->setSortingEnabled(true);
        treeWidgetComponents->setColumnCount(4);

        verticalLayout_3->addWidget(treeWidgetComponents);

        tabWidgetModel->addTab(tabModelComponents, QString());
        tabModelDataDefinitions = new QWidget();
        tabModelDataDefinitions->setObjectName(QString::fromUtf8("tabModelDataDefinitions"));
        verticalLayout_2 = new QVBoxLayout(tabModelDataDefinitions);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        treeWidgetDataDefnitions = new QTreeWidget(tabModelDataDefinitions);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(3, QString::fromUtf8("4"));
        __qtreewidgetitem1->setText(2, QString::fromUtf8("3"));
        __qtreewidgetitem1->setText(1, QString::fromUtf8("2"));
        __qtreewidgetitem1->setText(0, QString::fromUtf8("1"));
        treeWidgetDataDefnitions->setHeaderItem(__qtreewidgetitem1);
        treeWidgetDataDefnitions->setObjectName(QString::fromUtf8("treeWidgetDataDefnitions"));
        treeWidgetDataDefnitions->setAutoScrollMargin(8);
        treeWidgetDataDefnitions->setRootIsDecorated(true);
        treeWidgetDataDefnitions->setSortingEnabled(true);
        treeWidgetDataDefnitions->setColumnCount(4);

        verticalLayout_2->addWidget(treeWidgetDataDefnitions);

        tabWidgetModel->addTab(tabModelDataDefinitions, QString());

        verticalLayout_12->addWidget(tabWidgetModel);

        tabWidgetCentral->addTab(tabCentralModel, QString());
        tabCentralSimulation = new QWidget();
        tabCentralSimulation->setObjectName(QString::fromUtf8("tabCentralSimulation"));
        verticalLayout_6 = new QVBoxLayout(tabCentralSimulation);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        tabWidgetSimulation = new QTabWidget(tabCentralSimulation);
        tabWidgetSimulation->setObjectName(QString::fromUtf8("tabWidgetSimulation"));
        tabWidgetSimulation->setTabPosition(QTabWidget::North);
        tabWidgetSimulation->setTabShape(QTabWidget::Triangular);
        tabWidgetSimulation->setTabBarAutoHide(true);
        tabDebugBreakpoints = new QWidget();
        tabDebugBreakpoints->setObjectName(QString::fromUtf8("tabDebugBreakpoints"));
        verticalLayout_8 = new QVBoxLayout(tabDebugBreakpoints);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        tableWidget_Breakpoints = new QTableWidget(tabDebugBreakpoints);
        if (tableWidget_Breakpoints->columnCount() < 3)
            tableWidget_Breakpoints->setColumnCount(3);
        tableWidget_Breakpoints->setObjectName(QString::fromUtf8("tableWidget_Breakpoints"));
        tableWidget_Breakpoints->setEnabled(false);
        tableWidget_Breakpoints->setColumnCount(3);
        tableWidget_Breakpoints->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));

        verticalLayout_8->addWidget(tableWidget_Breakpoints);

        tabWidgetSimulation->addTab(tabDebugBreakpoints, QString());
        tabDebugVariables = new QWidget();
        tabDebugVariables->setObjectName(QString::fromUtf8("tabDebugVariables"));
        verticalLayout_14 = new QVBoxLayout(tabDebugVariables);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        tableWidget_Variables = new QTableWidget(tabDebugVariables);
        if (tableWidget_Variables->columnCount() < 3)
            tableWidget_Variables->setColumnCount(3);
        tableWidget_Variables->setObjectName(QString::fromUtf8("tableWidget_Variables"));
        tableWidget_Variables->setEnabled(false);
        tableWidget_Variables->setColumnCount(3);
        tableWidget_Variables->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));

        verticalLayout_14->addWidget(tableWidget_Variables);

        tabWidgetSimulation->addTab(tabDebugVariables, QString());
        tabDebugEntities = new QWidget();
        tabDebugEntities->setObjectName(QString::fromUtf8("tabDebugEntities"));
        verticalLayout_16 = new QVBoxLayout(tabDebugEntities);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        tableWidget_Entities = new QTableWidget(tabDebugEntities);
        if (tableWidget_Entities->columnCount() < 3)
            tableWidget_Entities->setColumnCount(3);
        tableWidget_Entities->setObjectName(QString::fromUtf8("tableWidget_Entities"));
        tableWidget_Entities->setEnabled(false);
        tableWidget_Entities->setColumnCount(3);
        tableWidget_Entities->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));

        verticalLayout_16->addWidget(tableWidget_Entities);

        tabWidgetSimulation->addTab(tabDebugEntities, QString());
        tabDebugTraces = new QWidget();
        tabDebugTraces->setObjectName(QString::fromUtf8("tabDebugTraces"));
        verticalLayout_17 = new QVBoxLayout(tabDebugTraces);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        textEdit_Simulation = new QTextEdit(tabDebugTraces);
        textEdit_Simulation->setObjectName(QString::fromUtf8("textEdit_Simulation"));
        textEdit_Simulation->setFont(font);
        textEdit_Simulation->setLineWrapMode(QTextEdit::NoWrap);
        textEdit_Simulation->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout_17->addWidget(textEdit_Simulation);

        tabWidgetSimulation->addTab(tabDebugTraces, QString());
        tabDebugEvents = new QWidget();
        tabDebugEvents->setObjectName(QString::fromUtf8("tabDebugEvents"));
        verticalLayout_9 = new QVBoxLayout(tabDebugEvents);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        tableWidget_Simulation_Event = new QTableWidget(tabDebugEvents);
        if (tableWidget_Simulation_Event->columnCount() < 3)
            tableWidget_Simulation_Event->setColumnCount(3);
        tableWidget_Simulation_Event->setObjectName(QString::fromUtf8("tableWidget_Simulation_Event"));
        tableWidget_Simulation_Event->setFont(font);
        tableWidget_Simulation_Event->setWordWrap(false);
        tableWidget_Simulation_Event->setRowCount(0);
        tableWidget_Simulation_Event->setColumnCount(3);

        verticalLayout_9->addWidget(tableWidget_Simulation_Event);

        tabWidgetSimulation->addTab(tabDebugEvents, QString());

        verticalLayout_6->addWidget(tabWidgetSimulation);

        tabWidgetCentral->addTab(tabCentralSimulation, QString());
        tabCentralWidget = new QWidget();
        tabCentralWidget->setObjectName(QString::fromUtf8("tabCentralWidget"));
        verticalLayout_10 = new QVBoxLayout(tabCentralWidget);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        tabWidgetReports = new QTabWidget(tabCentralWidget);
        tabWidgetReports->setObjectName(QString::fromUtf8("tabWidgetReports"));
        tabWidgetReports->setTabShape(QTabWidget::Triangular);
        tabWidgetReports->setTabBarAutoHide(true);
        tabReportsReports = new QWidget();
        tabReportsReports->setObjectName(QString::fromUtf8("tabReportsReports"));
        verticalLayout_18 = new QVBoxLayout(tabReportsReports);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        textEdit_Reports = new QTextEdit(tabReportsReports);
        textEdit_Reports->setObjectName(QString::fromUtf8("textEdit_Reports"));
        textEdit_Reports->setFont(font1);
        textEdit_Reports->setLineWrapMode(QTextEdit::NoWrap);
        textEdit_Reports->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout_18->addWidget(textEdit_Reports);

        tabWidgetReports->addTab(tabReportsReports, QString());
        TabReportsResults = new QWidget();
        TabReportsResults->setObjectName(QString::fromUtf8("TabReportsResults"));
        tabWidgetReports->addTab(TabReportsResults, QString());
        tabReportsPlots = new QWidget();
        tabReportsPlots->setObjectName(QString::fromUtf8("tabReportsPlots"));
        tabWidgetReports->addTab(tabReportsPlots, QString());

        verticalLayout_10->addWidget(tabWidgetReports);

        tabWidgetCentral->addTab(tabCentralWidget, QString());
        splitter->addWidget(tabWidgetCentral);

        verticalLayout_7->addWidget(splitter);

        horizontalLayoutZoomReplication = new QHBoxLayout();
        horizontalLayoutZoomReplication->setObjectName(QString::fromUtf8("horizontalLayoutZoomReplication"));
        labelMousePos = new QLabel(centralwidget);
        labelMousePos->setObjectName(QString::fromUtf8("labelMousePos"));
        QFont font2;
        font2.setPointSize(9);
        labelMousePos->setFont(font2);

        horizontalLayoutZoomReplication->addWidget(labelMousePos);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayoutZoomReplication->addWidget(line);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);

        horizontalLayoutZoomReplication->addWidget(label_3);

        horizontalSlider_ZoomGraphical = new QSlider(centralwidget);
        horizontalSlider_ZoomGraphical->setObjectName(QString::fromUtf8("horizontalSlider_ZoomGraphical"));
        horizontalSlider_ZoomGraphical->setMinimum(1);
        horizontalSlider_ZoomGraphical->setMaximum(1000);
        horizontalSlider_ZoomGraphical->setSingleStep(1);
        horizontalSlider_ZoomGraphical->setValue(500);
        horizontalSlider_ZoomGraphical->setOrientation(Qt::Horizontal);

        horizontalLayoutZoomReplication->addWidget(horizontalSlider_ZoomGraphical);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayoutZoomReplication->addWidget(line_2);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font2);

        horizontalLayoutZoomReplication->addWidget(label_2);

        label_ReplicationNum = new QLabel(centralwidget);
        label_ReplicationNum->setObjectName(QString::fromUtf8("label_ReplicationNum"));
        label_ReplicationNum->setFont(font2);

        horizontalLayoutZoomReplication->addWidget(label_ReplicationNum);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayoutZoomReplication->addWidget(label);

        progressBarSimulation = new QProgressBar(centralwidget);
        progressBarSimulation->setObjectName(QString::fromUtf8("progressBarSimulation"));
        progressBarSimulation->setFont(font2);
        progressBarSimulation->setValue(0);

        horizontalLayoutZoomReplication->addWidget(progressBarSimulation);


        verticalLayout_7->addLayout(horizontalLayoutZoomReplication);

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
        QIcon icon34;
        icon34.addFile(QString::fromUtf8(":/icons4/resources/icons/pack4/console.png"), QSize(), QIcon::Normal, QIcon::Off);
        dockWidgetConsole->setWindowIcon(icon34);
        dockWidgetConsole->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetConsole->setAllowedAreas(Qt::BottomDockWidgetArea|Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContentsConsole = new QWidget();
        dockWidgetContentsConsole->setObjectName(QString::fromUtf8("dockWidgetContentsConsole"));
        verticalLayout = new QVBoxLayout(dockWidgetContentsConsole);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEdit_Console = new QTextEdit(dockWidgetContentsConsole);
        textEdit_Console->setObjectName(QString::fromUtf8("textEdit_Console"));
        QFont font3;
        font3.setPointSize(8);
        textEdit_Console->setFont(font3);
        textEdit_Console->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout->addWidget(textEdit_Console);

        dockWidgetConsole->setWidget(dockWidgetContentsConsole);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, dockWidgetConsole);
        dockWidgetPlugins = new QDockWidget(MainWindow);
        dockWidgetPlugins->setObjectName(QString::fromUtf8("dockWidgetPlugins"));
        QIcon icon35;
        icon35.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/component.ico"), QSize(), QIcon::Normal, QIcon::Off);
        dockWidgetPlugins->setWindowIcon(icon35);
        dockWidgetPlugins->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetPlugins->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContentsPlugin = new QWidget();
        dockWidgetContentsPlugin->setObjectName(QString::fromUtf8("dockWidgetContentsPlugin"));
        horizontalLayout_2 = new QHBoxLayout(dockWidgetContentsPlugin);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        treeWidget_Plugins = new QTreeWidget(dockWidgetContentsPlugin);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem();
        __qtreewidgetitem2->setText(0, QString::fromUtf8("1"));
        treeWidget_Plugins->setHeaderItem(__qtreewidgetitem2);
        treeWidget_Plugins->setObjectName(QString::fromUtf8("treeWidget_Plugins"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(treeWidget_Plugins->sizePolicy().hasHeightForWidth());
        treeWidget_Plugins->setSizePolicy(sizePolicy2);
        treeWidget_Plugins->setToolTipDuration(-1);
        treeWidget_Plugins->setDragEnabled(true);
        treeWidget_Plugins->setDragDropMode(QAbstractItemView::DragDrop);
        treeWidget_Plugins->setDefaultDropAction(Qt::CopyAction);
        treeWidget_Plugins->setAlternatingRowColors(true);
        treeWidget_Plugins->setAutoExpandDelay(8);
        treeWidget_Plugins->setIndentation(7);
        treeWidget_Plugins->setSortingEnabled(true);
        treeWidget_Plugins->setAnimated(true);
        treeWidget_Plugins->setWordWrap(true);
        treeWidget_Plugins->header()->setVisible(false);

        horizontalLayout_2->addWidget(treeWidget_Plugins);

        dockWidgetPlugins->setWidget(dockWidgetContentsPlugin);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, dockWidgetPlugins);
        dockWidgetPropertyEditor = new QDockWidget(MainWindow);
        dockWidgetPropertyEditor->setObjectName(QString::fromUtf8("dockWidgetPropertyEditor"));
        QIcon icon36;
        icon36.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/table.ico"), QSize(), QIcon::Normal, QIcon::Off);
        dockWidgetPropertyEditor->setWindowIcon(icon36);
        dockWidgetPropertyEditor->setFloating(false);
        dockWidgetPropertyEditor->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetPropertyEditor->setAllowedAreas(Qt::BottomDockWidgetArea|Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        horizontalLayout_4 = new QHBoxLayout(dockWidgetContents);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        treeViewPropertyEditor = new PropertyEditor(dockWidgetContents);
        treeViewPropertyEditor->setObjectName(QString::fromUtf8("treeViewPropertyEditor"));
        sizePolicy2.setHeightForWidth(treeViewPropertyEditor->sizePolicy().hasHeightForWidth());
        treeViewPropertyEditor->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(treeViewPropertyEditor);

        dockWidgetPropertyEditor->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, dockWidgetPropertyEditor);
        toolBarGraphicalModel = new QToolBar(MainWindow);
        toolBarGraphicalModel->setObjectName(QString::fromUtf8("toolBarGraphicalModel"));
        toolBarGraphicalModel->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolBarGraphicalModel->setFloatable(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBarGraphicalModel);
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
        toolBarAnimation = new QToolBar(MainWindow);
        toolBarAnimation->setObjectName(QString::fromUtf8("toolBarAnimation"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBarAnimation);

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
        toolBarGraphicalModel->addAction(actionConnect);
        toolBarGraphicalModel->addAction(actionComponent_Breakpoint);
        toolBarGraphicalModel->addSeparator();
        toolBarGraphicalModel->addAction(actionGrid);
        toolBarGraphicalModel->addAction(actionRule);
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
        toolBarAnimation->addAction(actionLine);
        toolBarAnimation->addAction(actionEllipse);
        toolBarAnimation->addAction(actionRectangle);
        toolBarAnimation->addSeparator();
        toolBarAnimation->addAction(actionClock);
        toolBarAnimation->addAction(actionVariable);
        toolBarAnimation->addAction(actionExpression);

        retranslateUi(MainWindow);

        tabWidgetCentral->setCurrentIndex(0);
        tabWidgetModel->setCurrentIndex(4);
        tabWidgetSimulation->setCurrentIndex(0);
        tabWidgetReports->setCurrentIndex(1);


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
        actionExpression->setText(QCoreApplication::translate("MainWindow", "Expression", nullptr));
        actionResource->setText(QCoreApplication::translate("MainWindow", "Resource", nullptr));
        actionQueue->setText(QCoreApplication::translate("MainWindow", "Queue", nullptr));
        actionStation->setText(QCoreApplication::translate("MainWindow", "Station", nullptr));
        actionConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        actionComponent_Breakpoint->setText(QCoreApplication::translate("MainWindow", "Component Breakpoint", nullptr));
#if QT_CONFIG(tooltip)
        actionComponent_Breakpoint->setToolTip(QCoreApplication::translate("MainWindow", "Component Breakpoint", nullptr));
#endif // QT_CONFIG(tooltip)
        tabWidgetModel->setTabText(tabWidgetModel->indexOf(tabModelSimLanguage), QCoreApplication::translate("MainWindow", "SimulLang", nullptr));
        tabWidgetModel->setTabText(tabWidgetModel->indexOf(tabModelCpp), QCoreApplication::translate("MainWindow", "C++", nullptr));
        label_ModelGraphic->setText(QString());
        checkBox_ShowElements->setText(QCoreApplication::translate("MainWindow", "Show elements", nullptr));
        checkBox_ShowInternals->setText(QCoreApplication::translate("MainWindow", "Show internals", nullptr));
        checkBox_ShowLevels->setText(QCoreApplication::translate("MainWindow", "Show Levels", nullptr));
        checkBox_ShowRecursive->setText(QCoreApplication::translate("MainWindow", "Recursive", nullptr));
        pushButton_Export->setText(QCoreApplication::translate("MainWindow", "Export", nullptr));
        tabWidgetModel->setTabText(tabWidgetModel->indexOf(tabModelDiagram), QCoreApplication::translate("MainWindow", "Diagram", nullptr));
        tabWidgetModel->setTabText(tabWidgetModel->indexOf(tabModelComponents), QCoreApplication::translate("MainWindow", "Components", nullptr));
        tabWidgetModel->setTabText(tabWidgetModel->indexOf(tabModelDataDefinitions), QCoreApplication::translate("MainWindow", "DataDefinitions", nullptr));
        tabWidgetCentral->setTabText(tabWidgetCentral->indexOf(tabCentralModel), QCoreApplication::translate("MainWindow", "Model", nullptr));
        tabWidgetSimulation->setTabText(tabWidgetSimulation->indexOf(tabDebugBreakpoints), QCoreApplication::translate("MainWindow", "Breakpoints", nullptr));
        tabWidgetSimulation->setTabText(tabWidgetSimulation->indexOf(tabDebugVariables), QCoreApplication::translate("MainWindow", "Variables", nullptr));
        tabWidgetSimulation->setTabText(tabWidgetSimulation->indexOf(tabDebugEntities), QCoreApplication::translate("MainWindow", "Entities", nullptr));
        tabWidgetSimulation->setTabText(tabWidgetSimulation->indexOf(tabDebugTraces), QCoreApplication::translate("MainWindow", "Traces", nullptr));
        tabWidgetSimulation->setTabText(tabWidgetSimulation->indexOf(tabDebugEvents), QCoreApplication::translate("MainWindow", "Events", nullptr));
        tabWidgetCentral->setTabText(tabWidgetCentral->indexOf(tabCentralSimulation), QCoreApplication::translate("MainWindow", "Simulation", nullptr));
        tabWidgetReports->setTabText(tabWidgetReports->indexOf(tabReportsReports), QCoreApplication::translate("MainWindow", "Reports", nullptr));
        tabWidgetReports->setTabText(tabWidgetReports->indexOf(TabReportsResults), QCoreApplication::translate("MainWindow", "Results", nullptr));
        tabWidgetReports->setTabText(tabWidgetReports->indexOf(tabReportsPlots), QCoreApplication::translate("MainWindow", "Plots", nullptr));
        tabWidgetCentral->setTabText(tabWidgetCentral->indexOf(tabCentralWidget), QCoreApplication::translate("MainWindow", "Results", nullptr));
        labelMousePos->setText(QCoreApplication::translate("MainWindow", "<-,->", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Zoom:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Replication ", nullptr));
        label_ReplicationNum->setText(QCoreApplication::translate("MainWindow", "1/1", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", ":", nullptr));
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
        textEdit_Console->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu LGC Sans'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Console</p></body></html>", nullptr));
        dockWidgetPlugins->setWindowTitle(QCoreApplication::translate("MainWindow", "Plugins", nullptr));
        dockWidgetPropertyEditor->setWindowTitle(QCoreApplication::translate("MainWindow", "Property Editor", nullptr));
        toolBarGraphicalModel->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBarGraphicalModel", nullptr));
        toolBarEdit->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_2", nullptr));
        toolBarView->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_3", nullptr));
        toolBarSimulation->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_4", nullptr));
        toolBarAbout->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_5", nullptr));
        toolBarAnimation->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
