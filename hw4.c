#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* �w�q�ǥ͵��c */
struct Student {
    int id;           // 6��Ǹ�
    char name[20];    // �m�W
    int scores[3];    // �ƾǡB���z�B�^�妨�Z
    float average;    // �������Z
};

/* ��ܭӤH����e�� */
void showWelcome() 
{
    printf("�Z��:\n");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa aaa aaa aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa aaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa   a   a   aaa aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa   aa aaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaa aaa aaa aaa aaaaaaa aaa aaa aaa   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa aa   aaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaa   a   a   a   aaaaaaaaaaaaaaaaaaa aaaaaaaaaaaaaaaaa aaaa aaaa aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa aaaaa aa aaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaa  aaaaa aaa aaa aaaaaaaaaaaaaaaaaa aaaaaaaaaaaaaa aa   aa   aa   aaaaaaaaa aaaaaaaaaaaaaaaaaaaa   aaaaaa   aa aaaaaaaaaa");
    puts("aaaaaaaaaaa   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa   aaaaaaaaaaaa   aa aaaa aaaa aaaaaaaaa   aaaaaaaaaaaaaaaaaaaa a aaaaaa aa   aaaaaaaaa");
    puts("aaaaaaaaaa   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa aaaaaaaaaaaaaa aaaaaaaaaaaa aaaaaaaaa a aaaaaaaaaaaaaaaaaaaaaa   aaaa aaaa a aaaaaaaa");
    puts("aaaaaaaaa   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa aaaaaaaaaaaaaaa aaaaaaaaaaa   aaaaaaa   aaaaaaaaaaaaaaaaaaaaaaaa aa a   aaaa   aaaaaaa");
    puts("aaaaaaaa   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa   aaaaaaa aaaaa   aaaaaaaaaaa aaaaaaaaa aaaaaaaaaa aaa aaaaaaaaaaaa   a aaaaaa a aaaaaa");
    puts("aaaaaa   a aaa aaa aaa aaa aaaaaaaaaaaaaaaaaa aaaaaaa   aaaaa aaaaaaaaaaa aaaaaaaaaaa aaaaaaaa   a   aaaaaaaaaaaa aaaaaaaaaa   aaaaa");
    puts("aaaaa   aa   a   a   a   a   aaaaaaaaaaaaaa aaaaaaa aa aaaaaa aaaaaaaaaa   aaaaaaaaa   aaaaa aa aaa a aaaaaaaaaaaaaaaaaaaaaaa a aaaa");
    puts("aaaaaa a aa aaa aaa aaa aaa aaaaaaaaaaaaaa   aa aa   aaaaaaa   aaa aaa aaa aaaaaaaaaa a aaa   aaaaaa   aaaaaaaaaaaaaaaaaaaaaaa   aaa");
    puts("aaaaaaa   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa aa   aa aaaaaaaaa aaa   a   a   aaaaaaaaaa   a a aaaaaaaa aaaaaaaaaaaaaaaaaaaaaaaaa aaaa");
    puts("aaaaaaaa a aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa aaa0aaaaaaaaa aaaa aaa aaa aaaaaaaaaaaa a   aaaaaaaa aaaaaaaaaaaaaaaaaaaaaaaa aaaaaa");
    puts("aaaaaaaaa   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa   aaaaaaaaaaaaaa aaaaaaaaaaaa aa aaaaa   aaaaaaaaaaaaaaaaaaaaaa   aaaaa");
    puts("aaaaaaaaaa a aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa aa aaaaaaaaaaa   aaaaaaaaaaaaa   aaaaa aaaaaaaaaaaaaaaaaaaaaa aa aaaaa");
    puts("aaaaaaaaaaa   aa aaa aaa aaa aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa   aa aaaa aaa aaaaaaaaaaaaaaa aaaa aaaaaaaaaaaaaaaaaaaaaaa   aaaaaaa");
    puts("aaaaaaaaaaaa aa   a   a   a   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa aa   aa   aaaaaaaaaaaaaaaaaaaaaa   aaaaaaaaaaaaaaaaaaaaaaa aaaaaaaa");
    puts("aaaaaaaaaaaaaaaa aaa aaa aaa aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa aaaa aaaaaaaaaaaaaaaaaaaaaaaa aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
    printf("\nPlease enter the 4-digit password: ");
}

/* ��ܥD���A���� a-e �ﶵ */
void showMenu() 
{
    system("cls");
    printf("------------[Grade System]----------\n");
    printf("| a. Enter student grades          |\n");
    printf("| b. Display student grades        |\n");
    printf("| c. Search for student grades     |\n");
    puts("| d. Grade ranking                |");
    puts("| e. Exit system                  |");
    printf("------------------------------------\n");
    printf("Please enter your choice: ");
}

/* ��J�ǥͦ��Z�A�䴩5-10�W�ǥ� */
struct Student* enterGrades(int *numStudents) 
{
    int n, i, j;
    system("cls");
    printf("Enter the number of students (5-10): ");
    scanf("%d", &n);
    if (n < 5 || n > 10) {
        printf("Invalid number of students! Must be 5-10.\n");
        return NULL;
    }
    *numStudents = n;

    /* �ʺA���t�ǥͰ}�C */
    struct Student *students = (struct Student*)malloc(n * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    /* ��J�C�Ӿǥͪ���� */
    for (i = 0; i < n; i++) {
        int id;
        do {
            printf("Enter student %d's ID (6-digit): ", i + 1);
            scanf("%d", &id);
            if (id < 100000 || id > 999999) {
                printf("Invalid ID! Must be 6-digit (100000-999999).\n");
            }
        } while (id < 100000 || id > 999999);
        students[i].id = id;

        printf("Enter student %d's name: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter Math, Physics, English scores (0-100) for student %d: ", i + 1);
        float sum = 0;
        for (j = 0; j < 3; j++) {
            int score;
            do {
                scanf("%d", &score);
                if (score < 0 || score > 100) {
                    printf("Invalid score! Enter score %d (0-100): ", j + 1);
                }
            } while (score < 0 || score > 100);
            students[i].scores[j] = score;
            sum += score;
        }
        students[i].average = sum / 3.0;
    }
    printf("Grades entered successfully!\n");
    return students;
}

/* ��ܩҦ��ǥͦ��Z */
void displayGrades(struct Student *students, int numStudents) 
{
    int i;
    system("cls");
    if (students == NULL || numStudents == 0) {
        printf("No student data available!\n");
        return;
    }
    printf("Student Grades:\n");
    for (i = 0; i < numStudents; i++) {
        printf("Name: %s, ID: %06d, Math: %d, Physics: %d, English: %d, Average: %.1f\n",
               students[i].name, students[i].id, students[i].scores[0],
               students[i].scores[1], students[i].scores[2], students[i].average);
    }
}

/* ���m�W�d�߾ǥͦ��Z */
void searchGrades(struct Student *students, int numStudents) 
{
    char searchName[20];
    int i, found = 0;
    system("cls");
    if (students == NULL || numStudents == 0) {
        printf("No student data available!\n");
        return;
    }
    printf("Enter student name to search: ");
    scanf("%s", searchName);
    for (i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("Student found:\n");
            printf("Name: %s, ID: %06d, Math: %d, Physics: %d, English: %d, Average: %.1f\n",
                   students[i].name, students[i].id, students[i].scores[0],
                   students[i].scores[1], students[i].scores[2], students[i].average);
            found = 1;
        }
    }
    if (!found) {
        printf("Student with name %s not found!\n", searchName);
    }
}

int main() 
{
    int password, attempts, numStudents = 0;
    struct Student *students = NULL;

    /* �K�X���ҡA�̦h�T������ */
    attempts = 0;
    showWelcome();
    while (attempts < 3) {
        scanf("%d", &password);
        if (password == 2025) {
            printf("Password confirmed! Welcome!\n");
            system("pause");
            system("cls");
            break;
        } else {
            attempts++;
            if (attempts < 3) {
                printf("Error! Please try again (%d attempts left): ", 3 - attempts);
            } else {
                printf("Too many incorrect attempts! Program terminated.\n");
                return 1;
            }
        }
    }

    /* �D�`���A�B�z����� */
    char choice;
    do {
        showMenu();
        scanf(" %c", &choice);
        switch (choice) {
            case 'a': // ��J���Z
                system("cls");
                if (students != NULL) free(students);
                students = enterGrades(&numStudents);
                break;
            case 'b': // ��ܦ��Z
                displayGrades(students, numStudents);
                break;
            case 'c': // �d�ߦ��Z
                searchGrades(students, numStudents);
                break;
            case 'd': // ���Z�ƦW�]�|����{�^
                system("cls");
                printf("Ranking function not implemented yet.\n");
                break;
            case 'e': // �h�X�t��
                system("cls");
                do {
                    printf("Confirm exit? (y/n): ");
                    scanf(" %c", &choice);
                    if (choice == 'y' || choice == 'Y') {
                        if (students != NULL) free(students);
                        return 0;
                    } else if (choice == 'n' || choice == 'N') {
                        break;
                    }
                } while (1);
                break;
            default:
                printf("Invalid choice!\n");
        }
        printf("Press Enter to continue...");
        getchar(); getchar();
    } while (1);

    if (students != NULL) free(students);
    return 0;
}
