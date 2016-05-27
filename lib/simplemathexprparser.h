#ifndef SIMPLEMATHEXPRPARSER_H
#define SIMPLEMATHEXPRPARSER_H

#include "simpleexprparser_global.h"

#include <QString>
#include <QMap>

namespace utils {

	SIMPLEEXPRPARSERSHARED_EXPORT double parseSimpleMathExpr(QString const& expr,
									  QMap<QString, double> const& vars,
									  bool* ok = 0);

	SIMPLEEXPRPARSERSHARED_EXPORT int parseIntegerMathExpr(QString const& expr, bool* ok = 0);
};

#endif // SIMPLEMATHEXPRPARSER_H
