#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

class Student {
private:
    std::string name;
    std::string group;
    int* grades;
    int numGrades;

public:
    Student();
    Student(const std::string& name, const std::string& group, int* grades, int numGrades);
    Student(const Student& other);
    ~Student();

    std::string getName() const;
    std::string getGroup() const;
    int* getGrades() const;
    int getNumGrades() const;
    void setName(const std::string& name);
    void setGroup(const std::string& group);
    void setGrades(int* grades, int numGrades);

    friend std::ostream& operator<<(std::ostream& out, const Student& student);
    friend std::istream& operator>>(std::istream& in, Student& student);

    float calculateAverageGrade() const;
};

#endif
