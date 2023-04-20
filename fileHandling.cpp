#include <iostream>
#include <fstream>
using namespace std;

struct student
{
	int rollno;
	char name[20];
	char div;
	char address[20];
	public:
		void getdata();
		void putdata();
};

class Student
{
	fstream fp;
	student s;
	public:
		void addstudent();
		void displaystudent();
		void deletestudent();
		void physicaldelete();
		void search();
};


void student::getdata()
{
	cout<<endl;
	cout<<"Enter Roll No of student: ";
	cin>>rollno;
	cout<<"Enter Name of student: ";
	cin>>name;
	cout<<"Enter Div : ";
	cin>>div;
	cout<<"Enter Address ; ";
	cin>>address;
	cout<<endl;
}

void student::putdata()
{
	cout<<endl;
	cout<<"\tRoll No.:\t"<<rollno<<endl;
	cout<<"\tName\t:\t"<<name<<endl;
	cout<<"\tDiv\t:\t"<<div<<endl;
	cout<<"\tAddress\t:\t"<<address<<endl;
	cout<<endl;
}


void Student::addstudent()
{
	char ans;
	fp.open("ass11.dat", ios::out);
	do
	{
		s.getdata();
		fp.write((char *)&s, sizeof(s));
		cout<<"Do you wan to add more student ?"<<endl;
		cin>>ans;
	} while (ans=='Y' || ans=='y');
	fp.close();
}

void Student::displaystudent()
{
	fp.open("ass11.dat", ios::in);
	while(!fp.eof())
	{
		fp.read((char *)&s, sizeof(s));
		if (!fp.eof())
		{
			s.putdata();
		}
	}
	fp.close();
}

void Student::physicaldelete()
{
	int r;
	fstream tfp;// temporary file
	fp.open("ass11.dat",ios::in);
	tfp.open("temp",ios::out);
	cout << "\n Enter roll to be deleted :";
	cin >> r;
	while(fp.read((char*)&s,sizeof(s)))
	{
		//read record from student file
		if (s.rollno==r)
		{
			cout << "\n Deleting .....\n";
			s.putdata();
			//display record on screen
		}
		else
		{
			tfp.write((char*)&s,sizeof(s));
			//write record to temp file
		}
	}// end of while
	fp.close();
	tfp.close();
	remove("ass11.dat");
	rename("temp","ass11.dat");
}

void Student::search()
{
	fp.open("ass11.dat",ios::in);
	int r;
	cout << "\n Enter roll to be searched :";
	cin >> r;
	while(!fp.eof())
	{
		fp.read((char*)&s,sizeof(s));
		//read record from file
		if (!fp.eof() and s.rollno==r)
		{
			s.putdata();
			//display record on screen
			break;
		}
	}
	fp.close();
}
void menu()
{
	cout<<endl;
	cout<<"*** File Handling - Sequential File ***"<<endl;
	cout<<endl;
	cout<<"1. Add Student Data."<<endl;
	cout<<"2. Display Student Data."<<endl;
	cout<<"3. Search Student Data."<<endl;
	cout<<"4. Delete Student Data."<<endl;
	cout<<"5. Exit."<<endl;
}

int main()
{
	Student S;
	int choice;
	do
	{
		menu();
		cout<<"Enter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
			{
				S.addstudent();
				break;
			}
			case 2:
			{
				S.displaystudent();
				break;
			}
			case 3:
			{
				S.search();
				break;
			}
			case 4:
			{
				cout<<"Following student deleted sucessfully:"<<endl;
				S.physicaldelete();
				break;
			}

		}
	}while(true);
		cout<<"Exited";
	return 0;
}
