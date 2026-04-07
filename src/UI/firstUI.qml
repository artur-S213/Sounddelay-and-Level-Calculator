import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import AcousticController 1.0

Window {
    width: 1100
    height: 300
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
            padding: 10
            spacing: 5

            // Distance Input
            ResponsiveTile {
                id: distanceTile
                title: "Eingabe in m"
                titleBoxColor: "#1a1a1a"
                titleColor: "red"
                isInput: true
                // inputValue: Controller.distance.toLocaleString(Qt.locale("C"), "f", 2)
                // inputValue: "%1".arg(Controller.distance.toFixed(2))
                inputValue: Controller.distance.toFixed(2)
                onInputChanged: function (val) {
                    // let normalized = val
                    // if (val.includes(".")) {
                    //     normalized = val.replace(/\./g, "")
                    // }
                    // normalized = normalized.replace(",", ".")
                    // let normalized = val.replace(",", ".");

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
                titleBoxColor: "#1a3a5a"
            }

            // Lautsprecher 1 Lautstärke (Input)
            ResponsiveTile {
                title: "Schallpegel L1 in dB"
                titleBoxColor: "#5a4a7a"
                isInput: true
                // inputValue: Controller.soundLevelL1.toLocaleString(Qt.locale("C"), "f", 2)
                // inputValue: "%1".arg(Controller.soundLevelL1.toFixed(2))
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
                titleBoxColor: "#7a6a9a"
            }

            // Abfallpegel in -db
            ResponsiveTile {
                title: "Abfallpegel in -dB"
                value: Controller.dropLevel.toFixed(2)
                titleBoxColor: "#4a3a5a"
            }

            // Einstellungspegel
            ResponsiveTile {
                title: "Einstellungspegel in -db"
                value: Controller.adjustmentLevel.toFixed(2)
                titleBoxColor: "#632523"
                titleColor: "white"
            }

            // Sollwert
            ResponsiveTile {
                title: "Sollwert Pegel in db"
                value: Controller.setpoint.toFixed(2)
                titleBoxColor: "#40B02C"
                valueBoxColor: "#62D94A"
            }
        }
    }

    component ResponsiveTile: Column {
        property string title: ""
        property string value: "0,0"
        property color titleBoxColor: "gray"
        property color titleColor: "white"
        property color valueBoxColor: "#c0c0c0"
        property color valueColor: "white"
        property bool isInput: false
        property alias inputValue: inputField.text

        signal inputChanged(string newValue)

        width: (responsiveFlow.width > 400) ? 150 : parent.width - 80
        spacing: 0

        // Oberer Teil (Beschriftung)
        Rectangle {
            width: parent.width
            height: 35
            color: titleBoxColor
            Text {
                anchors.centerIn: parent
                text: title
                color: titleColor
                font.pixelSize: 11
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                wrapMode: Text.WordWrap
                width: parent.width - 4
            }
        }

        // Unterer Teil (Wert oder Eingabe)
        Rectangle {
            width: parent.width
            height: 40
            color: valueBoxColor
            border.color: "white"

            TextField {
                id: inputField
                visible: isInput
                anchors.fill: parent
                // Binding on text {
                //     value: Controller.
                // }
                color: valueColor
                horizontalAlignment: TextInput.AlignHCenter
                background: null
                // validator: DoubleValidator {
                //     bottom: 0
                //     decimals: 2
                //     locale: "C"
                // }
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
                font.pixelSize: 16
            }
        }
    }
}
