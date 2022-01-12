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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
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
    QAction *actionLoad;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionStart;
    QAction *actionStep;
    QAction *actionStop;
    QAction *actionPause;
    QAction *actionResume;
    QAction *actionClose;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *tabWidgetModel;
    QWidget *tabModel;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEditModel;
    QWidget *tabSimulation;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *textEditSimulation;
    QWidget *tabReport;
    QHBoxLayout *horizontalLayout_4;
    QTextEdit *textEditReports;
    QMenuBar *menubar;
    QMenu *menuModel;
    QMenu *menuSimulation;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QDockWidget *dockWidgetConsole;
    QWidget *dockWidgetContentsConsole;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEditConsole;
    QDockWidget *dockWidgetPlugins;
    QWidget *dockWidgetContentsPlugin;
    QHBoxLayout *horizontalLayout_5;
    QTreeWidget *treeWidgetPlugin;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(932, 624);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons2/resources/icons/pack2/ico/6.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setDockNestingEnabled(true);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/new document.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon1);
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/upload.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad->setIcon(icon2);
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
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/play.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionStart->setIcon(icon5);
        actionStep = new QAction(MainWindow);
        actionStep->setObjectName(QString::fromUtf8("actionStep"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/next track.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionStep->setIcon(icon6);
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/stop.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon7);
        actionPause = new QAction(MainWindow);
        actionPause->setObjectName(QString::fromUtf8("actionPause"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/pause.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionPause->setIcon(icon8);
        actionResume = new QAction(MainWindow);
        actionResume->setObjectName(QString::fromUtf8("actionResume"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/fast-forward.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionResume->setIcon(icon9);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionClose->setEnabled(false);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/close.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose->setIcon(icon10);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tabWidgetModel = new QTabWidget(centralwidget);
        tabWidgetModel->setObjectName(QString::fromUtf8("tabWidgetModel"));
        tabWidgetModel->setEnabled(false);
        tabModel = new QWidget();
        tabModel->setObjectName(QString::fromUtf8("tabModel"));
        horizontalLayout = new QHBoxLayout(tabModel);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        textEditModel = new QTextEdit(tabModel);
        textEditModel->setObjectName(QString::fromUtf8("textEditModel"));
        textEditModel->setFrameShape(QFrame::WinPanel);
        textEditModel->setFrameShadow(QFrame::Sunken);
        textEditModel->setLineWidth(1);
        textEditModel->setMidLineWidth(1);
        textEditModel->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        textEditModel->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        horizontalLayout->addWidget(textEditModel);

        tabWidgetModel->addTab(tabModel, QString());
        tabSimulation = new QWidget();
        tabSimulation->setObjectName(QString::fromUtf8("tabSimulation"));
        horizontalLayout_3 = new QHBoxLayout(tabSimulation);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        textEditSimulation = new QTextEdit(tabSimulation);
        textEditSimulation->setObjectName(QString::fromUtf8("textEditSimulation"));
        textEditSimulation->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_3->addWidget(textEditSimulation);

        tabWidgetModel->addTab(tabSimulation, QString());
        tabReport = new QWidget();
        tabReport->setObjectName(QString::fromUtf8("tabReport"));
        horizontalLayout_4 = new QHBoxLayout(tabReport);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        textEditReports = new QTextEdit(tabReport);
        textEditReports->setObjectName(QString::fromUtf8("textEditReports"));
        textEditReports->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_4->addWidget(textEditReports);

        tabWidgetModel->addTab(tabReport, QString());

        horizontalLayout_2->addWidget(tabWidgetModel);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 932, 24));
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
        dockWidgetConsole->setMinimumSize(QSize(100, 109));
        dockWidgetConsole->setAutoFillBackground(false);
        dockWidgetConsole->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetConsole->setAllowedAreas(Qt::BottomDockWidgetArea|Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContentsConsole = new QWidget();
        dockWidgetContentsConsole->setObjectName(QString::fromUtf8("dockWidgetContentsConsole"));
        verticalLayout = new QVBoxLayout(dockWidgetContentsConsole);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEditConsole = new QTextEdit(dockWidgetContentsConsole);
        textEditConsole->setObjectName(QString::fromUtf8("textEditConsole"));
        textEditConsole->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout->addWidget(textEditConsole);

        dockWidgetConsole->setWidget(dockWidgetContentsConsole);
        MainWindow->addDockWidget(Qt::BottomDockWidgetArea, dockWidgetConsole);
        dockWidgetPlugins = new QDockWidget(MainWindow);
        dockWidgetPlugins->setObjectName(QString::fromUtf8("dockWidgetPlugins"));
        sizePolicy.setHeightForWidth(dockWidgetPlugins->sizePolicy().hasHeightForWidth());
        dockWidgetPlugins->setSizePolicy(sizePolicy);
        dockWidgetPlugins->setMinimumSize(QSize(100, 109));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icons3/resources/icons/pack3/ico/component.ico"), QSize(), QIcon::Normal, QIcon::Off);
        dockWidgetPlugins->setWindowIcon(icon11);
        dockWidgetPlugins->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetPlugins->setAllowedAreas(Qt::BottomDockWidgetArea|Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContentsPlugin = new QWidget();
        dockWidgetContentsPlugin->setObjectName(QString::fromUtf8("dockWidgetContentsPlugin"));
        horizontalLayout_5 = new QHBoxLayout(dockWidgetContentsPlugin);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        treeWidgetPlugin = new QTreeWidget(dockWidgetContentsPlugin);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidgetPlugin->setHeaderItem(__qtreewidgetitem);
        treeWidgetPlugin->setObjectName(QString::fromUtf8("treeWidgetPlugin"));

        horizontalLayout_5->addWidget(treeWidgetPlugin);

        dockWidgetPlugins->setWidget(dockWidgetContentsPlugin);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, dockWidgetPlugins);
        QWidget::setTabOrder(textEditModel, textEditSimulation);
        QWidget::setTabOrder(textEditSimulation, textEditReports);
        QWidget::setTabOrder(textEditReports, tabWidgetModel);

        menubar->addAction(menuModel->menuAction());
        menubar->addAction(menuSimulation->menuAction());
        menuModel->addAction(actionNew);
        menuModel->addAction(actionLoad);
        menuModel->addAction(actionSave);
        menuModel->addAction(actionClose);
        menuModel->addSeparator();
        menuModel->addAction(actionExit);
        menuSimulation->addAction(actionStart);
        menuSimulation->addAction(actionStep);
        menuSimulation->addAction(actionStop);
        menuSimulation->addSeparator();
        menuSimulation->addAction(actionPause);
        menuSimulation->addAction(actionResume);

        retranslateUi(MainWindow);

        tabWidgetModel->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "GenESyS - Generic and Expasible System Smulator", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        actionLoad->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        actionStep->setText(QCoreApplication::translate("MainWindow", "Step", nullptr));
        actionStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        actionPause->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        actionResume->setText(QCoreApplication::translate("MainWindow", "Resume", nullptr));
        actionClose->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        textEditModel->setDocumentTitle(QCoreApplication::translate("MainWindow", "Model", nullptr));
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
