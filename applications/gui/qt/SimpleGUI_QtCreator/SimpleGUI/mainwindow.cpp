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
	simulator = new Simulator();
	simulator->getTracer()->setTraceLevel(Util::TraceLevel::L9_mostDetailed);
	simulator->getTracer()->addTraceHandler<MainWindow>(this, &MainWindow::_simulatorTraceHandler);
	_insertFakePlugins();
	//connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
	//        ui->progressBar, SLOT(setValue(int)));
}

MainWindow::~MainWindow() {
	delete ui;
}


//-----------------
// View
//-----------------

void MainWindow::_actualizeWidgets() {
	bool opened = simulator->getModels()->current() != nullptr;
	ui->actionSave->setEnabled(opened);
	ui->actionClose->setEnabled(opened);
	ui->menuSimulation->setEnabled(opened);
	ui->tabWidgetModel->setEnabled(opened);
    if (!opened) {
        ui->textEditModel->clear();
        ui->textEditSimulation->clear();
        ui->textEditReports->clear();
    }
}

//-----------------
// Simulator based
//-----------------

void MainWindow::_simulatorTraceHandler(TraceEvent e) {
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

void MainWindow::_insertPluginUI(Plugin* plugin) {
	if (plugin != nullptr) {
		if (plugin->isIsValidPlugin()) {
			QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(plugin->getPluginInfo()->getPluginTypename()));
			std::string plugtextAdds = "";
			if (plugin->getPluginInfo()->isComponent()) {
				plugtextAdds += ",Component";
				//item->setBackgroundColor(Qt::white);
				//item->set
				item->setIcon(QIcon(":/resources/icons/pack3/ico/component.ico"));
			} else {
				plugtextAdds += ",Element";
				//item->setBackgroundColor(Qt::lightGray);
				item->setIcon(QIcon(":/resources/icons/pack3/ico/calendar.ico"));
				//item->setFont(QFont::Style::StyleItalic);
			}
			if (plugin->getPluginInfo()->isSink()) {
				plugtextAdds += ",Sink";
				item->setIcon(QIcon(":/resources/icons/pack3/ico/loadInv.ico"));
			}
			if (plugin->getPluginInfo()->isSource()) {
				plugtextAdds += ",Source";
				item->setIcon(QIcon(":/resources/icons/pack3/ico/load.ico"));
			}
			if (plugin->getPluginInfo()->isReceiveTransfer()) {
				plugtextAdds += ",ReceiveTransfer";
				item->setIcon(QIcon(":/resources/icons/pack3/ico/load.ico"));
			}
			if (plugin->getPluginInfo()->isSendTransfer()) {
				plugtextAdds += ",SendTransfer";
				item->setIcon(QIcon(":/resources/icons/pack3/ico/loadInv.ico"));
			}
			plugtextAdds += "\n" + plugin->getPluginInfo()->getObservation(); //getDescriptionHelp();
			plugtextAdds = plugtextAdds.erase(0, 1);
			item->setToolTip(QString::fromStdString(plugtextAdds));
			item->setStatusTip(QString::fromStdString(plugtextAdds));
			ui->listWidget_Plugins->addItem(item);
		}
	}
}

