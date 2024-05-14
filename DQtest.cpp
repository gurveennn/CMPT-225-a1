#include "Deque.h"
#include <iostream>
using namespace std;

// Gurveen Nanua
// 301546459

int main() {

    const int num = 10; 

    cout << "initialize the queue:" << endl; 
    Deque<int> v; // Make an int queue 
    v.display(); // print its contents 

    // reserve capacity for 10 elements
    v.reserve(10);
    v.ddisplay(); //check if capacity changed
    cout << "\n" << endl; 


    //enqueue num onto the queue and multiply by 2
    for(int i = 0; i < num; ++i){
        v.enqueue(i*2);
    }

    v.display(); //print the contents
    cout << "\n" << endl; 

    //remove an element from the front and back
    int value1 = v.dequeue();
    int value2 = v.eject(); 
   
    
    cout << "remove an element from the front and back:";
    v.display(); // prints the contents

    cout << "if elements returned are correct then print true:\n" << endl;  
     if ( (value1 + value2) == 18 ) {
        cout << "true" << endl;
   
    }

    cout << "\n" << endl; 

    //Insert a new object at the front and back
    v.enqueue(12);
    v.jump(8);

    cout << "insert 8 at front and 12 at back:" << endl; 
    v.display(); //print its contents
    cout << "\n" << endl; 

    //remove 2 elements from the back and add one element to the front
    v.eject();
    v.eject();
    v.jump(7);



    cout << "remove 2 elements from back and add 7 to the front:" << endl; 
    v.display(); 
    cout << "\n" << endl; 

    //pfint out contents for debugging
    cout << "ddsiplay for debugging:" << endl; 
    v.ddisplay(); 
    cout << "\n" << endl; 

    //clear the queue
    cout << "clear the queue:" << endl; 
    v.clear();
    v.display(); 
    



}
