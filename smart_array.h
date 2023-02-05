#pragma once


class smart_array {
public:
    smart_array(int size);
    ~smart_array();
    void add_element(int val);
    void print();
    int get_element(int idx);
private:
    int* _ptr = nullptr;
    int _size = 0;
    int _last = -1;

    void init_array(int from);
};