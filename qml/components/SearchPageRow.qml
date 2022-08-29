import Felgo 3.0
import QtQuick 2.0


SimpleRow {
  id: root

  showDisclosure: true
  text:" Text"
  imageSource: Qt.resolvedUrl("qrc:///assets/cover.png")

  style: StyleSimpleRow {
    backgroundColor: Theme.colors.backgroundColor
    selectedBackgroundColor: backgroundColor
    textColor: Theme.colors.textColor
    detailTextColor: Theme.colors.textColor
    selectedTextColor: Theme.colors.secondaryTextColor
    dividerHeight: 0
  }

  detailText: {

      return "Detailed text "
  }
}
