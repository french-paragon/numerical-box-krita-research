#ifndef SIMPLEEXPRPARSER_GLOBAL_H
#define SIMPLEEXPRPARSER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SIMPLEEXPRPARSER_LIBRARY)
#  define SIMPLEEXPRPARSERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define SIMPLEEXPRPARSERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // SIMPLEEXPRPARSER_GLOBAL_H
