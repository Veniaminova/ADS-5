// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
private: 
    T* _stack;
    int _max_size;
    int cur;

public: 
    TStack() {
        _stack = new T[size];
        _max_size = size;
        cur = -1;
    }
    ~TStack() {
        delete[] _stack;
    }
    void push(T elem) {
        cur++;
        if (cur >= _max_size) {
            return;
        }
        _stack[cur] = elem;
    }
    T top() {
        return _stack[cur];
    }
    void pop() {
        cur--;
    }
    bool empty() {
        return cur == -1;
    }
};
#endif  // INCLUDE_TSTACK_H_
