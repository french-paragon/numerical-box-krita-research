#ifndef SPECIALINTSPINBOX_H
#define SPECIALINTSPINBOX_H

#include "simpleexprparser_global.h"

#include <QSpinBox>

class SIMPLEEXPRPARSERSHARED_EXPORT SpecialIntSpinBox : public QSpinBox
{
	Q_OBJECT
public:
	explicit SpecialIntSpinBox(QWidget *parent = 0);

	virtual int valueFromText(const QString & text) const;
	virtual QValidator::State validate ( QString & input, int & pos ) const;

signals:

public slots:
};

#endif // SPECIALINTSPINBOX_H
