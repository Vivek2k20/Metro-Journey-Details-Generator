#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<iostream.h>
#include<iomanip.h>

int i,gps,gpd,s,d,card;
float tcost;
void displaygreen(int n)
{
	switch(n)
	{
		case 1:printf("Yelechenahalli\n");break;
		case 2:printf("J.P Nagar\n");break;
		case 3:printf("Banashankari\n");break;
		case 4:printf("R.V Road\n");break;
		case 5:printf("Jayanagar\n");break;
		case 6:printf("South End Circle\n");break;
		case 7:printf("Lalbagh\n");break;
		case 8:printf("National College\n");break;
        case 9:printf("K.R Market\n");break;
        case 10:printf("Chikpete\n");break;
        case 11:printf("Majestic\n");break;
        case 12:printf("Mantri Square\n");break;
        case 13:printf("Srirampura\n");break;
        case 14:printf("MahakaviKuvempu Road\n");break;
        case 15:printf("Rajajinagar\n");break;
        case 16:printf("Mahalakshmi\n");break;
        case 17:printf("Sandal Soap Factory\n");break;
        case 18:printf("Yeshwanthpur\n");break;
        case 19:printf("Gorguntepalya\n");break;
        case 20:printf("Peenya\n");break;
        case 21:printf("Peenya Industry\n");break;
        case 22:printf("Jalahalli\n");break;
        case 23:printf("Dasarahalli\n");break;
        case 24:printf("Nagasandra\n");break;
   };
}
void displaypurple(int n)
{
	switch(n)
	{
		case 1:printf("Baiyyapanahalli\n");break;
		case 2:printf("Swami Vivekananda Road\n");break;
		case 3:printf("Indiranagar\n");break;
		case 4:printf("Halasuru\n");break;
		case 5:printf("Trinity\n");break;
		case 6:printf("M.G Road\n");break;
		case 7:printf("Cubbon Park\n");break;
		case 8:printf("VidhanaSoudha\n");break;
        case 9:printf("Sir.M.Vishveshwaraih/Central College\n");break;
        case 10:printf("Majestic\n");break;
        case 11:printf("City Railway Station\n");break;
        case 12:printf("Magadi Road\n");break;
        case 13:printf("Hosahalli\n");break;
        case 14:printf("Vijayanagar\n");break;
        case 15:printf("Attiguppe\n");break;
        case 16:printf("Deepanjali Nagar\n");break;
        case 17:printf("Mysore Road\n");break;
		
	};
}


 void displayall(int a)
 { if(a==1)
   {
   for(i=1;i<=24;i++)
   {
   printf("%d.",i);
   displaygreen(i);
   }
   else
   {
   for(i=1;i<=17;i++)
   {
   printf("%d.",i);
   displaypurple(i);
   };
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
return(fabs(s-d);
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
 int v;
 if(gps==gpd)
 {
   v=(s>d)?-1:1;
   for(i=s;i!=(d+v);i=i+v)
   {
    if(gps==1)
    displaygreen(i);
    else displaypurple(i);
    };
   }
  else if(gps==1)
  {  
    v=(s>11)?-1:1;
    for(i=s;i!=11+v;i=i+v)
    displaygreen(i);
    v=(10>d)?-1:1;
    for(i=10+v;i!=(d+v);i=i+v)
    displaypurple(i);
   }
   else
   { v=(s>10)?-1:1;
     for(i=s;i!=10+v;i=i+v)
     displaypurple(i);
     v=(11>d)?-1:1;
     for(i=11+v;i!=d+v;i=i+v)
     displaygreen(i);
    };
 }
 
 int time()
 { return(2*count());
 }
 
 void main()
 {  int ch;
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
               printf("No. of stations : %d\n",count());
               printf("Cost : %f\n",tcost);
               printf("Estimated Time of Travel : %d mins\n",time());
               getch();
               break;
        case 4:exit(0);
        default:printf("Invalid Choice\n");getch();
       };
      };
     }