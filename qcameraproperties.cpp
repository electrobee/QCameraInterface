#include "qcameraproperties.h"

QCameraProperties::QCameraProperties(QObject *parent)
	: QObject(parent)
{

}

QCameraProperties::~QCameraProperties()
{

}

QList<QVariant> QCameraProperties::getPropertyValues(QCameraProperties::QCameraPropertyTypes prop) { 
	return (_properties.empty() ?  QList<QVariant>() : _properties[prop]->values());
}
