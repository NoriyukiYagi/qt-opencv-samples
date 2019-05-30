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

    Grid {
        spacing: 8
        rows: 2
        columns: 2
        Button {
            text: "Select Input File"
            onClicked: {
                d.fileOpenDialog.open();
            }
        }
        Row {
            spacing: 8
            Label {
                text: "angleInDeg:"
                height: slider.height
                verticalAlignment: Text.AlignVCenter
            }
            Label {
                text: d.rotation.angleInDeg
                height: slider.height
                verticalAlignment: Text.AlignVCenter
            }
            Slider {
                id: slider
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
        }
        Image {
            id: inputImage
            source: d.rotation.inputFileUrl
            onStatusChanged: {
                if (inputImage.status === Image.Ready) {
                    d.rotation.execute();
                }
            }
        }
        Image {
            source: d.rotation.outputFileUrl
        }
    }
}
