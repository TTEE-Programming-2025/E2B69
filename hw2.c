#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main(void)
{
    // �ŧi�ܼ�
    int i,j, password;
    char select;
    char ch;
    int n;
    char confirm;
    int keep_running = 1; // ����D�j��O�_�~�����

    // ��ܭӤH��ƪ�
    printf("+----------+---------+---------+----------+----------+\n");
    printf("| �X�ͤ�� |  �� �O  |  �~ ��  | �NŪ�Ǯ� |   �m �W  |\n");
    printf("+----------+---------+---------+----------+----------+\n");
    printf("| 92.12.13 |  �k ��  |  21 ��  | �j�P�j�� |  ���a�M  |\n");
    printf("+----------+---------+---------+----------+----------+\n\n");

    // ��ܯS��r��
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

    // �K�X���ҡ]�̦h�T�����|�^
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

    // �D���\��
    while (keep_running)
    {
        system("cls"); // �M���ù�
        printf("--------------------------\n");
        printf("| a. �e�X�����T����       |\n");
        printf("| b. ��ܭ��k��           |\n");
        printf("| c. ����                 |\n");
        printf("--------------------------\n");
        printf("�п�� a. or b. or c.�G");
        scanf(" %c", &select);

        if (select == 'a' || select == 'A')
        {
            system("cls");
            printf("�п�Ja~n�������r���G");
            scanf(" %c", &ch);

            // �P�_��J�O�_�b a~n ���d��
            if (ch >= 'a' && ch <= 'n')
            {
                // �L�X�˪����T����
                for (i = ch; i >= 'a'; i--)
                {
                    for ( j = ch; j >= i; j--)
                    {
                        printf("%c", j); // �L�r��
                    }
                    printf("\n");
                }
                printf("�����N���^�D���...\n");
                getch();
            }
            else
            {
                printf("��J���~�A�Э��s��J a~n ���r���I\n");
                system("pause");
            }
        }
        else if (select == 'b' || select == 'B')
        {
            system("cls");
            printf("�п�J1~9�������Ʀr�G");
            scanf("%d", &n);

            // �P�_�O�_�b���T�d��
            if (n >= 1 && n <= 9)
            {
                // ��ܭ��k��
                for (i = 1; i <= n; i++)
                {
                    for ( j = 1; j <= n; j++)
                    {
                        printf("%2d*%2d=%2d  ", i, j, i*j);
                    }
                    printf("\n");
                }
                printf("�����N���^�D���...\n");
                getch();
            }
            else
            {
                printf("�Ʀr�W�X�d��A�Э��s��J�I\n");
                system("pause");
            }
        }
        else if (select == 'c' || select == 'C')
        {
            // ���}�{���e�A���T�{
            printf("Continue? (y/n): ");
            scanf(" %c", &confirm);

            if (confirm == 'y' || confirm == 'Y')
            {
                continue; // �~��^��D���
            }
            else if (confirm == 'n' || confirm == 'N')
            {
                printf("�{�������A�T�T�I\n");
                keep_running = 0; // �]��0�A���� while �j��
            }
            else
            {
                printf("��J���~�A�Э��s��ܡI\n");
                system("pause");
            }
        }
        else
        {
            printf("�L�Ŀﶵ�A�Э��s��J�I\n");
            system("pause");
        }
    }

    system("pause");
    return 0;
}

/*
�߱o�G
�o�����@�~�O�ڲĤ@���bGit Bash�W���դW��C�y���@�~�A�@�}�l�J��F�D�`�h���D�A
�Ҧp�Ggit���O�����Bpush���ѡB���|�]�������A���ڪ�F���֮ɶ��N���C
���L�]�]���o�ˡA�ھǷ|�F����l��git�B���commit�Ppush�A��O�N�~��ì�I

�b�g�o��C�y���{�����L�{���A�ڬO���ӨC�@�D���n�D�A�@�B�B�C�C�������C
�@�}�l�O�������n�J�K�X���ҡA���۬O�s�@�D���A��ӺC�C�[�W�e�����T���ΡB
�s�@���k��A�̫�A�B�z�������C
�C�����@�p�q�N���դ@���A���ڤ�����e���X���A���M�t�׺C���ܽ��C

�o���̤j���D�ԬO�u�����T���ΦL�X�r���˵۱ƦC�v�A
�ګ�ҤF�ܤ[�A�̫�Ψ�h�j��+��֦r������k�����Aı�o�ۤv�Z�F�`���I
�t�~���F���ƪ������A�ڤ]���S�O�`�N���k���r�������D�C

����ӻ��A���M�L�{���J��ܦh���D�A���ѨM��u���ܦ����N�P�A
�Ʊ楼�ӯ���g�X�󦳱��z�B�󦳮Ĳv���{���I
�]�����ۤv�A�n�h�d�N�ƪ��P��J���~�B�z���Ӹ`�A�o�ˤ~��i�B�o��֡C
*/

