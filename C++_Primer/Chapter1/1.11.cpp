#include <iostream>

int main(int argc,char* argv[])
{
    int n1 = 0,n2 = 0;
    
lab:
    std::cout << "Enter two numbers:";
    std::cin >> n1 >> n2;

    if(n1 > n2)
        goto lab;

    std::cout << "Integer" << "(" << n1 << "-" << n2 << "):";

    while(n1 < n2 - 1)
    {
        std::cout << ++n1 << " ";
    }

    std::cout << std::endl;


    return 0;
}