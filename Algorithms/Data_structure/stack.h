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
    T* storage = new T[ 0 ];
    
public:
    void push( T data )
    {
        this.size++;
        T* tmp_data = this.storage ;
        this.storage = new T[ size ] ;
        
        for( int numberOfelements = 0 ; numberOfelements < size - 1 ; numberOfelements++ )
        {
            this.storage[ numberOfelements ] = tmp_data[ numberOfelements ];
        }
        
        this.storage[ size ] = data;
        
        delete[] tmp_data;
    }
    
    T pop()
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
    
    
};

#endif /* stack_h */
