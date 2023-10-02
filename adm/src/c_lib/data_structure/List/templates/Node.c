#include <stdlib.h>

struct node{
    int key;
};


int NODE_GET_DATA( struct node *no )
{
    return no->key;
}
