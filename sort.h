//
// Created by jszym on 07/03/2022.
//

#ifndef SORTING_SORT_H
#include <iostream>
#define SORTING_SORT_H

//! Function printing table contents
template<typename TYPE>
void printTab(TYPE * tab, int Size);

//! Quicksort sorting
template<typename TYPE>
void quicksort(TYPE * data, int dataSize);

//! Mergesort sorting
template<typename TYPE>
void mergesort(TYPE * data, int dataSize);

#endif //SORTING_SORT_H
