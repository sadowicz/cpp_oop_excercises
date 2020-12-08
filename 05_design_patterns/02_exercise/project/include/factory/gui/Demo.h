#pragma once

#include "WidgetFactory.h"

namespace factory {

    namespace gui {

        class Demo {

        public:
            explicit Demo(std::shared_ptr<WidgetFactory> factory);
            void run(std::string type);

        private:
            std::shared_ptr<WidgetFactory> factory;
        };
    }
}