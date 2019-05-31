import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2
import QtOpenCVSamples 1.0

Pane {
    QtObject {
        id: d
        property Threshold threshold: Threshold {}

        property FileDialog fileOpenDialog: FileDialog {
            onAccepted: {
                d.threshold.inputFileUrl = d.fileOpenDialog.fileUrl
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
            source: d.threshold.inputFileUrl
            onStatusChanged: {
                if (inputImage.status === Image.Ready) {
                    d.threshold.execute();
                }
            }
        }
        Grid {
            spacing: 8
            columns: 2
            rows: 2
            Label {
                text: "Grayscale"
            }
            Row {
                spacing: 4
                Label {
                    text: "Thresh:"
                }
                Label {
                    text: d.threshold.thresh.toString()
                }
                Slider {
                    from: 0
                    to: 255
                    stepSize: 1
                    value: d.threshold.thresh
                    onValueChanged: {
                        if (value !== d.threshold.thresh) {
                            d.threshold.thresh = value;
                            d.threshold.execute();
                        }
                    }
                }
            }
            Image {
                source: d.threshold.output1FileUrl
            }
            Image {
                source: d.threshold.output2FileUrl
            }
        }
    }
}
