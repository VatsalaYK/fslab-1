//============================================================================
// Name        : lab9.cpp
// Author      : Vatsala Y K
// Version     : C++
// Copyright   : Your copyright notice
// Description : Reclaiming space in records
//============================================================================


//------incomplete code------//



#include <iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;
class student
{
	string usn;
	string name;
	string branch;
	string semester;
	 string buffer;

public:
	 class node
	{
		public : int address;
			 node *link;
	};
	node *first;
	void initialize()
	{
		first=NULL;
	}
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

	  }
	  void showstudent()
	  {
		  cout<<"usn:"<<usn<<endl;
		  cout<<"name:"<<name<<endl;
		  cout<<"branch:"<<branch<<endl;
		  cout<<"semester:"<<semester<<endl;
	  }
	  void pack()
	  {
		  string temp,sem1;

		  int i;
		  temp.erase();
		  buffer.erase();
		  temp+=usn+'|'+name+'|'+branch+'|'+semester;
	      	  for(i=temp.size();i<100;i++)
	          temp+='$';
	          buffer+=temp;
	          cout<<buffer<<endl;
	  }
	  void write()
	  {
		  fstream f1;
		  int pos;
		   if(first==NULL)
		    {
		  	f1.open("1.txt",ios::out|ios::app);
		  	f1<<buffer;
		  	f1<<endl;
			cout<<"inside first NULL"<<endl;
		}
		else
		{
			f1.open("1.txt");
			node *q,*p;
			q=first;		//last released record space will be used
			while(q->link!=NULL)
			{
				p=q;
				q=q->link;
			}
			pos=q->address;
			p->link=NULL;
			f1.seek(pos,ios::beg);
			f1<<buffer;
		}
		f1.close();
	  }
	  int search(string key)
	  {
		  fstream f2;
		  int pos=0,flag=0;
		  f2.open("1.txt",ios::in);
		  if(f2==NULL)
		{
			cout<<"File is not available"<<endl;
			return 0;
		}
		  while(!f1.eof())
		  {
			  buffer.erase();
			  getline(f2,buffer);
			 // pos=f1.tellp();
			  unpack();
			  if(key==usn)
			  {
				  cout<<"found the record"<<endl;
				  pos=f2.tellg();
				//  pos=pos-101;
				  cout<<"pos="<<pos<<endl;
				  cout<<"USN :"<<usn<<endl;
				  cout<<"Name :"<<name<<endl;
				  cout<<"Branch :"<<branch<<endl;
				  cout<<"Semester :"<<semester<<endl;
				  //f2.close();
				  flag=1;
				  return pos;
			  }
		    }
		f2.close();
		if(!flag)
		{
			cout<<"Not found"<<endl;
			return pos;
		}
	}
		  //cout<<"Record not found"<<endl;
		  //f1.close();
		  //return 0;
	 void unpack()
	 {
       int i=0;
       usn.erase();
       while(buffer[i]!='|')
       usn+=buffer[i++];
      /* i++;
       name.erase();
       while(buffer[i]!='|')
       name+=buffer[i++];
       i++;
       branch.erase();
       while(buffer[i]!='|')
       branch+=buffer[i++];
       i++;
       semester.erase();
       while(buffer[i]!='$')
       semester+=buffer[i++];
       i++;*/
	 }
	 void modify(string key)//delete not done
	 {
		 int ch,pos;
		// string key;
		 fstream fp1;
		 pos=search(key);
		/* cout<<"Enter the key to modify ; "<<endl;
		 cin>>key;
		 search(key);
		 //del(key);*/
		 cout    <<"1.INSERT USN"<<endl
				 <<"2.INSERT NAME"<<endl
				 <<"3.INSERT BRANCH"<<endl
				 <<"4.INSERT SEMESTER"<<endl;
		 cout<<"Enter your choice: ";
		 cin>>ch;
		 switch(ch)
		 {
		 case 1:
			 cout<<"Enter the USN : "<<endl;
			 cin>>usn;
			 break;
		 case 2:
			 cin.clear();
			 cin.ignore(255,'\n');
			 cout<<"Enter the name "<<endl;
			 getline(cin,name);
			 break;
		 case 3:
		 		cin.clear();
		 		cin.ignore(255,'\n');
		 		cout<<"Enter the branch "<<endl;
		 		getline(cin,branch);
		 		break;
		 case 4:
			 cout<<"Enter the sem"<<endl;
			 cin>>semester;
			 break;
		 }
		 pack();
		 write();
		 pos=pos-101;
		 fp1.open("Data10.txt");
		 fp1.seekp(pos,ios::beg);
		 fp1<<buffer;

	 }
	
};

int main()
{
	int choice,i,count,len;
	string key;
	student s;
	s.initialize();
 	 while(1)
  {
	  cout    <<"1.INSERT"<<endl
			  <<"2.DELETE"<<endl
			  <<"3.SEARCH"<<endl
			  <<"4.EXIT"<<endl;
	  cout<<"Enter your choice";
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

		  	  	  cout<<"Enter the key ; "<<endl;
		  	  	  cin>>key;
		          i= s.del(key);
		         /* if(i!=0)
		        	  cout<<"Found at "<<i-101;
		          else
		        	  cout<<"Not found";*/
		       break;
		  case 3:
			   cout<<"Enter the key ; "<<endl;
		  	  	  cin>>key;
		          i= s.search(key);
			  break;
		  case 4:
				exit(0);

		  default:
				cout<<"WRONG ENTRY"<<endl;			
				return 0;
		 }
	}
	return 0;
}
