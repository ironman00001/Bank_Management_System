#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<cstdlib>
#include<iomanip>
#include<stdio.h>
#include<string.h>
#include"b2.h"

using namespace std;


class bank
{   
public:
	char a[30],b[5],idc[30];
	char ws[10],es[10],esa[10],est[3],hsis[10][10],ntms[10][10];
    char hs[10][30],tme[10][30];
    char q[20],ag[3];
    char fda[10],fdd[10],fdt[13];
	char rda[10],rdd[10],rdt[13],rdap[10],rdn[10],rdnp[10];
    
		
	void in()
{
    for(int i=0;i<30;i++)
		{
			a[i]=' ';
			idc[i]=0;
			if(i<20)
			q[i]=0;
			if(i<10)
			{
				ws[i]=0;
				es[i]=0;rdnp[i]=0;
				esa[i]=0;
				fdd[i]=0;rda[i]=0;
				fda[i]=0;rdd[i]=0;
				rdd[i]=0;rdt[i]=0;
				rdn[i]=0;rdap[i]=0;
				idc[i]=0;rdn[i]=0;
			}
			if(i<13)
			{
				fdt[i]=0;
				rdt[i]=0;
			}
			if(i<3)
			{
				est[i]=0;
				ag[i]=0;
			}
		}
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
				hsis[i][j]=0;
				ntms[i][j]=0;
			}
			for(int j=0;j<30;j++)
			{
				hs[i][j]=0;
				tme[i][j]=0;
			}
		}
		itoa(0,rda,10);
		itoa(0,rdnp,10);
		itoa(0,rdap,10);
		itoa(0,fda,10);
	int w,e;
	cout<<"Enter your name :- ";fflush(stdin);
    cin.getline(a,30);
    fflush(stdin);
    cout<<"Enter age :- ";cin>>ag;
    cout<<"Enter account id of max 13 digit:- ";
	fflush(stdin);
	cin>>q; 
    pass(b);
    w=50;e=50;
    cout<<"\nBalance amount for saving account :-  "<<w<<endl;
    cout<<"Balance amount for current account :-  "<<e<<endl<<endl;
    itoa(w,ws,10);
    itoa(0,fda,10);
    itoa(0,rdnp,10);
    itoa(0,rda,10);
    itoa(e,es,10);
    strcpy(esa,es);
    time_t now = time(0);
	tm *ltm = localtime(&now);
	itoa(ltm->tm_mday,est,10);
	strcpy(idc,asctime(ltm));
	idc[24]=idc[27];
}

   
   void out()
{
    cout<<"Account id :-  "<<q<<endl;
	cout<<"Customer name :- "<<a<<endl;
    cout<<"Customer age :- "<<ag<<endl;
    cout<<"Account created on :- "<<idc<<endl;
    cout<<"Balance amount of savings account :-  "<<es<<endl;
    cout<<"Balance amount of current account :-  "<<ws<<endl<<endl;
}


   void deposit(int t=0)
   {
       int l,k=1,w,e;
       char id[2];
       e=atoi(es);
       w=atoi(ws);
       if(t==0)
	   {
		   cout<<endl<<endl<<"Customer name: "<<a<<endl;
	       d1:
	       cout<<"Enter account type for deposit \n";
	       cout<<"1 for saving\n2 for current"<<endl;
	       cin>>k;
	       if(k!=1&&k!=2)
	       {
	       	cout<<"Invalid choice\n\nRe-";
	       	goto d1;
		   }
	       if(k==1)
	       	{
		       cout<<"Previous balance of saving account :"<<e<<endl;
		       cout<<"Enter amount to deposit : ";
		       cin>>l;
		       if(l<=10)
		       {
		       	cout<<"Deposit amount should be greater than 10\n\n";goto dp1;
			   }
		       e=e+l;
		       cout<<"Total balance of saving account : "<<e<<endl<<endl;
		       histup(hs,tme,ntms,hsis,2,l,e,k,id);
		    }
		   else
		   	{
		       cout<<"Previous balance of current :"<<w<<endl;
		       cout<<"Enter amount to deposit : ";
		       cin>>l;
		       if(l<=10)
		       {
		       	cout<<"Deposit amount should be greater than 10\n\n";goto dp1;
			   }
		       w=w+l;
		       cout<<"Total balance of current account : "<<w<<endl<<endl;
		       histup(hs,tme,ntms,hsis,2,l,w,k,id);
		    }
      	}
	    itoa(w,ws,10);
        itoa(e,es,10);
	    dp1:
	    	cout<<" ";
   }

   void wdrw(int t=0)
   {
        char id[20];
   	    bank a2;
		fstream f1; 
	    int l,k,m,f=0,c=0,n,w,e,w1,e1,esa1=atoi(esa),rda1=atoi(rda),rdap1=atoi(rdap);
	    e=atoi(es);
        w=atoi(ws);
	    if(t==1)
	   {
	   	 f1.open("bank.dat",ios::in); 
	   	 f1.seekg(0,ios::beg);
	   	 while(f1.read((char*)&a2,sizeof(a2)))
	   	 c++;
	   	 f1.clear();
	   	 f1.seekg(0,ios::beg);
	   }
       cout<<endl<<endl<<"Customer name: "<<a<<endl;
       w11:
       	if(t==3)
       	cout<<"Enter account type for withdrawl fixed deposit\n";
       	else if(t==4)
       	cout<<"Enter account type for for withdrawl recurrence deposit\n";
       	else
       cout<<"Enter account type for withdrawl \n";
       cout<<"1 for savings account\n2 for current account"<<endl;
       cin>>k;
       if(k!=1&&k!=2)
       {
       	cout<<"Invalid choice\n\nRe-";
       	goto w11;
	   }
       if(k==1)
       {
       cout<<"Previous balance of saving account :"<<e;
	   wd2:
       cout<<"\nDo you want to continue : \n1 for Yes                2 for No\n";
       cin>>m;
       if(m==2)
       {
	   cout<<"\n                                         Transaction unsuccessful\n";
	   goto wd1;
	   }
       else if(m!=1)
       {
       	 cout<<"Invalid choice";goto wd2;
	   }
	   if(t==3)
	   cout<<"Enter amount to withdrawl greater than amount 10 for fixed deposit : ";
	   else if(t==4)
	   {
	   	if(rda1+20<=e)
    	{
	   	   	l=rda1;
	   	   	goto rd1;
		}
	   	else
	   	cout<<"\nNo enough amount and min. balance should be greater than 20\n\n";
	   	return;
	   }
	   else
       cout<<"Enter amount to withdrawl greater than amount 10 : ";
       cin>>l;
       if(l<=10||(e-l)<20)
       {
       	cout<<"Transaction should be greater than 10 and min. balance should be 20";
		   cout<<"\n                                         Transaction unsuccessful\n";
		   goto wd1;
	   }
	   if(t==1)
	   {
	   	   	cout<<"Enter id to transfer amount :- ";
        	cin>>id;
			while(f1.read((char*)&a2,sizeof(a2)))
            {
                if(!strcmp(a2.q,id)&&strcmp(q,id))
                {f=1;e1=atoi(a2.es);w1=atoi(a2.ws);break;}
	        }
	        f1.clear();
	        if(f==0)
	        {
	            cout<<"\nId dosen't exist\n\n ";cout<<"\n                                         Transaction unsuccessful\n";goto wd1;
	        }
	   }
         if(t==1)
           {
           	w4:
			cout<<"Enter transfer account's id type - \n";
           	cout<<"1 for savings account\n2 for current account"<<endl;
            cin>>n;
            
            if(n!=1&&n!=2)
		       {
		       	cout<<"Invalid choice\n\nRe-";
		       	goto w4;
			   }
			if(n==1)
			{
				e1=e1+l;
				histup(a2.hs,a2.tme,a2.ntms,a2.hsis,2,l,e1,n*10,q);
				itoa(e1,a2.es,10);
			}
			else
			{
				w1=w1+l;
				histup(a2.hs,a2.tme,a2.ntms,a2.hsis,2,l,w1,n*10,q);
				itoa(w1,a2.ws,10);
			}
	        histup(hs,tme,ntms,hsis,1,l,e-l,k*10,id);
		   }
		   else if(t==4)
		   {
		   	rd1:
		   	itoa(rdap1+l,rdap,10);	
		   	histup(hs,tme,ntms,hsis,7,l,e-l,k,id);
		   }
		   else if(t==3)
		   {
		   	itoa(l,fda,10);
		   	histup(hs,tme,ntms,hsis,3,l,e-l,k,id);
		   }
		   else
           histup(hs,tme,ntms,hsis,1,l,e-l,k,id);
		 cout<<"Balance of saving account : "<<e-l<<endl;
           e=e-l;
           if(esa1>e)
           {
           	esa1=e;
           	itoa(esa1,esa,10);
		   }
	   }
	   else
	   {
	   cout<<"Previous balance of current account :"<<w;
	   wd3:
       cout<<"\nDo you want to continue : \n1 for Yes                2 for No\n";
       cin>>m;
       if(m==2)
       goto wd1;
       else if(m!=1)
       {
       	 cout<<"Invalid choice";goto wd3;
	   }
	   if(t==3)
	   cout<<"Enter amount to withdrawl greater than amount 10 for fixed deposit : ";
	   else if(t==4)
	   {
	   	if(rda1+20<=w)
    	{
	   	   	l=rda1;
	   	   	goto rd2;
		}
	   	else
	   	cout<<"\nNo enough amount and min. balance should be greater than 20\n\n";
	   	return;
	   }
	   else
       cout<<"Enter amount to withdrawl greater than amount 10 : ";
       cin>>l;
       if(l<=10||(w-l)<20)
       {
       	cout<<"Transaction should be greater than 10 and min. balance should be 20";goto wd1;
	   }
	   if(t==1)
	   {
	   	    cout<<"Enter id to transfer amount :- ";
        	cin>>id;
			while(f1.read((char*)&a2,sizeof(a2)))
            {
            if(!strcmp(a2.q,id)&&strcmp(q,id))
                {f=1;e1=atoi(a2.es);w1=atoi(a2.ws);break;}
	        }
	        f1.clear();
	        if(f==0)
	        {
	            cout<<"\nId dosen't exist\n\n ";cout<<"\n                                         Transaction unsuccessful\n";goto wd1;
	        }
	   }
           if(t==1)
           {
           	w5:
	    	cout<<"Enter transfer account's id type - \n";
           	cout<<"1 for savings account\n2 for current account"<<endl;
            cin>>n;
            if(n!=1&&n!=2)
		       {
		       	cout<<"Invalid choice\n\nRe-";
		       	goto w5;
			   }
			if(n==1)
			{
				e1=e1+l;
				histup(a2.hs,a2.tme,a2.ntms,a2.hsis,2,l,e1,n*10,q);
				itoa(e1,a2.es,10);
			}
			else
			{
                w1=w1+l;
				histup(a2.hs,a2.tme,a2.ntms,a2.hsis,2,l,w1,n*10,q);
				itoa(w1,a2.ws,10);
			}
	        histup(hs,tme,ntms,hsis,1,l,w-l,k*10,id);
		   }
		   else if(t==4)
		   {
		   	rd2:
		   	itoa(rdap1+l,rdap,10);	
		   	histup(hs,tme,ntms,hsis,7,l,w-l,k,id);
		   }
		   else if(t==3)
		   {
		   	itoa(l,fda,10);
		   	histup(hs,tme,ntms,hsis,3,l,w-l,k,id);
		   }
		   else
           histup(hs,tme,ntms,hsis,1,l,w-l,k,id);
           cout<<"Balance of current account : "<<w-l<<endl;
           w=w-l;
	   }
		   
	   cout<<"\n                                         Transaction successful\n";
	   if(t==1)
		   {
		   	bank b[c];
		   	f1.clear();
		   	f1.seekg(0,ios::beg);
		   	for(int i=0;i<c;i++)
		   	f1.read((char*)&b[i],sizeof(b[i]));
		   	f1.close();
		   	f1.open("bank.dat",ios::out);
			for(int i=0;i<c;i++)
			{
				if(!strcmp(b[i].q,a2.q))
				f1.write((char*)&a2,sizeof(a2));
				else
				f1.write((char*)&b[i],sizeof(b[i]));
			}
		    f1.close();		  
		    }
	   wd1:
	    cout<<endl<<endl;
	    itoa(w,ws,10);
        itoa(e,es,10);
   }
   
   ~bank()
   {
   	
   }

   void balhis();
   
};


