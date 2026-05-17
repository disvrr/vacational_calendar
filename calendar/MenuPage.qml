import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Page {
 anchors.fill: parent
    visible: true
    background: Rectangle {
                     color: "#071a3d"
                 }

    title: qsTr("Fitness App")

    id: menuPage
    property StackView stack

    ListModel {
        id: activityModel

        ListElement {
            activity: "Календар"
            page: "Calendar.qml"
            title: "Календар"
        }

        ListElement {
            activity: "Налаштування"
            page: "Report.qml"
            title: "Налаштування"
        }

        ListElement {
            activity: "About"
            page: "About.qml"
            title: "About"
        }
    }

      ColumnLayout {

          anchors.centerIn: parent

              width: parent.width * 0.4
              spacing: 10
          Label {
              text: "Календар відпусток"
              color: "white"
              font.pixelSize: 24
              Layout.alignment: Qt.AlignHCenter
          }

          Repeater {

              model: activityModel


              delegate: Button {
                  text: activity
                  Layout.fillWidth: true
                  Layout.preferredHeight: 50

                  background: Rectangle {
                      color: "#00F5D4"
                      border.color: "#24f04f"
                      border.width: 2
                      radius: 8
                  }
                  contentItem: Text {
                      text: parent.text
                      color:  "#0b0e11"
                      font.pixelSize: 12
                      horizontalAlignment: Text.AlignHCenter
                      verticalAlignment: Text.AlignVCenter
                  }
                              onClicked: {
                              console.log("Выбрана активность:", model.activity)
                                        if (stack)
                                        stack.push(model.page, { "stack": stack })

                          }
                      }

                  }

          Item {
              Layout.fillHeight: true
          }
      }

      Button {
          text: "Вихід"

          anchors.right: parent.right
          anchors.bottom: parent.bottom
          anchors.margins: 20

          onClicked: Qt.quit()
      }

}
