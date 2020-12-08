#include "factory/gui/CheckBoxGnomeWidget.h"

factory::gui::CheckBoxGnomeWidget::CheckBoxGnomeWidget(int gnomeVersion) : gnomeVersion{gnomeVersion} {}

void factory::gui::CheckBoxGnomeWidget::draw() {

    std::cout << "factory::gui::CheckBoxGnomeWidget{ gnomeVersion: " << gnomeVersion << " }" << std::endl;
}

