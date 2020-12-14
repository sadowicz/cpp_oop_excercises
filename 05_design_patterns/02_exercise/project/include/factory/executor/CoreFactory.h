#pragma once

#include <memory>
#include "Core.h"

namespace factory {

    namespace executor {

        class CoreFactory {

        public:
            virtual ~CoreFactory() = default;
            virtual std::shared_ptr<Core> create(std::string equation) = 0;
        };
    }
}