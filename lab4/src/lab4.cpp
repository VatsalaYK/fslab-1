
//============================================================================
// Name        : lab4.cpp
// Author      : Vatsala Y k
// Version     : C++
// Copyright   : Your copyright notice
// Description : RRN in C++, Ansi-style
//============================================================================


#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<stdlib.h>
using namespace std;
class student
{
	string usn,name,branch,sem,buffer;
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
		cin>>sem;

	}
	void display_data();
	void pack();
	void unpack(int);
}s;
int rrn[100],count = 0;
fstream fp;
void find_rrn();
void search();
void error(int);
void find_rrn()
{
	int pos;
	string buffer;
	fp.open("data.txt",ios::in);
	if(!fp)
		error(1);
	while(fp)
	{
		pos = fp.tellg();
		getline(fp,buffer);
		if(buffer.length()==0)
			continue;
		rrn[++count]=pos;
	}
	fp.close();
}
void student::pack()
{
	int pos = fp.tellg();
	string buffer=usn+'|'+name +'|'+branch +'|'+sem+'$';
	fp<<buffer<<endl;
	cout<<endl<<buffer;
	rrn[++count]=pos;
}
void student::unpack(int pos)
{
	fp.seekg(pos, ios::beg);
	getline(fp, usn, '|');
	getline(fp, name, '|');
	getline(fp, branch, '|');
	getline(fp, sem, '$');
}
void student::display_data()
{
	cout<<"\nName: "<<name<<"\nusn: "<<usn<<"\nbranch: "<<branch<<"\nsem: "<<sem<<endl;
}
void search()
{
	int rrn_srch, pos;
	cout<<"Enter the RRN of the record to be found:\n";
	cin>>rrn_srch;
	if(rrn_srch>count||rrn_srch<1)
	{
		error(2);
		return;
	}
	cout<<"Record Found:\n";
	pos=rrn[rrn_srch];
	cout<<pos;
	fp.open("data.txt", ios::in);
	if(!fp)
		error(1);
	s.unpack(pos);
	fp.close();
	s.display_data();
}
void error(int error)
{
	switch(error)
	{
	case 1: cout<<"Unable to open the record File\n";
	exit(0);
	case 2:	cout<<"Invalid RRN\n";
	return;
	}
}
int main()
{
	int choice;
	fp.open("data.txt",ios::out|ios::app);
	fp.close();
	find_rrn();
	while(1)
	{
		cout<<"1. Insert a record\n2. Search for record using RRN\n3. Exit\nEnter Choice : ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			s.readfromconsole();

			fp.open("data.txt",ios::out|ios::app);
			if(!fp)
				error(1);
			s.pack();
			fp.close();
			break;
		case 2:
			search();
			break;
		default: exit(0);
		}
	}
}
