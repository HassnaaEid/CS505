#include <iostream>
using namespace std;
class student {

private: //data members
    int id;
    string name;
    float grade;

public: 
    //constructor
    student() {
        grade = 10;
    }
    student(float g)
    {
        grade = g;
    }
    student(float g, int i)
    {
        grade = g;
        id = i;
    }




    //methods
    void set_id(int i) {
        id = i;
    }
    void set_name(string s) {
        name = s;
    }
    void set_grade(float g) {
        grade = g;
    }
    int get_id() {
        return id;
    }
    float get_grade() {
        return grade;
    }
    string get_name() {
        return name;
    }
   
};

float getAverage(student arr[], int size) {
    float sum = 0;
    float avg;

    for (int i = 0; i < size; i++) {
        sum += arr[i].get_grade();
    }
    avg = sum / size;

    return avg;
}

 int main()
{
   
    int size=0, id;
    float grade, average = 0.0;
    string name;
    cout << "enter size: ";
    cin >> size;
    

    student* s = new student[size];
    for (int i = 0; i < size; i++)
    {
        cout << "name: ";
        cin >> name;
        s[i].set_name(name);
        cout << "id: ";
        cin >> id;
        s[i].set_id(id);
        cout << "grade: ";
        cin >> grade;
        s[i].set_grade(grade);
    }
    cout << "the average= " << getAverage(s, size);
    return 0;
}

