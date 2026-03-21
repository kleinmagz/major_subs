ASSIGNMENT ITE 14 - BI1
DATA GIVEN: 2026-01-27

A school is developing a Student Record System using the C programming language to manage student information efficiently.
Since the number of students is not fixed and may increase over time, the program uses a dynamic structure with dynamic memory allocation
Initially, the user enters the number of students, and their records - consisting of studentID, name, and GPA - are stored in dynamically allocated memory using malloc().
The function inputStudents() is responsible for accepting and storing student details into the structure array.
If additional students need to be added later, the program expands the existing memory usisng realloc() without losing the previously stored records.
Finally, the system allows the user to search for a student by entering a student ID; the program scans the dynamically allocated structure array and displays the matching student's information if found, or an appropriate message if the ID does not exist.
