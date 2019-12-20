/*
 *Functions that print option choosing frames
 *and two in-build maps
 *dbb version
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


/** initialize window*/
int init (void)
{
    /*init window*/
    system("title Snake Game v0.1.dbb【by SDUST weilinfox】");
    system("color 0f");

    /*reset the size of the window*/
    char com[50]="mode con cols=";
    strcat(com, MAP_X_C);
    strcat(com, " lines=");
    strcat(com, MAP_Y_C);
    system(com);

    /*hide cursor*/
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);

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

/** replay the game*/
int replay(void)
{
    int initSideBar(void);
    char ch;
    system("cls");
    initSideBar();
    gotoxy((MAP_X-28)/2, (MAP_Y-4)/2);
    printf("==========重玩卡关==========");
    gotoxy((MAP_X-28)/2, (MAP_Y-4)/2+1);
    printf("          重玩(Y)");
    gotoxy((MAP_X-28)/2, (MAP_Y-4)/2+2);
    printf("      任意键返回主界面");
    gotoxy((MAP_X-28)/2, (MAP_Y-4)/2+3);
    printf("============================");
    while (!kbhit()) ;
    ch=getch();
    if (ch=='y' || ch=='Y')
        return 1;
    else
        return 0;
}

/** confirm quit*/
int quitConfirm(void)
{
    char ch;
    int initSideBar(void);
    system("cls");
    initSideBar();
    gotoxy((MAP_X-28)/2, (MAP_Y-4)/2);
    printf("==========确认退出==========");
    gotoxy((MAP_X-28)/2, (MAP_Y-4)/2+1);
    printf("           退出(Y)");
    gotoxy((MAP_X-28)/2, (MAP_Y-4)/2+2);
    printf("         任意键取消");
    gotoxy((MAP_X-28)/2, (MAP_Y-4)/2+3);
    printf("============================");
    while (!kbhit()) ;
    ch=getch();
    if (ch=='y' || ch=='Y')
        exit(0);
    else
        return 0;
}

/** choose game's level*/
int chooseLevel(void)
{
    int lev=2;
    char ch;
    int initSideBar(void);
    system("cls");
    initSideBar();
    gotoxy((MAP_X-28)/2, (MAP_Y-5)/2);
    printf("==========选择难度==========");
    gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+1);
    printf("            简单");
    gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+2);
    printf("         -> 普通");
    gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+3);
    printf("            困难");
    gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+4);
    printf("============================");

    while (1) {
        switch (ch=getch()) {
        case 'w':
        case 'W':
        case 'a':
        case 'A':
        case 72:
        case 75:
            lev--;
            if (lev<1)
                lev=3;
            break;
        case 's':
        case 'S':
        case 'd':
        case 'D':
        case 80:
        case 77:
            lev++;
            if (lev>3)
                lev=1;
            break;
        case 13:
            return lev;
        }

        switch (lev) {
        case 1:
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2);
            printf("==========选择难度==========");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+1);
            printf("         -> 简单");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+2);
            printf("            普通");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+3);
            printf("            困难");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+4);
            printf("============================");
            break;
        case 2:
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2);
            printf("==========选择难度==========");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+1);
            printf("            简单");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+2);
            printf("         -> 普通");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+3);
            printf("            困难");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+4);
            printf("============================");
            break;
        case 3:
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2);
            printf("==========选择难度==========");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+1);
            printf("            简单");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+2);
            printf("            普通");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+3);
            printf("         -> 困难");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+4);
            printf("============================");
            break;
        }
    }
}

int mode (void)
{
    int mod=1;
    char ch;
    int initSideBar(void);
    int quitConfirm(void);
    int mode (void);
    system("cls");
    initSideBar();
    gotoxy((MAP_X-28)/2, (MAP_Y-5)/2);
    printf("==========选择模式==========");
    gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+1);
    printf("         -> 普通");
    gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+2);
    printf("            竞技");
    gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+3);
    printf("            退出");
    gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+4);
    printf("============================");

    while (1) {
        switch (ch=getch()) {
        case 'w':
        case 'W':
        case 'a':
        case 'A':
        case 72:
        case 75:
            mod--;
            if (mod<1)
                mod=3;
            break;
        case 's':
        case 'S':
        case 'd':
        case 'D':
        case 80:
        case 77:
            mod++;
            if (mod>3)
                mod=1;
            break;
        case 13:
            if (mod==3) {
                quitConfirm();
                mode();
            } else
                return mod==1?1:0;
        }

        switch (mod) {
        case 1:
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2);
            printf("==========选择模式==========");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+1);
            printf("         -> 普通");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+2);
            printf("            竞技");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+3);
            printf("            退出");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+4);
            printf("============================");
            break;
        case 2:
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2);
            printf("==========选择模式==========");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+1);
            printf("            普通");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+2);
            printf("         -> 竞技");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+3);
            printf("            退出");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+4);
            printf("============================");
            break;
        case 3:
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2);
            printf("==========选择模式==========");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+1);
            printf("            普通");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+2);
            printf("            竞技");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+3);
            printf("         -> 退出");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+4);
            printf("============================");
            break;
        }
    }
}

int chooseMap(void)
{
    int setMap (int);
    int mod=1;
    char ch;
    int initSideBar(void);
    system("cls");
    initSideBar();
    gotoxy((MAP_X-28)/2, (MAP_Y-5)/2);
    printf("==========选择地图==========");
    gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+1);
    printf("         -> 图一");
    gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+2);
    printf("            图二");
    gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+3);
    printf("            DBB");
    gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+4);
    printf("============================");

    while (1) {
        switch (ch=getch()) {
        case 'w':
        case 'W':
        case 'a':
        case 'A':
        case 72:
        case 75:
            mod--;
            if (mod<1)
                mod=3;
            break;
        case 's':
        case 'S':
        case 'd':
        case 'D':
        case 80:
        case 77:
            mod++;
            if (mod>3)
                mod=1;
            break;
        case 13:
            mapNo=mod;
            setMap(mod);
            return 0;
        }

        switch (mod) {
        case 1:
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2);
            printf("==========选择地图==========");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+1);
            printf("         -> 图一");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+2);
            printf("            图二");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+3);
            printf("            DBB");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+4);
            printf("============================");
            break;
        case 2:
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2);
            printf("==========选择地图==========");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+1);
            printf("            图一");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+2);
            printf("         -> 图二");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+3);
            printf("            DBB");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+4);
            printf("============================");
            break;
        case 3:
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2);
            printf("==========选择地图==========");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+1);
            printf("            图一");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+2);
            printf("            图二");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+3);
            printf("         -> DBB");
            gotoxy((MAP_X-28)/2, (MAP_Y-5)/2+4);
            printf("============================");
            break;
        }
    }

    return 0;
}

int setMap (int mode)
{
    int i, j;

    switch (mode) {
    case 1:
        memset(map, 0, sizeof(map));
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
        memset(map, 0, sizeof(map));
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
        break;
    case 3:
        memset(map, 0, sizeof(map));
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
        break;
    }

    return 0;
}
