#include "Function_2048.h"
#define filename "Alternative2.txt"
int main(void)
{
    //������������
    int all_step_num;      //�ܲ���
    char all_step[100000]; //��Ų���������
    double b_score;        //��������
    double o_score;        //��������
    long int m_score;      //��Ͻ����ܺ�
    int c_score;           //���������ܺ�
    double one_m_score;    //һ�ζ�Ͻ���
    int one_m_count;       //һ�ζ�ϵ���Ŀ
    int continue_step;     //������
    int one_c_score;       //���������Ľ���
    int max_c_num;         //���������
    int max_c_score;       //�����������
    int max_m_count;       //�������
    double max_m_score;    //����Ͻ���

    //���ļ��ж�ȡ���г��Ⱥ������ַ���
    setlocale(LC_ALL, ""); //���ػ�����
    FILE *fp_alternative;  // alternative�ļ���Ӧ��ָ��
    FILE *fp_score;        // score�ļ���Ӧ��ָ��
    FILE *fp_operate;      // operate�ļ���Ӧ��ָ��
    int len;
    wchar_t replace[50][100]; //����滻�ַ����е�����

    //д��һ���ļ�
    if ((fp_alternative = fopen(filename, "r")) == NULL)
    {
        puts("Alternative�ļ���ʧ��");
        system("Pause");
    }
    else
    {
        fscanf(fp_alternative, "%d", &len);
        for (int i = 0; i < len; i++)
        {
            fwscanf(fp_alternative, L"%s", replace[i]);
        }
        if (fclose(fp_alternative) != 0)
        {
            printf("Alternative�ļ��ر�ʧ��");
            system("Pause");
        }
    }
    //�ļ�д�����

    char order; //��ű��β����ı���
    int judge;  //����ж���Ϸ�ɹ����ı���
    while (1)
    {
    main_interface:;
        system("CLS");
        print_main_interface(); //�������ӡ����
        order = getch();
        if (order == 'q') //�˳�����
        {
            break;
        }
        else if (order == 's')
        {
            //��ʼ��Ϸ
        game_interface:;
            system("CLS");
            printf("��������������������ֱ�Ӱ�m������ΪĬ�ϳ��ȡ�\n");

            //�������е�����
            int m, n;
            int d;
            d = scanf("%d", &m);
            if (d == 1)
                scanf("%d", &n);
            else
            {
                m = 4;
                n = 4;
            }

            //��ʼ������
            int a[m][n];
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    a[i][j] = 0;
                }
            }

            //����������ʼ��
            all_step_num = 0;
            b_score = 0.0;
            o_score = 0.0;
            m_score = 0;
            c_score = 0;
            one_m_score = 0.0;
            one_m_count = 0;
            continue_step = 0;
            one_c_score = 0;
            max_c_num = 0;
            max_c_score = 0;
            max_m_count = 0;
            max_m_score = 0.0;

            //������ʼ����
            generate_2_4_two(m, n, a);
            system("CLS");
            print_board(m, n, a, replace);
            printf("����������:       %d\n", continue_step);
            printf("��ǰ������������:  %d\n", one_c_score);
            printf("�ϲ�����:         %d\n", one_m_count);
            printf("���ζ�Ͻ�������:  %.0lf\n", one_m_score);

            while (1)
            {
                order = getch();
                if (order == 'q') //�������������
                {
                    printf("�Ƿ�Ҫ���������棿(Y/N)\n");
                    order = getch();
                    if (order == 'y')
                    {
                        goto main_interface;
                    }
                    else
                    {
                        continue;
                    }
                }
                else if (order == 'r') //���¿�ʼ��Ϸ����
                {
                    printf("�Ƿ�Ҫ���¿�ʼ��Ϸ����Y/N��\n");
                    order = getch();
                    if (order == 'y')
                    {
                        goto game_interface;
                    }
                    else
                    {
                        continue;
                    }
                }

                //��Ϸ���Ĳ���
                else if (order == 'a' || order == 'd' || order == 'w' || order == 's')
                {
                    //�����ж���Ϸ�Ƿ�ʤ��
                    judge = judge_win(m, n, a, len);
                    if (judge == 1)
                    {
                        //�ն���ʾ
                        system("CLS");
                        generate_2_4_one(m, n, a);
                        print_board(m, n, a, replace);
                        printf("����������:       %d\n", continue_step);
                        printf("��ǰ������������:  %d\n", one_c_score);
                        printf("�ϲ�����:         %d\n", one_m_count);
                        printf("���ζ�Ͻ�������:  %.0lf\n", fabs(one_m_score));
                        printf("��ϲ�㣬�ɹ����أ�\n");
                        system("Pause");
                        system("CLS");
                        basic_score(m, n, len, &b_score);
                        operate_score(&all_step_num, &o_score);
                        printf("��������:         %.0lf\n", b_score - o_score);
                        printf("�������������ܺ�:  %d\n", c_score);
                        printf("��Ͻ��������ܺ�:  %ld\n", m_score);
                        printf("��Ϸ�ܵ÷�:       %.0lf\n", b_score - o_score + c_score + m_score);

                        // д��score�ļ�
                        if ((fp_score = fopen("score.txt", "a")) == NULL)
                        {
                            puts("score.txt�ļ���ʧ��");
                            system("Pause");
                        }
                        else
                        {
                            fprintf(fp_score, "��������:       %.0lf\n", b_score - o_score);
                            fprintf(fp_score, "���������ܺ�:   %d\n", c_score);
                            fprintf(fp_score, "��Ͻ����ܺ�:   %ld\n", m_score);
                            fprintf(fp_score, "��Ϸ�ܵ÷�:     %.0lf\n", b_score - o_score + c_score + m_score);
                            fprintf(fp_score, "���������:     %d\n", max_c_num);
                            fprintf(fp_score, "��������÷�:   %d\n", max_c_score);
                            fprintf(fp_score, "��߶����:     %d\n", max_m_count);
                            fprintf(fp_score, "��߶�ϵ÷�:   %.0lf\n", max_m_score);
                            if (fclose(fp_score) != 0)
                            {
                                printf("score.txt�ļ��ر�ʧ��");
                                system("Pause");
                            }
                        }

                        // д��operate�ļ�
                        if ((fp_operate = fopen("operate.txt", "a")) == NULL)
                        {
                            puts("operate.txt�ļ���ʧ��");
                            system("Pause");
                        }
                        else
                        {
                            fprintf(fp_operate, "������:     %d\n", all_step_num);
                            fprintf(fp_operate, "�������Ϊ: %s\n", all_step);
                            if (fclose(fp_operate) != 0)
                            {
                                printf("operate.txt�ļ��ر�ʧ��");
                                system("Pause");
                            }
                        }
                        system("Pause");
                        goto main_interface;
                    }

                    //Ȼ���ж���Ϸ�Ƿ�ʧ��
                    judge = judge_lose(m, n, a);
                    if (judge < 0)
                    {
                        //�ն���ʾ
                        system("CLS");
                        generate_2_4_one(m, n, a);
                        print_board(m, n, a, replace);
                        printf("���ź�����սʧ�ܡ�\n");
                        system("Pause");
                        system("CLS");
                        printf("��������:         %.0lf\n", b_score);
                        printf("�������������ܺ�:  %d\n", c_score);
                        printf("��Ͻ��������ܺ�:  %ld\n", m_score);
                        printf("��Ϸ�ܵ÷�:       %ld\n", (long)(c_score + m_score));

                        // д��score�ļ�
                        if ((fp_score = fopen("score.txt", "a")) == NULL)
                        {
                            puts("score.txt�ļ���ʧ��");
                            system("Pause");
                        }
                        else
                        {
                            fprintf(fp_score, "��������:       %.0lf\n", b_score - o_score);
                            fprintf(fp_score, "���������ܺ�:   %d\n", c_score);
                            fprintf(fp_score, "��Ͻ����ܺ�:   %ld\n", m_score);
                            fprintf(fp_score, "��Ϸ�ܵ÷�:     %.0lf\n", b_score - o_score + c_score + m_score);
                            fprintf(fp_score, "���������:     %d\n", max_c_num);
                            fprintf(fp_score, "��������÷�:   %d\n", max_c_score);
                            fprintf(fp_score, "��߶����:     %d\n", max_m_count);
                            fprintf(fp_score, "��߶�ϵ÷�:   %.0lf\n", max_m_score);
                            if (fclose(fp_score) != 0)
                            {
                                printf("score.txt�ļ��ر�ʧ��");
                                system("Pause");
                            }
                        }

                        // д��operate�ļ�
                        if ((fp_operate = fopen("operate.txt", "a")) == NULL)
                        {
                            puts("operate.txt�ļ���ʧ��");
                            system("Pause");
                        }
                        else
                        {
                            fprintf(fp_operate, "������:     %d\n", all_step_num);
                            fprintf(fp_operate, "�������Ϊ: %s\n", all_step);
                            if (fclose(fp_operate) != 0)
                            {
                                printf("operate.txt�ļ��ر�ʧ��");
                                system("Pause");
                            }
                        }
                        //�ļ��������
                        system("Pause");
                        goto main_interface;
                    }

                    //�������Ƕ�����Ĳ����ͷ����ļ���

                    //���������ݺϲ�
                    gather(m, n, a, order);
                    //�����Ͻ���
                    multiple_score(m, n, a, &m_score, &one_m_score, &one_m_count, order);
                    //������������
                    continue_score(m, n, a, order, &c_score, &continue_step, &one_c_score);
                    //��move��ɶ�����Ĳ���
                    move(m, n, a, order);
                    //��¼�������;������
                    all_step_num++;
                    all_step[all_step_num - 1] = order;
                    //��¼���ĸ��ַ���
                    if (max_c_num < continue_step)
                    {
                        max_c_num = continue_step;
                    }
                    if (max_c_score < one_c_score)
                    {
                        max_c_score = one_c_score;
                    }
                    if (max_m_count < one_m_count)
                    {
                        max_m_count = one_m_count;
                    }
                    if (max_m_score < one_m_score)
                    {
                        max_m_score = one_m_score;
                    }
                    //��ӡ���̲�׼����һ�β���
                    system("CLS");
                    generate_2_4_one(m, n, a);
                    print_board(m, n, a, replace);
                    printf("����������:       %d\n", continue_step);
                    printf("��ǰ������������:  %d\n", one_c_score);
                    printf("�ϲ�����:         %d\n", one_m_count);
                    printf("���ζ�Ͻ�������:  %.0lf\n", fabs((double)one_m_score));
                }

                //�Զ�ִ�г���
                else if (order == 'g')
                {
                    printf("������Ҫ�Զ����ִ�еĲ���\n");
                    int step;
                    scanf("%d", &step);
                    automatic(step, m, n, a, len, &b_score, &all_step_num, &o_score, &m_score, &one_m_score, &one_m_count, &c_score, &continue_step, &one_c_score, replace, all_step, &max_c_num, &max_c_score, &max_m_count, &max_m_score, fp_score, fp_operate);
                    printf("ִ�н�����\n");
                    goto main_interface;
                }
                else
                {
                    continue;
                }
            }
        }
        //��������
        else if (order == 'h')
        {
            system("CLS");
            print_help_interface(); //��ӡ�������溯��
            while (1)
            {
                order = getch();
                if (order == 'b') //'b'Ϊbackѡ��
                {
                    goto main_interface;
                }
            }
        }
        else
        {
            continue;
        }
    }
    return 0;
}