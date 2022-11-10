#include <iostream>

int main(int argc,char *argv[])
{
    std::cout << "Enter two numbers:";

    //定义整型变量
    int n1 = 0,n2 = 0;   
    //输入流，接收用户输入数据  
    std::cin >> n1 >> n2;
    //输出两数之积，表达式，程序语句由表达式构成
    std::cout << "n1 * n2 = " << n1*n2 << std::endl;

    return 0;
}