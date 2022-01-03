#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../dialogs/dialogabout.h"
#include "../dialogs/dialogmodelinformation.h"
#include "Traits.h"
#include <Qt>
#include <QFileDialog>
#include <QMessageBox>
#include <QStandardItem>
#include <QListWidget>
#include <QListWidgetItem>
#include <QString>

// get path 
#include <string>
#include <limits.h>
#include <unistd.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->actionAbout, SIGNAL(triggered(bool)), this, SLOT(on_actionAbout_triggered()));

    // action menu on plugin list 
    auto actView = new QAction("View", this);
    // auto actDelete = new QAction("Delete", this);
    // you can set up slot connections here or in designer
    connect(actView, SIGNAL(triggered()), this, SLOT(viewItem()));
    //connect(actDelete, SIGNAL(triggered()), this, SLOT(eraseItem()));
    ui->listWidget_Plugins->setContextMenuPolicy(Qt::ActionsContextMenu);
    ui->listWidget_Plugins->addActions({actView}); //, actDelete});
    //--------------------------
    // models
    //ui->tabWidgetModels->clear(); // no models openned

    //*****************************************************************
    this->simulator = new Simulator();
    TraceManager* tm = simulator->getTracer();
    tm->setTraceLevel(Traits<GenesysApplication_if>::traceLevel);
    tm->addTraceHandler<MainWindow>(this, &MainWindow::_traceHandler);
    tm->addTraceReportHandler<MainWindow>(this, &MainWindow::_traceReportHandler);
    tm->addTraceSimulationHandler<MainWindow>(this, &MainWindow::_traceSimulationHandler);
    tm->addTraceErrorHandler<MainWindow>(this, &MainWindow::_traceErrorHandler);
    _simulationInsertPlugins();
    // refresh UI
    _refreshActions();
    _refreshTabWidgetModel();
    QString title = QString::fromStdString("Generic and Expansible System Simulator (" + std::to_string(this->simulator->getVersionNumber()) + ")");
    this->setWindowTitle(title);
}

MainWindow::~MainWindow() {
    delete ui;
}

//*******************************************************************
// SIMULATOR START
//*******************************************************************

void MainWindow::_insertPluginUI(Plugin* plugin) {
    if (plugin != nullptr) {
        if (plugin->isIsValidPlugin()) {
            QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(plugin->getPluginInfo()->getPluginTypename()));
            std::string plugtextAdds = "";
            if (plugin->getPluginInfo()->isComponent()) {
                plugtextAdds += ",Component";
                //item->setBackgroundColor(Qt::white);
                //item->set
                item->setIcon(QIcon(":/resources/icons/pack3/png/24x24/Component.png"));
            } else {
                plugtextAdds += ",Element";
                //item->setBackgroundColor(Qt::lightGray);
                item->setIcon(QIcon(":/resources/icons/pack3/png/24x24/Calendar.png"));
                //item->setFont(QFont::Style::StyleItalic);
            }
            if (plugin->getPluginInfo()->isSink()) {
                plugtextAdds += ",Sink";
                item->setIcon(QIcon(":/resources/icons/pack3/png/24x24/LoadInv.png"));
            }
            if (plugin->getPluginInfo()->isSource()) {
                plugtextAdds += ",Source";
                item->setIcon(QIcon(":/resources/icons/pack3/png/24x24/Load.png"));
            }
            if (plugin->getPluginInfo()->isReceiveTransfer()) {
                plugtextAdds += ",ReceiveTransfer";
                item->setIcon(QIcon(":/resources/icons/pack3/png/24x24/Load.png"));
            }
            if (plugin->getPluginInfo()->isSendTransfer()) {
                plugtextAdds += ",SendTransfer";
                item->setIcon(QIcon(":/resources/icons/pack3/png/24x24/LoadInv.png"));
            }
            plugtextAdds += "\n" + plugin->getPluginInfo()->getObservation(); //getDescriptionHelp();
            plugtextAdds = plugtextAdds.erase(0, 1);
            item->setToolTip(QString::fromStdString(plugtextAdds));
            item->setStatusTip(QString::fromStdString(plugtextAdds));
            ui->listWidget_Plugins->addItem(item);
        }
    }
}

