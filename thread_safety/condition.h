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
#include <cerrno>

namespace thread_safety
{

class Condition : public base_class::noncopyable
{
public:
    explicit Condition(MutexLock& _mutex_lock)
        : mutex_lock(_mutex_lock)
    {
        pthread_cond_init(&condition, NULL);
    }

    ~Condition(void)
    {
        pthread_cond_destroy(&condition);
    }

    void wait(void)
    {
        pthread_cond_wait(&condition, mutex_lock.get_pthread_mutex());
    }

    bool time_wait(int seconds)
    {
        struct timespec absolute_time;
        clock_gettime(CLOCK_REALTIME, &absolute_time);
        absolute_time.tv_sec += seconds;
        return ETIMEDOUT == 
            pthread_cond_timedwait(&condition, mutex_lock.get_pthread_mutex(), &absolute_time);
    }

    void notify(void)
    {
        pthread_cond_signal(&condition);
    }

    void notify_all(void)
    {
        pthread_cond_broadcast(&condition);
    }
protected:

private:
    MutexLock& mutex_lock;
    pthread_cond_t condition;

}; // end of class Condition

} // end of namespace thread_safety

#endif // end of __THREAD_SAFETY_CONDITION_H__


