//Embedded Design Lab 0 Problem 3 Sorting an Array of Strings
//This program takes in user input of 10 strings and sorts and prints them in alphabetical order
//Tracy Qiu 9/14/20

#include <iostream>
#include <string> //can use string type
using namespace std;

//set up function prototypes
void PrintArray(string v[], int size);
void SortArray(string v[], int size);

//start of main
int main()
{
    //initialize the array of 10 strings
    string array[10];
    int array_size = 10;
    //asking for user input of ten strings
    cout << "Please enter ten strings, click enter after each one\n";

    //counter to loop through each string inputted
    for (int i = 0; i < array_size; i++)
    {
        //assigning user input string as input variable
        string input;
        cin >> input;
        //assigning input as element i of the array
        array[i] = input;
    }

    //call functions to sort and print the array
    SortArray(array, array_size);
    PrintArray(array,array_size);
    cout << "\n";
    return 0;
} //end of main

//function prints array
void PrintArray(string v[], int size){
    //loops through elements of the array and print them
    for (int i = 0; i<=size-1; i++)
        cout << v[i] << " " ;
}

//function sorts an array of strings in alphabetical order using selection sort algorithm
//selection sort finds the smallest puts it as the minimum then continues to iterate
void SortArray(string v[], int size)
{
    //counter to loop through the array,index up to size-1 because last value v[size-1] gets sorted in j loop
    for (int i = 0; i < size-1; i++) {
        //index of the string with letter earliest in alphabet, initialize as first value
        int min_index = i;
        //counter to loop through the array, starts with second element
        for (int j = i+1; j < size; j++){
            //if current element is before the than smallest element in the alphabet
            if (v[j] < v[min_index]){
                //have a new front of the alphabet, change the index of the current minimum
                min_index = j;
            }
        }
        //if the index of the smallest element so far isnt the current element's index i, swap them
        if (min_index != i){
            string temp;
            //set temp to the current string
            temp = v[i];
            //replace the previously smallest string with the new smallest string
            v[i] = v[min_index];
            //replace the min_index element with the temporary value
            v[min_index] = temp;
        }
    }
}



/*
 * another way of writing the program
//function sorts an array of strings in alphabetical order
void SortArray(string v[], int size)
{
    string temp; //placeholder string used when strings need to be swapped
    //counter to loop through size-1 times
    for (int j = 0; j<size; j++)
        //counter to sort values up to index size-1 because last value v[i+1] will be sorted
        for (int i = 0; i < size-1; i++)
        {
            //if the letters of the first string come after the letters of the second string in the alphabet
            if (v[i] > v[i+1])
            {
                //set temp to the current string
                temp = v[i];
                //assign the next string to the current element
                v[i] = v[i+1];
                //replace the next element with the temp string
                v[i+1] = temp;
            }
        }
}
 */


