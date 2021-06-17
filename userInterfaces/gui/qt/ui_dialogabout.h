/********************************************************************************
** Form generated from reading UI file 'dialogabout.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
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
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogAbout
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QTextEdit *textEdit;

    void setupUi(QDialog *DialogAbout)
    {
        if (DialogAbout->objectName().isEmpty())
            DialogAbout->setObjectName(QString::fromUtf8("DialogAbout"));
        DialogAbout->resize(417, 258);
        DialogAbout->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        DialogAbout->setModal(true);
        buttonBox = new QDialogButtonBox(DialogAbout);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(70, 220, 331, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        label = new QLabel(DialogAbout);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 63, 100));
        label->setPixmap(QPixmap(QString::fromUtf8(":/rec/resources/software_genesys.gif")));
        label_2 = new QLabel(DialogAbout);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 10, 316, 19));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setFrameShadow(QFrame::Raised);
        label_2->setTextFormat(Qt::RichText);
        label_3 = new QLabel(DialogAbout);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 50, 273, 17));
        label_4 = new QLabel(DialogAbout);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 100, 273, 17));
        label_5 = new QLabel(DialogAbout);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(90, 70, 291, 17));
        textEdit = new QTextEdit(DialogAbout);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 120, 391, 91));
        textEdit->setFrameShape(QFrame::NoFrame);
        textEdit->setFrameShadow(QFrame::Plain);
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit->setReadOnly(true);

        retranslateUi(DialogAbout);

        QMetaObject::connectSlotsByName(DialogAbout);
    } // setupUi

    void retranslateUi(QDialog *DialogAbout)
    {
        DialogAbout->setWindowTitle(QApplication::translate("DialogAbout", "About ReGenESyS", nullptr));
        label->setText(QString());
        label_2->setText(QApplication::translate("DialogAbout", "Generic and Expansible System Simulator", nullptr));
        label_3->setText(QApplication::translate("DialogAbout", "Author: Prof. Dr. Ing. Rafael Luiz Cancian", nullptr));
        label_4->setText(QApplication::translate("DialogAbout", "Version 19.11 (DayOfTheDead 19)", nullptr));
        label_5->setText(QApplication::translate("DialogAbout", "Federal University of Santa Catarina, Brazil", nullptr));
        textEdit->setHtml(QApplication::translate("DialogAbout", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\" bgcolor=\"#eeeeee\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Tahoma,Arial,sans-serif'; color:#000000;\">Genesys is a result of teaching and researchactivities of Professor Dr. Ing Rafael Luiz Cancian. It began in early 2002 as a way to teach students the basics andsimulation techniques of systems implemented by other comercial simulation tools, such as Arena. In Genesysdevelopment he replicated all the SIMAN language, used by Arena software, and Genesys has become a clone of thattool, including its graphical interface. Genesys allowed the inclusion of new simulation components"
                        " through dynamiclink libraries and also the parallel execution of simulation models in a distributed environment. The developmentof Genesys continued until 2007, when the professor stopped teaching systems simulation.</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogAbout: public Ui_DialogAbout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGABOUT_H
