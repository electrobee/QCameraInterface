#include "qcameramanager.h"

QCameraManager::QCameraManager(QObject *parent)
	: QObject(parent)
{
	initialize();
}

QCameraManager::~QCameraManager()
{

}

void QCameraManager::initialize()
{
	QDir cameralibpath("./cameras");
	cameralibpath.makeAbsolute();
	qDebug(qPrintable(cameralibpath.absolutePath()));
	foreach(QString cameralib, cameralibpath.entryList(QStringList("*.dll"),QDir::Files))
	{
		qDebug(qPrintable(cameralibpath.absoluteFilePath(cameralib)));
		QPluginLoader loader( cameralibpath.absoluteFilePath(cameralib));
		QObject *candidate = loader.instance();
		qDebug(qPrintable(loader.errorString()));
		if(candidate)
		{
			QCameraInterface *camerainterface = qobject_cast<QCameraInterface *>(candidate);

			if(camerainterface)
			{
				_camerainterfacetypes[ camerainterface->name() ] = cameralibpath.absoluteFilePath(cameralib);
				camerainterface->initialize();
				_availablecameras << camerainterface->getcameras();
				_loadedInterfaces.append(camerainterface);
			}
		}
	}

}

QList<QCamera *> QCameraManager::showdialog(bool multi)
{
	QCameraDialog *dialog = new QCameraDialog();

	dialog->setMultiSelect(multi);

	getcameralist();

	dialog->setcameralist(_availablecameras);

	int ret = dialog->exec();
	return  dialog->selectedcameras();
}
QList<QCamera *> QCameraManager::getcameralist()
{
	_availablecameras.clear();
	foreach(QCameraInterface *camerainterface, _loadedInterfaces)
	{
		_availablecameras << camerainterface->getcameras();
	}
	return _availablecameras;
}

