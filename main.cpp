#include <stdlib.h>
#include "Student.h"
#include "Course.h"
#include <fstream>
#include <curses.h>

int main()
{
  // Create a StudentList object
  StudentList list;

  // Creating object to list of courses
  CourseList courses;

  // to access to vector first we create an empty pointer
  Student *student = nullptr;

  std::string nameComplete, course, idClass; //
  int ID;
  char decision = 'y';
  char program_decision = 'y';
  int option;

  bool input_complete = false;
  bool while_state = false;

  do
  {
    std::cout << "selecione a sua opcao: \n\t[0-Adicionar Aluno\n\t1-Ver Alunos por cursos\n\t2-Ver Alunos por cursos e turma\n\t3-Adicionar Cursos\n\t4-Ver Cursos\n\t5-Limpar Lista(ficheiro .txt)\n\t10-sair]\t\nOpcao:";
    std::cin >> option;
    std::cin.ignore();
    std::cout << std::endl;

    switch (option)
    {
    case 0: // Adicionar Aluno.
    {       // while (!input_complete) // Not false
      do
      {
        std::cout << "name complete: ";
        // std::cin >> nameComplete;
        std::getline(std::cin, nameComplete);
        std::cout << std::endl;

        std::cout << "ID: ";
        std::cin >> ID;
        std::cin.ignore(); // ignora la qlqr problema q resolve a situacao 0_o
        std::cout << std::endl;

        std::cout << "course : ";
        // std::cin >> course;//Prints Computer??
        std::getline(std::cin, course);
        std::cout << std::endl;

        std::cout << "idClass : ";
        std::getline(std::cin, idClass);
        std::cout << std::endl;

        // student = new Student(nameComplete, ID, course);
        student = new Student(nameComplete, ID, course, idClass, &courses); // Adding to pointer of object new student name, ID and course
                                                                            // Also such fenonema can be labeled as heap memory or dinamic memory

        list.addStudent(student); // object list, submits all values from student value to while loop for it to then return
                                  // sends out name, ID, course, idClass
        std::cout << "Gostaria de escrever novo aluno? : ";
        std::cin >> decision;
        std::cin.ignore();

        if (decision == 'n' && decision != 'y') // using 'n' to exit, and y other flag(works too) to keep on menu
        {
          input_complete = true;
        }
    
      } while (!input_complete); // end of while state

      // Open the file for writing, by appending(extra configuration)
      std::ofstream file("students.txt", std::ios::app); // ios::app means we want to open new file in append mode

      std::list<Student *> students1 = list.getStudentsClass("CS", "CS101");

      // Print the names and IDs of the students
      for (auto it = students1.begin(); it != students1.end(); it++)
      { // Looping on to the list
        std::cout << "Name: " << (*it)->getName() << std::endl;
        std::cout << "ID: " << (*it)->getId() << std::endl;
        std::cout << "Course: " << (*it)->getCourse() << std::endl;
        std::cout << "idClass: " << (*it)->getIdClass() << std::endl;

        // Now writing to file
        file << "Name: " << (*it)->getName() << std::endl;
        file << "ID: " << (*it)->getId() << std::endl;
        file << "Course: " << (*it)->getCourse() << std::endl;
        file << "IdClass: " << (*it)->getIdClass() << std::endl;
        file << std::endl;
      }
      // Now we close our file
      file.close();

      cout << "Para voltar prima 'Enter' key" << endl;
      getchar();
      break; // Breaks after if clause

    } // end of Case 0

    case 1: // Ver por Curso:
    {
      // clear console
      system("clear");

      // Get a list of students taking the "Computer Science" course
      std::list<Student *> students = list.getStudents("CS");
      // Print the names and IDs of the students
      for (auto it = students.begin(); it != students.end(); it++)
      { // Looping on to the list
        std::cout << "Name: " << (*it)->getName() << std::endl;
        std::cout << "ID: " << (*it)->getId() << std::endl;
        std::cout << "Course: " << (*it)->getCourse() << std::endl;
      }
      getchar();
      break;
    }

    case 2:
    {
      // clear console
      system("clear");

      // Get a list of students taking the "Computer Science" course and idCourse
      std::list<Student *> students1 = list.getStudentsClass("CS", "CS101");

      // Print the names and IDs of the students
      for (auto it = students1.begin(); it != students1.end(); it++)
      { // Looping on to the list
        std::cout << "Name: " << (*it)->getName() << std::endl;
        std::cout << "ID: " << (*it)->getId() << std::endl;
        std::cout << "Course: " << (*it)->getCourse() << std::endl;
        std::cout << "idClass: " << (*it)->getIdClass() << std::endl;
      }
      cout << "Para voltar prima 'Enter' key" << endl;
      getchar();
      break;
    }

    case 3: // Adding courses to the list
    {
      // Add some courses to the list

      courses.addCourse("CS");
      courses.addCourse("Ps");
      
      cout << "Para voltar prima 'Enter' key" << endl;
      getchar();
      break;
    }
    case 4: // View set list of inside the program.
    {
      CourseList *studentCourses = student->getCourses(); // assing to object inside of switch target option(case 4:), by derenfereencing from pointer

      std::list<std::string> courses = studentCourses->getCourses(); // now assigning previous assigned object to constructor courses.

      for (const auto &course : courses)
      {
        cout << "List de Cursos : " << course << endl;
      }

      delete studentCourses; // Deleting the pointer to prevent leaks, and for the sake of safety measearing
      cout << "Para voltar prima 'Enter' key" << endl;
      getchar();
      break;
    }

    case 5:
    {
      // Wipe all data
      std::ofstream file("students.txt");
      file.close();
      cout << "Para voltar prima 'Enter' key" << endl;
      getchar();
      break;
    }

    case 10:
    {
      std::cout << "Gostaria continuar?";
      std::cin >> program_decision;
      if (program_decision == 'n')
      {
        while_state = true;
        delete student; // freeing pointer from the memmory to avoid any leaks
      }
      break;
    }
    }
  } while (!while_state);

  return 0;
}
