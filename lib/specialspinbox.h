#ifndef SPECIALSPINBOX_H
#define SPECIALSPINBOX_H

#include "simpleexprparser_global.h"

#include <QDoubleSpinBox>

class SIMPLEEXPRPARSERSHARED_EXPORT SpecialSpinBox : public QDoubleSpinBox
{
	Q_OBJECT
public:
	explicit SpecialSpinBox(QWidget *parent = 0);

	virtual double valueFromText(const QString & text) const;
	virtual QValidator::State validate ( QString & input, int & pos ) const;

signals:

public slots:

protected:
};

#endif // SPECIALSPINBOX_H
