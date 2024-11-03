#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main () {

    ifstream file("palavras.txt", fstream::in); // C:/DESENVOLVIMENTO/Linguagem C (UFMG)/semestre2/palavras.txt mudar para palavras.txt
    if (!file.is_open()) 
        return 1;

    int keyNumber;
    cin >> keyNumber;

    string key;
    for (int i = 0; i <= keyNumber; i++) 
        getline(file, key);

    string missedLetters;
    string answer = "*****";
    
    for (int i = 1; i <= 5; i++) {
        string attempt;
        cin >> attempt;

        if (attempt == key) {
                cout << key << " (" << missedLetters << ")" << endl;
                cout << "GANHOU!";
                return 0;
        }

        for (int j = 0; j < 5; j++) {
            if (attempt[j] == key[j]) 
                answer[j] = attempt[j];
            else {
                bool found = false;
                for (int k = 0; k < 5; k++) {
                    if (attempt[j] == key[k]) {
                        answer[j] = tolower(attempt[j]);
                        found = true;
                        break;
                    }
                }
                if (!found && missedLetters.find(attempt[j]) == string::npos) // retorno quando não acha o char
                    missedLetters += attempt[j];
            } 
        }

        cout << answer << " (" << missedLetters << ")" << endl;

        for (int j = 0; j < 5; j++) { //  reset de lower case
            if (islower(answer[j])) 
                answer[j] = '*';
        }
    }

    cout << "PERDEU! " << key;

    file.close();
    return 0;
}
