#include <iostream>

int main(int agrc,char *argv[])
{
    int i = 0,sum = 0;
    /*
    for(初始化语句;循环条件;表达式)
    {
        循环体
    }

    for 与 while 本质上没有区别，for 一般用于已知范围内的循环，while 用于带有终止条件的循环
    */
    for(i = 50;i <= 100;i++)
    {
        sum += i;
    }

    std::cout << "sum = " << sum << std::endl;
    return 0;
}