/********************************************************************************
** Form generated from reading UI file 'qcameradialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QCAMERADIALOG_H
#define UI_QCAMERADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QCameraDialogClass
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *lwCameras;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *QCameraDialogClass)
    {
        if (QCameraDialogClass->objectName().isEmpty())
            QCameraDialogClass->setObjectName(QStringLiteral("QCameraDialogClass"));
        QCameraDialogClass->resize(400, 300);
        verticalLayout = new QVBoxLayout(QCameraDialogClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lwCameras = new QListWidget(QCameraDialogClass);
        lwCameras->setObjectName(QStringLiteral("lwCameras"));
        lwCameras->setSelectionMode(QAbstractItemView::MultiSelection);

        verticalLayout->addWidget(lwCameras);

        buttonBox = new QDialogButtonBox(QCameraDialogClass);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(QCameraDialogClass);

        QMetaObject::connectSlotsByName(QCameraDialogClass);
    } // setupUi

    void retranslateUi(QWidget *QCameraDialogClass)
    {
        QCameraDialogClass->setWindowTitle(QApplication::translate("QCameraDialogClass", "Select a camera", 0));
    } // retranslateUi

};

namespace Ui {
    class QCameraDialogClass: public Ui_QCameraDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QCAMERADIALOG_H
