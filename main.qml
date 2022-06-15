import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.0

Window {
    width: 800
    height: 400
    visible: true
    title: "Available Restaurants"

    Row {
        width: parent.width
        height: parent.height
        spacing: 5

        Item {
            width: parent.width/2
            height: parent.height

            Text {
                id: label
                text: "Select the hour"
                font.family: "Arial"
                font.pixelSize: 35
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
                onClicked: {
                    myListView.model.clear()
                    let availableRestaurants = restaurantController.available(hourInput.text)
                    if (availableRestaurants.length === 0) {
                        myListView.model.append({ restaurant: "There are no available restaurants at this time!" })
                    }
                    for (let i = 0; i<availableRestaurants.length; i++) {
                        myListView.model.append({ restaurant: i + " - " + availableRestaurants[i] });
                    }
                }
            }
        }

        Column {
            width: parent.width/2
            height: parent.height
            ListView {
                id: myListView
                anchors.fill: parent
                anchors.top: availableLabel.bottom
                model: ListModel {}
                spacing: 5
                delegate: Text {
                    text: restaurant
                    font.pointSize: 12
                }
            }
        }
    }
}
