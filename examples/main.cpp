#include <iostream>
#include "../include/Array.h"
#include "../src/Array.cpp"

using std::cout;
using std::cin;
using std::endl;

int main() {
    Array<int> arr;
    
    for (int i = 0; i < 10; i++) {
        arr.append(i * 2 + 1);
    }

    arr[3] = 999;

    cout << arr.count() << endl;
    cout << arr[3] << endl;
    cin.get();
    return 0;
}