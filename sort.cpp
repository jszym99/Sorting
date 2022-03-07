//
// Created by jszym on 07/03/2022.
//

#include "sort.h"

//! Quicksort sorting
template<typename TYPE>
void quicksort(TYPE * data, int dataSize) {
    int pivot = dataSize / 2;
    // If table size is 1 it is sorted
    if (dataSize <= 1)
        return;

    int start = 0; // Start index
    int end = dataSize - 1; // End index

    int i = start;
    int j = end;
    // Look for numbers to swap
    while (i < j && pivot != start && pivot != end) {

        // going from the left
        while (data[i] < data[pivot] && i < j)
            i++;
        // Going from the right
        while (data[j] > data[pivot] && i < j)
            j--;

        // Move pivot if needed
        if (pivot == i)
            pivot = j;
        else if (pivot == j)
            pivot = i;

        // Swap and move iterators
        std::swap(data[i++], data[j--]);
    }

    //Sort left sub-array
    if (pivot != start)
        quicksort<TYPE>(data, pivot);
    //Sort right sub-array
    if (pivot != end)
        quicksort<TYPE>(&data[pivot + 1], end - pivot);

}

template void quicksort<int> (int *, int);
template void quicksort<float> (float *, int);
template void quicksort<double> (double *, int);
template void quicksort<char> (char *, int);

