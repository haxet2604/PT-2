#include "student.h"
#include <stdexcept>

Student::Student() : name(""), group(""), grades(nullptr), numGrades(0) {
    std::cout << "Default constructor called" << std::endl;
}

Student::Student(const std::string& name, const std::string& group, int* grades, int numGrades)
    : name(name), group(group), numGrades(numGrades) {
    std::cout << "Parametrized constructor called" << std::endl;
    this->grades = new int[numGrades];
    for (int i = 0; i < numGrades; ++i) {
        if (grades[i] < 2 || grades[i] > 5) {
            delete[] this->grades;
            throw std::invalid_argument("Invalid grade detected");
        }
        this->grades[i] = grades[i];
    }
}

Student::Student(const Student& other)
    : name(other.name), group(other.group), numGrades(other.numGrades) {
    std::cout << "Copy constructor called" << std::endl;
    this->grades = new int[numGrades];
    for (int i = 0; i < numGrades; ++i) {
        this->grades[i] = other.grades[i];
    }
}

Student::~Student() {
    std::cout << "Destructor called" << std::endl;
    delete[] grades;
}

std::string Student::getName() const {
    return name;
}

std::string Student::getGroup() const {
    return group;
}

int* Student::getGrades() const {
    return grades;
}

int Student::getNumGrades() const {
    return numGrades;
}

void Student::setName(const std::string& name) {
    this->name = name;
}

void Student::setGroup(const std::string& group) {
    this->group = group;
}

void Student::setGrades(int* grades, int numGrades) {
    delete[] this->grades;
    this->grades = new int[numGrades];
    for (int i = 0; i < numGrades; ++i) {
        if (grades[i] < 2 || grades[i] > 5) {
            delete[] this->grades;
            throw std::invalid_argument("Invalid grade detected");
        }
        this->grades[i] = grades[i];
    }
    this->numGrades = numGrades;
}

std::ostream& operator<<(std::ostream& out, const Student& student) {
    out << "Name: " << student.name << ", Group: " << student.group << ", Grades: ";
    for (int i = 0; i < student.numGrades; ++i) {
        out << student.grades[i] << " ";
    }
    return out;
}

std::istream& operator>>(std::istream& in, Student& student) {
    std::cout << "Enter name: ";
    in >> student.name;
    std::cout << "Enter group: ";
    in >> student.group;
    std::cout << "Enter number of grades: ";
    in >> student.numGrades;
    student.grades = new int[student.numGrades];
    for (int i = 0; i < student.numGrades; ++i) {
        std::cout << "Enter grade " << i + 1 << ": ";
        in >> student.grades[i];
        if (student.grades[i] < 2 || student.grades[i] > 5) {
            delete[] student.grades;
            throw std::invalid_argument("Invalid grade detected");
        }
    }
    return in;
}

float Student::calculateAverageGrade() const {
    float sum = 0.0f;
    for (int i = 0; i < numGrades; ++i) {
        sum += grades[i];
    }
    return sum / numGrades;
}
