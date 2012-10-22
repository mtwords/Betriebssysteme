#include <stdio.h>
#include <stdlib.h>

int main() {
    struct list_item {
      int data;
      struct list_item *next;
    };

    typedef struct list_item list;

    list *item = (list*)malloc(sizeof(list));
    item->data = 54;

    list *item2 = (list*)malloc(sizeof(list));
    item2->data = 99;

    item->next = item2;
}

