import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.0

Window {
    width: 400
    height: 250
    visible: true
    title: "Available Restaurants"
    Column {
            width: parent.width
            height: parent.height
            spacing: 5
            Text {
                id: label
                text: "Select the hour"
                font.family: "Arial"
                font.pixelSize: 50
                font.bold: true
                anchors.bottomMargin: 10
                anchors.horizontalCenter: parent.horizontalCenter
            }
            TextField {
                id: hourInput
                width: 160
                anchors.top: label.bottom
                placeholderText: "e.g.: 9:37 or 16:43"
                font.pixelSize: 16
                font.family: "Arial"
                anchors.horizontalCenter: parent.horizontalCenter
            }
            Button {
                text: "Search"
                font.family: "Arial"
                font.pixelSize: 16
                anchors.top: hourInput.bottom
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
}
