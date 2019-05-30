import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2
import QtOpenCVSamples 1.0

Pane {
    QtObject {
        id: d
        property Perspective perspective: Perspective {}

        property FileDialog fileOpenDialog: FileDialog {
            onAccepted: {
                d.perspective.inputFileUrl = d.fileOpenDialog.fileUrl
            }
        }
    }

    Column {
        Button {
            text: "Select Input File"
            onClicked: {
                d.fileOpenDialog.open();
            }
        }

        Item {
            width: childrenRect.width
            height: childrenRect.height

            Image {
                id: inputImage
                source: d.perspective.inputFileUrl
                anchors.left: parent.left
                anchors.top: outputImage.top
                onStatusChanged: {
                    if (inputImage.status === Image.Ready) {
                        d.perspective.destLeftTopX = 0;
                        d.perspective.destLeftTopY = 0;
                        d.perspective.destRightTopX = inputImage.width;
                        d.perspective.destRightTopY = 0;
                        d.perspective.destLeftBottomX = 0;
                        d.perspective.destLeftBottomY = inputImage.height;
                        d.perspective.destRightBottomX = inputImage.width;
                        d.perspective.destRightBottomY = inputImage.height;
                        d.perspective.execute();
                    }
                }
            }

            Image {
                id: outputImage
                width: inputImage.width
                height: inputImage.height
                source: d.perspective.outputFileUrl
                anchors.left: destLeftRangeSlider.right
                anchors.top: destTopRangeSlider.bottom
            }

            RangeSlider {
                id: destTopRangeSlider
                from: 0
                to: inputImage.width
                first.value: d.perspective.destLeftTopX
                first.onValueChanged: {
                    if (first.value !== d.perspective.destLeftTopX) {
                        d.perspective.destLeftTopX = first.value;
                        d.perspective.execute();
                    }
                }
                second.value: d.perspective.destRightTopX
                second.onValueChanged: {
                    if (second.value !== d.perspective.destRightTopX) {
                        d.perspective.destRightTopX = second.value;
                        d.perspective.execute();
                    }
                }
                orientation: Qt.Horizontal
                anchors.top: parent.top
                anchors.left: outputImage.left
                anchors.right: outputImage.right
            }

            RangeSlider {
                id: destLeftRangeSlider
                from: 0
                to: inputImage.height
                rotation: 180
                first.value: d.perspective.destLeftTopY
                first.onValueChanged: {
                    if (first.value !== d.perspective.destLeftTopY) {
                        d.perspective.destLeftTopY = first.value;
                        d.perspective.execute();
                    }
                }
                second.value: d.perspective.destLeftBottomY
                second.onValueChanged: {
                    if (second.value !== d.perspective.destLeftBottomY) {
                        d.perspective.destLeftBottomY = second.value;
                        d.perspective.execute();
                    }
                }
                orientation: Qt.Vertical
                anchors.left: inputImage.right
                anchors.top: outputImage.top
                anchors.bottom: outputImage.bottom
            }

            RangeSlider {
                id: destRightRangeSlider
                from: 0
                to: inputImage.height
                rotation: 180
                first.value: d.perspective.destRightTopY
                first.onValueChanged: {
                    if (first.value !== d.perspective.destRightTopY) {
                        d.perspective.destRightTopY = first.value;
                        d.perspective.execute();
                    }
                }
                second.value: d.perspective.destRightBottomY
                second.onValueChanged: {
                    if (second.value !== d.perspective.destRightBottomY) {
                        d.perspective.destRightBottomY = second.value;
                        d.perspective.execute();
                    }
                }
                orientation: Qt.Vertical
                anchors.left: outputImage.right
                anchors.top: outputImage.top
                anchors.bottom: outputImage.bottom
            }

            RangeSlider {
                id: destBottomRangeSlider
                from: 0
                to: inputImage.width
                first.value: d.perspective.destLeftBottomX
                first.onValueChanged: {
                    if (first.value !== d.perspective.destLeftBottomX) {
                        d.perspective.destLeftBottomX = first.value;
                        d.perspective.execute();
                    }
                }
                second.value: d.perspective.destRightBottomX
                second.onValueChanged: {
                    if (second.value !== d.perspective.destRightBottomX) {
                        d.perspective.destRightBottomX = second.value;
                        d.perspective.execute();
                    }
                }
                orientation: Qt.Horizontal
                anchors.top: outputImage.bottom
                anchors.left: outputImage.left
                anchors.right: outputImage.right
            }
        }
    }
}
