#include "factory/gui/ButtonKdeWidget.h"

factory::gui::ButtonKdeWidget::ButtonKdeWidget(int kdeVersion) : kdeVersion{kdeVersion} {}

void factory::gui::ButtonKdeWidget::draw() {

    std::cout << "factory::gui::ButtonKdeWidget{ kdeVersion: " << kdeVersion << " }" << std::endl;
}