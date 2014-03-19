/****************************************************************************
** Meta object code from reading C++ file 'mypanelopengl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GoL2/mypanelopengl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mypanelopengl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyPanelOpenGL_t {
    QByteArrayData data[13];
    char stringdata[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MyPanelOpenGL_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MyPanelOpenGL_t qt_meta_stringdata_MyPanelOpenGL = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 7),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 12),
QT_MOC_LITERAL(4, 36, 5),
QT_MOC_LITERAL(5, 42, 6),
QT_MOC_LITERAL(6, 49, 6),
QT_MOC_LITERAL(7, 56, 6),
QT_MOC_LITERAL(8, 63, 5),
QT_MOC_LITERAL(9, 69, 6),
QT_MOC_LITERAL(10, 76, 4),
QT_MOC_LITERAL(11, 81, 12),
QT_MOC_LITERAL(12, 94, 5)
    },
    "MyPanelOpenGL\0process\0\0clicktostart\0"
    "pause\0glider\0pulsar\0gosper\0clear\0"
    "random\0save\0loadlastsave\0reset\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyPanelOpenGL[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08,
       3,    0,   70,    2, 0x08,
       4,    0,   71,    2, 0x08,
       5,    0,   72,    2, 0x08,
       6,    0,   73,    2, 0x08,
       7,    0,   74,    2, 0x08,
       8,    0,   75,    2, 0x08,
       9,    0,   76,    2, 0x08,
      10,    0,   77,    2, 0x08,
      11,    0,   78,    2, 0x08,
      12,    0,   79,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyPanelOpenGL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyPanelOpenGL *_t = static_cast<MyPanelOpenGL *>(_o);
        switch (_id) {
        case 0: _t->process(); break;
        case 1: _t->clicktostart(); break;
        case 2: _t->pause(); break;
        case 3: _t->glider(); break;
        case 4: _t->pulsar(); break;
        case 5: _t->gosper(); break;
        case 6: _t->clear(); break;
        case 7: _t->random(); break;
        case 8: _t->save(); break;
        case 9: _t->loadlastsave(); break;
        case 10: _t->reset(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MyPanelOpenGL::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_MyPanelOpenGL.data,
      qt_meta_data_MyPanelOpenGL,  qt_static_metacall, 0, 0}
};


const QMetaObject *MyPanelOpenGL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyPanelOpenGL::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyPanelOpenGL.stringdata))
        return static_cast<void*>(const_cast< MyPanelOpenGL*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int MyPanelOpenGL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
