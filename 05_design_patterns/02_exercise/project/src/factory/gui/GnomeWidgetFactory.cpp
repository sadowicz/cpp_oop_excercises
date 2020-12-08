#include "factory/gui/GnomeWidgetFactory.h"

factory::gui::GnomeWidgetFactory::GnomeWidgetFactory(int kdeVersion) : gnomeVersion{gnomeVersion} {}

std::shared_ptr<factory::gui::Widget> factory::gui::GnomeWidgetFactory::create(std::string type) {

    if(type == "button")
        return std::make_shared<ButtonGnomeWidget>( gnomeVersion );

    if(type == "list")
        return std::make_shared<ListGnomeWidget>( gnomeVersion );

    if(type == "check_box")
        return std::make_shared<CheckBoxGnomeWidget>( gnomeVersion );

    throw std::runtime_error{ "Unsupported Gnome widget type: " + type };
}