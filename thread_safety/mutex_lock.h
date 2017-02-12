/*************************************************************************************************
* Copyright (C) 2006-2017 All rights reserved.
* @Version: 1.0
* @Created: 2017-02-05 14:13
* @Author: u203,cplusu203@gmail.com
* @Description: mutex encapsulation
*
* @History: 
***************************************************************************************************/
#ifndef __THREAD_SAFETY_MUTEX_LOCK_H__
#define __THREAD_SAFETY_MUTEX_LOCK_H__

#include <pthread.h>

#include "../base_class/noncopyable.h"

namespace thread_safety
{

class MutexLock : public base_class::noncopyable
{
public:
    MutexLock(void)
        : mutex_holder(0)
    {
        pthread_mutex_init(&mutex, NULL);
    }

    ~MutexLock(void)
    {
        pthread_mutex_destroy(&mutex);
    }

    pid_t get_mutex_holder(void) const
    {
        return mutex_holder;
    }

    pthread_mutex_t* get_pthread_mutex(void)
    {
        return &mutex;
    }

    void lock(pid_t _mutex_holder = 0)
    {
        pthread_mutex_lock(&mutex);
        mutex_holder = _mutex_holder;
    }

    void unlock(void)
    {
        mutex_holder = 0;
        pthread_mutex_unlock(&mutex);
    }
protected:

private:
    pthread_mutex_t mutex;
    pid_t mutex_holder;

}; // end of class MutexLock


class AutoMutexLock : public base_class::noncopyable
{
public:
    explicit AutoMutexLock(MutexLock& _mutex_lock) 
        : mutex_lock(_mutex_lock)
    {
        mutex_lock.lock();
    }

    ~AutoMutexLock(void)
    {
        mutex_lock.unlock();
    }

protected:

private:
    MutexLock& mutex_lock;

}; // end of class AutoMutexLock

} // end of namespace thread_safety

#endif // end of __THREAD_SAFETY_MUTEX_LOCK_H__


