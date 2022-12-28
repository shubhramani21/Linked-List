#include<stdio.h>
#include<stdlib.h>
#include<iostream>

//these are some basic operation function on linked list. 
struct node
{
    int data;
    struct node *next;
}*head;

void create()
{
    struct node *p=NULL,*last=NULL;
    int val=0,size=0;

    printf("Enter the size of the linked list: ");
    scanf("%d",&size);
    
    for(int i=0;i<size;i++)
    {
        printf("Enter the %d data: ",(i+1));
        scanf("%d",&val);
        //doing the below step to create a head
        if(i==0)
        {
            head=(struct node*)malloc(sizeof(struct node));
            head->data=val;
            head->next=NULL;
            last=head;
        }//now the usual method is used or logic used 
        else
        {
            p=(node*)malloc(sizeof(node));
            p->data=val;
            p->next=NULL;
            last->next=p;
            last=p;
        }

    }   
}
void display()
{
    node *p=head;
    while (p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void insert() 
{
    int pos=0;
    printf("Enter the position you want to insert the data: ");
    scanf("%d",&pos);

    int val=0;
    printf("Enter the data of the new node: ");
    scanf("%d",&val);

    node *p,*t;

    if(pos==0)
    {
        t=(node *)malloc(sizeof(node));
        t->data=val;
        t->next=head;
        head=t;
    }else//(pos>1)
    {
        p=head;
        for(int i=0;i<pos-2 && p!=NULL;i++)
        {
            p=p->next;
        }
        if(p!=NULL)
        {
            t=(node *)malloc(sizeof(node));
            t->data=val;
            t->next=p->next;
            p->next=t;
        }else{
            printf("The following position is not avaliable!!!");
        }
    }

}
int del()
{
    int pos=0,x=0;
    node *p=NULL,*q=NULL;
    printf("Enter the position you want to delete: ");
    scanf("%d",&pos);
    p=head;
    
    if(pos==1)
    {
        head=p->next;
        x=p->data;
        free(p);
    }else
    {
        for(int i=0;i<pos-1 && p!=NULL;i++)
        {
            q=p;
            p=p->next;
        }
        if(p!=NULL)
        {
            q->next=p->next;
            x=p->data;
            free(p);
        }

    }
    return x;
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
                printf("The deleted element is %d\n",del());
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
