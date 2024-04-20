#include <iostream>
#include "windows.h"
using namespace std;

bool isPalindrome(int num) {
    int reversedNum = 0;
    int originalNum = num;

    while (num > 0) {
        int remainder = num % 10;
        reversedNum = reversedNum * 10 + remainder;
        num /= 10;
    }

    return originalNum == reversedNum;
}

void fillArrayWithPalindromes(int arr[], int size) {
    int num = 0;
    int count = 0;

    while (count < size) {
        if (isPalindrome(num)) {
            arr[count] = num;
            count++;
        }
        num++;
    }
}

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    const int size = 25;
    int arr[size];

    fillArrayWithPalindromes(arr, size);

    cout << "Array of palindromes: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int target;
    cout << "Enter a number to search: ";
    cin >> target;

    int index = binarySearch(arr, size, target);

    if (index != -1) {
        cout << "Number " << target << " found at position " << index << endl;
    }
    else {
        cout << "Number " << target << " not found in the array" << endl;
    }

    return 0;
}