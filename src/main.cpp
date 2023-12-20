// // main.cpp
// #include "student.h"
// #include <iostream>
// #include <vector>
// #include <algorithm>

// bool compareStudents(const Student& a, const Student& b) {
//     return a.calculateAverageGrade() < b.calculateAverageGrade();
// }

// int main()
// {
//     int numStudents;
//     std::cout << "Enter number of students: ";
//     std::cin >> numStudents;

//     std::vector<Student> students;
//     for (int i = 0; i < numStudents; ++i)
//     {
//         try
//         {
//             Student student;
//             std::cin >> student;
//             students.push_back(student);
//         }
//         catch (const std::invalid_argument &e)
//         {
//             std::cerr << "Error: " << e.what() << std::endl;
//             --i;
//         }
//     }

//     std::sort(students.begin(), students.end(), compareStudents);

//     bool found = false;
//     for (size_t i = 0; i < students.size(); ++i)
//     {
//         const Student &student = students[i];
//         int *grades = student.getGrades();
//         bool hasGrade2 = false;
//         for (int j = 0; j < student.getNumGrades(); ++j)
//         {
//             if (grades[j] == 2)
//             {
//                 hasGrade2 = true;
//                 break;
//             }
//         }
//         if (hasGrade2)
//         {
//             std::cout << student << std::endl;
//             found = true;
//         }
//     }

//     if (!found)
//     {
//         std::cout << "No students with at least one grade of 2." << std::endl;
//     }

//     return 0;
// }


#include <iostream>
#include "fileprocessor.h"

int main() {
    std::string fileName;
    std::cout << "Введите имя файла: ";
    std::cin >> fileName;

    try {
        FileProcessor processor(fileName);
        std::vector<std::string> linesWithTwoDigitNumbers = processor.getLinesWithTwoDigitNumbers();

        std::cout << "Строки с двузначными числами:\n";
        for (const auto& line : linesWithTwoDigitNumbers) {
            std::cout << line << std::endl;
        }
    } catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}

