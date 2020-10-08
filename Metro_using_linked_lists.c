#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<iostream.h>
#include<iomanip.h>

struct station
{
  int no;
  char name[50];
  int pt;int nt;
  struct station *p;
  struct station *n;
};
typedef struct station node;

node *g;
node *p;

node *getnode()
{
node *newnode;
newnode=(node*)malloc(sizeof(node));
newnode->p=newnode->n=NULL;
return (newnode);
}


node *insert(node *head,int nol,char namel[50],int ptl,int ntl)
{ node *ph;
 ph=head;
 while(ph->n!=NULL)
 ph=ph->n;
 node *h=getnode();
 h->no=nol;
 strcpy(h->name,namel);
 h->pt=ptl;
 h->nt=ntl;
 ph->n=h;
 h->p=ph;
 h->n=NULL;
 return(head);
 }
 
int i,gps,gpd,s,d,card;
float tcost;


void displaystation(int n,int gp)
{
node *head;
if(gp==1)
head=g;
else head=p;
while(head->no!=n)
head=head->n;
printf("%s\n",head->name);
}


void initialize()
{
g=insert(g,1,"Yelchenahalli",0,2);
g=insert(g,2,"JP Nagar",2,2);
g=insert(g,3,"Banashankari",2,2);
g=insert(g,4,"RV Road",2,2);
g=insert(g,5,"Jayanagar",2,2);
g=insert(g,6,"South End Circle",2,2);
g=insert(g,7,"Lalbagh",2,1);
g=insert(g,8,"National College",1,2);
g=insert(g,9,"KR Market",2,2);
g=insert(g,10,"Chikpete",2,2);
g=insert(g,11,"Majestic",2,3);
g=insert(g,12,"Mantri Square",3,2);
g=insert(g,13,"Srirampura",2,1);
g=insert(g,14,"Mahakavi Kuvempu Road",1,1);
g=insert(g,15,"Rajajinagar",1,2);
g=insert(g,16,"Mahalakshmi",2,2);
g=insert(g,17,"Sandal Soap Factory",2,2);
g=insert(g,18,"Yeshwantpur",2,2);
g=insert(g,19,"Gorguntepalya",2,2);
g=insert(g,20,"Peenya",2,1);
g=insert(g,21,"Peenya Industry",1,1);
g=insert(g,22,"Jalahalli",1,2);
g=insert(g,23,"Dasarahalli",2,2);
g=insert(g,24,"Nagasandra",2,0);

p=insert(p,1,"Baiyyapanahalli",0,2);
p=insert(p,2,"Swami Vivekananda Road",2,2);
p=insert(p,3,"Indiranagar",2,2);
p=insert(p,4,"Halasuru",2,2);
p=insert(p,5,"Trinity",2,2);
p=insert(p,6,"MG Road",2,2);
p=insert(p,7,"Cubbon Park",2,1);
p=insert(p,8,"Vidhana Soudha/Dr.B.R Ambedkar Station",1,2);
p=insert(p,9,"Sir.M.Vishveshwaraiah/Central College",2,2);
p=insert(p,10,"Majestic",2,1);
p=insert(p,11,"City Railway Station",1,2);
p=insert(p,12,"Magadi Road",2,2);
p=insert(p,13,"Hosahalli",2,2);
p=insert(p,14,"Vijayanagar",2,2);
p=insert(p,15,"Attiguppe",2,2);
p=insert(p,16,"Deepanjali Nagar",2,2);
p=insert(p,17,"Mysore Road",2,0);

}


 void displayall(int a)
{ int n;
 if(a==1)
  n=24;
 else n=17;
 for(i=1;i<=n;i++)
 {
  printf("%d.",i);
  displaystation(i,a);
  };
}


void inp()
{ 
printf("Enter Starting Station :\n1.Green Line\n2.Purple Line\nEnter your choice :\n");
scanf("%d",&gps);
displayall(gps);
printf("Enter Station :\n");
scanf("%d",&s);
printf("\n\nEnter Destination :\n1.Green Line\n2.Purple Line\nEnter your choice :\n");
scanf("%d",&gpd);
displayall(gpd);
printf("Enter Station :\n");
scanf("%d",&d);
printf("Do you have a smart card?\n1.Yes\n2.No\nEnter choice :\n");
scanf("%d",&card);
}

