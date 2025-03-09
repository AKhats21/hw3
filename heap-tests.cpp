#include <iostream>
#include <fstream>
#include <functional>
#include "heap.h"
using namespace std;

int main()
{
    // Heap<int,greater<int>> testing = Heap<int, greater<int>>();
    Heap<int> testing;
    testing.push(1);
    testing.push(4);
    testing.push(3);
    testing.push(8);
    testing.push(7);
    testing.pop();
    
    cout << testing.top() << endl;


    return 0;
}