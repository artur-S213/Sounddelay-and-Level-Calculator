import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import AcousticController 1.0

Window {
    width: 1600
    height: 220
    visible: true
    title: qsTr("Acoustic Delay Calculator")

    ScrollView {
        anchors.fill: parent
        contentWidth: availableWidth
        anchors.centerIn: parent

        Flow {
            id: responsiveFlow
            width: parent.width
            anchors.centerIn: parent
            padding: 16
            spacing: 10

            // Distance Input
            ResponsiveTile {
                id: distanceTile
                title: "Eingabe in m"
                tileColor: "#F4A878"
                titleColor: "#3A1500"
                valueColor: "#3A1500"
                isInput: true
                inputValue: Controller.distance.toFixed(2)
                onInputChanged: function (val) {
                    let floatVal = parseFloat(val);
                    if (isNaN(floatVal)) floatVal = 0;
                    let finalValue = Math.min(floatVal, 5000.00);
                    Controller.distance = finalValue
                }
            }

            // Delay in ms
            ResponsiveTile {
                title: "Verzögerung in ms"
                value: Controller.delay.toFixed(2)
                tileColor: "#F5E6A0"
                titleColor: "#3A2E00"
                valueColor: "#4A3C00"
            }

            // Lautsprecher 1 Lautstärke (Input)
            ResponsiveTile {
                title: "Schallpegel L1 in dB"
                tileColor: "#A8C8F0"
                titleColor: "#0A1E3A"
                valueColor: "#0A1E3A"
                isInput: true
                inputValue: Controller.soundLevelL1.toFixed(2)
                onInputChanged: function (val) {
                    let floatVal = parseFloat(val);
                    if (isNaN(floatVal)) floatVal = 0;
                    let finalValue = Math.min(floatVal, 5000.00);
                    Controller.soundLevelL1 = finalValue;
                }
            }

            // Lautsprecher 2 Lautstärke
            ResponsiveTile {
                title: "Schallpegel L2 in dB"
                value: Controller.soundLevelL2.toFixed(2)
                tileColor: "#C0D8F8"
                titleColor: "#0A1E3A"
                valueColor: "#1A3A5A"
            }

            // Einstellungspegel
            ResponsiveTile {
                title: "Einstellungspegel in -dB"
                value: Controller.adjustmentLevel.toFixed(2)
                tileColor: "#C8ECE8"
                titleColor: "#082820"
                valueColor: "#0F3828"
            }

            // Abfallpegel in -dB
            ResponsiveTile {
                title: "Abfallpegel in -dB"
                value: Controller.dropLevel.toFixed(2)
                tileColor: "#A8E8C0"
                titleColor: "#082810"
                valueColor: "#0F3818"
            }

            // Sollwert
            ResponsiveTile {
                title: "Sollwert Pegel in dB"
                value: Controller.setpoint.toFixed(2)
                tileColor: "#6EDF78"
                titleColor: "#052008"
                valueColor: "#0A3010"
            }
        }
    }

    component ResponsiveTile: Column {
        property string title: ""
        property string value: "0,0"
        property color tileColor: "#C0C0C0"
        property color titleColor: "#333333"
        property color valueColor: "#555555"
        property bool isInput: false
        property alias inputValue: inputField.text

        signal inputChanged(string newValue)

        width: (responsiveFlow.width > 400) ? 210 : parent.width - 80
        spacing: 0

        Rectangle {
            width: parent.width
            height: 80
            radius: 14
            color: tileColor

            Column {
                anchors.fill: parent
                anchors.margins: 10
                spacing: 6

                // Titel
                Text {
                    width: parent.width
                    text: title
                    color: titleColor
                    font.pixelSize: 16
                    // font.bold: true
                    horizontalAlignment: Text.AlignHCenter
                    wrapMode: Text.WordWrap
                }


                // Wert oder Eingabe
                Item {
                    width: parent.width
                    height: 40

                    TextField {
                        id: inputField
                        visible: isInput
                        anchors.fill: parent
                        color: valueColor
                        font.pixelSize: 17
                        font.bold: true
                        horizontalAlignment: TextInput.AlignHCenter
                        background: null
                        inputMethodHints: Qt.ImhFormattedNumbersOnly
                        onEditingFinished: {
                            let cleanText = text.replace(",", ".");
                            text = cleanText;
                            inputChanged(cleanText);
                            focus = false;
                        }
                    }

                    Text {
                        visible: !isInput
                        anchors.centerIn: parent
                        text: value
                        color: valueColor
                        font.pixelSize: 18
                        // font.italic: true
                    }
                }
            }
        }
    }
}
