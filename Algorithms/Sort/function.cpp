//
//  function.cpp
//  Sort_main
//
//  Created by Sasha on 19/07/16.
//  Copyright © 2016 Sasha. All rights reserved.
//

#include "function.hpp"
#include <iostream>

void swap ( int *Mass , int firstIndex , int  secondIndex )
{
    int buffer = Mass[ secondIndex ];
    Mass[ secondIndex ] = Mass[ firstIndex ];
    Mass[ firstIndex ] = buffer ;
}


void printMass ( int *Mass , int MassLenth )
{
    for(int numberOfelemnts = 0 ; numberOfelemnts < MassLenth ; numberOfelemnts++)
    {
        std::cout<<Mass[numberOfelemnts]<<" ";
    }
}

void scanMass ( int *Mass , int MassLenth )
{
    for( int numberOfelemnts = 0 ; numberOfelemnts < MassLenth ; numberOfelemnts++)
    {
        std::cin >> Mass[ numberOfelemnts ];
    }
}

void copyMass ( int *MassCopyto , int *MassCopyFrom , int lenthOfMass )
{
    for( int  numberOfelements = 0 ; numberOfelements < lenthOfMass ; numberOfelements++ )
    {
        MassCopyto[ numberOfelements ] = MassCopyFrom[ numberOfelements ];
    }
}

void copyMass( int *MassCopyto , int *MassCopyFrom , int lenthOfmass , int FromIndex , int ToIndex )
{
    for( int  numberOfelements = FromIndex ; numberOfelements < ToIndex ; numberOfelements++ )
    {
        MassCopyto[ numberOfelements - FromIndex ] = MassCopyFrom[ numberOfelements ];
    }
}


int FindInsertIndex( int *Mass , int MassLenthSort , int valueToInsert )
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

void Insert(int *Mass , int MassLenth ,int InsertFrom , int InserTo , int *bufferMass )
{
    int buffer = Mass[ InsertFrom ];
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


int FindIndexOfSmallestFromIndex( int *mass , int lenthOfmass , int startIndex )
{
    int min_index  = startIndex;
    int byffer = mass[ min_index ];
    
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



void BoubleSort( int *Mass , int lenthOfMass)
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

void InsertSort( int *Mass , int lenthOfMass )
{
    int insertIndex = 0;
    int *bufferMass = new int[ lenthOfMass ];
    for( int numberOfelements = 0 ; numberOfelements < lenthOfMass ; numberOfelements++ )
    {
        insertIndex = FindInsertIndex( Mass , numberOfelements , Mass[ numberOfelements ] );
        if( numberOfelements != insertIndex )
        {
            Insert( Mass , lenthOfMass , numberOfelements , insertIndex , bufferMass );
        }
    }
    
}

void ChoiseSort(int *mass , int lenthOfmass)
{
    for(int numberOfelemnts = 0 ; numberOfelemnts < lenthOfmass ; numberOfelemnts++)
    {
        swap(mass, numberOfelemnts, FindIndexOfSmallestFromIndex(mass, lenthOfmass, numberOfelemnts));
    }
}

void MergeSort(int *mass , int lenthOfmass)
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
}


