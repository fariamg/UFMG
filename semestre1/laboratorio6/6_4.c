#include <stdio.h>
#include <stdlib.h>

int leapYear(int year);

int main() {
    int year;
    while (scanf("%d", &year) != EOF) {
        printf("%d\n", leapYear(year));
    }
    return 0;

}

int leapYear(int year) {
    if (year % 4 == 0 && year % 100 != 0) {
        return 1;
    } else if (year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}