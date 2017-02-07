/*************************************************************************************************
* Copyright (C) 2006-2017 All rights reserved.
* @Version: 1.0
* @Created: 2017-02-07 09:37
* @Author: u203,cplusu203@gmail.com
* @Description: quit sort algorithm
*
* @History: 
***************************************************************************************************/
#ifndef __SORT_ALGORITHM_QUICK_SORT_H__
#define __SORT_ALGORITHM_QUICK_SORT_H__

#include <vector>

namespace sort_algorithm
{

template <typename T>
int partition(std::vector<T>& data, int start, int end)
{
    int index = start - 1;
    for (int i = start; i < end; ++i)
    {
        if (data[i] >= data[end])
        {
            continue;
        }

        std::swap(data[++index], data[i]);
    }

    std::swap(data[++index], data[end]);
    return index;
}

template <typename T>
void quick_sort(std::vector<T>& data, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int index = partition(data, start, end);
    quick_sort(data, start, index-1);
    quick_sort(data, index+1, end);
}

}

#endif // end of __SORT_ALGORITHM_QUICK_SORT_H__


