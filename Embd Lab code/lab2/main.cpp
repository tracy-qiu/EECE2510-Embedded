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
void PrintPerson(Person *person)
{
    cout << "Person with ID: " << person->id << endl;
    cout << "\tName: " << person->name << endl;
    cout << "\tAge: " << person->age << endl << endl;;
}


void AddPerson(List *list){

    Person *newperson;
    newperson = new Person;

    list->count++;

    cout << "\nYou selected 'Add a person'";
    cout << "\nPlease enter the name of the new person: ";
    cin >> newperson->name;
    cout << "\nPlease enter the age of the new person:";
    cin >> newperson->age;
    newperson->id = list->count;

    ListInsert(list, newperson);
    PrintPerson(newperson);


}

/** main function: Will create and process a linked list
 */
int main() {
    List list;				// Create the main list
    ListInitialize(&list);			// Initialize the list
//*************** PUT THE REST OF YOUR CODE HERE  *****************

    cout << "\nMain menu: \n" <<
         "1. Add a person\n" <<
         "2. Find a person\n" <<
         "3. Remove a person\n" <<
         "4. Print the list\n" <<
         "5. Exit\n" <<
         "Select an option:";


    //while loop to continually get user input
    while(true){
        //user inputs an option from menu
        int input;
        cin >> input;

        //switch input to use different functions for each option
        switch (input) {

            //case 1 add a person to the list
            case 1:
                AddPerson(&list);
                cout << "\nPlease select another option to continue or 5 to exit";
                continue; //continue in switch

            // case 2 find a person
            case 2:
                cout << "You selected 'Find a person'\n";
                cout << "Please enter the person's ID: ";
                int id;
                cin >> id;
                ListFind(&list, id);
                if (ListGet(&list) == NULL)
                    cout << "Invalid ID, unable to find\n";
                else
                    PrintPerson(ListGet(&list));

            cout << "\nPlease select another option to continue or 5 to exit";
            continue; //continue in switch

        //case 3
        case 3:
            cout << "You selected 'Remove a person'\n";
            cout << "You selected 'Find a person'\n";
            cout << "Please enter the person's ID: ";
            cin >> id;
            ListFind(&list, id);
            if (ListGet(&list) == NULL)
                cout << "Invalid ID, unable to remove\n";
            else {
                ListRemove(&list);
                cout << "Person ID: " << id << "has been removed\n";
            }

            cout << "\nPlease select another option to continue or 5 to exit";
            continue; //continue in switch

        //case 4
        case 4:
            cout << "You selected 'Print the list'\n";
            ListHead(&list);
            while(ListGet(&list) != NULL){
                PrintPerson(ListGet(&list));
                ListNext(&list);
            }

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


} //end main