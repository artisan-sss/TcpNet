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

#include <algorithm>

namespace sort_algorithm
{

template <typename BidirIter, typename UnaryPredicate>
BidirIter partition(BidirIter first, BidirIter last, UnaryPredicate pred)
{
    BidirIter middle = first;
    BidirIter key = last-1;
    while (first < last)
    {
        if (pred(first))
        {
            std::swap(*middle, *first);
            ++middle;
        }

        ++first;
    }

    std::swap(*middle, *--last);
    return middle;
}

template <typename BidirIter>
void quick_sort(BidirIter first, BidirIter last)
{
    if (first == last)
    {
        return;
    }

    auto key = *(last-1);
    BidirIter middle = sort_algorithm::partition(first, last, [key](BidirIter first){return *first < key;});
    quick_sort(first, middle);
    quick_sort(++middle, last);
}

}

#endif // end of __SORT_ALGORITHM_QUICK_SORT_H__


