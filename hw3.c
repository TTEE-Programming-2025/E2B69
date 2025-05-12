#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int password,i,j;
	
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
}
