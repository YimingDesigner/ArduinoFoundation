#ifndef ARDUINO_FOUNDATION_ARRAY_H_
#define ARDUINO_FOUNDATION_ARRAY_H_

template <typename T>
class Array {
   private:
    int _count;
    int _capacity;
    int _minCapacity;
    T* _values;
    
    void resizeCapacity() {
        if (_count == _capacity) {
            _capacity = _capacity * 2;
            _values = (T*)realloc(_values, _capacity * sizeof(T));
        } else if (_count <= _minCapacity && _capacity != _minCapacity) {
            _capacity = _minCapacity;
            _values = (T*)realloc(_values, _capacity * sizeof(T));
        } else if (_count <= _capacity / 2) {
            _capacity = _capacity / 2;
            _values = (T*)realloc(_values, _capacity * sizeof(T));
        }
    }

   public:
    Array(int minCapacity = 4) {
        _count = 0;
        _capacity = minCapacity;
        _minCapacity = minCapacity;
        _values = (T*)malloc(_capacity * sizeof(T));
    }

    Array(const T* array, const int count) {
        _count = count;
        _capacity = count;
        _minCapacity = count;
        _values = (T*)malloc(_capacity * sizeof(T));
        for (int i = 0; i < count; i++) {
            _values[i] = array[i];
        }
    }

    ~Array() {
        free(_values);
    }

    bool isEmpty() const {
        if (_count == 0) {
            return true;
        } else {
            return false;
        }
    }

    int count() const {
        return _count;
    }

    T& operator[](const int index) const {
        return _values[index];
    }

    T& first() const {
        return _values[0];
    }

    T& last() const {
        return _values[_count];
    }

    void append(const T& newElement) {
        resizeCapacity();
        _values[_count] = newElement;
        _count += 1;
    }

    T& operator+(const Array object) {
        for (int i = 0; i < object._count; i++) {
            this->append(object[i]);
        }
    }

    void operator+=(const Array object) {
        for (int i = 0; i < object._count; i++) {
            this->append(object[i]);
        }
    }

    void insert(const T& element, const int index) {
        resizeCapacity();
        if (0 <= index && index <= _count) {
            for (int i = _count; i > index; i--) {
                _values[i] = _values[i - 1];
            }
            _values[index] = element;
            _count += 1;
        }
    }

    void replace(const T& element, const int index) {
        if (0 <= index && index < _count) {
            _values[index] = element;
        }
    }

    void remove(const int index) {
        if (0 <= index && index < _count) {
            for (int i = index; i < _count - 1; i++) {
                _values[i] = _values[i + 1];
            }
            _count -= 1;
            resizeCapacity();
        }
    }

    void removeFirst() {
        remove(0);
    }

    void removeLast() {
        _count -= 1;
        resizeCapacity();
    }

    void removeAll() {
        _count = 0;
        resizeCapacity();
    }
};

#endif