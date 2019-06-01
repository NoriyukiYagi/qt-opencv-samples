import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2
import QtOpenCVSamples 1.0

Pane {
    QtObject {
        id: d
        property Blur blur: Blur {}

        property FileDialog fileOpenDialog: FileDialog {
            onAccepted: {
                d.blur.inputFileUrl = d.fileOpenDialog.fileUrl
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
                text: "kernel size:"
                height: slider.height
                verticalAlignment: Text.AlignVCenter
            }
            Label {
                text: d.blur.kernelSize
                height: slider.height
                verticalAlignment: Text.AlignVCenter
            }
            Slider {
                id: slider
                from: 1
                to: 100
                stepSize: 1
                value: d.blur.kernelSize
                onValueChanged: {
                    if (value !== d.blur.kernelSize) {
                        d.blur.kernelSize = value;
                        d.blur.execute();
                    }
                }
            }
        }
        Image {
            id: inputImage
            source: d.blur.inputFileUrl
            onStatusChanged: {
                if (inputImage.status === Image.Ready) {
                    d.blur.execute();
                }
            }
        }
        Image {
            source: d.blur.outputFileUrl
        }
    }
}
