#include "snapshotter.h"

#include <QtDebug>
#include <QOpenGLFramebufferObject>

Snapshotter::Snapshotter(FboQuickView* fboq)
  :QQuickImageProvider(QQmlImageProviderBase::Image)
  ,_fboquickview(fboq)
{
  _image=QImage(40,30,QImage::Format_RGB32);
  _image.fill(0xff888888);
}
  
Snapshotter::~Snapshotter()
{}

QImage Snapshotter::requestImage(const QString& id, QSize *size, const QSize &requestedSize) {
  qDebug() << "Snapshotter: requestImage invoked, id " << id << ", size " << requestedSize;

  _image=_fboquickview->snapshot();
  if (size) *size=_image.size();

  if (requestedSize!=QSize(-1,-1)) {
    _image=_image.scaled(requestedSize);
  }

  return _image;
}

void Snapshotter::snapshot() {
  qDebug() << "Snapshotter: snapshot invoked";
}
