#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

struct Student students[100];
int count = 0;

void addStudent() {
    if(count >= 100) {
        printf("List full! Max 100 students allowed.\n");
        return;
    }
    printf("Enter Roll Number: ");
    scanf("%d", &students[count].roll);
    printf("Enter Name: ");
    scanf(" %[^\n]", students[count].name);
    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);
    count++;
    printf("Student Added Successfully!\n\n");
}

void displayStudents() {
    if(count == 0) {
        printf("No students found! Add students first.\n\n");
        return;
    }
    printf("\n--- All Student Records ---\n");
    for(int i = 0; i < count; i++) {
        printf("%d. Roll: %d | Name: %s | Marks: %.2f\n",
               i+1, students[i].roll, students[i].name, students[i].marks);
    }
    printf("---------------------------\n\n");
}

void searchStudent() {
    if(count == 0) {
        printf("No students to search! Add students first.\n\n");
        return;
    }
    int roll, found = 0;
    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);
    for(int i = 0; i < count; i++) {
        if(students[i].roll == roll) {
            printf("\n--- Student Found ---\n");
            printf("Roll: %d\n", students[i].roll);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n\n", students[i].marks);
            found = 1;
            break;
        }
    }
    if(!found) printf("Student with Roll %d not found!\n\n", roll);
}

int main() {
    int choice;
    printf("=== STUDENT MANAGEMENT SYSTEM ===\n\n");
    while(1) {
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4:
                printf("\nThank you! Exiting...\n");
                return 0;
            default: printf("Invalid choice! Please enter 1-4\n\n");
        }
    }
}
