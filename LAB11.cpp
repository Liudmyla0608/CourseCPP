#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <numeric>

struct Student {
    std::string lastName;
    double averageGrade;

    // Конструктор
    Student(const std::string& ln, double ag) : lastName(ln), averageGrade(ag) {}

    // Оператор сортування за замовчуванням (за прізвищем)
    bool operator<(const Student& other) const {
        return lastName < other.lastName;
    }
};

int main() {
    // Вихідний вектор студентів
    std::vector<Student> students = {
        {"Ivanov", 4.2},
        {"Petrov", 3.9},
        {"Sidorov", 4.8},
        {"Kuznetsov", 3.5},
        {"Smirnov", 4.5}
    };

    //Зчитування і запис у файл
    {
        std::ofstream outFile("students.txt");
        for (const auto& s : students) {
            outFile << s.lastName << " " << s.averageGrade << "\n";
        }
        outFile.close();
    }

    //Сортування за прізвищем і середнім балом
    std::sort(students.begin(), students.end());
    std::cout << "Сортування за прізвищем:\n";
    for (const auto& s : students) {
        std::cout << s.lastName << " " << s.averageGrade << "\n";
    }

    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.averageGrade > b.averageGrade;
    });
    std::cout << "\nСортування за середнім балом:\n";
    for (const auto& s : students) {
        std::cout << s.lastName << " " << s.averageGrade << "\n";
    }

    //Винести студентів із середнім балом > 4
    std::vector<Student> highAchievers;
    std::copy_if(students.begin(), students.end(), std::back_inserter(highAchievers), [](const Student& s) {
        return s.averageGrade > 4.0;
    });

    //Зберегти всі середні бали з кроку 3
    std::vector<double> highGrades;
    std::transform(highAchievers.begin(), highAchievers.end(), std::back_inserter(highGrades), [](const Student& s) {
        return s.averageGrade;
    });

    //Дізнатися, скільки значень середнього бала > 4.5
    int countAbove = std::count_if(highGrades.begin(), highGrades.end(), [](double grade) {
        return grade > 4.5;
    });
    std::cout << "\nКількість балів вище 4.5: " << countAbove << "\n";

    //Знайти середній бал всіх студентів
    double totalAverage = std::accumulate(students.begin(), students.end(), 0.0, [](double sum, const Student& s) {
        return sum + s.averageGrade;
    }) / students.size();
    std::cout << "\nСередній бал всіх студентів: " << totalAverage << "\n";

    //Перевірити, чи входить вектор з кроку 3 у вихідний вектор
    bool isSubsequence = std::search(
        students.begin(), students.end(),
        highAchievers.begin(), highAchievers.end(),
        [](const Student& a, const Student& b) {
            return a.lastName == b.lastName && a.averageGrade == b.averageGrade;
        }
    ) != students.end();
    std::cout << "\nЧи є вектор студентів із кроку 3 підпослідовністю вихідного вектора: " 
              << (isSubsequence ? "Так" : "Ні") << "\n";

    return 0;
}
