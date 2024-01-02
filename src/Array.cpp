#include "../include/Array.h"

#include <stdlib.h>

template <typename T>
void Array<T>::resizeCapacity() {
    if (_count == _capacity) {
        _capacity = _capacity * 2;
        _values = (T*) realloc(_values, _capacity * sizeof(T));
    } else if (_count <= 4) {
        _capacity = 4;
        _values = (T*) realloc(_values, _capacity * sizeof(T));
    } else if (_count < _capacity/2) {
        _capacity = _capacity / 2;
        _values = (T*) realloc(_values, _capacity * sizeof(T));
    }
}

template <typename T>
Array<T>::Array() {
    _count = 0;
    _capacity = 4;
    _values = (T*) malloc(_capacity * sizeof(T));
}

template <typename T>
Array<T>::Array(const T * array, const int count) {
    _count = count;
    _capacity = count;
    _values = (T*) malloc(_capacity * sizeof(T));
    for (int i = 0; i < count; i++) {
        _values[i] = array[i];
    }
}

template <typename T>
Array<T>::~Array() {
    free(_values);
}

template <typename T>
bool Array<T>::isEmpty() const {
    if (_count == 0) {
        return true;
    } else {
        return false;
    }
}

template <typename T>
int Array<T>::count() const {
    return _count;
}

template <typename T>
T & Array<T>::operator[](const int index) const {
    if (0 <= index && index < _count) {
        return _values[index];
    } else {
        return _values[0];    // index out of range
    }
}

template <typename T>
T & Array<T>::first() const {
    return _values[0];
}

template <typename T>
T & Array<T>::last() const {
    return _values[_count];
}

template <typename T>
void Array<T>::append(const T & newElement) {
    resizeCapacity();
    _values[_count] = newElement;
    _count += 1;
}

template <typename T>
T & Array<T>::operator+(const Array object) {
    for (int i = 0; i < object._count; i++) {
        this->append(object[i]);
    }
}

template <typename T>
void Array<T>::operator+=(const Array object) {
    for (int i = 0; i < object._count; i++) {
        this->append(object[i]);
    }
}

template <typename T>
void Array<T>::insert(const T & element, const int index) {
    resizeCapacity();
    if (0 <= index && index <= _count) {
        for (int i = _count; i > index; i--) {
            _values[i] = _values[i-1];
        }
        _values[index] = element;
        _count += 1;
    }
}

template <typename T>
void Array<T>::replace(const T & element, const int index) {
    if (0 <= index && index < _count) {
        _values[index] = element;
    }
}

template <typename T>
void Array<T>::remove(const int index) {
    if (0 <= index && index < _count) {
        for (int i = index; i < _count-1; i++) {
            _values[i] = _values[i+1];
        }
        _count -= 1;
    }
    resizeCapacity();
}

template <typename T>
void Array<T>::removeFirst() {
    remove(0);
}

template <typename T>
void Array<T>::removeLast() {
    _count -= 1;
    resizeCapacity();
}

template <typename T>
void Array<T>::removeAll() {
    _count = 0;
    resizeCapacity();
}