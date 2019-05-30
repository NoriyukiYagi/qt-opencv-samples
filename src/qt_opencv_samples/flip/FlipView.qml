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
                text: "flipCode:"
                height: slider.height
                verticalAlignment: Text.AlignVCenter
            }
            Label {
                text: d.flip.flipCode
                height: slider.height
                verticalAlignment: Text.AlignVCenter
            }
            Slider {
                id: slider
                from: -1
                to: 1
                stepSize: 1
                value: d.flip.flipCode
                onValueChanged: {
                    if (value !== d.flip.flipCode) {
                        d.flip.flipCode = value;
                        d.flip.execute();
                    }
                }
            }
        }
        Image {
            source: d.flip.inputFileUrl
        }
        Image {
            source: d.flip.outputFileUrl
        }
    }
}
