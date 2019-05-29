import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2
import QtOpenCVSamples 1.0

Pane {
    QtObject {
        id: d
        property Rotation rotation: Rotation {}

        property FileDialog fileOpenDialog: FileDialog {
            onAccepted: {
                d.rotation.inputFileUrl = d.fileOpenDialog.fileUrl
            }
        }
    }

    Label {
        text: "RotationView"
    }

    Column {
        spacing: 8
        Button {
            text: "Select Input File"
            onClicked: {
                d.fileOpenDialog.open();
            }
        }
        Image {
            source: d.rotation.inputFileUrl
        }
        Row {
            spacing: 8
            Label {
                text: "angleInDeg:"
            }
            Label {
                text: d.rotation.angleInDeg
            }
        }
        Slider {
            from: -360
            to: 360
            stepSize: 1
            value: d.rotation.angleInDeg
            onValueChanged: {
                if (value !== d.rotation.angleInDeg) {
                    d.rotation.angleInDeg = value;
                    d.rotation.execute();
                }
            }
        }
        Image {
            source: d.rotation.outputFileUrl
        }
    }
}