void MainWindow::__simulationInsert_FAKE_Plugins() {
    //Util::TraceLevel tl = simulator->getTracer()->traceLevel();
    //simulator->getTracer()->setTraceLevel(Util::TraceLevel::debugOnly);
    PluginManager* plm = simulator->getPlugins();

    _insertPluginUI(plm->insert("create.so"));
    _insertPluginUI(plm->insert("dispose.so"));
    _insertPluginUI(plm->insert("decide.so"));
    _insertPluginUI(plm->insert("batch.so"));
    _insertPluginUI(plm->insert("separate.so"));
    _insertPluginUI(plm->insert("assign.so"));
    _insertPluginUI(plm->insert("record.so"));
    _insertPluginUI(plm->insert("submodel.so"));
    //_insertPluginUI(plm->insert("entitytype.so"));
    _insertPluginUI(plm->insert("entitygroup.so"));
    //_insertPluginUI(plm->insert("attribute.so"));
    //_insertPluginUI(plm->insert("counter.so"));
    _insertPluginUI(plm->insert("queue.so"));
    _insertPluginUI(plm->insert("set.so"));
    _insertPluginUI(plm->insert("resource.so"));
    _insertPluginUI(plm->insert("variable.so"));
    _insertPluginUI(plm->insert("schedule.so"));
    _insertPluginUI(plm->insert("entitygroup.so"));
    // arena advanced process
    _insertPluginUI(plm->insert("delay.so"));
    _insertPluginUI(plm->insert("dropoff.so"));
    _insertPluginUI(plm->insert("hold.so"));
    _insertPluginUI(plm->insert("match.so"));
    _insertPluginUI(plm->insert("pickup.so"));
    _insertPluginUI(plm->insert("read.so"));
    _insertPluginUI(plm->insert("write.so"));
    _insertPluginUI(plm->insert("release.so"));
    _insertPluginUI(plm->insert("remove.so"));
    _insertPluginUI(plm->insert("seize.so"));
    _insertPluginUI(plm->insert("search.so"));
    _insertPluginUI(plm->insert("signal.so"));
    _insertPluginUI(plm->insert("store.so"));
    _insertPluginUI(plm->insert("unstore.so"));
    _insertPluginUI(plm->insert("expression.so"));
    _insertPluginUI(plm->insert("failure.so"));
    _insertPluginUI(plm->insert("file.so"));
    _insertPluginUI(plm->insert("statisticscollector.so"));
    _insertPluginUI(plm->insert("storage.so"));
    // arena transfer station
    _insertPluginUI(plm->insert("enter.so"));
    _insertPluginUI(plm->insert("leave.so"));
    _insertPluginUI(plm->insert("pickstation.so"));
    _insertPluginUI(plm->insert("route.so"));
    _insertPluginUI(plm->insert("sequence.so"));
    _insertPluginUI(plm->insert("station.so"));
    // arena transfer conveyour
    _insertPluginUI(plm->insert("access.so"));
    _insertPluginUI(plm->insert("exit.so"));
    _insertPluginUI(plm->insert("start.so"));
    _insertPluginUI(plm->insert("stop.so"));
    _insertPluginUI(plm->insert("conveyour.so"));
    _insertPluginUI(plm->insert("segment.so"));
    // arena transfer transport
    _insertPluginUI(plm->insert("alocate.so"));
    _insertPluginUI(plm->insert("free.so"));
    _insertPluginUI(plm->insert("halt.so"));
    _insertPluginUI(plm->insert("move.so"));
    _insertPluginUI(plm->insert("request.so"));
    _insertPluginUI(plm->insert("transporter.so"));
    _insertPluginUI(plm->insert("distance.so"));
    _insertPluginUI(plm->insert("network.so"));
    _insertPluginUI(plm->insert("networklink.so"));
    // others
    _insertPluginUI(plm->insert("dummy.so"));
    _insertPluginUI(plm->insert("lsode.so"));
    _insertPluginUI(plm->insert("biochemical.so"));
    _insertPluginUI(plm->insert("markovchain.so"));
    _insertPluginUI(plm->insert("cellularautomata.so"));
    _insertPluginUI(plm->insert("cppforgenesys.so"));
    //simulator->getTracer()->setTraceLevel(tl);
}

