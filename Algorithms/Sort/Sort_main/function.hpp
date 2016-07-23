//
//  function.hpp
//  Sort_main
//
//  Created by Sasha on 19/07/16.
//  Copyright © 2016 Sasha. All rights reserved.
//

#ifndef function_hpp
#define function_hpp

#include <stdio.h>
//help function
void swap           ( int *mass , int first , int second );

void printMass      ( int *mass , int massLenth );

void scanMass       ( int *mass , int massLenth );

void Insert         ( int *mass , int massLenth , int InsertFrom , int InserTo);

int  FindInsertIndex( int *mass , int massLenth , int valueToInsert );

void copyMass       ( int *massCopyto , int *massCopyFrom , int lenthOfmass );

void Merge          ( int *items , int *left , int *right , int leftLength , int rightLength );



//sort function
void BoubleSort ( int *mass , int lenthOfmass );
void InsertSort ( int *mass , int lenthOfmass );
void ChoiseSort ( int *mass , int lenthOfmass );
void MergeSort  ( int *mass , int lenthOfmass );
#endif /* function_hpp */
