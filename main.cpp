//Nihal Parthasarathy
//11/6/2021
//This program takes in students with their info and puts them into a list where the program can print it out and can delete a specif student based of their id number
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

//Initilizes Struct
struct student {
  char first[20];
  char last[20];
  int id;
  float gpa;

};

//Function Prototypes
void addStudent(vector<student*> &vec1);
void printStudent(vector<student*> &vec1);
void deleteStudent(vector<student*> &vec1);

int main() {

  //Initilizes Varubles
  bool stillGoing = true;
  vector <student*> vec;
  char input[10];

  //While loop to keep the coude running
  while (stillGoing == true) {
    cout << "Enter ADD to add a student, PRINT to print them out, and Delete to delete a Student" << endl;
    cin >> input;
    
    if (strcmp(input, "ADD") == 0) {//Calls the add function
      addStudent(vec);
    }
    else if (strcmp(input, "PRINT") == 0) {//Calls the print function
      printStudent(vec);
    }
    else if (strcmp(input, "DELETE") == 0) {//Calls the delete function
      deleteStudent(vec);
    }
    else if (strcmp(input, "QUIT") == 0) {//Returns false
      stillGoing = false;
    }
    else {
      cout << "Please try again" << endl;
    }
  }
  return 0;
}


void addStudent(vector<student*> &vec1) {
  //Adds a new student
  student* newStudent = new student();
  cout << "Enter first name" << endl;
  cin >> newStudent->first;
  cout << "Enter last name" << endl;
  cin >> newStudent->last;
  cout << "Enter id number" << endl;
  cin >> newStudent->id;
  cout << "Enter GPA" << endl;
  cin >> newStudent->gpa;
  vec1.push_back(newStudent); //Puts the new student into the back of the vector
}

void printStudent(vector<student*> &vec1) {
  //Prints all the students out
  for (int i =0; i < vec1.size(); ++i) {
    cout << vec1[i]->first << ", ";
    cout << vec1[i]->last << ", ";
    cout << vec1[i]->id << ", ";
    cout << vec1[i]->gpa << endl;
  }

}

void deleteStudent(vector<student*> &vec1) {
  //Deletes A specific Student
  student* newStudent = new student();
  //Initlizes Iterator
  vector<student*>::iterator it;
  int in;
  cout << "enter in student id" << endl;
  cin >> in;
  cout << in << endl;
  for (it = vec1.begin(); it < vec1.end(); ++it) {
    if ((*it)->id == in) {
      vec1.erase(it); //Deletes the student
      cout << "student deleted" << endl;
    }
  }
}
