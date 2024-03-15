#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <locale.h>

//���к����������������໥����
int random_2_4();
void print_main_interface(void);
void generate_2_4_two(int m, int n, int a[m][n]);
void generate_2_4_one(int m, int n, int a[m][n]);
void gather(int m, int n, int a[m][n], char order);
void combine(int m, int n, int a[m][n], char order);
void move(int m, int n, int a[m][n], char order);
int judge_win(int m, int n, int a[m][n], int len); // 1��ʾʤ��
int judge_lose(int m, int n, int a[m][n]);         // 0��ʾ������-1��ʾʧ��
void print_help_interface(void);
void basic_score(int m, int n, int len, double *b_score);
void operate_score(int *all_step_num, double *o_score);
void multiple_score(int m, int n, int a[m][n], long int *m_score, double *one_m_score,
                    int *one_m_count, char order);
void continue_score(int m, int n, int a[m][n], char order, int *c_score, int *continue_step, int *one_c_score);
int fibonacci(int num);
void print_board(int m, int n, int a[m][n], wchar_t replace[50][100]);
void print_single(int num, wchar_t replace[50][100]);
void automatic(int step, int m, int n, int a[m][n], int len, double *b_score, int *all_step_num,
               double *o_score,long int *m_score, double *one_m_score, int *one_m_count, int *c_score, int *continue_step, int *one_c_score, wchar_t replace[50][100], char all_step[100000], int *max_c_num, int *max_c_score, int *max_m_count, double *max_m_score, FILE *fp_score, FILE *fp_operate);

//�������2��4����
//����2�ļ��ʴ󣬲���4�ļ���С
int random_2_4()
{
    srand((unsigned)time(NULL) + clock());
    if (rand() % 6 == 0) //������4�ĸ��ʸ�СһЩ
    {
        return 4;
    }
    else
    {
        return 2;
    }
}

//�������ӡ����
void print_main_interface(void)
{
    printf("###############Welcome to 2048###############\n");
    printf("#    Please choose one command:             #\n");
    printf("#        h: help                            #\n");
    printf("#        s: start                           #\n");
    printf("#        q: quit                            #\n");
    printf("##################Have fun###################\n");
}

//��������2��4�ĺ���
void generate_2_4_two(int m, int n, int a[m][n]) // m��n��
{
    for (int x = 1; x <= 2;) //�������������
    {
        int x1, x2;
        srand((unsigned)time(NULL) + clock());
        x1 = rand() % m;
        x2 = rand() % n;
        if (a[x1][x2] == 0) //��ֹ�������±���ͬ
        {
            a[x1][x2] = random_2_4();
            x++;
        }
    }
}

//����һ��2��4�ĺ���
void generate_2_4_one(int m, int n, int a[m][n])
{
    int count = 0;
    for (int x = 1; x < 2;) //����һ�������
    {
        int x1, x2;
        srand((unsigned)time(NULL) + clock());
        x1 = rand() % m;
        x2 = rand() % n;
        if (a[x1][x2] == 0) //��ֹ�������±���ͬ
        {
            a[x1][x2] = random_2_4();
            x++;
        }
        else
        {
            count++;
            if (count > 100000)
            {
                x++;
            }
        }
    }
}

//���ֿ�£����
//��ÿ��ÿ���ȿ�£��һ��
void gather(int m, int n, int a[m][n], char order)
{
    switch (order)
    {
    case 'a':
        for (int x1 = 0; x1 < m; x1++) //����ʹ��������
        {
            int i = 0;
            for (int x2 = 0; x2 < n; x2++)
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
        }
        break;
    case 'd':
        for (int x1 = 0; x1 < m; x1++) //����ʹ��������
        {
            int i = n - 1;
            for (int x2 = n - 1; x2 >= 0; x2--)
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
        }
        break;
    case 'w':
        for (int x1 = 0; x1 < n; x1++) //����ʹ��������
        {
            int i = 0;
            for (int x2 = 0; x2 < m; x2++)
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
        }
        break;
    case 's':
        for (int x1 = 0; x1 < n; x1++) //����ʹ��������
        {
            int i = m - 1;
            for (int x2 = m - 1; x2 >= 0; x2--)
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
        }
        break;
    }
}

