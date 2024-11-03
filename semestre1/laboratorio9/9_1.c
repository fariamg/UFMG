#include <stdio.h>

typedef enum 
{
    JAN=1,FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV, DEZ
} month;

typedef struct
{
    int day, year;
    month month;
} date;

typedef struct 
{
    char name[100];
    char local[100];
    date date;
} event;

void registerEvents(event schedule[], int n);

void printEvents(event schedule[], date d, int n);

int main() {
    int n;
    scanf("%d", &n);

    event schedule[n];

    registerEvents(schedule, n);

    date date;
    scanf("%d %d %d", &date.day, &date.month, &date.year);

    printEvents(schedule, date, n);
}

void registerEvents(event schedule[], int n) {
    for (int i = 0; i < n; i++) {
        event newEvent;

        scanf("%s %s %d %d %d", newEvent.name, newEvent.local, &newEvent.date.day, &newEvent.date.month, &newEvent.date.year);

        schedule[i] = newEvent;
    }
}

void printEvents(event schedule[], date d, int n) {
    int founded = 0;
    for (int i = 0; i < n; i++) {
        if (schedule[i].date.day == d.day && schedule[i].date.month == d.month && schedule[i].date.year == d.year) {
            printf("%s %s\n", schedule[i].name, schedule[i].local);
            founded++;
        }
    }
    if (!founded) {
        printf("Nenhum evento encontrado!");
    }
}