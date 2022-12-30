#include<stdio.h>
#include<iostream>
#include<stdlib.h>

struct node 
{
    node *prev;
    int data;
    node *next;
}*head;


void create()
{
    node *last,*t;
    int n,data;
    printf("Enter the size of the linked list: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the data: ");
        scanf("%d",&data);
        if(i==0)
        {
            head=(node *)malloc(sizeof(node));
            head->data=data;
            head->next=head->prev=NULL;
            last=head;
        }else
        {
            t=(node *)malloc(sizeof(node));
            t->data=data;
            t->next=last->next;
            t->prev=last;
            last->next=t;
            last=t;
        }
    }
}

int length();

void display()
{
    node *p;
    p=head;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void insert()
{
    node *p=head,*t;
    
    int pos=0,x,len=length();

    printf("Enter the positon: ");
    scanf("%d",&pos);

    if(pos<0 || pos >len)
    {
        printf("Enter valid position!!");
        return;
    }

    printf("Enter the data: ");
    scanf("%d",&x);

    if(pos==0)
    {
        t=(node *)malloc(sizeof(node));
        t->data=x;
        t->prev=NULL;
        t->next=head;
        head->prev=t;
        head=t;
    }else
    {
        for(int i=0;i<pos-1;i++)
        {
            p=p->next;
        }
        t=(node *)malloc(sizeof(node));
        t->data=x;

        t->prev=p;
        t->next=p->next;
        if(p->next!=NULL)
        {
            p->next->prev=t;
        }
        p->next=t;
    }
}

void del()
{
    node *p=head,*t;
    
    int pos=0,x,len;
    len=length();

    printf("Enter the positon: ");
    scanf("%d",&pos);

    if(pos<0 || pos >len)
    {
        printf("Enter valid position!!");
        return;
    }

    if(pos==1)
    {
        head=head->next;
        if(head!=NULL)
        {
            head->prev=NULL;
        }
        x=p->data;
        free(p);
    }else
    {
        for(int i=0;i<pos-1;i++)
        {
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next)
        {
            p->next->prev=p->prev;
        }
        x=p->data;
        free(p);
    }
    printf("The deleted data is %d",x);
}

int length()
{
    node *p=head;
    int count=1;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}


int main()
{
    int num=0,a=1,flag=0;
    create();
    printf("\n");
    
    while (a==1)
    {
        printf(" Press 1:for the list display\n Press 2: to insert a node\n Press 3: to delete\n Press 4: to exit\n");
        printf("Press the num: ");
        scanf("%d",&num);
        printf("\n");
        switch (num)
        {
            case 1:
                display();
                break;
            
            case 2:
                insert();
                break;
            
            case 3:
                del();
                break;
            
            case 4:
                printf("GOODBYE!!!\n");
                flag=1;
                break;
            
            default:
                printf("Enter a valid number!!\n");
                break;
        }
        printf("\n");
        if(flag==1)
        {
            break;
        }
    }
    
    
    
    return 0;
}


