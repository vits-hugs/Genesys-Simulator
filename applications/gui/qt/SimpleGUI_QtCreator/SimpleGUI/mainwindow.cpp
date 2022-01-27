#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <fstream>
#include <streambuf>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MainWindow) {
	ui->setupUi(this);
	ui->dockWidgetContentsConsole->setMaximumHeight(150);
	ui->dockWidgetContentsPlugin->setMaximumWidth(150);
    ui->listWidget_Plugins->setSortingEnabled(true);
    //ui->treeWidget_Plugins->setVisible(false);
	simulator = new Simulator();
	simulator->getTracer()->setTraceLevel(Util::TraceLevel::L9_mostDetailed);
	simulator->getTracer()->addTraceHandler<MainWindow>(this, &MainWindow::_simulatorTraceHandler);
	simulator->getTracer()->addTraceErrorHandler<MainWindow>(this, &MainWindow::_simulatorTraceErrorHandler);
	simulator->getTracer()->addTraceReportHandler<MainWindow>(this, &MainWindow::_simulatorTraceReportsHandler);
	simulator->getTracer()->addTraceSimulationHandler<MainWindow>(this, &MainWindow::_simulatorTraceSimulationHandler);
	_insertFakePlugins();
    //...
}

MainWindow::~MainWindow() {
	delete ui;
}


//-----------------
// View
//-----------------

void MainWindow::_actualizeWidgets() {
	bool opened = simulator->getModels()->current() != nullptr;
	bool running = false;
	bool paused = false;
	if (opened) {
		running = simulator->getModels()->current()->getSimulation()->isRunning();
		paused = simulator->getModels()->current()->getSimulation()->isPaused();
	}
	ui->actionSave->setEnabled(opened);
	ui->actionClose->setEnabled(opened);
	ui->actionCheck->setEnabled(opened);
	ui->menuSimulation->setEnabled(opened);
	ui->actionStart->setEnabled(opened);
	ui->actionStep->setEnabled(opened);
	ui->actionStop->setEnabled(opened && (running || paused));
	ui->actionPause->setEnabled(opened && running);
	ui->actionResume->setEnabled(opened && paused);
	ui->tabWidgetModel->setEnabled(opened);
	if (!opened) {
		_clearModelEditors();
	}
}

void MainWindow::_actualizeModelTextHasChanged(bool hasChanged) {
	if (_textModelHasChanged != hasChanged) {
		QString text = "Model";
		if (hasChanged) {
			text += "*";
		}
		ui->tabWidgetModel->setTabText(0, text);
	}
	_textModelHasChanged = hasChanged;

}

void MainWindow::_insertCommandInConsole(std::string text) {
	ui->textEdit_Console->setTextColor(QColor::fromRgb(0, 255, 0));
	ui->textEdit_Console->append("\n$genesys> " + QString::fromStdString(text));
}

void MainWindow::_clearModelEditors() {
	ui->textEdit_Model->clear();
	ui->textEdit_Simulation->clear();
	ui->textEdit_Reports->clear();
}

//-------------------------
// Simulator Trace Handlers
//-------------------------

void MainWindow::_simulatorTraceHandler(TraceEvent e) {
	if (e.getTracelevel() == Util::TraceLevel::L1_errorFatal)
		ui->textEdit_Console->setTextColor(QColor::fromRgb(255, 0, 0));
	else if (e.getTracelevel() == Util::TraceLevel::L2_results)
		ui->textEdit_Console->setTextColor(QColor::fromRgb(0, 0, 255));
	else if (e.getTracelevel() == Util::TraceLevel::L3_errorRecover)
		ui->textEdit_Console->setTextColor(QColor::fromRgb(223, 0, 0));
	else if (e.getTracelevel() == Util::TraceLevel::L4_warning)
		ui->textEdit_Console->setTextColor(QColor::fromRgb(128, 0, 0));
	else {
		unsigned short grayVal = 45 * (static_cast<unsigned int> (e.getTracelevel()) - 5);
		ui->textEdit_Console->setTextColor(QColor::fromRgb(grayVal, grayVal, grayVal));
	}
	ui->textEdit_Console->append(QString::fromStdString(e.getText()));
}

void MainWindow::_simulatorTraceErrorHandler(TraceErrorEvent e) {
	ui->textEdit_Console->setTextColor(QColor::fromRgb(255, 0, 0));
	ui->textEdit_Console->append(QString::fromStdString(e.getText()));
}

