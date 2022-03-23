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
void quicksort(TYPE *data, int dataSize, bool dwn) {

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
        while ((!dwn*(data[i] < data[pivot]) || dwn*(data[i] > data[pivot])) && i < j)
            i++;
        // Going from the right
        while ((!dwn*(data[j] > data[pivot]) || dwn*(data[j] < data[pivot])) && i < j)
            j--;

        // Move pivot if needed
        if (pivot == i)
            pivot = j;
        else if (pivot == j)
            pivot = i;

        // Swap and move iterators
        TYPE tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
        i++;
        j--;
    }

    //Sort left sub-array
    if (pivot != start)
        quicksort<TYPE>(data, pivot, dwn);
    //Sort right sub-array
    if (pivot != end)
        quicksort<TYPE>(&data[pivot + 1], end - pivot, dwn);

}

template void quicksort<int>(int *, int, bool);
/*template void quicksort<float>(float *, int);
template void quicksort<double>(double *, int);
template void quicksort<char>(char *, int);*/

//! Mergesort sorting
template<typename TYPE>
void mergesort(TYPE *data, int dataSize, bool dwn) {

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
        mergesort<TYPE>(&leftSublist[0], mid, dwn);
    //Sort right sublist
    if (mid <= end)
        mergesort<TYPE>(&rightSublist[0], dataSize - mid, dwn);

    int l = 0; // Left sublist iterator
    int r = 0; // Right sublist iterator

    // Sort and marge data from sorted sublists
    for (int i = 0; i < dataSize; i++) {
        if (l >= mid) // Left sublist is empty
            data[i] = rightSublist[r++]; // Copy remaining data
        else if (r >= dataSize - mid) // Right sublist is empty
            data[i] = leftSublist[l++]; // Copy remaining data
        else if (!dwn*(leftSublist[l] <= rightSublist[r]) || dwn*(leftSublist[l] > rightSublist[r]))
            data[i] = leftSublist[l++];
        else if (!dwn*(leftSublist[l] > rightSublist[r]) || dwn*(leftSublist[l] <= rightSublist[r]))
            data[i] = rightSublist[r++];
    }
}

template void mergesort<int>(int *, int, bool);

/*template void mergesort<float>(float *, int);
template void mergesort<double>(double *, int);
template void mergesort<char>(char *, int);*/

//! Creates a heap from data in array
template<typename TYPE>
void heapify(TYPE *tab, int tabSize, int parentIndex, bool dwn) {

    int lChildIndex = parentIndex * 2 + 1; // left child index
    int rChildIndex = parentIndex * 2 + 2; // right child index
    int maxIndex = parentIndex; // index of the largest number in the sub-tree

    // Paren must be larger than any child
    if (lChildIndex <= tabSize - 1 && (!dwn*(tab[lChildIndex] > tab[maxIndex]) || dwn*(tab[lChildIndex] < tab[maxIndex])))
        maxIndex = lChildIndex;
    if (rChildIndex <= tabSize - 1 && (!dwn*(tab[rChildIndex] > tab[maxIndex]) || dwn*(tab[rChildIndex] < tab[maxIndex])))
        maxIndex = rChildIndex;

    // Swap parent with the largest child
    if (maxIndex != parentIndex) {
        std::swap(tab[parentIndex], tab[maxIndex]);

        // Heapify the modified sub-tree
        heapify(tab, tabSize, maxIndex, dwn);
    }
}

template void heapify<int>(int *, int, int, bool);

//! Heapsort sorting
template<typename TYPE>
void heapsort(TYPE *data, int dataSize, bool dwn) {
    // Heapify entire array from the bottom
    for (int i = 0; i <= dataSize/2; i++)
    {
        heapify(data, dataSize, dataSize/2 - i, dwn);
    }

    // Heapify entire array from the top
    for(int i = 1; i < dataSize; i++) {
        // Move sorted number to the end of the array
        std::swap(data[0], data[dataSize - i]);
        // Heapify the unsorted part of the array
        heapify(data, dataSize - i, 0, dwn);
    }

}

template void heapsort<int>(int *, int, bool);
/*template void heapsort<float>(float *, int);
template void heapsort<double>(double *, int);
template void heapsort<char>(char *, int);*/