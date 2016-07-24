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
#include <iostream>
#include "Header.h"


template <typename Type>
 void swap ( Type *Mass , int firstIndex , int  secondIndex )
 {
 Type buffer = Mass[ secondIndex ];
 Mass[ secondIndex ] = Mass[ firstIndex ];
 Mass[ firstIndex ] = buffer ;
}

template <typename Type>
void printMass ( Type *Mass , int MassLenth )
{
    for(int numberOfelemnts = 0 ; numberOfelemnts < MassLenth ; numberOfelemnts++)
    {
        std::cout<<Mass[numberOfelemnts]<<" ";
    }
}

template <typename Type>
void scanMass ( Type *Mass , int MassLenth )
{
    for( int numberOfelemnts = 0 ; numberOfelemnts < MassLenth ; numberOfelemnts++)
    {
        std::cin >> Mass[ numberOfelemnts ];
    }
}

template <typename Type>
void copyMass ( Type *MassCopyto , Type *MassCopyFrom , int lenthOfMass )
{
    for( int  numberOfelements = 0 ; numberOfelements < lenthOfMass ; numberOfelements++ )
    {
        MassCopyto[ numberOfelements ] = MassCopyFrom[ numberOfelements ];
    }
}

template <typename Type>
void copyMass( Type *MassCopyto , Type *MassCopyFrom , int lenthOfmass , int FromIndex , int ToIndex )
{
    for( int  numberOfelements = FromIndex ; numberOfelements < ToIndex ; numberOfelements++ )
    {
        MassCopyto[ numberOfelements - FromIndex ] = MassCopyFrom[ numberOfelements ];
    }
}

template <typename Type>
int FindInsertIndex( Type *Mass , int MassLenthSort , Type valueToInsert )
{
    int InsertIndex = 0;
    
    for( int numberOfelements = 1 ; numberOfelements <= MassLenthSort ; numberOfelements++ )
    {
        if( Mass[ numberOfelements - 1 ] < valueToInsert && valueToInsert <= Mass[ numberOfelements ] )
        {
            InsertIndex =  numberOfelements;
        }
    }
    
    return InsertIndex;
}

template <typename Type>
void Insert(Type *Mass , int MassLenth ,int InsertFrom , int InserTo , Type *bufferMass )
{
    Type buffer = Mass[ InsertFrom ];
    int correctMainMass = 0 ;
    int correctBufferMass = 0;
    
    copyMass( bufferMass, Mass , MassLenth );
    for( int numberOfelements = 0 ; numberOfelements < MassLenth ; numberOfelements++ )
    {
        if( numberOfelements == InserTo )
        {
            correctMainMass++;
        }
        else if ( numberOfelements == InsertFrom )
        {
            correctBufferMass++;
        }
        Mass[ numberOfelements + correctMainMass ] = bufferMass[ numberOfelements + correctBufferMass ];
    }
    Mass[ InserTo ] = buffer;
}

template <typename Type>
int FindIndexOfSmallestFromIndex( int *mass , int lenthOfmass , int startIndex )
{
    int min_index  = startIndex;
    Type byffer = mass[ min_index ];
    
    for( int numberOfelements = startIndex ; numberOfelements < lenthOfmass ; numberOfelements++ )
    {
        if(mass[ numberOfelements ] < byffer )
        {
            min_index = numberOfelements;
            byffer = mass[ min_index ];
        }
    }
    
    return min_index;
}
template <typename Type>
void BoubleSort( Type *Mass , int lenthOfMass)
{
    bool swaped = false;
    
    while( !swaped )
    {
        swaped = true;
        for( int numberOfelemnts = 1 ; numberOfelemnts < lenthOfMass ; numberOfelemnts++ )
        {
            if( Mass[ numberOfelemnts - 1 ] > Mass[ numberOfelemnts ] )
            {
                swap( Mass , numberOfelemnts-1 , numberOfelemnts );
                swaped = false;
            }
        }
    }
}

template <typename Type>
void InsertSort( Type *Mass , int lenthOfMass )
{
    int insertIndex = 0;
    Type *bufferMass = new int[ lenthOfMass ];
    for( int numberOfelements = 0 ; numberOfelements < lenthOfMass ; numberOfelements++ )
    {
        insertIndex = FindInsertIndex( Mass , numberOfelements , Mass[ numberOfelements ] );
        if( numberOfelements != insertIndex )
        {
            Insert( Mass , lenthOfMass , numberOfelements , insertIndex , bufferMass );
        }
    }
    
}

template <typename Type>
void ChoiseSort(Type *mass , int lenthOfmass)
{
    for(int numberOfelemnts = 0 ; numberOfelemnts < lenthOfmass ; numberOfelemnts++)
    {
        swap(mass, numberOfelemnts, FindIndexOfSmallestFromIndex(mass, lenthOfmass, numberOfelemnts));
    }
}

/*void MergeSort(int *mass , int lenthOfmass)
 {
 
 if(lenthOfmass == 1)
 {
 return;
 }
 int leftSize = lenthOfmass/2;
 int rightSize = lenthOfmass - leftSize;
 int *leftMass = new int[leftSize];
 int *rightMass = new int[rightSize];
 copyMass(mass, leftMass, leftSize, 0, leftSize);
 copyMass(mass, rightMass, rightSize, rightSize, lenthOfmass);
 MergeSort(leftMass, leftSize);
 MergeSort(rightMass, rightSize);
 Merge(mass, leftMass, rightMass, leftSize, rightSize);
 }
 
 
 void Merge(int *items, int *left, int *right , int leftLength ,int rightLength )
 {
 int leftIndex = 0;
 int rightIndex = 0;
 int targetIndex = 0;
 int remaining = leftLength + rightLength;
 while(remaining != 0)
 {
 if (leftIndex == leftLength)
 {
 items[targetIndex] = right[rightIndex++];
 }
 else if (rightIndex == rightLength)
 {
 items[targetIndex] = left[leftIndex++];
 }
 else if (left[leftIndex] == right[rightIndex])
 {
 items[targetIndex] = left[leftIndex++];
 }
 else
 {
 items[targetIndex] = right[rightIndex++];
 }
 targetIndex++;
 remaining--;
 }
 }*/

#endif /* function_hpp */
