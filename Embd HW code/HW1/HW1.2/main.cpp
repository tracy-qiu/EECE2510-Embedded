//Embedded Design Homework 1 Problem 2
//This program swaps pointers but does not change the values of x and y
//Tracy Qiu ID 001313852 9/30/20

# include <iostream>

using namespace std;

//function swaps the pointers by passing pointers by reference
void PointerSwap(int *&p1, int *&p2){
    //create temp pointer that points to what p1 is pointing to
    int *temp;
    temp = p1;
    //point p1 to p2 address then p2 to temp address
    p1 = p2;
    p2 = temp;
}

//code provided by assignment
int main()
{
    //initialize the values of x and y
    int x = 1, y = 9;
    int *p1, *p2;
    //p1 and p2 point to dereferenced values of x and y
    p1 = &x;
    p2 = &y;
    cout << *p1 << " and " << *p2 << endl; //displays "1 and 9"
    cout << x << " and " << y << endl;    //displays "1 and 9"

    //call PointerSwap function
    PointerSwap(p1, p2);
    cout << *p1 << " and " << *p2 << endl;   //displays "9 and 1"
    cout << x << " and " << y << endl;    //displays "1 and 9"
    return 0;
}
