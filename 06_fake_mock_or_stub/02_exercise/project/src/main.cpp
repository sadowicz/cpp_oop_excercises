#include <iostream>

#include "Universe.h"

#include "Time.h"
#include "Space.h"
#include "Observer.h"

int main() {

    std::cout << "Are you sure you want to run this thing? [yes/no]" << std::endl;

    std::string confirmation{};
    std::cin >> confirmation;

    if (confirmation != "yes") {

        std::cout << "Uff... It was close..." << std::endl;
        return 0;
    }

    std::cout << "Whatever..." << std::endl;

    Time time{};
    Space space{};
    Observer observer{};

    Universe universe{time, space, observer};

    universe.create();
    universe.simulate(13800000000);

    std::string question = "Have People evolved?";
    std::string answer = observer.answer(question);

    std::cout << question << " : " << answer << std::endl;

    return 0;
}