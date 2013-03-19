#include "qcameradialog.h"

QCameraDialog::QCameraDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

QCameraDialog::~QCameraDialog()
{

}

void QCameraDialog::setcameralist(const QList<QCamera *> cameras)
{
	foreach(QCamera *camera, cameras)
	{
		QListWidgetItem *item = new QListWidgetItem(camera->identifier(), ui.lwCameras);
		_allcameras.insert(camera->identifier(), camera);
	}
}

QList<QCamera *> QCameraDialog::selectedcameras()
{
	QList<QCamera *> selected;

	QList<QListWidgetItem *> selectedItems = ui.lwCameras->selectedItems();

	foreach(QListWidgetItem *item, selectedItems)
	{
		selected.append(_allcameras[item->text()]);
	}

	return selected;
}

void QCameraDialog::on_buttonBox_clicked(QAbstractButton* button)
{
    if( 0 == button->text().compare("OK",Qt::CaseSensitive))
    {
		this->accept();
    }
	else{
		this->reject();
	}
}

void QCameraDialog::setMultiSelect(bool multi)
{
	ui.lwCameras->setSelectionMode(multi ? QAbstractItemView::MultiSelection : QAbstractItemView::SingleSelection);
}
	
