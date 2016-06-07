#include "specialintspinbox.h"

#include "simplemathexprparser.h"

SpecialIntSpinBox::SpecialIntSpinBox(QWidget *parent) :
	QSpinBox(parent),
  _lastExprParsed("0"),
  _isLastValid(true)
{

}

SpecialIntSpinBox::~SpecialIntSpinBox(){

	//needed to avoid a segfault during destruction.
	_isLastValid = true;

}

int SpecialIntSpinBox::valueFromText(const QString & text) const{

	_lastExprParsed = text;

	bool ok;

	int val = utils::parseIntegerMathExpr(text, &ok);

	if(text.trimmed().isEmpty()){ //an empty text is considered valid in this case.
		ok = true;
	}

	if(!ok){
		_isLastValid = false;
		emit errorWhileParsing(text);
	} else {
		_isLastValid = true;
		emit noMoreParsingError();
	}

	return val;

}

QString SpecialIntSpinBox::textFromValue(int val) const{

	if(!_isLastValid){
		return QString(_lastExprParsed.toLatin1());
	}

	return QSpinBox::textFromValue(val);

}

QValidator::State SpecialIntSpinBox::validate ( QString & input, int & pos ) const{

	return QValidator::Acceptable;

}

void SpecialIntSpinBox::stepBy(int steps){

	_isLastValid = true;

	QSpinBox::stepBy(steps);

}

