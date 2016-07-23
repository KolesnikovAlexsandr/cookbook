//
//  main.cpp
//  Sort_main
//
//  Created by Sasha on 19/07/16.
//  Copyright © 2016 Sasha. All rights reserved.
//

#include <iostream>
#include "Header.h"
#include "function.hpp"

int main(int argc, const char * argv[]) {
    
    int lenthOfmass = 5;
    int *mass = new int[lenthOfmass];
    
    scanMass(mass, lenthOfmass);

    MergeSort(mass , lenthOfmass);
    printMass(mass, lenthOfmass);
    
    return 0;
}

