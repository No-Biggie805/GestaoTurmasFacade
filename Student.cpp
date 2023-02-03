#include "Student.h"

/*CourseList class*/
// Chamar default constructor
CourseList::CourseList() {}

// Chamar Destructor
CourseList::~CourseList() {}

// Adding to specific course list
void CourseList::addCourse(string course) { courses_.push_back(course); }

// Mutator, or Getter
list<string> CourseList::getCourses() const { return courses_; }

// --------------------------------------XXX-----------------------------------------

/*Student Base Class*/

// Default constructor
Student::Student() {}

// Constructor Parametrizado
Student::Student(std::string name, int id, std::string course, std::string idClass, CourseList *courses) // Initializer list constructor
    : name_(name), id_(id), course_(course), idClass_(idClass), courses_(courses)
{
}

// Accessors or Getters
std::string Student::getName() const { return name_; }
int Student::getId() const { return id_; }
std::string Student::getCourse() const { return course_; }
std::string Student::getIdClass() const { return idClass_; }
CourseList *Student::getCourses() const { return new CourseList(*courses_); } // Return by value of pointer..

// Mutators or Setters
void Student::setName(std::string name) { name_ = name; }
void Student::setId(int id) { id_ = id; }
void Student::setCourse(std::string course) { course_ = course; }
void Student::setIdClass(std::string idClass) { idClass_ = idClass; }
void Student::setCourses(CourseList *courses) { courses_ = courses; }
// Setter could be missing for adding courses?

// ---------------------------------------------XXX-------------------------------------------------

/*StudentList class*/
//  default Constructor
StudentList::StudentList() {}

//   //Destructor
//   ~StudentList(){delete }

// Add a student to the list
void StudentList::addStudent(Student *student) { students_.push_back(student); } // Adding new student to list

// Get a list of students taking a given course
std::list<Student *> StudentList::getStudents(std::string course) // Isto é o que o professor deve querer, falta implementar por IDturma, implementação similar mas por turma
{                                                                 // edit: deleted std:string course
    std::list<Student *> students;

    for (auto it = students_.begin(); it != students_.end(); it++)
    {
        if ((*it)->getCourse() == course)
        { // Removing this if statement will unfilter the course returns, also putting user input can disrupt with this
            students.push_back(*it);
        }
    }

    return students;
}

std::list<Student *> StudentList::getStudentsClass(std::string course, std::string idClass) // Isto é o que o professor deve querer, falta implementar por IDturma, implementação similar mas por turma
{                                                                                           // edit: deleted std:string course
    std::list<Student *> students;

    for (auto it = students_.begin(); it != students_.end(); it++)
    {
        if ((*it)->getCourse() == course && (*it)->getIdClass() == idClass) // get functions from above..
        {                                                                   // Removing this if statement will unfilter the course returns, also putting user input can disrupt with this
            students.push_back(*it);                                        // increments to list according to loop
        }
    }
    return students;
}
// -----------------------------------------------XXX-------------------------------------------------------