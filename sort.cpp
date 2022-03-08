//
// Created by jszym on 07/03/2022.
//

#include "sort.h"

//! Function printing table contents
template<typename TYPE>
void printTab(TYPE *tab, int Size) {
    for (int i = 0; i < Size; i++)
        std::cout << tab[i] << " ";

    std::cout << "\n";
}

template void printTab<int>(int *, int);

template void printTab<float>(float *, int);

template void printTab<double>(double *, int);

template void printTab<char>(char *, int);

//! Quicksort sorting
template<typename TYPE>
void quicksort(TYPE *data, int dataSize) {

    // If table size is 1 it is sorted
    if (dataSize <= 1)
        return;

    int start = 0; // Start index
    int end = dataSize - 1; // End index
    int pivot = dataSize / 2;

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

template void quicksort<int>(int *, int);
template void quicksort<float>(float *, int);
template void quicksort<double>(double *, int);
template void quicksort<char>(char *, int);

//! Mergesort sorting
template<typename TYPE>
void mergesort(TYPE *data, int dataSize) {

    // If table size is 1 it is sorted
    if (dataSize <= 1)
        return;

    int start = 0; // Start index
    int end = dataSize - 1; // End index
    int mid = dataSize / 2;

    // Copy data to two separate sublists
    TYPE leftSublist[mid]; // Left part sublist (start to middle)
    for (int i = 0; i < mid; i++)
        leftSublist[i] = data[i];

    TYPE rightSublist[dataSize - mid]; // Right sublist (middle to end)
    for (int i = 0; i < dataSize - mid; i++)
        rightSublist[i] = data[mid + i];

    //Sort left sublist
    if (mid > start)
        mergesort<TYPE>(&leftSublist[0], mid);
    //Sort right sublist
    if (mid <= end)
        mergesort<TYPE>(&rightSublist[0], dataSize - mid);

    int l = 0; // Left sublist iterator
    int r = 0; // Right sublist iterator

    // Sort and marge data from sorted sublists
    for (int i = 0; i < dataSize; i++) {
        if (l >= mid) // Left sublist is empty
            data[i] = rightSublist[r++]; // Copy remaining data
        else if (r >= dataSize - mid) // Right sublist is empty
            data[i] = leftSublist[l++]; // Copy remaining data
        else if (leftSublist[l] <= rightSublist[r])
            data[i] = leftSublist[l++];
        else if (rightSublist[r] < leftSublist[l])
            data[i] = rightSublist[r++];
    }
}

template void mergesort<int>(int *, int);
template void mergesort<float>(float *, int);
template void mergesort<double>(double *, int);
template void mergesort<char>(char *, int);