void MainWindow::_simulatorTraceSimulationHandler(TraceSimulationEvent e) {
	unsigned short grayVal = 45 * (static_cast<unsigned int> (e.getTracelevel()) - 5);
	ui->textEdit_Simulation->setTextColor(QColor::fromRgb(grayVal, grayVal, grayVal));
	ui->textEdit_Simulation->append(QString::fromStdString(e.getText()));
}

void MainWindow::_simulatorTraceReportsHandler(TraceEvent e) {
	ui->textEdit_Reports->append(QString::fromStdString(e.getText()));
}

void MainWindow::_onSimulationPausedHandler(SimulationEvent* re) {
	_actualizeWidgets();
}

void MainWindow::_onSimulationEndHandler(SimulationEvent* re) {
	_actualizeWidgets();
	ui->tabWidgetModel->setCurrentIndex(2);
}

void MainWindow::_setOnEventHandlers() {
	simulator->getModels()->current()->getOnEvents()->addOnSimulationEndHandler(this, &MainWindow::_onSimulationEndHandler);
	simulator->getModels()->current()->getOnEvents()->addOnSimulationPausedHandler(this, &MainWindow::_onSimulationPausedHandler);
}

//-------------------------
// Simulator Fake Plugins
//-------------------------

void MainWindow::_insertPluginUI(Plugin* plugin) {
	if (plugin != nullptr) {
		if (plugin->isIsValidPlugin()) {
			QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(plugin->getPluginInfo()->getPluginTypename()));
            //QTreeWidgetItem *treeItem = new QTreeWidgetItem; //(ui->treeWidget_Plugins);
            std::string plugtextAdds = plugin->getPluginInfo()->getCategory() + ": ";
            QBrush brush;
			if (plugin->getPluginInfo()->isComponent()) {
                plugtextAdds += " Component";
                brush.setColor(Qt::white);
                item->setBackground(brush);
                item->setBackgroundColor(Qt::white);
				item->setIcon(QIcon(":/resources/icons/pack3/ico/component.ico"));
			} else {
                plugtextAdds += " DataDefinition";
                brush.setColor(Qt::lightGray);
                item->setBackground(brush);
                item->setBackgroundColor(Qt::lightGray);
                item->setIcon(QIcon(":/resources/icons/pack3/ico/calendar.ico"));
				//item->setFont(QFont::Style::StyleItalic);
			}
			if (plugin->getPluginInfo()->isSink()) {
                plugtextAdds += ", Sink";
                item->setTextColor(Qt::blue);
				item->setIcon(QIcon(":/resources/icons/pack3/ico/loadInv.ico"));
			}
			if (plugin->getPluginInfo()->isSource()) {
                plugtextAdds += ", Source";
                item->setTextColor(Qt::blue);
                item->setIcon(QIcon(":/resources/icons/pack3/ico/load.ico"));
			}
			if (plugin->getPluginInfo()->isReceiveTransfer()) {
                plugtextAdds += ", ReceiveTransfer";
                item->setTextColor(Qt::blue);
                item->setIcon(QIcon(":/resources/icons/pack3/ico/load.ico"));
			}
			if (plugin->getPluginInfo()->isSendTransfer()) {
                plugtextAdds += ", SendTransfer";
                item->setTextColor(Qt::blue);
                item->setIcon(QIcon(":/resources/icons/pack3/ico/loadInv.ico"));
			}
            //treeItem->setText(0,QString::fromStdString(plugtextAdds));
            plugtextAdds += "\nDescrption: " + plugin->getPluginInfo()->getDescriptionHelp();
            plugtextAdds += "\nTemplate: " + plugin->getPluginInfo()->getLanguageTemplate();
            item->setToolTip(QString::fromStdString(plugtextAdds));
            item->setStatusTip(QString::fromStdString(plugin->getPluginInfo()->getLanguageTemplate()));
			ui->listWidget_Plugins->addItem(item);


		}
	}
}

