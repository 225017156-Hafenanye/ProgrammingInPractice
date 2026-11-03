#include <stdio.h>
#include <string.h>

#define MAX 5

int main(void)
{
    char names[MAX][100];
    char emails[MAX][100];
    char phones[MAX][30];
    char towns[MAX][50];
    char searchName[100];
    int i, found = 0;

    for (i = 0; i < MAX; i++)
    {
        printf("\n--- Supplier %d ---\n", i + 1);

        printf("Name : ");
        fgets(names[i], sizeof(names[i]), stdin);
        names[i][strcspn(names[i], "\n")] = '\0';

        printf("Email: ");
        fgets(emails[i], sizeof(emails[i]), stdin);
        emails[i][strcspn(emails[i], "\n")] = '\0';

        printf("Phone: ");
        fgets(phones[i], sizeof(phones[i]), stdin);
        phones[i][strcspn(phones[i], "\n")] = '\0';

        printf("Town : ");
        fgets(towns[i], sizeof(towns[i]), stdin);
        towns[i][strcspn(towns[i], "\n")] = '\0';
    }

    printf("\n=========== ALL SUPPLIERS ===========\n");
    for (i = 0; i < MAX; i++)
    {
        printf("%d. %s | %s | %s | %s\n", i + 1, names[i], emails[i], phones[i], towns[i]);
    }

    printf("\nEnter supplier name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    for (i = 0; i < MAX; i++)
    {
        if (strcmp(names[i], searchName) == 0)
        {
            printf("Supplier found at position %d.\n", i + 1);
            printf("Name : %s\nEmail: %s\nPhone: %s\nTown : %s\n",
                   names[i], emails[i], phones[i], towns[i]);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Supplier not found.\n");

    return 0;
}