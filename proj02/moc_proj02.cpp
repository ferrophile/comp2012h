/****************************************************************************
** Meta object code from reading C++ file 'proj02.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "proj02.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'proj02.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tetris[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x0a,
      26,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Tetris[] = {
    "Tetris\0\0move_block_down()\0update_map()\0"
};

void Tetris::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Tetris *_t = static_cast<Tetris *>(_o);
        switch (_id) {
        case 0: _t->move_block_down(); break;
        case 1: _t->update_map(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Tetris::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Tetris::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Tetris,
      qt_meta_data_Tetris, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tetris::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tetris::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tetris::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tetris))
        return static_cast<void*>(const_cast< Tetris*>(this));
    return QWidget::qt_metacast(_clname);
}

int Tetris::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
