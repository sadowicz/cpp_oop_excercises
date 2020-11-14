#include "RingBuffer.h"

RingBuffer::RingBuffer(unsigned int capacity) : _capacity{capacity}, _size{} {

    if(!this->capacity()) {
        throw std::invalid_argument{"Zero passed as capacity."};
    }
}

void RingBuffer::add(int element) {
    _size++;
}

int RingBuffer::remove() {

    if(!size()) {
        throw std::out_of_range{"Removing from zero size buffer."};
    }

    _size--;
}
