#include <stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *sp=NULL;
struct node *push(struct node *,int);
struct node *pop(struct node *,int *);
void display(struct node *);
int search(struct node *,int);
int main()
{
int opt,data,found;
for(;;)
{
printf("\n1.Push\n2.Pop\n3.Display\n4.Search\n5.Exit \n");
printf("Enter your choice:");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("Enter element to insert:");
       scanf("%d",&data);
       sp=push(sp,data);
       break;
case 2:
       if(sp==NULL)
       printf("stack is empty!\n");
       else{
       sp=pop(sp,&data);
       printf("poped element is:%d\n",data);
       }break;
case 3:display(sp);
       break;
case 4:printf("Enter the element to be searched:");
       scanf("%d",&data);
       found=search(sp,data);
       if(found!=0)
       printf("The element is found at position %d\n",found);
       else
       printf("Not found\n");
       break;
case 5:exit(0);
       break;
}
}
return 0;}

//function to insert an element in singly linked list
struct node *push(struct node *p,int data){
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
temp->data=data;
temp->next=sp;
return temp;
}
//function to remove an element from singly linked list
struct node *pop(struct node *sp,int *x){
struct node*temp;
if (sp!=NULL)
{
temp=sp;
*x=sp->data;
sp=sp->next;
free(temp);
}
return sp;}
//function to display an element of singly linked list
void display(struct node *sp)
{
  if(sp==NULL)
  {
  printf("Singly linked list is empty \n");
  return;
  }
  printf("Singly linked list elements are : \n");
  while(sp!=NULL)
  {
  printf("%d\n",sp->data);
  sp=sp->next;
  } 
}
//function to search element in singly linked list
int search(struct node *sp,int data)
{
  int pos=1;
   while(sp!=NULL)
{
   if(sp->data==data)
{
   return pos;
}
   sp=sp->next;
   pos++;
}
return 0;
}
