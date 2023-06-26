#include <iostream>
using namespace std;

template<int T>
class TemplatedClass
{
public:
	int get_T() { return T; }
private:
};

int main()
{
	TemplatedClass<5> templatedA;
	cout << templatedA.get_T() << endl;

	const int runtimeVal = 5;
	// int runtimeVal = 5;	// E: needs to be const
	TemplatedClass<runtimeVal> templatedB;
	cout << templatedB.get_T() << endl;
}
