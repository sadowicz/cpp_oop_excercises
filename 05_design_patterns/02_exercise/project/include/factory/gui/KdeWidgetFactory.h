#pragma once

#include "WidgetFactory.h"

#include "ButtonKdeWidget.h"
#include "ListKdeWidget.h"
#include "CheckBoxKdeWidget.h"

namespace factory {

    namespace gui {

        class KdeWidgetFactory : WidgetFactory {

        public:
            explicit KdeWidgetFactory(int kdeVersion);
            std::shared_ptr<Widget> create(std::string type) override;

        private:
            int kdeVersion;
        };
    }
}