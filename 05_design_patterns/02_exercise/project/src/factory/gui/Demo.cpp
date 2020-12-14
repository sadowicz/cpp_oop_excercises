#include "factory/gui/Demo.h"

factory::gui::Demo::Demo(std::shared_ptr<WidgetFactory> factory) : factory{ std::move(factory) } {}

void factory::gui::Demo::run(std::string type) {

    auto widget = factory->create(type);
    widget->draw();
}

