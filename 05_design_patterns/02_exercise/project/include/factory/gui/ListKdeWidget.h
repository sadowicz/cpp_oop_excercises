#pragma once

#include <iostream>
#include "Widget.h"

namespace factory {

    namespace gui {

        class ListKdeWidget : public Widget {

        public:
            explicit ListKdeWidget(int kdeVersion);
            void draw() override;

        private:
            int kdeVersion;
        };
    }
}