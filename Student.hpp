#if !defined(STUDENT_H)
#define STUDENT_H

#include <string>
#include "Database.hpp"

class Student
{
private:
    std::string name, surname;
    int grade;

    std::string subjects_names[17];
    int subject_marks[17];
    std::string taken_subjects[17];
public:
    Student();

    void createImage(int id, Database user, char *argv[]);
    std::string subjectsTaking(int id, Database user);

    ~Student();
};

#endif // STUDENT_H