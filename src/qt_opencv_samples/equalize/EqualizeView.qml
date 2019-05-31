import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2
import QtOpenCVSamples 1.0

Pane {
    QtObject {
        id: d
        property Equalize equalize: Equalize {}

        property FileDialog fileOpenDialog: FileDialog {
            onAccepted: {
                d.equalize.inputFileUrl = d.fileOpenDialog.fileUrl
            }
        }
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
            id: inputImage
            source: d.equalize.inputFileUrl
            onStatusChanged: {
                if (inputImage.status === Image.Ready) {
                    d.equalize.execute();
                }
            }
        }
        Row {
            spacing: 8
            Column {
                spacing: 4
                Label {
                    text: "Grayscale"
                }
                Image {
                    source: d.equalize.output1FileUrl
                }
            }
            Column {
                spacing: 4
                Label {
                    text: "Equalized"
                }
                Image {
                    source: d.equalize.output2FileUrl
                }
            }
        }
    }
}
