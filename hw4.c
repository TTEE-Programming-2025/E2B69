#include <stdio.h>
#include <stdlib.h>

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
    puts("aaaaaaaaaaa   aa aaa aaa aaa aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa   aa aaaa aaa aaaaaaaaaaaaaaa aaaa aaaaaaaaaaaaaaaaaaaaaaa   aaaaaaa");
    puts("aaaaaaaaaaaa aa   a   a   a   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa aa   aa   aaaaaaaaaaaaaaaaaaaaaa   aaaaaaaaaaaaaaaaaaaaaaa aaaaaaaa");
    puts("aaaaaaaaaaaaaaaa aaa aaa aaa aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa aaaa aaaaaaaaaaaaaaaaaaaaaaaa aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
    printf("\nPlease enter the 4-digit password: ");
}

/* 顯示主選單，提供 a-e 選項 */
void showMenu() 
{
    system("cls"); // 清除螢幕
    printf("------------[Grade System]----------\n");
    printf("| a. Enter student grades          |\n");
    printf("| b. Display student grades        |\n");
    printf("| c. Search for student grades     |\n");
    printf("| d. Grade ranking                |\n");
    printf("| e. Exit system                  |\n");
    printf("------------------------------------\n");
    printf("Please enter your choice: ");
}

/* 輸入學生成績，固定5名學生 */
void enterGrades(int ids[], int scores[][3]) 
{
    int i;
    system("cls");
    printf("Enter grades for 5 students:\n");
    for (i = 0; i < 5; i++) {
        printf("Enter student %d's ID (6-digit): ", i + 1);
        scanf("%d", &ids[i]);
        printf("Enter Math, Physics, English scores for student %d: ", i + 1);
        scanf("%d %d %d", &scores[i][0], &scores[i][1], &scores[i][2]);
    }
    printf("Grades entered successfully!\n");
}

/* 顯示所有學生成績 */
void displayGrades(int ids[], int scores[][3], int numStudents) 
{
    int i;
    system("cls");
    if (numStudents == 0) {
        printf("No student data available!\n");
        return;
    }
    printf("Student Grades:\n");
    for (i = 0; i < numStudents; i++) {
        printf("ID: %06d, Scores: Math=%d, Physics=%d, English=%d\n", 
               ids[i], scores[i][0], scores[i][1], scores[i][2]);
    }
}

int main() 
{
    int password, attempts, i;
    int ids[5]; // 儲存5名學生的學號
    int scores[5][3]; // 儲存5名學生的三科成績
    int numStudents = 0; // 已輸入的學生數量

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
                printf("Error! Please try again (%d attempts left): ", 3 - attempts);
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
        scanf(" %c", &choice); // 空格吸收換行符
        switch (choice) {
            case 'a': // 輸入成績
                enterGrades(ids, scores);
                numStudents = 5; // 固定5名學生
                break;
            case 'b': // 顯示成績
                displayGrades(ids, scores, numStudents);
                break;
            case 'c': // 查詢成績（尚未實現）
                system("cls");
                printf("Search function not implemented yet.\n");
                break;
            case 'd': // 成績排名（尚未實現）
                system("cls");
                printf("Ranking function not implemented yet.\n");
                break;
            case 'e': // 退出系統
                system("cls");
                do {
                    printf("Confirm exit? (y/n): ");
                    scanf(" %c", &choice);
                    if (choice == 'y' || choice == 'Y') {
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
        getchar(); getchar(); // 等待使用者輸入
    } while (1);

    return 0;
}
