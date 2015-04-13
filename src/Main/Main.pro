TARGET   = IQview
CONFIG  += app
include (../config.pri)

HEADERS  = multiSelect.h manipulatedFrameSetConstraint.h object.h
SOURCES  = multiSelect.cpp manipulatedFrameSetConstraint.cpp object.cpp main.cpp \
           LoadShader.cpp

QT     *= xml opengl widgets gui
CONFIG += qt opengl warn_on thread rtti console embed_manifest_exe no_keywords

INCLUDEPATH += $$PWD/..
LIBS        += $$PWD/../../build/libQGLViewer.a
