#include "Deque.h"
#include <iostream>
using namespace std;

//Gurveen Nanua
// 301546459

int main() {

     Deque<int> v; // Make an int queue 

     //enque items
     v.enqueue(1);
     v.enqueue(2);
     v.enqueue(3);
     v.enqueue(4);
     v.enqueue(5);

     v.display(); //diplay its contents

     //change the value like an array
     v[0] = 8; 
     v[4] = 10;

     v.display(); //see if the contents are changed
     


}