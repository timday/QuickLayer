TEMPLATE = app

QT += qml quick

SOURCES += main.cpp snapshotter.cpp
HEADERS += snapshotter.h

RESOURCES += main.qrc

include( ../QuickLayer.pri )

CONFIG += c++11
