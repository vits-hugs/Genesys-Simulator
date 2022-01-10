/********************************************************************************
 ** Form generated from reading UI file 'dialogabout.ui'
 **
 ** Created by: Qt User Interface Compiler version 5.15.2
 **
 ** WARNING! All changes made in this file will be lost when recompiling UI file!
 ********************************************************************************/

#ifndef UI_DIALOGABOUT_H
#define UI_DIALOGABOUT_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogAbout {
public:
	QVBoxLayout *verticalLayout_3;
	QHBoxLayout *horizontalLayout_2;
	QLabel *labelIcon;
	QVBoxLayout *verticalLayout_2;
	QLabel *label_2;
	QLabel *labelAuthor;
	QLabel *labelInstitution;
	QLabel *labelVersionGenesys;
	QTextEdit *textEditDescription;
	QDialogButtonBox *buttonOk;
	void setupUi(QDialog *DialogAbout) {
		if (DialogAbout->objectName().isEmpty())
			DialogAbout->setObjectName(QString::fromUtf8("DialogAbout"));
		DialogAbout->resize(469, 227);
		DialogAbout->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
		DialogAbout->setModal(true);
		verticalLayout_3 = new QVBoxLayout(DialogAbout);
		verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
		horizontalLayout_2 = new QHBoxLayout();
		horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
		labelIcon = new QLabel(DialogAbout);
		labelIcon->setObjectName(QString::fromUtf8("labelIcon"));
		labelIcon->setPixmap(QPixmap(QString::fromUtf8(":/rec/resources/software_genesys.gif")));

		horizontalLayout_2->addWidget(labelIcon);

		verticalLayout_2 = new QVBoxLayout();
		verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
		label_2 = new QLabel(DialogAbout);
		label_2->setObjectName(QString::fromUtf8("label_2"));
		QFont font;
		font.setPointSize(12);
		font.setBold(true);
		font.setWeight(75);
		label_2->setFont(font);
		label_2->setFrameShadow(QFrame::Raised);
		label_2->setTextFormat(Qt::RichText);

		verticalLayout_2->addWidget(label_2);

		labelAuthor = new QLabel(DialogAbout);
		labelAuthor->setObjectName(QString::fromUtf8("labelAuthor"));

		verticalLayout_2->addWidget(labelAuthor);

		labelInstitution = new QLabel(DialogAbout);
		labelInstitution->setObjectName(QString::fromUtf8("labelInstitution"));

		verticalLayout_2->addWidget(labelInstitution);

		labelVersionGenesys = new QLabel(DialogAbout);
		labelVersionGenesys->setObjectName(QString::fromUtf8("labelVersionGenesys"));

		verticalLayout_2->addWidget(labelVersionGenesys);


		horizontalLayout_2->addLayout(verticalLayout_2);


		verticalLayout_3->addLayout(horizontalLayout_2);

		textEditDescription = new QTextEdit(DialogAbout);
		textEditDescription->setObjectName(QString::fromUtf8("textEditDescription"));
		QFont font1;
		font1.setPointSize(9);
		textEditDescription->setFont(font1);
		textEditDescription->setFrameShape(QFrame::NoFrame);
		textEditDescription->setFrameShadow(QFrame::Plain);
		textEditDescription->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		textEditDescription->setReadOnly(true);

		verticalLayout_3->addWidget(textEditDescription);

		buttonOk = new QDialogButtonBox(DialogAbout);
		buttonOk->setObjectName(QString::fromUtf8("buttonOk"));
		buttonOk->setOrientation(Qt::Horizontal);
		buttonOk->setStandardButtons(QDialogButtonBox::Ok);

		verticalLayout_3->addWidget(buttonOk);


		retranslateUi(DialogAbout);
		QObject::connect(buttonOk, SIGNAL(accepted()), DialogAbout, SLOT(accept()));

		QMetaObject::connectSlotsByName(DialogAbout);
	} // setupUi
	void retranslateUi(QDialog *DialogAbout) {
		DialogAbout->setWindowTitle(QCoreApplication::translate("DialogAbout", "About GenESyS", nullptr));
		labelIcon->setText(QString());
		label_2->setText(QCoreApplication::translate("DialogAbout", "Generic and Expansible System Simulator", nullptr));
		labelAuthor->setText(QCoreApplication::translate("DialogAbout", "Author: Prof. Dr. Ing. Rafael Luiz Cancian", nullptr));
		labelInstitution->setText(QCoreApplication::translate("DialogAbout", "Federal University of Santa Catarina, Brazil", nullptr));
		labelVersionGenesys->setText(QCoreApplication::translate("DialogAbout", "Version 19.11 (DayOfTheDead 19)", nullptr));
		textEditDescription->setHtml(QCoreApplication::translate("DialogAbout", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
				"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
				"p, li { white-space: pre-wrap; }\n"
				"</style></head><body style=\" font-family:'DejaVu LGC Sans'; font-size:9pt; font-weight:400; font-style:normal;\" bgcolor=\"#eeeeee\">\n"
				"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Tahoma,Arial,sans-serif'; font-size:8pt; color:#000000;\">Genesys is a result of teaching and researchactivities of Professor Dr. Ing Rafael Luiz Cancian. It began in early 2002 as a way to teach students the basics andsimulation techniques of systems implemented by other comercial simulation tools, such as Arena. In Genesysdevelopment he replicated all the SIMAN language, used by Arena software, and Genesys has become a clone of thattool, including its graphical interface. Genesys allowed the inclusion of ne"
				"w simulation components through dynamiclink libraries and also the parallel execution of simulation models in a distributed environment. The developmentof Genesys continued until 2007, when the professor stopped teaching systems simulation.</span></p></body></html>", nullptr));
	} // retranslateUi

};

namespace Ui {

	class DialogAbout : public Ui_DialogAbout {
	};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGABOUT_H
