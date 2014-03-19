/****************************************************************************
** Meta object code from reading C++ file 'mypanelopengl.h'
**
** Created: Mon Dec 9 13:19:08 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GoL2/mypanelopengl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mypanelopengl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyPanelOpenGL[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      25,   14,   14,   14, 0x08,
      40,   14,   14,   14, 0x08,
      48,   14,   14,   14, 0x08,
      57,   14,   14,   14, 0x08,
      66,   14,   14,   14, 0x08,
      75,   14,   14,   14, 0x08,
      83,   14,   14,   14, 0x08,
      92,   14,   14,   14, 0x08,
      99,   14,   14,   14, 0x08,
     114,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MyPanelOpenGL[] = {
    "MyPanelOpenGL\0\0process()\0clicktostart()\0"
    "pause()\0glider()\0pulsar()\0gosper()\0"
    "clear()\0random()\0save()\0loadlastsave()\0"
    "reset()\0"
};

const QMetaObject MyPanelOpenGL::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_MyPanelOpenGL,
      qt_meta_data_MyPanelOpenGL, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyPanelOpenGL::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyPanelOpenGL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyPanelOpenGL::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyPanelOpenGL))
        return static_cast<void*>(const_cast< MyPanelOpenGL*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int MyPanelOpenGL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: process(); break;
        case 1: clicktostart(); break;
        case 2: pause(); break;
        case 3: glider(); break;
        case 4: pulsar(); break;
        case 5: gosper(); break;
        case 6: clear(); break;
        case 7: random(); break;
        case 8: save(); break;
        case 9: loadlastsave(); break;
        case 10: reset(); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
