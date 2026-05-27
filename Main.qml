import QtQuick
import QtQuick.Controls
import QtQuick.Layouts


ApplicationWindow {
    id: appWindow
   visibility: Window.Maximized
        minimumWidth: 500
        minimumHeight: 200
    visible: true
    title: qsTr("Calendar App")
    property string globalReportPath: ""

        Component.onCompleted: {
            let saved = fileService.loadPath()
                    if (saved !== "") {
                        globalReportPath = saved
                    }
        }
    property string titleOnToolBar

    StackView {
           id: stack
           anchors.fill: parent
           initialItem: MenuPage {
               stack: stack
           }

       }
}

