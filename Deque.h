#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
using namespace std;

template <typename Object>
class Deque 
{
  public:
    Deque()
      {  
         theCapacity = 8 ;
         objects = new Object[ theCapacity ]; 
         theSize = 0 ;
         front = 0 ; 
         back = 0 ; 
      }
      
    ~Deque( )
      { delete [ ] objects; }

    bool empty( ) const  { return size( ) == 0; }
    int size( ) const { return theSize; }
    void clear( ){
        // remove all contents and reset the capacity to it's initial value 
        // Implement this...
       
        theSize = 0;
        front = 0;
        back = 0; 
        
        theCapacity = 8; 
        
    }

    void reserve( int newCapacity )
    {
        // change the capacity to newCapacity 
        // (provided it is larger than the current size)
        // 
        // Implement this...
        if( newCapacity > theSize){
          Object * newarray = new Object [newCapacity];
          for (int i = 0; i < theSize; ++i){
            newarray[i] = objects[i];
          }
          Object *temp = objects;
          objects = newarray;
          delete [] temp; 
          theCapacity = newCapacity; 
        }
        
    }

    // Operations 

    void enqueue( const Object & x )// Insert a new object at the back 
    {
        if( theSize == theCapacity ) reserve( 2 * theCapacity + 1 );
        objects[ back ] = x ; 
        back = (back+1) % theCapacity ;
        theSize++ ;
    }

    void jump( const Object & x )// Insert a new object at the front 
    {
        // Implement this 
        if (theSize == theCapacity) {
          reserve( 2 * theCapacity + 1); 
        }
        front = (front - 1 + theCapacity) % theCapacity;
        objects[front] = x; 
        theSize++; 
    }

    Object dequeue( )// Remove and return the object at the front 
    {
        theSize--;
        Object temp = objects[front];
        front = (front+1) % theCapacity ;
        return temp;
    }

    Object eject( )// Remove and return the object at the back 
    {
        // Implement this
        theSize--;
        back = (back - 1 + theCapacity) % theCapacity; 
       
        return objects[back];  
    }

    void display() const // print out the contents of the deque
    {
       // Implement this.  The output should be similar to that 
       // used in the Vector and Stack classes provided.
      
       cout << "size:" << theSize << endl; 
       
       cout << "< ";
       int index = front; 
       for(int i = 0; i < theSize; ++i){
          cout << i << "=" << objects[index] << ", ";
          index = (index + 1) % theCapacity; //wrap around the array
       }
       cout << ">" << endl; 
    }

    void ddisplay() const // print out the contents of the objects 
    // array, and relevant variables, for debugging or verifying 
    // correctness. 
    {
        // Implement this.  The output should be in the style used in 
        // Vector and Stack classes provided.
        cout << "capacity = " << theCapacity << ", size = " << theSize << endl; 

        cout << "[ ";
        int index = front;
        for(int i = 0; i < theCapacity; ++i){
          cout << i << "=" << objects[index] << ", ";
          index = (index + 1) % theCapacity; //wrap aroud the array 
        }
        cout << "]" << endl; 
    }

    //implemaent operator[] for array like access
    Object& operator[](const int & x)
    {
      int index = (x % theCapacity);
      return objects[index]; 
    }


  private:
    int theSize;
    int front;
    int back;
    int theCapacity;
    Object * objects;
};

#endif
