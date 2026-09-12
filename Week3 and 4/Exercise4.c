#include <stdio.h>

int main()
{
    char studentName[50];
    float test1;
    float test2;
    float assignment;
    float total;

    printf("Enter Student Name: ");
    scanf("%49s", studentName);

    printf("Enter Test 1 Mark: ");
    scanf("%f", &test1);

    printf("Enter Test 2 Mark: ");
    scanf("%f", &test2);

    printf("Enter Assignment Mark: ");
    scanf("%f", &assignment);

    total = test1 + test2 + assignment;

    printf("\nStudent: %s\n", studentName);
    printf("Total Mark: %.2f\n", total);

    if (total >= 75.0f && total <= 100.0f)
    {
        printf("Result: Distinction\n");
    }
    else if (total >= 60.0f && total < 75.0f)
    {
        printf("Result: Credit\n");
    }
    else if (total >= 50.0f && total < 60.0f)
    {
        printf("Result: Pass\n");
    }
    else
    {
        printf("Result: Fail\n");
    }

    return 0;
}