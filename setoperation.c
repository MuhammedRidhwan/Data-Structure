#include<stdio.h>
#include<stdlib.h>
struct bit{unsigned char x:1;};
int uset[]={0,1,2,3,4,5,6,7,8,9},SIZE=10;
void main()
{
void readset(struct bit[],int n);
void printset(struct bit[]);
void unionset(struct bit[],struct bit[],struct bit[]);
void insertset(struct bit[],struct bit[],struct bit[]);
void difference(struct bit[],struct bit[],struct bit[]);
struct bit a[10]={0},b[10]={0},c[10]={0};
int n;
printf(" NUMBER OF ELEMENTS IN SET A: ");
scanf("%d",&n);
readset(a,n);
printf(" NUMBER OF ELEMENTS IN SET B: ");
scanf("%d",&n);
readset(b,n);
printf(" SET A: ");
printset(a);
printf(" SET B: ");
printset(b);
unionset(a,b,c);
printf(" AUB = ");
printset(c);
insertset(a,b,c);
printf(" A INTERSECTION B = ");
printset(c);
difference(a,b,c);
printf(" A-B = ");
printset(c);
}
//to read a set and store as bit string
void readset(struct bit a[],int n)
{
int i,x,k;
printf("ENTER %d ELEMENT:",n);
for(i=0;i<n;++i)
{
scanf("%d",&x);
for(k=0;k<SIZE;++k)
if(uset[k]==x)
{
a[k].x=1;
break;
}}
return;
}
//to print a set from bit string representation
void printset(struct bit a[])
{
int k;
printf("{");
for(k=0;k<SIZE;++k)
if(a[k].x==1)
printf("%d ",uset[k]);
printf("}\n");
return;
}
//to find union of two sets using bitstring
void unionset(struct bit a[],struct bit b[],struct bit c[])
{
int k;
for(k=0;k<SIZE;++k)
c[k].x=a[k].x|b[k].x;
return;
}
//to find intersection of 2 sets
void insertset(struct bit a[],struct bit b[],struct bit c[])
{
int k;
for(k=0;k<SIZE;++k)
c[k].x=a[k].x&b[k].x;
return;
}
//to find the difference of two sets
void difference(struct bit a[],struct bit b[],struct bit c[])
{
int k;
for(k=0;k<SIZE;++k)
if(a[k].x==1)
c[k].x=a[k].x^b[k].x;
return;
}
