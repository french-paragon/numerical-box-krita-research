#include "specialintspinbox.h"

#include "simplemathexprparser.h"

SpecialIntSpinBox::SpecialIntSpinBox(QWidget *parent) :
	QSpinBox(parent),
  _isLastValid(true)
{
	_lastExprParsed = new QString("0");

	connect(this, SIGNAL(noMoreParsingError()),
			this, SLOT(clearErrorStyle()));
	connect(this, SIGNAL(errorWhileParsing(QString)),
			this, SLOT(setErrorStyle()));

}

SpecialIntSpinBox::~SpecialIntSpinBox(){

	//needed to avoid a segfault during destruction.
	delete _lastExprParsed;

}

int SpecialIntSpinBox::valueFromText(const QString & text) const{

	*_lastExprParsed = text;

	bool ok;

	int val = utils::parseIntegerMathExpr(text, &ok);

	if(text.trimmed().isEmpty()){ //an empty text is considered valid in this case.
		ok = true;
	}

	if(!ok){
		_isLastValid = false;
		//emit errorWhileParsing(text); //if uncommented become red everytime the string is wrong.
	} else {
		_isLastValid = true;
		emit noMoreParsingError();
	}

	return val;

}

QString SpecialIntSpinBox::textFromValue(int val) const{

	if(!_isLastValid){
		emit errorWhileParsing(*_lastExprParsed);
		return *_lastExprParsed;
	}

	return QSpinBox::textFromValue(val);

}

QValidator::State SpecialIntSpinBox::validate ( QString & input, int & pos ) const{

	return QValidator::Acceptable;

}

void SpecialIntSpinBox::stepBy(int steps){

	_isLastValid = true;
	emit noMoreParsingError();

	QSpinBox::stepBy(steps);

}

void SpecialIntSpinBox::setErrorStyle(){
	setStyleSheet("Background: red; color: white;");
}

void SpecialIntSpinBox::clearErrorStyle(){
	setStyleSheet("");
}

