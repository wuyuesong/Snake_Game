/*
 *One-way Listed Link Snake Game v0.1.1
 *Using pure C and some windows API
 *By SDUST weilinfox
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "snake.h"
#include "frame.h"
#include "function.h"

/** Speed level*/
int level=2;
/** difficult level*/
int dfclevel=2;
/** accelerate when get half of the score*/
int step=0;
/** play mode 0:never win*/
int win=1;
/** map no*/
int mapNo=0;
/** play time*/
clock_t runtime=0;

/** Size of the map*/
char map[MAP_Y][MAP_X];
char frame[MAP_Y][MAP_X];

/** Attribute of snake body*/
int length=0;
snakeBodyNode* head=NULL;
snakeBodyNode* tail=NULL;

/** locate and direction of new snake body*/
int xp[6];
int yp[6];
/** up1 down2 left3 right 4*/
int dirp[6];

/** food location*/
int foodX, foodY;
int foodF=0;


int main()
{
    int i, j;
    int countMSecond, foodMSecond, run=1;
    long long playTime=0;
    char ch;

    processStart:
    /*start*/
    init();

    /*setup map and init snake*/
    mode();
    chooseMap();

    dfclevel=level=chooseLevel();

    gameStart:
    system("cls");
    initSideBar();
    run=1;
    playTime=0;
    if (dfclevel==1)
        step=0;
    level=dfclevel;

    /*set snake*/
    length=0;

    newSnake();
    initNewSnake(head, xp, yp, dirp);

    /*init srand*/
    srand((unsigned int)time(0));

    system("color f0");

	gotoxy(1,1);
    getFrame(frame, map, head);
    for (i=0; i<MAP_Y; i++) {
        for (j=0; j<MAP_X; j++) {
            putchar(frame[i][j]);
        }
        putchar('\n');
    }
    runtime=clock();
    printSideBarInfo();
    playTime=0;
    countMSecond=foodMSecond=0;
    /*waiting for start*/
    ch=getch();
    switch (ch) {
    case 'w':
    case 'W':
    case 72:
        head->direction=1;
        break;
    case 's':
    case 'S':
    case 80:
        head->direction=2;
        break;
    case 'a':
    case 'A':
    case 75:
        head->direction=3;
        break;
    case 'd':
    case 'D':
    case 77:
        head->direction=4;
        break;
    }
    runtime=clock();
    getFood();

    /*int firstPrintSideBarInfo=1;*/
    while (run) {
        if (kbhit()) {
            ch=getch();
            switch (ch) {
            case 'w':
            case 'W':
            case 72:
                head->direction=1;
                break;
            case 's':
            case 'S':
            case 80:
                head->direction=2;
                break;
            case 'a':
            case 'A':
            case 75:
                head->direction=3;
                break;
            case 'd':
            case 'D':
            case 77:
                head->direction=4;
                break;
            case 'q':
            case 'Q':
                gotoxy(1, MAP_Y+1);
                printf("Quit? (Y)\n\n\n\n\n");
                if ((ch=getch())=='y' || ch=='Y')
                    goto processStart;
                else {
                    system("cls");
                    for (i=0; i<MAP_Y; i++) {
                        for (j=0; j<MAP_X; j++) {
                            putchar(frame[i][j]);
                        }
                        putchar('\n');
                    }
                    initSideBar();
                    printSideBarInfo();
                }
                break;
            }
            ch=0;
        }
        playTime++;
        countMSecond++;
        foodMSecond++;

        if (playTime%200==0) {
            printSideBarInfo();
            /*runtime=clock();*/
        }

        /*time to next frame?*/
        if (countMSecond>=timeToGo()) {
            snakeBodyNode* node=head->next;
            int tx, ty, td;
            int pdir=head->direction;
            int px=head->x, py=head->y;
            switch (head->direction) {
            case 1:
                head->y--;
                if (head->y<0)
                    head->y=MAP_Y-1;
                break;
            case 2:
                head->y++;
                if (head->y>=MAP_Y)
                    head->y=0;
                break;
            case 3:
                head->x--;
                if (head->x<0)
                    head->x=MAP_X-1;
                break;
            case 4:
                head->x++;
                if (head->x>=MAP_X)
                    head->x=0;
                break;
            default:
                MessageBox(NULL,"Undefined direction at running!","ERROR!",MB_OK);
                exit(1);
            }
            while (node!=NULL) {
                tx=node->x;
                ty=node->y;
                td=node->direction;
                node->x=px;
                node->y=py;
                node->direction=pdir;
                px=tx;
                py=ty;
                pdir=td;

                node=node->next;
            }

            /*judge if game over*/
            if (judge()) {
                run=0;
                continue;
            } else {
                /*system("cls");*/
                gotoxy(1, 1);
                getFrame(frame, map, head);
                printFrame(frame);
                countMSecond=0;
                if (foodF) {
                    gotoxy(foodX+1, foodY+1);
                    putchar('*');
                }
            }
        }
        /*print food*/
        if (foodPrint(foodMSecond)) {
            /*system("cls");*/
            gotoxy(foodX+1, foodY+1);
            if (foodF) {
                putchar('*');
                foodF=!foodF;
            } else {
                putchar(' ');
                foodF=!foodF;
            }

            foodMSecond=0;
        }

        /*eat food*/
        if (head->x==foodX && head->y==foodY) {
            getFood();

            /*add node*/
            snakeBodyNode* preNode;
            for (i=0; i<3; i++) {
                preNode=tail;
                tail=addNode();
                tail->direction=preNode->direction;
                switch (preNode->direction) {
                case 1:
                    tail->x=preNode->x;
                    tail->y=preNode->y+1;
                    break;
                case 2:
                    tail->x=preNode->x;
                    tail->y=preNode->y-1;
                    break;
                case 3:
                    tail->x=preNode->x+1;
                    tail->y=preNode->y;
                    break;
                case 4:
                    tail->x=preNode->x-1;
                    tail->y=preNode->y;
                    break;
                default:
                    MessageBox(NULL,"Undefined direction at adding node!","ERROR!",MB_OK);
                    exit(1);
                }
            }
            printSideBarInfo();
        }

        /*printf("%lld", playTime);
        printf("\n\n");*/
        Sleep(1);

        if (length>40 && win) {
            system("color 0f");
            gotoxy(1, MAP_Y+1);
            printf("Win!\n\n\n\n\n");
            run=0;
        }
    }

    gotoxy(1, MAP_Y+1);
    if (!run && length<=40) {
        system("color 0f");
        printf("Game over!\n\n\n\n\n");
    } else if (!win) {
        system("color 0f");
        printf("I believe you will make a difference!\n\n\n\n\n");
    }
    Sleep(1500);

    freeSnake(head);

    if (length>40 && win && dfclevel<3) {
        dfclevel++;
        printf("Upgraded!\n\n\n");
        Sleep(500);
        goto gameStart;
    }

    int flag;
    flag=replay();
    if (flag)
        goto gameStart;
    else
        goto processStart;

    return 0;
}
