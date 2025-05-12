#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ��l�� 9x9 �y���A'-' ��ܪŦ�A'*' ��ܤw�Q�w�w�A'@' ����{�ɦw��
char seats[9][9];
int justArranged = 0; // �лx�G�O�_�觹���y��w��

// ��ܭӤH���檺�e��
void displayWelcome() 
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
    puts("aaaaaaaaaaa   aa aaa aaa aaa aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa   aa aaaa aaa aaaaaaaaaaaaaaa aaaa aaaaaaaaaaaaaaaaaaaaaaa   aaaaaaa");
    puts("aaaaaaaaaaaa aa   a   a   a   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa aa   aa   aaaaaaaaaaaaaaaaaaaaaa   aaaaaaaaaaaaaaaaaaaaaaa aaaaaaaa");
    puts("aaaaaaaaaaaaaaaa aaa aaa aaa aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa aaaa aaaaaaaaaaaaaaaaaaaaaaaa aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
    printf(" \n");
    printf("Please enter the password�G");
}

// ��l�Ʈy�����H���ͦ�10�Ӥw�w�w�y��
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

// ��ܮy���
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
                printf("@"); // ��w�Ʈ���� '@'
            } else {
                printf("%c", seats[i][j]); // ��� '-' �� '*'
            }
        }
        printf("\n");
    }
}

// �D���
void displayMenu() 
{
    system("cls"); 
    printf("*--------[Booking System]--------*\n");
    printf("| a. Available seats             |\n");
    printf("| b. Arrange for you             |\n");
    printf("| c. Choose by your self         |\n");
    printf("| d. EXIT                        |\n");
    printf("*--------------------------------*\n");
    printf("Please enter your choice�G");
}

// �t�Φw�Ʈy��
void arrangeSeats() 
{
    int num, i, j, k;
    printf("How many seats do you need (1-4)?�G");
    scanf("%d", &num);
    if (num < 1 || num > 4) {
        printf("Invalid number of seats�I\n");
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
                        seats[i][j + k] = '@'; // �{�ɼаO�� '@'
                    arranged = 1;
                    break;
                }
            }
        }
    } else { // num == 4
        // �����զP�@��
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
        // ���լ۾F���
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
        justArranged = 1; // �]�m�лx�A��ܭ�w��
        displaySeats();
        char choice;
        printf("Satisfy with this arrangement? (y/n)�G");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            // �N '@' �ର '*'�A�������w�w�w
            for (i = 0; i < 9; i++)
                for (j = 0; j < 9; j++)
                    if (seats[i][j] == '@') seats[i][j] = '*';
        } else {
            // �N '@' ��_�� '-'
            for (i = 0; i < 9; i++)
                for (j = 0; j < 9; j++)
                    if (seats[i][j] == '@') seats[i][j] = '-';
        }
        justArranged = 0; // ���m�лx�A�T�O�U����ܨϥ� '*'
    } else {
        printf("Unable to arrange consecutive seats�I\n");
    }
}

// �ϥΪ̿�ܮy��
void chooseSeats() 
{
    int row, col;
    printf("Please enter the seat number (ex: 1-2)�G");
    if (scanf("%d-%d", &row, &col) != 2 || row < 1 || row > 9 || col < 1 || col > 9) {
        printf("Invalid input�I\n");
        return;
    }
    row--; col--; // �ഫ���}�C����
    if (seats[row][col] == '-') {
        seats[row][col] = '@'; // �{�ɼаO�� '@'
        justArranged = 1; // �]�m�лx�A��ܭ�w��
        displaySeats();
        // �ߧY�N '@' �ର '*'�A�������w�w�w
        seats[row][col] = '*';
        justArranged = 0; // ���m�лx�A�T�O�U����ܨϥ� '*'
    } else {
        printf("The seat has been reserved�I\n");
    }
}

