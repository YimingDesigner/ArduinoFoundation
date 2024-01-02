#ifndef ARDUINO_FOUNDATION_KEY_VALUE_PAIR_H_
#define ARDUINO_FOUNDATION_KEY_VALUE_PAIR_H_

template <typename Key, typename Value>
struct KeyValuePair {
    Key key;
    Value value;
};

#endif