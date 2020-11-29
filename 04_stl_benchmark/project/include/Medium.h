#pragma once

#include <random>

struct Medium {

    constexpr static unsigned SIZE = 256u;
    int data[SIZE];

    void clear() {
        std::fill_n(data, SIZE, 0);
    }

    void randomize() {
        static std::random_device rd{};
        static std::mt19937 gen{rd()};
        static std::uniform_int_distribution<int> dis{};

        for (int &i : data)
            i = dis(gen);
    }

    bool operator<(const Medium &rhs) const {

        return std::lexicographical_compare(std::cbegin(this->data), std::cend(this->data),
                                            std::cbegin(rhs.data), std::cend(rhs.data));
    }

    bool operator==(const Medium &rhs) const {

        bool result = true;

        if(this->data[0] < rhs.data[0] || this->data[0] > rhs.data[0])
            result = false;

        return result;
    }
};

namespace std {
    template<>
    struct hash<Medium> {
        std::size_t operator()(const Medium &d) const {

            // TODO: Implement me!
            return 0;
        }
    };
}