#include <iostream>

//统计当前输入数据的重复个数
int main(int argc,char *argv[])
{
    int curValue = 0,value,cnt = 1;

    /*
    if(条件判断)
    {

    }
    else
    {
        
    }
    */
    if(std::cin >> curValue)
    {
        while(std::cin >> value)
        {
            if(value == curValue)
                ++cnt;
            else
            {
                std::cout << curValue << " occurs " << cnt << " times" << std::endl;
                curValue = value;
                cnt = 1;
            }
        }

        std::cout << curValue << " occurs " << cnt << " times" << std::endl;
    }

    return 0;
}