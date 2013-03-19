#ifndef QCAMERADIALOG_H
#define QCAMERADIALOG_H

#include <QDialog>
#include <QAbstractButton>

#include "qcamera.h"
#include "ui_qcameradialog.h"

class QCameraDialog : public QDialog
{
	Q_OBJECT
public:
	QCameraDialog(QWidget *parent = 0);
	~QCameraDialog();

	void setcameralist(const QList<QCamera *> cameras);
	QList<QCamera *> selectedcameras();
	void setMultiSelect(bool multi);
private:
	Ui::QCameraDialogClass ui;
	QMap<QString, QCamera *> _allcameras;

protected slots:
	void on_buttonBox_clicked(QAbstractButton* button);
signals:
		void camera_selected(QList<QCamera *> cameras);
};

#endif // QCAMERADIALOG_H
