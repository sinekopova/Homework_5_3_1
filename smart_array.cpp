#pragma once

#include <iostream>
#include "smart_array.h"

smart_array::smart_array(int size) {
    _ptr = new int[size];
    _size = size;
    init_array(_count);
}

smart_array::~smart_array() {
    delete[] _ptr;
}

void smart_array::add_element(int val) {
    if (_size == _count) {
        if (_size != 0)
            _size *= 2;
        else
            _size = 1;
        int* new_ptr = new int[_size];
        for (int i = 0; i < _size / 2; i++)
            new_ptr[i] = _ptr[i];

        delete[] _ptr;
        _ptr = std::move(new_ptr);
        init_array(_count);
    }
    _ptr[_count] = val;
    _count++;
}

int smart_array::get_element(int idx){
    if (idx > 0 && idx < _count)
        return _ptr[idx];
    else
        throw std::exception("Индекс вне диапазона");
}

void smart_array::init_array(int from) {
    for (int i = from; i < _size; i++)
        _ptr[i] = 0;
}

void smart_array::print() {
    std::cout << "Content: ";
    for (int i = 0; i < _count; i++)
        std::cout << _ptr[i] << " ";
    std::cout << "\n";
}