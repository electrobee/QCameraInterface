#ifndef QCAMERA_H
#define QCAMERA_H
#include "qcamerainterface_global.h"

#include <QObject>
#include <QImage>

#include "qcameraproperties.h"

class QCAMERAINTERFACE_EXPORT QCamera : public QObject
{
	Q_OBJECT

public:
	virtual int QCConnect() = 0;
	virtual int QCDisconnect() = 0;

	virtual void capture(int seconds=0) = 0;
	virtual void setbulbmode(bool bulb) = 0;

	virtual QImage getImage() = 0;
	virtual QString identifier() = 0;
	virtual QString model() = 0;
	virtual void setSelected() = 0;


	virtual QCameraProperties *getCameraProperties() = 0;
	virtual QCameraProperty *getCameraProperty(QCameraProperties::QCameraPropertyTypes prop) = 0;
	virtual void setCameraProperty(QCameraProperties::QCameraPropertyTypes prop, QVariant value) = 0;
	
	

	virtual void setImageDirectory(QString dir) = 0;
	virtual void setImageFilePrefix(QString imagenameprefix) = 0;

	virtual void toggleLiveView(bool onoff) = 0;
	
	virtual int batteryLevel() = 0;

	virtual bool hasBulbMode() = 0;
	virtual bool canSetBulbMode() = 0;
	virtual bool hasLiveView() = 0;
	virtual bool canStreamLiveView() = 0;

	virtual void initializeLiveView()=0;
	virtual QPixmap *getLiveViewImage() = 0;
	virtual void endLiveView() =0;

	virtual void lockUI() = 0;
	virtual void unlockUI()= 0;
protected:
	virtual void notifypropertychanged(QCameraProperties::QCameraPropertyTypes prop, QVariant value) = 0;

signals:
	void image_captured(QImage image);
	void camera_selected(QCamera *);
	void camera_busy(bool busy);
	void camera_needs_input(QString text);
	void camera_property_changed(QCameraProperties::QCameraPropertyTypes prop, QVariant value);
private:
	
};

#endif // QCAMERA_H
