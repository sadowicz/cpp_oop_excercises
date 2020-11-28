#pragma once

#include <random>

struct Small {

    constexpr static unsigned SIZE = 1u;
    char data[SIZE];

    void clear() {
        std::fill_n(data, SIZE, 0);
    }

    void randomize() {
        static std::random_device rd{};
        static std::mt19937 gen{rd()};
        static std::uniform_int_distribution<char> dis{-128, 127};

        for (char &i : data)
            i = dis(gen);
    }

    bool operator<(const Small &rhs) const {

        return this->data[0] < rhs.data[0];
    }

    bool operator==(const Small &rhs) const {

        return this->data[0] == rhs.data[0];
    }
};

namespace std {
    template<>
    struct hash<Small> {
        std::size_t operator()(const Small &d) const {
            static std::random_device rd{};
            static std::mt19937 gen{rd()};
            static std::uniform_int_distribution<size_t> dis{std::numeric_limits<size_t>::min(), std::numeric_limits<size_t>::max()};

            return dis(gen);
        }
    };
}
