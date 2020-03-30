/*
 *Functions that print option choosing frames
 *0.3.1 version
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
    int ch;
    int mode (void);
    int quitConfirm(void);
    int showRank (void);
    int mainMenu (void);
    int saveModeFile (void);
    int chooseLevel(void);
    int chooseMap(void);
    int initSideBar(void);
    int printLittleSideBarInfo (void);

    clear();
    initSideBar();
    printLittleSideBarInfo();
    gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2);
    printw("===============主菜单===============");
    gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+1);
    printw("                模式");
    gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+2);
    printw("                地图");
    gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+3);
    printw("                难度");
    gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+4);
    printw("           -> 开始游戏");
    gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+5);
    printw("               排行榜");
    gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+6);
    printw("                退出");
    gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+7);
    printw("===================================");
    refresh();

    while (1) {
        switch (ch=getch()) {
        case 'w':
        case 'a':
        case KEY_UP:
        case KEY_LEFT:
            opt--;
            if (opt<1)
                opt=ITEM;
            break;
        case 's':
        case 'd':
        case KEY_DOWN:
        case KEY_RIGHT:
            opt++;
            if (opt>ITEM)
                opt=1;
            break;
        case '\n': {
            switch (opt) {
            case 1:
                mode();
                clear();
                initSideBar();
                printLittleSideBarInfo();
                break;
            case 2:
                chooseMap();
                clear();
                initSideBar();
                printLittleSideBarInfo();
                break;
            case 3:
                dfclevel=level=chooseLevel();
                clear();
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
                //MessageBox(NULL,"A error occured in main menu!","ERROR!",MB_OK);
                endwin();
		exit(1);
            }
        }
        }

        switch (opt) {
        case 1:
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2);
            printw("===============主菜单===============");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+1);
            printw("           ->   模式");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+2);
            printw("                地图");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+3);
            printw("                难度");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+4);
            printw("              开始游戏");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+5);
            printw("               排行榜");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+6);
            printw("                退出");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+7);
            printw("===================================");
            refresh();
	    break;
        case 2:
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2);
            printw("===============主菜单===============");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+1);
            printw("                模式");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+2);
            printw("           ->   地图");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+3);
            printw("                难度");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+4);
            printw("              开始游戏");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+5);
            printw("               排行榜");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+6);
            printw("                退出");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+7);
            printw("===================================");
            refresh();
	    break;
        case 3:
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2);
            printw("===============主菜单===============");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+1);
            printw("                模式");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+2);
            printw("                地图");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+3);
            printw("           ->   难度");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+4);
            printw("              开始游戏");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+5);
            printw("               排行榜");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+6);
            printw("                退出");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+7);
            printw("===================================");
            refresh();
	    break;
        case 4:
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2);
            printw("===============主菜单===============");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+1);
            printw("                模式");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+2);
            printw("                地图");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+3);
            printw("                难度");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+4);
            printw("           -> 开始游戏");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+5);
            printw("               排行榜");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+6);
            printw("                退出");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+7);
            printw("===================================");
            refresh();
	    break;
        case 5:
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2);
            printw("===============主菜单===============");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+1);
            printw("                模式");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+2);
            printw("                地图");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+3);
            printw("                难度");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+4);
            printw("              开始游戏");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+5);
            printw("           ->  排行榜");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+6);
            printw("                退出");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+7);
            printw("===================================");
            refresh();
	    break;
        case 6:
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2);
            printw("===============主菜单===============");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+1);
            printw("                模式");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+2);
            printw("                地图");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+3);
            printw("                难度");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+4);
            printw("              开始游戏");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+5);
            printw("               排行榜");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+6);
            printw("           ->   退出");
            gotoxy((MAP_X-LEN)/2, (MAP_Y-ITEM-2)/2+7);
            printw("===================================");
	    refresh();
	    break;
        }
    }
}

/** replay the game*/
int replay(void)
{
    int initSideBar(void);
    char ch;
    clear();
    initSideBar();
    gotoxy((MAP_X-28)/2, (MAP_Y-4)/2);
    printw("==========重玩卡关==========");
    gotoxy((MAP_X-28)/2, (MAP_Y-4)/2+1);
    printw("          重玩(Y)");
    gotoxy((MAP_X-28)/2, (MAP_Y-4)/2+2);
    printw("      任意键返回主界面");
    gotoxy((MAP_X-28)/2, (MAP_Y-4)/2+3);
    printw("============================");
    refresh();
    
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
    clear();
    initSideBar();
    gotoxy((MAP_X-28)/2, (MAP_Y-4)/2);
    printw("==========确认退出==========");
    gotoxy((MAP_X-28)/2, (MAP_Y-4)/2+1);
    printw("           退出(Y)");
    gotoxy((MAP_X-28)/2, (MAP_Y-4)/2+2);
    printw("         任意键取消");
    gotoxy((MAP_X-28)/2, (MAP_Y-4)/2+3);
    printw("============================");
    refresh();

    ch=getch();
    if (ch=='y' || ch=='Y') {
    	/*show cursor*/
    	curs_set(1);
        endwin();
	exit(0);
    } else
        return 0;
}

