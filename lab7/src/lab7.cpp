//============================================================================
// Name        : lab7.cpp
// Author      : Vatsala Y K
// Version     : C++
// Copyright   : Your copyright notice
// Description : Co-Sequential match
//============================================================================
#include <iostream>
#include <fstream>
#include<string.h>
#include<stdlib.h>
#include<sstream>
#define max 100
#define mx 20
using namespace std;
class coseq
{
	string name,buffer;
	int count1,count2;
	string a[max],b[max];
public :
	void load(char file1[mx],char file2[mx]);
	void sort();
	void insert(char file1[mx],char file2[mx]);
	void read(int);
	void match();
};
void coseq::read(int j)
{
	int i,n;
	cout<<"Enter the number of names to enter in list-"<<j<<endl;
	cin>>n;
	buffer.erase();
	for(i=0;i<n;i++)
	{
		//buffer.erase();
		cout<<"Enter the Name: "<<endl;
		cin>>name;
		buffer+=name;
		buffer+="\n";
		//cout<<buffer<<endl;
	}
	//cout<<buffer<<endl;                      //buffer contents
}
void coseq::insert(char file1[mx],char file2[mx])
{
	//int a=1;
	//int b=2;	
	fstream fp;
	read(1);
	cout<<"Contents if file 1 "<<endl<<buffer;
	fp.open(file1,ios::out|ios::app);
	fp<<buffer;
	fp.close();
	read(2);
	cout<<"Contents of file 2 "<<endl<<buffer;
	fp.open(file2,ios::out|ios::app);
	fp<<buffer;
	fp.close();
}
void coseq::load(char file1[mx],char file2[mx])
{
	int i=0;
	fstream fp;
	count1 = 0;
	fp.open(file1,ios::in);
	while(!fp.eof())
	{
		getline(fp,name);
		a[i]=name;
		cout<<"Count of 'i' for file 1 is "<<i<<endl; //count of i
		i++;
		count1++;
	}
	//cout<<"Count 1 is "<<count1<<endl;
	cout<<"Contents of file 1 are:"<<endl;
	for(i=0;i<count1;i++)
        cout<<a[i]<<endl;
	fp.close();
	count2 = 0;
	i=0;
	fp.open(file2,ios::in);
	while(!fp.eof())
	{
		getline(fp,name);
		b[i]=name;
		i++;
		cout<<"Count of 'i' for file 2 is"<<i<<endl;    //count of i
		count2++;
	}
	//cout<<"Count 2 is "<<count2<<endl;
	cout<<"Contents of file 2 are:"<<endl;
	for(i=0;i<count2;i++)
        cout<<b[i]<<endl;
	fp.close();
	fp.close();
}
void sorting(string arr[],int n)
{
	int i,j;
	string temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
void coseq::sort()
{
	int i;
	sorting(a,count1);
	cout<<"The Sorted names of list-1: "<<endl;
	for(i=0;i<=count2;i++)
		cout<<a[i]<<endl;
	sorting(b,count2);
	cout<<"The Sorted names of list-2: "<<endl;
	for(i=0;i<=count2;i++)
		cout<<b[i]<<endl;
}
void coseq::match()
{
	int i=0,j=0;
	while(i<=count1 && j<=count2)
	{
		if(a[i]==b[j])
		{
			cout<<a[i]<<endl;
			i++;
			j++;
		}
		if(a[i]<b[j])i++;
		if(a[i]>b[j])j++;
	}
}
int main()
{
	coseq c;
	char file1[mx],file2[mx];
	cout<<"Enter the first file name [FORMAT- filename.txt]"<<endl;
	cin>>file1;
	cout<<"Enter the next file name [FORMAT- filename.txt]"<<endl;
	cin>>file2;
	c.insert(file1,file2);
	c.load(file1,file2);
	c.sort();
	cout<<"Common names in both lists are : "<<endl;
	c.match();
	return 0;
}
