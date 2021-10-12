#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// progrsam to List
typedef struct node{
    int value;
    struct node *next;  
    //struct treenode *right;
}node;

void printlist(node *head);
node* create_new_node(int value);
node* insert_at_head(node **head,node *node_to_insert);
void insert_after_node(node *node_to_insert_after,node* newnode);
node *findnode(node *head,int value);
void remove_value(node **head , int value);

#endif