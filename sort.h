//
// Created by jszym on 07/03/2022.
//

#ifndef SORTING_SORT_H
#include <iostream>
#include "tools.h"
#define SORTING_SORT_H


//! Partitions an array for quick sorting
template<typename TYPE>
int partition(TYPE * data, int dataSize, bool dwn = false);

//! Quicksort sorting
template<typename TYPE>
void quicksort(TYPE * data, int dataSize, bool dwn = false);

//! Mergesort sorting
template<typename TYPE>
void mergesort(TYPE * data, int dataSize, bool dwn = false);

//! Creates a heap from data in array
template<typename TYPE>
void heapify(TYPE *tab, int tabSize, int root, bool dwn);

//! Heapsort sorting
template<typename TYPE>
void heapsort(TYPE * data, int dataSize, bool dwn = false);

//! Insertion soring
template<typename TYPE>
void insertsort(TYPE * data, int dataSize, bool dwn = false);

//! Introspective sorting
template<typename TYPE>
void introsort(TYPE * data, int dataSize,int depth, bool dwn = false);

#endif //SORTING_SORT_H
