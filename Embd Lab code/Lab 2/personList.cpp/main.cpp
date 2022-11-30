//Embedded Design Lab 2 Linked Lists and gdb Debugger
//This program makes a linked list of struct People and takes user input for commands add, find, search, and print
//Tracy Qiu ID 001313852 9/28/20

#include <iostream>
#include <string>
using namespace std;

// Linked List Management Code
struct Person
{
    // Unique identifier for the person
    int id;
    // Information about person
    string name;
    int age;
    // Pointer to next person in list
    Person *next;
};

struct List
{
    // First person in the list. A value equal to NULL indicates that the
    // list is empty.
    Person *head;
    // Current person in the list. A value equal to NULL indicates a
    // past-the-end position.
    Person *current;
    // Pointer to the element appearing before 'current'. It can be NULL if
    // 'current' is NULL, or if 'current' is the first element in the list.
    Person *previous;
    // Number of persons in the list
    int count;
};

// Give an initial value to all the fields in the list.
void ListInitialize(List *list)
{
    list->head = NULL;
    list->current = NULL;
    list->previous = NULL;
    list->count = 0;
}

// Move the current position in the list one element forward. If last element
// is exceeded, the current position is set to a special past-the-end value.
void ListNext(List *list)
{
    if (list->current)
    {
        list->previous = list->current;
        list->current = list->current->next;
    }
}

// Move the current position to the first element in the list.
void ListHead(List *list)
{
    list->previous = NULL;
    list->current = list->head;
}

// Get the element at the current position, or NULL if the current position is
// past-the-end.
Person *ListGet(List *list)
{
    return list->current;
}

// Set the current position to the person with the given id. If no person
// exists with that id, the current position is set to past-the-end.
void ListFind(List *list, int id)
{
    ListHead(list);
    while (list->current && list->current->id != id)
        ListNext(list);
}

// Insert a person before the element at the current position in the list. If
// the current position is past-the-end, the person is inserted at the end of
// the list. The new person is made the new current element in the list.
void ListInsert(List *list, Person *person)
{
    // Set 'next' pointer of current element
    person->next = list->current;
    // Set 'next' pointer of previous element. Treat the special case where
    // the current element was the head of the list.
    if (list->current == list->head)
        list->head = person;
    else
        list->previous->next = person;
    // Set the current element to the new person
    list->current = person;
}

// Remove the current element in the list. The new current element will be the
// element that appeared right after the removed element.
void ListRemove(List *list)
{
    // Ignore if current element is past-the-end
    if (!list->current)
        return;
    // Remove element. Consider special case where the current element is
    // in the head of the list.
    if (list->current == list->head)
        list->head = list->current->next;
    else
        list->previous->next = list->current->next;
    // Free element, but save pointer to next element first.
    Person *next = list->current->next;
    delete list->current;
    // Set new current element
    list->current = next;
}
// Print all attributes of the person
void PrintPerson(Person *person)
{
    cout << "Person with ID: " << person->id << endl;
    cout << "\tName: " << person->name << endl;
    cout << "\tAge: " << person->age << endl << endl;;
}

// Takes user input to populate person attributes and calls ListInsert to insert person to list
void AddPerson(List *list){

    //create a new pointer of type person
    Person *newperson;
    newperson = new Person;
    //increase the counter for ID numbers
    list->count++;

    //get user input for newperson's name and age
    cout << "Please enter the name of the new person:";
    cin >> newperson->name;
    cout << "Please enter the age of the new person:";
    cin >> newperson->age;
    //assign the list count as the new person's id becuase the id just increases consecutively
    newperson->id = list->count;

    //insert this newperson into the list and make it this person the current
    ListInsert(list, newperson);
    //PrintPerson(newperson);
    cout << endl;
}

/** main function: Will create and process a linked list
 */

int main() {
    List list;				// Create the main list
    ListInitialize(&list);			// Initialize the list
//*************** PUT THE REST OF YOUR CODE HERE  *****************

    //print the input menu
    cout << "Main menu:" << endl <<
         "1. Add a person" << endl <<
         "2. Find a person" << endl <<
         "3. Remove a person" << endl <<
         "4. Print the list" << endl <<
         "5. Exit" << endl;

    //declare input variable
    int input;

    //continue running through this loop while input does not equal 5
    do {
        //takes in user input from menu
        cout << "Please select an option:";
        cin >> input;

        //switch input to use different functions for each option
        switch (input) {
            //case 1 add a person to the list
            case 1:
                cout << "You selected 'Add a person'" << endl;
                //call AddPerson function to get person attributes and insert in list
                AddPerson(&list);
                break; //break out of switch

                //case 2 find a person with the given ID
            case 2:
                cout << "You selected 'Find a person'" << endl;
                cout << "Please enter the person's ID:";
                //take in user input of id
                int id;
                cin >> id;
                //call ListFind to traverse linked list looking for person of given id
                ListFind(&list, id);
                //if the given id does not exist in the list, print error message
                if (ListGet(&list) == NULL)
                    cout << "Invalid ID, unable to find person" << endl << endl;
                //if found, get and print person
                else
                    PrintPerson(ListGet(&list));
                break; //break out of switch

                //case 3 remove a person with the given ID
            case 3:
                cout << "You selected 'Remove a person'" << endl;
                cout << "Please enter the person's ID:";
                //take in user input of id
                cin >> id;
                //call ListFind to traverse linked list looking for person of given id
                ListFind(&list, id);
                //if the given id does not exist in the list, print error message
                if (ListGet(&list) == NULL)
                    cout << "Invalid ID, unable to remove person" << endl << endl;
                    //if found, remove the person from the list
                else {
                    ListRemove(&list);
                    cout << "Person " << id << " has been removed" << endl << endl;
                }

                break; //break out of switch

                //case 4 print the whole list
            case 4:
                cout << "You selected 'Print the list'" << endl;
                //call ListHead to make the current student the head
                ListHead(&list);
                //while the current is not  null print the current person
                while (ListGet(&list) != NULL){
                    PrintPerson(ListGet(&list));
                    //call ListNext to make the next student the current
                    ListNext(&list);
                }

                break; //break out of switch

                //case 5 exits the program
            case 5:
                cout << "You selected 'Exit'" << endl;
                break; //break out of switch

                //default if an invalid value is inserted
            default:
                //prints menu again
                cout << "Please enter a valid option" << endl <<
                     "Main menu:" << endl <<
                     "1. Add a person" << endl <<
                     "2. Find a person" << endl <<
                     "3. Remove a person" << endl <<
                     "4. Print the list" << endl <<
                     "5. Exit" << endl;
                break; //break out of switch
        }
    }
        //continue in do while loop while input does not equal five
        //if it does, break out of loop and end main
    while (input != 5);
} //end main