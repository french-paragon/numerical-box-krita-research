#include "specialintspinbox.h"

#include "simplemathexprparser.h"

SpecialIntSpinBox::SpecialIntSpinBox(QWidget *parent) :
	QSpinBox(parent)
{

}

int SpecialIntSpinBox::valueFromText(const QString & text) const{

	return utils::parseIntegerMathExpr(text);

}
QValidator::State SpecialIntSpinBox::validate ( QString & input, int & pos ) const{

	return QValidator::Acceptable;

}

