#pragma once

#include <iostream>
#include "Widget.h"

namespace factory {

    namespace gui {

        class ButtonGnomeWidget : public Widget {

        public:
            explicit ButtonGnomeWidget(int gnomeVersion);
            void draw() override;

        private:
            int gnomeVersion;
        };
    }
}