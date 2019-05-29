import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import "./qt_opencv_samples/flip"

ApplicationWindow {
    visible: true
    width: 1024
    height: 768

    Component {
        id: flipView
        FlipView {}
    }

    Loader {
        anchors.fill: parent
        sourceComponent: flipView
    }
}
