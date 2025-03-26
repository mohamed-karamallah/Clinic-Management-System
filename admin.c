#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD_TYPES.h"
#include"admin.h"

patient_t *head = NULL;
uint8 a = SLOT_AVAILABLE, b = SLOT_AVAILABLE, c = SLOT_AVAILABLE, d = SLOT_AVAILABLE, e = SLOT_AVAILABLE;
void Admin()
{
	uint32 choice, password;
	uint8  pass = 0, counter = 0;
	
	while(1)
	{
  printf("Please enter password: ");
   
        if (scanf("%d", &password) != 1 || getchar() != '\n')
        {
            fflush(stdin);
            printf("Invalid format,it should be digits followed by 'enter'\n");
            counter++;
            if (counter >= 3)
            {
                exit(0);
            }
            continue;
        }

        if (password == Admin_Password)
        {
            printf("\nWelcome to admin mode\n\n");
            break;
        }
        else
        {
            printf("Incorrect password.\n");
            counter++;
            if (counter >= 3)
            {
                exit(0);
            }
        }
	}
	
	while(1)
	{
		printf("1.Add new patient record\t2.Edit patient record.\n3.Reserve a slot.\t\t4.Cancel reservation.\n5.Exit Admin mode\n");
		printf("\nEnter your choice: ");
		 if (scanf("%d", &choice) != 1 || getchar() != '\n')
{
    fflush(stdin);
    printf("\nInvalid input, please enter a valid number.\n");
    continue;
}
		
		switch(choice)
		{
			case ADD_PATIENT:
			{
				AddPatient();
				break;
			}
			case EDIT:
			{
				EditPatientRecord();
				break;
			}
			case RESERVE_SLOT:
			{
				ReserveSlot();
				break;
			}
			case CANCEL:
			{
				Cancel_Reservation();
				break;
			}
			case EXIT_ADMIN:
			{
				return;
			}
			default:
			{
				printf("Invalid Input.\n");
				
				break;
			}
		}
	}
}


void AddPatient()
{
	uint32 Age, ID;
	uint8 Name[50], Gender[10];
	patient_t *ptr = head;
	printf("Please Enter Patient informations\n\nName: ");
	fgets(Name, sizeof(Name), stdin);
	Name[strlen(Name) - 1] = 0;
	printf("Age: ");
	   if (scanf("%d", &Age) != 1 || getchar() != '\n')
{
    fflush(stdin);
    printf("\nInvalid,age should be a number\n");
    return;
}
	printf("Gender: ");
	fgets(Gender, sizeof(Gender), stdin);
	Gender[strlen(Gender) - 1] = 0;
	printf("ID: ");
	   if (scanf("%d", &ID) != 1 || getchar() != '\n')
{
    fflush(stdin);
    printf("\nInvalid,ID should be a number\n");
    return;
}
	
	if(ptr != NULL)
	{
		while(ptr != NULL)
		{
			if(ID == ptr->id)
			{
				printf("\nThis ID already Exist\n");
				
				return;
			}
			ptr = ptr->next;
		}
	}
	
	patient_t *new_node = (patient_t *) malloc(sizeof(patient_t));
	
strncpy(new_node->name, Name, sizeof(new_node->name));
    new_node->age = Age;
    strncpy(new_node->gender, Gender, sizeof(new_node->gender));
    new_node->id = ID;
    new_node->slot = ' ';
    new_node->next = NULL;
	
	if(head == NULL)
	{
		head = new_node;
	}
	else
	{
		ptr=head;
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = new_node;
	}
	printf("\nPatient has been added.\n");
	
}	


void Print(uint8 index)
{
	patient_t *ptr = head;
	
	if(ptr == NULL)
	{
		printf("No patients found\n");
		return;
	}
	  for (uint32 i = 0; i < index - 1 ; i++)
    {
        ptr = ptr->next;
    }

    if (ptr != NULL)
    {
        printf("Name: %s\n", ptr->name);
        printf("Age: %d\n", ptr->age);
        printf("Gender: %s\n", ptr->gender);
    }
    else
    {
        printf("Patient not found.\n");
    }
}

void EditPatientRecord()
{
	uint32 ID, Age;
	uint8 Name[50], Gender[10], counter = 0, index = 0;
	patient_t *ptr = head;
	
	printf("Enter ID to edit: ");
	scanf("%d", &ID);
	
	while(ptr != NULL)
	{
		index++;
		if(ID == ptr->id)
		{
			printf("ID exist.\n\n");
			printf("Patient information.\n\n");
			Print(index);
			counter++;
			break;
		}
		ptr = ptr->next;
	}
	
	if(counter == 0)
	{
		printf("\nID not found!\n");
		
		return;
	}
	
	printf("Please Enter Patient new informations\n\nName: ");
	fflush(stdin);
	 fgets(ptr->name, sizeof(ptr->name), stdin);
	ptr->name[strcspn(ptr->name, "\n")] = 0;
	printf("Age: ");
	scanf("%d", &ptr->age);
	printf("Gender: ");
	fflush(stdin);
	fgets(ptr->gender, sizeof(ptr->gender), stdin);
	ptr->gender[strcspn(ptr->gender, "\n")] = 0;
	printf("New patien information.\n");
	Print(index);
}

