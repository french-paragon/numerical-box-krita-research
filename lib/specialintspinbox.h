#ifndef SPECIALINTSPINBOX_H
#define SPECIALINTSPINBOX_H

#include "simpleexprparser_global.h"

#include <QSpinBox>

class SIMPLEEXPRPARSERSHARED_EXPORT SpecialIntSpinBox : public QSpinBox
{
	Q_OBJECT
public:
	explicit SpecialIntSpinBox(QWidget *parent = 0);
	~SpecialIntSpinBox();

	virtual int valueFromText(const QString & text) const;
	virtual QString textFromValue(int val) const;
	virtual QValidator::State validate ( QString & input, int & pos ) const;

	virtual void stepBy(int steps);

signals:

	//! \brief signal emmitted when the last parsed expression create an error.
	void errorWhileParsing(QString expr) const;
	//! \brief signal emmitted when the last parsed expression is valid.
	void noMoreParsingError() const;

public slots:

	void setErrorStyle();
	void clearErrorStyle();

protected:

	mutable QString* _lastExprParsed;
	mutable bool _isLastValid;
};

#endif // SPECIALINTSPINBOX_H
