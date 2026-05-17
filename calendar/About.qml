import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Page {
    id: aboutPage
    title: "Про програму"
    property StackView stack
    header: ToolBarHeader {
    stack: aboutPage.stack
    }

    ScrollView {
        anchors.fill: parent
        contentWidth: availableWidth

        ColumnLayout {
            width: parent.width - 40
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 15

            Label {
                text: "Інструкція користувача"
                font.pixelSize: 22
                font.bold: true
                Layout.topMargin: 20
            }

            Text {
                Layout.fillWidth: true
                wrapMode: Text.WordWrap
                lineHeight: 1.2
                font.pixelSize: 16
                color: "#2c3e50"
                text: "
1. **Вибір працівника:** Оберіть потрібне ім'я зі списку у верхній частині екрана.
2. **Налаштування кольору:** Відкрийте меню (⋮) -> Color та оберіть колір для позначень.
3. **Бронювання дат:** - Натисніть на дату початку періоду.
   - Натисніть на дату завершення.
   - Період автоматично зафарбується у ваш колір.
4. **Звіт:** Натисніть кнопку 'Generate a report', щоб зберегти всі дані у файл."
                textFormat: Text.MarkdownText // Дозволяє використовувати жирний шрифт через **
            }


            Label {
                text: "Версія 1.0.0 | Розробник: Діана Івахненко"
                font.pixelSize: 12
                color: "grey"
                Layout.alignment: Qt.AlignHCenter
            }
        }
    }
}
