//Embedded Design Homework 1 Problem 1
//This problem creates swaps values using pass by pointer and pass by reference
//Tracy Qiu ID 001313852 9/30/20

#include <iostream>

using namespace std;

//function swaps the values of two integers using pass by pointer
void SwapP(int *x, int *y){
    //initialize temp value as pointer x
    int temp = *x;
    //*x points to what *y is pointing to
    *x = *y;
    //*y points to what temp is pointing to
    *y = temp;
}

//function swaps the values of two integers using pass by reference
void SwapR(int &x, int &y){
    //initialize temp as the value of dereferenced x
    int temp = x;
    //assign the value of y to x
    x = y;
    //assign the value of temp to y
    y = temp;
}


int main() {
    //initialize x and y
    int x = 3;
    int y = 5;

    //call SwapP function, swap using pass by pointer
    SwapP(&x, &y);
    cout << "The value of x: " << x;
    cout << "\nThe value of y: " << y;

    //call SwapR function, swap using pass by reference
    SwapR(x, y);
    cout << "\nThe value of x: " << x;
    cout << "\nThe value of y: " << y;

    return 0;
}



