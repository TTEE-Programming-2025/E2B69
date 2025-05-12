#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 初始化 9x9 座位表，'-' 表示空位，'*' 表示已被預定，'@' 表示已安排
char seats[9][9];
int i,j,k;

// 顯示個人風格的畫面
void displayWelcome() 
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
    printf(" \n");
    printf("Please enter the password：");
}

// 初始化座位表並隨機生成10個已預定座位
void initSeats() 
{
    for (i = 0; i < 9; i++)
        for ( j = 0; j < 9; j++)
            seats[i][j] = '-';
    
    srand(time(NULL));
    int count = 0;
    while (count < 10) {
        int row = rand() % 9;
        int col = rand() % 9;
        if (seats[row][col] == '-') {
            seats[row][col] = '*';
            count++;
        }
    }
}

// 顯示座位表，將 '@' 顯示為 '*'
void displaySeats() 
{
    printf("  123456789\n");
    for ( i = 8; i >= 0; i--) 
    {
        printf("%d ", i + 1);
        for ( j = 0; j < 9; j++)
            printf("%c", seats[i][j] == '@' ? '*' : seats[i][j]);
        printf("\n");
    }
}

// 主選單
void displayMenu() 
{
    system("cls"); 
    printf("*--------[Booking System]--------*\n");
    printf("| a. Available seats             |\n");
    printf("| b. Arrange for you             |\n");
    printf("| c. Choose by your self         |\n");
    printf("| d. EXIT                        |\n");
    printf("*--------------------------------*\n");
    printf("Please enter your choice：");
}

// 系統安排座位
void arrangeSeats() 
{
    int num;
    printf("How many seats do you need (1-4)?：");
    scanf("%d", &num);
    if (num < 1 || num > 4) {
        printf("Unvalible number of seats！\n");
        return;
    }
    
    int arranged = 0;
    if (num <= 3) {
        for ( i = 0; i < 9 && !arranged; i++) {
            for ( j = 0; j <= 9 - num; j++) {
                int free = 1;
                for (k = 0; k < num; k++)
                    if (seats[i][j + k] != '-') free = 0;
                if (free) {
                    for ( k = 0; k < num; k++)
                        seats[i][j + k] = '0';
                    arranged = 1;
                    break;
                }
            }
        }
    } else { // num == 4
        // 先嘗試同一行
        for ( i = 0; i < 9 && !arranged; i++) {
            for (j = 0; j <= 5; j++) {
                if (seats[i][j] == '-' && seats[i][j + 1] == '-' && 
                    seats[i][j + 2] == '-' && seats[i][j + 3] == '-') {
                    seats[i][j] = seats[i][j + 1] = seats[i][j + 2] = seats[i][j + 3] = '0';
                    arranged = 1;
                    break;
                }
            }
        }
        // 嘗試相鄰兩行
        if (!arranged) {
            for (i = 0; i < 8 && !arranged; i++) {
                for (j = 0; j < 8; j++) {
                    if (seats[i][j] == '-' && seats[i][j + 1] == '-' && 
                        seats[i + 1][j] == '-' && seats[i + 1][j + 1] == '-') {
                        seats[i][j] = seats[i][j + 1] = seats[i + 1][j] = seats[i + 1][j + 1] = '0';
                        arranged = 1;
                        break;
                    }
                }
            }
        }
    }
    
    if (arranged) {
        displaySeats();
        char choice;
        printf("Satisfy with this arrangement? (y/n)：");
        scanf(" %c", &choice);
        if (choice == 'y') {
            // 將 '0' 改為 '@'
            for (i = 0; i < 9; i++)
                for (j = 0; j < 9; j++)
                    if (seats[i][j] == '0') seats[i][j] = '@';
        } else {
            // 將 '0' 恢復為 '-'
            for (i = 0; i < 9; i++)
                for ( j = 0; j < 9; j++)
                    if (seats[i][j] == '0') seats[i][j] = '-';
        }
    } else {
        printf("Unable to arrange consecutive seats！\n");
    }
}

// 使用者選擇座位
void chooseSeats() 
{
    int row, col;
    printf("Please enter the seat number (ex: 1-2)：");
    if (scanf("%d-%d", &row, &col) != 2 || row < 1 || row > 9 || col < 1 || col > 9) {
        printf("Invalid input！\n");
        return;
    }
    row--; col--; // 轉換為陣列索引
    if (seats[row][col] == '-') {
        seats[row][col] = '@'; // 改為 '@' 表示已安排
        displaySeats();
    } else {
        printf("The seat has been reserved！\n");
    }
}

int main() 
{
    // 1. 密碼驗證，限制三次
    int password;
    int attempts = 0;
    displayWelcome();
    while (attempts < 3) {
        scanf("%d", &password);
        if (password == 2025) {
            printf("Password confirm！Welcome！\n");
            break;
        } else {
            attempts++;
            if (attempts < 3) {
                printf("Error！Please check your password and try again (%d attempts left)：", 3 - attempts);
            } else {
                printf("Too many incorrect attempts！Program terminated.\n");
                return 1;
            }
        }
    }

    // 初始化座位表
    initSeats();

    // 主循環
    char choice;
    do {
        displayMenu();
        scanf(" %c", &choice);
        switch (choice) {
            case 'a': // 顯示可用座位
                displaySeats();
                break;
            case 'b': // 系統安排座位
                arrangeSeats();
                break;
            case 'c': // 使用者選擇座位
                chooseSeats();
                break;
            case 'd': // 退出選項
                printf("Continue? (y/n)：");
                scanf(" %c", &choice);
                if (choice == 'n') return 0;
                break;
            default:
                printf("Unvalible Choice！\n");
        }
        printf("Press Enter to Continue...");
        getchar(); getchar(); // 等待使用者輸入
    } while (1);

    return 0;
}
