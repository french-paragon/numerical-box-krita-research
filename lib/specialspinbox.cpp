#include "specialspinbox.h"

#include <QDebug>
#include <iostream>
#include <QMap>

#include "simplemathexprparser.h"

SpecialSpinBox::SpecialSpinBox(QWidget *parent) :
	QDoubleSpinBox(parent),
	_isLastValid(true)
{
	_lastExprParsed = new QString("0.0");

	connect(this, SIGNAL(noMoreParsingError()),
			this, SLOT(clearErrorStyle()));
	connect(this, SIGNAL(errorWhileParsing(QString)),
			this, SLOT(setErrorStyle()));

}
SpecialSpinBox::~SpecialSpinBox(){

	//needed to avoid a segfault during destruction.
	delete _lastExprParsed;

}

double SpecialSpinBox::valueFromText(const QString & text) const{

	*_lastExprParsed = text;

	bool ok;

	double ret = utils::parseSimpleMathExpr(text, QMap<QString, double>(), &ok);

		if(!ok){
			_isLastValid = false;
			//emit errorWhileParsing(_lastExprParsed); //if uncommented become red everytime the string is wrong.
			return ret;
		} else {

			_isLastValid = true;
			emit noMoreParsingError();
			return ret;
		}

	return ret;

}
QString SpecialSpinBox::textFromValue(double val) const{

	if(!_isLastValid){
		emit errorWhileParsing(*_lastExprParsed);
		return *_lastExprParsed;
	}

	return QDoubleSpinBox::textFromValue(val);

}

QValidator::State SpecialSpinBox::validate ( QString & input, int & pos ) const{

	return QValidator::Acceptable;

}

void SpecialSpinBox::stepBy(int steps){

	_isLastValid = true; //reset to valid state so we can use the up and down buttons.
	emit noMoreParsingError();

	QDoubleSpinBox::stepBy(steps);

}

void SpecialSpinBox::setErrorStyle(){
	if(!_isLastValid){
		setStyleSheet("Background: red; color: white;");
	}
}

void SpecialSpinBox::clearErrorStyle(){
	if(_isLastValid){
		setStyleSheet("");
	}
}

