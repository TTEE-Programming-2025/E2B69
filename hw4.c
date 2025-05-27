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
    puts("aaaaaaaaaaa   aa aaa aaa aaa a a aaaa aaaaaaaaaaaaaaaaaaaaaaa aaaaaaaa");
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

/* �ˬd�Ǹ��O�_�ߤ@ */
int isUniqueId(struct Student *students, int numStudents, int id) 
{
    int i;
    for (i = 0; i < numStudents; i++) {
        if (students[i].id == id) {
            return 0; // ���ߤ@
        }
    }
    return 1; // �ߤ@
}

/* ��J�ǥͦ��Z */
struct Student* enterGrades(int *numStudents) 
{
    int n, i, j;
    system("cls");
    printf("Enter the number of students (5-10): ");
    scanf("%d", &n);
    if (n < 5 || n > 10) {
        printf("Error: Number of students must be between 5 and 10.\n");
        return NULL;
    }
    *numStudents = n;

    /* �ʺA���t�O���� */
    struct Student *students = (struct Student*)malloc(n * sizeof(struct Student));
    if (students == NULL) {
        printf("Error: Memory allocation failed!\n");
        return NULL;
    }

    /* ��J�ǥ͸�� */
    for (i = 0; i < n; i++) {
        int id;
        do {
            printf("Enter student %d's ID (6-digit): ", i + 1);
            scanf("%d", &id);
            if (id < 100000 || id > 999999) {
                printf("Error: ID must be a 6-digit number (100000-999999).\n");
            } else if (!isUniqueId(students, i, id)) {
                printf("Error: ID already exists! Try another ID.\n");
            }
        } while (id < 100000 || id > 999999 || !isUniqueId(students, i, id));
        students[i].id = id;

        printf("Enter student %d's name (up to 19 chars): ", i + 1);
        scanf("%19s", students[i].name);

        printf("Enter Math, Physics, English scores (0-100) for student %d: ", i + 1);
        float sum = 0;
        for (j = 0; j < 3; j++) {
            int score;
            do {
                scanf("%d", &score);
                if (score < 0 || score > 100) {
                    printf("Error: Score %d must be between 0 and 100: ", j + 1);
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

/* ��ܩҦ��ǥͦ��Z�A���榡 */
void displayGrades(struct Student *students, int numStudents) 
{
    int i;
    system("cls");
    if (students == NULL || numStudents == 0) {
        printf("No student data available!\n");
        return;
    }
    printf("==============================================================\n");
    printf("Student Grades:\n");
    printf("--------------------------------------------------------------\n");
    printf("%-20s %-10s %-8s %-10s %-10s %-8s\n", "Name", "ID", "Math", "Physics", "English", "Average");
    printf("--------------------------------------------------------------\n");
    for (i = 0; i < numStudents; i++) {
        printf("%-20s %06d %-8d %-10d %-10d %-8.1f\n",
               students[i].name, students[i].id, students[i].scores[0],
               students[i].scores[1], students[i].scores[2], students[i].average);
    }
    printf("==============================================================\n");
}

/* ���m�W�d�߾ǥͦ��Z�A��ܩҦ��ǰt���G */
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
    scanf("%19s", searchName);
    printf("==============================================================\n");
    printf("Search Results:\n");
    printf("--------------------------------------------------------------\n");
    printf("%-20s %-10s %-8s %-10s %-10s %-8s\n", "Name", "ID", "Math", "Physics", "English", "Average");
    printf("--------------------------------------------------------------\n");
    for (i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("%-20s %06d %-8d %-10d %-10d %-8.1f\n",
                   students[i].name, students[i].id, students[i].scores[0],
                   students[i].scores[1], students[i].scores[2], students[i].average);
            found = 1;
        }
    }
    printf("==============================================================\n");
    if (!found) {
        printf("Student with name %s not found!\n", searchName);
    }
}

/* ���Z�ƦW�A���������Z���� */
void gradeRanking(struct Student *students, int numStudents) 
{
    int i, j;
    system("cls");
    if (students == NULL || numStudents == 0) {
        printf("No student data available!\n");
        return;
    }
    /* �ƻs�ǥͰ}�C�A�קK�ק��l��� */
    struct Student *sorted = (struct Student*)malloc(numStudents * sizeof(struct Student));
    if (sorted == NULL) {
        printf("Error: Memory allocation failed!\n");
        return;
    }
    for (i = 0; i < numStudents; i++) {
        sorted[i] = students[i];
    }
    /* �_�w�ƧǡA���������Z���� */
    for (i = 0; i < numStudents - 1; i++) {
        for (j = 0; j < numStudents - i - 1; j++) {
            if (sorted[j].average < sorted[j + 1].average) {
                struct Student temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }
    /* ��ܱƦW */
    printf("==============================================================\n");
    printf("Grade Ranking:\n");
    printf("--------------------------------------------------------------\n");
    printf("%-5s %-20s %-10s %-8s\n", "Rank", "Name", "ID", "Average");
    printf("--------------------------------------------------------------\n");
    for (i = 0; i < numStudents; i++) {
        printf("%-5d %-20s %06d %-8.1f\n", i + 1, sorted[i].name, sorted[i].id, sorted[i].average);
    }
    printf("==============================================================\n");
    free(sorted);
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
                printf("Error: Please try again (%d attempts left): ", 3 - attempts);
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
            case 'd': // ���Z�ƦW
                gradeRanking(students, numStudents);
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
//�����o���@�~���ڦ�ì�}�h�C�q���q1����¦�ج[�춥�q4�����������A�ڳv�B��{�F�K�X���ҡB���ާ@�B���Z��J�B��ܡB�d�ߩM�ƦW�\��A�`�J�z�ѤF C �y�������ΡC
//�o���@�~���ھǷ|�ϥε��c�]struct Student�^��´�Ǹ��B�m�W�M���Z��ơA�óz�L�ʺA�O������t�]malloc �M free�^�䴩�F�����ǥͼƶq�C�q���q2�}�l�A�ڥ[�J��J���ҡA�T�O�Ǹ���6��B���Z�b0-100�����F�춥�q4�A���{�Ǹ��ߤ@���ˬd�A���ɵ{��í�w�ʡC�]�p�D���M������������|��ҲդƵ{���M���[��X�����n�ʡC��@�_�w�Ƨǧ����ƦW�\��A�h���ڪ�B�x���t��k�����ΡC
//�L�{���A�ѨM�sĶ���~�]�p ld returned 1 exit status�^���ھǷ|�ˬd���Ұ��D�A�Ҧp�����B�椤���{���Ψϥ� ASCII ���|�C���ӡA�ڧƱ��u�ƱƧǮĲv�å[�J���Z�ק�\��C�o���@�~���ȴ��ɤF�ڪ��{���]�p��O�A�]���ڹ�ϥΪ�����M�{�������ʦ��F��`���{�ѡC
