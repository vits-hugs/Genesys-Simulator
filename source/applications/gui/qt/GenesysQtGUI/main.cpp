#include "mainwindow.h"
#include <QApplication>

#include "../../../GenesysApplication_if.h"
#include "../../../TraitsApp.h"

//*************************************************************
// Configure the app: GUI (true) or TerminalApplication (false)
bool runGUI = false;
//*************************************************************
//*************************************************************
// Configure the tests: run the tests (true) or run the app (false)
bool runTests = true;
//*************************************************************

int mainGraphicQtApp(int argc, char *argv[]) {
	QApplication a(argc, argv);
	MainWindow w;
	w.showMaximized(); //.show();
	return a.exec();
}

int mainTerminalApp(int argc, char *argv[]) {
	GenesysApplication_if *app = new TraitsApp<GenesysApplication_if>::Application();
	return app->main(argc, argv);
}

int tests() {
	class TestClass: public ModelDataDefinition {
	public:
		TestClass():ModelDataDefinition(nullptr, "Nada mesmo", "nenhum nome", false) {
			_int = 2;
			_str = "um valor";
			_doub = 3.14;
			ADD_PROPERTY_G("Prop String", std::string, 1, true, TestClass, getStr, setStr, "parentName", "displayText", "statusTip", "toolTip", "whatIsThis")
			ADD_PROPERTY_G("Prop Int", int, 2, true, TestClass, getInt, setInt, "parentName", "displayText", "statusTip", "toolTip", "whatIsThis")

		}
		std::string getStr() {return _str;}
		void setStr(std::string val) {_str=val;}
		double getDoub() {return _doub;}
		void setdoub(double val) {_doub=val;}
		int getInt() {return _int;}
		void setInt(int val) {_int=val;}
	private:
		std::string _str;
		double _doub;
		int _int;
	};

	TestClass* cl = new TestClass();
	PropertyBaseG* prop = cl->getPropertiesG()->getProperty("String");
	std::cout << "(" << prop->getPropertyName()+"|" << prop->getPropertyType() <<") " << prop->getPropertyName() << "=" << std::endl;
}

int main(int argc, char *argv[]) {
	if (runTests) {
		return tests();
	} else {
		if (runGUI) {
			return mainGraphicQtApp(argc, argv);
		} else {
			return mainTerminalApp(argc, argv);
		}
	}
}

