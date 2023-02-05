#pragma once

#include <iostream>
#include "smart_array.h"

smart_array::smart_array(int size) {
    _ptr = new int[size];
    _size = size;
    init_array(_last);
}

smart_array::~smart_array() {
    delete[] _ptr;
}

void smart_array::add_element(int val) {
    if ((_size == _last + 1) && _size != 0) {
        _size *= 2;
        int* new_ptr = new int[_size];
        for (int i = 0; i < _size / 2; i++)
            new_ptr[i] = _ptr[i];

        _ptr = std::move(new_ptr);
        init_array(_last);
    }
    _ptr[_last + 1] = val;
    _last++;
}

int smart_array::get_element(int idx){
    return _ptr[idx];
}

void smart_array::init_array(int from) {
    for (int i = from + 1; i < _size; i++)
        _ptr[i] = 0;
}

void smart_array::print() {
    std::cout << "Content: ";
    for (int i = 0; i <= _last; i++)
        std::cout << _ptr[i] << " ";
    std::cout << "\n";
}