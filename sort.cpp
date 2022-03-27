//
// Created by jszym on 07/03/2022.
//

#include "sort.h"

// Data size below which insertion sorting is used
#define useInsert 16
// Depth from which quicksort is no longer used
#define qcDepth 0

//! Partitions an array for quick sorting
template<typename TYPE>
int partition(TYPE *data, int dataSize, bool dwn) {
    int start = 0; // Start index
    int end = dataSize - 1; // End index
    int pivot = data[start]; // Take first element of the array as a pivot value
    int pivotIndex = 0; //Pivot index

    // Move pivot to the center
    for(int i = start; i < end;i++)
    {
        if(data[i+1] <= pivot)
            pivotIndex++;
    }
    // Swap two values
    swap(data[pivotIndex],data[start]);

    int i = start; // Iteration from the left
    int j = end; // Iteration from the right


    // Look for numbers to swap
    while(i < pivotIndex && j > pivotIndex)
    {
        // going from the left
        while(data[i] <= pivot)
            i++;
        // going from the right
        while(data[j] > pivot)
            j--;
        if (i < pivotIndex && j > pivotIndex)
            swap(data[i++],data[j--]);
    }
    return pivotIndex;
}
template int partition<int>(int *, int, bool);
/*template int partition<float>(int *, int, bool);
template int partition<double>(int *, int, bool);
template int partition<char>(int *, int, bool);*/

//! Quicksort sorting
template<typename TYPE>
void quicksort(TYPE *data, int dataSize, bool dwn) {

    // If table size is 1 it is sorted
        if (dataSize <= 1)
            return;

    int start = 0; // Start index
    int end = dataSize - 1; // End index

    // Divide the array
    int pivot = partition(data,dataSize,dwn);

    //Sort left sub-array
    if (pivot != start)
        quicksort<TYPE>(data, pivot, dwn);
    //Sort right sub-array
    if (pivot != end)
        quicksort<TYPE>(&data[pivot + 1], end - pivot, dwn);

}

template void quicksort<int>(int *, int, bool);
/*template void quicksort<float>(float *, int, bool);
template void quicksort<double>(double *, int, bool);
template void quicksort<char>(char *, int, bool);*/

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

/*template void mergesort<float>(float *, int, bool);
template void mergesort<double>(double *, int, bool);
template void mergesort<char>(char *, int, bool);*/

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
        swap(tab[parentIndex], tab[maxIndex]);

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
        swap(data[0], data[dataSize - i]);
        // Heapify the unsorted part of the array
        heapify(data, dataSize - i, 0, dwn);
    }

}

template void heapsort<int>(int *, int, bool);
/*template void heapsort<float>(float *, int, bool);
template void heapsort<double>(double *, int, bool);
template void heapsort<char>(char *, int, bool);*/

//! Insertion soring
template<typename TYPE>
void insertsort(TYPE * data, int dataSize, bool dwn)
{
    // If table size is 1 it is sorted
    if(dataSize <= 1)
        return;
    // Iterate through the array
    for(int i = 1; i < dataSize;i++)
    {
        // Move the smallest value to the beginning of the array
        while(!dwn*(data[i] < data[i-1]) || dwn*(data[i] > data[i-1]))
        {
            swap(data[i], data[i-1]);
        }
    }
    insertsort(data,dataSize-1,dwn);
}
template void insertsort<int>(int *, int, bool);
/*template void insertsort<float>(int *, int, bool);
template void insertsort<double>(int *, int, bool);
template void insertsort<char>(int *, int, bool);*/

//! Introspective sorting
template<typename TYPE>
void introsort(TYPE * data, int dataSize,int depth, bool dwn)
{
    int start = 0; // Start index
    int end = dataSize - 1; // End index

    if(dataSize < useInsert) {
        insertsort(data, dataSize, dwn);
        return;
    } else if(depth <= qcDepth){

        // Heapify entire array from the bottom
        for (int i = 0; i <= dataSize/2; i++)
        {
            heapify(data, dataSize, dataSize/2 - i, dwn);
        }
        swap(data[0], data[dataSize - 1]);
        //printTab(data,dataSize);
        introsort(data,dataSize-1, depth, dwn);

    } else {
        // Divide the array
        int pivot = partition(data, dataSize, dwn);

        //Sort left sub-array
        if (pivot != start)
            introsort<TYPE>(data, pivot, depth-1, dwn);
        //Sort right sub-array
        if (pivot != end)
            introsort<TYPE>(&data[pivot + 1], end - pivot, depth-1, dwn);
    }

}
template void introsort<int>(int *, int, int, bool);
/*template void introsort<float>(int *, int, int, bool);
template void introsort<double>(int *, int, int, bool);
template void introsort<char>(int *, int, int, bool);*/