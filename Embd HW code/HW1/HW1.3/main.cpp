//Embedded Design Homework 1 Problem 3
//This problem mirrors values in an array
//Tracy Qiu ID 001313852 9/30/20

#include <iostream>

using namespace std;

//function mirrors a given array of integers
void mirror(int v[], int size){
    //counter for 0 to less than half the size
    //this indexes up to the middle element
    //size/2 rounds down to lower whole number, so this works for array with odd number of values
    for (int i = 0; i < size/2; i++){
        //set the front element as temp
        int temp = v[i];
        //assign the back element to the front element
        v[i] = v[size-1-i];
        //assign the temp to the back element
        v[size-1-i] = temp;
    }
}

int main()
{
    // Declare array
    int v[] = {5, 6, 7, 8, 2, 1};
    // Mirror it
    mirror(v, 6);
    // Print array
    for (int i = 0; i < 6; i++)
        cout << v[i] << '\n';
    return 0;
}