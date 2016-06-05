#include "specialspinbox.h"

#include <QDebug>
#include <iostream>
#include <QMap>

#include "simplemathexprparser.h"

SpecialSpinBox::SpecialSpinBox(QWidget *parent) :
	QDoubleSpinBox(parent),
	_lastExprParsed("0.0"),
	_isLastValid(true)
{

}
SpecialSpinBox::~SpecialSpinBox(){

	//needed to avoid a segfault during destruction.
	_isLastValid = true;

}

double SpecialSpinBox::valueFromText(const QString & text) const{

	_lastExprParsed = text;

	bool ok;

	double ret = utils::parseSimpleMathExpr(text, QMap<QString, double>(), &ok);

		if(!ok){
			_isLastValid = false;
			emit errorWhileParsing(text);
			return ret;
		} else {

			_isLastValid = true;
			emit errorWhileParsing(text);
			return ret;
		}

	return ret;

}
QString SpecialSpinBox::textFromValue(double val) const{

	if(!_isLastValid){
		return _lastExprParsed;
	}

	return QString("%1").arg(val);

}

QValidator::State SpecialSpinBox::validate ( QString & input, int & pos ) const{

	return QValidator::Acceptable;

}

