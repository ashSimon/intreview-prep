#include <iostream>
#include <vector>
#include "Headers/utility.hpp"


// Enums
enum class BulbSize {
    SMALL,
    MEDIUM,
    LARGE
};

class Bulb {
private:
    // Instance Variable
    BulbSize size;
public:
    // Instance Method 
    BulbSize getBulbSize() {
        return size;
    }
    // Instance method
    void setBulbSize(BulbSize s) {
        size = s;
    }
    // Others Bulb classes and fields
};

// CONSTANT
const std::string text = "Hello world!";

// CONDITION AND LOOPS
std::vector<int> numbers = {1,2,3,4,5,6,7,8,9,10};

// ARRAY
int arr[10] = {0,1,2,3,4,5,6,7,8,9};


// VECTOR
std::vector<int> vec;
void printVec(std::vector<int> &data) {
    int count = data.size();
    std::cout << "Valued stored are: ";
    for(int i = 0; i < count; i++) {
        std::cout << data[i] << " ";
    }
}

// SYSTEM STACK AND METHOD CALLS
void function2() {
    std::cout << "func2 line " << std::endl;
}

void function1() {
    std::cout << "func1 line 1" << std::endl;
    function2();
    std::cout << "func1 line 2 " << std::endl;
}


// RECURSIVE FUNCTION
// factorial 
int factorial(int integer) {
    // termination condition 
    if (integer <= 1) {
        return 1;
    }
    // Body,Recursive Expansive
    return integer * factorial(integer - 1);
}

// print base 10 Integer s 
// void printInt1(int number) {
//     char digit = static_cast<int>(number % 10 + '0');
//     number = number / 10;
//     if (number != 0) {
//         printInt1(number);
//     }
//     std::cout << digit;
// }

// print base 16 Integer s 
// void printInt2(int number, int const base) {
//     std::string converstion = "123456789ABCDEF";
//     char digit = static_cast<int>(number%base);
//     number = number / base;
//     if (number != 0) {
//         printInt2(number, base);
//     }
//     std::cout << " " << converstion[digit];
// }

// TOWER OF HANOI

void tower_of_hanoi(int num, char src, char dst, char temp) {
    if (num < 1) return;
    tower_of_hanoi(num - 1, src, temp, dst);
    std::cout << "Move " << num << " disk from peg " << src << " to peg " << dst << std::endl;
    tower_of_hanoi(num - 1, temp, dst, src);
}

// GREATEST COMMON DIVISOR

int _gcd(int m, int n) {
    if (m < n) return (_gcd(m,n));
    if (m % n == 0) return (n);
    return _gcd(n, m%n);
}

// FIBONNACI NUMBER 
int fibonnaci(int n) {
    if (n <= 1) return n;
    return fibonnaci(n - 1) + fibonnaci(n - 2);
}


// ALL PERMUTATION OF AN INTEGER ARRAY
void permutation(std::vector<int> &data, int i, int length) {
    if (length == i) {
        printArray(data, length);
        return;
    }
    int j = i;
    for (j = i; j < length; j++) {
        swap(data, i, j);
        permutation(data, i + i, length);
        swap(data, i, j);
    }
    return;
}

// BINARY SEARCH USING RECURSION
int binarySearchRecursion(std::vector<int> &data, int low, int high, int value) {
    int mid = low + (high - low) / 2; // avoid overflow 
    if (data[mid] == value) return mid;
    else if (data[mid] < value) {
        return binarySearchRecursion(data, mid + 1, high, value);
    } else {
        return binarySearchRecursion(data, low, mid - 1, value);
    }
}

int main() {

    // Bulb b;
    // b.setBulbSize(BulbSize::MEDIUM);
    // std::cout << "Bulb Size: " << (int)b.getBulbSize() << std::endl;

    // std::cout << text << std::endl;

    // int sum = 0;

    // while(i < numbers.size()) {
    //     sum += numbers[i];
    //     i++;
    // }

    // for(int i = 0; i < 100; i++) {
        // vec.push_back(i);
    // }
    // printVec(vec);

    

    // for(int i = 0; i < numbers.size(); i++) {
    //     sum += numbers[i];
    // }
    // forEach loop
    // for(auto n: arr) {
    //     sum += n;
    // }

    // std::cout << "Sum is: " << sum << std::endl;

    // std::cout << "main line 1" << std::endl;
    // function1();
    // std::cout << "main line 2" << std::endl;

    // // std::cout << "base 10: " << printInt1(5) << std::endl;
    // printInt1(100);
    
    //  printInt2(5, 16);

    // int num = 4;
    // std::cout << "The sequence of moves in tower of hanoi:" << std::endl;
    // tower_of_hanoi(num, 'A', 'B', 'C');

    // std::cout << "fibonnaci " << fibonnaci(10) << std::endl;
    // std::vector<int> arr = {1,2,3,4,10,1200000};
    // std::cout << "We are finding 4 using binary search " << binarySearchRecursion(arr, 0,arr.size(), 5);
    return 0;
}