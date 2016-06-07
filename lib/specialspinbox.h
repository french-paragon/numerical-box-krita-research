#ifndef SPECIALSPINBOX_H
#define SPECIALSPINBOX_H

#include "simpleexprparser_global.h"

#include <QDoubleSpinBox>

class SIMPLEEXPRPARSERSHARED_EXPORT SpecialSpinBox : public QDoubleSpinBox
{
	Q_OBJECT
public:
	explicit SpecialSpinBox(QWidget *parent = 0);
	~SpecialSpinBox();

	virtual double valueFromText(const QString & text) const;
	virtual QString textFromValue(double val) const;
	virtual QValidator::State validate ( QString & input, int & pos ) const;

	virtual void stepBy(int steps);

signals:

	//! \brief signal emmitted when the last parsed expression create an error.
	void errorWhileParsing(QString expr) const;
	//! \brief signal emmitted when the last parsed expression is valid.
	void noMoreParsingError() const;

public slots:

protected:

	mutable QString _lastExprParsed;
	mutable bool _isLastValid;
};

#endif // SPECIALSPINBOX_H
