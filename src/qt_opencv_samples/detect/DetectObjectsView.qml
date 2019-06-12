import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2
import QtOpenCVSamples 1.0

Pane {
    QtObject {
        id: d
        property DetectObjects detectObjects: DetectObjects {}

        property FileDialog fileOpenDialog: FileDialog {
            onAccepted: {
                d.detectObjects.inputFileUrl = d.fileOpenDialog.fileUrl
            }
        }
    }

    Grid {
        spacing: 8
        columns: 2
        rows: 2

        Button {
            text: "Select Input File"
            onClicked: {
                d.fileOpenDialog.open();
            }
        }

        ComboBox {
            width: 500
            model: d.detectObjects.cascadeFileUrls
            onCurrentIndexChanged: {
                d.detectObjects.cascadeFileUrl = model[currentIndex];
                d.detectObjects.execute();
            }
        }

        Image {
            id: inputImage
            source: d.detectObjects.inputFileUrl
            onStatusChanged: {
                if (inputImage.status === Image.Ready) {
                    d.detectObjects.execute();
                }
            }
        }

        Item {
            width: childrenRect.width
            height: childrenRect.height
            Image {
                source: d.detectObjects.outputFileUrl
            }
            Repeater {
                model: d.detectObjects.detectedObjects
                delegate: Rectangle {
                    border.color: "red"
                    border.width: 1
                    color: "transparent"
                    x: modelData.x
                    y: modelData.y
                    width: modelData.width
                    height: modelData.height
                }
            }
        }
    }
}
