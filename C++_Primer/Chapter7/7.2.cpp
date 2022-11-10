#include <iostream>
#include <string>
#include <vector>

class Screen;

//窗口类
class Window_mgr {
    public:
        //窗户中每个屏幕的编号
        using ScreenIndex = std::vector<Screen*>::size_type;
    public:
        void clear(ScreenIndex);
    private:
        std::vector<Screen*> sc;
    public:
        Window_mgr();
        ~Window_mgr();
};

//屏幕类
class Screen {
    public:
        typedef std::string::size_type pos;
    public:
        //得到光标位置字符
        char get_char() const { return content[position]; };
        //得到指定位置的字符
        char get_char(pos r,pos c) const;
        //移动光标到指定位置
        Screen& move(pos r,pos c);

        //设置指定位置的字符
        Screen &set_char(pos r,pos c,char ch);
        //设置光标位置的字符
        Screen &set_char(char ch);

        //显示屏幕字符
        const Screen& display(std::ostream &os) const { do_display(os); return *this; };
        Screen& display(std::ostream &os) { do_display(os); return *this; };
    private:
        //显示屏幕字符
        void do_display(std::ostream &os) const;
    private:
        std::string content;    //屏幕内容
        pos position;           //光标位置
        pos width;              //屏幕宽度
        pos height;             //屏幕高度
    public:
        //默认构造函数
        Screen() = default;
        //构造函数重载（带参构造函数）
        Screen(const char c,const pos width,const pos height):content(height*width,c),width(width),height(height),position(0) { };
        //委托构造函数，当一个构造函数参数是另一个构造函数的子集时，为了简化书写，可以使用委托构造函数
        Screen(const pos width,const pos height):Screen('\0',width,height) { };
    
    //友元函数
    friend void Window_mgr::clear(ScreenIndex);
};

inline char Screen::get_char(pos r,pos c) const 
{
    return content[width*r+c];
}

inline Screen& Screen::move(pos r,pos c)
{
    position = r*width + c;
    return *this;
}

inline Screen& Screen::set_char(char ch)
{
    content[position] = ch;
    return *this;
}

inline Screen& Screen::set_char(pos r,pos c,char ch)
{
    content[r*width+c] = ch;
    return *this;
}

inline void Screen::do_display(std::ostream &os) const
{
    int i = 0,j = 0;
    for(i = 0;i < height;i++)
    {
        for(j = 0;j < width;j++)
            os << content[i*width+j];
        
        os << std::endl;
    }
}


inline Window_mgr::Window_mgr() 
{ 
    Screen* p = new Screen('\0',24,80);
    sc.push_back(p); 
};

inline Window_mgr::~Window_mgr()
{
    for(auto it : sc)
        delete[] it;
}

inline void Window_mgr::clear(ScreenIndex i)
{
    Screen* p = sc[i];

    p->content = std::string(p->height*p->width,'\0');
}


int main(int argc,char *argv[])
{
    Screen MyScreen('#',5,3);
    const Screen blank('r',5,3);
    MyScreen.set_char(2,2,'t').display(std::cout);
    std::cout << std::endl;
    blank.display(std::cout);

    return 0;
}