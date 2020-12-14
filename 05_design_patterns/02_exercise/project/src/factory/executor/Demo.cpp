#include "factory/executor/Demo.h"

factory::executor::Demo::Demo(std::shared_ptr<CoreFactory> factory) : factory{ std::move(factory) } {}

void factory::executor::Demo::run(std::string equation) {

    auto widget = factory->create(equation);
    widget->execute();
}