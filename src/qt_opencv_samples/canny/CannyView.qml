import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2
import QtOpenCVSamples 1.0

Pane {
    QtObject {
        id: d
        property Canny canny: Canny {}

        property FileDialog fileOpenDialog: FileDialog {
            onAccepted: {
                d.canny.inputFileUrl = d.fileOpenDialog.fileUrl
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

        Row {
            spacing: 4
            Column {
                Row {
                    spacing: 4
                    Label {
                        text: "Threshold:"
                    }
                    Label {
                        text: d.canny.threshold1.toString()
                    }
                    Label {
                        text: d.canny.threshold2.toString()
                    }
                }
                RangeSlider {
                    from: 0
                    to: 255
                    stepSize: 1
                    first.value: d.canny.threshold1
                    first.onValueChanged: {
                        if (first.value !== d.canny.threshold1) {
                            d.canny.threshold1 = first.value;
                            d.canny.execute();
                        }
                    }
                    second.value: d.canny.threshold2
                    second.onValueChanged: {
                        if (second.value !== d.canny.threshold2) {
                            d.canny.threshold2 = second.value;
                            d.canny.execute();
                        }
                    }
                }
            }
            Switch {
                text: qsTr("Equalize")
                checked: d.canny.equalize
                onCheckedChanged: {
                    if (checked !== d.canny.equalize) {
                        d.canny.equalize = checked;
                        d.canny.execute();
                    }
                }
            }
        }

        Image {
            id: inputImage
            source: d.canny.inputFileUrl
            onStatusChanged: {
                if (inputImage.status === Image.Ready) {
                    d.canny.execute();
                }
            }
        }

        Image {
            source: d.canny.outputFileUrl
        }
    }
}
