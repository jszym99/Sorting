#include <iostream>
#include "sort.h"

//! Function printing table contents
template<typename TYPE>
void printTab(TYPE * tab, int Size) {
    for (int i = 0; i < Size; i++)
        std::cout << tab[i] << " ";

    std::cout << "\n";
}
template void printTab<int> (int *, int);
template void printTab<float> (float *, int);
template void printTab<double> (double *, int);
template void printTab<char> (char *, int);


/*//! Quicksort sorting
void quicksort(int *tab, int tabSize) {
    int pivot = tabSize / 2;
    // If table size is 1 it is sorted
    if (tabSize <= 1)
        return;

    int start = 0; // Start index
    int end = tabSize - 1; // End index

    int i = start;
    int j = end;
    // Look for numbers to swap
    while (i < j && pivot != start && pivot != end) {

        // going from the left
        while (tab[i] < tab[pivot] && i < j)
            i++;
        // Going from the right
        while (tab[j] > tab[pivot] && i < j)
            j--;

        // Move pivot if needed
        if (pivot == i)
            pivot = j;
        else if (pivot == j)
            pivot = i;

        // Swap and move iterators
        std::swap(tab[i++], tab[j--]);
    }

    //Sort left sub-array
    if (pivot != start)
        quicksort(tab, pivot);
    //Sort right sub-array
    if (pivot != end)
        quicksort(&tab[pivot + 1], end - pivot);

}
*/

int main() {
    int data[]{6, 1, 9, 2, 1, 0, 3, 6, 8, 2};
    float data2[] {1, 4.8, 6, -1.1, 6, -5, 9, 2, 0.5, -4 };
    char data3[] {'a', 'g', 't', 'n', 'l', 'i','p','s','b', 'w',};
    int dataSize = 10;
    std::cout << "Before sorting: ";
    printTab(data, dataSize);
    std::cout << "After sorting: ";
    quicksort<int> (data, dataSize);
    printTab(data, dataSize);

    std::cout << "\nBefore sorting: ";
    printTab(data2, dataSize);
    quicksort<float> (data2, dataSize);
    std::cout << "After sorting: ";
    printTab(data2, dataSize);

    std::cout << "\nBefore sorting: ";
    printTab(data3, dataSize);
    quicksort<char> (data3, dataSize);
    std::cout << "After sorting: ";
    printTab(data3, dataSize);
}
