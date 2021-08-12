#include "array.h"
#include <iostream>

int main()
{
    Array<double> test(1000);
    std::cout << test.size() << std::endl;
    for (int i = 0; i < test.size(); i++)
    {
        test[i] = i;
        std::cout << test[i] << " ";
    }
}