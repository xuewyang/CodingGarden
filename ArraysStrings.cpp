//
//  ArraysStrings.cpp
//  CTCI
//
//  Created by Xuewen on 9/24/17.
//  Copyright © 2017 Xuewen. All rights reserved.
//

#include "ArraysStrings.hpp"

ArraysandStrings::ArraysandStrings(){}
ArraysandStrings::~ArraysandStrings(){}

bool ArraysandStrings::IsUnique(string str) {
    // suppose string is ASCII
    if (str.length() > 128)
        return false;
    bool unique[128] = {false};
    for (int i = 0; i < str.length(); i++) {
        int val = str[i];
        if (!unique[val])
            unique[val] = true;
        else
            return false;
    }
    return true;
}

bool ArraysandStrings::IsPermutation0(string str1, string str2) {
    // assume ASCII
    if (str1.length() != str2.length())
        return false;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return str1 == str2;
}

bool ArraysandStrings::IsPermutation(string str1, string str2) {
    // assume ASCII
    if (str1.length() != str2.length())
        return false;
    int len = int(str1.length());
    int res[128] = {0};
    for (int i = 0; i < len; i++) {
        res[int(str1[i])] += 1;
        res[int(str2[i])] -= 1;
    }
    for (int j = 0; j < 128; j++)
        if (res[j] != 0)
            return false;
    return true;
}

void ArraysandStrings::URLify(string& str, int n) {
    // first determine the final length of the string.
    int count = 0;
    for (int i = 0 ; i < n; i++)
        if (str[i] == ' ')
            count++;
    int finalLength = n + 2*count;
    str[finalLength] = '\0';
    int index = finalLength-1;
    for (int j = n-1; j >= 0; j--) {
        if (str[j] != ' ') {
            str[index] = str[j];
            index--;
        }
        else {
            str[index] = '0';
            str[index-1] = '2';
            str[index-2] = '%';
            index-=3;
        }
    }
}

bool ArraysandStrings::IsPalinPerm(string str) {
    // assume ASCII
    unordered_map<int, int> um;
    int odd = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ')
            continue;
        int val = int(str[i]);
        if (val >= 'a' && val <= 'z')
            val -= int('a');
        else {
            if (val >= 'A' && val <= 'Z')
                val -= int('A');
            else
                return false;  // cannot be outside of A-Z and a-z.
        }
        
        um[val] += 1;
        if (um[val] % 2 == 1)
            odd++;
        else
            odd--;
    }
    return odd <= 1;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int j = low - 1;
    for (int i = low; i < high; i++) {
        if (arr[i] < pivot) {
            j++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[j+1], &arr[high]);
    return j+1;
}

void ArraysandStrings::quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high);
    }
}

void merge(int arr[], int l, int m, int r) {
    int leftArr[m-l+1], rightArr[r-m];
    for (int i = 0; i < m-l+1; i++)
        leftArr[i] = arr[i+l];
    for (int i = 0; i < r-m; i++)
        rightArr[i] = arr[i+m+1];
    
    int i = 0, j = 0, k = l;
    while (i < m-l+1 && j < r-m) {
        if (leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }
    while (i < m-l+1)
        arr[k++] = leftArr[i++];
    while (j < r-m)
        arr[k++] = rightArr[j++];
}

void ArraysandStrings::mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
