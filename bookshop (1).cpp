
#include<iostream>
#include<string.h>
using namespace std;

class books
{
public:
	char *author;
	char *title;
	int price;
	char *publisher;
	int stock_position;

books()
{
author=new char[20];
title=new char[20];
publisher=new char[2];  
price=0;
stock_position=0;
}

void add()
{
cout<<"\nenter title";
cin>>title;
cout<<"\nenter auther";
cin>>author;
cout<<"\nEnter price";
cin>>price;
cout<<"\nEnter publisher";
cin>>publisher;
cout<<"\nEnter stock of books";
cin>>stock_position;
}

void disp()
{

cout<<endl<<title<<"\t\t"<<author<<"\t\t"<<price<<"\t\t"<<publisher<<"\t\t "<<stock_position;
}
};

int main()
{
int ch,ch1=1,n=0,bno=0,copy=0,total=0,cnt=0;
char book_t[20],book_a[20];

books *b;
do
{

cout<<"1.Add\n";
cout<<"2.Issue\n";
cout<<"3.Display list of available books\n";
cout<<"4.Exit\n";

cout<<"Enter your choice\n";
cin>>ch;
switch(ch)
{
case 1: cout<<"Adding Information.................\n";
	cout<<"********************************************\n";
	cout<<"\nHow many books you want to add? ";
	cin>>n;
         b=new books[n]; 




	for(int i=0;i<n;i++)
	{
	b[i].add();

	}
	
	cout<<"\ntitle\t     auther\t     price\t     publisher\t       stock\n";
	cout<<"-------------------------------------------------------------------------\n";
	for(int i=0;i<n;i++)
	{	
	b[i].disp();
	}	
	break;
case 2: cout<<"Issueing Book.......................\n";
	cout<<"**********************************************\n";
	cout<<"\nEnter book title";
	cin>>book_t;
	cout<<"\nEnter book author";
	cin>>book_a;
		
	for(int i=0;i<n;i++)
	{
		
	if(strcmp(b[i].title,book_t)==0&&strcmp(b[i].author,book_a)==0)
	{
		cout<<"\nTitle= "<<b[i].title;
		cout<<"\nAuthor= "<<b[i].author;
		cout<<"\nPrice= "<<b[i].price;
		cout<<"\nPublisher= "<<b[i].publisher;
		cout<<"\nStock available= "<<b[i].stock_position;
		cout<<"\nHow many copies you want- ";
		cin>>copy;
		
		if(copy<=b[i].stock_position)
		{
		  total=copy*b[i].price;
		  cout<<"\nTotal price of book is "<<total;
		  b[i].stock_position-=copy;
		  cout<<"\nStock available= "<<b[i].stock_position;
		}
		else
		{		
		cout<<"\nRequested copies are not in stock ";	
		}
		
		break;
	}

	else
	{
	cnt=1;
	}//else
	}//for
	if(cnt==1)
	cout<<"\nBook is not available";
	break;

case 3:
	 cout<<" Books Available.......................\n";
	cout<<"**********************************************\n";
	cout<<"\ntitle\t     auther\t     price\t     publisher\t       stock\n";
	cout<<"-------------------------------------------------------------------------\n";
	for(int i=0;i<n;i++)
	{	
	b[i].disp();
	}
case 4: 


	cout<<"\nexit......\n";
	break;
}
cout<<"\nDo you want to continue?(0/1)\n";
cin>>ch1;
}while(ch1==1);

}


