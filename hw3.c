#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int password,i,j;
	
	for (i = 0; i < 3; i++) 
    {
        printf("�п�J�|��ƱK�X�G");
        scanf("%d", &password);

        if (password == 2025) 
        {
            printf("�K�X���T�I�i�J�D���C\n");
            system("pause");
            system("cls");
            break; // ���T�N���X�K�X����
        }
        else
        {
            printf("�K�X���~�I\n");
        }

        if (i == 2)
        {
            printf("���~�T���A�{�������I\n");
            system("pause");
            return 0; // ���~�W�L���ơA���������{��
        }
    }
}