void bank::balhis()
{
   if(hsis[0][0]==0)
    cout<<"\nEmpty transaction history\n\n";
    else
    {
        cout<<"\n\n        ==================================================================================================\n";
        cout<<"         "<<"       Type of transaction    "<<"   |"<<"  Trs amount"<<"  |"<<"  Net amount"<<"  |"<<"          Date and time      " <<"   "<<endl;
        cout<<"        ==================================================================================================\n";
        for(int i=0;i<10;i++)
      {
          if(hsis[i][0]==0)
          break;
            cout<<"       "<<setw(31)<<hs[i]<<"    |"<<setw(12)<<hsis[i]<<"  |"<<setw(12)<<ntms[i]<<"  |"<<setw(30)<<tme[i]<<endl;
      }
        cout<<"        ==================================================================================================\n\n\n";

    }
}

void interest(bank &a)
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	char id[2];
	int b=atoi(a.est),e=atoi(a.es),fda1=atoi(a.fda),rdap1=atoi(a.rdap),rdnp1=atoi(a.rdnp),rdn1=atoi(a.rdn),rdd1=atoi(a.rdd);
	if(b!=ltm->tm_mday)
	{
		if((float(e)/100.0*10.0)>0)
		histup(a.hs,a.tme,a.ntms,a.hsis,5,float(e)/100.0*10.0,e+float(e)/100.0*10.0,1,id);
		e=e+float(e)/100.0*10.0;                                                               
		itoa(ltm->tm_mday,a.est,10);
		itoa(e,a.es,10);
		strcpy(a.esa,a.es);
	}
	
	b=atoi(a.fdd);e=atoi(a.ws);
	if(fda1>0&&a.fdt[0]!=0&&b<datecomp(a.fdt))
	{
		e=e+fda1+(fda1*b)/100.0;
		histup(a.hs,a.tme,a.ntms,a.hsis,4,fda1+(fda1*b)/100,e,2,id);
		fda1=-1;
		itoa(e,a.ws,10);
		itoa(fda1,a.fda,10);                                                              
	}
	
	if(rdap1>0&&(rdn1==rdnp1||rdd1+1<datecomp(a.rdt)))
	{
		if(rdnp1!=rdn1)
		{
				e=e+(rdap1*12)/100+rdap1;
				histup(a.hs,a.tme,a.ntms,a.hsis,6,rdap1*12/100+rdap1,e,2,id);	
				itoa(-2,a.rdap,10);
		}
		else
		{
		    e=e+(rdap1*25)/100+rdap1+rdn1*2*rdd1;
			histup(a.hs,a.tme,a.ntms,a.hsis,6,(rdap1*25)/100+rdap1+rdn1*2*rdd1,e,2,id);	
			itoa(-1,a.rdap,10);	
		}
		itoa(e,a.ws,10);
		itoa(0,a.rdnp,10);
	}
}

