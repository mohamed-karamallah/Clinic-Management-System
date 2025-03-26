#ifndef ADMIN_H
#define ADMIN_H

#define ADMIN 1
#define USER 2
#define END 3

#define Admin_Password 1234
#define ADD_PATIENT 1
#define EDIT 2
#define RESERVE_SLOT 3
#define CANCEL 4
#define EXIT_ADMIN 5
#define SLOT_A 'a'
#define SLOT_B 'b'
#define SLOT_C 'c'
#define SLOT_D 'd'
#define SLOT_E 'e'
#define SLOT_RESERVED 1
#define SLOT_AVAILABLE 0

typedef struct patient
{
	uint8 name[50];
	uint32 age;
	uint8 gender[10];
	uint32 id;
	uint8 slot;
	struct patient *next;
}patient_t;

void Admin(void);
void AddPatient(void);
void Print(uint8 index);
void EditPatientRecord(void);
void ReserveSlot(void);
void Cancel_Reservation(void);

extern patient_t *head;
extern uint8 a, b, c, d, e;//for reservations

#endif