//���ֽ�Ϻ���
//��ÿ��ÿ�п��Խ�ϵ����ֽ�ϲ������ö�������Ϊ0
void combine(int m, int n, int a[m][n], char order)
{
    switch (order)
    {
    case 'a':
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n - 1;)
            {
                if (a[i][j] == 0)
                {
                    break;
                }
                else if (a[i][j] == a[i][j + 1])
                {
                    a[i][j] = a[i][j] * 2;
                    a[i][j + 1] = 0;
                    j = j + 2;
                }
                else
                {
                    j++;
                }
            }
        }
    }
    break;
    case 'd':
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = n - 1; j > 0;)
            {
                if (a[i][j] == 0)
                {
                    break;
                }
                else if (a[i][j] == a[i][j - 1])
                {
                    a[i][j] = a[i][j] * 2;
                    a[i][j - 1] = 0;
                    j = j - 2;
                }
                else
                {
                    j--;
                }
            }
        }
    }
    break;
    case 'w':
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m - 1;)
            {
                if (a[j][i] == 0)
                {
                    break;
                }
                else if (a[j][i] == a[j + 1][i])
                {
                    a[j][i] = a[j][i] * 2;
                    a[j + 1][i] = 0;
                    j = j + 2;
                }
                else
                {
                    j++;
                }
            }
        }
    }
    break;
    case 's':
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = n - 1; j > 0;)
            {
                if (a[j][i] == 0)
                {
                    break;
                }
                else if (a[j][i] == a[j - 1][i])
                {
                    a[j][i] = a[j][i] * 2;
                    a[j - 1][i] = 0;
                    j = j - 2;
                }
                else
                {
                    j--;
                }
            }
        }
    }
    break;
    }
}

//���������������
void move(int m, int n, int a[m][n], char order)
{
    combine(m, n, a, order);
    gather(m, n, a, order);
}

//�ж�ʤ�������������÷���ֵ0��ʾ������1��ʾʤ��
int judge_win(int m, int n, int a[m][n], int len)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == (int)pow(2, len))
            {
                return 1;
            }
        }
    }
    return 0;
}

//�ж�ʧ�������������÷���ֵ0��ʾ������-1��ʾʧ��
int judge_lose(int m, int n, int a[m][n])
{
    int flag = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 0)
            {
                flag++;
            }
        }
    }
    if (flag == 0)
    {
        int count = 0;
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (a[i][j] == a[i][j + 1] || a[i][j] == a[i + 1][j] || a[i + 1][j] == a[i + 1][j + 1] || a[i][j + 1] == a[i + 1][j + 1])
                {
                    count++;
                }
            }
        }
        if (count > 0)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return 0;
    }
}

//���������ӡ����
void print_help_interface(void)
{
    printf("******Help Information***********\n");
    printf("*\th\t: help info     *\n");
    printf("*\ts\t: start game    *\n");
    printf("*\tw/��\t: merge up      *\n");
    printf("*\ts/��\t: merge down    *\n");
    printf("*\ta/��\t: merge left    *\n");
    printf("*\td/��\t: merge right   *\n");
    printf("*\tg\t: automatic     *\n");
    printf("*\tb\t: back          *\n");
    printf("*\tq\t: quit          *\n");
    printf("*********************************\n");
}

//�����������㺯��
void basic_score(int m, int n, int len, double *b_score)
{
    *b_score = m * n * 10 * exp(len);
}

//�����������㺯��
void operate_score(int *all_step_num, double *o_score)
{
    *o_score = log((double)*all_step_num) / log(2.0);
}

//��Ϸ������㺯��
void multiple_score(int m, int n, int a[m][n], long int *m_score, double *one_m_score,
                    int *one_m_count, char order)
{
    *one_m_score = 0;
    *one_m_count = 0;
    switch (order)
    {
    case 'a':
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n - 1;)
            {
                if (a[i][j] == 0)
                {
                    break;
                }
                else if (a[i][j] == a[i][j + 1])
                {
                    *one_m_score = (*one_m_score) + (log(a[i][j]) / log(2.0)) * exp(log(a[i][j]) / log(2));
                    (*one_m_count)++;
                    j += 2;
                }
                else
                {
                    j++;
                }
            }
        }
    }
    break;
    case 'd':
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = n - 1; j > 0;)
            {
                if (a[i][j] == 0)
                {
                    break;
                }
                else if (a[i][j] == a[i][j - 1])
                {
                    *one_m_score = (*one_m_score) + (log(a[i][j]) / log(2.0)) * exp(log(a[i][j]) / log(2));
                    (*one_m_count)++;
                    j -= 2;
                }
                else
                {
                    j--;
                }
            }
        }
    }
    break;
    case 'w':
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m - 1;)
            {
                if (a[j][i] == 0)
                {
                    break;
                }
                else if (a[j][i] == a[j + 1][i])
                {
                    *one_m_score = (*one_m_score) + (log(a[j][i]) / log(2.0)) * exp(log(a[j][i]) / log(2));
                    (*one_m_count)++;
                    j += 2;
                }
                else
                {
                    j++;
                }
            }
        }
    }
    break;
    case 's':
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = n - 1; j > 0;)
            {
                if (a[j][i] == 0)
                {
                    break;
                }
                else if (a[j][i] == a[j - 1][i])
                {
                    *one_m_score = (*one_m_score) + (log(a[i][j]) / log(2.0)) * exp(log(a[i][j]) / log(2));
                    (*one_m_count)++;
                    j -= 2;
                }
                else
                {
                    j--;
                }
            }
        }
    }
    break;
    }
    (*m_score) = (*m_score) + (int)(fabs((*one_m_score)));
}

