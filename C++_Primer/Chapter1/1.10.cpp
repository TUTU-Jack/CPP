#include <iostream>

int main(int argc,char* argv[])
{
    int i = 9;

    std::cout << "Integeter(0-10):";
    while(i > 0)
    {
        std::cout << i-- << " ";
    }
    std::cout << std::endl;

    return 0;
}