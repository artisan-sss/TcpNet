#include <cstdlib>
#include <cstdio>

/*
 * clang++ version 3.5.0+
 */
#include "../base_template/singleton.h"
#include "../base_class/noncopyable.h"
#include "../thread_safety/mutex_lock.h"

class SingletonTest : public base_class::noncopyable
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
    //SingletonTest(SingletonTest&);
    //SingletonTest& operator=(SingletonTest&);

}; // end of Class Singleton

void test_singleton_template(void)
{
    SingletonTest& singleton_test = base_template::Singleton<SingletonTest>::instance();
    for (int i = 0; i < 10; ++i)
    {
        singleton_test.say_hello();
    }
}

#include <cstdlib>
#include <vector>
#include <stdlib.h>

#include "../sort_algorithm/quick_sort.h"

void test_quit_sort(int count)
{
    //std::vector<int> data(count);
    int* data = new int[count];
    srand((unsigned)time(NULL));
    for (int i = 0; i < count; ++i)
    {
        data[i] = rand()%1000;
        printf("%d ", data[i]);
    }
    printf("\n");

    //sort_algorithm::quick_sort(data.begin(), data.end());
    sort_algorithm::quick_sort(&data[0], &data[count-1] + 1);
    for (int i = 0; i < count; ++i)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}

int main()
{
    printf("main function first code line!!!\n");

    thread_safety::MutexLock mutex_lock;
    thread_safety::AutoMutexLock guard(mutex_lock);

    test_singleton_template();

    test_quit_sort(10);

    printf("main function before return code line!!!\n");
    return 1;
}


