#include <string>
#include <iostream>
using namespace std;
class NEPerson {
private:
    int id;
    string pname;
    string address;
public:
    NEPerson();
    virtual void GetPersonInfo() {
        cout << "Please enter the person's ID, name, and address";
        cin >> id >> pname >> address;
    }

    NEPerson(int d, string n, string a) {
        id = d;
        pname = n;
        address = a;
    }

    virtual void printInfo() {
        cout << "Name: " << pname;
        cout << "\t ID: " << id;
        cout << "\t Address: " << address << endl;
    }

    bool NEPerson::operator<(NEPerson &p2){
        return (pname < p2.pname);
    }
};

class NEStudent : public NEPerson {
private:
    string major;
    float gpa;
    int CurCoursesNum;
    string* CurEnrolledCourses;
public:
    /*
    NEStudent();
    NEStudent.GetPersonInfo();
    virtual void GetStudentInfo() {
        cout << "Please enter the person's ID, name, and address";
        cin >> major >> gpa >> CurCoursesNum;
    }
     */
    NEStudent(int d, string n, string a, string m, float g, int cnum):NEPerson(d, n, a)
    { major = m; gpa = g; CurCoursesNum = cnum; }
    void addEnrolledCourses() {
        CurEnrolledCourses = new string[CurCoursesNum];
        cout << "Enter the code of " << CurCoursesNum;
        cout << " course(s) for the student:\n";
        for (int i = 0; i < CurCoursesNum; i++) cin >> CurEnrolledCourses[i];
    }
    virtual void printInfo() {
        NEPerson::printInfo();
        cout << "\t Student Major: " << major;
        cout << "\t GPA = " << gpa;
        cout << "\n\t Taking Courses:\n";
        for (int i = 0; i < CurCoursesNum; i++)
            cout << "\t   " << CurEnrolledCourses[i] << endl;
    }
    bool NEStudent::operator<(NEStudent &p2){
        return (gpa < p2.gpa);
    }
    ~NEStudent()
    { if (!CurEnrolledCourses) delete[] CurEnrolledCourses; }
};

class NETeacher : public NEPerson {
private:
    string rank;
    string department;
    int CurCoursesLoad;
    string* CurCoursesTeaching;
public:
    NETeacher(int d, string n, string a, string r, string p, int cnum) :NEPerson(d, n, a)
    { rank = r; department = p; CurCoursesLoad = cnum;}
    virtual void printInfo() {
        NEPerson::printInfo();
        cout << "\t Teacher Rank: " << rank;
        cout << "\t Department = " << department;
        cout << "\n\t Teaching Courses:\n";
        for (int i = 0; i < CurCoursesLoad; i++)
            cout << "\t   " << CurCoursesTeaching[i] << endl;
    }
    void addCoursesTeaching() {
        CurCoursesTeaching = new string[CurCoursesLoad];
        cout << "Enter the code of " << CurCoursesLoad;
        cout << " course(s) for the teacher:\n";
        for (int i = 0; i < CurCoursesLoad; i++)
            cin >> CurCoursesTeaching[i]; }
    ~NETeacher()
    { if (!CurCoursesTeaching) delete[] CurCoursesTeaching; }
};

class NEGradStudent : public NEStudent , public NETeacher{
private:
    string gradLevel;
public:
    //NEGradStudent(int d, string n, string a, string m, float g, int clnum,
    //             string r, string p, int ctnum, string gL) : NEStudent(d, n, a, m, g, clnum) , NETeacher(d, n, a, r, p, ctnum)

    NEGradStudent(string gL);
    {gradLevel = gL;}
    virtual void printInfo() {
        NEStudent::printInfo();
        NETeacher::printInfo();
        cout << "\t Graduating Level: " << gradLevel;
    }

};


//A template function that prints the info of two objects based on their < relation.
template <class T>
void PrintOrdered(T &v1, T &v2) {
    if (v1 < v2) { v1.printInfo(); v2.printInfo(); }
    else { v2.printInfo(); v1.printInfo(); }
}

template <class T>
void PrintReverseOrdered(T &v1, T &v2) {
    if (v1 < v2) { v2.printInfo(); v1.printInfo(); }
    else { v1.printInfo(); v2.printInfo(); }
}


int main() {


    NEGradStudent g1(888, "Adam", "Dedham", "Assistant Professor", "EECE", 3);
/*
    NEPerson s3();
    s3.GetPersonInfo();


    NEStudent s1(111, "John", "Boston", "CE", 3.2, 2);
    NEStudent s2(222, "Emily", "Cambridge", "CS", 3.6, 3);
    NETeacher t1(888, "Adam", "Dedham", "Assistant Professor", "EECE", 3);
    NETeacher t2(999, "Mary", "Foxboro", "Associate Professor", "CS", 2);

    s1.addEnrolledCourses();
    s2.addEnrolledCourses();
    t1.addCoursesTeaching();
    t2.addCoursesTeaching();

    NEPerson* ps1 = &s1;
    NEPerson* ps2 = &s2;
    NEPerson* pt1 = &t1;
    NEPerson* pt2 = &t2;


    ps1->printInfo();
    ps2->printInfo();

    pt1->printInfo();
    pt2->printInfo();


    cout << "\n Students ordered by GPA (Ascending):\n";
    PrintOrdered(s1, s2);
    cout << "\n Teachers ordered alphabetically (Ascending):\n";
    PrintOrdered(t1, t2);


    //cout << "\n Students ordered alphabetically:\n";
    //PrintOrdered(*&s1, *&s2);
    //probably have to use this and pointer

    cout << "\n Students ordered by GPA (Descending):\n";
    PrintReverseOrdered(s1, s2);
    cout << "\n Teachers ordered alphabetically (Descending):\n";
    PrintReverseOrdered(t1, t2);




    //testing Q1 < operation overloading alphabetically ordering names
    NEPerson p1(111, "Annie", "Boston");
    NEPerson p2(222, "Jack", "Newton");
    if (p1 < p2) cout << "true";


    //testing Q2 < operation overloading comparing gpas
    NEStudent s1(111, "Annie", "Boston", "CE", 3.2, 2);
    NEStudent s2(222, "Jack", "Newton","CS", 3.6, 3);
    if (s1 < s2) cout << "true";
*/

    return 0;
}
