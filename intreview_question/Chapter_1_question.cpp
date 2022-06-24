#include <iostream>
#include <vector>
#include "../Headers/utility.hpp"

// prototypes
void reverseArray(std::vector<int> &arr, int start, int end);

// ARRAY INTREVIEW QUESTION
int sum_array(std::vector<int> &arr) {
    int size = arr.size();
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// SEQUENTIAL SEARCH
int sequentialSearch(std::vector<int> &arr, int value) {
    int size = arr.size();
    for(int i = 0; i < size; i++) {
        if (value == arr[i]) return arr[i];
    }
    return -1;
}

// BINARY SEARCH
int binarySearch(std::vector<int> &arr, int value) {
    int size = arr.size();
    int mid;
    int low = 0;
    int high = size - 1;
    while(low <= high) {
        mid = low + (high - low) / 2; // to avoid overflow;
        if (arr[mid] == value) return arr[mid];
        else {
            if(arr[mid] < value) low = mid + 1;
            else high = mid - 1;
        }
    }
    return -1;
}

// ROTATING AN ARRAY BY K-POSITIONS
void rotateArray(std::vector<int> &arr, int k) {
    int n = arr.size();
    reverseArray(arr, 0, k - 1);
    reverseArray(arr, k, n - 1);
    reverseArray(arr, 0, n - 1);
}

void reverseArray(std::vector<int> &arr, int start, int end) {
    for (int i = start, j = end; i < j; i++, j--) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}


// FIND THE LARGEST SUM CONTIGUES SUBARRAY
int maxSubArraySum(std::vector<int> &arr) {
    int size = arr.size();
    int maxSoFar = 0, maxEndingHere = 0;

    for(int i = 0; i < size; i++) {
        maxEndingHere = maxEndingHere + arr[i];
        if (maxEndingHere < 0) maxEndingHere = 0;
        if (maxSoFar < maxEndingHere) maxSoFar = maxEndingHere; 
    }

    return maxSoFar;
}

// Exercise 
// 1. find average of all elements in an array
int average_of_array(std::vector<int> &arr) {
    int size = arr.size();
    int average = 0;
    for (int i = 0; i < size; i++) {
        average += arr[i];
    }
    average = average / size;
    return average;
}
// 2. Find the sum of all the elements of a two dimensional array
int sum_of_array(std::vector<std::vector<int>> &arr) {
    int size = arr.size();
    int sum = 0;
    for (int row = 0; row < size; row++) {
        for (int column = 0;  column < arr[row].size(); column++) {
            sum += arr[row][column];
        }
    }
    return sum;
}


// 3. find the largest element in the array
int maximum_in_array(int arr[], int size) {
    int max = arr[0];
    for(int i = 0; i < size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }    
    return max;
}

// 4. find the smallest element in the array
int minimun_in_array(int arr[], int size) {
    int min = arr[0];
    for(int i = 0; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// 5. find the second largest element in the array
int maximum_second(std::vector<int> &arr) {
    int max = arr[0];
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > max) {
            max = arr[i];
            
        }
        if (max > arr[i + 1]) {
            max = arr[i];
        }
    }

    return max;
}

// 6. Print all maxima's in a array 
void print_maxima(std::vector<int> &arr) {
    int max = arr[0];
    for(int i = 1; i < arr.size(); i++) {
        if (arr[i] > max) {
            std::cout << max << std::endl;   
        }
    }
}

int main() {
    // std::vector<std::vector<int>> vect = {{1,2,3,4,5},{6,7,8,9,10}};
    // std::cout << "sum of a two dimensional array is: " << sum_of_array(vect);
    std::vector<int> arr =  {5,6,20,100,50,200,10000};
    // std::cout << "Second largest element of array is: " << maximum_second(arr) << std::endl;
    print_maxima(arr);
    return 0;
}