#include <iostream>
#include <string>

//全局变量
int globalVarible;

using PF = int(*)(int);

int Function(int a)
{
    std::cout << "形参：" << ++a << std::endl;

    return 0;
}

const int& Function(int a,int &b)
{
    //静态局部变量，作用域为函数内部，但生命周期为全局
    static int staticLocalVarible = 0;
    staticLocalVarible++;

    b++;
    std::cout << "静态局部变量：" << staticLocalVarible << std::endl;
    std::cout << "引用：" << b << std::endl;
    std::cout << "引用地址：" << &b << std::endl << std::endl;

    return b;
}

int* Function(int *c)
{
    (*c)++;

    std::cout << "指针值：" << *c << std::endl;
    std::cout << "指针地址：" << c << std::endl << std::endl;
    return c;
}

//（由内向外）函数本身为 Function 参数为 const std::string &str，函数返回值为函数指针，指向的函数的参数为 int ，返回类型为 int
int (*Function(const std::string &str))(int)
{
    std::cout << str << std::endl;

    return Function;
}


int main()
{
    int a = 0;
    //函数传形参，为值传递，不改变变量本身
    Function(a);
    std::cout << "a:" << a << std::endl << std::endl;

    int b = 0;
    //函数传实参，引用传递,函数返回值为常引用，不可更改引用变量值
    const int &reference = Function(a,b);
    std::cout << "varible b value:" << b << std::endl;
    std::cout << "varible b address:" << &b << std::endl;
    std::cout << "reference value:" << reference << std::endl;
    std::cout << "reference address:" << &reference << std::endl << std::endl;
    //reference = 3; error

    //函数内部有静态局部变量，再次调用，静态局部变量跳过初始化（只初始化一次），值继续更改
    Function(a,b);
    std::cout << "reference value:" << reference << std::endl << std::endl;

    //函数参数为指针变量，传入变量地址会改变变量值
    int *pointer = Function(&globalVarible);
    std::cout << "global varible value:" << globalVarible << std::endl;
    std::cout << "global varible address:" << &globalVarible << std::endl;
    std::cout << "pointer varible value:" << *pointer << std::endl;
    std::cout << "pointer varible address:" << pointer << std::endl << std::endl;


    //函数返回类型为函数指针
    PF ff = Function("Hello World");
    printf("Function address:%p\n",&ff);

    ff = Function;
    printf("Function address:%p\n",&ff);
}