#include <iostream>
#include<string>
#include<fstream>
using namespace std;
class student
{
	string usn;
	string name;
	string branch;
	string semester;
	 string buffer;

public:
	  void readfromconsole()
	  {
		cin.clear();
		cin.ignore(255,'\n');
	    cin.clear();
	    cout<<"Enter the name"<<endl;
	    getline(cin,name);
	    cin.clear();
	    cin.ignore(255,'\n');
	    cout<<"Enter the usn"<<endl;
	    cin>>usn;
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

				  temp=usn+'|'+name+'|'+branch+'|'+semester;
				 // buffer=temp;
	     for(i=temp.size();i<100;i++)

	       temp+='$';

	     buffer+=temp;
	     cout<<buffer<<endl;
	  }
	  void write()
	  {
		  fstream f1;

		  f1.open("Data22.txt",ios::out|ios::app);
		  f1<<buffer;
		  f1<<endl;
		  f1.close();
	  }
	  int search(string key)
	  {
		  fstream f1;
		  int pos;
		  f1.open("Data22.txt",ios::in);
		  while(!f1.eof())
		  {
			  getline(f1,buffer);
			  pos=f1.tellp();
			  unpack();
			  if(usn==key)
			  {

				  cout<<"found the record"<<endl;
				  return pos;
			  }

		  }
		  cout<<"Record not found"<<endl;
		  f1.close();

	 }
	 void unpack()
	 {
       int i=0;
       usn.erase();
       while(buffer[i]!='|')
       usn+=buffer[i++];
       i++;
       while(buffer[i]!='|')
       name+=buffer[i++];
       i++;
       while(buffer[i]!='|')
       branch+=buffer[i++];
       i++;
       while(buffer[i]!='$')
       semester+=buffer[i++];
       i++;
	 }
	 void modify()
	 {
		 int ch;
		 string key;
		 cout<<"Enter the key to modify ; "<<endl;
		 cin>>key;
		 search(key);
		 //del(key);
		 cout<<"1.INSERT USN"<<endl<<"2.INSERT NAME"<<endl<<"3.INSERT BRANCH"<<endl<<"4.INSERT SEMESTER"<<endl;
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
	 }

};

int main()
{
	int choice,i;
	string key;
	student s;
  while(1)
  {
	  cout<<"1.INSERT"<<endl<<"2.SEARCH"<<endl<<"3.DELETE"<<endl<<"4.MODIFY"<<endl;
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
		          s.search(key);
		       break;
		  case 3:
			  s.modify();
			  break;

		  default:return 0;
		 }
	}
	return 0;
}
