import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2
import QtOpenCVSamples 1.0

Pane {
    QtObject {
        id: d
        property Flip flip: Flip {}

        property FileDialog fileOpenDialog: FileDialog {
            onAccepted: {
                d.flip.inputFileUrl = d.fileOpenDialog.fileUrl
            }
        }
    }

    Label {
        text: "FlipView"
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
            source: d.flip.inputFileUrl
        }
        Row {
            spacing: 8
            Label {
                id: flipCodeLabel
                text: "flipCode:"
            }
            Label {
                text: d.flip.flipCode
            }
        }
        Slider {
            from: -1
            to: 1
            stepSize: 1
            value: d.flip.flipCode
            onValueChanged: {
                if (value != d.flip.flipCode) {
                    d.flip.flipCode = value;
                }
            }
        }
        Button {
            text: "Execute Flip"
            onClicked: {
                d.flip.execute();
            }
        }
        Image {
            source: d.flip.outputFileUrl
        }
    }
}
