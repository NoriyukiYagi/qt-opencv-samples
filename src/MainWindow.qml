import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import "./qt_opencv_samples/flip"
import "./qt_opencv_samples/rotation"
import "./qt_opencv_samples/perspective"
import "./qt_opencv_samples/equalize"

ApplicationWindow {
    visible: true
    width: 1152
    height: 864

    QtObject {
        id: d
        property variant titles: [
            "Flip",
            "Rotation",
            "Perspective",
            "Equalize"
        ]
        property list<Component> components: [
            Component {
                FlipView {}
            },
            Component {
                RotationView {}
            },
            Component {
                PerspectiveView {}
            },
            Component {
                EqualizeView {}
            }
        ]
    }

    header: Pane {
        Row {
            spacing: 4
            Label {
                text: "Select Component:"
                anchors.baseline: selection.baseline
            }
            ComboBox {
                id: selection
                model: d.titles
                displayText: d.titles[currentIndex]
            }
        }
    }

    ScrollView {
        anchors.fill: parent
        Loader {
            sourceComponent: d.components[selection.currentIndex]
        }
    }
}
