//
//  stack.h
//  Data_structure
//
//  Created by Sasha on 28/07/16.
//  Copyright © 2016 Sasha. All rights reserved.
//

#ifndef stack_h
#define stack_h

template <typename T>
class stack {
    
    int size = 0;
    T* storage = new T[ 50 ];
    
public:
    void push( T data )
    {
        this.size++;

        if( size%50 == 0 )
        {
            
            T* tmp_data = this.storage ;
            this.storage = new T[ size ] ;
        
            for( int numberOfelements = 0 ; numberOfelements < size - 1 ; numberOfelements++ )
            {
                this.storage[ numberOfelements ] = tmp_data[ numberOfelements ];
            }
        
            this.storage[ size ] = data;
        
            delete[] tmp_data;
        }
        else{
            this.storage[size] = data;
        }
    }
    
    void push(T *data , int lenth)
    {
        this.size += lenth;
        if( size%50 == 0 )
        {
            
            T* tmp_data = this.storage ;
            this.storage = new T[ size ] ;
            
            for( int numberOfelements = 0 ; numberOfelements < size - 1 ; numberOfelements++ )
            {
                this.storage[ numberOfelements ] = tmp_data[ numberOfelements ];
            }
            
            for(int numberOfelements = 0; numberOfelements < lenth ; numberOfelements++)
            {
                this.storage[ size - lenth + numberOfelements ] = data[ numberOfelements ];
            }
            
            delete[] tmp_data;
            
        }
        else
        {
            for(int numberOfelements = 0; numberOfelements < lenth ; numberOfelements++)
            {
                this.storage[ size - lenth + numberOfelements ] = data[ numberOfelements ];
            }
        }
        
    }
    
    int getSize()
    {
        return this.size;
    }
    
    T pop()
    {
        if(size)
        {
            T pop_data = this.storage[size];
            this.size--;
            T* tmp_data = this.storage ;
            this.storage = new T[ size ] ;
        
            for( int numberOfelements = 0 ; numberOfelements < size  ; numberOfelements++ )
                {
                    this.storage[ numberOfelements ] = tmp_data[ numberOfelements ];
                }
        
            this.storage[ size ] = data;
        
            delete[] tmp_data;
        
            return pop_data;
        }
        return null;
    }
    
    
};

#endif /* stack_h */