int main() 
{
    // �K�X���ҡA����T��
    int password, attempts;
    attempts = 0;
    displayWelcome();
    while (attempts < 3) {
        scanf("%d", &password);
        if (password == 2025) {
            printf("Password confirm�IWelcome�I\n");
            break;
        } else {
            attempts++;
            if (attempts < 3) {
                printf("Error�IPlease check your password and try again (%d attempts left)�G", 3 - attempts);
            } else {
                printf("Over 3 attempts! System END.\n");
                return 1;
            }
        }
    }

    // ��l�Ʈy���
    initSeats();

    // �D�`��
    char choice;
    do {
        displayMenu();
        scanf(" %c", &choice);
        switch (choice) {
            case 'a': // ��ܥi�ήy��
                displaySeats();
                break;
            case 'b': // �t�Φw�Ʈy��
                arrangeSeats();
                break;
            case 'c': // �ϥΪ̿�ܮy��
                chooseSeats();
                break;
            case 'd': // �h�X�ﶵ
                printf("Continue? (y/n)�G");
                scanf(" %c", &choice);
                if (choice == 'n' || choice == 'N') return 0;
                break;
            default:
                printf("Invalid Choice�I\n");
        }
        printf("Press Enter to Continue...");
        getchar(); getchar(); // ���ݨϥΪ̿�J
    } while (1);

    return 0;
}
//�b�o�����{���]�p�@�~���A�ڳ]�p�ù�@�F�@��²�檺 9��9 �y��w���t�ΡC����}�o�L�{���u�O�m�� C �y���y�k�A
//�����ھǲߨ�p��N��ڻݨD��Ѧ��{���޿�A�H�Φp��βM�����e���P�y�{�]�p���ɨϥΪ�����C
//���M�o�Өt�Ϊ��\�ण������A���ڪ�F���֮ɶ��b�Ӹ`�B�z�W�A�ר�O�G
//1.�B�z�t�Φw�ƻP��ʿ��ɪ��аO�P�ഫ
//2.��ܮɦp�����e������M��
//3.�ϥΪ̨C�@�B���n���A���ܻP�O�@
//4.�o������|��A�@��²�檺�\��I��A�������ܦh�޿�P���~�B�z���Ҷq�C
//�ڤ]�Ǩ쪺�X��ơG
//1.�}�C���Χ���m
//�Q�ΤG���}�C�Ӽ����y��ϡA�O�o�����֤ߡC�ھǷ|�F�p��ާ@�G���}�C�A�]�t��l�ơBŪ�g�����B�z�L�y�Щw��S�w��m�����A�o�良�Ӽg�ѽL�B�a�ϡB�C�������γ������U�C
//2.�޿��ѻP�ҲդƳ]�p
//��C�@�ӥ\��]���O��ܮy��B�t�Φw�ơB�ϥΪ̿��^��@�ӭӿW�ߪ��禡�A�j�j���ɤF�{�����iŪ�ʻP���@�ʡC�D�y�{�N���@�ӱ���ߡA�I�s���P�\��C
//3.�y�{����P���b�]�p
//�ڥ[�J�F�K�X����n�J�B���~��J�B�z�]���y�Ю榡���~�B�W�X�d�򵥡^�A����ӵ{�����|�]���ϥΪ̾ާ@���~�ӷ��A�]��K��u�u��t�Ρv�Ӧ����]�p�C
//4.�ƪ��P��ı����
//�گS�O�]�p�F����ƪ��}���e���A���F���{���󦳭ӤH�S��A�]�������\���Ѯv�����@�G�C�o�]�����ڡA�{�����F�\�ॿ�T�A�ϥΪ̤����P�ާ@����]�ܭ��n�C
//5.�p��P�ϥΪ̤���
//���ެO���]�p�B�w�ƽT�{�]y/n�^�B�٬O�ۿ�y��᪺�Y�ɦ^�X�A���O���F���ϥΪ̦b�ϥήɧ�ı�C�o�]���U�ڲz�ѡu�{�����u�O�g���q���ݡA�]�O���H�Ϊ��v�C

