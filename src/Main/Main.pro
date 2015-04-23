TARGET   = IQview
CONFIG  += app
LIBS        += $$PWD/../../build/libQGLViewer.a
include (../config.pri)

HEADERS  = multiSelect.h manipulatedFrameSetConstraint.h object.h
SOURCES  = multiSelect.cpp manipulatedFrameSetConstraint.cpp object.cpp main.cpp \
           LoadShader.cpp

QT     *= xml opengl widgets gui
CONFIG += qt opengl warn_on thread rtti console embed_manifest_exe no_keywords

INCLUDEPATH += $$PWD/..


#LIBS        += -LC:/Users/agilbert/Development/extlib/lib -lQGLViewer2
#INCLUDEPATH += C:/Users/agilbert/Development/libQGLViewer-2.5.2/
