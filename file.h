/*
 *Edit files
 *v0.2.0
 *By SDUST weilinfox
 */

#include "defines.h"

extern char map[MAP_Y][MAP_X];
/** Speed level*/
extern int level;
/** difficult level*/
extern int dfclevel;
/** play mode 0:never win*/
extern int win;
/** map no*/
extern int mapNo;
/** scores*/
extern strscore score[5];


/** Read mode file: snakeMode.conf
  * and init some variables*/
 int readModeFile (void)
 {
     int firstLoad(void);
     FILE* filePnt=NULL;

     filePnt=fopen("snakeMode.conf", "r");
     if (filePnt==NULL) {
        /*first load*/
        firstLoad();

        filePnt=fopen("myMap.txt", "w");
        if (filePnt==NULL) {
            MessageBox(NULL,"Fail to establish map file!","ERROR!",MB_OK);
            exit(1);
        }
        fclose(filePnt);
        filePnt=fopen("score.log", "w");
        if (filePnt==NULL) {
            MessageBox(NULL,"Fail to establish log file!","ERROR!",MB_OK);
            exit(1);
        }
        fprintf(filePnt, "NULL 0 0 0\nNULL 0 0 0\nNULL 0 0 0\nNULL 0 0 0\nNULL 0 0 0\n");
        fclose(filePnt);

        filePnt=fopen("snakeMode.conf", "w");
        if (filePnt==NULL) {
            MessageBox(NULL,"Fail to establish configure file!","ERROR!",MB_OK);
            exit(1);
        }
        fprintf(filePnt, "[mode] 1\n[map] 1\n[level] 2\n");

        /*set variables*/
        win=1;
        setMap(mapNo=1);
        dfclevel=level=2;

        fclose(filePnt);
        filePnt=NULL;
     } else {
        if (fscanf(filePnt, "[mode]%d\n[map]%d\n[level]%d", &win, &mapNo, &dfclevel)!=3) {
            MessageBox(NULL,"Read configure file error!\n Please delete the configure file.","ERROR!",MB_OK);
            exit(1);
        }
        setMap(mapNo);
        level=dfclevel;

        fclose(filePnt);
        filePnt=NULL;
     }

     return 0;
 }

/** Save mode file: snakeMode.conf*/
int saveModeFile (void)
{
    FILE* filePnt=NULL;

    filePnt=fopen("snakeMode.conf", "w");
    if (filePnt==NULL) {
        MessageBox(NULL,"Fail to write configure file!","ERROR!",MB_OK);
        exit(1);
    }
    fprintf(filePnt, "[mode] %d\n[map] %d\n[level] %d\n", win, mapNo, dfclevel);

    fclose(filePnt);
    filePnt=NULL;

    return 0;
}

/** Read map file: myMap.txt
  * and init map[][]*/
int readMapFile (void)
{
    FILE* filePnt=NULL;
    int i, j;
    char ch;

    filePnt=fopen("myMap.txt", "r");
    if (filePnt==NULL) {
        MessageBox(NULL,"Fail to load map file!\nIt will now be established.","Attention!",MB_OK);
        filePnt=fopen("myMap.txt", "w");
        filePnt=freopen("myMap.txt", "r", filePnt);
        if (filePnt==NULL) {
            MessageBox(NULL,"Fail to establish map file!","ERROR!",MB_OK);
            exit(1);
        }
    }

    for (i=0; i<MAP_Y; i++) {
        for (j=0; j<MAP_X; j++) {
            ch=fgetc(filePnt);
            if (ch=='\n') {
                break;
            } else if (ch==EOF) {
                break;
            } else {
                map[i][j]=ch;
            }
        }
        if (ch==EOF)
            break;
    }

    fclose(filePnt);
    filePnt=NULL;

    return 0;
}

/** Read log file: score.log
  * and init score{}*/
int readLogFile (void)
{
    FILE* filePnt=NULL;
    int i;

    filePnt=fopen("score.log", "r");
    if (filePnt==NULL) {
        MessageBox(NULL,"Fail to load log file!\nIt will now be established.","Attention!",MB_OK);
        filePnt=fopen("score.log", "w");
        if (filePnt==NULL) {
            MessageBox(NULL,"Fail to establish log file!","ERROR!",MB_OK);
            exit(1);
        }
        fprintf(filePnt, "NULL 0 0 0\nNULL 0 0 0\nNULL 0 0 0\nNULL 0 0 0\nNULL 0 0 0\n");
        filePnt=freopen("score.log", "r", filePnt);
        if (filePnt==NULL) {
            MessageBox(NULL,"Fail to read log file!","ERROR!",MB_OK);
            exit(1);
        }
    }

    for (i=0; i<5; i++) {
        if (fscanf(filePnt, "%s%d%d%d", score[i].name, &score[i].dfclevel, &score[i].score, &score[i].map)!=4) {
            MessageBox(NULL,"Read log file error!\n Please delete the log file.","ERROR!",MB_OK);
            exit(1);
        }
    }

    fclose(filePnt);
    filePnt=NULL;

    return 0;
}

/** Save log file: score.log*/
int saveLogFile (void)
{
    FILE* filePnt=NULL;
    int i;

    filePnt=fopen("score.log", "w");
    if (filePnt==NULL) {
        MessageBox(NULL,"Fail to write log file!","ERROR!",MB_OK);
        exit(1);
    }
    for (i=0; i<5; i++) {
        fprintf(filePnt, "%s %d %d %d\n", score[i].name, score[i].dfclevel, score[i].score, score[i].map);
    }

    fclose(filePnt);
    filePnt=NULL;

    return 0;
}
