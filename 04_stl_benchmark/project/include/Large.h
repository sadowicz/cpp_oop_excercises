#pragma once

#include <random>

struct Large {

    constexpr static unsigned SIZE = 128u*1024u;

    double data[SIZE];

    void clear() {
        std::fill_n(data, SIZE, 0);
    }

    void randomize() {
        static std::random_device rd{};
        static std::mt19937 gen{rd()};
        static std::uniform_real_distribution<> dis{};

        for (double &i : data) {
            i = dis(gen);
        }
    }

    bool operator<(const Large &rhs) const {

        return std::lexicographical_compare(std::cbegin(this->data), std::cend(this->data),
                                            std::cbegin(rhs.data), std::cend(rhs.data));
    }

    bool operator==(const Large &rhs) const {

        return std::equal(std::cbegin(this->data), std::cend(this->data), std::cbegin(rhs.data));
    }
};

namespace std {
    template<>
    struct hash<Large> {
        std::size_t operator()(const Large &d) const {

            std::size_t hash = 0;
            std::hash<double>hasher{};

            for(int i = 0; i < Large::SIZE; i++) {
                hash += (hasher(d.data[i]) * (i + 1));
            }

            return hash;
        }
    };
}
