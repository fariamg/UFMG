#include <string>
#include <vector>

#pragma once

class Student {
    private: 
        std::string name;
        int number;
        std::vector<int> grades;
    public:
        Student(const std::string& nome, int matricula, const std::vector<int>& notas);
        std::string getName() const;
        int getNumber() const;
        void setName(const std::string name);
        void setNumber(int number);
        double gradesAverage() const;
        int maxGrade() const;
        int minGrade() const;
        std::string toString() const;
};