//�����������㺯��
void continue_score(int m, int n, int a[m][n], char order, int *c_score, int *continue_step, int *one_c_score)
{
    *one_c_score = 0;
    int count = 0;
    switch (order)
    {
    case 'a':
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n - 1;)
            {
                if (a[i][j] == 0)
                {
                    break;
                }
                else if (a[i][j] == a[i][j + 1])
                {
                    count++;
                    j += 2;
                }
                else
                {
                    j++;
                }
            }
        }
    }
    break;
    case 'd':
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = n - 1; j > 0;)
            {
                if (a[i][j] == 0)
                {
                    break;
                }
                else if (a[i][j] == a[i][j - 1])
                {
                    count++;
                    j -= 2;
                }
                else
                {
                    j--;
                }
            }
        }
    }
    break;
    case 'w':
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m - 1;)
            {
                if (a[j][i] == 0)
                {
                    break;
                }
                else if (a[j][i] == a[j + 1][i])
                {
                    count++;
                    j += 2;
                }
                else
                {
                    j++;
                }
            }
        }
    }
    break;
    case 's':
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = n - 1; j > 0;)
            {
                if (a[j][i] == 0)
                {
                    break;
                }
                else if (a[j][i] == a[j - 1][i])
                {
                    count++;
                    j -= 2;
                }
                else
                {
                    j--;
                }
            }
        }
    }
    break;
    }
    if (count > 0)
    {
        (*continue_step)++;
        *one_c_score = fibonacci(*continue_step);
        *c_score = (*c_score) + (*one_c_score);
    }
    else
    {
        *continue_step = 0;
    }
}

//쳲����������㺯��
int fibonacci(int num)
{
    if (num < 3)
        return 1;
    else
    {
        int f[num];
        f[0] = 1;
        f[1] = 1;
        for (int i = 2; i < num; i++)
            f[i] = f[i - 1] + f[i - 2];
        return f[num - 1];
    }
}

//���̴�ӡ����
void print_board(int m, int n, int a[m][n], wchar_t replace[50][100])
{
    for (int i = 0; i < 16 * n + 1; i++)
    {
        printf("-");
    }
    printf("\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            print_single(a[i][j], replace);
        }
        printf("|\n");
        for (int k = 0; k < 16 * n + 1; k++)
        {
            printf("-");
        }
        printf("\n");
    }
}

//�����ַ��滻����
void print_single(int num, wchar_t replace[50][100])
{
    int temp;
    if (num == 0)
    {
        printf("|\t\t");
    }
    else
    {
        temp = (int)(log(num) / log(2));
        wprintf(L"|\t%s\t", replace[temp - 1]);
    }
}