int count()
{
if(gps==gpd)
return(fabs(s-d));
else if(gps==1)
return (fabs(11-s)+fabs(10-d));
else return (fabs(10-s)+fabs(11-d));
}


void cost()
{
tcost=10;
if(count()>2)
tcost=tcost+(2.5*count());
if(card==1)
tcost=tcost-(0.15*tcost);
}

void path()
{
node *trav;
 
   if(gps==gpd)
   { 
     trav=(gps==1)?g:p;
     if(s>d)
     { 
      while(trav->no!=s)
      trav=trav->n;
      while(trav->no!=d-1)
      {
       printf("%d.%s\n",trav->no,trav->name);
       trav=trav->p;
       };
      }
      else 
      { 
       while(trav->no!=s)
       trav=trav->n;
       while(trav->no!=d+1)
       {
        printf("%d.%s\n",trav->no,trav->name);
        trav=trav->n;
        };
        };
     }
     else
     {
      trav=(gps==1)?g:p;
      while(trav->no!=s)
      trav=trav->n;
      if(s<((gps==1)?11:10))
      { 
        while(trav->no!=((gps==1)?11:10))
        {
         printf("%d.%s\n",trav->no,trav->name);
         trav=trav->n;
         };
       }
       else
       {  
         while(trav->no!=((gps==1)?11:10))
         {
          printf("%d.%s\n",trav->no,trav->name);
          trav=trav->p;
          };
         };
        trav=((gps==1)?p:g);
        while(trav->no!=((gps==1)?10:11))
        trav=trav->n;
        if(d>((gps==1)?10:11))
        {
          while(trav->no!=d+1)
          {
           printf("%d.%s\n",trav->no,trav->name);
           trav=trav->n;
           };
         }
         else 
          {
           while(trav->no!=d-1)
           {
            printf("%d.%s\n",trav->no,trav->name);
            trav=trav->p;
           };
          };

 };
 }
 
 int time()
 {int t;node *trav;t=0;
 
   if(gps==gpd)
   { trav=(gps==1)?g:p;
     if(s>d)
     { 
      while(trav->no!=s)
      trav=trav->n;
      while(trav->no!=d)
      {
       t=t+(trav->pt);
       trav=trav->p;
       };
       return t;
      }
      else 
      { 
       while(trav->no!=s)
       trav=trav->n;
       while(trav->no!=d)
       {
        t=t+(trav->nt);
        trav=trav->n;
        };
        return t;
        };
     }
     else
     {
      trav=((gps==1)?g:p);
      while(trav->no!=s)
      trav=trav->n;
      if(s<((gps==1)?11:10))
      { 
        while(trav->no!=((gps==1)?11:10))
        {
         t=t+trav->nt;
         trav=trav->n;
         };
       }
       else
       {  
         while(trav->no!=((gps==1)?11:10))
         {
          t=t+trav->pt;
          trav=trav->p;
          };
         };
        trav=((gps==1)?p:g);
        while(trav->no!=((gps==1)?10:11))
        trav=trav->n;
        if(d>((gps==1)?10:11))
        {
          while(trav->no!=d)
          {
           t=t+trav->nt;
           trav=trav->n;
           };
           return t;
         }
         else 
          {
           while(trav->no!=d)
           {
            t=t+trav->pt;
            trav=trav->p;
           };
           return t;
          };
 };
 }
 
 void main()
 {  int ch;
 g=getnode();
 p=getnode();
 initialize();
    while(1)
    {
      printf("----MENU----\n\n1.Display Green Line\n2.Display Purple Line\n3.Generate Journey Details\n4.Exit\nEnter You Choice :\n");
      scanf("%d",&ch);
      switch(ch)
      {
        case 1:displayall(1);getch();break;
        case 2:displayall(2);getch();break;
        case 3:inp();
               if(gps!=gpd)
               printf("Change Trains at Majestic\n");
               printf("Stations between start and end stations :\n");
               path();cost();
               printf("No. of stations : %d\n",((s==d)?0:count()-1));
               printf("Cost : %f\n",tcost);
               printf("Estimated Time of Travel : %d mins\n",time());
               getch();
               break;
        case 4:exit(0);
        default:printf("Invalid Choice\n");getch();
       };
      };
     }