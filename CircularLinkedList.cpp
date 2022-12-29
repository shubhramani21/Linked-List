#include<stdio.h>
#include<iostream>
#include<stdlib.h>

//these are some basic operation function on circular linked list. 

struct node
{
    int data;
    node *next;
}*head;

void create()
{
    int i=0,data=0,n=0;
    node *t=NULL, *last=NULL;
    printf("Enter the number of linked list:");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter the data: ");
        scanf("%d",&data);
        if(i==0)
        {
            head=(node *)malloc(sizeof(node));
            head->data=data;
            head->next=head;
            last=head;
        }
        else
        {
            t=(node *)malloc(sizeof(node));
            t->data=data;
            t->next=last->next;
            last->next=t;
            last=t;
        }
    }
}

void display()
{
    node *p=NULL;
    p=head;
    do
    {
        printf("%d ",p->data);
        p=p->next;
    }while(p!=head);
    printf("\n");
}

void insert()
{
    node *t,*p;
    int i,pos;

    printf("Enter the position: ");
    scanf("%d",&pos);

    int data;
    printf("Enter the data: ");
    scanf("%d",&data);

    if(pos==1)
    {
        t=(node *)malloc(sizeof(node));
        t->data=data;
        if(head==NULL)
        {
            head=t;
            head->next=head;
        }
        else
        {
            p=head;
            while (p->next!=head)
            {
                p=p->next;
            }
            t->next=head;
            p->next=t;
            head=t;
        }
    }
    else
    {
        p=head;
        for(int i=0;i<pos-2;i++)
        {
            p=p->next;
        }
        t=(node *)malloc(sizeof(node));
        t->data=data;
        t->next=p->next;
        p->next=t;

    }
}

void del()
{
    node *p,*t,*q;
    int pos,x;
    printf("Enter the position you want to delete: ");
    scanf("%d",&pos);

    if(pos==1)
    {
        p=head;
        while (p->next!=head)
        {
            p=p->next;
        }
        if(p==head)
        {
            x=head->data;
            free(head);
            head=NULL;
        }
        else
        {
            p->next=head->next;
            x=head->data;
            free(head);
            head=p->next;
        }
    }else
    {
        p=head;
        for(int i=1;i<pos-1;i++)
        {
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        free(q);    
    }
    printf("The deleted elment is %d\n",x);
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
