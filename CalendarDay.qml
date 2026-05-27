import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: root
readonly property date cellDate: new Date(currentYear, model.month, model.day)
readonly property bool isCurrentMonth: model.month === mGrid.month
    opacity: isCurrentMonth ? 1 : 0.1
    readonly property bool inRange: {
        var start = Worker.startDate;
        var end = Worker.endDate;

        Worker.rangeChanged;
        return Worker.isInRange(cellDate);
    }
    readonly property bool isSelected: calendarPage.selectedDate.toDateString() ===
        new Date(currentYear, mGrid.month, model.day).toDateString()

    readonly property string savedColor: {
calendarPage.updt
    fileService.dataUpdated;
    var currentWorkerColor = Worker.color;
    return fileService.getColorForDate(cellDate)
    }
    readonly property bool isSaved: savedColor !== undefined && savedColor !== "transparent"
    Rectangle {
       id: rangeRect
       anchors.fill: parent
       anchors.margins: 1
       visible: root.isCurrentMonth && (root.inRange || root.isSaved)
       color: {
            let forceUpdt = updt
               if (root.isSaved) {
                   let c = root.savedColor;
                   return (c !== undefined && c !== "") ? c : "transparent";
               }
               if (root.inRange) {
                   return Worker.color;
               }

               return "transparent";
           }
       radius: 2
   }
    Rectangle {
        anchors.centerIn: parent
        width: parent.width * 0.8
        height: width
        radius: width / 2

        color:  "green"
        opacity: isSelected ? 1.0 : 0.3
        visible: model.today
    }
Text {
id: dayText
anchors.centerIn: parent
horizontalAlignment: Text.AlignHCenter
verticalAlignment: Text.AlignVCenter
text: model.day
color: (inRange || isSaved) ? "white" : (isCurrentMonth ? "#2c3e50" : "#bdc3c7")
font.pixelSize: Math.max(8, yearGrid.cellWidth / 15)
font.bold: (inRange || isSaved)

}

}
