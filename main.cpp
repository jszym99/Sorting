#include <iostream>
#include <chrono>
#include <math.h>
#include <time.h>
#include "tools.h"
#include "sort.h"

//! Generates file with special data sets
void genDataFile(int size, std::string fileName) {
    for (int i = 0; i < 10; i++) {
        int *tab = new int[size];
        genRandomTab(tab, size, -1000, 1000);
        saveToFile(tab, size, fileName);
        quicksort(tab, size / 4);
        saveToFile(tab, size, fileName);
        quicksort(tab, size / 2);
        saveToFile(tab, size, fileName);
        quicksort(tab, size * 3 / 4);
        saveToFile(tab, size, fileName);
        quicksort(tab, size * 95 / 100);
        saveToFile(tab, size, fileName);
        quicksort(tab, size * 99 / 100);
        saveToFile(tab, size, fileName);
        quicksort(tab, size * 997 / 1000);
        saveToFile(tab, size, fileName);
        heapsort(tab, size, true);
        saveToFile(tab, size, fileName);
        delete[] tab;
        std::cout << i << " done" << std::endl;
    }
}
int main() {
    std::string dataSet [] = {"10k","50k","100k","500k","1M"};

    // Create data file for tests
    /*int tabSize[] = {10000, 50000, 100000, 500000, 1000000};
    srand (time(NULL));
    for(int i = 0; i < 5;i++){
        std::string fileName = "../Data/" + dataSet[i] + ".txt";
        genDataFile(tabSize[i], fileName);
        std::cout << dataSet[i] << " done\n" << std::endl;
    }*/

    // Test sorting algorithm
    for(int i = 0; i < 5; i++) {
        std::string file = "../Data/" + dataSet[i] + ".txt";
        std::cout << dataSet[i]  << ",,,,,,,," << std::endl;
        int rows, columns;
        int *tab = new int[80 * 1000000];
        columns = readFile(tab, rows, file);
        int tabSize = rows * columns;
        int maxDepth = 2 * log2(tabSize);
        for (int j = 0; j < rows; j++) {
            auto start = std::chrono::high_resolution_clock::now();
            //! Uncomment sorting option
            //quicksort(&tab[j * columns], columns);
            //heapsort(&tab[j * columns], columns);
            //mergesort(&tab[j * columns], columns);
            //insertsort(&tab[j * columns], columns);
            introsort(&tab[j * columns], columns, maxDepth);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            if(j!=0 && j%8==0)
                std::cout << "\n";

            std::cout << duration.count() << ", ";
        }
        std::cout << "\n";
    }

    //For testing
    /*int data[] = {6, 1, 9, 2, 1, 0, 3, 6, 8, 2,1, 4, 6, 1, 6, 5, 9, 2, 0, 4};
    int dataSize = 20;
    int maxDepth = 2*log2(dataSize);
    std::cout << "Before sorting: ";
    printTab(data, dataSize);
    std::cout << "After sorting: ";
    mergesort<int> (data, dataSize);
    printTab(data, dataSize);*/

    /*int rows, columns;
    int *tab = new int[80 * 1000000];
    columns = readFile(tab, rows, "../Data/1M.txt");
    int tabSize = rows * columns;

    for (int i = 0; i < rows; i++) {
        //printTab(&tab[i*columns],columns);
        auto start = std::chrono::high_resolution_clock::now();
        quicksort(&tab[i * columns], columns);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        //std::cout << i+1 << ". " <<  duration.count() << " ms" << std::endl;
        if(i!=0 && i%8==0)
            std::cout << "\n";

        std::cout << duration.count() << ", ";
        //printTab(&tab[i*columns],columns);
    }*/
}
