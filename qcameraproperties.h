#ifndef QCAMERAPROPERTIES_H
#define QCAMERAPROPERTIES_H
#include "qcamerainterface_global.h"

#include <QObject>
#include <QMap>

#include "qcameraproperty.h"

class QCAMERAINTERFACE_EXPORT QCameraProperties : public QObject
{
	Q_OBJECT

public: enum QCameraPropertyTypes{
		BatteryLevel,
		ImageTypes,
		ResolutionMode,
		ReleaseMode,
		FocusMode,
		LightMeteringMode,
		FlashMode,
		ExposureMode,
		ExposureTimes,
		SceneMode,
		Iso,
		CaptureMode,
		Resolution,
		DriveMode,
		DateTimeFormat,
		WhiteBalanceMode,
		MirrorAntiShake,
		ColorSpace,
		NoiseReductionMode,
		Aperture,
		WhiteBalance,
		BulbMode
	};

private:
	QMap<QCameraProperties::QCameraPropertyTypes, QCameraProperty*> _properties;
protected:

public:
	QCameraProperties(QObject *parent=0);
	~QCameraProperties();

	void addProperty(QCameraProperties::QCameraPropertyTypes type, QCameraProperty *prop) { _properties.insert(type, prop); }
	void clear(){_properties.clear(); }

	QList<QVariant> getPropertyValues(QCameraProperties::QCameraPropertyTypes prop) { return _properties[prop]->values(); }
	QList<QString> getPropertyKeys(QCameraProperties::QCameraPropertyTypes prop) { return _properties[prop]->keys(); }
	QCameraProperty *getCameraProperty(QCameraProperties::QCameraPropertyTypes prop) { return _properties[prop]; }
	friend class QCamera;

	
};

#endif // QCAMERAPROPERTIES_H
