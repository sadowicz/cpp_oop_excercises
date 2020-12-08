#include "factory/gui/CheckBoxKdeWidget.h"

factory::gui::CheckBoxKdeWidget::CheckBoxKdeWidget(int kdeVersion) : kdeVersion{kdeVersion} {}

void factory::gui::CheckBoxKdeWidget::draw() {

    std::cout << "factory::gui::CheckBoxKdeWidget{ kdeVersion: " << kdeVersion << " }" << std::endl;
}

