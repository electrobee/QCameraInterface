#ifndef QCAMERAMANAGER_H
#define QCAMERAMANAGER_H
#include "qcamerainterface_global.h"

#include <QObject>
#include <QMap>
#include <QDir>
#include <QList>
#include <QPluginLoader>

#include "qcameradialog.h"
#include "qcamerainterface.h"

class QCAMERAINTERFACE_EXPORT QCameraManager : public QObject
{
	Q_OBJECT

public:
	QCameraManager(QObject *parent=0);
	~QCameraManager();

	QCamera *getcamera(int index) { return _availablecameras.at(index); }
	int getcameracount() { return _availablecameras.count(); }
	void selectCamera(QCamera *camera) { camera->setSelected(); } 

	QList<QCamera *> showdialog(bool multi);
	QList<QCamera *> getcameralist();
private:
	QMap<QString, QString> _camerainterfacetypes;
	QList<QCameraInterface *> _loadedInterfaces;
	QList<QCamera *> _availablecameras;
	void initialize();

};

#endif // QCAMERAMANAGER_H
