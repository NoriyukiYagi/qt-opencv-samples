import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import "./qt_opencv_samples/flip"
import "./qt_opencv_samples/rotation"
import "./qt_opencv_samples/perspective"
import "./qt_opencv_samples/equalize"
import "./qt_opencv_samples/threshold"
import "./qt_opencv_samples/blur"
import "./qt_opencv_samples/detect"

ApplicationWindow {
    visible: true
    width: 1152
    height: 864

    QtObject {
        id: d
        property variant views: [
            ["Flip", "./qt_opencv_samples/flip/FlipView.qml"],
            ["Rotation", "./qt_opencv_samples/rotation/RotationView.qml"],
            ["Perspective", "./qt_opencv_samples/perspective/PerspectiveView.qml"],
            ["Equalize", "./qt_opencv_samples/equalize/EqualizeView.qml"],
            ["Threshold", "./qt_opencv_samples/threshold/ThresholdView.qml"],
            ["Blur", "./qt_opencv_samples/blur/BlurView.qml"],
            ["Canny", "./qt_opencv_samples/canny/CannyView.qml"],
            ["Corners", "./qt_opencv_samples/detect/DetectCornersView.qml"],
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
                model: d.views
                displayText: d.views[currentIndex][0].toString()
                delegate: ItemDelegate {
                    text: modelData[0].toString()
                }
            }
        }
    }

    ScrollView {
        anchors.fill: parent
        Loader {
            source: d.views[selection.currentIndex][1].toString()
        }
    }
}
