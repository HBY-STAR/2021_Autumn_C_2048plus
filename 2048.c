#include "Function_2048.h"

int main()
{
welcome:;//goto�����������˻�ӭ����
    int input; 
    system("CLS");//��ӡ��ӭ����
    print_main_interface();
    while (1)
    {                    //�ó���һֱ���У�ֱ������q
        input = getch(); //���벢�ó����ȡ�������ڼ�������ʾ���Ҳ��ð��س�
        while (input != 'q')
        {
            switch (input) //ʶ��������ַ�����·ִ��
            {
            case 's':
            start:;
            { //��ʼ��Ϸ
                int a[4][4] =
                    {
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}};
                
                system("CLS");//����
                //��ӡ���
                printf("-----------------------------------------------------------------\n");
                for (int i = 0; i <= 3; i++)
                {
                    for (int j = 0; j <= 3; j++)
                    {
                        printf("|\t%d\t", a[i][j]);
                    }
                    printf("|\n");
                    printf("-----------------------------------------------------------------\n");
                }
                //��Ҫ��Ϸ�߼�
                //�ڲ�while
                while (1)//����Ϸ����һֱ���У�ֱ������q�˳��˴���Ϸ
                {
                game:;//goto��������������Ϸ����
                    int input1;
                    input1 = getch();
                    while (input1 != 'q')
                    {
                        switch (input1)//���������ѡ��
                        {
                        case 'r'://���¿�ʼ��Ϸ
                        {
                            printf("�Ƿ�Ҫ���¿�ʼ��Ϸ����Y/N��");
                            int restart;
                            restart=getch();
                            switch(restart)
                            {
                                case 'y':goto start;break;
                                case 'n':goto game;break;
                            }
                        }
                        //����
                        case 'a':
                        {
                            for (int x1 = 0; x1 <= 3; x1++) //����ʹ��������
                            {
                                int i = 0;
                                for (int x2 = 0; x2 <= 3; x2++)
                                {
                                    if (a[x1][x2] > 0)
                                    {
                                        if (i != x2)
                                        {
                                            a[x1][i] = a[x1][x2];
                                            i++;
                                            a[x1][x2] = 0;
                                        }
                                        else
                                        {
                                            i++;
                                        }
                                    }
                                }
                            }                               //�����ж�����
                            for (int x3 = 0; x3 <= 3; x3++) //�ϲ�������
                            {
                                if (a[x3][0] == a[x3][1] && a[x3][2] != a[x3][3])
                                {
                                    a[x3][0] = a[x3][0] * 2;
                                    a[x3][1] = a[x3][2];
                                    a[x3][2] = a[x3][3];
                                    a[x3][3] = 0;
                                }
                                else if (a[x3][0] == a[x3][1] && a[x3][2] == a[x3][3])
                                {
                                    a[x3][0] = a[x3][0] * 2;
                                    a[x3][1] = a[x3][2] * 2;
                                    a[x3][2] = 0;
                                    a[x3][3] = 0;
                                }
                                else if (a[x3][0] != a[x3][1] && a[x3][1] == a[x3][2])
                                {
                                    a[x3][1] = a[x3][1] * 2;
                                    a[x3][2] = a[x3][3];
                                    a[x3][3] = 0;
                                }
                                else if (a[x3][0] != a[x3][1] && a[x3][2] == a[x3][3])
                                {
                                    a[x3][2] = a[x3][2] * 2;
                                    a[x3][3] = 0;
                                }
                            }
                        }
                        break; //���Ƶ��˽���
                               //����
                        case 'd':
                        {
                            for (int x1 = 1; x1 <= 3; x1++) //����ʹ��������
                            {
                                int i = 3;
                                for (int x2 = 3; x2 >= 0; x2--)
                                {
                                    if (a[x1][x2] > 0)
                                    {
                                        if (i != x2)
                                        {
                                            a[x1][i] = a[x1][x2];
                                            i--;
                                            a[x1][x2] = 0;
                                        }
                                        else
                                        {
                                            i--;
                                        }
                                    }
                                }
                            }                               //�����ж�����
                            for (int x3 = 0; x3 <= 3; x3++) //�ϲ�������
                            {
                                if (a[x3][3] == a[x3][2] && a[x3][1] != a[x3][0])
                                {
                                    a[x3][3] = a[x3][3] * 2;
                                    a[x3][2] = a[x3][1];
                                    a[x3][1] = a[x3][0];
                                    a[x3][0] = 0;
                                }
                                else if (a[x3][3] == a[x3][2] && a[x3][1] == a[x3][0])
                                {
                                    a[x3][3] = a[x3][3] * 2;
                                    a[x3][2] = a[x3][1] * 2;
                                    a[x3][1] = 0;
                                    a[x3][0] = 0;
                                }
                                else if (a[x3][3] != a[x3][2] && a[x3][2] == a[x3][1])
                                {
                                    a[x3][2] = a[x3][2] * 2;
                                    a[x3][1] = a[x3][0];
                                    a[x3][0] = 0;
                                }
                                else if (a[x3][3] != a[x3][2] && a[x3][1] == a[x3][0])
                                {
                                    a[x3][1] = a[x3][1] * 2;
                                    a[x3][0] = 0;
                                }
                            }
                        }
                        break; //���Ƶ��˽���
                        //����
                        case 'w':
                        {
                            for (int x1 = 0; x1 <= 3; x1++) //������ʹ��������
                            {
                                int i = 0;
                                for (int x2 = 0; x2 <= 3; x2++)
                                {
                                    if (a[x2][x1] > 0)
                                    {
                                        if (i != x2)
                                        {
                                            a[i][x1] = a[x2][x1];
                                            i++;
                                            a[x2][x1] = 0;
                                        }
                                        else
                                        {
                                            i++;
                                        }
                                    }
                                }

                            }                               //�����ж�����
                            for (int x3 = 0; x3 <= 3; x3++) //�ϲ�������
                            {
                                if (a[0][x3] == a[1][x3] && a[2][x3] != a[3][x3])
                                {
                                    a[0][x3] = a[0][x3] * 2;
                                    a[1][x3] = a[2][x3];
                                    a[2][x3] = a[3][x3];
                                    a[3][x3] = 0;
                                }
                                else if (a[0][x3] == a[1][x3] && a[2][x3] == a[3][x3])
                                {
                                    a[0][x3] = a[0][x3] * 2;
                                    a[1][x3] = a[2][x3] * 2;
                                    a[2][x3] = 0;
                                    a[3][x3] = 0;
                                }
                                else if (a[0][x3] != a[1][x3] && a[1][x3] == a[2][x3])
                                {
                                    a[1][x3] = a[1][x3] * 2;
                                    a[2][x3] = a[3][x3];
                                    a[3][x3] = 0;
                                }
                                else if (a[0][x3] != a[1][x3] && a[2][x3] == a[3][x3])
                                {
                                    a[2][x3] = a[2][x3] * 2;
                                    a[3][x3] = 0;
                                }
                            }
                        }
                        break; //���Ƶ��˽���
                        //����
                        case 's':
                        {
                            for (int x1 = 0; x1 <= 3; x1++) //����ʹ��������
                            {
                                int i = 3;
                                for (int x2 = 3; x2 >= 0; x2--)
                                {
                                    if (a[x2][x1] > 0)
                                    {
                                        if (i != x2)
                                        {
                                            a[i][x1] = a[x2][x1];
                                            i--;
                                            a[x2][x1] = 0;
                                        }
                                        else
                                        {
                                            i--;
                                        }
                                    }
                                }

                            }                               //�����ж�����
                            for (int x3 = 0; x3 <= 3; x3++) //�ϲ�������
                            {
                                if (a[3][x3] == a[2][x3] && a[1][x3] != a[0][x3])
                                {
                                    a[3][x3] = a[3][x3] * 2;
                                    a[2][x3] = a[1][x3];
                                    a[1][x3] = a[0][x3];
                                    a[0][x3] = 0;
                                }
                                else if (a[3][x3] == a[2][x3] && a[1][x3] == a[0][x3])
                                {
                                    a[3][x3] = a[3][x3] * 2;
                                    a[2][x3] = a[1][x3] * 2;
                                    a[1][x3] = 0;
                                    a[0][x3] = 0;
                                }
                                else if (a[3][x3] != a[2][x3] && a[2][x3] == a[1][x3])
                                {
                                    a[2][x3] = a[2][x3] * 2;
                                    a[1][x3] = a[0][x3];
                                    a[0][x3] = 0;
                                }
                                else if (a[3][x3] != a[2][x3] && a[1][x3] == a[0][x3])
                                {
                                    a[1][x3] = a[1][x3] * 2;
                                    a[0][x3] = 0;
                                }
                            }
                        }
                        break; //���Ƶ��˽���
                        default:
                            goto game;//��Ч���������䷵�ر�����Ϸ����
                        }
                        //Ȼ���ж���Ϸ�Ƿ����
                        //�ж���Ϸʤ��
                        for (int i = 0; i <= 3; i++)
                        {
                            for (int j = 0; j <= 3; j++)
                            {
                                if (a[i][j] == 2048)
                                {
                                    printf("��ϲ�㣬�ɹ����أ�");
                                    system("pause");
                                    goto welcome; //�ص���ӭ����
                                }
                            }
                        }
                        //�ж���Ϸʧ��
                        if (a[0][0] != 0 && a[0][1] != 0 && a[0][2] != 0 && a[0][3] != 0 &&
                            a[1][0] != 0 && a[1][1] != 0 && a[1][2] != 0 && a[1][3] != 0 &&
                            a[2][0] != 0 && a[2][1] != 0 && a[2][2] != 0 && a[2][3] != 0 &&
                            a[3][0] != 0 && a[3][1] != 0 && a[3][2] != 0 && a[3][3] != 0)
                        {
                            int loop1, loop2;
                            for (loop1 = 0; loop1 <= 2; loop1++)
                            {
                                for (loop2 = 0; loop2 <= 2; loop2++)
                                {
                                    if (a[loop1][loop2] == a[loop1][loop2 + 1] || a[loop1][loop2] == a[loop1 + 1][loop2] || a[loop1 + 1][loop2] == a[loop1 + 1][loop2 + 1] || a[loop1][loop2 + 1] == a[loop1 + 1][loop2 + 1])
                                    {
                                        goto game;
                                    }
                                    else
                                    {
                                        printf("���ź�����սʧ�ܡ�");
                                        system("pause");
                                        goto welcome; //���ػ�ӭ����
                                    }
                                }
                            }
                        }
                        //����һ�������
                        else
                        {
                            while (1)
                            {
                                int m, n;
                                m = rand() % 4;
                                n = rand() % 4;
                                if (a[m][n] == 0)
                                {
                                    a[m][n] = random_2_4();
                                    break;
                                }
                            }
                        } //��������ɽ���
                          //��ӡ���
                        system("CLS");//����
                        //��ӡ���
                        printf("-----------------------------------------------------------------\n");
                        for (int i = 0; i <= 3; i++)
                        {
                            for (int j = 0; j <= 3; j++)
                            {
                                printf("|\t%d\t", a[i][j]);
                            }
                            printf("|\n");
                            printf("-----------------------------------------------------------------\n");
                        }      
                        break; //���ڲ�while����
                    }
                    if (input1 == 'q')
                    {
                        printf("�Ƿ��˳���Ϸ����Y/N��\n");
                        int tuichu;
                        tuichu = getch();
                        switch (tuichu)
                        {
                        case 'y':
                        {
                            goto welcome;
                        }
                        case 'n':
                        {
                            goto game; //������һ��
                        }
                        }
                        break;
                    }
                }
            }
            break;
            case 'h':
            { //��������
                system("CLS");
                printf("******Help Information******\n");
                printf("\th\t: help info\n");
                printf("\ts\t: start game\n");
                printf("\tw/��\t: merge up\n");
                printf("\ts/��\t: merge down\n");
                printf("\ta/��\t: merge left\n");
                printf("\td/��\t: merge right\n");
                printf("\tq\t: quit\n");
                printf("****************************\n");
            }
            break;
            default:;
            }
            break;
        }
        if (input == 'q')
        {
            printf("�Ƿ��˳���Ϸ����Y/N��\n");
            int tuichu1;
            tuichu1 = getch();
            switch (tuichu1)
            {
            case 'y':
            {
                break;
            }
            case 'n':
            {
                goto welcome; //������һ��
            }
            }
            break;
        }
    }

    return 0;
}
