#ifndef LIST_H
#define LIST_H

    #define MAX_LEN 4

    typedef struct list List;
    typedef struct node Node;
    typedef int boolean;

    List* LIST_NEW();
    boolean LIST_IS_FULL(List *li);
    boolean LIST_IS_EMPTY(List *li);
    Node *LIST_GET(List *li, int i);
    void LIST_FREE(List *li);
    int LIST_LEN(List *li);
    int LIST_INSERT_END(List *li, Node *no);
    int LIST_INSERT_BEGIN(List *li, Node *no);
    int LIST_ORDER_INSERT(List *li, Node *no);
    int LIST_REMOVE_END(List *li);
    int LIST_REMOVE(List *li, int key);
    int LIST_REMOVE_INDEX(List *li, int i);

#endif
