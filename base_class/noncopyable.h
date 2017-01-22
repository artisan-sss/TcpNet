/*************************************************************************************************
* Copyright (C) 2006-2017 All rights reserved.
* @Version: 1.0
* @Created: 2017-01-22 15:36
* @Author: u203,cplusu203@gmail.com
* @Description: Noncopyable base class without dependecies
*
* @History: Source code from boost_1_63_0/boost/core/noncopyable.hpp
***************************************************************************************************/
#ifndef __BASE_CLASS_NONCOPYABLE_H__
#define __BASE_CLASS_NONCOPYABLE_H__

namespace base_class
{
class noncopyable
{
public:

protected:
    noncopyable(void) = default;
    ~noncopyable(void) = default;

private:
// Private copy constructor and copy assignment ensure classes derived from
//  class noncopyable cannot be copied.
    noncopyable(const noncopyable&) = delete;
    noncopyable& operator=(const noncopyable&) = delete;

}; // end of class noncopyable

} // end of namespace base_class

#endif // end of __BASE_CLASS_NONCOPYABLE_H__


