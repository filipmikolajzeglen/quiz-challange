#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <windows.h>

std::string temat, nick;
std::string tresc[5];
std::string odpA[5], odpB[5], odpC[5], odpD[5];
std::string poprawna[5];
std::string odpowiedz;
int punkty = 0;

int main() {
    int nr_pytania = 0;
    int nr_linii = 1;
    std::string linia;

    std::fstream quiz;
    quiz.open("quiz.txt", std::ios::in);

    if (quiz.good() == false) {
        std::cout << " Plik 'quiz.txt' nie istnieje.";
        exit(0);
    }

    while (getline(quiz, linia)) {
        switch (nr_linii) {
            case 1:
                temat = linia;
                break;
            case 2:
                nick = linia;
                break;
            case 3:
                tresc[nr_pytania] = linia;
                break;
            case 4:
                odpA[nr_pytania] = linia;
                break;
            case 5:
                odpB[nr_pytania] = linia;
                break;
            case 6:
                odpC[nr_pytania] = linia;
                break;
            case 7:
                odpD[nr_pytania] = linia;
                break;
            case 8:
                poprawna[nr_pytania] = linia;
                break;
        }

        if (nr_linii == 8) {
            nr_linii = 2;
            nr_pytania++;
        }
        nr_linii++;
    }

    quiz.close();

    for (int i = 0; i <= 4; i++) {
        std::cout << std::endl << " Pytanie nr. " << i + 1 << " " << tresc[i] << std::endl;
        Sleep(2000);
        std::cout << " A. " << odpA[i] << std::endl;
        std::cout << " B. " << odpB[i] << std::endl;
        std::cout << " C. " << odpC[i] << std::endl;
        std::cout << " D. " << odpD[i] << std::endl;

        std::cout << " Twoja odpowiedz to: ";
        std::cin >> odpowiedz;

        transform(odpowiedz.begin(), odpowiedz.end(), odpowiedz.begin(), ::tolower);

        if (odpowiedz == poprawna[i]) {
            std::cout << " Tak! To poprawna odpowiedz!" << std::endl;
            punkty++;
            Sleep(1500);
        } else {
            std::cout << " Zla odpowiedz! Poprawna to: " << poprawna[i] << std::endl;
            Sleep(1500);
        }

    }

    std::cout << std::endl << " Koniec! Udalo ci sie zebrac: " << punkty << " punktow." << std::endl;

    getchar();
    return 0;
}