//
//  DynamicProgramming.hpp
//  CTCI
//
//  Created by Xuewen on 10/14/17.
//  Copyright © 2017 Xuewen. All rights reserved.
//

#ifndef DynamicProgramming_hpp
#define DynamicProgramming_hpp

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>

class DP {
public:
    DP();
    ~DP();
    int binomialCoeff(int, int);
    int binomialCoeffDP(int, int);
    int binomialCoeffDPMem(int, int);
    int fiboTopDown(int);
    int lis(int[], int);
    int editDistance(std::string, std::string, int, int);
    int editDistanceDP(std::string, std::string, int, int);
    int printCountRec(int);
    int printCountDP(int);
    int lcs(char *, char *, int, int);
    int lcs_dp(char *, char *, int, int);
    int scs(char *, char *);
    int scs_rec(char *, char *, int, int);
    int scs_dp(char *, char *, int, int);
};

#endif /* DynamicProgramming_hpp */
