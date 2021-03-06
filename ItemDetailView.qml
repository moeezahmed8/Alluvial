
import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2


ApplicationWindow{

    title: qsTr(ItemDetailView)
    width: 640
    height: 480
    visible: true

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: messageDialog.show(qsTr("Open action triggered"));
            }
            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
            }

        }
        Menu {
            title: qsTr("&Edit")
            MenuItem{
                text: qsTr("&edit")
                onTriggered: messageDialog.show(qsTr("edit button pushed"));
            }
        }
    }

    ItemDetailViewForm {
        anchors.fill: parent

    }
}

