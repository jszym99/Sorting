//
// Created by jszym on 27/03/2022.
//

#ifndef SORTING_TOOLS_H
#include <iostream>
#include <fstream>
#include <sstream>
#define SORTING_TOOLS_H


//! Prints 1D array contents
template<typename TYPE>
void printTab(TYPE * tab, int Size);

//! Swaps two values by reference
template<typename TYPE>
void swap(TYPE & a, TYPE & b);

//! Reads data from special file
int readFile(int * tab,int & row, std::string fileName);

//! Generates 1D array of random numbers between min and max
void genRandomTab(int * tab, int length, int min, int max);

//! Saves data from 1D array to a file
void saveToFile(int * tab, int tabSize, std::string fileName);

#endif //SORTING_TOOLS_H
