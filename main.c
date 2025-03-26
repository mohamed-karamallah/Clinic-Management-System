#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD_TYPES.h"
#include "admin.h"
#include "user.h"

int main()
{
    uint32 mode;

    while (1)
{
    printf("\nModes:\n1. Admin\n2. User\n3. Close Program\n\nEnter your choice: ");


   if (scanf("%d", &mode) != 1 || getchar() != '\n')
{
    fflush(stdin);
    printf("\nInvalid input, please enter a valid number.\n");
    continue;
}

    switch (mode)
    {
        case ADMIN:
            Admin();
            break;
        case USER:
            User();
            break;
        case END:
            printf("\nExiting program...\n");
            return 0;
        default:
            printf("\nInvalid choice, please choose 1, 2, or 3.\n");
      
    }
}

    return 0;
}
