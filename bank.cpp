#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<cstdlib>
#include<fstream>
#include<iomanip>
#include"b1.h"

using namespace std;

int main()
{
    int n,f=0,sz=0;
	bank a1,a2,a3;
	admin1 ad;
    fstream f1;
    f1.open("bank.dat",ios::in|ios::out|ios::ate);
    if(f1==0)
    {
       f1.open("bank.dat",ios::out);f1.close();
       f1.open("bank.dat",ios::in|ios::out|ios::ate); 
    }
    
    
    start:
    
    cout<<"                                               Welcome to GEU bank\n\n\n\n";
    f1.seekg(0,ios::beg);
    while(f1.read((char*)&a3,sizeof(a3)))
    {
   	sz=f1.tellg();
   	interest(a3);
    f1.seekp(sz-sizeof(a3),ios::beg);
    f1.write((char*)&a3,sizeof(a3));
    f1.clear();
    f1.seekg(sz,ios::beg);
	}
	f1.clear();
	time_t now = time(0);
	tm *ltm = localtime(&now);
	int dd=ltm->tm_mday,mm=1+ltm->tm_mon,yy=1900+ltm->tm_year;
	start1:
	cout<<"                                                                                    TODAY :- "<<dd<<"/"<<mm<<"/"<<yy<<endl;
    cout<<"Enter your choice-\n=====================================================================================\n1 for create account\n2 for login\n3 for admin login\n4 for refresh\n0 for exit\n";
    cin>>n;
    if(n==0)
        goto b1;
    if(n==1)
    {
		a1.in();
        f=0;
        e11:
            f1.seekg(0,ios::beg);
        while(f1.read((char*)&a2,sizeof(a2)))
        {
            if(!strcmp(a2.q,a1.q))
                {f=1;break;}
        }
        f1.clear();
        if(f==1)
        {
            int m;
			cout<<"\nId matched\n";
			idc:
		    cout<<"Do you want to continue process : \n1 for Yes                2 for No\n";
		    cin>>m;
		    if(m==2)
		    {
			   cout<<"\n                                         Id not created\n\n\n";
	    	   goto b2;
			}
		    else if(m!=1)
		    {
		       	cout<<"Invalid choice\n";goto idc;
			}
			cout<<"Re-enter new id : ";
			cin>>a1.q;
			f=0;
			goto e11;
        }
        f1.seekp(0,ios::end);
        f1.write((char*)&a1,sizeof(a1));
        cout<<"\n                                         Id successfully created\n";
	    goto b2;
    }
	else if(n==4)
    {
    	if(datecheck(dd,mm,yy,1))
    	{
    		cout<<"\nAlready refreshed\n\n";
			cout<<"Press any key to continue...";
		    getch();
		    system("cls");
		    cout<<"                                               Welcome to GEU bank\n\n\n\n";
		    goto start1;
		}
		else
		{
		    cout<<endl<<endl;
		    datecheck(dd,mm,yy,2);
    		goto b2;
		}
	}
    else if(n==2)
    {
       char id[20];
       f=0;
       cout<<"\nLogin-\nEnter id no. : ";
       cin>>id;
       f1.seekg(0,ios::beg);
       while(f1.read((char*)&a2,sizeof(a2)))
        {
            if(!strcmp(id,a2.q))
                {
					f=1;
					sz=f1.tellg();
					sz=sz-sizeof(a2);
					break;
				}
        }
        f1.clear();
        
       if(f==0)
        {
		cout<<"Id doesn't exist\n\n";
		f1.clear();
	    goto b2;
		}
       else
       {
         f=checkpass(a2.b);
         if(f!=1)
         {
            cout<<"\n\n                                   Login unsuccessful\n\n";
			f=0;
			f1.clear();
	        goto b2;
         }
         system("cls");
       }

    }
    else if(n==3)
    {
    	f=ad.in();
    	if(f==1)
    	{
    		f=0;goto b2;
		}
		admin:
		cout<<"\n                                                                                    TODAY :- "<<dd<<"/"<<mm<<"/"<<yy<<endl;
		cout<<"\n\nEnter your choice-\n=====================================================================================\n";
	    cout<<"1 to view all accounts                                                  2 to delete a account \n\n";
	    cout<<"3 to view or open accounts by id                                        4 to view accounts by name\n\n";
	    cout<<"5 to view total amount in bank                                          6 to back\n\n";
	    cout<<"7 for exit\n\n";
	    cin>>n;

	    if(n==7)
	    {
	    	cout<<"\n\n                               Admin logout successful\n\n\n";
	    	goto b1;
		}
		else if(n==6)
		{
			cout<<"\n\n                               Admin logout successful\n\n\n";
	    	goto b2;
		}
		else if(n==5)
		{
			int sv=0,cr=0,e,w;
			f1.seekg(0,ios::beg);
	       while(f1.read((char*)&a1,sizeof(a1)))
	        {
	            e=atoi(a1.es);
	            w=atoi(a1.ws);
				sv=sv+e;
	            cr=cr+w;
	        }
	        f1.clear();
	        cout<<"\nTotal amount in savings account = "<<sv<<endl;
	        cout<<"\nTotal amount in current account = "<<cr<<endl<<endl<<endl;
	        goto admin;
		}
		else if(n==3)
		{
			adv:
			int m;
			cout<<"Enter \n1 to view account\n2 open account\n";
			cin>>m;
			if(m!=1&&m!=2)
		{
			cout<<"Invalid choice\n";
			goto adv;
		}
		else if(m==1)
		{
			ad.vid();
			goto admin;
		}
		else
		{
			char id[20];
	       f=0;
	       cout<<"\nLogin-\nEnter id no. : ";
	       cin>>id;
	       f1.seekg(0,ios::beg);
	       while(f1.read((char*)&a2,sizeof(a2)))
	        {
	            if(!strcmp(id,a2.q))
	                {
						f=1;
						sz=f1.tellg();
						sz=sz-sizeof(a2);
						break;
					}
	        }
	        f1.clear();
	        
	       if(f==0)
	        {
			cout<<"Id doesn't exist\n\n";
			f1.clear();
		    goto admin;
			}
	       else
	       {
	            cout<<"\n\n                                   Login successful\n\n";
	            goto e2;
	       }
		}
		
		}
		else if(n==1)
		{
			ad.vaac();
			goto admin;
		}
		else if(n==4)
		{
			ad.vaan();
			goto admin;
		}
		else if(n==2)
		{
			ad.delid();
			goto admin;
		}
		else
		{
			cout<<"invalid choice\n\n";
			goto admin;
		}

	}
    else if(n==0)
        goto b1;
    else
    {
	cout<<"invalid choice\n\n";
	goto b2;
	}

    e2:
    	cout<<"\n\n\n                       You are Logged in "<<a2.a<<endl<<endl<<endl;
    	rdw(a2);
    	f1.seekp(sz,ios::beg);
		f1.write((char*)&a2,sizeof(a2));
		f1.clear();
    cout<<"                                                                                    TODAY :- "<<dd<<"/"<<mm<<"/"<<yy<<endl;
    cout<<"\n\nEnter your choice-\n=====================================================================================\n";
    cout<<"1 for edit profile                                                        2 for cash withdrawl \n\n";
    cout<<"3 for cash deposit                                                        4 for account details\n\n";
    cout<<"5 for transaction history                                                 6 for money transfer to other id  \n\n";
    cout<<"7 for deposits                                                            8 to go back\n\n";
    cout<<"9 for exit\n\n";
    cin>>n;
    if(n==8)
        {
			cout<<"\n\n                                   Logout successful\n\n";
			goto b2;
		}
	else if(n==7)
	{
		d1:
			int m;
			cout<<"Enter \n1 for fixed deposits\n2 for recurrence deposits\n3 to go back\n";
			cin>>m;
			if(m!=1&&m!=2&&m!=3)
		{
			cout<<"Invalid choice\n";
			goto d1;
		}
		else if(m==1)
		{
			fd(a2);
			f1.seekp(sz,ios::beg);
			f1.write((char*)&a2,sizeof(a2));
		    f1.clear();
       }
		else if(m==2)
		{
			rd(a2);
			f1.seekp(sz,ios::beg);
			f1.write((char*)&a2,sizeof(a2));
			f1.clear();
		}
		else
		goto b3;
		goto b3;
	}
    else if(n==6)
    {
    	a2.wdrw(1);
        
        f1.seekp(sz,ios::beg);
		f1.write((char*)&a2,sizeof(a2));
		f1.clear();
        goto b3;
	}
    else if(n==9)
        {
        	cout<<"\n\n                                   Logout successful\n\n\n\n\n\n";
			goto b1;
		}
    else if(n==1)
    {
    int t;
    f=0;
	cout<<"Enter your name: ";fflush(stdin);
    cin.getline(a2.a,30);
    fflush(stdin);
    cout<<"Enter age : ";cin>>a2.ag;
    pass(a2.b);
    e21:
    cout<<"\n\nDo you want to Update ID-\n\n";
    cout<<"1 for Yes                   2 for No\n\n";
    cin>>t;
    if(t==2)
    {
    	goto b11;
	}
	else if(t!=1)
	{
		cout<<"\n\nInvalid choice\n";
		goto e21;
	}
    cout<<"Enter account id : ";cin>>a2.q;
            f1.seekg(0,ios::beg);
        while(f1.read((char*)&a1,sizeof(a1)))
        {
			if(!strcmp(a2.q,a1.q))
                {f=1;break;}
        }
        f1.clear();
        if(f==1)
        {
            cout<<"\nId matched\n";f=0;goto e21;
        }
        b11:
    f1.seekp(sz,ios::beg);
    f1.write((char*)&a2,sizeof(a2));
    cout<<"\n\n                                        Profile updated\n\n";goto b3;
    }
    else if(n==2)
    {
        a2.wdrw();
        
        f1.seekp(sz,ios::beg);
		f1.write((char*)&a2,sizeof(a2));
		f1.clear();
        goto b3;
    }
    else if(n==3)
    {
        a2.deposit();
        
        f1.seekp(sz,ios::beg);
		f1.write((char*)&a2,sizeof(a2));
		f1.clear();
        goto b3;
    }
    else if(n==4)
    {
        cout<<"\n\nDetails are-\n";
		a2.out();
        goto b3;
    }
    else if(n==5)
    {
        a2.balhis();
        cout<<"\n\n";
        goto b3;
    }
    else
    {
      cout<<"invalid choice\n\n";
	  goto b3;
    }
    b3:
		cout<<"Press any key to continue...";
		getch();
		system("cls");
	    goto e2;
    b2:
		cout<<"Press any key to continue...";
		getch();
		system("cls");
	    goto start;
    b1:
        cout<<"                                 Thank you for banking\n=====================================================================================\n\n";
        f1.close();
        return(0);
}

