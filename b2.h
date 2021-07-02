#include<iostream>
#include<conio.h>
#include<iomanip>
#include<string.h>
#include<stdio.h>
#include<cstdlib>
#include<ctime>

using namespace std;

void timepu(int a[],char f[])
{
	int i=0,j=0,cc=0;
	char c[5];
	while(f[i]!=0)
	{
		c[0]=0,c[1]=0;
		while(f[i]!='/'&&f[i]!=0)
		{
			c[j]=f[i];
			i++;j++;
		}
		c[4]=0;
		a[cc]=atoi(c);
		j=0;cc++;i++;
	}
	
}

int leap(int a)
{
	if(a%100==0)
	a=(a%400==0)?29:28;
	else
	a=(a%4==0)?29:28;
	return a;
}

int datecomp(char dt[])
{
	int d[12]={31,28,31,30,31,30,31,31,30,31,30,31},a[3],n=0,i,j,f=0;
	timepu(a,dt);
	d[1]=leap(a[2]);
	time_t now = time(0);
	tm *ltm = localtime(&now);
	if(1+ltm->tm_mon==a[1]&&1900+ltm->tm_year==a[2])
	{
		n=ltm->tm_mday-a[0];return n;
	} 
		i=a[1]%12,j=a[2];
		n=n+ltm->tm_mday+d[a[1]-1]-a[0];
		while(1)
		{
			if(j==0)
			break;
			if((i)%12==1&&i>1)
			{
				j++;
				d[1]=leap(1900+ltm->tm_year);
			}
			n=n+d[i%12];
			if((((i%12+1)==1+ltm->tm_mon)&&((j)==1900+ltm->tm_year)))
			break;
			i++;
		}
		return n;
	
}

void timeup(int a,int b,int c,char f[])
{
	char u[5];
	for(int i=0;i<12;i++)
	f[i]=0;
	itoa(a,u,10);strcat(f,u);strcat(f,"/");
	itoa(b,u,10);strcat(f,u);strcat(f,"/");
	itoa(c,u,10);strcat(f,u);
}

int checkpass(char b[],int cl=4)
{
    char j[cl];
    cout<<"Enter your pin password: ";
    for(int i=0;i<cl;i++)
    {
        ck:
		j[i]=getch();
		if(!(j[i]<=57&&j[i]>=48))
		{
			goto ck;
		}
        cout<<"*";
    }
    if(!(strcmp(j,b)))
        return 1;
    else
        return 0;
}

void pass(char b[])
{
    int f=1;
    pss:
    if(f!=1)
    cout<<"\nPassword not matched-\nAgain ";
    cout<<"enter your new four pin password: ";
    for(int i=0;i<4;i++)
    {
        ps:
		b[i]=getch();
		if(!(b[i]<=57&&b[i]>=48))
		{
			goto ps;
		}
		fflush(stdin);
        cout<<"*";
    }
    b[4]=0;
    cout<<"\nRe-";
    f=checkpass(b);
    if(f==0)
    goto pss;

}