void ReserveSlot()
{
    uint8 slot_choice;
    uint32 ID;
    uint8 found = 0;
    patient_t *ptr = head;

    printf("Available slots:\n");
    if (a == SLOT_AVAILABLE) printf("a. 2pm to 2:30pm\n");
    if (b == SLOT_AVAILABLE) printf("b. 2:30pm to 3pm\n");
    if (c == SLOT_AVAILABLE) printf("c. 3pm to 3:30pm\n");
    if (d == SLOT_AVAILABLE) printf("d. 4pm to 4:30pm\n");
    if (e == SLOT_AVAILABLE) printf("e. 4:30pm to 5pm\n");

    if (a == SLOT_RESERVED && b == SLOT_RESERVED && c == SLOT_RESERVED && d == SLOT_RESERVED && e == SLOT_RESERVED)
    {
        printf("No available slots.\n");
        return;
    }

    printf("Enter patient ID: ");
    if (scanf("%d", &ID) != 1 ||  getchar() != '\n')
    {
        fflush(stdin);
        printf("Invalid input. Please enter ID as a number.\n");
        return;
    }

    while (ptr != NULL)
    {
        if (ID == ptr->id)
        {
            if (ptr->slot != ' ')
            {
                printf("Patient already has a reservation.\n");
                return;
            }

            printf("Enter slot character: ");
            scanf(" %c", &slot_choice);

            if ((slot_choice == SLOT_A && a == SLOT_RESERVED) ||
                (slot_choice == SLOT_B && b == SLOT_RESERVED) ||
                (slot_choice == SLOT_C && c == SLOT_RESERVED) ||
                (slot_choice == SLOT_D && d == SLOT_RESERVED) ||
                (slot_choice == SLOT_E && e == SLOT_RESERVED))
            {
                printf("Slot is already reserved. Please choose a different slot.\n");
                return;
            }

            if (slot_choice == SLOT_A && a == SLOT_AVAILABLE) {
				ptr->slot = SLOT_A; a = SLOT_RESERVED;
				}
            else if (slot_choice == SLOT_B && b == SLOT_AVAILABLE) {
				ptr->slot = SLOT_B; b = SLOT_RESERVED; 
				}
            else if (slot_choice == SLOT_C && c == SLOT_AVAILABLE) {
				ptr->slot = SLOT_C; c = SLOT_RESERVED;
				}
            else if (slot_choice == SLOT_D && d == SLOT_AVAILABLE) {
				ptr->slot = SLOT_D; d = SLOT_RESERVED; 
				}
            else if (slot_choice == SLOT_E && e == SLOT_AVAILABLE) {
				ptr->slot = SLOT_E; e = SLOT_RESERVED;
				}
            else
            {
                printf("Invalid slot choice or slot not available.\n");
                return;
            }

            printf("Slot has been reserved.\n");
            found = 1;
            break;
        }
        ptr = ptr->next;
    }

    if (!found)
    {
        printf("Patient ID not found.\n");
    }
}


void Cancel_Reservation()
{
    uint32 ID;
    uint8 counter = 0;
    patient_t *ptr = head;

    printf("To cancel reservation enter:\n");
    printf("ID: ");
    if(scanf("%d", &ID) != 1||getchar() != '\n') {
        printf("\nInvalid, please enter a valid ID.\n");
        fflush(stdin);
        
        return;
    }

    while(ptr != NULL)
    {
        if(ID == ptr->id)
        {
            if(((ptr->slot == SLOT_A && a == SLOT_RESERVED) ||
                (ptr->slot == SLOT_B && b == SLOT_RESERVED) ||
                (ptr->slot == SLOT_C && c == SLOT_RESERVED) ||
                (ptr->slot == SLOT_D && d == SLOT_RESERVED) ||
                (ptr->slot == SLOT_E && e == SLOT_RESERVED)))
            {
                switch(ptr->slot)
                {
                    case SLOT_A:
                        a = SLOT_AVAILABLE;
                        break;
                    case SLOT_B:
                        b = SLOT_AVAILABLE;
                        break;
                    case SLOT_C:
                        c = SLOT_AVAILABLE;
                        break;
                    case SLOT_D:
                        d = SLOT_AVAILABLE;
                        break;
                    case SLOT_E:
                        e = SLOT_AVAILABLE;
                        break;
                    default:
                        printf("\nInvalid slot status!\n");
                        
                        return;
                }
                ptr->slot = ' ';
                printf("\nReservation has been canceled.\n");
                
                return;
            }
            else
            {
                printf("\nThis patient doesn't have a reservation.\n");
                
                return;
            }
        }
        ptr = ptr->next;
    }
    printf("\nIncorrect ID.\n");
    
}


