//Embedded Design Lab 0 Problem 2 Sorting an Array of Integers
//This program creates a random array of integers then sorts them from smallest to largest then prints the array
//Tracy Qiu 9/14/20

#include <iostream>
#include <ctime> //used for srand function
using namespace std;

//set up function prototypes
void PrintArray(int v[], int size);
void RandomArray(int v[], int size);
void SortArray(int v[], int size);

//start of main
int main()
{
    int array[10]; //initialize the array to have ten integers
    int array_size = 10; //variable will the passed in the functions

    //call functions to create and print random array
    RandomArray(array, array_size);
    PrintArray(array, array_size);
    cout << "\n";
    //calls functions to sort and print array
    SortArray(array, array_size);
    PrintArray(array,array_size);
    cout << "\n";
    return 0;
} //end of main

//function takes in an array and prints it
void PrintArray(int v[], int size){
    //loops through the array and prints each element
    for (int i = 0; i<=size-1; i++)
        cout << v[i] << " " ;
}

//function creates a random array integers
void RandomArray(int v[], int size){
    //create the seed for random
    srand((unsigned)time(NULL));
    //loop through the array assigning each element a random int between 0 and 99
    for (int i = 0; i <= size-1; i++)
        v[i] = (rand()%100);
}

//function sorts an array of integers from smallest to largest using selection sort algorithm
//selection sort finds the smallest puts it as the minimum then continues to iterate
void SortArray(int v[], int size)
{
    //counter to loop through the array,index up to size-1 because last value v[size-1] gets sorted in j loop
    for (int i = 0; i < size-1; i++) {
        //index of the smallest integer, initialize as first value
        int min_index = i;
        //counter to loop through the array, starts with second element
        for (int j = i+1; j < size; j++){
            //if current element is smaller than smallest element
            if (v[j] < v[min_index]){
                //have a new minimum, change the index of the current minimum
                min_index = j;
            }
        }
        //if the index of the smallest element so far isnt the current element's index i, swap them
        if (min_index != i){
            int temp;
            //set temp to the current string
            temp = v[i];
            //replace the previously smallest int with the new smallest int
            v[i] = v[min_index];
            //replace the min_index element with the temporary value
            v[min_index] = temp;
        }
    }
}

/*
 * another way of writing the program
//function sorts an array of integers from smallest to largest
void SortArray(int v[], int size)
{
    int temp; //placeholder int used when values need to be swaped
    //counter to loop through size-1 times
    for (int j = 0; j<size; j++)
        //counter to sort values, index up to size-1 because last value v[i+1] gets sorted
        for (int i = 0; i < size-1; i++)
        {
            //if the current int is smaller than the next int
            if (v[i] > v[i+1])
            {
                //set temp to the current integer
                temp = v[i];
                //assign the next int to the current element
                v[i] = v[i+1];
                //replace the next element with the temp int
                v[i+1] = temp;
            }
        }
}
*/