//�Զ����к���
void automatic(int step, int m, int n, int a[m][n], int len, double *b_score, int *all_step_num,
               double *o_score,long int *m_score, double *one_m_score, int *one_m_count, int *c_score, int *continue_step, int *one_c_score, wchar_t replace[50][100], char all_step[100000], int *max_c_num, int *max_c_score, int *max_m_count, double *max_m_score, FILE *fp_score, FILE *fp_operate)
{
    int r;
    char order;
    int judge;
    srand((unsigned)time(NULL) + clock());
    for (int i = 0; i < step; i++)
    {
        r = rand() % 4;
        switch (r)
        {
        case 0:
            order = 'w';
            break;
        case 1:
            order = 's';
            break;
        case 2:
            order = 'a';
            break;
        case 3:
            order = 'd';
            break;
        }
        judge = judge_win(m, n, a, len);
        if (judge == 1)
        {
            system("CLS");
            generate_2_4_one(m, n, a);
            print_board(m, n, a, replace);
            printf("����������:       %d\n", *continue_step);
            printf("��ǰ������������:  %d\n", *one_c_score);
            printf("�ϲ�����:         %d\n", *one_m_count);
            printf("���ζ�Ͻ�������:  %.0lf\n", fabs(*one_m_score));
            printf("��ϲ�㣬�ɹ����أ�\n");
            system("Pause");
            system("CLS");
            basic_score(m, n, len, b_score);
            operate_score(all_step_num, o_score);
            printf("��������:         %.0lf\n", *b_score - *o_score);
            printf("�������������ܺ�:  %d\n", *c_score);
            printf("��Ͻ��������ܺ�:  %ld\n", (*m_score));
            printf("��Ϸ�ܵ÷�:       %.0lf\n", *b_score - *o_score + *c_score + *m_score);
            // score�ļ�
            if ((fp_score = fopen("score.txt", "a")) == NULL)
            {
                puts("score.txt�ļ���ʧ��");
                system("Pause");
            }
            else
            {
                fprintf(fp_score, "��������:       %.0lf\n", *b_score - *o_score);
                fprintf(fp_score, "���������ܺ�:   %d\n", *c_score);
                fprintf(fp_score, "��Ͻ����ܺ�:   %ld\n", *m_score);
                fprintf(fp_score, "��Ϸ�ܵ÷�:     %.0lf\n", *b_score - *o_score + *c_score + *m_score);
                fprintf(fp_score, "���������:     %d\n", *max_c_num);
                fprintf(fp_score, "��������÷�:   %d\n", *max_c_score);
                fprintf(fp_score, "��߶����:     %d\n", *max_m_count);
                fprintf(fp_score, "��߶�ϵ÷�:   %.0lf\n", *max_m_score);
                if (fclose(fp_score) != 0)
                {
                    printf("score.txt�ļ��ر�ʧ��");
                    system("Pause");
                }
            }
            // operate�ļ�
            if ((fp_operate = fopen("operate.txt", "a")) == NULL)
            {
                puts("operate.txt�ļ���ʧ��");
                system("Pause");
            }
            else
            {
                fprintf(fp_operate, "������:     %d\n", *all_step_num);
                fprintf(fp_operate, "�������Ϊ: %s\n", all_step);
                if (fclose(fp_operate) != 0)
                {
                    printf("operate.txt�ļ��ر�ʧ��");
                    system("Pause");
                }
            }
            //�ļ��������
            system("Pause");
            break;
        }
        judge = judge_lose(m, n, a);
        if (judge == -1)
        {
            system("CLS");
            generate_2_4_one(m, n, a);
            print_board(m, n, a, replace);
            printf("���ź�����սʧ�ܡ�\n");
            system("Pause");
            system("CLS");
            printf("��������:         0\n");
            printf("�������������ܺ�:  %d\n", *c_score);
            printf("��Ͻ��������ܺ�:  %ld\n", *m_score);
            printf("��Ϸ�ܵ÷�:       %ld\n", *c_score + *m_score);
            // score�ļ�
            if ((fp_score = fopen("score.txt", "a")) == NULL)
            {
                puts("score.txt�ļ���ʧ��");
                system("Pause");
            }
            else
            {
                fprintf(fp_score, "��������:       %.0lf\n", *b_score - *o_score);
                fprintf(fp_score, "���������ܺ�:   %d\n", *c_score);
                fprintf(fp_score, "��Ͻ����ܺ�:   %ld\n", *m_score);
                fprintf(fp_score, "��Ϸ�ܵ÷�:     %.0lf\n", *b_score - *o_score + *c_score + *m_score);
                fprintf(fp_score, "���������:     %d\n", *max_c_num);
                fprintf(fp_score, "��������÷�:   %d\n", *max_c_score);
                fprintf(fp_score, "��߶����:     %d\n", *max_m_count);
                fprintf(fp_score, "��߶�ϵ÷�:   %.0lf\n", *max_m_score);
                if (fclose(fp_score) != 0)
                {
                    printf("score.txt�ļ��ر�ʧ��");
                    system("Pause");
                }
            }
            // operate�ļ�
            if ((fp_operate = fopen("operate.txt", "a")) == NULL)
            {
                puts("operate.txt�ļ���ʧ��");
                system("Pause");
            }
            else
            {
                fprintf(fp_operate, "������:     %d\n", *all_step_num);
                fprintf(fp_operate, "�������Ϊ: %s\n", all_step);
                if (fclose(fp_operate) != 0)
                {
                    printf("operate.txt�ļ��ر�ʧ��");
                    system("Pause");
                }
            }
            //�ļ��������
            system("Pause");
            break;
        }
        gather(m, n, a, order);
        multiple_score(m, n, a, m_score, one_m_score, one_m_count, order);
        continue_score(m, n, a, order, c_score, continue_step, one_c_score);
        move(m, n, a, order);
        (*all_step_num)++;
        all_step[(*all_step_num) - 1] = order;
        if (*max_c_num < *continue_step)
        {
            *max_c_num = *continue_step;
        }
        if (*max_c_score < *one_c_score)
        {
            *max_c_score = *one_c_score;
        }
        if (*max_m_count < *one_m_count)
        {
            *max_m_count = *one_m_count;
        }
        if (*max_m_score < *one_m_score)
        {
            *max_m_score = *one_m_score;
        }
        system("CLS");
        generate_2_4_one(m, n, a);
        print_board(m, n, a, replace);
        printf("����������:       %d\n", *continue_step);
        printf("��ǰ������������:  %d\n", *one_c_score);
        printf("�ϲ�����:         %d\n", *one_m_count);
        printf("���ζ�Ͻ�������:  %.0lf\n", fabs(*one_m_score));
        Sleep(10);
    }
}
