#include <numeric>
#include <algorithm>
#include <iostream>
#include <sstream>

#include "aluno.hpp"

Student::Student(const std::string& name, int number, const std::vector<int>& grades)
    : name(name), number(number), grades(grades) {}

std::string Student::getName() const {
    return name;
}

int Student::getNumber() const {
    return number;
}

void Student::setName(const std::string name_) {
    name = name_;
}

void Student::setNumber(int number_) {
    number = number_;
}

double Student::gradesAverage() const {
    if (grades.empty()) return 0;
    int sum = std::accumulate(grades.begin(), grades.end(), 0.0);
    return sum / static_cast<double>(grades.size());
}

int Student::maxGrade() const {
    if (grades.empty()) return 0;
    return *std::max_element(grades.begin(), grades.end());
}

int Student::minGrade() const {
    if (grades.empty()) return 0;
    return *std::min_element(grades.begin(), grades.end());
}

std::string Student::toString() const {
    std::ostringstream oss;
    oss << number << " " << name << " ";
    for (int grade : grades) {
        oss << grade << " ";
    }
    return oss.str();
}