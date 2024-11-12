#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>
#include <sstream>

void processAndCountWords(const std::string &line, std::map<std::string, int> &wordCount) {
    std::stringstream ss(line);
    std::string word;
    
    while (ss >> word) {
        std::string processedWord;
        for (size_t i = 0; i < word.size(); ++i) {
            if (std::isalnum(word[i])) {
                processedWord += std::tolower(word[i]);
            } else if (word[i] == '-' && i > 0 && i < word.size() - 1) {
                if (!processedWord.empty()) {
                    wordCount[processedWord]++;
                    processedWord.clear();
                }
            }
        }
        if (!processedWord.empty()) {
            wordCount[processedWord]++;
        }
    }
}

int main() {
    std::string filename;
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        return 1;
    }

    std::map<std::string, int> wordCount;
    std::string line;

    while (std::getline(file, line)) {
        processAndCountWords(line, wordCount);
    }

    file.close();

    for (const auto &entry : wordCount) {
        std::cout << entry.first << " " << entry.second << std::endl;
    }

    return 0;
}
