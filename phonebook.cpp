#include<iostream>
#define MAX 10
using namespace std;
struct phonebook
{
	string name;
	long long int number;
};

class Hashtable
{
	public:
		phonebook hashtable[MAX];

		Hashtable()
		{
			for(int i=0;i<MAX;i++)
			{
				hashtable[i].number=0;
			}
		}
		
		int hash(long long int key);
		void insertlinear(phonebook p);
		void insertquadratic(phonebook p);
		int searchlinear(long long int key);
		int searchquadratic(long long int key);
		int deletelinear(long long int key);
		int deletequadratic(long long int key);
		void display();
};
void linearprobing();
void quadraticprobing();

int Hashtable::hash(long long int key)
{
	int pos;
	pos = (key%MAX);
	return pos;
}

void Hashtable::insertlinear(phonebook p)
{
	int pos;
	pos = hash(p.number);
	
	if(hashtable[pos].number==0)
	{
		hashtable[pos]=p;
	}
	else
	{
		for(int i = (pos+1)%MAX; i != pos;i=(i+1)%MAX)
		{
			if(hashtable[i].number==0)
			{
				hashtable[i]=p;
				break;
			}
		}
	}
}

int Hashtable::searchlinear(long long int key)
{
	int pos,cnt;
	pos = hash(key);cnt=1;
	if(hashtable[pos].number==key)
	{
		cout<<"Number found in the phonebook."<<endl;
		cout<<"Name :"<<hashtable[pos].name<<endl;
		cout<<"No. of comparisons :"<<cnt<<endl;
	}
	else
	{
		for(int i = (pos+1)%MAX; i != pos;i=(i+1)%MAX)
		{	
			cnt++;
			if(hashtable[i].number==key)
			{
				cout<<"Number found in the phonebook."<<endl;
				cout<<"Name:"<<hashtable[i].name<<endl;
				cout<<"No. of comparisons :"<<cnt<<endl;
				return i;
			}
		}
		return -1;
	}

	return 0;
}

int Hashtable::deletelinear(long long int key)
{
	int pos;
	pos = hash(key);
	if(hashtable[pos].number==key)
	{
		hashtable[pos].number=0;
		hashtable[pos].name="";
		return pos;
	}
	else
	{	
		for(int i=(pos+1)%MAX;i != pos;i=(i+1)%MAX)
		{
			if(hashtable[i].number==key)
			{
				hashtable[i].number=0;
				hashtable[i].name="";
				return i;
			}
		}
		return -1;
	}
}
void Hashtable::display()
{
	for(int i=0;i<MAX;i++)
	{
		cout<<i<<" : "<<hashtable[i].name<<" : "<<hashtable[i].number<<endl;
	}
}

void Hashtable::insertquadratic(phonebook p)
{
	int pos;
	for(int i=0;i<MAX;i++)
	{	
		pos = (hash(p.number) + i*i)%MAX;
		if(hashtable[pos].number==0)
		{
			hashtable[pos]=p;
			break;
		}
	}
}

int Hashtable::searchquadratic(long long int key)
{
	int pos,cnt=1;
	for(int i=0;i<MAX;i++)
	{	
		pos = (hash(key) + i*i)%MAX;
		if(hashtable[pos].number==key)
		{
			cout<<"Number found in the phonebook."<<endl;
			cout<<"Name: "<<hashtable[pos].name<<endl;
			cout<<"No. of comparisons:"<<cnt<<endl;
			return pos;
		}
		cnt++;
	}
	return -1;
}

int Hashtable::deletequadratic(long long int key)
{
	int pos;
	for(int i=0;i<MAX;i++)
	{
		pos = (hash(key) + i*i)%MAX;
		if(hashtable[pos].number==key)
		{
			hashtable[pos].number=0;
			hashtable[pos].name="";
			return pos;
		}
	}
	return -1;
}

int main()
{
	int choice;
	cout<<"\t\t\t***Main Menu***"<<endl;
	cout<<"(1)Linear Probing(Without replacement)."<<endl;
	cout<<"(2)Quadratic Probing."<<endl;
	cout<<"(3)Exit."<<endl;
	cout<<"Enter your choice:"<<endl;
	cin>>choice;

	if(choice==1)
	{
		linearprobing();
	}
	else if(choice==2)
	{
		quadraticprobing();
	}
	else if(choice==3)
	{
		cout<<"Exiting the program"<<endl;
	}
	
	return 0;
}
void linearprobing()
{
	Hashtable ht1;
	phonebook p1;

	int choice1;
	while(true)
	{
		cout<<"***LinearProbing choice menu***"<<endl;
		cout<<"(1)Insert phone number and name to phonebook."<<endl;
		cout<<"(2)Search number in the phonebook."<<endl;
		cout<<"(3)Delete number from the phonebook."<<endl;
		cout<<"(4)Display entire phonebook."<<endl;
		cout<<"(5)Return to main menu."<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>choice1;
		if(choice1==1)
		{
			cout<<"Enter name:"<<endl;
			cin>>p1.name;
			cout<<"Enter phone number of "<<p1.name<<":"<<endl;
			cin>>p1.number;
			ht1.insertlinear(p1);
		}
		else if(choice1==2)
		{
			long long int val;
			int res;	
			cout<<"Enter number to be searched:"<<endl;
			cin>>val;
			res=ht1.searchlinear(val);
			if(res==-1)
			{
				cout<<"Number is not present in the phonebook."<<endl;
			}	
		}
		else if(choice1==3)
		{
			long long int val;
			int res;
			cout<<"Enter number to be deleted:"<<endl;
			cin>>val;
			res=ht1.deletelinear(val);
			if(res==-1)
			{
				cout<<"Number can't be deleted as it is not present in the Phonebook."<<endl;
			}
			else
			{	
				cout<<"Number deleted successfully from the position :"<<res<<endl;
			}
		}
		else if(choice1==4)
		{
			main();
		}
		
	}
}
void quadraticprobing()
{
	Hashtable ht2;
	phonebook p2;
	int choice2;
	while(true)
	{
		cout<<"***QuadraticProbing choice menu***"<<endl;
		cout<<"(1)Insert phone number and name to phonebook."<<endl;
		cout<<"(2)Search number in the phonebook."<<endl;
		cout<<"(3)Delete number from the phonebook."<<endl;
		cout<<"(4)Display entire phonebook."<<endl;
		cout<<"(5)Return to main menu."<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>choice2;
		if(choice2==1)
		{
			cout<<"Enter name:"<<endl;
			cin>>p2.name;
			cout<<"Enter phone number of "<<p2.name<<":"<<endl;
			cin>>p2.number;
			ht2.insertquadratic(p2);
		}
		else if(choice2==2)
		{
			long long int val;
			int res;	
			cout<<"Enter number to be searched:"<<endl;
			cin>>val;
			res=ht2.searchquadratic(val);
			if(res==-1)
			{
				cout<<"Number is not present in the phonebook."<<endl;
			}	
		}
		else if(choice2==3)
		{
			long long int val;
			int res;
			cout<<"Enter number to be deleted:"<<endl;
			cin>>val;
			res=ht2.deletequadratic(val);
			if(res==-1)
			{
				cout<<"Number can't be deleted as it is not present in the Phonebook."<<endl;
			}
			else
			{	
				cout<<"Number deleted successfully from the position :"<<res<<endl;
			}
		}
		else if(choice2==4)
		{
			main();
		}
		
	}
}