void fd(bank &a2)
{
	int m,tw=atoi(a2.ws),te=atoi(a2.es);
	if(a2.fda[0]==48)
       	{
	       	cout<<"\nNo fixed deposits\n";
	    	m1:
	    	cout<<"Do you want to add fixed deposits :- \n1 for Yes\n2 for No\n";
	    	cin>>m;
			if(m!=1&&m!=2)
			{
				cout<<"Invalid choice\n";
				goto m1;
			}
			else if(m==1)
			{
				a2.wdrw(3);
				int i=atoi(a2.ws),j=atoi(a2.es);
				if(i!=tw||j!=te)
				{
			        fdup(a2.fdd,a2.fdt);
					return;
				}
				cout<<"                  \nDeposit unsuccessful\n\n\n";
				return;	
			}
			else
				return;
		}
			else
			{
				cout<<"\nDeposited amount :- "<<a2.fda<<endl;
				cout<<"Time period  :- "<<a2.fdd<<endl;
				cout<<"Amount deposited on :- "<<a2.fdt<<endl<<endl<<endl;
			}
}

void rd(bank &a2)
{
	int m,te=atoi(a2.rdap),rdd1=atoi(a2.rdd),rdn1=atoi(a2.rdn),rdnp1=atoi(a2.rdnp);
	time_t now = time(0);
	tm *ltm = localtime(&now);
		if(te==0)
	       	{
		       	cout<<"\nNo recurrence deposits\n";
		    	m2:
		    	cout<<"Do you want to create recurrence deposits :- \n1 for Yes\n2 for No\n";
		    	cin>>m;
				if(m!=1&&m!=2)
				{
					cout<<"Invalid choice\n";
					goto m2;
				}
				else if(m==1)
				{
				    rdup(a2.rda,a2.rdd,a2.rdn,a2.rdt);
				    rd1:
					a2.wdrw(4);
					int j=atoi(a2.rdap);
					if(j!=te)
					{
					    cout<<"                  \nDeposit successful\n\n\n";
					    rdnp1++;
					    itoa(rdnp1,a2.rdnp,10);
					    timeup(ltm->tm_mday,1+ltm->tm_mon,1900+ltm->tm_year,a2.rdt);
					    a2.rdt[12]=0;
				        return;
					}
					cout<<"                  \nDeposit unsuccessful\n\n\n";
					return;	
				}
				else
					return;
			}
			else
			{
				cout<<"\nDeposited amount :- "<<a2.rdap<<endl;
				cout<<"Amount to be deposited :- "<<a2.rda<<endl;
				cout<<"Time period  :- "<<rdd1<<endl;
				cout<<"No. of deposits :- "<<rdn1<<endl;
				cout<<"Last amount deposited on :- "<<a2.rdt<<endl<<endl<<endl;
				m3:
	        	cout<<"Enter your choice :- \n1 for cancel RD\n2 to add RD\n3 for to go back\n";
	        	cin>>m;
		    	if(m!=1&&m!=2&&m!=3)
		    	{
			    	cout<<"Invalid choice\n";
			    	goto m3;
		    	}
		    	else if(m==1)
		    	{
		    		int w=atoi(a2.ws);
		    		w=w+te+te*12/100.0;
		    		itoa(w,a2.ws,10);
		    		itoa(0,a2.rdap,10);
		    		itoa(0,a2.rdn,10);
		    		itoa(0,a2.rdnp,10);
		    		histup(a2.hs,a2.tme,a2.ntms,a2.hsis,6,te*12/100.0+te,w,2,a2.rdd);
		    		cout<<"\n                                      Recurrence deposit cancelled    \n ";
				}
				else if(m==2)
				{
					if(rdn1==rdnp1)
					cout<<"\nNo.of deposits exceeded\n\n";
					else if(rdd1>datecomp(a2.rdt))
					cout<<"\nAmount can't be deposited before time\n\n";
					else
					goto rd1;
				}
				cout<<endl;
			}
}
		
