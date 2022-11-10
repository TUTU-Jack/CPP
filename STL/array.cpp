#include <iostream>
#include <array>
#include <time.h>
#include <stdlib.h>

#define MAX 500000

//比较函数
int comparefuction(const void* p1,const void* p2)
{
    const int* a = (const int*)p1;
    const int* b = (const int*)p2;

    if(*a < *b)
        return -1;
    else if(*a > *b)
        return 1;
    else
        return 0;

}

//简单使用 array 容器
int main(int argc,char* argv[])
{
    //创建一个 array 容器
    std::array<int,MAX> a;

    srand((unsigned)time(NULL));
    clock_t starttime = clock();
    for(int i = 0;i < a.size();i++)
        a.at(i) = rand()%MAX;
    std::cout << "spend time:" << clock() - starttime << std::endl;
    std::cout << "array size: " << a.size() << std::endl;
    std::cout << "The address of the first element: " << a.data() << std::endl;
    std::cout << "The value of the random element:" << a.at(rand()%MAX) << std::endl;

    int key = rand()%MAX;
    starttime = clock();
    //快速排序
    qsort(a.data(),a.size(),sizeof(int),comparefuction);
    //二分查找
    void* p = bsearch(&key,a.data(),a.size(),sizeof(int),comparefuction);
    std::cout << "spend time:" << clock() - starttime << std::endl;
    std::cout << "Find the element address:" << p << std::endl;
    std::cout << "Find the element data:" << *(const int*)p << std::endl;
    std::cout << "Key:" << key << std::endl;

    return 0;
}