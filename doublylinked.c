#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *left, *right;
};
void main()
{
struct node *list=(struct node*)0;
struct node *insert(struct node *,int);
struct node *delete(struct node *,int);
struct node *search(struct node *,int);
void display (struct node *);
struct node *start =(struct node *)0;
int item,opt;
while(1)
{
printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.SEARCH\n5.EXIT\n");
printf("Enter your option:");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("item to insert:");
      scanf("%d",&item);
      start=insert(start,item);
      break;
case 2:printf("item to delete :");
      scanf("%d",&item);
      start=delete(start,item);
      break;
case 3:display(start);
       break;
case 4:printf("item to search:");
       scanf("%d",&item);
       if(search(start,item)==(struct node*)0)
       printf("Not Found");
       else
       printf("Found");
       break;
case 5:exit(0);
}
}
}
//function to insert elements in doubly linked list
struct node *insert(struct node*s,int data)
{
struct node *t;
t=(struct node*)malloc(sizeof(struct node));
t-> data=data;
t->left =(struct node *)0;
t->right=s;
if(s!=0)
s->left=t;
return t;
}
//funcion to display elements in doubly linked list
void display(struct node *s)
{
if(s==0)
{
printf("\n list is empty!\n");
return;}
printf("\n list elements are:\n");
while(s!=0)
{
printf("%d\t",s->data);
s=s->right;
}
printf("\n");
return;
}
//function to search elements 
struct node *search(struct node *s,int data)
{
while(s!=0 && data!=s->data)
s=s->right;
return s;
}
//function to delete elements
struct node *delete(struct node *s,int data)
{
struct node *t;
t=search(s,data);
if(t==0)
printf("Data not found \n");
else 
{
if(t->left==0)
{
s=s->right;
if(t->right!=0)
s->left=0;
}
else
{
t->left->right=t->right;
if(t->right!=0)
t->right->left=t->left;
}
free(t);}
return s;
}
