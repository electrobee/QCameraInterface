#ifndef QCAMERAPROPERTY_H
#define QCAMERAPROPERTY_H

#include <QObject>
#include <QVariant>

#include "qcamerainterface_global.h"


class QCAMERAINTERFACE_EXPORT QCameraProperty 
{
private:
	QList<QString> _keys;
	QList<QVariant> _values;
	QVariant _currentValue;
	QString _name;
	int opcode;

public:
	QCameraProperty(QString propName="");
	~QCameraProperty();

	QList<QVariant> values() { return _values; }
	QList<QString> keys() { return _keys; }
	QMap<QString,QVariant> keyvaluepairs();
	QVariant value() { return _currentValue; }
	QVariant value(QString key) { int index = _keys.indexOf(key); return _values.at(index); }
	void setCurrentValue(QVariant value) { _currentValue = value; }
	void appendValue(QString name, QVariant value) { _values.append(value); _keys.append(name); }
	
};

#endif // QCAMERAPROPERTY_H
