/*
 *Useful functions and
 *three in-build maps
 *0.3.0 version
 *For linux
 *By SDUST weilinfox
 */

#include "defines.h"

extern char map[MAP_Y][MAP_X];
extern int step;
/** locate and direction of new snake body*/
extern int xp[6];
extern int yp[6];
/** up1 down2 left3 right 4*/
extern int dirp[6];
/** play mode 0:never win*/
extern int win;
/** map no*/
extern int mapNo;
/** difficult level*/
extern int dfclevel;
/** Speed level*/
extern int level;
/** scores*/
extern strscore score[5];


/** initialize window and mode variables*/
int init (void)
{
    int setMap (int);
    int readModeFile (void);
    int readLogFile (void);
    /*init window
    system("title Snake Game v0.2.0【by SDUST weilinfox】");
    system("color 0f");*/

    /*reset the size of the window
    char com[50]="mode con cols=";
    strcat(com, MAP_X_C);
    strcat(com, " lines=");
    strcat(com, MAP_Y_C);
    system(com);*/

    /*hide cursor*/
    system("echo -e \"\\033[?25l\"");

	/*read configure file*/
	readModeFile();
	readLogFile();

    return 0;
}

/** first load welcome*/
int firstLoad(void)
{
    int gotoxy(int, int);
    gotoxy(1, 10);
    printf("               看来这是你第一次运行这个程序。\n"
           "               我不保证这个程序不会怼坏你的内存、吓晕你的猫猫，或者干出别的出格的事情。\n"
           "               但是它确实会生成配置文件，放在和这个程序同个目录里。\n"
           "               通常它是安全的，但若真的有什么不好的事情发生了，请告诉我。万分感谢!\n"
           "               如果有杀毒软件报毒，那你确实得考虑要不要卸了它。\n"
           "               毕竟，你只运行了一个我写的软件，它误报了，误报率 100%% 真是让人不敢恭维呢。\n"
           "               手动滑稽\n\n"
           "                                                            ——一只整天不知道干啥的狸\n\n\n\n\n"
           "               Press any key to continue...");
    getchar();
    getchar();

    return 0;
}

int welcome (void)
{
	int gotoxy(int, int);
    char welcome[15][95]={"                  #############                                             ####            ",
                        "             ###################                                          ####              ",
                        "          ######################                                        ####                ",
                        "         ########         ####                                        #####                 ",
                        "        ####            ##                                           ####                   ",
                        "        ###                                             ####       ####                 ### ",
                        "        ######                           ####        ########     ####   #####       #######",
                        "          ##########             ###   ######     ####    ###   ####   #######     ###   ###",
                        "              ##########       ####  #######    ####     ###   ###   ###   ##    ###   ###  ",
                        "                      ####    ###  ###  ##    ###      ###    ###  ###   ##     ###  ##     ",
                        "                        ###  ### ###   ##    ###     ####    ### ####  ##      #####     #  ",
                        "  ###               ######    ####   ######  ######## ###### ####   ########   #####   ##   ",
                        " #######################            ####      ###    ####     #      ####       #######     ",
                        "   ##################                                                  By weilinfox         ",
                        "                                          Data loaded successfully...                       "};

    int i, j;
    int len=strlen(welcome[0]);

    system("clear");
    for (i=0; welcome[0][i]!='\0'; i++) {
        for (j=0; j<15; j++) {
            gotoxy((MAP_X-len+15)/2+i+1, (MAP_Y-15)/2+j+1);
            putchar(welcome[j][i]);
        }
        sleepms(10);
    }
    sleepms(1500);

    return 0;
}

/** judge whether game is over*/
int judge (void)
{
    if (map[head->y][head->x])
        return 1;

    int state=0;
    snakeBodyNode* node=head->next;
    int x=head->x;
    int y=head->y;

    while (node!=NULL && !state) {
        if (node->x==x && node->y==y)
            return 1;
        node=node->next;
    }
    return 0;
}

