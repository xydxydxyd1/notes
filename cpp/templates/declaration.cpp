#include <iostream>
#include <string>
using namespace std;

// declaration
template<typename T> T templatedFunction(T val);

// explicit instantiation declaration
// template char templatedFunction<char>(char val);

// explicit instantiation definition
template<>
char templatedFunction<char>(char val)
{
    return val + 1;
}

int main()
{
	cout << templatedFunction(5) << endl;
	cout << templatedFunction('a') << endl;
	cout << templatedFunction(9.8) << endl;
}

template<typename T> T templatedFunction(T val)
{
    return val;
}
