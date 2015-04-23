TARGET  = QGLViewer
CONFIG += lib
include (../config.pri)

CONFIG *= opengl warn_on thread 
QT     *= xml opengl

DEFINES += QGLVIEWER_STATIC

HEADERS = \
      qglviewer.h \
	  camera.h \
	  manipulatedFrame.h \
	  manipulatedCameraFrame.h \
	  frame.h \
	  constraint.h \
	  keyFrameInterpolator.h \
	  mouseGrabber.h \
	  quaternion.h \
	  vec.h \
	  domUtils.h \
	  config.h

SOURCES = \
      qglviewer.cpp \
	  camera.cpp \
	  manipulatedFrame.cpp \
	  manipulatedCameraFrame.cpp \
	  frame.cpp \
	  saveSnapshot.cpp \
	  constraint.cpp \
	  keyFrameInterpolator.cpp \
	  mouseGrabber.cpp \
	  quaternion.cpp \
	  vec.cpp

FORMS *= ImageInterface.ui

DISTFILES *= qglviewer-icon.xpm

# ---------------------------------------------
# --  V e c t o r i a l   R e n d e r i n g  --
# ---------------------------------------------
# In case of compilation troubles with vectorial rendering, uncomment this line
# DEFINES *= NO_VECTORIAL_RENDER

contains( DEFINES, NO_VECTORIAL_RENDER ) {
  message( Vectorial rendering disabled )
} else {
  FORMS *= VRenderInterface.ui

  SOURCES *= \
	VRender/BackFaceCullingOptimizer.cpp \
	VRender/BSPSortMethod.cpp \
	VRender/EPSExporter.cpp \
	VRender/Exporter.cpp \
	VRender/FIGExporter.cpp \
	VRender/gpc.cpp \
	VRender/ParserGL.cpp \
	VRender/Primitive.cpp \
	VRender/PrimitivePositioning.cpp \
	VRender/TopologicalSortMethod.cpp \
	VRender/VisibilityOptimizer.cpp \
	VRender/Vector2.cpp \
	VRender/Vector3.cpp \
	VRender/NVector3.cpp \
	VRender/VRender.cpp

  VRENDER_HEADERS = \
	VRender/AxisAlignedBox.h \
	VRender/Exporter.h \
	VRender/gpc.h \
	VRender/NVector3.h \
	VRender/Optimizer.h \
	VRender/ParserGL.h \
	VRender/Primitive.h \
	VRender/PrimitivePositioning.h \
	VRender/SortMethod.h \
	VRender/Types.h \
	VRender/Vector2.h \
	VRender/Vector3.h \
	VRender/VRender.h

  HEADERS *= $${VRENDER_HEADERS}
}
