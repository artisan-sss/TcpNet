/*************************************************************************************************
* Copyright (C) 2006-2017 All rights reserved.
* @Version: 1.0
* @Created: 2017-02-05 16:38
* @Author: u203,cplusu203@gmail.com
* @Description: 
*
* @History: 
***************************************************************************************************/
#ifndef __THREAD_SAFETY_CONDITION_WAITER_H__
#define __THREAD_SAFETY_CONDITION_WAITER_H__

#include "condition.h"
#include "../base_class/noncopyable.h"

namespace thread_safety
{

class ConditionWaiter : public base_class::noncopyable
{
public:
    ConditionWaiter()
        : condition(mutex_lock), 
        signaled(false)
    {}

    ~ConditionWaiter(void)
    {}

    void wait(void)
    {
        AutoMutexLock guard(mutex_lock);
        while (!signaled)
        {
            condition.wait();
        }
        // only one thread awaked
        signaled = false;
    }

    void unicast(void)
    {
        AutoMutexLock guard(mutex_lock);
        signaled = true;
        condition.notify();
    }

    void broadcast(void)
    {
        AutoMutexLock guard(mutex_lock);
        signaled = true;
        condition.notify_all();
    }
protected:

private:
    MutexLock mutex_lock;
    Condition condition;
    bool signaled;
};

} // end of namespace thread_safety

#endif // end of __THREAD_SAFETY_CONDITION_WAITER_H__


