#pragma once

#include <iostream>
#include "Widget.h"

namespace factory {

    namespace gui {

        class ButtonKdeWidget : public Widget {

        public:
            explicit ButtonKdeWidget(int kdeVersion);
            void draw() override;

        private:
            int kdeVersion;
        };
    }
}