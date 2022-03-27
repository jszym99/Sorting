#include <iostream>
#include <chrono>
#include <math.h>
#include <time.h>
#include "tools.h"
#include "sort.h"

//! Generates file with special data sets
void genDataFile(int size, std::string fileName) {
    int *tab = new int[size];
    for (int i = 0; i < 10; i++) {
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
        quicksort(tab, size, true);
        saveToFile(tab, size, fileName);
    }
}
int main() {
    /*// Create data file for tests
    srand (time(NULL));
    int tabSize = 1000000;
    std::string fileName = "../1M.txt";
    genDataFile(tabSize, fileName);*/

    std::string dataSet [] = {"10k","50k","100k","500k","1M"};
    for(int i = 0; i < 5; i++) {
        std::string file = "../" + dataSet[i] + ".txt";
        std::cout << file << ",,,,,,,," << std::endl;
        int rows, columns;
        int *tab = new int[80 * 1000000];
        columns = readFile(tab, rows, file);
        int tabSize = rows * columns;
        int maxDepth = 2 * log2(tabSize);
        for (int i = 0; i < rows; i++) {
            //printTab(&tab[i*columns],columns);
            auto start = std::chrono::high_resolution_clock::now();
            quicksort(&tab[i * columns], columns, maxDepth);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            //std::cout << i+1 << ". " <<  duration.count() << " ms" << std::endl;
            if(i!=0 && i%8==0)
                std::cout << "\n";

            std::cout << duration.count() << ", ";
            //printTab(&tab[i*columns],columns);
        }
        std::cout << "\n";
    }
}
