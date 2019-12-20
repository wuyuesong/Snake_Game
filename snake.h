/*
 *Establish snake using One-way linked list
 *This file including functions that set up and delete the linked list
 *v0.2.0
 *By SDUST weilinfox
 */

/** definition of strscore*/
typedef struct sscr {
    char name[25];
    int dfclevel;
    int score;
    int map;
} strscore;

/** Attribute of snake body node*/
typedef struct body {
    int x, y;
    int direction;
    struct body* next;
} snakeBodyNode;
extern int length;
extern snakeBodyNode* head;
extern snakeBodyNode* tail;

/** Establish a snake*/
snakeBodyNode* newSnake()
{
    snakeBodyNode* addNode(void);
    int i;

    length++;
    head=tail=(snakeBodyNode*)malloc(sizeof(snakeBodyNode));
    tail->next=NULL;
    for (i=1 ; i<5; i++) {
        if (addNode()==NULL) break;
    }

    return tail;
}

/** initialize new snake*/
int initNewSnake(snakeBodyNode* head, int* x, int* y, int* direction)
{
    snakeBodyNode* node=head;
    int i;
    for (i=0; ; i++) {
        node->x=x[i];
        node->y=y[i];
        node->direction=direction[i];
        node=node->next;
        if (node==NULL) {
            break;
        }
    }
    return 0;
}

/** initialize a snake body node*/
int initNode(snakeBodyNode* nodePoint, int x, int y, int dir)
{
    nodePoint->x=x;
    nodePoint->y=y;
    nodePoint->direction=dir;

    return 0;
}

/** add a snake body node*/
snakeBodyNode* addNode(void)
{
    if (tail==NULL) return NULL;
    tail->next=(snakeBodyNode*)malloc(sizeof(snakeBodyNode));
    (tail->next)->next=NULL;
    tail=tail->next;
    length++;

    return tail;
}

/** delete the snake*/
int freeSnake(snakeBodyNode* node)
{
    snakeBodyNode* nodeN;
    while (node!=NULL) {
        nodeN=node->next;
        free(node);
        node=nodeN;
    }
    head=tail=NULL;

    return 0;
}
