#include <stdio.h>
#include <stdlib.h>

// Função para verificar se um ano é bissexto
int isLeapYear(int year) {
    if (year % 4 == 0 && year % 100 != 0) {
        return 1;
    } else if (year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Função para calcular o número de dias em um mês específico
int daysInMonth(int month, int year) {
    switch (month) {
        case 1: return 31;
        case 2: return isLeapYear(year) ? 29 : 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: return 0;
    }
}

// Função para calcular o número de dias desde 01/01/0000 até a data fornecida
int daysSinceStart(int day, int month, int year) {
    int days = 0;
    for (int y = 0; y < year; y++) {
        days += isLeapYear(y) ? 366 : 365;
    }
    for (int m = 1; m < month; m++) {
        days += daysInMonth(m, year);
    }
    days += day;
    return days;
}

// Função para calcular o número de dias entre a data fornecida e 17/09/2020
int dateDif(int day, int month, int year) {
    int referenceDay = 17;
    int referenceMonth = 9;
    int referenceYear = 2020;

    int days1 = daysSinceStart(day, month, year);
    int days2 = daysSinceStart(referenceDay, referenceMonth, referenceYear);

    return days2 - days1 + 1;
}

int main() {
    int day, month, year;
    while (scanf("%d %d %d", &day, &month, &year) != EOF) {
        printf("%d\n", dateDif(day, month, year));
    }
    return 0;
}