#ifndef QCAMERAINTERFACE_H
#define QCAMERAINTERFACE_H

#include "qcamera.h"
#include "qcamerainterface_global.h"

class QCAMERAINTERFACE_EXPORT QCameraInterface : public QObject
{
	Q_OBJECT
public:
	virtual void initialize() = 0;
	virtual void unload() = 0;
	virtual QList<QCamera *> getcameras() = 0;
	virtual QString name() = 0;
	virtual QCamera * selectedCamera() = 0;


private:

};

Q_DECLARE_INTERFACE(QCameraInterface, "com.ctphoto.QCameraInterface/0.1")


#endif // QCAMERAINTERFACE_H
