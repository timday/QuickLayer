import QtQuick 2.0

Rectangle {
  id: main
 
  color: 'black'

  Image {
    id: image
    anchors.fill: parent
    anchors.margins: 40
    source: 'image://snapshotter/'+frame  // Hack to get image provider called again
    property int frame: 0
  }

  Text {
    anchors.top: main.top
    anchors.horizontalCenter: main.horizontalCenter
    text: 'Offscreen rendering in progress (hopefully).\nClick to capture and show a snapshot...'
    color: 'yellow'
  }

  Text {
    anchors.bottom: main.bottom
    anchors.horizontalCenter: main.horizontalCenter
    text: 'Offscreen image was '+image.sourceSize.width+'x'+image.sourceSize.height
    color: 'yellow'
  }


  MouseArea {
    objectName: "clickme"
    anchors.fill: parent

    signal snapshot
    onClicked: {snapshot();image.frame++;}
  }

}
