#ifndef STUDENT_H
#define STUDENT_H

// #include "Course.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;

class CourseList
{
private:
  list<string> courses_;

public:
  // default constructor
  CourseList();
  // Destructor
  ~CourseList();

  void addCourse(string course);
  // Adding to specific course list

  // Mutator, or Getter
  list<string> getCourses() const;
};

class Student : public CourseList // Tera de ficar tudo no GestaoTurmasFacade??
{
public:
  // Default constructor
  Student();
  // Constructor
  Student(std::string name, int id, std::string course, std::string idClass, CourseList *courses); // Initializer list constructor

  // Accessors or Getters
  std::string getName() const;   
  int getId() const;              
  std::string getCourse() const;  
  std::string getIdClass() const; 
  CourseList *getCourses() const; //Return by value of pointer..

  // Mutators or Setters
  void setName(std::string name);       
  void setId(int id);                  
  void setCourse(std::string course);   
  void setIdClass(std::string idClass); 
  void setCourses(CourseList *courses); 
                    

private:
  std::string name_;
  int id_;
  std::string course_;
  std::string idClass_;
  CourseList *courses_; // Member object
};
class StudentList
{
public:
  // Constructor
  StudentList(); // {}

  //   //Destructor
  //   ~StudentList(){delete ;}

  // Add a student to the list
  void addStudent(Student *student); // Adding new student to list

  // Get a list of students taking a given course
  std::list<Student *> getStudents(std::string course); // Isto é o que o professor deve querer, falta implementar por IDturma, implementação similar mas por turma
  std::list<Student *> getStudentsClass(std::string course, std::string idClass); // Isto é o que o professor deve querer, falta implementar por IDturma, implementação similar mas por turma

private:
  std::list<Student *> students_;
};
#endif