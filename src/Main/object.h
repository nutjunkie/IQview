/****************************************************************************

 Copyright (C) 2002-2014 Gilles Debunne. All rights reserved.

 This file is part of the QGLViewer library version 2.6.1.

 http://www.libqglviewer.com - contact@libqglviewer.com

 This file may be used under the terms of the GNU General Public License 
 versions 2.0 or 3.0 as published by the Free Software Foundation and
 appearing in the LICENSE file included in the packaging of this file.
 In addition, as a special exception, Gilles Debunne gives you certain 
 additional rights, described in the file GPL_EXCEPTION in this package.

 libQGLViewer uses dual licensing. Commercial/proprietary software must
 purchase a libQGLViewer Commercial License.

 This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

*****************************************************************************/

#ifndef OBJECT_H_
#define OBJECT_H_

#include "QGLViewer/frame.h"

class QGLContext;


class Object
{
   public :
      Object(QGLContext*);
      ~Object();
      void draw() const;
      void setProgram(GLuint const program) { m_programID = program; }
      qglviewer::Frame frame;
   private:
      void drawObject() const;
      void drawTriangle() const;
      static const GLfloat s_vertexBufferData[9];
      GLuint m_vertexBuffer;
      GLuint m_programID;
      QGLContext* m_context;
};

#endif // OBJECT_H_
