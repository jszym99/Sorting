//
// Created by jszym on 27/03/2022.
//

#include "tools.h"

//! Prints 1D array contents
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

template<typename TYPE>
void swap(TYPE & a, TYPE & b)
{
    TYPE tmp = a;
    a = b;
    b = tmp;
}
template void swap<int>(int &, int &);
/*template void swap<float>(float *, float *);
template void swap<double>(double *, double *);
template void swap<char>(char *, char *);*/

//! Reads data from special file
int readFile(int * tab,int & row, std::string fileName)
{
    std::ifstream file;
    file.open(fileName);
    if(!file) {
        std::cerr << "Error: file couldn't be opened" << std::endl;
        return 0;
    }
    std::string line;
    int num;
    row = 0;
    int col = 0;
    char ch;
    while(std::getline(file, line))
    {
        std::stringstream ss(line);
        while(ss >> num)
        {
            tab[col] = num;
            col++;
            //ss >> ch;
        }
        row++;
    }

    file.close();
    return col/row;
}

//! Generates 1D array of random numbers between min and max
void genRandomTab(int * tab, int length, int min, int max)
{
    for(int i=0; i < length; i++)
    {
        tab[i] = rand() % ((max+1)-min) + min;
    }
}

//! Saves data from 1D array to a file
void saveToFile(int * tab, int tabSize, std::string fileName)
{
    std::ofstream file;
    file.open(fileName, std::ios_base::app);
    for(int i =0; i<tabSize;i++)
    {
        file << tab[i] << " ";
    }
    file << "\n";
    file.close();
}