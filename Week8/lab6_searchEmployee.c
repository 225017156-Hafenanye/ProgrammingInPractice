#include <stdio.h>

int searchEmployee(int id, int ids[], int size);

int main(void)
{
    int employeeIDs[] = {101, 102, 103, 104, 105};
    int size = sizeof(employeeIDs) / sizeof(employeeIDs[0]);
    int id, position;

    printf("Enter employee ID: ");
    scanf("%d", &id);

    position = searchEmployee(id, employeeIDs, size);

    if (position != -1)
        printf("Employee found at position %d.\n", position);
    else
        printf("Employee not found.\n");

    return 0;
}

int searchEmployee(int id, int ids[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (ids[i] == id)
        {
            return i;
        }
    }
    return -1;
}