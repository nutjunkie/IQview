###############################################################################
#
#  This is the main IQview project file.  To use this file type one of the
#  following commands:
#
#     OS X:     qmake -spec macx-g++ -o Makefile IQview.pro
#     Linux:    qmake -unix -o Makefile IQview.pro
#     Windows:  qmake.exe -win32 -o Makefile IQview.pro
#
###############################################################################


CONFIG  += ordered
TEMPLATE = subdirs

SUBDIRS  = src/QGLViewer \
           src/Main \

#SUBDIRS  = src/Main \
           
