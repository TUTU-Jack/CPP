#include <iostream>

int main(int argc,char *argv[])
{
    int value = 0,sum = 0;

    std::cout << "Enter the number:";
    //流结束条件（接收到文件结束符 EOF 或 接收错误 (接收数据类型不符))
    //键盘输入 ctrl + D 表示结束
    while(std::cin >> value)
    {
        sum += value;
    }

    std::cout << "sum = " << sum << std::endl;

    return 0;
}