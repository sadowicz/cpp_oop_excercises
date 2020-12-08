#pragma once

#include "WidgetFactory.h"

#include "ButtonGnomeWidget.h"
#include "ListGnomeWidget.h"
#include "CheckBoxGnomeWidget.h"

namespace factory {

    namespace gui {

        class GnomeWidgetFactory : public WidgetFactory {

        public:
            explicit GnomeWidgetFactory(int gnomeVersion);
            std::shared_ptr<Widget> create(std::string type) override;

        private:
            int gnomeVersion;
        };
    }
}