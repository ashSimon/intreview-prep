#include <iostream>
#include <vector>
#include "./Headers/utility.hpp"

// printarray
void printArray(std::vector<int> &arr)
{
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void swap(std::vector<int> &data, int x, int y) {
    int temp = data[x];
    data[x] = data[y];
    data[y] = temp;
}