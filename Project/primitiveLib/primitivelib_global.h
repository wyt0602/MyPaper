#ifndef PRIMITIVELIB_GLOBAL_H
#define PRIMITIVELIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PRIMITIVELIB_LIBRARY)
#  define PRIMITIVELIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define PRIMITIVELIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#ifdef Q_OS_WIN
#define MY_EXPORT __declspec(dllexport)
#else
#define MY_EXPORT
#endif

#endif // PRIMITIVELIB_GLOBAL_H
