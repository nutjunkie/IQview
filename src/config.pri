###############################################################################
#
#  This is the qmake configuration file for IQview.  This file should be 
#  included in all .pro files to ensure consistent settings across the subdirs
#
###############################################################################


QMAKE_CXXFLAGS += -O2 -g -ggdb

# Make much smaller libraries (and packages) by removing debugging informations
QMAKE_CFLAGS_RELEASE -= -g
QMAKE_CXXFLAGS_RELEASE -= -g

CONFIG += no_keywords qt rtti
QT     +=


QT_VERSION=$$[QT_VERSION]

contains( QT_VERSION, "^5.*") {
   cache()
   QT += gui widgets
}

INCLUDEPATH += ../glm

lib {
   TEMPLATE    = lib
   CONFIG     += staticlib
   BUILD_DIR   = ../../build/$$TARGET
   DESTDIR     = ../../build
}

app {
   TEMPLATE    = app
   BUILD_DIR   = ../../build/$$TARGET
   DESTDIR     = ../../build
}


MOC_DIR     = $$BUILD_DIR/moc
UI_DIR      = $$BUILD_DIR/ui
OBJECTS_DIR = $$BUILD_DIR/obj