void rdw(bank &a2)
{
	int rdd1=atoi(a2.rdd),a11=atoi(a2.rdap),f1=atoi(a2.fda);
    	if(a11>0&&(rdd1==datecomp(a2.rdt)||rdd1+1==datecomp(a2.rdt)))
    	{cout<<"=============================================================================================\n";
		cout<<"WARNING : Its Time for recurrence deposit otherwise it will be cancelled\n";
		cout<<"=============================================================================================\n";
	    }
	    else if(a11==-1)
	    {
	    cout<<"=============================================================================================\n";
		cout<<"NOTICE : Recurrence deposit time completed and amount deposited successfully\n";
		cout<<"=============================================================================================\n";	
		itoa(0,a2.rdap,10);
		}
		else if(a11==-2)
		{
		cout<<"=============================================================================================\n";
		cout<<"NOTICE : Recurrence deposit cancelled due to uncompletion of deposits\n";
		cout<<"=============================================================================================\n";	
		itoa(0,a2.rdap,10);
		}
		if(f1==-1)
		{
		cout<<"=============================================================================================\n";
		cout<<"NOTICE : Fixed deposit time completed and amount deposited successfully\n";
		cout<<"=============================================================================================\n";	
		itoa(0,a2.fda,10);	
		}
}

class admin1
{
	int ai;
	char ap[10];
	public:
		admin1()
		{
			ai=1710141059;
			strcpy(ap,"6403223");
		}

