#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QTreeWidgetItem>
#include <QGraphicsItem>

#include "../../../../../kernel/simulator/Simulator.h"
#include "../../../../../kernel/simulator/TraceManager.h"
#include "CodeEditor.h"
#include "ModelGraphicsScene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

	bool graphicalModelHasChanged() const;
	void setGraphicalModelHasChanged(bool graphicalModelHasChanged);

private slots:
	void on_actionNew_triggered();
	void on_actionSave_triggered();
	void on_actionClose_triggered();
	void on_actionExit_triggered();
	void on_actionStop_triggered();
	void on_actionStart_triggered();
	void on_actionStep_triggered();
	void on_actionPause_triggered();
	void on_actionResume_triggered();
	void on_actionOpen_triggered();
	void on_actionCheck_triggered();
	void on_actionAbout_triggered();
	void on_actionLicence_triggered();
	void on_actionGet_Involved_triggered();
	//void on_textCodeEdit_Model_textChanged();
	void on_tabWidget_Model_tabBarClicked(int index);
	void on_tabWidget_Debug_currentChanged(int index);
	void on_horizontalSlider_Zoom_valueChanged(int value);
	void on_checkBox_ShowElements_stateChanged(int arg1);
	void on_checkBox_ShowInternals_stateChanged(int arg1);
	void on_checkBox_ShowRecursive_stateChanged(int arg1);
	void on_checkBox_ShowLevels_stateChanged(int arg1);
	void on_pushButton_Breakpoint_Insert_clicked();
	void on_pushButton_Breakpoint_Remove_clicked();
	void on_tabWidgetCentral_currentChanged(int index);
	void on_tabWidgetCentral_tabBarClicked(int index);
	void on_treeWidget_Plugins_itemDoubleClicked(QTreeWidgetItem *item, int column);
	void on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint);
	void on_horizontalSlider_ZoomGraphical_valueChanged(int value);
	void on_actionConnect_triggered();
	void on_pushButton_Export_clicked();
	void on_tabWidgetModelLanguages_currentChanged(int index);
	void on_actionComponent_Breakpoint_triggered();
	void on_treeWidgetComponents_itemSelectionChanged();

	void on_treeWidget_Plugins_itemClicked(QTreeWidgetItem *item, int column);

	void on_TextCodeEditor_textChanged();

	void on_tabWidgetModel_currentChanged(int index);

	void on_tabWidgetSimulation_currentChanged(int index);

	void on_tabWidgetReports_currentChanged(int index);

private: // VIEW

private: // trace handlers
	void _simulatorTraceHandler(TraceEvent e);
	void _simulatorTraceErrorHandler(TraceErrorEvent e);
	void _simulatorTraceSimulationHandler(TraceSimulationEvent e);
	void _simulatorTraceReportsHandler(TraceEvent e);
private: // simuletor event handlers
	void _onReplicationStartHandler(SimulationEvent* re);
	void _onSimulationStartHandler(SimulationEvent* re);
	void _onSimulationPausedHandler(SimulationEvent* re);
	void _onSimulationResumeHandler(SimulationEvent* re);
	void _onSimulationEndHandler(SimulationEvent* re);
	void _onProcessEventHandler(SimulationEvent* re);
	void _onEntityCreateHandler(SimulationEvent* re);
	void _onEntityRemoveHandler(SimulationEvent* re);
private: // model Graphics View handlers
	void _onSceneMouseEvent(QGraphicsSceneMouseEvent* mouseEvent);
	void _onSceneGraphicalModelEvent(GraphicalModelEvent* event);
private: // QGraphicsScene Slots
	void sceneChanged(const QList<QRectF> &region);
	void sceneFocusItemChanged(QGraphicsItem *newFocusItem, QGraphicsItem *oldFocusItem, Qt::FocusReason reason);
	//void sceneRectChanged(const QRectF &rect);
	void sceneSelectionChanged();
private: // Similar to QGraphicsScene Slots
	void sceneGraphicalModelChanged();
private: // simulator related
	void _setOnEventHandlers();
	void _insertPluginUI(Plugin* plugin);
	void _insertFakePlugins();
	bool _setSimulationModelBasedOnText();
	bool _createModelImage();
	std::string _adjustDotName(std::string name);
	void _insertTextInDot(std::string text, unsigned int compLevel, unsigned int compRank, std::map<unsigned int, std::map<unsigned int, std::list<std::string>*>*>* dotmap, bool isNode = false);
	void _recursiveCreateModelGraphicPicture(ModelDataDefinition* componentOrData, std::list<ModelDataDefinition*>* visited, std::map<unsigned int, std::map<unsigned int, std::list<std::string>*>*>* dotmap);
	void _actualizeModelCppCode();
	std::string _addCppCodeLine(std::string line, unsigned int indent=0);
private: // view
	void _initModelGraphicsView();
	void _actualizeActions();
	void _actualizeTabPanes();
	void _actualizeModelSimLanguage();
	void _actualizeModelTextHasChanged(bool hasChanged);
	void _actualizeSimulationEvents(SimulationEvent * re);
	void _actualizeDebugVariables(bool force);
	void _actualizeDebugEntities(bool force);
	void _actualizeDebugBreakpoints(bool force);
	void _actualizeModelComponents(bool force);
	void _actualizeGraphicalModel(SimulationEvent * re);
	void _insertCommandInConsole(std::string text);
	void _clearModelEditors();
	void _gentle_zoom(double factor);
	//bool _checkStartSimulation();
private:
	Ui::MainWindow *ui;
	Simulator* simulator;
	bool _textModelHasChanged = false;
	bool _graphicalModelHasChanged = false;
	bool _modelWasOpened = false;
	QString _modelfilename;
	int _zoomValue;
private:
	const struct TABINDEXES_STRUC {
		const unsigned int TabCentralModelIndex = 0;
		const unsigned int TabCentralSimulationIndex = 1;
		const unsigned int TabCentralReportsIndex = 2;
		const unsigned int TabModelSimLangIndex = 0;
		const unsigned int TabModelCppCodeIndex = 1;
		const unsigned int TabModelDiagramIndex = 2;
		const unsigned int TabModelComponentsIndex = 3;
		const unsigned int TabDebugBreakpointIndex = 0;
		const unsigned int TabDebugVariableIndex = 1;
		const unsigned int TabDebugEntityIndex = 2;
		const unsigned int TabDebugTraceIndex = 3;
		const unsigned int TabDebugEventsIndex = 4;
		const unsigned int TabReportReportIndex = 0;
		const unsigned int TabReportResultIndex = 1;
		const unsigned int TabReportPlotIndex = 2;
	} CONST;
	//CodeEditor* textCodeEdit_Model;
};
#endif // MAINWINDOW_H