/** judge whether break a recored*/
int brRecord (int lev, int s)
{
    if (s>score[4].score)
        return 1;
    else if (s==score[4].score && s!=0 && lev>score[4].dfclevel)
        return 1;
    else
        return 0;
}

/** save a recored*/
int saveRecord(int lev, int s, int map)
{
    int initSideBar(void);
    int gotoxy(int, int);
    int saveLogFile (void);
    int i;
    for (i=4; i>0; i--) {
        if (s>score[i-1].score ||
            (s==score[i-1].score && lev>score[i].dfclevel)) {
            score[i].score=score[i-1].score;
            score[i].dfclevel=score[i-1].dfclevel;
            score[i].map=score[i-1].map;
            strcpy(score[i].name, score[i-1].name);
        } else
            break;
    }
    score[i].score=s;
    score[i].dfclevel=lev;
    score[i].map=map;

    system("clear");
    initSideBar();

    gotoxy((MAP_X-28)/2, (MAP_Y-3)/2);
    printf("============昵称============");
    gotoxy((MAP_X-28)/2, (MAP_Y-3)/2+1);
    putchar('>');
    gotoxy((MAP_X-28)/2, (MAP_Y-3)/2+2);
    printf("============================");
    gotoxy((MAP_X-28)/2, (MAP_Y-3)/2+3);
    printf("请输入少于 20 个字母或 10 个汉字");

    gotoxy((MAP_X-28)/2+3, (MAP_Y-3)/2+1);
    scanf("%s", score[i].name);
    score[i].name[20]='\0';

    saveLogFile();

    return 0;
}

