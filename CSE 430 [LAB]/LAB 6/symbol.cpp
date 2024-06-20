#include<bits/stdc++.h>
# include <conio.h>
//# include <alloc.h>
# include <string.h>
# define null 0
int size=0;
void insert();
void del();
int search(char lab[]);
void modify();
void display();
struct symbtab
{
          char label[10];
          int addr;
          struct symbtab *next;
};
struct symbtab *first,*last;
int main()
{
          int op;
          int y;
          char la[10];
          //clrscr();
          do
          {
                   printf("\nSYMBOL TABLE IMPLEMENTATION\n");
                   printf("1. INSERT\n");
                   printf("2. DISPLAY\n");
                   printf("3. DELETE\n");
                   printf("4. SEARCH\n");
                   printf("5. MODIFY\n");
                   printf("6. END\n");
                   printf("Enter your option : ");
                   scanf("%d",&op);
                   switch(op)
                   {
                             case 1:
                             insert();
                             display();
                             break;
                             case 2:
                             display();
                             break;
                             case 6:
                             break;
                   }

          }
          while(op<6);
          getch();
}
void insert()
{
          int n=0;
          char l[10];
          printf("Enter the label : ");
          scanf("%s",l);
          //n=search(l);
          if(n==1)
          {
          printf("The label already exists. Duplicate cant be inserted\n");
          }
          else
          {
                   struct symbtab *p;
                   p=(struct symbtab*)malloc(sizeof(struct symbtab));
                   strcpy(p->label,l);
                   printf("Enter the address : ");
                   scanf("%d",&p->addr);
                   p->next=null;
                   if(size==0)
                   {
                             first=p;
                             last=p;
                   }
                   else
                   {
                             last->next=p;
                             last=p;
                   }
                   size++;
          }

}
void display()
{
          int i;
          struct symbtab *p;
          p=first;
          printf("LABEL\tADDRESS\n");
          for(i=0;i<size;i++)
          {
                   printf("%s\t%d\n",p->label,p->addr);
                    p=p->next;
          }

}
