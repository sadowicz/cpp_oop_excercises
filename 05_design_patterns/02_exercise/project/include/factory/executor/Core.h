#pragma once

namespace factory {

    namespace executor {

        class Core {

        public:
            virtual void execute() = 0;
        };
    }
}