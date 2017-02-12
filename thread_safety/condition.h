/*************************************************************************************************
* Copyright (C) 2006-2017 All rights reserved.
* @Version: 1.0
* @Created: 2017-02-05 16:35
* @Author: u203,cplusu203@gmail.com
* @Description: pthread_cont_t encapsulation
*
* @History: 
***************************************************************************************************/
#ifndef __THREAD_SAFETY_CONDITION_H__
#define __THREAD_SAFETY_CONDITION_H__

#include "mutex_lock.h"

namespace thread_safety
{

class Condition : public base_clas::noncopyable
{
public:
    explicit Condition(MutexLock& _mutex_lock)
        : mutex_lock(_mutex_lock)
    {
        pthread_cont_init(&condition, NULL);
    }

    ~Condition(void)
    {
        pthread_cont_destroy(&condition);
    }

    void wait(void)
    {
    
    }

    bool time_wait(int seconds)
    {
    
    }

    void notify(void)
    {
    
    }

    void notify_all(void)
    {
    
    }
protected:

private:
    MutexLock& mutex_lock;
    pthread_cont_t condition;

}; // end of class Condition

} // end of namespace thread_safety

#endif // end of __THREAD_SAFETY_CONDITION_H__


