#include <iostream>
#include <string>


class Person {
    public:

        std::string get_name() const { return name; };
        int get_age() const { return age; };
        std::string get_address() const { return address; };

        void set_name(const std::string &name) { this->name = name; };
        void set_age(const int age) { this->age = age; };
        void set_address(const std::string &address) { this->address = address; };
    private:
        std::string name;
        int age;
        std::string address;
    public:
        //显示使用默认构造函数
        Person() = default;
        Person(const std::string& name,int age,const std::string& address):name(name),age(age),address(address) {};
};

//操作符重载，输出对象
std::ostream& operator << (std::ostream& os,const Person& person)
{
    os << "Name:" << person.get_name() << "\tAge:" << person.get_age() << "\tAddress:" << person.get_address();

    return os;
}


int main(int argc,char *argv[])
{
    Person person("ths",22,"royal");

    std::cout << "Name:" << person.get_name() << "\tAge:" << person.get_age() << "\tAddress:" << person.get_address() << std::endl;
    std::cout << person << std::endl << std::endl;

    person.set_address("ShangHai");
    std::cout << person << std::endl;


    return 0;
}