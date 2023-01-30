#include <iostream>
#include <Example.h>

int main() {
	std::cout << msg() << "\n";
    int arr[5] = { 1, 2, 3, 4, 5 };
    Array<int> a(arr, 5);
    a.print();
    a.get(0);
    return 0;
	
}