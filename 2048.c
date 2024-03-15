#include "Function_2048.h"

int main()
{
welcome:;//goto语句可以跳到此欢迎界面
    int input; 
    system("CLS");//打印欢迎界面
    print_main_interface();
    while (1)
    {                    //让程序一直运行，直到输入q
        input = getch(); //输入并让程序读取，但不在键盘上显示，且不用按回车
        while (input != 'q')
        {
            switch (input) //识别输入的字符并分路执行
            {
            case 's':
            start:;
            { //开始游戏
                int a[4][4] =
                    {
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}};
                
                system("CLS");//清屏
                //打印表格
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
                //主要游戏逻辑
                //内层while
                while (1)//让游戏界面一直运行，直到输入q退出此次游戏
                {
                game:;//goto语句可以跳到此游戏界面
                    int input1;
                    input1 = getch();
                    while (input1 != 'q')
                    {
                        switch (input1)//对输入进行选择
                        {
                        case 'r'://重新开始游戏
                        {
                            printf("是否要重新开始游戏？（Y/N）");
                            int restart;
                            restart=getch();
                            switch(restart)
                            {
                                case 'y':goto start;break;
                                case 'n':goto game;break;
                            }
                        }
                        //左移
                        case 'a':
                        {
                            for (int x1 = 0; x1 <= 3; x1++) //左移使方块贴合
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
                            }                               //让行列都贴合
                            for (int x3 = 0; x3 <= 3; x3++) //合并左移项
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
                        break; //左移到此结束
                               //右移
                        case 'd':
                        {
                            for (int x1 = 1; x1 <= 3; x1++) //右移使方块贴合
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
                            }                               //让行列都贴合
                            for (int x3 = 0; x3 <= 3; x3++) //合并右移项
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
                        break; //右移到此结束
                        //上移
                        case 'w':
                        {
                            for (int x1 = 0; x1 <= 3; x1++) //上移移使方块贴合
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

                            }                               //让行列都贴合
                            for (int x3 = 0; x3 <= 3; x3++) //合并上移项
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
                        break; //上移到此结束
                        //下移
                        case 's':
                        {
                            for (int x1 = 0; x1 <= 3; x1++) //下移使方块贴合
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

                            }                               //让行列都贴合
                            for (int x3 = 0; x3 <= 3; x3++) //合并下移项
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
                        break; //下移到此结束
                        default:
                            goto game;//无效输入则令其返回本次游戏界面
                        }
                        //然后判断游戏是否结束
                        //判断游戏胜利
                        for (int i = 0; i <= 3; i++)
                        {
                            for (int j = 0; j <= 3; j++)
                            {
                                if (a[i][j] == 2048)
                                {
                                    printf("恭喜你，成功过关！");
                                    system("pause");
                                    goto welcome; //回到欢迎界面
                                }
                            }
                        }
                        //判断游戏失败
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
                                        printf("很遗憾，挑战失败。");
                                        system("pause");
                                        goto welcome; //返回欢迎界面
                                    }
                                }
                            }
                        }
                        //生成一个随机数
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
                        } //随机数生成结束
                          //打印表格
                        system("CLS");//清屏
                        //打印表格
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
                        break; //让内层while结束
                    }
                    if (input1 == 'q')
                    {
                        printf("是否退出游戏？（Y/N）\n");
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
                            goto game; //返回上一步
                        }
                        }
                        break;
                    }
                }
            }
            break;
            case 'h':
            { //帮助界面
                system("CLS");
                printf("******Help Information******\n");
                printf("\th\t: help info\n");
                printf("\ts\t: start game\n");
                printf("\tw/↑\t: merge up\n");
                printf("\ts/↓\t: merge down\n");
                printf("\ta/←\t: merge left\n");
                printf("\td/→\t: merge right\n");
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
            printf("是否退出游戏？（Y/N）\n");
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
                goto welcome; //返回上一步
            }
            }
            break;
        }
    }

    return 0;
}
