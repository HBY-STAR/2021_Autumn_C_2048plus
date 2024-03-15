#include "Function_2048.h"
#define filename "Alternative2.txt"
int main(void)
{
    //基础变量定义
    int all_step_num;      //总步数
    char all_step[100000]; //存放操作的数组
    double b_score;        //基础分数
    double o_score;        //操作分数
    long int m_score;      //多合奖励总和
    int c_score;           //连击奖励总和
    double one_m_score;    //一次多合奖励
    int one_m_count;       //一次多合的数目
    int continue_step;     //连击数
    int one_c_score;       //本次连击的奖励
    int max_c_num;         //最大连击数
    int max_c_score;       //最大连击奖励
    int max_m_count;       //最大多合数
    double max_m_score;    //最大多合奖励

    //从文件中读取序列长度和序列字符串
    setlocale(LC_ALL, ""); //本地化操作
    FILE *fp_alternative;  // alternative文件对应的指针
    FILE *fp_score;        // score文件对应的指针
    FILE *fp_operate;      // operate文件对应的指针
    int len;
    wchar_t replace[50][100]; //存放替换字符序列的数组

    //写入一个文件
    if ((fp_alternative = fopen(filename, "r")) == NULL)
    {
        puts("Alternative文件打开失败");
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
            printf("Alternative文件关闭失败");
            system("Pause");
        }
    }
    //文件写入完成

    char order; //存放本次操作的变量
    int judge;  //存放判断游戏成功数的变量
    while (1)
    {
    main_interface:;
        system("CLS");
        print_main_interface(); //主界面打印函数
        order = getch();
        if (order == 'q') //退出程序
        {
            break;
        }
        else if (order == 's')
        {
            //开始游戏
        game_interface:;
            system("CLS");
            printf("请输入行数和列数，若直接按m则设置为默认长度。\n");

            //控制行列的输入
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

            //初始化数组
            int a[m][n];
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    a[i][j] = 0;
                }
            }

            //基础变量初始化
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

            //产生初始棋盘
            generate_2_4_two(m, n, a);
            system("CLS");
            print_board(m, n, a, replace);
            printf("已连击次数:       %d\n", continue_step);
            printf("当前连击奖励分数:  %d\n", one_c_score);
            printf("合并次数:         %d\n", one_m_count);
            printf("本次多合奖励分数:  %.0lf\n", one_m_score);

            while (1)
            {
                order = getch();
                if (order == 'q') //返回主界面程序
                {
                    printf("是否要返回主界面？(Y/N)\n");
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
                else if (order == 'r') //重新开始游戏程序
                {
                    printf("是否要重新开始游戏？（Y/N）\n");
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

                //游戏核心部分
                else if (order == 'a' || order == 'd' || order == 'w' || order == 's')
                {
                    //首先判断游戏是否胜利
                    judge = judge_win(m, n, a, len);
                    if (judge == 1)
                    {
                        //终端显示
                        system("CLS");
                        generate_2_4_one(m, n, a);
                        print_board(m, n, a, replace);
                        printf("已连击次数:       %d\n", continue_step);
                        printf("当前连击奖励分数:  %d\n", one_c_score);
                        printf("合并次数:         %d\n", one_m_count);
                        printf("本次多合奖励分数:  %.0lf\n", fabs(one_m_score));
                        printf("恭喜你，成功过关！\n");
                        system("Pause");
                        system("CLS");
                        basic_score(m, n, len, &b_score);
                        operate_score(&all_step_num, &o_score);
                        printf("基础分数:         %.0lf\n", b_score - o_score);
                        printf("连击奖励分数总和:  %d\n", c_score);
                        printf("多合奖励分数总和:  %ld\n", m_score);
                        printf("游戏总得分:       %.0lf\n", b_score - o_score + c_score + m_score);

                        // 写入score文件
                        if ((fp_score = fopen("score.txt", "a")) == NULL)
                        {
                            puts("score.txt文件打开失败");
                            system("Pause");
                        }
                        else
                        {
                            fprintf(fp_score, "基础分数:       %.0lf\n", b_score - o_score);
                            fprintf(fp_score, "连击奖励总和:   %d\n", c_score);
                            fprintf(fp_score, "多合奖励总和:   %ld\n", m_score);
                            fprintf(fp_score, "游戏总得分:     %.0lf\n", b_score - o_score + c_score + m_score);
                            fprintf(fp_score, "最高连击数:     %d\n", max_c_num);
                            fprintf(fp_score, "最高连击得分:   %d\n", max_c_score);
                            fprintf(fp_score, "最高多合数:     %d\n", max_m_count);
                            fprintf(fp_score, "最高多合得分:   %.0lf\n", max_m_score);
                            if (fclose(fp_score) != 0)
                            {
                                printf("score.txt文件关闭失败");
                                system("Pause");
                            }
                        }

                        // 写入operate文件
                        if ((fp_operate = fopen("operate.txt", "a")) == NULL)
                        {
                            puts("operate.txt文件打开失败");
                            system("Pause");
                        }
                        else
                        {
                            fprintf(fp_operate, "操作数:     %d\n", all_step_num);
                            fprintf(fp_operate, "具体操作为: %s\n", all_step);
                            if (fclose(fp_operate) != 0)
                            {
                                printf("operate.txt文件关闭失败");
                                system("Pause");
                            }
                        }
                        system("Pause");
                        goto main_interface;
                    }

                    //然后判断游戏是否失败
                    judge = judge_lose(m, n, a);
                    if (judge < 0)
                    {
                        //终端显示
                        system("CLS");
                        generate_2_4_one(m, n, a);
                        print_board(m, n, a, replace);
                        printf("很遗憾，挑战失败。\n");
                        system("Pause");
                        system("CLS");
                        printf("基础分数:         %.0lf\n", b_score);
                        printf("连击奖励分数总和:  %d\n", c_score);
                        printf("多合奖励分数总和:  %ld\n", m_score);
                        printf("游戏总得分:       %ld\n", (long)(c_score + m_score));

                        // 写入score文件
                        if ((fp_score = fopen("score.txt", "a")) == NULL)
                        {
                            puts("score.txt文件打开失败");
                            system("Pause");
                        }
                        else
                        {
                            fprintf(fp_score, "基础分数:       %.0lf\n", b_score - o_score);
                            fprintf(fp_score, "连击奖励总和:   %d\n", c_score);
                            fprintf(fp_score, "多合奖励总和:   %ld\n", m_score);
                            fprintf(fp_score, "游戏总得分:     %.0lf\n", b_score - o_score + c_score + m_score);
                            fprintf(fp_score, "最高连击数:     %d\n", max_c_num);
                            fprintf(fp_score, "最高连击得分:   %d\n", max_c_score);
                            fprintf(fp_score, "最高多合数:     %d\n", max_m_count);
                            fprintf(fp_score, "最高多合得分:   %.0lf\n", max_m_score);
                            if (fclose(fp_score) != 0)
                            {
                                printf("score.txt文件关闭失败");
                                system("Pause");
                            }
                        }

                        // 写入operate文件
                        if ((fp_operate = fopen("operate.txt", "a")) == NULL)
                        {
                            puts("operate.txt文件打开失败");
                            system("Pause");
                        }
                        else
                        {
                            fprintf(fp_operate, "操作数:     %d\n", all_step_num);
                            fprintf(fp_operate, "具体操作为: %s\n", all_step);
                            if (fclose(fp_operate) != 0)
                            {
                                printf("operate.txt文件关闭失败");
                                system("Pause");
                            }
                        }
                        //文件处理结束
                        system("Pause");
                        goto main_interface;
                    }

                    //接下来是对数组的操作和分数的计算

                    //首先让数据合并
                    gather(m, n, a, order);
                    //计算多合奖励
                    multiple_score(m, n, a, &m_score, &one_m_score, &one_m_count, order);
                    //计算连击奖励
                    continue_score(m, n, a, order, &c_score, &continue_step, &one_c_score);
                    //用move完成对数组的操作
                    move(m, n, a, order);
                    //记录操作数和具体操作
                    all_step_num++;
                    all_step[all_step_num - 1] = order;
                    //记录最大的各种分数
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
                    //打印棋盘并准备下一次操作
                    system("CLS");
                    generate_2_4_one(m, n, a);
                    print_board(m, n, a, replace);
                    printf("已连击次数:       %d\n", continue_step);
                    printf("当前连击奖励分数:  %d\n", one_c_score);
                    printf("合并次数:         %d\n", one_m_count);
                    printf("本次多合奖励分数:  %.0lf\n", fabs((double)one_m_score));
                }

                //自动执行程序
                else if (order == 'g')
                {
                    printf("请输入要自动随机执行的步数\n");
                    int step;
                    scanf("%d", &step);
                    automatic(step, m, n, a, len, &b_score, &all_step_num, &o_score, &m_score, &one_m_score, &one_m_count, &c_score, &continue_step, &one_c_score, replace, all_step, &max_c_num, &max_c_score, &max_m_count, &max_m_score, fp_score, fp_operate);
                    printf("执行结束。\n");
                    goto main_interface;
                }
                else
                {
                    continue;
                }
            }
        }
        //帮助界面
        else if (order == 'h')
        {
            system("CLS");
            print_help_interface(); //打印帮助界面函数
            while (1)
            {
                order = getch();
                if (order == 'b') //'b'为back选项
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