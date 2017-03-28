import QtQuick 2.7
import QtQuick.Controls 2.0

ApplicationWindow {
    readonly property alias pageStack: stackView

    id: app
    visible: true
    width: 768
    height: 1280
    color: Style.windowBackground

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: AlbumListPage {}
    }

    onClosing: {
        if ( Qt.platform.os == "android" ) {
            if ( stackView.depth > 1 ) {
                close.accepted = false
                stackView.pop()
            }
        }
    }
}