void MainWindow::_insertFakePlugins() {
	PluginManager* pm = simulator->getPlugins();
    // TRYING SOME NEW ORGANIZATION (BASED ON ARENA 16..20)
    // ...
	//-----------------------------------------------------

	// OLD ORGANIZATION

	// model components
	// arena basic process
    (pm->insert("create.so"));
    (pm->insert("dispose.so"));
    (pm->insert("decide.so"));
    (pm->insert("batch.so"));
    (pm->insert("separate.so"));
    (pm->insert("assign.so"));
    (pm->insert("record.so"));
    (pm->insert("process.so"));
    (pm->insert("submodel.so"));
    (pm->insert("entitygroup.so"));
    (pm->insert("queue.so"));
    (pm->insert("set.so"));
    (pm->insert("resource.so"));
    (pm->insert("variable.so"));
    (pm->insert("schedule.so"));
    (pm->insert("entitygroup.so"));
	// arena advanced process
    (pm->insert("delay.so"));
    (pm->insert("dropoff.so"));
    (pm->insert("hold.so"));
    (pm->insert("match.so"));
    (pm->insert("pickup.so"));
    (pm->insert("read.so"));
    (pm->insert("write.so"));
    (pm->insert("release.so"));
    (pm->insert("remove.so"));
    (pm->insert("seize.so"));
    (pm->insert("search.so"));
    (pm->insert("signal.so"));
    (pm->insert("store.so"));
    (pm->insert("unstore.so"));
    (pm->insert("expression.so"));
    (pm->insert("failure.so"));
    (pm->insert("file.so"));
    (pm->insert("storage.so"));
	// arena transfer station
    (pm->insert("enter.so"));
    (pm->insert("leave.so"));
    (pm->insert("pickstation.so"));
    (pm->insert("route.so"));
    (pm->insert("sequence.so"));
    (pm->insert("station.so"));
    (pm->insert("label.so"));
	// arena transfer conveyour
    (pm->insert("access.so"));
    (pm->insert("exit.so"));
    (pm->insert("start.so"));
    (pm->insert("stop.so"));
    (pm->insert("conveyour.so"));
    (pm->insert("segment.so"));
	// arena transfer transport
    (pm->insert("alocate.so"));
    (pm->insert("free.so"));
    (pm->insert("halt.so"));
    (pm->insert("move.so"));
    (pm->insert("request.so"));
    (pm->insert("transporter.so"));
    (pm->insert("distance.so"));
    (pm->insert("network.so"));
    (pm->insert("networklink.so"));
	// others
    (pm->insert("dummy.so"));
    (pm->insert("lsode.so"));
    (pm->insert("biochemical.so"));
    (pm->insert("markovchain.so"));
    (pm->insert("cellularautomata.so"));
    (pm->insert("cppforg.so"));
    // now complete the information
    simulator->getPlugins()->completePluginsFieldsAndTemplates();
    for (unsigned int i=0; i<simulator->getPlugins()->size(); i++) {
        //@TODO: now it's the opportunity to adjust template
        _insertPluginUI(simulator->getPlugins()->getAtRank(i));
    }
}


//-------------------------
// PRIVATE SLOTS
//-------------------------

void MainWindow::on_actionNew_triggered() {
	Model* m;
	if ((m = simulator->getModels()->current()) != nullptr) {
		QMessageBox::StandardButton reply = QMessageBox::question(this, "New Model", "There is a model oppened already. Do you want to remove it and to create new model?", QMessageBox::Yes | QMessageBox::No);
		if (reply == QMessageBox::No) {
			return;
		}
	}
	_insertCommandInConsole("model_new");
	if (m != nullptr) {
		simulator->getModels()->remove(m);
	}
	m = simulator->getModels()->newModel();
	ui->textEdit_Model->clear();
	ui->textEdit_Simulation->clear();
	ui->textEdit_Reports->clear();
	ui->textEdit_Console->moveCursor(QTextCursor::End);
	// create a basic initial template for the model
	std::string tempFilename = "./temp.tmp";
	m->getPersistence()->setOption(ModelPersistence_if::Options::SAVEDEFAULTS, true);
	bool res = m->save(tempFilename);
	m->getPersistence()->setOption(ModelPersistence_if::Options::SAVEDEFAULTS, false);
	if (res) { // read the file saved and copy its contents to the model text editor
		std::string line;
		std::ifstream file(tempFilename);
		if (file.is_open()) {
			while (std::getline(file, line)) {
				ui->textEdit_Model->append(QString::fromStdString(line));
			}
			file.close();
			QMessageBox::information(this, "New Model", "Model successfully created");
		} else {
			ui->textEdit_Console->append(QString("Error reading template model file"));
		}
		_actualizeModelTextHasChanged(true);
		_setOnEventHandlers();
	} else {
		ui->textEdit_Console->append(QString("Error saving template model file"));
	}
	_actualizeWidgets();
}