/** choose game's level and return*/
int chooseLevel(void)
{
    int lev=level;
    int ch;
    int initSideBar(void);
    clear();
    initSideBar();

    while (1) {
        switch (lev) {
        case 0:
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2);
            printw("==========选择难度==========");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+1);
            printw("         -> 休闲");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+2);
            printw("            简单");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+3);
            printw("            普通");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+4);
            printw("            困难");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+5);
            printw("============================");
            refresh();
            break;
        case 1:
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2);
            printw("==========选择难度==========");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+1);
            printw("            休闲");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+2);
            printw("         -> 简单");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+3);
            printw("            普通");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+4);
            printw("            困难");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+5);
            printw("============================");
            refresh();
            break;
        case 2:
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2);
            printw("==========选择难度==========");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+1);
            printw("            休闲");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+2);
            printw("            简单");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+3);
            printw("         -> 普通");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+4);
            printw("            困难");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+5);
            printw("============================");
            refresh();
            break;
        case 3:
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2);
            printw("==========选择难度==========");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+1);
            printw("            休闲");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+2);
            printw("            简单");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+3);
            printw("            普通");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+4);
            printw("         -> 困难");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+5);
            printw("============================");
            refresh();
            break;
        }

        switch (ch=getch()) {
        case 'w':
        case 'a':
        case KEY_UP:
        case KEY_LEFT:
            lev--;
            if (lev<0)
                lev=3;
            break;
        case 's':
        case 'd':
        case KEY_DOWN:
        case KEY_RIGHT:
            lev++;
            if (lev>3)
                lev=0;
            break;
        case '\n':
            return lev;
        }

    }
}

/** Choose mode and set "win"*/
int mode (void)
{
    int mod=(win==1?1:2);
    int ch;
    int initSideBar(void);
    int quitConfirm(void);
    int mode (void);
    clear();
    initSideBar();

    while (1) {
        switch (mod) {
        case 1:
            gotoxy((MAP_X-28)/2, (MAP_Y-4)/2);
            printw("==========选择模式==========");
            gotoxy((MAP_X-28)/2, (MAP_Y-4)/2+1);
            printw("         -> 普通");
            gotoxy((MAP_X-28)/2, (MAP_Y-4)/2+2);
            printw("            竞技");
            gotoxy((MAP_X-28)/2, (MAP_Y-4)/2+3);
            printw("============================");
            refresh();
	    break;
        case 2:
            gotoxy((MAP_X-28)/2, (MAP_Y-4)/2);
            printw("==========选择模式==========");
            gotoxy((MAP_X-28)/2, (MAP_Y-4)/2+1);
            printw("            普通");
            gotoxy((MAP_X-28)/2, (MAP_Y-4)/2+2);
            printw("         -> 竞技");
            gotoxy((MAP_X-28)/2, (MAP_Y-4)/2+3);
            printw("============================");
            refresh();
	    break;
        }

        switch (ch=getch()) {
        case 'w':
        case 'a':
        case KEY_UP:
        case KEY_LEFT:
            mod--;
            if (mod<1)
                mod=2;
            break;
        case 's':
        case 'd':
        case KEY_DOWN:
        case KEY_RIGHT:
            mod++;
            if (mod>2)
                mod=1;
            break;
        case '\n':
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
    int ch;
    int initSideBar(void);
    clear();
    initSideBar();

    while (1) {
        switch (mod) {
        case 1:
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2);
            printw("==========选择地图==========");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+1);
            printw("       -> 经典图一");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+2);
            printw("          经典图二");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+3);
            printw("            DBB");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+4);
            printw("         自定义地图");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+5);
            printw("============================");
            refresh();
	    break;
        case 2:
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2);
            printw("==========选择地图==========");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+1);
            printw("          经典图一");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+2);
            printw("       -> 经典图二");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+3);
            printw("            DBB");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+4);
            printw("         自定义地图");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+5);
            printw("============================");
            refresh();
	    break;
        case 3:
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2);
            printw("==========选择地图==========");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+1);
            printw("          经典图一");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+2);
            printw("          经典图二");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+3);
            printw("       ->   DBB");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+4);
            printw("         自定义地图");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+5);
            printw("============================");
            refresh();
	    break;
        case 4:
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2);
            printw("==========选择地图==========");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+1);
            printw("          经典图一");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+2);
            printw("          经典图二");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+3);
            printw("            DBB");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+4);
            printw("       ->自定义地图");
            gotoxy((MAP_X-28)/2, (MAP_Y-6)/2+5);
            printw("============================");
            refresh();
	    break;
        }

        switch (ch=getch()) {
        case 'w':
        case 'a':
        case KEY_UP:
        case KEY_LEFT:
            mod--;
            if (mod<1)
                mod=4;
            break;
        case 's':
        case 'd':
        case KEY_DOWN:
        case KEY_RIGHT:
            mod++;
            if (mod>4)
                mod=1;
            break;
        case '\n':
            mapNo=mod;
            setMap(mod);
            return 0;
        }

    }

    return 0;
}
