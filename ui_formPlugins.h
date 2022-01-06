/********************************************************************************
** Form generated from reading UI file 'formPlugins.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPLUGINS_H
#define UI_FORMPLUGINS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_formPlugins
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *formPlugins)
    {
        if (formPlugins->objectName().isEmpty())
            formPlugins->setObjectName(QString::fromUtf8("formPlugins"));
        formPlugins->resize(632, 465);
        buttonBox = new QDialogButtonBox(formPlugins);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(270, 390, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(formPlugins);
        QObject::connect(buttonBox, SIGNAL(accepted()), formPlugins, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), formPlugins, SLOT(reject()));

        QMetaObject::connectSlotsByName(formPlugins);
    } // setupUi

    void retranslateUi(QDialog *formPlugins)
    {
        formPlugins->setWindowTitle(QCoreApplication::translate("formPlugins", "Plugins", nullptr));
    } // retranslateUi

};

namespace Ui {
    class formPlugins: public Ui_formPlugins {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPLUGINS_H
