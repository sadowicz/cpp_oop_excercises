#include "factory/gui/ListKdeWidget.h"

factory::gui::ListKdeWidget::ListKdeWidget(int kdeVersion) : kdeVersion{kdeVersion} {}

void factory::gui::ListKdeWidget::draw() {

    std::cout << "factory::gui::ListKdeWidget{ kdeVersion: " << kdeVersion << " }" << std::endl;
}