	int in()
	{
		int id,f=0;
       cout<<"\nAdmin login-\nEnter id no. : ";
       cin>>id;
       if(id==ai)
       f=1;
       if(f==0)
        {
		    cout<<"Id doesn't match\n\n";
			return 1;
		}
       else
       {
         f=checkpass(ap,7);
         if(f==1)
            {cout<<"\n\n                               Admin login successful\n\n";return 0;}
         else
         {
            cout<<"\n\n                                Admin login unsuccessful\n\nRe-";return 1;
         }
       }
	}

	void vid()
	{
		fstream f1;
		bank a1;
		int f=0;
    	f1.open("bank.dat",ios::in|ios::out|ios::ate);
    	char id[30];
	    cout<<"\n\nEnter id no. : ";
	    cin>>id;
	    f1.seekg(0,ios::beg);
	    while(1)
	    {
		    f1.read((char*)&a1,sizeof(a1));
		    if(f1==0) 
		       break;
		 if(!strcmp(id,a1.q))
	      {
		       f=1;
			   f1.clear();
			   cout<<"\n\nAccount details are-\nPassword :- "<<a1.b<<endl;
			   a1.out();
			   break;
			}
	    }
	    if(f==0)
	        {
			    cout<<"Id doesn't exist\n\n";
				f1.clear();
			}
	}

