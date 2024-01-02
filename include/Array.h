#ifndef ARDUINO_FOUNDATION_ARRAY_H_
#define ARDUINO_FOUNDATION_ARRAY_H_

template <typename T>
class Array {
private:
    int _count;
    int _capacity;
    T * _values;

    void resizeCapacity();

public:
    Array();
    Array(const T * array, const int count);
    ~Array();
    bool isEmpty() const;
    int count() const;
    T & operator[](const int index) const;
    T & first() const;
    T & last() const;
    void append(const T & newElement);
    T & operator+(const Array object);
    void operator+=(const Array object);
    void insert(const T & element, const int index);
    void replace(const T & element, const int index);
    void remove(const int index);
    void removeFirst();
    void removeLast();
    void removeAll();
};

#endif