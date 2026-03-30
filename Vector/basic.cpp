#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec;
    cout << "vector size = " << vec.size() << "  capacity = " << vec.capacity() << endl;

    // used to add a new value to the vector; it adds the value at the end.
    vec.push_back(56);
    cout << "vector size = " << vec.size() << "  capacity = " << vec.capacity() << endl;
    vec.push_back(57);
    cout << "vector size = " << vec.size() << "  capacity = " << vec.capacity() << endl;
    vec.push_back(58);
    cout << "vector size = " << vec.size() << "  capacity = " << vec.capacity() << endl;

    cout << endl;
    vec.push_back(59);
    cout << "vector size = " << vec.size() << "  capacity = " << vec.capacity() << endl;
    cout << endl;

    vec.push_back(60);
    cout << "vector size = " << vec.size() << "  capacity = " << vec.capacity() << endl;
    vec.push_back(61);
    cout << "vector size = " << vec.size() << "  capacity = " << vec.capacity() << endl;

    cout << endl;

    // used to remove the last value
    vec.pop_back();
    cout << "vector size after pop = " << vec.size() << "  capacity after pop = " << vec.capacity() << endl;

    cout << endl;
    // used to access the last value
    cout << "last value " << vec.back() << endl;

    // used tp access index value
    cout << "0 index value " << vec.at(0) << endl;

    cout << endl;

    for (int val : vec)
    {
        cout << val << endl;
    }

    return 0;
}

// output command g++ basic.cpp && a.exe