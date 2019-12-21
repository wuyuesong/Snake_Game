/*
 *Functions that print option choosing frames
 *0.3.0 version
 *For linux
 *By SDUST weilinfox
 */

 /** number of main menu items*/
 #define ITEM 6
 /** length of a item*/
 #define LEN 36

/** play mode 0:never win*/
extern int win;
/** map no*/
extern int mapNo;
/** Speed level*/
extern int level;
/** difficult level*/
extern int dfclevel;

/** print main menu*/
int mainMenu (void)
{
    int opt=4;
    char ch;
    int mode (void);
    int quitConfirm(void);
    int showRank (void);
    int mainMenu (void);
    int saveModeFile (void);
    int chooseLevel(void);
    int chooseMap(void);
    int initSideBar(void);
    int printLittleSideBarInfo (void);

    system("clear");
    initSideBar();
    printLittleSideBarInfo();
    gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2);
    printf("===============主菜单===============");
    gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+1);
    printf("                模式");
    gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+2);
    printf("                地图");
    gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+3);
    printf("                难度");
    gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+4);
    printf("           -> 开始游戏");
    gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+5);
    printf("               排行榜");
    gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+6);
    printf("                退出");
    gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+7);
    printf("===================================");

    while (1) {
        switch (ch=getch()) {
        case 'w':
        case 'W':
        case 'a':
        case 'A':
        case 72:
        case 75:
            opt--;
            if (opt<1)
                opt=ITEM;
            break;
        case 's':
        case 'S':
        case 'd':
        case 'D':
        case 80:
        case 77:
            opt++;
            if (opt>ITEM)
                opt=1;
            break;
        case 13: {
            switch (opt) {
            case 1:
                mode();
                system("clear");
                initSideBar();
                printLittleSideBarInfo();
                break;
            case 2:
                chooseMap();
                system("clear");
                initSideBar();
                printLittleSideBarInfo();
                break;
            case 3:
                dfclevel=level=chooseLevel();
                system("clear");
                initSideBar();
                printLittleSideBarInfo();
                break;
            case 4:
                saveModeFile();
                return 0;
            case 5:
                showRank();
                mainMenu();
                return 0;
            case 6:
                quitConfirm();
                mainMenu();
                return 0;
            default:
                MessageBox(NULL,"A error occured in main menu!","ERROR!",MB_OK);
                exit(1);
            }
        }
        }

        switch (opt) {
        case 1:
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2);
            printf("===============主菜单===============");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+1);
            printf("           ->   模式");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+2);
            printf("                地图");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+3);
            printf("                难度");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+4);
            printf("              开始游戏");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+5);
            printf("               排行榜");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+6);
            printf("                退出");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+7);
            printf("===================================");
            break;
        case 2:
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2);
            printf("===============主菜单===============");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+1);
            printf("                模式");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+2);
            printf("           ->   地图");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+3);
            printf("                难度");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+4);
            printf("              开始游戏");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+5);
            printf("               排行榜");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+6);
            printf("                退出");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+7);
            printf("===================================");
            break;
        case 3:
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2);
            printf("===============主菜单===============");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+1);
            printf("                模式");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+2);
            printf("                地图");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+3);
            printf("           ->   难度");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+4);
            printf("              开始游戏");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+5);
            printf("               排行榜");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+6);
            printf("                退出");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+7);
            printf("===================================");
            break;
        case 4:
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2);
            printf("===============主菜单===============");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+1);
            printf("                模式");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+2);
            printf("                地图");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+3);
            printf("                难度");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+4);
            printf("           -> 开始游戏");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+5);
            printf("               排行榜");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+6);
            printf("                退出");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+7);
            printf("===================================");
            break;
        case 5:
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2);
            printf("===============主菜单===============");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+1);
            printf("                模式");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+2);
            printf("                地图");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+3);
            printf("                难度");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+4);
            printf("              开始游戏");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+5);
            printf("           ->  排行榜");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+6);
            printf("                退出");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+7);
            printf("===================================");
            break;
        case 6:
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2);
            printf("===============主菜单===============");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+1);
            printf("                模式");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+2);
            printf("                地图");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+3);
            printf("                难度");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+4);
            printf("              开始游戏");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+5);
            printf("               排行榜");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+6);
            printf("           ->   退出");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+7);
            printf("===================================");
            break;
        }
    }
}

