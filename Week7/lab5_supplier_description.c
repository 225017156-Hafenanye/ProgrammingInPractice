#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[] = "ABC Office Supplies";
    char town[] = "Windhoek";
    char description[200];

    strcpy(description, name);              /* start with the name */
    strcat(description, " operates in ");   /* add the middle text */
    strcat(description, town);              /* add the town */
    strcat(description, ".");               /* finish the sentence */

    printf("%s\n", description);

    return 0;
}