void histup(char q[][30],char tme[][30],char ntm[][10],char w[][10],int a,int s,int d,int f,char id[])
{
   int i,j;char t[10];
   for(i=0;i<10;i++)
   {
	   if(w[i][0]==0)
        break;
   }
   time_t tt;
    struct tm * ti;
    time (&tt);
    ti = localtime(&tt);
   if(i!=0)
   {
        if(i==10)
		i--;
       for(j=i;j>0;j--)
       {
		 strcpy(q[j],q[j-1]);
		 strcpy(tme[j],tme[j-1]);
		 strcpy(w[j],w[j-1]);
         strcpy(ntm[j],ntm[j-1]);
       }
   }
                   strcpy(tme[0],asctime(ti));
                   tme[0][24]=tme[0][27];itoa(s,t,10);
                   strcpy(w[0],t);itoa(d,t,10);
                   strcpy(ntm[0],t);
     
       if(a==1)
           {
               if((f/10)==1||f==1)
               {
                   if(f==10)
                   {
                   	strcpy(q[0],"Trf to ");
                   	strcat(q[0],id);
                   	strcat(q[0]," from sav");
				   }
				   else
				   strcpy(q[0],"Withdrawl from saving");
               }
               else
               {
                   if(f==20)
                   {
                   	strcpy(q[0],"Trf to ");
                   	strcat(q[0],id);
                   	strcat(q[0]," from cur");
				   }
				   else
				   strcpy(q[0],"Withdrawl from current");
               }
           }
           else if(a==3)
           {
           	      if(f==1)
				   strcpy(q[0],"Withdrawl for FD from sav");
               else 
				   strcpy(q[0],"Withdrawl for FD from cur");
		   }
		   else if(a==4)
           {
				   strcpy(q[0],"Dep from FD to curr acc");
		   }
		   else if(a==5)
		   {
		   	       strcpy(q[0],"Dep by bank intrst to sav");
		   }
		   else if(a==6)
		   {
		   	       strcpy(q[0],"Dep from RD to curr acc");
		   }
		   else if(a==7)
		   {
		   	       if(f==1)
				   strcpy(q[0],"Withdrawl for RD from sav");
                   else 
				   strcpy(q[0],"Withdrawl for RD from cur");
		   }
           else
           {
               if((f/10)==1||f==1)
               {
                   if(f==10)

                   {
                   	strcpy(q[0],"Dep from ");
                   	strcat(q[0],id);
                   	strcat(q[0]," to sav");
				   }
				   else
				   strcpy(q[0],"Deposit to saving acc");
               }
               else
               {
                   if(f==20)
                   {
                   	strcpy(q[0],"Dep from ");
                   	strcat(q[0],id);
                   	strcat(q[0]," to cur");
				   }
				   else
				   strcpy(q[0],"Deposit to current acc");
               }
           }

}

int checkname(string a,char b[])
{
	int j=0;
	for(int i=0;i<a.size();i++)
	{
		if(a.at(i)!=b[j])
		return 0;
		j++;
	}
	return 1;

}
 
 void fdup(char fdd[],char fdt[])
 {
 	int l;char u[6];
 	fdp:
 	cout<<"Enter no. of days :- ";
 	cin>>l;
 	if(l<=0)
 	{
	 cout<<"Invalid choice\nRe-";goto fdp;
	}
	time_t now = time(0);
	tm *ltm = localtime(&now);
	timeup(ltm->tm_mday,1+ltm->tm_mon,1900+ltm->tm_year,fdt);
	itoa(l,fdd,10);
	cout<<endl<<endl;
 }

void rdup(char rda[],char rdd[],char rdn[],char rdt[])
{
	int a,t,n;
	a1:
	cout<<"Enter amount to be deposited :- ";
	cin>>a;
	if(a<=30)
	{
		cout<<"Amount should be greater than 30\nRe-";
		goto a1;
	}
	t1:
	cout<<"Enter time period for each deposit :- ";
	cin>>t;
	if(t<=0)
	{
		cout<<"Time period should be greater than 0\nRe-";
		goto t1;
	}
	n1:
	cout<<"Enter no. of times to be deposited :- ";
	cin>>n;
	if(n<=1)
	{
		cout<<"No. of deposits should be greater than 1\nRe-";
		goto n1;
	}
	itoa(a,rda,10);
	itoa(t,rdd,10);
	itoa(n,rdn,10);
}

int datecheck(int &a,int &b,int &c,int d)
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	if(d==1)
	{
		if(a==ltm->tm_mday&&b==1+ltm->tm_mon&&c==1900+ltm->tm_year)
		return 1;
		else 
		return 0;
	}
	a=ltm->tm_mday;b=1+ltm->tm_mon;c=1900+ltm->tm_year;
	
}




