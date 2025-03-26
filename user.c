#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD_TYPES.h"
#include "admin.h"
#include "user.h"

void User()
{
    uint32 option;
    

    printf("Welcome to user mode\n\n");

    while (1)
    {
        printf("1. View Patient Record\t\t2. View Today's Reservations\t\t3. Exit User Mode\n");
        printf("Enter your choice: ");
          if (scanf("%d", &option) != 1 || getchar() != '\n')
{
    fflush(stdin);
    printf("\nInvalid input, please enter a valid number.\n");
    continue;
}

        switch (option)
        {
            case PATIENT_RECORD: 
                PatientRecord();
                break;
            case TODAY_RESERVATION:
                TodayReservation();
                break;
            case EXIT_USER:
                return;
            default:
                 printf("\nInvalid choice, please choose 1, 2, or 3.\n");
                break;
        }
    }
}

void PatientRecord()
{
    uint32 ID;
    uint8 index = 0;
    patient_t *ptr = head;

    printf("Enter Patient ID: ");
    if (scanf("%d", &ID) != 1)
    {
        printf("\nInvalid input. Please enter a number.\n");
        fflush(stdin); 
        return;
    }

    while (ptr != NULL)
    {
        index++;
        if (ID == ptr->id)
        {
            printf("\nPatient Record:\n");
            Print(index);
            return;
        }
        ptr = ptr->next;
    }

    printf("ID not found!\n");
}

void TodayReservation()
{
    patient_t *ptr = head;
    uint8 reserved = 0;

    printf("\nReserved Slots:\n\n");
    while (ptr != NULL)
    {
        if (ptr->slot != ' ')
        {
            switch (ptr->slot)
{
    case SLOT_A:
        printf("ID: %d has a reservation from 2pm to 2:30pm\n", ptr->id);
        break;
    case SLOT_B:
        printf("ID: %d has a reservation from 2:30pm to 3pm\n", ptr->id);
        break;
    case SLOT_C:
        printf("ID: %d has a reservation from 3pm to 3:30pm\n", ptr->id);
        break;
    case SLOT_D:
        printf("ID: %d has a reservation from 4pm to 4:30pm\n", ptr->id);
        break;
    case SLOT_E:
        printf("ID: %d has a reservation from 4:30pm to 5pm\n", ptr->id);
        break;
    default:
        break;
}
            reserved = 1;
        }
        ptr = ptr->next;
    }

    if (!reserved)
    {
        printf("No Reserved Slots.\n\n");
    }
}
