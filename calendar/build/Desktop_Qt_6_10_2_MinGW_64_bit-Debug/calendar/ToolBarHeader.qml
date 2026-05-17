import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs


ToolBar {
    id: toolBar
    property string reportPath: ""
    property var stack
    implicitHeight: 72

    background: Rectangle {
                     color: "#071a3d"
                 }

    Label {
            id: timeLabel
            text: "00:00"
            anchors.right: parent.right
            anchors.rightMargin: 100
            anchors.verticalCenter: parent.verticalCenter
           font.pixelSize: 18
            color: "white"
        }
        Connections {
            target: networkService
            function onTimeReceived(timeString) {
                timeLabel.text = timeString
            }
        }
        Timer {
            interval: 1000
            running: true
            repeat: true
            triggeredOnStart: true
            onTriggered: networkService.fetchTime()
        }
    MessageDialog {
        id: reportSuccessDialog
        title: "info"
        text: "Звіт згенеровано!"
        buttons: MessageDialog.Ok
    }
    MessageDialog {
        id: confirmPartialSaveDialog

        title: "Підтвердження"

        text: "У деяких працівників не заповнені дати. Зберегти звіт?"

        buttons: MessageDialog.Yes | MessageDialog.No

        onAccepted: {
            reportSuccessDialog.open()
           fileService.writeResults(reportPath)
        }
    }
    Menu{
        id: menuBar
        property bool isDateExist: false
               title: qsTr("⋮")
               MenuItem  { text: qsTr("&Save report in file")
               onTriggered: {

                          if(fileService.hasIncompleteBookings()) {
                              confirmPartialSaveDialog.open()
                          } else {

                              reportSuccessDialog.open()
                             fileService.writeResults(reportPath)
                            }
                        }
               }
    }


        RowLayout {
            anchors.fill: parent
            ToolButton {
                text: qsTr("‹")
                Layout.preferredWidth: 56
                Layout.preferredHeight: 30
                font.pixelSize: 30
                background: Rectangle {
                    radius: 16
                    color: parent.down ? "#00c2a8" : (parent.hovered ? "#123d5c" : "#0d2a52")
                    border.color: parent.hovered ? "#00f5d4" : "#1b426f"
                    border.width: 1
                }
                contentItem: Text {
                    text: parent.text
                    color: "white"
                    font: parent.font
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                onClicked: {
                if(stack && stack.depth > 1) stack.pop()}
            }
            Label {
                text: (stack && stack.currentItem) ? stack.currentItem.title : "Додаток"
                font.pixelSize: 22
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
                color: "white"
            }
            ToolButton {
                id: menuButton
                text: qsTr("⋮")
                Layout.preferredWidth: 56
                Layout.preferredHeight: 30
                font.pixelSize: 30
                background: Rectangle {
                    radius: 16
                    color: parent.down ? "#00c2a8" : (parent.hovered ? "#123d5c" : "#0d2a52")
                    border.color: parent.hovered ? "#00f5d4" : "#1b426f"
                    border.width: 1
                }
                contentItem: Text {
                    text: parent.text
                    color: "white"
                    font: parent.font
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }

                onClicked: {
                    menuBar.x = menuButton.x
                    menuBar.y = menuButton.y
                    menuBar.open()
                }
            }

        }

}