	void vaac()
	{
		fstream f1;
		bank a1;
		int f=0;
    	f1.open("bank.dat",ios::in|ios::out|ios::ate);
	    f1.seekg(0,ios::beg);
	    while(1)
	    {
		       fflush(stdin);
		       f1.read((char*)&a1,sizeof(a1));
		       if(f1==0)
		       break;
		       f=1;
			   cout<<"\n\nPassword :- "<<a1.b<<endl;
			   a1.out();
	    }
	    f1.clear();
	    if(f==0)
	        {
			    cout<<"\n\nNone of the accounts are created\n\n\n";
			}
	}

	void vaan()
	{
		fstream f1;
		bank a1;
		int f=0;
    	f1.open("bank.dat",ios::in|ios::out|ios::ate);
    	string at;
	    cout<<"\n\nEnter few alphabets from starting : ";
		fflush(stdin);
	    getline(cin,at);
	    fflush(stdin);
	    f1.seekg(0,ios::beg);
	    while(1)
	    {
		       f1.read((char*)&a1,sizeof(a1));
		       if(f1==0)
		       break;
		 if(checkname(at,a1.a))
	      {
		       f=1;
			   cout<<"\n\nAccount details are-\nPassword :- "<<a1.b<<endl;
			   a1.out();
			}
	    }
	   	f1.clear();
	    if(f==0)
	        {
			    cout<<"Id's doesn't exist by this alphabets\n\n";
			}
	}

	void delid()
	{
		fstream f1;
		int f=0,c=0;
		char id[30];
		bank a1;
		f1.open("bank.dat",ios::in);
		cout<<"Enter id to delete :- ";
		cin>>id;
		f1.seekg(0,ios::beg);
		while(f1.read((char*)&a1,sizeof(a1)))
		{
			if(!strcmp(id,a1.q))
			{
				f=1;
			}
			c++;
		}

		f1.clear();

		if(f==0)
		{
			cout<<"\nId doesn't exist\n\n";
			return;
		}

		bank a2[c];
		f1.seekg(0,ios::beg);

		for(int i=0;i<c;i++)
		{
			f1.read((char*)&a1,sizeof(a1));a2[i]=a1;
		}

		f1.clear();

		f1.close();

		f1.open("bank.dat",ios::out);
		f1.seekp(0,ios::beg);

		for(int i=0;i<c;i++)
		{
			if(strcmp(id,a2[i].q))
			f1.write((char*)&a2[i],sizeof(a1));
		}

		f1.close();
		cout<<"Id  successfully deleted\n\n";

	}

};
