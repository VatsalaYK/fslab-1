//============================================================================
// Name        : lab3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include<string.h>
#include<fstream>
#include<sstream>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class student
{
			string usn;
			string name;
			string branch;
			int semester;
		    string buffer;

public:
	  void readfromconsole()
	  {
			cin.clear();
			cin.ignore(255,'\n');
			cout<<"Enter the name"<<endl;
			getline(cin,name);
			cout<<"Enter the usn"<<endl;
			cin>>usn;
			cin.clear();
			cin.ignore(255,'\n');
			cout<<"Enter the branch"<<endl;
			cin>>branch;
			cout<<"Enter the semester"<<endl;
			cin>>semester;
			cin.clear();
			cin.ignore(255,'\n');
			cout<<endl;
	  }
	  void showstudent()
	  {
			  cout<<"USN :"<<usn<<endl;
			  cout<<"Name :"<<name<<endl;
			  cout<<"Branch :"<<branch<<endl;
			  cout<<"semester :"<<semester<<endl;
	  }
	  void pack()
	  {
			  string temp;
			  string sem1;
			  stringstream out;
			  out<<semester;
			  sem1=out.str();
			  temp.erase();
			  buffer.erase();
			  temp=usn+'|'+name+'|'+branch+'|'+sem1+'@';
			  buffer=temp;
			  cout<<buffer<<endl;
	  }
	  void write()
	  {
			  fstream f1;
			  f1.open("Data1.txt",ios::out|ios::app);
			  f1<<buffer;
			  f1<<endl;
			  f1.close();
	  }
	  int search(string key)
	  {
			  fstream f1;
			  int pos;
			  string g_usn;
			  f1.open("Data1.txt",ios::in);
			  while(!f1.eof())
			  {
				  getline(f1,buffer);
				  pos=f1.tellp();
				 g_usn= unpack();
				  if(usn==key)
				  {
					  cout<<"found the record"<<endl;
					  cout<<"pos="<<pos<<endl;
					  cout<<"USN :"<<usn<<endl;
					  cout<<"Name :"<<name<<endl;
					  cout<<"Branch :"<<branch<<endl;
					  cout<<"Semester :"<<semester<<endl;
					  f1.close();
					  return pos;
				  }
				  else
					  cout<<"Record not found"<<endl;
			  }
			  return -1;
	 }
	 string unpack()
	 {
			 string s;
			 int i=0;
			 cout<<endl;
			 usn.erase();
		     while(buffer[i]!='|')
			   {
				   usn+=buffer[i++];
				   i++;
			   }
			   i++;
			   name.erase();

			   while(buffer[i]!='|')
			   {
				   name+=buffer[i++];
				   i++;
			   }
			   i++;
			   branch.erase();

			   while(buffer[i]!='|')
			   {
				   branch+=buffer[i++];
				   i++;
			   }
			   i++;
			   semester=0;

			   while(buffer[i]!='$')
			   {
				   s=buffer[i];
				   stringstream convert(s);
				   convert>>semester;
				   i++;
			   }
						cout<<"usn is :"<<usn<<endl;
						cout<<"name is :"<<name<<endl;
						cout<<"branch is :"<<branch<<endl;
						cout<<"sem is :"<<semester<<endl;
						return usn;
	 }
	 void modify(string key)
	 {
				 int ch,pos;
				 fstream f1;
				 pos=search(key);
				 if(pos<1)return;
				 cout<<"Record is modified at the position :"<<pos<<endl;
				 cout<<"Enter the field to be modified :"<<endl
						 <<"1.Modify USN"<<endl
						 <<"2.Modify NAME"<<endl
						 <<"3.Modify BRANCH"<<endl
						 <<"4.Modify SEMESTER"<<endl;
				 cout<<"Enter your choice: ";
				 cin>>ch;
				 switch(ch)
				 {
						 case 1:

							 cout<<"Enter the USN : "<<endl;
							 cin>>usn;
							 cout<<endl;
							 pack();
							 break;
						 case 2:

							 cin.clear();
							 cin.ignore(255,'\n');
							 cout<<"Enter the name "<<endl;
							 getline(cin,name);
							 cout<<endl;
							 pack();
							 break;
						 case 3:

								cin.clear();
								cin.ignore(255,'\n');
								cout<<"Enter the branch "<<endl;
								getline(cin,branch);
								cout<<endl;
								pack();
								break;
						 case 4:

							 cout<<"Enter the sem"<<endl;
							 cin>>semester;
							 cout<<endl;
							 pack();
							 break;
						 default:
							 cout<<"Enter a valid choice"<<endl;
				 }
				 write();
				 pos=pos-(buffer.size()-1);
				 f1.open("Data10.txt");
				 f1.seekp(pos,ios::beg);
				 f1<<buffer;
				 f1<<endl;
				 f1.close();
	 }
};

int main()
{
	int choice,i;
	string key;
	student s;
	while(1)
	{
			cout<<"1.INSERT"<<endl
			    <<"2.SEARCH"<<endl
			    <<"3.DELETE"<<endl
			    <<"4.MODIFY"<<endl;
			    cout<<"Enter your choice"<<endl;
			    cin>>choice;
			    switch(choice)
				{
						 case 1:

							   s.readfromconsole();
							   s.showstudent();
							   s.pack();
							   s.write();
								   break;
						  case 2:

								  cout<<"Enter the key: "<<endl;
								  cin>>key;
								  i= s.search(key);
								  if(i!=0)
									  cout<<"Found at "<<i-101;
								  else
									  cout<<"Not found";
								  break;

						  case 3:
							  	  //delete not done as of now
							  	  break;

						  case 4:
								  cout<<"Enter the key(USN) : "<<endl;
								  cin>>key;
								  s.modify(key);
								  break;

						  default:
							  	  cout<<"INVALID INPUT"<<endl<<"----TRY AGAIN----"<<endl;
							  	  return 0;
				 }
		}
	    return 0;
}


