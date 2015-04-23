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

#include "multiSelect.h"
#include <qapplication.h>
#include <QGLFramebufferObject>
#include <QGLFormat>
#include <QtDebug>


int main(int argc, char** argv)
{
  QApplication application(argc,argv);

  QGLFormat glFormat(QGL::SampleBuffers);
qDebug() << "Starting application";

 glFormat.setVersion( 3, 3 );
 glFormat.setProfile( QGLFormat::CoreProfile ); // Requires >=Qt-4.8.0
 glFormat.setSampleBuffers( true );
qDebug() << "GLFormat set";

  QGLContext context(glFormat);
  context.makeCurrent();
  
qDebug() << "context created";

  Viewer viewer(&context);
  viewer.setWindowTitle("multiSelect");
qDebug() << "about to show window";
  viewer.show();

  qDebug() << QGLFormat::openGLVersionFlags();

  return application.exec();
}