void MainWindow::on_actionSave_triggered() {
	QString fileName = QFileDialog::getSaveFileName(this,
			tr("Save Model"), "",
			tr("Genesys Model (*.gen);;All Files (*)"));
	if (fileName.isEmpty())
		return;
	else {
		_insertCommandInConsole("model_save");
		QFile file(fileName);
		if (!file.open(QIODevice::WriteOnly)) {
			QMessageBox::information(this, tr("Unable to access file to save"),
					file.errorString());
			return;
		}
		std::ofstream savefile;
		savefile.open(fileName.toStdString(), std::ofstream::out);
		QString data = ui->textEdit_Model->toPlainText();
		QStringList strList = data.split(QRegExp("[\n]"), QString::SkipEmptyParts);
		for (unsigned int i = 0; i < strList.size(); i++) {
			savefile << strList.at(i).toStdString() << std::endl;
		}
		savefile.close();
		QMessageBox::information(this, "Save Model", "Model successfully saved");
		_actualizeModelTextHasChanged(false);
	}
	_actualizeWidgets();
}

void MainWindow::on_actionClose_triggered() {
	_insertCommandInConsole("model_close");
	simulator->getModels()->remove(simulator->getModels()->current());
	_actualizeWidgets();
	QMessageBox::information(this, "Close Model", "Model successfully closed");
}

void MainWindow::on_actionExit_triggered() {
	QMessageBox::StandardButton res = QMessageBox::question(this, "Exit GenESyS", "Do you want to exit GenESyS?", QMessageBox::Yes | QMessageBox::No);
	if (res == QMessageBox::Yes) {
		QApplication::quit();
	}
}

void MainWindow::on_actionStop_triggered() {
	_insertCommandInConsole("stop");
	simulator->getModels()->current()->getSimulation()->stop();
	_actualizeWidgets();
}

void MainWindow::on_actionStart_triggered() {
	_insertCommandInConsole("start");
	ui->textEdit_Simulation->clear();
	ui->textEdit_Reports->clear();
	simulator->getModels()->current()->getSimulation()->start();
	_actualizeWidgets();
	ui->tabWidgetModel->setCurrentIndex(1);
}

void MainWindow::on_actionStep_triggered() {
	_insertCommandInConsole("step");
	simulator->getModels()->current()->getSimulation()->step();
	_actualizeWidgets();
	ui->tabWidgetModel->setCurrentIndex(1);
}

void MainWindow::on_actionPause_triggered() {
	_insertCommandInConsole("pause");
	simulator->getModels()->current()->getSimulation()->pause();
	_actualizeWidgets();
}

void MainWindow::on_actionResume_triggered() {
	_insertCommandInConsole("start");
	simulator->getModels()->current()->getSimulation()->start();
	_actualizeWidgets();
	ui->tabWidgetModel->setCurrentIndex(1);
}

void MainWindow::on_actionOpen_triggered() {
	QString fileName = QFileDialog::getOpenFileName(
			this, "Open Model", "./",
			tr("All files (*.*);;Genesys model (*.gen)"));
	if (fileName == "") {
		return;
	}
	_insertCommandInConsole("model_open");
	bool result = simulator->getModels()->loadModel(fileName.toStdString());
	if (result) {
		_clearModelEditors();
		std::string line;
		std::ifstream file(fileName.toStdString());
		if (file.is_open()) {
			while (std::getline(file, line)) {
				ui->textEdit_Model->append(QString::fromStdString(line));
			}
			file.close();
		} else {
			ui->textEdit_Console->append(QString("Error reading model file"));
		}
		ui->textEdit_Console->append("\n");
		_setOnEventHandlers();
		_actualizeModelTextHasChanged(false);
		_actualizeWidgets();
		QMessageBox::information(this, "Open Model", "Model successfully oppened");
	} else {
		QMessageBox::warning(this, "Open Model", "Error while opening model");
	}
	_actualizeWidgets();
}

void MainWindow::on_textEdit_Model_textChanged() {
	this->_actualizeModelTextHasChanged(true);
}

void MainWindow::on_listWidget_Plugins_itemClicked(QListWidgetItem *item)
{

}

void MainWindow::on_listWidget_Plugins_itemDoubleClicked(QListWidgetItem *item)
{
    if (ui->textEdit_Model->isEnabled()) {
        ui->textEdit_Model->append(item->statusTip());
    }
}
