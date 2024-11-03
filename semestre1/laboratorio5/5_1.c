#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char name[50];
    unsigned int age;
    float salary;
} person;

int main()
{
    person persons[4] = {0};
    for (int i = 0; i <= 100; i++)
    {
        char command[50];
        fgets(command, 50, stdin);
        command[strcspn(command, "\n")] = 0; 
        if (strcmp(command, "exit") == 0)
        {
            break;
        }
        if (strcmp(command, "inserir") == 0) {
            int inserted = 0;
            for (int i = 0; i < 4; i++)
            {
                if (persons[i].age == 0) 
                {
                    scanf("%49s %u %f", persons[i].name, &persons[i].age, &persons[i].salary);
                    while (getchar() != '\n'); 
                    inserted = 1;
                    printf("Registro %s %d %.2f inserido\n", persons[i].name, persons[i].age, persons[i].salary);
                    break;
                }
            }
            if (!inserted) {
                printf("Espaco insuficiente\n");
            }
        }
        if (strcmp(command, "mostrar") == 0) {
            char personName[50];
            scanf("%49s", personName);
            while (getchar() != '\n'); 
            int found = 0;
            for (int i = 0; i < 4; i++)
            {
                if (strcmp(persons[i].name, personName) == 0) {
                    printf("Registro %s %u %.2f\n", persons[i].name, persons[i].age, persons[i].salary);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Registro ausente\n");
            }
        }
    }
    return 0;
}