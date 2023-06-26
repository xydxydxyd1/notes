#include <iostream>
#include <concept>

template<typename T>
concept HasName = requires(T a)
{
    a.name;
};

int main()
{
}
