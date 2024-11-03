#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char street[50];
    unsigned int number;
    char state[50];
} address;

typedef struct
{
    char name[50];
    unsigned int age;
    float salary;
    address personAddress;
} person;

int main()
{
    person persons[5] = {0};
    for (int i = 0; i <= 100; i++)
    {
        char command[50];
        fgets(command, 50, stdin);
        command[strcspn(command, "\n")] = 0;
        if (strcmp(command, "exit") == 0)
        {
            break;
        }
        if (strcmp(command, "inserir") == 0)
        {
            int inserted = 0;
            for (int i = 0; i < 5; i++)
            {
                if (persons[i].age == 0)
                {
                    scanf("%49s %u %f %49s %u %49s", persons[i].name, &persons[i].age, &persons[i].salary, persons[i].personAddress.street, &persons[i].personAddress.number, persons[i].personAddress.state);
                    while (getchar() != '\n');
                    inserted = 1;
                    printf("Registro %s %d %.2f %s %u %s inserido\n", persons[i].name, persons[i].age, persons[i].salary, persons[i].personAddress.street, persons[i].personAddress.number, persons[i].personAddress.state);
                    break;
                }
            }
            if (!inserted)
            {
                printf("Espaco insuficiente\n");
            }
        }
        if (strcmp(command, "mostrar") == 0)
        {
            char personName[50];
            scanf("%49s", personName);
            while (getchar() != '\n');
            int found = 0;
            for (int i = 0; i < 5; i++)
            {
                if (strcmp(persons[i].name, personName) == 0)
                {
                    printf("Registro %s %u %.2f %s %u %s\n", persons[i].name, persons[i].age, persons[i].salary, persons[i].personAddress.street, persons[i].personAddress.number, persons[i].personAddress.state);
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                printf("Registro ausente\n");
            }
        }
        if (strcmp(command, "alterar") == 0)
        {
            char newName[50];
            unsigned int newAge;
            float newSalary;
            char newStreet[50];
            unsigned int newNumber;
            char mewState[50];

            scanf("%49s %u %f %49s %u %49s", newName, &newAge, &newSalary, newStreet, &newNumber, mewState);
            while (getchar() != '\n');

            int altered = 0;
            for (int i = 0; i < 5; i++)
            {
                if (strcmp(persons[i].name, newName) == 0)
                {
                    strcpy(persons[i].name, newName);
                    persons[i].age = newAge;
                    persons[i].salary = newSalary;
                    strcpy(persons[i].personAddress.street, newStreet);
                    persons[i].personAddress.number = newNumber;
                    strcpy(persons[i].personAddress.state, mewState);
                    printf("Registro %s %u %.2f %s %u %s alterado\n", persons[i].name, persons[i].age, persons[i].salary, persons[i].personAddress.street, persons[i].personAddress.number, persons[i].personAddress.state);
                    altered = 1;
                    break;
                }
            }
            if (!altered)
            {
                printf("Registro ausente para alteracao\n");
            }
        }
    }
    return 0;
}