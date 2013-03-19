#include "qcameraproperty.h"

QCameraProperty::QCameraProperty(QString propName)
	
{
	_name = propName;
}

QCameraProperty::~QCameraProperty()
{

}

QMap<QString, QVariant> QCameraProperty::keyvaluepairs()
 {
	QMap<QString, QVariant> temp;

	for(int i=0; i < _values.count(); i++)
	{
		temp.insert(_keys.at(i), _values.at(i));
	}

	return temp;
}