/** replay the game*/
int replay(void)
{
    int initSideBar(void);
    char ch;
    system("clear");
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
    system("clear");
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
    if (ch=='y' || ch=='Y') {
    	/*show cursor*/
    	system("echo -e \"\\033[?25h\""); 
        exit(0);
    } else
        return 0;
}

/** choose game's level and return*/
int chooseLevel(void)
{
    int lev=level;
    char ch;
    int initSideBar(void);
    system("clear");
    initSideBar();

    while (1) {
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

    }
}

/** Choose mode and set "win"*/
int mode (void)
{
    int mod=(win==1?1:2);
    char ch;
    int initSideBar(void);
    int quitConfirm(void);
    int mode (void);
    system("clear");
    initSideBar();

    while (1) {
        switch (mod) {
        case 1:
            gotoxy((MAP_X-28)/2, (MAP_Y-4)/2);
            printf("==========选择模式==========");
            gotoxy((MAP_X-28)/2, (MAP_Y-4)/2+1);
            printf("         -> 普通");
            gotoxy((MAP_X-28)/2, (MAP_Y-4)/2+2);
            printf("            竞技");
            gotoxy((MAP_X-28)/2, (MAP_Y-4)/2+3);
            printf("============================");
            break;
        case 2:
            gotoxy((MAP_X-28)/2, (MAP_Y-4)/2);
            printf("==========选择模式==========");
            gotoxy((MAP_X-28)/2, (MAP_Y-4)/2+1);
            printf("            普通");
            gotoxy((MAP_X-28)/2, (MAP_Y-4)/2+2);
            printf("         -> 竞技");
            gotoxy((MAP_X-28)/2, (MAP_Y-4)/2+3);
            printf("============================");
            break;
        }

        switch (ch=getch()) {
        case 'w':
        case 'W':
        case 'a':
        case 'A':
        case 72:
        case 75:
            mod--;
            if (mod<1)
                mod=2;
            break;
        case 's':
        case 'S':
        case 'd':
        case 'D':
        case 80:
        case 77:
            mod++;
            if (mod>2)
                mod=1;
            break;
        case 13:
                win=(mod==1?1:0);
                return 0;
        }

    }
}

/** ChooseMap and set "mapNo"*/
int chooseMap(void)
{
    int setMap (int);
    int mod=mapNo;
    char ch;
    int initSideBar(void);
    system("clear");
    initSideBar();

    while (1) {
        switch (mod) {
        case 1:
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2);
            printf("==========选择地图==========");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+1);
            printf("       -> 经典图一");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+2);
            printf("          经典图二");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+3);
            printf("            DBB");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+4);
            printf("         自定义地图");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+5);
            printf("============================");
            break;
        case 2:
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2);
            printf("==========选择地图==========");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+1);
            printf("          经典图一");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+2);
            printf("       -> 经典图二");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+3);
            printf("            DBB");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+4);
            printf("         自定义地图");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+5);
            printf("============================");
            break;
        case 3:
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2);
            printf("==========选择地图==========");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+1);
            printf("          经典图一");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+2);
            printf("          经典图二");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+3);
            printf("       ->   DBB");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+4);
            printf("         自定义地图");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+5);
            printf("============================");
            break;
        case 4:
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2);
            printf("==========选择地图==========");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+1);
            printf("          经典图一");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+2);
            printf("          经典图二");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+3);
            printf("            DBB");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+4);
            printf("       ->自定义地图");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+5);
            printf("============================");
            break;
        }

        switch (ch=getch()) {
        case 'w':
        case 'W':
        case 'a':
        case 'A':
        case 72:
        case 75:
            mod--;
            if (mod<1)
                mod=4;
            break;
        case 's':
        case 'S':
        case 'd':
        case 'D':
        case 80:
        case 77:
            mod++;
            if (mod>4)
                mod=1;
            break;
        case 13:
            mapNo=mod;
            setMap(mod);
            return 0;
        }

    }

    return 0;
}
