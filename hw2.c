#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main(void)
{
    int i,j, password;
    char select;
    char ch;
    int n;
    char confirm;

    printf("+----------+---------+---------+----------+----------+\n");
    printf("| �X�ͤ�� |  �� �O  |  �~ ��  | �NŪ�Ǯ� |   �m �W  |\n");
    printf("+----------+---------+---------+----------+----------+\n");
    printf("| 92.12.13 |  �k ��  |  21 ��  | �j�P�j�� |  ���a�M  |\n");
    printf("+----------+---------+---------+----------+----------+\n\n");
    printf(" \n");
	printf("\n�Z��:\n");
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
	
    for (i = 0; i < 3; i++) 
    {
        printf("�п�J�|��ƱK�X�G");
        scanf("%d", &password);

        if (password == 2025) 
        {
            printf("�K�X���T�I�i�J�U�@�B�C\n");
            system("pause");
            system("cls");
            break;
        } 
        else 
        {
            printf("�K�X���~�I\n");
        }

        if (i == 2) 
        {
            printf("���~�T���A�{�������I\n");
            system("pause");
            return 0;
        }
    }

    do
    {
        printf("--------------------------\n");
        printf("| a. �e�X�����T����       |\n");
        printf("| b. ��ܭ��k��           |\n");
        printf("| c. ����                 |\n");
        printf("--------------------------\n");
        printf("�п�ܥ\��G");
        scanf(" %c", &select);

        if(select == 'a' || select == 'A')
        {
            system("cls");
            while(1)
            {
                printf("�п�J�r�� (a~n)�G");
                scanf(" %c", &ch);
                
                if(ch >= 'a' && ch <= 'n')
                {
                    int height = ch - 'a' + 1;
                    for (i = 0; i < height; i++) 
                    {
                        for ( j = 0; j <= i; j++) 
                        {
                            printf("%c", ch - j);
                        }
                        printf("\n");
                    }
                    printf("�����N��^��D���...\n");
                    getch();
                    system("cls");
                    break;
                }
                else
                {
                    printf("��J���~�I�Э��s��J�C\n");
                }
            }
        }
        else if(select == 'b' || select == 'B')
        {
            system("cls");
            while(1)
            {
                printf("�п�J1��9����ơG");
                scanf("%d", &n);

                if(n >= 1 && n <= 9)
                {
                    for( i = 1; i <= n; i++)
                    {
                        for( j = 1; j <= n; j++)
                        {
                            printf("%2d*%2d=%2d ", i, j, i*j);
                        }
                        printf("\n");
                    }
                    printf("�����N��^��D���...\n");
                    getch();
                    system("cls");
                    break;
                }
                else
                {
                    printf("��J���~�I�Э��s��J�C\n");
                }
            }
        }
        else if(select == 'c' || select == 'C')
        {
            printf("Continue? (y/n)�G");
            scanf(" %c", &confirm);

            if(confirm == 'y' || confirm == 'Y')
            {
                system("cls");
                continue;
            }
            else if(confirm == 'n' || confirm == 'N')
            {
                printf("�{�������A�T�T��\n");
                system("pause");
                return 0;
            }
            else
            {
                printf("��J���~�A�Э��s��ܥ\��I\n");
            }
        }
        else
        {
            printf("��J���~�I�Э��s��ܥ\��C\n");
        }
    } while(1);

    return 0;
}

