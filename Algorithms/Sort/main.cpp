//
//  main.cpp
//  Sort_main
//
//  Created by Sasha on 19/07/16.
//  Copyright © 2016 Sasha. All rights reserved.
//

#include "Header.h"

int main(int argc, const char * argv[]) {
    
    int lenthOfmass = 5;
    int *mass = new int[lenthOfmass];
    
    scanMass<int>(mass, lenthOfmass);
    //BoubleSort<int>(mass, lenthOfmass);
    MergeSort<int>(mass , lenthOfmass);
    printMass<int>(mass, lenthOfmass);
    
    return 0;
}

