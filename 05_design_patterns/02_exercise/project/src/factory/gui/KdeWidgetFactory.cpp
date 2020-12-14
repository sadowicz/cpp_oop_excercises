#include "factory/gui/KdeWidgetFactory.h"

factory::gui::KdeWidgetFactory::KdeWidgetFactory(int kdeVersion) : kdeVersion{kdeVersion} {}

std::shared_ptr<factory::gui::Widget> factory::gui::KdeWidgetFactory::create(std::string type) {

    if(type == "button")
        return std::make_shared<ButtonKdeWidget>( kdeVersion );

    if(type == "list")
        return std::make_shared<ListKdeWidget>( kdeVersion );

    if(type == "check_box")
        return std::make_shared<CheckBoxKdeWidget>( kdeVersion );

    throw std::runtime_error{ "Unsupported Kde widget type: " + type };
}