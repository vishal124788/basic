#include<stdlib.h>
#include<stdio.h>
#include"linkedlist.h"

void printlist(node* head){
    node * temporary =head;

    while(temporary !=NULL){
        printf("%d - ", temporary->value);
    }
    printf("\n");
}

node* create_new_node(int value){
    node *result = (node*)malloc(sizeof(node));
    result->value =value;
    result->next = NULL;
    return result;
}

node* insert_at_head(node **head,node *nodeto_insert){
    nodeto_insert->next = *head;
    *head = nodeto_insert;
    return nodeto_insert;
}

void insert_after_node(node *node_to_insert_after,node* newnode){
    node_to_insert_after->next = newnode;
    newnode->next = node_to_insert_after->next;
}

node* findnode(node *head,int value){
    node* tmp = head;
    while(tmp != NULL){
        if(tmp->value == value) return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

void remove_value(node **head, int value){
    node *tmp = *head;

    if(*head != NULL &&(*head)->value ==value){
        tmp = *head;
        *head = (*head)->next ;
        free(tmp);
    }

    while(tmp != NULL){
        if(tmp->next && tmp->next->value ==value){
            node *result = tmp->next;
            tmp->next = tmp->next->next;
            free(result);
            return;
        }
        tmp = tmp->next;
    }

    return;

}