void MainWindow::_simulationInsertPlugins() {
    // TODO: Not implemented yet
    __simulationInsert_FAKE_Plugins();
}

void MainWindow::_traceHandler(TraceEvent e) {
    // TODO: -- use e.getTracelevel() to set text style (color, bold, etc)
    if (e.getTracelevel() == Util::TraceLevel::L1_errorFatal)
        ui->textEdit_Console->setTextColor(QColor::fromRgb(255, 0, 0));
    else if (e.getTracelevel() == Util::TraceLevel::L3_errorRecover)
        ui->textEdit_Console->setTextColor(QColor::fromRgb(128, 0, 0));
    else {
        unsigned short grayVal = 5 * (static_cast<unsigned int> (e.getTracelevel()));
        ui->textEdit_Console->setTextColor(QColor::fromRgb(grayVal, grayVal, grayVal));
    }
    ui->textEdit_Console->append(QString::fromStdString(e.getText()));
}

void MainWindow::_traceErrorHandler(TraceErrorEvent e) {
    ui->textEdit_Console->setTextColor(QColor::fromRgb(255, 0, 0));
    ui->textEdit_Console->append(QString::fromStdString(e.getText()));
}

void MainWindow::_traceReportHandler(TraceEvent e) {
    ui->textEdit_Console->setTextColor(QColor::fromRgb(0, 0, 128));
    ui->textEdit_Console->append(QString::fromStdString(e.getText()));
}

void MainWindow::_traceSimulationHandler(TraceSimulationEvent e) {
    if (e.getTracelevel() == Util::TraceLevel::L1_errorFatal)
        ui->textEdit_Console->setTextColor(QColor::fromRgb(255, 64, 0));
    else if (e.getTracelevel() == Util::TraceLevel::L3_errorRecover)
        ui->textEdit_Console->setTextColor(QColor::fromRgb(128, 64, 0));
    else {
        unsigned short grayVal = 5 * (static_cast<unsigned int> (e.getTracelevel()));
        ui->textEdit_Console->setTextColor(QColor::fromRgb(grayVal, 128, grayVal));
    }
    ui->textEdit_Console->append(QString::fromStdString(e.getText()));
}
// default Event Handlers

void MainWindow::_onSimulationStartHandler(SimulationEvent* re) {

}

void MainWindow::_onReplicationStartHandler(SimulationEvent* re) {

}

void MainWindow::_onProcessEventHandler(SimulationEvent* re) {

}

void MainWindow::_onReplicationEndHandler(SimulationEvent* re) {

}

void MainWindow::_onSimulationEndHandler(SimulationEvent* re) {

}

void MainWindow::_onEntityRemoveHandler(SimulationEvent* re) {

}

void MainWindow::_refreshActions() {
    bool thereIsAtLeastOneModelOpenned = simulator->getModels()->size() > 0;
    ui->actionClose->setEnabled(thereIsAtLeastOneModelOpenned);
    ui->actionSave->setEnabled(thereIsAtLeastOneModelOpenned);
    ui->actionSave_as->setEnabled(thereIsAtLeastOneModelOpenned);
    //ui->actionModels->setEnabled(thereIsAtLeastOneModelOpenned);
    ui->menuModel->setEnabled(thereIsAtLeastOneModelOpenned);
    ui->tabWidgetModels->setEnabled(thereIsAtLeastOneModelOpenned);
}