void MainWindow::_insertFakePlugins() {
	PluginManager* pm = simulator->getPlugins();
	// TRYING SOME NEW ORGANIZATION (BASED ON ARENA 16..20)

	// DISCRETE

	// CONTINUOS

	// DATA DEFINITION


	//-----------------------------------------------------

	// OLD ORGANIZATION

	// model components
	// arena basic process
	_insertPluginUI(pm->insert("create.so"));
	_insertPluginUI(pm->insert("dispose.so"));
	_insertPluginUI(pm->insert("decide.so"));
	_insertPluginUI(pm->insert("batch.so"));
	_insertPluginUI(pm->insert("separate.so"));
	_insertPluginUI(pm->insert("assign.so"));
	_insertPluginUI(pm->insert("record.so"));
	_insertPluginUI(pm->insert("process.so"));
	_insertPluginUI(pm->insert("submodel.so"));
	_insertPluginUI(pm->insert("entitygroup.so"));
	_insertPluginUI(pm->insert("queue.so"));
	_insertPluginUI(pm->insert("set.so"));
	_insertPluginUI(pm->insert("resource.so"));
	_insertPluginUI(pm->insert("variable.so"));
	_insertPluginUI(pm->insert("schedule.so"));
	_insertPluginUI(pm->insert("entitygroup.so"));
	// arena advanced process
	_insertPluginUI(pm->insert("delay.so"));
	_insertPluginUI(pm->insert("dropoff.so"));
	_insertPluginUI(pm->insert("hold.so"));
	_insertPluginUI(pm->insert("match.so"));
	_insertPluginUI(pm->insert("pickup.so"));
	_insertPluginUI(pm->insert("read.so"));
	_insertPluginUI(pm->insert("write.so"));
	_insertPluginUI(pm->insert("release.so"));
	_insertPluginUI(pm->insert("remove.so"));
	_insertPluginUI(pm->insert("seize.so"));
	_insertPluginUI(pm->insert("search.so"));
	_insertPluginUI(pm->insert("signal.so"));
	_insertPluginUI(pm->insert("store.so"));
	_insertPluginUI(pm->insert("unstore.so"));
	_insertPluginUI(pm->insert("expression.so"));
	_insertPluginUI(pm->insert("failure.so"));
	_insertPluginUI(pm->insert("file.so"));
	_insertPluginUI(pm->insert("storage.so"));
	// arena transfer station
	_insertPluginUI(pm->insert("enter.so"));
	_insertPluginUI(pm->insert("leave.so"));
	_insertPluginUI(pm->insert("pickstation.so"));
	_insertPluginUI(pm->insert("route.so"));
	_insertPluginUI(pm->insert("sequence.so"));
	_insertPluginUI(pm->insert("station.so"));
	// arena transfer conveyour
	_insertPluginUI(pm->insert("access.so"));
	_insertPluginUI(pm->insert("exit.so"));
	_insertPluginUI(pm->insert("start.so"));
	_insertPluginUI(pm->insert("stop.so"));
	_insertPluginUI(pm->insert("conveyour.so"));
	_insertPluginUI(pm->insert("segment.so"));
	// arena transfer transport
	_insertPluginUI(pm->insert("alocate.so"));
	_insertPluginUI(pm->insert("free.so"));
	_insertPluginUI(pm->insert("halt.so"));
	_insertPluginUI(pm->insert("move.so"));
	_insertPluginUI(pm->insert("request.so"));
	_insertPluginUI(pm->insert("transporter.so"));
	_insertPluginUI(pm->insert("distance.so"));
	_insertPluginUI(pm->insert("network.so"));
	_insertPluginUI(pm->insert("networklink.so"));
	// others
	_insertPluginUI(pm->insert("dummy.so"));
	_insertPluginUI(pm->insert("lsode.so"));
	_insertPluginUI(pm->insert("biochemical.so"));
	_insertPluginUI(pm->insert("markovchain.so"));
	_insertPluginUI(pm->insert("cellularautomata.so"));
	_insertPluginUI(pm->insert("cppforg.so"));
}

void MainWindow::on_actionNew_triggered() {
    ui->textEdit_Console->append("\n> model_new");
	Model* m;
	if ((m = simulator->getModels()->current()) != nullptr) {
		simulator->getModels()->remove(m);
	}
	m = simulator->getModels()->newModel();
	ui->textEditModel->clear();
	ui->textEditSimulation->clear();
	ui->textEditReports->clear();
    ui->textEdit_Console->moveCursor(QTextCursor::End);
    std::string tempFilename = "./temp.tmp";
	bool res = m->save(tempFilename);
	if (res) {
        std::string line;
        std::ifstream file(tempFilename);
        if (file.is_open()) {
            while (std::getline(file, line)) {
                ui->textEdit_Console->append(QString::fromStdString(line));
                ui->textEdit_Console->moveCursor(QTextCursor::End);
            }
            file.close();
            QMessageBox::information(this, "New Model", "Model successfully created");
        } else {
            ui->textEdit_Console->append(QString("Error reading template model file"));
        }
      } else {
        ui->textEdit_Console->append(QString("Error saving template model file"));
	}
	_actualizeWidgets();
}

void MainWindow::on_actionLoad_triggered()
{
    QFileDialog fd;
    fd.exec();
    //fd.getOpenFileName()
    QMessageBox::information(this, "Load Model", "Model successfully loaded");

}

void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,
            tr("Save Model"), "",
            tr("Model (*.txt);;All Files (*)"));
    if (fileName.isEmpty())
        return;
    else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(this, tr("Unable to open file"),
            file.errorString());
            return;
        }
        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_5_12);
        out << ui->textEditModel->toPlainText();
        QMessageBox::information(this, "Save Model", "Model successfully saved");
    }
}

void MainWindow::on_actionClose_triggered()
{
    ui->textEdit_Console->moveCursor(QTextCursor::End);
    ui->textEdit_Console->append("> model_close");
    simulator->getModels()->remove(simulator->getModels()->current());
    _actualizeWidgets();
    QMessageBox::information(this, "Close Model", "Model successfully closed");
}

void MainWindow::on_actionExit_triggered()
{
    int res = QMessageBox::question(this, "Exit", "Do you want to exit GenESyS?", QMessageBox::Yes|QMessageBox::No);
    if (res == QMessageBox::Yes) {
        QApplication::closeAllWindows();
    }
}

void MainWindow::on_actionStop_triggered()
{

}
