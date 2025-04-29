#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main(void)
{
    // 宣告變數
    int i,j, password;
    char select;
    char ch;
    int n;
    char confirm;
    int keep_running = 1; // 控制主迴圈是否繼續執行

    // 顯示個人資料表
    printf("+----------+---------+---------+----------+----------+\n");
    printf("| 出生日期 |  性 別  |  年 齡  | 就讀學校 |   姓 名  |\n");
    printf("+----------+---------+---------+----------+----------+\n");
    printf("| 92.12.13 |  男 性  |  21 歲  | 大同大學 |  曾冠霖  |\n");
    printf("+----------+---------+---------+----------+----------+\n\n");

    // 顯示特殊字圖
    printf(" \n");
	printf("\n班號:\n");
	printf(" \n");
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

    // 密碼驗證（最多三次機會）
    for (i = 0; i < 3; i++) 
    {
        printf("請輸入四位數密碼：");
        scanf("%d", &password);

        if (password == 2025) 
        {
            printf("密碼正確！進入主選單。\n");
            system("pause");
            system("cls");
            break; // 正確就跳出密碼驗證
        }
        else
        {
            printf("密碼錯誤！\n");
        }

        if (i == 2)
        {
            printf("錯誤三次，程式結束！\n");
            system("pause");
            return 0; // 錯誤超過次數，直接結束程式
        }
    }

    // 主選單功能
    while (keep_running)
    {
        system("cls"); // 清除螢幕
        printf("--------------------------\n");
        printf("| a. 畫出直角三角形       |\n");
        printf("| b. 顯示乘法表           |\n");
        printf("| c. 結束                 |\n");
        printf("--------------------------\n");
        printf("請選擇 a. or b. or c.：");
        scanf(" %c", &select);

        if (select == 'a' || select == 'A')
        {
            system("cls");
            printf("請輸入a~n之間的字元：");
            scanf(" %c", &ch);

            // 判斷輸入是否在 a~n 的範圍內
            if (ch >= 'a' && ch <= 'n')
            {
                // 印出倒直角三角形
                for (i = ch; i >= 'a'; i--)
                {
                    for ( j = ch; j >= i; j--)
                    {
                        printf("%c", j); // 印字元
                    }
                    printf("\n");
                }
                printf("按任意鍵返回主選單...\n");
                getch();
            }
            else
            {
                printf("輸入錯誤，請重新輸入 a~n 的字元！\n");
                system("pause");
            }
        }
        else if (select == 'b' || select == 'B')
        {
            system("cls");
            printf("請輸入1~9之間的數字：");
            scanf("%d", &n);

            // 判斷是否在正確範圍
            if (n >= 1 && n <= 9)
            {
                // 顯示乘法表
                for (i = 1; i <= n; i++)
                {
                    for ( j = 1; j <= n; j++)
                    {
                        printf("%2d*%2d=%2d  ", i, j, i*j);
                    }
                    printf("\n");
                }
                printf("按任意鍵返回主選單...\n");
                getch();
            }
            else
            {
                printf("數字超出範圍，請重新輸入！\n");
                system("pause");
            }
        }
        else if (select == 'c' || select == 'C')
        {
            // 離開程式前再次確認
            printf("Continue? (y/n): ");
            scanf(" %c", &confirm);

            if (confirm == 'y' || confirm == 'Y')
            {
                continue; // 繼續回到主選單
            }
            else if (confirm == 'n' || confirm == 'N')
            {
                printf("程式結束，掰掰！\n");
                keep_running = 0; // 設為0，結束 while 迴圈
            }
            else
            {
                printf("輸入錯誤，請重新選擇！\n");
                system("pause");
            }
        }
        else
        {
            printf("無效選項，請重新輸入！\n");
            system("pause");
        }
    }

    system("pause");
    return 0;
}

/*
心得：
這次的作業是我第一次在Git Bash上嘗試上傳C語言作業，一開始遇到了非常多問題，
例如：git指令不熟、push失敗、路徑設錯等等，讓我花了不少時間摸索。
不過也因為這樣，我學會了怎麼初始化git、怎麼commit與push，算是意外收穫！

在寫這個C語言程式的過程中，我是按照每一題的要求，一步步慢慢完成的。
一開始是先完成登入密碼驗證，接著是製作主選單，後來慢慢加上畫直角三角形、
製作乘法表，最後再處理結束選單。
每完成一小段就測試一次，讓我比較不容易出錯，雖然速度慢但很踏實。

這次最大的挑戰是「直角三角形印出字母倒著排列」，
我思考了很久，最後用兩層迴圈+減少字母的方法完成，覺得自己蠻厲害的！
另外為了讓排版更整齊，我也有特別注意乘法表的字串對齊問題。

整體來說，雖然過程中遇到很多問題，但解決後真的很有成就感，
希望未來能夠寫出更有條理、更有效率的程式！
也提醒自己，要多留意排版與輸入錯誤處理的細節，這樣才能進步得更快。
*/

