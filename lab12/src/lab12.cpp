//============================================================================
// Name        : lab12.cpp
// Author      : Vatsala Y K
// Version     : C++
// Copyright   : Your copyright notice
// Description : Reclaiming space using linked list
//============================================================================

#include<sys/types.h>
#include<string.h>
#include<fstream>
#include<sstream>
#include <iostream>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#define max 100
using namespace std;
class Student {
	string name;
	string usn;
	string branch;
	string sem;
public:
	Student(string iname,string iusn,string ibranch,string isem)
	{
		name=iname;
		usn=iusn;
		branch=ibranch;
		sem=isem;
	}
	string pack(int n)
	{
		string buffer;
		buffer=usn+'|'+name+'|'+branch+'|'+sem;
		for(int i=buffer.size();i<n;i++)
		{
					buffer+='$';
		}
		return buffer;
	}
};
class Node
{
	int offset;
	Node *next;
public:
	Node()
	{
		next=NULL;
	}
	Node(int ioffset)
	{
		offset=ioffset;
	}
	friend class List;
};
class List
{
	Node *head;
public:
	List()
	{
		head=NULL;
	}
	void insert(int offset)
	{
		Node *temp=new Node(offset);
		temp->next=head;
		head=temp;
	}
	int get()
	{
		if(head==NULL)
		{
			return -1;
		}
		int offset=head->offset;
		head=head->next;
		return offset;
	}
};
class RBF
{
	char filename[max];
	int recsize;
public:
	RBF(char ifilename[max],int recsiz)
	{
		strcpy(filename,ifilename);
		recsize=recsiz;
	}
	void addrec(string buffer,int offset)
	{
		ofstream f;
		if(offset==-1)
		{
			fstream f(filename,ios::out|ios::app);
			f<<buffer;
			f<<endl;
			f.close();
		}
		else
		{
		fstream f(filename);
		cout<<"value of offset : "<<offset<<endl;
		f.seekp(offset,ios::beg);
		f<<buffer;
		f<<endl;
		f.close();
		}
	}
	int dele(string key,string value)
	{
		cout<<"inside delete"<<endl;
		string name;
		string a="*";
		string usn;
		string branch;
		string sem;
		int i=0,pos=0 ;
		string s;
		stringstream ss;
		cout<<"filename : "<<filename<<endl;
		fstream f(filename,ios::in);
		while(!f.eof())
		{
			getline(f,s);
			cout<<"s : "<<s<<endl;
			ss.str("");
			ss<<s;
			pos=f.tellp();
			pos=pos-101;
			getline(ss,usn,'|');
			cout<<"usn : "<<usn<<endl;
			if(key=="usn")
			{
				if(value==usn)
				{
					fstream of(filename);
					of.clear();
					of.seekp(pos,ios::beg);
					of<<'*';
					int apos=of.tellp();
					cout<<"value of apos : "<<apos<<endl;
					of.close();
					return pos;
				}
			}
			getline(ss,name,'|');
			if(key=="name")
				{
					if(value==name)
					{
						f.clear();
						f.seekp(pos,ios::beg);
						f<<'*';
						return pos;
					}
				}
			getline(ss,branch,'|');
			if(key=="branch")
				{
					if(value==branch)
					{
						f.clear();
						f.seekp(pos,ios::beg);
						f<<'*';
						return pos;
					}
				}
			getline(ss,sem,'$');
			if(key=="sem")
				{
					if(value==sem)
					{
						f.clear();
						f.seekp(pos,ios::beg);
						f<<'*';
						return pos;
					}
				}
		}
	}
};
int main()
{
	List l1;
	RBF r1("data.txt",100);
	string s;
	int pos;
	int i;
	Student s1("abc","678","ise","7");
	Student s2("def","123","cse","7");
	Student s3("ghi","456","tce","7");
	Student s4("jkl","789","me","7");
	s=s1.pack(100);
	pos=l1.get();
	r1.addrec(s,pos);
	s=s2.pack(100);
	pos=l1.get();
	r1.addrec(s,pos);
	s=s3.pack(100);
	pos=l1.get();
	r1.addrec(s,pos);
	s=s4.pack(100);
	pos=l1.get();
	r1.addrec(s,pos);
	cout<<"Do you want to delete\npress 1 if yes else 0 : ";
	cin>>i;
	cout<<endl;
	if(i==1)
	{
		pos=r1.dele("usn","123");
		cout<<"value of pos : "<<pos<<endl;
		l1.insert(pos);
		pos=r1.dele("usn","456");
		cout<<"value of pos : "<<pos<<endl;
		l1.insert(pos);
		cout<<"i guess u deleted succesfully"<<endl;
	}
	cout<<"Do you want to add a record ?\npress 1 if yes else 0 : ";
	cin>>i;
	cout<<endl;
	if(i==1)
	{
		pos=l1.get();
		cout<<"value of pos via get() : "<<pos<<endl;
		Student s5("alpha","159","ise","7");
		s=s5.pack(100);
		r1.addrec(s,pos);
		pos=l1.get();
		cout<<"value of pos via get() : "<<pos<<endl;
		Student s6("beta","753","ise","7");
		s=s6.pack(100);
		r1.addrec(s,pos);
		pos=l1.get();
		cout<<"value of pos via get() : "<<pos<<endl;
		Student s7("gamma","842","ise","7");
		s=s7.pack(100);
		r1.addrec(s,pos);
	}
}
