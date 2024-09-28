#include <iostream>

using namespace std;

// create list use linked list
struct node
{
    int data;
    struct node *link;
    // node *link;
};

node *A;
A = NULL;

// create a memory block to store node
node *temp = (node *)malloc(sizeof(node));
// node *temp = new node();
(*temp).data = 2;
// temp->data = 2;
(*temp).link = NULL;
// temp->link = NULL;
A = temp;

temp = new node();
// temp = (node *)malloc(sizeof(node))
temp->link = NULL;

// liked list:insert a node at beginning
#include <iostream>
#include <stdio.h>
struct node
{
    int data;
    struct node *next; // to store address of next node
}
// create a value to store the address of first node
struct node *head; // we declare it as a global value
void insert(int x)
{
    node *temp = (node *)malloc(sizeof(struct node)); // malloc return a pointer to the memory block,which is empty
    (*temp).data = x;
    // eq to temp -> data = x
    temp->next = NULL;
};
void print();
int main()
{
    head = NULL; // initialize head to NULL,empty list
    printf("how many numbers?\n");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("enter the number\n");
        scanf("%d", &x);
        insert(x);
        print();
    }
}