// https://en.cppreference.com/w/cpp/language/partial_specialization
// Partial specialization of templates allow one to customize template
// for specific sets of arguments

#include <iostream>

template<typename T1, typename T2>
class is_pointer
{
public:
	static const bool value = false;
};

template<typename T2>
class is_pointer<T2*, T2>
{
public:
	static const bool value = true;
};

int main()
{
	std::cout << is_pointer<int*, int>::value << std::endl;
	std::cout << is_pointer<float*, int>::value << std::endl;
}
