import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs
 Page {
    id: calendarPage
    title: "Календар"
    property int updt: 0
    property int currentYear: new Date().getFullYear()
    property date selectedDate: new Date()
    background: Rectangle {
        color: "#f5f7fa"
    }
    property StackView stack
    header: ToolBarHeader {
    stack: calendarPage.stack
    reportPath: globalReportPath
    }
    ListModel {id: workersModel}

    Connections{
        target: fileService
            function onDataUpdated() {
                updt++
            }
    }
    MessageDialog {
        id: confirmDeleteDialog
        title: "confirm"
        text: "Впевнені, що хочете видалити всі записи?"
        buttons: MessageDialog.Ok | MessageDialog.Cancel
        onAccepted: {
                fileService.deleteResults("data.json");
                console.log("Записи видалено");
            }
            onRejected: {
                console.log("Видалення скасовано");
            }
    }
    ColorDialog {
        id: colorDialog
        title: "Оберіть колір для " + Worker.firstName
        selectedColor: Worker.color
        onAccepted: {
        var colorStr = selectedColor.toString()
                Worker.color = colorStr
                console.log("ОБРАНО КОЛІР:", colorStr)
        }
    }
    Component.onCompleted: {
            fileService.loadResults("data.json");
            console.log("Дані завантажено з файлу при старті");
        yearGrid.positionViewAtIndex(
                new Date().getMonth(),
                GridView.Center
            )
        }

ColumnLayout {
        anchors.fill: parent
        anchors.margins: 20
        spacing: 14

        Rectangle {
            id: settingsPanel
            Layout.fillWidth: true
            Layout.preferredHeight: 180
            radius: 12
            color: "white"
            clip: true
            border.color: "#dce5ef"
            border.width: 1

            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 14
                spacing: 10

        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            spacing: 10
        ComboBox {
                    id: workerSelector
                    Layout.alignment: Qt.AlignHCenter
                    Layout.preferredWidth:
                           Math.max(250, contentItem.implicitWidth + 80)
                    font.pixelSize: appWindow.width * 0.01
                    model: fileService.workersNames

                    contentItem: RowLayout {
                            spacing: 10
                            Text {
                                text: (workerSelector.currentIndex + 1)+ " "+ workerSelector.displayText
                                font: workerSelector.font
                                color: "#2c3e50"
                                verticalAlignment: Text.AlignVCenter
                                Layout.fillWidth: true
                            }
                            Rectangle {
                                width: 20
                                height: 20
                                radius: 4
                                visible: Worker.color !== ""
                                color: Worker.color
                                border.color: "white"
                                border.width: 1
                                Layout.alignment: Qt.AlignVCenter
                                MouseArea {
                                       anchors.fill: parent
                                       cursorShape: Qt.PointingHandCursor

                                       onClicked: {
                                           colorDialog.open()
                                       }
                                   }
                            }
                        }
                    delegate: ItemDelegate {
                            width: workerSelector.width
                            contentItem: RowLayout {
                                spacing: 10
                                Text {
                                    text:(index + 1) + " " + model.modelData
                                    color: "#2c3e50"
                                    font.pixelSize: appWindow.width * 0.01
                                    verticalAlignment: Text.AlignVCenter
                                }
                                Rectangle {
                                    width: 18
                                    height: 18
                                    radius: 3
                                    color: {
                                        var col = Worker.color;
                                        fileService.dataUpdated;
                                        var parts = modelData.split(" ");
                                            if (parts.length >= 2) {
                                                return fileService.getColorForWorker(parts[0], parts[1]);
                                            }
                                    }
                                    border.color: "#bdc3c7"
                                    border.width: 1
                                }

                            }
                            highlighted: workerSelector.highlightedIndex === index
                        }
                    onActivated: (index) =>{
                                     var fullName = workerSelector.currentText;
                                         var parts = fullName.split(" ");
                                         if (parts.length >= 2) {
                                             Worker.firstName = parts[0];
                                             Worker.lastName = parts[1];
                                             Worker.color = fileService.getColorForWorker(Worker.firstName, Worker.lastName);
                                         }
                                         console.log("Працівник вибраний на:", Worker.firstName, Worker.lastName);
                    }
                }
        Button {
            text: "Очистити всі записи"
            Layout.fillWidth: false
            contentItem: Text {
                text: parent.text
                color: "red"
                horizontalAlignment: Text.AlignHCenter
            }
            onClicked: {
                confirmDeleteDialog.open()
                Worker.startDate = new Date(0);
                Worker.endDate = new Date(0);
                console.log("Всі записи видалено");
            }
        }
     }
        RowLayout {
                    spacing: 10
                    Layout.alignment: Qt.AlignHCenter
                    TextField {
                        id: newFirstName
                        placeholderText: "Ім'я"
                        font.pixelSize: appWindow.width * 0.01
                        onAccepted: {
                             newLastName.forceActiveFocus()
                         }
                    }

                    TextField {
                        id: newLastName
                        placeholderText: "Прізвище"
                        font.pixelSize: appWindow.width * 0.01
                        onAccepted: {
                            if (newFirstName.text !== "" || newLastName.text !== "") {
                                fileService.addWorker(newFirstName.text, newLastName.text);
                                                    newFirstName.text = "";
                                                    newLastName.text = "";
                                                }
                                newFirstName.text = "";
                                newLastName.text = "";;
                         }
                    }

                    Button {
                        text: "Додати призвіще"
                        font.pixelSize: appWindow.width * 0.01
                        onClicked: {
                            if (newFirstName.text !== "" || newLastName.text !== "") {
                                fileService.addWorker(newFirstName.text, newLastName.text);
                                                    newFirstName.text = "";
                                                    newLastName.text = "";
                                                }
                                newFirstName.text = "";
                                newLastName.text = "";
                            }
                        }
                    }

        Button {
            checkable: true
            text: "Зберегти діапазон"
            font.pixelSize: appWindow.width * 0.01
            Layout.alignment: Qt.AlignHCenter
            enabled: Worker.startDate && Worker.endDate
            highlighted: checked
            onClicked: {

                fileService.createObject(Worker);
                calendarPage.selectedDate = new Date(calendarPage.selectedDate);
                console.log("Запис додано!");
            }

        }
            }
        }

        Rectangle {
            id: calendarPanel
            Layout.fillWidth: true
            Layout.fillHeight: true
            radius: 12
            color: "white"
            clip: true
            border.color: "#dce5ef"
            border.width: 1

        GridView {
                id: yearGrid
                anchors.fill: parent
                anchors.margins: 14

                property int columns: width > 1200 ? 5 : 4// needed 3

                cellWidth: width / columns
                cellHeight: cellWidth * 0.9
                interactive: true
                boundsBehavior: Flickable.StopAtBounds
                ScrollBar.vertical: ScrollBar { }

                model: 12
                clip: true

                delegate: Item {
                    width: yearGrid.cellWidth
                    height: yearGrid.cellHeight

                    ColumnLayout {
                        anchors.fill: parent
                        anchors.margins: 20//padding
                        spacing: 2

                        Label {
                            text: Qt.locale("uk_UA").standaloneMonthName(model.index)
                            Layout.alignment: Qt.AlignHCenter
                            font.bold: true
                            font.pixelSize: 16
                            color: "#2c3e50"
                            textFormat: Text.PlainText
                        }


                        MonthGrid {
                            id: mGrid
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            month: model.index
                            year: currentYear
                            locale: Qt.locale("uk_UA")

                                delegate:
                                    CalendarDay {}

                            onClicked : (date) => {
                                        calendarPage.selectedDate = date
                                        Worker.handleClick(date, Worker)
                                        console.log("Обрана дата:", calendarPage.selectedDate.toLocaleDateString())
                                        }
                        }
                    }
                }
        }
        }
}}