void MainWindow::_refreshTabWidgetModel() {
    bool thereIsAtLeastOneModelOpenned = simulator->getModels()->size() > 0;
    if (!thereIsAtLeastOneModelOpenned)
        ui->tabWidgetModels->clear(); // no models openned
}

//*******************************************************************
// MAINWINDOW START
//*******************************************************************

void MainWindow::on_actionAbout_triggered() {
    DialogAbout da;
    da.setLabelVersion(QString::fromStdString(this->simulator->getVersion()));
    da.setModal(true);
    da.exec();
}

void MainWindow::on_actionExit_triggered() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Exit", "Exit GeneSyS?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        //qDebug() << "Yes was clicked";
        QApplication::quit();
    } else {
        //qDebug() << "Yes was *not* clicked";
    }
}

void MainWindow::_createNewTabForModel(Model* newModel) {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "New", "Create new model?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        QWidget* newTabForModel = new QWidget(this);
        mapSimUI.map(newModel, newTabForModel);
        ui->tabWidgetModels->addTab(newTabForModel, QString::fromStdString(newModel->getInfos()->getName()));
        ui->tabWidgetModels->setCurrentIndex(ui->tabWidgetModels->count() - 1);
        _refreshActions();
        _refreshTabWidgetModel();
    }
}

void MainWindow::on_actionNew_triggered() {
    Model* newModel = new Model(simulator);
    simulator->getModels()->insert(newModel);
    _createNewTabForModel(newModel);
}

void MainWindow::on_actionOpen_triggered() {
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open Simulation Model"), "",
            tr("Genesys Simulation Model (*.gsm);;All Files (*)"));
    if (fileName.isEmpty())
        return;
    else {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(this, tr("Unable to open file"),
                    file.errorString());
            return;
        }
        bool loaded = simulator->getModels()->loadModel(fileName.toStdString());
        if (loaded) {
            _createNewTabForModel(simulator->getModels()->current());
            _refreshActions();
            _refreshTabWidgetModel();
        }
    }
}

void MainWindow::on_actionClose_triggered() {

}

void MainWindow::on_actionSave_triggered() {
    QString fileName = QFileDialog::getSaveFileName(this,
            tr("Save Simulation Model"), "",
            tr("Genesys Simulation Model (*.gsm);;All Files (*)"));
    if (fileName.isEmpty())
        return;
    else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(this, tr("Unable to open file"),
                    file.errorString());
            return;
        }
        //QDataStream out(&file);
        //out.setVersion(QDataStream::Qt_4_5);
        //out << contacts;
    }
}

void MainWindow::on_actionSave_as_triggered() {

}

void MainWindow::on_actionUndo_triggered() {

}

void MainWindow::on_actionRedo_triggered() {

}

void MainWindow::on_actionCut_triggered() {

}

void MainWindow::on_actionCopy_triggered() {

}

void MainWindow::on_actionPaste_triggered() {

}

void MainWindow::on_actionFind_triggered() {

}

void MainWindow::on_actionReplace_triggered() {

}

void MainWindow::on_actionGroup_triggered() {

}

void MainWindow::on_actionCheck_Model_triggered() {

}

void MainWindow::on_actionStart_triggered() {

}

void MainWindow::on_actionStep_triggered() {

}

void MainWindow::on_actionStop_triggered() {

}

void MainWindow::on_actionRun_Control_triggered() {

}

void MainWindow::on_tabWidgetModels_tabBarDoubleClicked(int index) {

}

void MainWindow::on_tabWidgetModels_tabCloseRequested(int index) {

}

void MainWindow::on_tabWidgetModels_currentChanged(int index) {

}

void MainWindow::on_actionInformation_triggered() {
    DialogModelInformation dmi;
    dmi.setModal(true);
    dmi.exec();
}
