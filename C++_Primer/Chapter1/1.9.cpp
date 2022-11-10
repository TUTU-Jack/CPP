#include <iostream>

int main(int argc,char *argv[])
{
    int i = 50,sum = 0;

    /*
        while(循环条件)
        {
            循环体
        }
    */
    while(i <= 100)
    {
        sum += i;
        i++;
    }

    std::cout << "sum = " << sum << std::endl;

    return 0;
}