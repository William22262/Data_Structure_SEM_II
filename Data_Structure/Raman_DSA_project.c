/* 
* C program to phone directory Using hash table.
* Author : Raman Pandey
* Date : 10/18/2016
* Ref : Data Structure using c and c++ , google.com
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 

 
struct node {
    int key, num;
    char name[100];
    struct node *next;
};
 
struct hash {
    struct node *head;
    int count;
};
struct hash *hash_table = NULL;
int element_num = 0;

struct node * getnode(int , char *, int);

void insert_data(int, char *, int); 
void delete_data(int );
void search_data(int );
void display();

 
int main() 
{
    int n, choice, key, num;

    char name[50];
    printf("Enter the tablesize:\t");
    scanf("%d", &n);
    element_num = n;
    hash_table = (struct hash *) calloc(n, sizeof(struct hash));
    while (1) {
        printf("\n1. Insertion\n2. Deletion\n3. Searching\n4. Display\n5. Exit\n");
        printf("*****************************************************************\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        system("cls");
        switch (choice) {
        case 1:
            printf("Enter the key value:");
            scanf("%d", &key);
            printf("Name:");
            scanf("%s",name);
            printf("Number:");
            scanf("%d", &num);
            insert_data(key, name, num);
            getch();
            break;
 
        case 2:
            printf("Enter the key for delete:");
            scanf("%d", &key);
    
            delete_data(key);
            getch();
			break;
 
        case 3:
            printf("Enter the key to search:");
            scanf("%d", &key);
            search_data(key);
            getch();
			break;
        case 4:
            display();
            getch();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Operation\n");
            break;
        }
    }
    return 0;
}

/*------Function to insert data-------*/
 
void insert_data(int key, char *name, int num)
 {
    int hash_index = key % element_num;
    struct node *newnode = getnode(key, name, num);
    if (!hash_table[hash_index].head)
	 {
        hash_table[hash_index].head = newnode;
        hash_table[hash_index].count = 1;
        return;
     }
    
    newnode->next = (hash_table[hash_index].head);
    hash_table[hash_index].head = newnode;
    hash_table[hash_index].count++;
    return;
 }
 
 /*------Function to create new node-------*/
 struct node * getnode(int key, char *name, int num) 
 {
    struct node *newnode;
    newnode = (struct node *) malloc(sizeof(struct node));
    newnode->key = key;
    newnode->num = num;
    strcpy(newnode->name, name);
    newnode->next = NULL;
    return newnode;
  }

/*------Function to delete data-------*/

void delete_data(int key)
 {
    int hash_index = key % element_num, flag = 0;
    struct node *temp, *myNode;
    myNode = hash_table[hash_index].head;
    if (!myNode) {
        printf("Data not found in Table!!\n");
        return;
    }
    temp = myNode;
    while (myNode != NULL) {
    
        if (myNode->key == key) {
            flag = 1;
            if (myNode == hash_table[hash_index].head)
                hash_table[hash_index].head = myNode->next;
            else
                temp->next = myNode->next;
 
            hash_table[hash_index].count--;
            free(myNode);
            break;
        }
        temp = myNode;
        myNode = myNode->next;
    }
    if (flag==1)
        printf("Data deleted from Table\n");
    else
        printf("Data not found in Table!!\n");
    return;
 }

 /*------Function to create new node-------*/

void search_data(int key) 
{
    int hash_index = key % element_num, flag = 0;
    struct node *myNode;
    myNode = hash_table[hash_index].head;
    if (!myNode) {
        printf("Element not found in Table!\n");
        return;
    }
    while (myNode != NULL) {
        if (myNode->key == key) {
            printf("ID    : %d\n", myNode->key);
            printf("Name  : %s\n", myNode->name);
            printf("Number: %d\n", myNode->num);
            flag = 1;
            break;
        }
        myNode = myNode->next;
    }
    if (!flag)
        printf("Element not found in Table!\n");
    return;
}

/*------Function to display record-------*/

void display() 
{
    struct node *myNode;
    int i;
    for (i = 0; i < element_num; i++) {
        if (hash_table[i].count == 0)
            continue;
        myNode = hash_table[i].head;
        if (!myNode)
            continue;
        printf("\nData at index %d in Hash Table:\n", i);
        printf("ID\t Name\t Number   \n");
        while (myNode != NULL) {
            printf("%d\t", myNode->key);
            printf("%s\t", myNode->name);
            printf("%d\n", myNode->num);
            myNode = myNode->next;
        }
    }
    return;
}
