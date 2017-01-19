#include <cstdlib>
#include <cstdio>

#include "../base_template/singleton.h"

class SingletonTest
{
public:
    SingletonTest(void)
    {
        printf("SingletonTest constructor!!!\n");
    }

    ~SingletonTest(void)
    {
        printf("SingletonTest destructor!!!\n");
    }

    inline void say_hello(void)
    {
        printf("hello, this is SingletonTest!!!\n");
    }
private:
    SingletonTest(SingletonTest&);
    SingletonTest& operator=(SingletonTest&);

}; // end of Class Singleton

void test_singleton_template(void)
{
    SingletonTest& singleton_test = base_template::Singleton<SingletonTest>::instance();
    for (int i = 0; i < 10; ++i)
    {
        singleton_test.say_hello();
    }
}


int main()
{
    test_singleton_template();

    return 1;
}


