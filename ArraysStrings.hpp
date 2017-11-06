//
//  ArraysStrings.hpp
//  CTCI
//
//  Created by Xuewen on 9/24/17.
//  Copyright © 2017 Xuewen. All rights reserved.
//

#ifndef ArraysStrings_hpp
#define ArraysStrings_hpp

#include <stdio.h>
#include <string>
#include <unordered_map>

using namespace std;

class ArraysandStrings {
public:
    ArraysandStrings();
    ~ArraysandStrings();
    bool IsUnique(string);
    bool IsPermutation0(string, string);
    bool IsPermutation(string, string);
    void URLify(string&, int);
    bool IsPalinPerm(string);
    void quickSort(int [], int, int);
    void mergeSort(int [], int, int);
};

#endif /* ArraysStrings_hpp */
