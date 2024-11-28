#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#include "C:\DESENVOLVIMENTO\Linguagem C (UFMG)\UFMG\semestre2\PDS2\vpl6\include\aluno.hpp"

int main() {
    std::vector<Student> classList;

    while (true) {
        std::string name;
        std::getline(std::cin, name);
        if (name == "END") break;

        int number;
        std::cin >> number;

        std::vector<int> grades;
        int grade;
        
        while (std::cin >> grade && grade != -1) {
            grades.push_back(grade);
        }
        std::cin.ignore(); 

        classList.emplace_back(name, number, grades);
    }

    std::sort(classList.begin(), classList.end(), [](const Student &a, const Student &b) {
        return a.getName() < b.getName();
    });

    for (const Student& student : classList) {
        std::cout << student.toString() << std::endl;
    }

    return 0;
}