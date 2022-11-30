/*Embedded Design Homework 1 Problem 4 Structs
 * This program creates a struct for student
 * Tracy Qiu ID 001313852 9/30/20
 * */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//create struct representing a student
struct Student{
    //declare name variable
    string name;
    //declare grade variable
    int grade;
};

//function to add a student to array of students
void AddStudent(Student *student, int index)
{
    //assign input to the name of the student of the current index
    cout << "Please enter the name of the student:";
    cin >> student[index].name;

    //ask user for student's grade
    cout << "Please enter the student's grade:";
    //assign input to the grade of the student of the current index
    cin >> student[index].grade;

    //check if grade is between 0-100 (inclusive)
    if (student[index].grade < 0 || student[index].grade > 100 ){
        //print error message if not in range
        cout << "Please enter a valid grade between 0 and 100:";
        cin >> student[index].grade;
    }
}

//function to sort the students in order of descending grade
void sort(Student *student, int csize){
    //declare variables for tempgrade and tempname
    int tempgrade;
    string tempname;
    //counter for elements of the students array
    for(int i=0;i<csize;i++)
    {
        //counter for elements of the students array starting at
        //second elements used to compare consecutive elements
        for(int j=i+1;j<csize;j++)
        {
            //if previous elements is smaller than latter one
            if(student[i].grade < student[j].grade)
            {
                //set previous element as temp values
                tempgrade = student[i].grade;
                tempname = student[i].name;
                //assign the latter element to the previous element
                student[i].grade = student[j].grade;
                student[i].name = student[j].name;
                //set the latter equal to the temp values
                student[j].grade = tempgrade;
                student[j].name = tempname;
            }
        }
    }
}

//function to print the name and grade of a student
void PrintStudent(Student *student, int index)
{
    cout << student[index].name << " " << student[index].grade << "\n";
}

//function to find the average grade
void average(Student *student, int csize){
    //initialize a sum of zero
    int sum = 0;
    //counter for adding each element of the array to the sum
    for (int i = 0; i < csize; i++)
        sum += student[i].grade;
    //average equals the sum divided by the number of students
    int average = sum/csize;
    cout << "The class average is: " << average << "\n";
}

//function to find the range of the grades
void range(Student *student, int csize){
    //initialise the lowest and greatest as the first elements of the array
    int lowest = student[0].grade;
    int greatest = student[0].grade;
    //loop through all values of the array
    for (int i = 1; i < csize; i++){
        //if the current element is smaller than the lowest, then set this element to lowest
        if(student[i].grade < lowest)
            lowest = student[i].grade;
        //if the current element is smaller than the lowest, then set this element to greatest
        if(student[i].grade > greatest)
            greatest = student[i].grade;
    }
    //range equals the greatest grade subtract the lowest grade
    int range = greatest - lowest;
    cout << "The range of the students' grades is " << range << "\n";
}

//function to find the maximum grade, will be the first element because array is in descending order
void maximum(Student *student) {
    cout << "The class maximum grade: " << student[0].grade << "\n";
}

//function to find the minimum, will be the last element because array is in descending order
void minimum(Student *student, int csize) {
    cout << "The class minimum grade: " << student[csize-1].grade << "\n";
}

//start of main
int main() {
    //get user input for the size of the array of students
    int csize;
    cout << "Please enter the number of students in the class:";
    cin >> csize;
    //create a new array of students
    Student *students = new Student[csize];

    //counter for each element of the array
    for (int i = 0; i < csize; i++) {
        //call AddStudent function to add values to array
        AddStudent(students, i);
        cout << "\n";
    }
    //call sort function to order elements in descending order
    sort(students, csize);

    //loop through entire array and print each student
    for(int i = 0; i < csize; i++)
        PrintStudent(students, i);

    //call average, range, maximum, and minimum functions to solve these values
    average(students, csize);
    range(students, csize);
    maximum(students);
    minimum(students, csize);

    return 0;
}
