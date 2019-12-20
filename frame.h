/*
 *Functions that set and print the frame
 *Including maps and side bar
 *By SDUST weilinfox
 */

#include "defines.h"

extern char map[MAP_Y][MAP_X];
extern char frame[MAP_Y][MAP_X];
extern int level;
extern int step;
extern int foodX, foodY;
extern int foodF;
/** play mode 0:never win*/
extern int win;
/** map no*/
extern int mapNo;
/** difficult level*/
extern int dfclevel;
/** Speed level*/
extern int level;
/** play time*/
extern clock_t runtime;

/** relocate cursor*/
int gotoxy(int x, int y)
{
    /*use gotoxy(1,1); instead of system("cls");
     *avoid flashing, the left top corner is (1, 1)
     */
	COORD pos;
	pos.X = x - 1;
	pos.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);

	return 0;
}

/** get a frame*/
int getFrame (char frame[][MAP_X], char map[][MAP_X], snakeBodyNode* node)
{
    int i, j;

    memset(frame, 0, sizeof(char)*MAP_X*MAP_Y);
    for (i=0; i<MAP_Y; i++) {
        for (j=0; j<MAP_X; j++) {
            if (map[i][j])
                frame[i][j]=map[i][j];
        }
    }
    while (node!=NULL) {
        if (node==head) {
            frame[node->y][node->x]='@';
        } else {
            frame[node->y][node->x]='+';
        }
        node=node->next;
    }

    return 0;
}

/** print frame*/
int printFrame (char frame[][MAP_X])
{
    /*refresh partly to avoid stutter*/
    int gotoxy(int, int);
    int i, j;
    int x=head->x, y=head->y;
    int x1=head->x, y1=head->y;
    snakeBodyNode* node=head->next;
    while (node!=NULL) {
        if (node->x<x)
            x=node->x;
        if (node->y<y)
            y=node->y;
        if (node->x>x1)
            x1=node->x;
        if (node->y>y1)
            y1=node->y;
        node=node->next;
    }
    for (i=(y-1<0?0:y-1); i<=(y1+1>MAP_Y-1?MAP_Y-1:y1+1); i++) {
        gotoxy(x<1?1:x, i+1);
        for (j=(x-1<0?0:x-1); j<=(x1+1>MAP_X-1?MAP_X-1:x1+1); j++) {
            putchar(frame[i][j]);
        }
    }

    /*gotoxy(1, MAP_Y);
    printf(" %d %d %d %d", (x-1<0?0:x-1), (x1+1>MAP_X-1?MAP_X-1:x1+1), (y-1<0?0:y-1), (y1+1>MAP_Y-1?MAP_Y-1:y1+1));
    getch();*/

    return 0;
}

/** time to fresh the screen*/
int timeToGo (void)
{
    static int prelength=5;
    if (length-prelength>=18 && level<5) {
        prelength=length;
        level+=step;
        /*printf("   %d", level);*/
    }
    if (level>4)
        return 5;
    else
        return (int)(FRAME_MSECOND-level*10);
}

/** get a new food*/
int getFood (void)
{
    int f=1;
    while (f) {
        foodX=rand()%MAP_X;
        foodY=rand()%MAP_Y;
        /*if food's location is not well*/
        if (!map[foodY][foodX])
            f=0;
    }

    return 0;
}

/** make food flashing*/
int foodPrint (int mSecond)
{
    if (mSecond>=FOOD_MSECOND)
        return 1;
    else
        return 0;
}

int initSideBar(void)
{
    int gotoxy(int, int);
    int i;
    for (i=2; i<MAP_Y; i++) {
        gotoxy(MAP_X+2, i);
        putchar('$');
    }

    gotoxy(MAP_X+4, 3);
    printf("Time: ");
    gotoxy(MAP_X+4, 5);
    printf("Level: ");
    gotoxy(MAP_X+4, 7);
    printf("Speed: ");
    gotoxy(MAP_X+4, 9);
    printf("Map: ");
    gotoxy(MAP_X+4, 11);
    printf("Mode: ");
    gotoxy(MAP_X+4, 13);
    printf("Score: ");

    gotoxy(MAP_X+4, 28);
    printf("Control:");
    gotoxy(MAP_X+4, 30);
    printf("     W");
    gotoxy(MAP_X+4, 31);
    printf("   A S D");
    gotoxy(MAP_X+4, 33);
    printf("     ¡ü");
    gotoxy(MAP_X+4, 34);
    printf("  ¡û ¡ý ¡ú");
    gotoxy(MAP_X+4, 36);
    printf("Press Q to");
    gotoxy(MAP_X+4, 37);
    printf("quit or pulse");
    gotoxy(MAP_X+4, 38);
    printf("while gaming");

    return 0;
}

int printSideBarInfo (void)
{
    gotoxy(MAP_X+12, 3);
    printf("%d s   ", (int)((clock()-runtime)/CLOCKS_PER_SEC));
    gotoxy(MAP_X+12, 5);
    printf("%d", dfclevel);
    gotoxy(MAP_X+12, 7);
    printf("%d", level);
    gotoxy(MAP_X+12, 9);
    printf("%d", mapNo);
    gotoxy(MAP_X+12, 11);
    if (win)
        printf("Common");
    else
        printf("Compete");
    gotoxy(MAP_X+12, 13);
        printf("%d", (length-5)*2);

        return 0;
}
