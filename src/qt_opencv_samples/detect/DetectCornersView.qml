import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2
import QtOpenCVSamples 1.0

Pane {
    QtObject {
        id: d
        property DetectCorners detectCorners: DetectCorners {}

        property FileDialog fileOpenDialog: FileDialog {
            onAccepted: {
                d.detectCorners.inputFileUrl = d.fileOpenDialog.fileUrl
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
                        text: "MaxCorners:"
                    }
                    Label {
                        text: d.detectCorners.maxCorners.toString()
                    }
                }
                Slider {
                    from: 1
                    to: 1000
                    stepSize: 1
                    value: d.detectCorners.maxCorners
                    onValueChanged: {
                        if (value !== d.detectCorners.maxCorners) {
                            d.detectCorners.maxCorners = value;
                            d.detectCorners.execute();
                        }
                    }
                }
            }
            Column {
                Row {
                    spacing: 4
                    Label {
                        text: "QualityLevel:"
                    }
                    Label {
                        text: d.detectCorners.qualityLevel.toString()
                    }
                }
                Slider {
                    from: 0.001
                    to: 1
                    stepSize: 0.001
                    value: d.detectCorners.qualityLevel
                    onValueChanged: {
                        if (value !== d.detectCorners.qualityLevel) {
                            d.detectCorners.qualityLevel = value;
                            d.detectCorners.execute();
                        }
                    }
                }
            }
            Column {
                Row {
                    spacing: 4
                    Label {
                        text: "MinDistance:"
                    }
                    Label {
                        text: d.detectCorners.minDistance.toString()
                    }
                }
                Slider {
                    from: 0
                    to: 100
                    stepSize: 0.1
                    value: d.detectCorners.minDistance
                    onValueChanged: {
                        if (value !== d.detectCorners.minDistance) {
                            d.detectCorners.minDistance = value;
                            d.detectCorners.execute();
                        }
                    }
                }
            }
        }

        Image {
            id: inputImage
            source: d.detectCorners.inputFileUrl
            onStatusChanged: {
                if (inputImage.status === Image.Ready) {
                    d.detectCorners.execute();
                }
            }
        }

        Item {
            width: childrenRect.width
            height: childrenRect.height
            Image {
                source: d.detectCorners.outputFileUrl
            }
            Repeater {
                model: d.detectCorners.detectedCorners
                delegate: Rectangle {
                    width: 5
                    height: width
                    radius: width * 0.5
                    border.color: "red"
                    border.width: 1
                    x: modelData.x - width/2
                    y: modelData.y - height/2
                }
            }
        }
    }
}
