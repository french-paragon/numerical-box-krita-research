#include "specialspinbox.h"

#include <QDebug>
#include <iostream>
#include <QMap>

#include "simplemathexprparser.h"

SpecialSpinBox::SpecialSpinBox(QWidget *parent) : QDoubleSpinBox(parent)
{

}

double SpecialSpinBox::valueFromText(const QString & text) const{

	return utils::parseSimpleMathExpr(text, QMap<QString, double>());

}
QValidator::State SpecialSpinBox::validate ( QString & input, int & pos ) const{

	return QValidator::Acceptable;

}

