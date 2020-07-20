#ifndef __snapshotter_h__
#define __snapshotter_h__

#include <QQuickImageProvider>

#include "../FboQuickView.h"

class Snapshotter: public QObject, public QQuickImageProvider {
    Q_OBJECT
public:

    Snapshotter(FboQuickView*);
  
    ~Snapshotter();

    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize);
                  
  public slots:

    void snapshot();

  private:

    QImage _image;
    FboQuickView* _fboquickview;
};

#endif
