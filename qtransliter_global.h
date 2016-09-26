#ifndef QTRANSLITER_GLOBAL_H
#define QTRANSLITER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QTRANSLITER_LIBRARY)
#  define QTRANSLITERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QTRANSLITERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QTRANSLITER_GLOBAL_H