/** initialize map and set "step"*/
int setMap (int mode)
{
    int i, j;
    int readMapFile (void);
    memset(map, 0, sizeof(map));

    switch (mode) {
    case 1:
        for (i=0; i<MAP_X; i++){
            map[0][i]='#';
            map[MAP_Y-1][i]='#';
        }
        for (i=1; i<MAP_Y-1; i++) {
            map[i][0]='#';
            map[i][MAP_X-1]='#';
        }
        for (i=0; i<6; i++)
            xp[i]=1;
        for (i=0; i<6; i++)
            yp[i]=6-i;
        for (i=0; i<6; i++)
            dirp[i]=2;
        step=1;
        break;
    case 2:
        strcpy(&map[((MAP_Y/2)-9)/2][(MAP_X-60)/2], "####################                    ####################");
        strcpy(&map[((MAP_Y/2)-9)/2+1][(MAP_X-60)/2], "####################                    ####################");
        strcpy(&map[((MAP_Y/2)-9)/2+2][(MAP_X-60)/2], "####################                    ####################");
        strcpy(&map[((MAP_Y/2)-9)/2+3][(MAP_X-60)/2], "###                                                      ###");
        strcpy(&map[((MAP_Y/2)-9)/2+4][(MAP_X-60)/2], "###                                                      ###");
        strcpy(&map[((MAP_Y/2)-9)/2+5][(MAP_X-60)/2], "###                                                      ###");
        strcpy(&map[((MAP_Y/2)-9)/2+6][(MAP_X-60)/2], "###             ########            ########             ###");
        strcpy(&map[((MAP_Y/2)-9)/2+7][(MAP_X-60)/2], "###             ########            ########             ###");
        strcpy(&map[((MAP_Y/2)-9)/2+8][(MAP_X-60)/2], "###             ########            ########             ###");
        strcpy(&map[((MAP_Y/2)-9)/2+9][(MAP_X-60)/2], "###             ########            ########             ###");
        strcpy(&map[((MAP_Y/2)-9)/2+10][(MAP_X-60)/2], "                ########            ########");
        strcpy(&map[((MAP_Y/2)-9)/2+11][(MAP_X-60)/2], "                ########            ########");
        strcpy(&map[((MAP_Y/2)-9)/2+12][(MAP_X-60)/2], "                ########            ########");
        strcpy(&map[((MAP_Y/2)-9)/2+13][(MAP_X-60)/2], "                ########            ########");

        strcpy(&map[MAP_Y/2][(MAP_X-60)/2-2], "#####");
        strcpy(&map[MAP_Y/2][(MAP_X-60)/2+57], "#####");
        strcpy(&map[MAP_Y/2][(MAP_X-5)/2], "#####");

        strcpy(&map[MAP_Y-(((MAP_Y/2)-9)/2)][(MAP_X-60)/2], "####################                    ####################");
        strcpy(&map[MAP_Y-(((MAP_Y/2)-9)/2)-1][(MAP_X-60)/2], "####################                    ####################");
        strcpy(&map[MAP_Y-(((MAP_Y/2)-9)/2)-2][(MAP_X-60)/2], "####################                    ####################");
        strcpy(&map[MAP_Y-(((MAP_Y/2)-9)/2)-3][(MAP_X-60)/2], "###                                                      ###");
        strcpy(&map[MAP_Y-(((MAP_Y/2)-9)/2)-4][(MAP_X-60)/2], "###                                                      ###");
        strcpy(&map[MAP_Y-(((MAP_Y/2)-9)/2)-5][(MAP_X-60)/2], "###                                                      ###");
        strcpy(&map[MAP_Y-(((MAP_Y/2)-9)/2)-6][(MAP_X-60)/2], "###             ########            ########             ###");
        strcpy(&map[MAP_Y-(((MAP_Y/2)-9)/2)-7][(MAP_X-60)/2], "###             ########            ########             ###");
        strcpy(&map[MAP_Y-(((MAP_Y/2)-9)/2)-8][(MAP_X-60)/2], "###             ########            ########             ###");
        strcpy(&map[MAP_Y-(((MAP_Y/2)-9)/2)-9][(MAP_X-60)/2], "###             ########            ########             ###");
        strcpy(&map[MAP_Y-(((MAP_Y/2)-9)/2)-10][(MAP_X-60)/2], "                ########            ########");
        strcpy(&map[MAP_Y-(((MAP_Y/2)-9)/2)-11][(MAP_X-60)/2], "                ########            ########");
        strcpy(&map[MAP_Y-(((MAP_Y/2)-9)/2)-12][(MAP_X-60)/2], "                ########            ########");
        strcpy(&map[MAP_Y-(((MAP_Y/2)-9)/2)-13][(MAP_X-60)/2], "                ########            ########");

        for (i=0; i<MAP_Y; i++) {
            for (j=0; j<MAP_X; j++) {
                if (map[i][j]!='#')
                    map[i][j]=0;
            }
        }
        for (i=0; i<6; i++)
            xp[i]=1;
        for (i=0; i<6; i++)
            yp[i]=6-i;
        for (i=0; i<6; i++)
            dirp[i]=2;
        step=0;
        break;
    case 3:
        strcpy(&map[((MAP_Y/2)-9)/2][(MAP_X-52)/2],    "######     #####################");
        strcpy(&map[((MAP_Y/2)-9)/2+1][(MAP_X-52)/2],  "######     #############################");
        strcpy(&map[((MAP_Y/2)-9)/2+2][(MAP_X-52)/2],  "######     ##################################");
        strcpy(&map[((MAP_Y/2)-9)/2+3][(MAP_X-52)/2],  "######                             ##############");
        strcpy(&map[((MAP_Y/2)-9)/2+4][(MAP_X-52)/2],  "######                                   ###########");
        strcpy(&map[((MAP_Y/2)-9)/2+5][(MAP_X-52)/2],  "######                                       #########");
        strcpy(&map[((MAP_Y/2)-9)/2+6][(MAP_X-52)/2],  "######          ############                  ########");
        strcpy(&map[((MAP_Y/2)-9)/2+7][(MAP_X-52)/2],  "######          ###############               ########");
        strcpy(&map[((MAP_Y/2)-9)/2+8][(MAP_X-52)/2],  "######          ################              ########");
        strcpy(&map[((MAP_Y/2)-9)/2+9][(MAP_X-52)/2],  "######          ################              ########");
        strcpy(&map[((MAP_Y/2)-9)/2+10][(MAP_X-52)/2], "######          ###############              ########");
        strcpy(&map[((MAP_Y/2)-9)/2+11][(MAP_X-52)/2], "######          ############                ########");
        strcpy(&map[((MAP_Y/2)-9)/2+12][(MAP_X-52)/2], "######                                    ########");
        strcpy(&map[((MAP_Y/2)-9)/2+13][(MAP_X-52)/2], "######                                  ########");
        strcpy(&map[((MAP_Y/2)-9)/2+14][(MAP_X-52)/2], "######                    ###################");

        strcpy(&map[MAP_Y/2][(MAP_X-52)/2+14], "###");

        strcpy(&map[MAP_Y-(((MAP_Y/2)-9)/2)][(MAP_X-52)/2], "######     #####################");
        strcpy(&map[MAP_Y-(((MAP_Y/2)-9)/2)-1][(MAP_X-52)/2], "######     #############################");
        strcpy(&map[MAP_Y-(((MAP_Y/2)-9)/2)-2][(MAP_X-52)/2], "######     ##################################");
        strcpy(&map[MAP_Y-(((MAP_Y/2)-9)/2)-3][(MAP_X-52)/2], "######                             ##############");
        strcpy(&map[MAP_Y-(((MAP_Y/2)-9)/2)-4][(MAP_X-52)/2], "######                                   ###########");
        strcpy(&map[MAP_Y-(((MAP_Y/2)-9)/2)-5][(MAP_X-52)/2], "######                                       #########");
        strcpy(&map[MAP_Y-(((MAP_Y/2)-9)/2)-6][(MAP_X-52)/2], "######          ############                  ########");
        strcpy(&map[MAP_Y-(((MAP_Y/2)-9)/2)-7][(MAP_X-52)/2], "######          ###############               ########");
        strcpy(&map[MAP_Y-(((MAP_Y/2)-9)/2)-8][(MAP_X-52)/2], "######          ################              ########");
        strcpy(&map[MAP_Y-(((MAP_Y/2)-9)/2)-9][(MAP_X-52)/2], "######          ################              ########");
        strcpy(&map[MAP_Y-(((MAP_Y/2)-9)/2)-10][(MAP_X-52)/2], "######          ###############              ########");
        strcpy(&map[MAP_Y-(((MAP_Y/2)-9)/2)-11][(MAP_X-52)/2], "######          ############                ########");
        strcpy(&map[MAP_Y-(((MAP_Y/2)-9)/2)-12][(MAP_X-52)/2], "######                                    ########");
        strcpy(&map[MAP_Y-(((MAP_Y/2)-9)/2)-13][(MAP_X-52)/2], "######                                  ########");
        strcpy(&map[MAP_Y-(((MAP_Y/2)-9)/2)-14][(MAP_X-52)/2], "######                    ###################");

        for (i=0; i<MAP_Y; i++) {
            for (j=0; j<MAP_X; j++) {
                if (map[i][j]!='#')
                    map[i][j]=0;
            }
        }
        for (i=0; i<6; i++)
            xp[i]=1;
        for (i=0; i<6; i++)
            yp[i]=6-i;
        for (i=0; i<6; i++)
            dirp[i]=2;
        step=0;
        break;
    case 4:
        readMapFile();
        for (i=0; i<MAP_Y; i++) {
            for (j=0; j<MAP_X; j++) {
                if (map[i][j]==' ')
                    map[i][j]=0;
                else if (isprint(map[i][j]))
                    map[i][j]='#';
            }
        }
        for (i=0; i<6; i++)
            xp[i]=1;
        for (i=0; i<6; i++)
            yp[i]=6-i;
        for (i=0; i<6; i++)
            dirp[i]=2;
        step=0;
        break;
    }

    return 0;
}
