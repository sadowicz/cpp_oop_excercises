#pragma once

#include <iostream>
#include "Widget.h"

namespace factory {

    namespace gui {

        class CheckBoxKdeWidget : public Widget {

        public:
            explicit CheckBoxKdeWidget(int kdeVersion);
            void draw() override;

        private:
            int kdeVersion;
        };
    }
}