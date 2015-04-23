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

#include <qgl.h>
#include "object.h"
#include <QtDebug>
#include <QGLFunctions>
#include <QGLContext>

using namespace qglviewer;


// An array of 3 vectors which represents 3 vertices
const GLfloat Object::s_vertexBufferData[] = 
{
   -1.0f, -1.0f, 0.0f,
   1.0f, -1.0f, 0.0f,
   0.0f,  1.0f, 0.0f,
};

  
Object::Object(QGLContext* context) : m_programID(0), m_context(context)
{
   QGLFunctions f(m_context);
   // Generate 1 buffer, put the resulting identifier in m_vertexbuffer
   f.glGenBuffers(1, &m_vertexBuffer);
   // The following commands will talk about our 'm_vertexbuffer' buffer
   f.glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
   // Give our vertices to OpenGL.
   f.glBufferData(GL_ARRAY_BUFFER, sizeof(s_vertexBufferData), s_vertexBufferData, GL_STATIC_DRAW);
}


void Object::draw() const
{
  //glPushMatrix();
  //glMultMatrixd(frame.matrix());
  //GLuint matrixLocation = glGetUniformLocation(m_programID, "MVP");
  //glUniformMatrix4fv(matrixLocation, 1, GL_FALSE, m);
  //drawTriangle();
  drawObject();
  //glPopMatrix();
}


void Object::drawObject() const
{
  static GLUquadric* quad = gluNewQuadric();
  gluSphere(quad, 0.03, 10, 6);
  gluCylinder(quad, 0.03, 0.0, 0.09, 10, 1);
}


void Object::drawTriangle() const
{
   QGLFunctions f(m_context);
   // 1rst attribute buffer : vertices
   //glEnableVertexAttribArray(0);
   f.glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
   f.glVertexAttribPointer(
      0,        // attribute 0. No particular reason for 0, but must match the layout in the shader.
      3,        // size
      GL_FLOAT, // type
      GL_FALSE, // normalized?
      0,        // stride
      (void*)0  // array buffer offset
   );
   glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
   //glDisableVertexAttribArray(0);
}


