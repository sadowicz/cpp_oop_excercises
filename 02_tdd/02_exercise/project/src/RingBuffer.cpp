#include "RingBuffer.h"

RingBuffer::RingBuffer(unsigned int capacity) : _capacity{capacity}, _size{} {

}

void RingBuffer::add(int element) {
    _size++;
}

int RingBuffer::remove() {

}
