//Embedded Design Lab 1 Dynamically Growing Arrays in C++
//This program takes user input to add elements to an array and grow, shrink the array
//Tracy Qiu ID 001313852 9/21/20

#include <iostream>
#include <cstdlib>

using namespace std;

//declare global variables
double *v; //pointer to the first element in a sequence of elements
int vsize; //number of elements inserted in vector
int capacity; //number of elements currently allocated for a vector

//function declarations
void Initialize(); //initializes global variables
void Finalize(); //free memory associated with the vector
void Grow(); //grows the capacity of the vector
void PrintVector(); //prints elements in vector
void AddElement(); //adds an element to the end of the vector
void RemoveElement(); //removes an element from the end of the vector
void InsertElement(); //inserts an element in specified index of vector
void Shrink(); //shrinks the capacity of the vector

int main() {
    //initialize the global variables
    Initialize();

    //print the menu
    cout << "\nMain menu: \n" <<
         "1. List vector's contents\n" <<
         "2. Append element at the end\n" <<
         "3. Remove last element\n" <<
         "4. Insert one element\n" <<
         "5. Exit\n" <<
         "Select an option:";

    //while loop to continually get user input
    while(true){
        //user inputs an option from menu
        int input;
        cin >> input;
        //switch input to use different functions for each option
        switch (input) {
            //case 1 prints vector
            case 1:
                cout << "You selected 'List vector's contents'\n";
                //call PrintVector() function to print vector
                PrintVector();
                cout << "\nPlease select another option to continue or 5 to exit";
                continue; //continue in switch
            //case 2 appends an element to the end of the vector
            case 2:
                cout << "You selected 'Append element at the end'\n";
                //call AddElement() function to add element
                AddElement();
                cout << "\nPlease select another option to continue or 5 to exit";
                continue; //continue in switch
            //case 3 removes the last element of the vector
            case 3:
                cout << "You selected 'Remove last element'\n";
                //call RemoveElement() function to remove last element
                RemoveElement();
                //if the vector is less than 30% filled with elements, then shrink and cut the capacity in half
                if(vsize < 0.3*capacity)
                    //call the Shrink() function to half the capacity
                    Shrink();
                cout << "\nPlease select another option to continue or 5 to exit";
                continue; //continue in switch
            //case 4 inserts an element at indicated index
            case 4:
                cout << "You selected 'Insert one element'\n";
                //call InsertElement() function
                InsertElement();
                cout << "\nPlease select another option to continue or 5 to exit";
                continue; //continue in switch
            //case 5 exits the program
            case 5:
                cout << "\nYou selected 'Exit'\n";
                break; //break out of switch
            //default if an invalid value is inserted
            default:
                //prints menu again
                cout << "\nPlease enter a valid option\n" <<
                     "Main menu: \n" <<
                     "1. List vector's contents\n" <<
                     "2. Append element at the end\n" <<
                     "3. Remove last element\n" <<
                     "4. Insert one element\n" <<
                     "5. Exit\n" <<
                     "Select an option:";
                continue; //continue in switch
        }
        break; //break out of the while loop
    }
    //call Finalize() to free vector's memory
    Finalize();
    return 0;
}


//initialize the three global variables associated with the vector
void Initialize(){
    vsize = 0; //starts with no elements inserted
    capacity = 2; //starts with a capacity of 2 elements
    v = new double[capacity]; //pointer v points to new array of doubles of size capacity
}

void PrintVector(){
    //loops through elements of the array and prints them
    for (int i = 0; i < vsize; i++)
        cout << *(v+i) << " " ;
}

//function creates a new vector and doubles the capacity
void Grow(){
    double *nv; //create new pointer
    capacity *= 2; //double the capacity
    //pointer nv points to a new array of doubles of size capacity
    nv = new double[capacity];
    //nv copies elements in v
    for(int i = 0; i < vsize ; i++){
        nv[i] = v[i];
    }

    //prints that the vector has grown and the previous and new capacity
    cout << "Vector Grown" << endl;
    cout << "Previous capacity: " <<  capacity/2 << endl;
    cout << "New capacity: " << capacity << endl;

    //delete array v to free memory
    delete[] v;
    //pointer v points to new array of doubles of size capacity
    v = new double[capacity];

    //have pointer v point to elements nv is pointing to
    for(int i = 0; i < vsize ; i++){
        v[i] = nv[i];
    }

    //delete array nv to free memory
    delete[] nv;
}

//function adds element to the end of the vector
void AddElement(){
    //initialize newelement variable
    double newelement;
    cout << "Enter the new element:";
    //cin the user input and assign to newelement variable
    cin >> newelement;
    //increase the size by one
    vsize++;
    //if number of elements inserted exceeds the capacity then call the Grow function to double the capacity
    if (vsize > capacity){
        Grow();
    }
    //assign the new element as the last element of the array
    v[vsize-1] = newelement;

}

//function removes the last element
void RemoveElement(){
    //checks if there are elements in the array
    if (vsize > 0){
        //v[vsize-1] = NULL;
        //decrease the size by one
        --vsize;
    }
    //if there are no elements in the array print this error message
    else
        cout << "No elements in vector to remove\n";
}

//function inserts an element at specified index
void InsertElement(){
    //declaring variables for user inputs
    int index;
    double insertnum;
    //ask user to input the index of the element and the element that they want to insert
    cout << "Enter the index of new element:";
    cin >> index;
    cout << "Enter the new element:";
    cin >> insertnum;

    //check to see if index is in the range 0 - vsize
    if (index >= 0 && index <= vsize) {
        //if the number of elements inserted already equals capacity, then call Grow and double the capacity
        if(vsize == capacity){
            Grow();
        }
        //declare nv pointer that points to new array of size capacity
        double *nv;
        nv = new double[capacity];
        //copy all the elements before the index to nv
        for (int i = 0; i < index; i++)
            nv[i] = v[i];
        //copy all the elements after the index to nv, shift elements one to the right
        for (int j = index; j < vsize; j++)
            nv[j + 1] = v[j];
        //the number entered gets assigned to that index of nv
        nv[index] = insertnum;
        //added an element so increase vsize
        vsize++;

        //v points to elements nv is pointing to
        for(int i = 0; i < vsize ; i++){
            v[i] = nv[i];
        }
        //free memory of nv
        delete[] nv;
    }
    //if the index is invalid prints an error message
    else {
        cout << "Please enter a valid index between 0 and " << vsize;
    }
}

//function cuts the capacity in half
void Shrink(){
    //only shrink if the capacity is greater than 2
    if (capacity > 2) {
        //half the capacity
        capacity = capacity / 2;
        //declare nv pointer that points to new array of halved capacity
        double *nv = new double[capacity];
        //elements in nv copied from elements in v
        for (int i = 0; i < vsize; i++) {
            nv[i] = v[i];
        }

        //if vsize isnt zero, then print message about shrinking
        if (vsize != 0) {
            cout << "Vector Shrank" << endl;
            cout << "Previous capacity: " << capacity * 2 << endl;
            cout << "New capacity: " << capacity << endl;
        }

        //v elements are copied from nv elements
        for (int i = 0; i < vsize; i++) {
            v[i] = nv[i];
        }

        //free memory of nv
        delete[] nv;
    }
}

//free the memory associated with the vector
void Finalize(){
//delete v to free the memory
    delete[] v;
}