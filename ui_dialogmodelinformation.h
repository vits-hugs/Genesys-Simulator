/********************************************************************************
** Form generated from reading UI file 'dialogmodelinformation.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGMODELINFORMATION_H
#define UI_DIALOGMODELINFORMATION_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogModelInformation
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_AnalystName;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *lineEdit_ProjectTitle;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_ModelName;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *lineEdit_Description;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEdit_Version;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogModelInformation)
    {
        if (DialogModelInformation->objectName().isEmpty())
            DialogModelInformation->setObjectName(QString::fromUtf8("DialogModelInformation"));
        DialogModelInformation->resize(400, 300);
        DialogModelInformation->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        verticalLayout = new QVBoxLayout(DialogModelInformation);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(DialogModelInformation);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_AnalystName = new QLineEdit(DialogModelInformation);
        lineEdit_AnalystName->setObjectName(QString::fromUtf8("lineEdit_AnalystName"));

        horizontalLayout_2->addWidget(lineEdit_AnalystName);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(DialogModelInformation);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        lineEdit_ProjectTitle = new QLineEdit(DialogModelInformation);
        lineEdit_ProjectTitle->setObjectName(QString::fromUtf8("lineEdit_ProjectTitle"));

        horizontalLayout_3->addWidget(lineEdit_ProjectTitle);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(DialogModelInformation);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_ModelName = new QLineEdit(DialogModelInformation);
        lineEdit_ModelName->setObjectName(QString::fromUtf8("lineEdit_ModelName"));

        horizontalLayout->addWidget(lineEdit_ModelName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(DialogModelInformation);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        lineEdit_Description = new QLineEdit(DialogModelInformation);
        lineEdit_Description->setObjectName(QString::fromUtf8("lineEdit_Description"));

        horizontalLayout_4->addWidget(lineEdit_Description);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(DialogModelInformation);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        lineEdit_Version = new QLineEdit(DialogModelInformation);
        lineEdit_Version->setObjectName(QString::fromUtf8("lineEdit_Version"));

        horizontalLayout_5->addWidget(lineEdit_Version);


        verticalLayout->addLayout(horizontalLayout_5);

        buttonBox = new QDialogButtonBox(DialogModelInformation);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        label_2->setBuddy(lineEdit_AnalystName);
        label_4->setBuddy(lineEdit_ProjectTitle);
        label->setBuddy(lineEdit_ModelName);
        label_3->setBuddy(lineEdit_Description);
        label_5->setBuddy(lineEdit_Version);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(lineEdit_AnalystName, lineEdit_ProjectTitle);
        QWidget::setTabOrder(lineEdit_ProjectTitle, lineEdit_ModelName);
        QWidget::setTabOrder(lineEdit_ModelName, lineEdit_Description);
        QWidget::setTabOrder(lineEdit_Description, lineEdit_Version);

        retranslateUi(DialogModelInformation);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogModelInformation, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogModelInformation, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogModelInformation);
    } // setupUi

    void retranslateUi(QDialog *DialogModelInformation)
    {
        DialogModelInformation->setWindowTitle(QApplication::translate("DialogModelInformation", "Model Information", nullptr));
        label_2->setText(QApplication::translate("DialogModelInformation", "Analyst Name:", nullptr));
        label_4->setText(QApplication::translate("DialogModelInformation", "Project Title:", nullptr));
        label->setText(QApplication::translate("DialogModelInformation", "Model Name:", nullptr));
        label_3->setText(QApplication::translate("DialogModelInformation", "Description:", nullptr));
        label_5->setText(QApplication::translate("DialogModelInformation", "Version:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogModelInformation: public Ui_DialogModelInformation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGMODELINFORMATION_H
