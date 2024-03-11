#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#include "door_struct.h"

struct node* init(struct door* door) {
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->door = door;
    root->next = NULL;
    return root;
}

struct node* add_door(struct node* elem, struct door* door) {
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp->door = door;
    tmp->next = elem->next;
    elem->next = tmp;
    return tmp;
}
struct node* find_door(struct node* root, int door_id) {
    struct node* res = NULL;
    while (root->next != NULL) {
        if (root->door->id = door_id) {
            res = root;
            break;
        }
        root = root->next;
    }
    if (root->door->id == door_id) {
        res = root;
    }
    return res;
}

struct node* remove_door(struct node* root, struct node* elem) {
    struct node* tmp = root;
    while (root->next != NULL) {
        if (root->next = elem) {
            root->next = elem->next;
            free(elem);
        }
        root = root->next;
    }
    return tmp;
}

void destroy(struct node* root) {
    while (root->next != NULL) {
        struct node* tmp = root;
        root = root->next;
        free(tmp);
    }
    free(root);
}