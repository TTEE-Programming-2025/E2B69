#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 定義學生結構 */
struct Student {
    int id;           // 6位學號
    char name[20];    // 姓名
    int scores[3];    // 數學、物理、英文成績
    float average;    // 平均成績
};

/* 顯示個人風格畫面 */
void showWelcome() 
{
    printf("班號:\n");
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

/* 顯示主選單，提供 a-e 選項 */
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

/* 檢查學號是否唯一 */
int isUniqueId(struct Student *students, int numStudents, int id) 
{
    int i;
    for (i = 0; i < numStudents; i++) {
        if (students[i].id == id) {
            return 0; // 不唯一
        }
    }
    return 1; // 唯一
}

/* 輸入學生成績 */
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

    /* 動態分配記憶體 */
    struct Student *students = (struct Student*)malloc(n * sizeof(struct Student));
    if (students == NULL) {
        printf("Error: Memory allocation failed!\n");
        return NULL;
    }

    /* 輸入學生資料 */
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

/* 顯示所有學生成績，表格格式 */
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

/* 按姓名查詢學生成績，顯示所有匹配結果 */
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

/* 成績排名，按平均成績降序 */
void gradeRanking(struct Student *students, int numStudents) 
{
    int i, j;
    system("cls");
    if (students == NULL || numStudents == 0) {
        printf("No student data available!\n");
        return;
    }
    /* 複製學生陣列，避免修改原始資料 */
    struct Student *sorted = (struct Student*)malloc(numStudents * sizeof(struct Student));
    if (sorted == NULL) {
        printf("Error: Memory allocation failed!\n");
        return;
    }
    for (i = 0; i < numStudents; i++) {
        sorted[i] = students[i];
    }
    /* 冒泡排序，按平均成績降序 */
    for (i = 0; i < numStudents - 1; i++) {
        for (j = 0; j < numStudents - i - 1; j++) {
            if (sorted[j].average < sorted[j + 1].average) {
                struct Student temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }
    /* 顯示排名 */
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

    /* 密碼驗證，最多三次嘗試 */
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

    /* 主循環，處理選單選擇 */
    char choice;
    do {
        showMenu();
        scanf(" %c", &choice);
        switch (choice) {
            case 'a': // 輸入成績
                system("cls");
                if (students != NULL) free(students);
                students = enterGrades(&numStudents);
                break;
            case 'b': // 顯示成績
                displayGrades(students, numStudents);
                break;
            case 'c': // 查詢成績
                searchGrades(students, numStudents);
                break;
            case 'd': // 成績排名
                gradeRanking(students, numStudents);
                break;
            case 'e': // 退出系統
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
//完成這次作業讓我收穫良多。從階段1的基礎框架到階段4的完善版本，我逐步實現了密碼驗證、選單操作、成績輸入、顯示、查詢和排名功能，深入理解了 C 語言的應用。
//這次作業讓我學會使用結構（struct Student）組織學號、姓名和成績資料，並透過動態記憶體分配（malloc 和 free）支援靈活的學生數量。從階段2開始，我加入輸入驗證，確保學號為6位且成績在0-100之間；到階段4，更實現學號唯一性檢查，提升程式穩定性。設計主選單和表格顯示讓我體會到模組化程式和美觀輸出的重要性。實作冒泡排序完成排名功能，則讓我初步掌握演算法的應用。
//過程中，解決編譯錯誤（如 ld returned 1 exit status）讓我學會檢查環境問題，例如關閉運行中的程式或使用 ASCII 路徑。未來，我希望優化排序效率並加入成績修改功能。這次作業不僅提升了我的程式設計能力，也讓我對使用者體驗和程式健壯性有了更深的認識。
