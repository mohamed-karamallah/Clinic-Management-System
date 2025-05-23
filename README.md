# Clinic Management System

A C-based clinic management system that provides both administrative and user interfaces for managing patient records and appointments.

## Features

### Admin Features
- Add new patient records
- Edit existing patient information
- Reserve appointment slots
- Cancel reservations
- View all patient records

### User Features
- View patient records
- Check today's reservations
- View available appointment slots

## System Requirements
- C compiler (GCC recommended)
- Standard C libraries
- Windows/Linux/MacOS operating system

## Installation

1. Clone the repository:
```bash
git clone https://github.com/mohamed-karamallah/Clinic-Management-System.git
```

2. Navigate to the project directory:
```bash
cd Clinic-Management-System
```

3. Compile the program:
```bash
gcc main.c admin.c user.c -o clinic_system
```

4. Run the program:
```bash
./clinic_system
```

## Usage

### Admin Mode
1. Select mode 1 (Admin) from the main menu
2. Enter the admin password (default: 1234)
3. Choose from the following options:
   - Add new patient
   - Edit patient record
   - Reserve a slot
   - Cancel reservation
   - Exit admin mode

### User Mode
1. Select mode 2 (User) from the main menu
2. Choose from the following options:
   - View patient record
   - View today's reservations
   - Exit user mode

## Data Structure
The system uses a linked list to store patient records with the following information:
- Name
- Age
- Gender
- ID
- Reserved slot

## Appointment Slots
The system manages 5 appointment slots:
- Slot A
- Slot B
- Slot C
- Slot D
- Slot E

## Contributing
Feel free to submit issues and enhancement requests!

## License
This project is open source and available under the MIT License.

## Author
Mohamed Karamallah 