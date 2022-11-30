//Embedded Design Lab 2 Prelab Linked Lists and gdb Debugger
//This program is debugged using gdb
//Tracy Qiu ID 001313852 9/28/20

#include <iostream>
#include <string>

using namespace std;

//create person struct with name and age attributes
struct Person {
 string name;
 int age;
};

//function that prints the persons name and age
void PrintPerson(Person *person) {
 cout << person->name << " is " << person->age << " years old\n";
}

//initialize a person and print the persons name and age
int main()
{
 Person person;
 person.name = "John";
 person.age = 10;
 PrintPerson(&person);
}
