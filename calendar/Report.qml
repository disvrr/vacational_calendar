import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs

Page {
    id: reportPage
    title: "Налаштування"
    property StackView stack

    header: ToolBarHeader {
    stack: reportPage.stack
reportPath: globalReportPath
    }
    ColumnLayout {
            anchors.fill: parent
         anchors.margins: padding
    Label {
        text: "Сторінка налаштувань"
       // elide: Label.ElideRight
        horizontalAlignment: Qt.AlignHCenter
        verticalAlignment: Qt.AlignVCenter
        Layout.fillWidth: true
        font.bold: true
        font.pixelSize: titleFontPx
    }
    Button {
        checkable: true
        text: "Натисніть, щоб обрати файл для збереження списку відпусток"
        Layout.fillWidth: true
        Layout.preferredHeight: controlHeight
        highlighted: checked
        font.pixelSize: bodyFontPx
        onClicked: {
            saveFileDialog.open()
        }
    }
    Rectangle {
                Layout.fillWidth: true
                height: controlHeight
                color: "#eeeeee"
                border.color: "#cccccc"
                radius: 4
                Text {
                    anchors.centerIn: parent
                    text: "Обраний файл: " + globalReportPath
                    elide: Text.ElideLeft
                    width: parent.width - 20
                    font.pixelSize: bodyFontPx
                }
            }
    FileDialog {
        id: saveFileDialog
        title: "Оберіть куди зберегти звіт"
        currentFile: "report.txt"
        fileMode: FileDialog.SaveFile
        nameFilters: ["Text files (*.txt)", "All files (*)"]

        onAccepted: {
            let path = selectedFile.toString().replace("file:///", "")
            globalReportPath = path
            fileService.savePath(path)
            console.log("Звіт збережено у:", path)
        }
    }
    }

}
