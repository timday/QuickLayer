#include <QtDebug>
#include <QGuiApplication>
#include <QOpenGLContext>
#include <QQuickItem>
#include <QQuickView>

#include "FboQuickView.h"
//#include "FboQuickWrapperWindow.h"

#include "snapshotter.h"

int main( int argc, char *argv[] )
{
    QGuiApplication app( argc, argv );

    QSize onscreen_size( 640, 480 );
    QSize offscreen_size( 3840, 2160 );

    QOpenGLContext* context = new QOpenGLContext;
    context->create();
    FboQuickView fboQuickView( context );
    fboQuickView.resize( offscreen_size );
    fboQuickView.setSource( QUrl( QStringLiteral( "qrc:/demo.qml" ) ) );

    //FboQuickWrapperWindow window( &fboQuickView );
    //window.resize( onscreen_size );
    //window.show();

    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);

    Snapshotter* snapshotter=new Snapshotter(&fboQuickView);
    QQmlEngine *engine = view.engine();
    engine->addImageProvider(QLatin1String("snapshotter"),snapshotter);

    view.setSource( QUrl( QStringLiteral( "qrc:/main.qml" ) ) );
    view.resize(onscreen_size);
    view.show();
    
    QObject* item=view.rootObject()->findChild<QObject*>("clickme");
    QObject::connect(
      item,SIGNAL(snapshot()),
      snapshotter,SLOT(snapshot())
    );
    
    return app.exec();
}
