#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 初始化 9x9 座位表，'-' 表示空位，'*' 表示已被預定，'@' 表示臨時安排
char seats[9][9];
int justArranged = 0; // 標誌：是否剛完成座位安排

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
    int i, j;
    for (i = 0; i < 9; i++)
        for (j = 0; j < 9; j++)
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

// 顯示座位表
void displaySeats() 
{
    int i, j;
    printf("  123456789\n");
    for (i = 8; i >= 0; i--) 
    {
        printf("%d ", i + 1);
        for (j = 0; j < 9; j++)
        {
            if (justArranged && seats[i][j] == '@') {
                printf("@"); // 剛安排時顯示 '@'
            } else {
                printf("%c", seats[i][j]); // 顯示 '-' 或 '*'
            }
        }
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
    int num, i, j, k;
    printf("How many seats do you need (1-4)?：");
    scanf("%d", &num);
    if (num < 1 || num > 4) {
        printf("Invalid number of seats！\n");
        return;
    }
    
    int arranged = 0;
    if (num <= 3) {
        for (i = 0; i < 9 && !arranged; i++) {
            for (j = 0; j <= 9 - num; j++) {
                int free = 1;
                for (k = 0; k < num; k++)
                    if (seats[i][j + k] != '-') free = 0;
                if (free) {
                    for (k = 0; k < num; k++)
                        seats[i][j + k] = '@'; // 臨時標記為 '@'
                    arranged = 1;
                    break;
                }
            }
        }
    } else { // num == 4
        // 先嘗試同一行
        for (i = 0; i < 9 && !arranged; i++) {
            for (j = 0; j <= 5; j++) {
                if (seats[i][j] == '-' && seats[i][j + 1] == '-' && 
                    seats[i][j + 2] == '-' && seats[i][j + 3] == '-') {
                    seats[i][j] = seats[i][j + 1] = seats[i][j + 2] = seats[i][j + 3] = '@';
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
                        seats[i][j] = seats[i][j + 1] = seats[i + 1][j] = seats[i + 1][j + 1] = '@';
                        arranged = 1;
                        break;
                    }
                }
            }
        }
    }
    
    if (arranged) {
        justArranged = 1; // 設置標誌，表示剛安排
        displaySeats();
        char choice;
        printf("Satisfy with this arrangement? (y/n)：");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            // 將 '@' 轉為 '*'，紀錄為已預定
            for (i = 0; i < 9; i++)
                for (j = 0; j < 9; j++)
                    if (seats[i][j] == '@') seats[i][j] = '*';
        } else {
            // 將 '@' 恢復為 '-'
            for (i = 0; i < 9; i++)
                for (j = 0; j < 9; j++)
                    if (seats[i][j] == '@') seats[i][j] = '-';
        }
        justArranged = 0; // 重置標誌，確保下次顯示使用 '*'
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
        seats[row][col] = '@'; // 臨時標記為 '@'
        justArranged = 1; // 設置標誌，表示剛安排
        displaySeats();
        // 立即將 '@' 轉為 '*'，紀錄為已預定
        seats[row][col] = '*';
        justArranged = 0; // 重置標誌，確保下次顯示使用 '*'
    } else {
        printf("The seat has been reserved！\n");
    }
}

int main() 
{
    // 密碼驗證，限制三次
    int password, attempts;
    attempts = 0;
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
                printf("Over 3 attempts! System END.\n");
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
                if (choice == 'n' || choice == 'N') return 0;
                break;
            default:
                printf("Invalid Choice！\n");
        }
        printf("Press Enter to Continue...");
        getchar(); getchar(); // 等待使用者輸入
    } while (1);

    return 0;
}
//在這次的程式設計作業中，我設計並實作了一個簡單的 9×9 座位預約系統。整體開發過程不只是練習 C 語言語法，
//更讓我學習到如何將實際需求拆解成程式邏輯，以及如何用清楚的畫面與流程設計提升使用者體驗。
//雖然這個系統的功能不算複雜，但我花了不少時間在細節處理上，尤其是：
//1.處理系統安排與手動選位時的標記與轉換
//2.顯示時如何讓畫面對齊清楚
//3.使用者每一步都要有適當提示與保護
//4.這讓我體會到，一個簡單的功能背後，往往有很多邏輯與錯誤處理的考量。
//我也學到的幾件事：
//1.陣列應用更熟練
//利用二維陣列來模擬座位圖，是這次的核心。我學會了如何操作二維陣列，包含初始化、讀寫元素、透過座標定位特定位置等等，這對未來寫棋盤、地圖、遊戲等應用都有幫助。
//2.邏輯拆解與模組化設計
//把每一個功能（像是顯示座位、系統安排、使用者選位）拆成一個個獨立的函式，大大提升了程式的可讀性與維護性。主流程就像一個控制中心，呼叫不同功能。
//3.流程控制與防呆設計
//我加入了密碼限制登入、錯誤輸入處理（像座標格式錯誤、超出範圍等），讓整個程式不會因為使用者操作錯誤而當掉，也更貼近「真實系統」該有的設計。
//4.排版與視覺風格
//我特別設計了風格化的開場畫面，除了讓程式更有個人特色，也能讓評閱的老師眼睛一亮。這也提醒我，程式除了功能正確，使用者介面與操作體驗也很重要。
//5.如何與使用者互動
//不管是選單設計、安排確認（y/n）、還是自選座位後的即時回饋，都是為了讓使用者在使用時更直覺。這也幫助我理解「程式不只是寫給電腦看，也是給人用的」。

