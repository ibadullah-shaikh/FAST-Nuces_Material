#include<iostream>				//standard functions				
#include<fstream>				//For filing
#include<string.h>				//For strings
#include<conio.h>				//For getch()
using namespace std;
void DescendingOrder();
class Record
{
	static int count;			//for counting records
	char name[20],sex[10];		
	int id;
	float quiz1,quiz2,mid,final,avg_mid,avg_quiz,avg_final;		//variables for storing/calculating data
public:
	Record()			//Default Constructor
	{
	}
	void set_data(int id,char na[20], char se[10])		//setter to set data
	{
		this->id=id;
		strcpy(name,na);
		strcpy(sex,se);
	}
	void set_mid(float mid)			//setter to set mid marks
	{
		this->mid=mid;
	}
	void set_quiz(float quiz1,float quiz2)		//setter to set quizes marks
	{
		this->quiz1=quiz1;
		this->quiz2=quiz2;
	}
	void set_final(float final)			//setter to set final marks
	{
		this->final=final;
	}
	float get_avgQuiz() const			//getter to get average of quizes
	{
		return avg_quiz;
	}
	float get_avgMid() const			//getter to get average of mid
	{
		return avg_mid;
	}
	float get_avgFinal() const			//getter to get average of final
	{
		return avg_final;
	}
	int get_count()						//getter to get average of total No. of Records
	{
		return count;
	}
	float get_final() const				//getter to get average of final's marks
	{
		return final;
	}
	void Display()						//Function to display data
	{
		cout<<"Student Name:"<<name<<endl;
		cout<<"I'd:"<<id<<endl;
		cout<<"Sex:"<<sex<<endl;
		cout<<"Quiz 1 Marks:"<<quiz1<<endl;
		cout<<"Quiz 2 Marks:"<<quiz2<<endl;
		cout<<"Mid Marks:"<<mid<<endl;
		cout<<"Final Marks:"<<final<<endl;
		cout<<"=========================================="<<endl;
	}
	void add_record()				//Function that will add data in file
	{
		ofstream add;
		add.open("Student Record.txt",ios::app);
		if(add.is_open())
		{
			add.write( (char*)this, sizeof(*this) );
			count++;
			add.close();
		}
		else
		{
			cout<<"File doesn't exists or doesn't opened...!!"<<endl;
		}
	}
	void delete_record(int del)			//Function that will delete data from file
	{
		int i=0;
		ofstream writefile;
		ifstream readfile;
		readfile.open("Student Record.txt");
		if(readfile.is_open())
		{
			writefile.open("New.txt",ios::app); //opening new file to store data in that file 
			readfile.read( (char*)this , sizeof(*this) ); //reading data from file in which stored
			while(!readfile.eof())
			{
				if(id!=del) //condtion to check if id doesn't match then write record in new file
				{
					writefile.write( (char*)this, sizeof(*this) );
				}
				else //else condition if ids matched the do nothing just continue that record
				{
					i++; //i++, to check if record was present or not
					count--; //if present deleted record's count will be minus
				}
				readfile.read( (char*)this , sizeof(*this) ); //reading next record
			}
			writefile.close();
			readfile.close();
			remove("Student Record.txt");  //removing old file
			rename("new.txt","Student Record.txt"); //renaming new file by the old one.
			if(i==0) //i++ is used here, if record not found then display no record fornd of that id.
			{
				cout<<"Record Not Found...!!"<<endl;
			}
			else
			{
				//if found then display all updated records
				cout<<"Record Deleted Successfully...!!"<<endl;
				cout<<"Updated Records are given below."<<endl;
				cout<<"Total No of Record of Students:"<<count<<endl<<endl;
				displayAll();
			}
		
		}
		else
		{
			cout<<"Record file doesn't open or doesn't available...!!"<<endl;
		}
	}
	void search_by_name(char search[15])			//Function that will search by name data in file
	{
		int i=0;
		ifstream file;
		file.open("Student Record.txt");
		if(file.is_open())
		{
			file.read( (char*)this , sizeof(*this) );
			while(!file.eof())
			{
				if( strcmp(name,search)==0 ) //compairing searched name if matched then display
				{
					i++; //i++, to check if record found or not;
					Display();
				}
				else
				{
					
				}
				file.read( (char*)this , sizeof(*this) );
			}
		}
		else
		{
			cout<<"Record file doesn't open or doesn't available...!!"<<endl;
		}
		if(i==0)
		{
			//i++ is used here, if record not found then display no record fornd of that id.
			cout<<"No such Record found of that name...!!"<<endl;
		}
	}
	void UpdateRecord(int upd_id)			//Function that will update data in file
	{
		int i=0;
		ifstream old_file;			
		ofstream new_file;
		old_file.open("Student Record.txt");  	//opening file to frtch data 
		if(old_file.is_open())
		{
			new_file.open("New.txt",ios::app);		//opening new file to store data in that file
			old_file.read( (char*)this, sizeof(*this) );
			while(!old_file.eof())
			{
				if(id!=upd_id)  //condition , if update id and fetched data id doesn't match
								//store that data directly into the new file
				{
					new_file.write( (char*)this, sizeof(*this) );
				}
				else
				{
					//if matches then take the name, sex , and marks that are to be updated
					int t;
					char nam[20],se[10];
					char q1,q2,midd,finall;
				b:
					cout<<"Enter Updated Data...!!"<<endl;
					cout<<"Name:";
					cin>>nam;
					t=strlen(nam);
					try
					{
						for(i=0;i<t;i++)
						{
							if(nam[i] >= 48 && nam[i] <= 57)
							{
								throw(1);
							}
						}
					}
					catch(int a)
					{
						cout<<"Exception occured...!! Please give correct input...!!"<<endl;
						cout<<"Press any Key..!!"<<endl;
						getch();
						system("cls");
						goto b;
					}
					cout<<"Sex:";
					cin>>se;
					t=strlen(se);
					try
					{
						for(i=0;i<t;i++)
						{
							if(se[i] >= 48 && se[i] <= 57)
							{
								throw(1);
							}
						}
					}
					catch(int a)
					{
						cout<<"Exception occured...!! Please give correct input...!!"<<endl;
						cout<<"Press any Key..!!"<<endl;
						getch();
						system("cls");
						goto b;
					}
					cout<<"Quiz 1 Marks:";
					cin>>q1;
					try
					{
						if(q1>=97 && q1<=122)
						{
							throw('a');
						}
						else if(q1>=65 && q1<=90)
						{
							throw('A');
						}
						q1-=48;
					}
					catch(char a)
					{
						cout<<"Exception occured...!! Please give correct input...!!"<<endl;
						cout<<"Press any Key..!!"<<endl;
						getch();
						system("cls");
						goto b;
					}
					cout<<"Quiz 2 Marks:";
					cin>>q2;
					try
					{
						if(q2>=97 && q2<=122)
						{
							throw('a');
						}
						else if(q2>=65 && q2<=90)
						{
							throw('A');
						}
						q2-=48;
					}
					catch(char a)
					{
						cout<<"Exception occured...!! Please give correct input...!!"<<endl;
						cout<<"Press any Key..!!"<<endl;
						getch();
						system("cls");
						goto b;
					}
					cout<<"Mid Marks:";
					cin>>midd;
					try
					{
						if(midd>=97 && midd<=122)
						{
							throw('a');
						}
						else if(midd>=65 && midd<=90)
						{
							throw('A');
						}
						midd-=48;
					}
					catch(char a)
					{
						cout<<"Exception occured...!! Please give correct input...!!"<<endl;
						cout<<"Press any Key..!!"<<endl;
						getch();
						system("cls");
						goto b;
					}
					cout<<"Final Marks:";
					cin>>finall;
					try
					{
						if(finall>=97 && finall<=122)
						{
							throw('a');
						}
						else if(finall>=65 && finall<=90)
						{
							throw('A');
						}
						finall-=48;
					}
					catch(char a)
					{
						cout<<"Exception occured...!! Please give correct input...!!"<<endl;
						cout<<"Press any Key..!!"<<endl;
						getch();
						system("cls");
						goto b;
					}
					strcpy(name,nam);
					strcpy(sex,se);
					quiz1=q1;
					quiz2=q2;
					mid=midd;
					final=finall;
					new_file.write( (char*)this, sizeof(*this) ); //updated data to be stored in new file
					i++;//i++, to check if record found or not;
				}
				old_file.read( (char*)this , sizeof(*this) ); 
			}
			old_file.close();
			new_file.close();
			remove("Student Record.txt");  //removing old file
			rename("New.txt","Student Record.txt"); 	//renaming new file in which data is updated
														// with old one
			if(i==0)
			{
				//i++ is used here, if record not found then display no record fornd of that id.
				cout<<"No Record found of that I'd...!!"<<endl;
			}
			else
			{
				//if found, then display all including updated one.
				system("cls");
				cout<<"Record Updated...!!"<<endl;
				displayAll();
			}
		}
		else
		{
			cout<<"Record file doesn't open or doesn't available...!!"<<endl;
		}
	}
	void average_AllEvaluation()			//Function that will calculate averages from file
	{
		ifstream file;
		file.open("Student Record.txt");
		if(file.is_open())
		{
			file.read( (char*)this , sizeof(*this) );
			while(!file.eof())
			{
				//adding marks in avg variables
				avg_mid=avg_mid+mid;
				avg_final=avg_final+final;
				avg_quiz=avg_quiz+quiz1;
				avg_quiz=avg_quiz+quiz2;
				
				file.read( (char*)this , sizeof(*this) );
			}
			
			file.close();
		}
		else
		{
			cout<<"File doesn't open."<<endl;
		}
	}
	void MaxEeahEv()			//Function that will determine maximum marks data in file
	{
		float q1max,q2max,midmax,finmax;
		ifstream file;
		file.open("Student Record.txt");
		if(file.is_open())
		{
			file.read( (char*)this , sizeof(*this) );
			//assigning values of first record in variables to check with the next one record
			q1max=quiz1;
			q2max=quiz2;
			midmax=mid;
			finmax=final;
			while(!file.eof())
			{
				file.read( (char*)this , sizeof(*this) );
				//conditions to check if next records marks are high than previous one
				//then assign those marks to max: variables 
				if(quiz1>q1max)
				{
					q1max=quiz1;
				}
				if(quiz2>q2max)
				{
					q2max=quiz2;
				}
				if(mid>midmax)
				{
					midmax=mid;
				}
				if(final>finmax)
				{
					finmax=final;
				}
			}
			file.close();
		}
		//Displaying maximum values
		cout<<"Maximum Marks in Quiz 1:"<<q1max<<endl;
		cout<<"Maximum Marks in Quiz 2:"<<q2max<<endl;
		cout<<"Maximum Marks in Mid:"<<midmax<<endl;
		cout<<"Maximum Marks in Final:"<<finmax<<endl;
	}
	void MinEeahEv()			//Function that will determine minimum marks data in file
	{
		float q1min,q2min,midmin,finmin;
		ifstream file;
		file.open("Student Record.txt");
		if(file.is_open())
		{
			file.read( (char*)this , sizeof(*this) );
			//assigning values of first record in variables to check with the next one record
			q1min=quiz1;
			q2min=quiz2;
			midmin=mid;
			finmin=final;
			while(!file.eof())
			{
				file.read( (char*)this , sizeof(*this) );
				//conditions to check if next records marks are low than previous one
				//then assign those marks to min: variables
				if(quiz1<q1min)
				{
					q1min=quiz1;
				}
				if(quiz2<q2min)
				{
					q2min=quiz2;
				}
				if(mid<midmin)
				{
					midmin=mid;
				}
				if(final<finmin)
				{
					finmin=final;
				}
			}
			file.close();
		}
		//Displaying minimum marks
		cout<<"Minimum Marks in Quiz 1:"<<q1min<<endl;
		cout<<"Minimum Marks in Quiz 2:"<<q2min<<endl;
		cout<<"Minimum Marks in Mid:"<<midmin<<endl;
		cout<<"Minimum Marks in Final:"<<finmin<<endl;
	}
	void displayAll()			//Function that will display all data from file
	{
		ifstream dis;
		dis.open("Student Record.txt");
		while(!dis.eof())
		{	
			if( (dis.read( (char*)this , sizeof(*this))))
			{
				Display();
			}
			else
			{
				break;
			}
		}
	}
};
int Record::count=0;

int main()
{
	int ch;
	char na[20],se[10];
	int t,i,a,b,c;
	char id,q1,q2,mid,fin;
	Record r;
	while(ch!=11)		//press 11 to exit the program
	{
		//Main Menu...
a:
		cout<<"\t\t\t\xB2\xB2\xB2Welcome to XYZ School of Management's Portal\xB2\xB2\xB2"<<endl<<endl;
		cout<<"What do you want to do?\n1.Add Student Record?\n2.Delete a Particular Student Record?\n";
		cout<<"3.Update a Particular Student Record?\n4.Search a particular student by its name?\n";
		cout<<"5.View all Student Records?\n6.Calculate an average of Student’s scores in each Evaluation?\n";
		cout<<"7.Display the highest score of each evaluation?\n8.Display the lowest score of each";
		cout<<" evaluation?\n9.Display total number of student’s records?";
		cout<<"\n10.Display all student record in descending order in terms of final score?";
		cout<<"\n11.Exit.\nYour Choice:";
		cin>>ch;
		if(ch==1)  //Add Data
		{
			system("cls");
			cout<<"Enter Name:";
			cin>>na;
			t=strlen(na);
			try
			{
				for(i=0;i<t;i++)
				{
					if(na[i] >= 48 && na[i] <= 57)
					{
						throw(1);
					}
				}
			}
			catch(int a)
			{
				cout<<"Exception occured...!! Please give correct input...!!"<<endl;
				cout<<"Press any Key..!!"<<endl;
				getch();
				system("cls");
				goto a;
				
			}
			cout<<"Enter I'd:";
			cin>>id;
			try
			{
				if(id>=97 && id<=122)
				{
					throw('a');
				}
				else if(id>=65 && id<=90)
				{
					throw('A');
				}
				id-=48;
			}
			catch(char a)
			{
				cout<<"Exception occured...!! Please give correct input...!!"<<endl;
				cout<<"Press any Key..!!"<<endl;
				getch();
				system("cls");
				goto a;
			}
			cout<<"Enter Sex:";
			cin>>se;
			t=strlen(se);
			try
			{
				for(i=0;i<t;i++)
				{
					if(se[i] >= 48 && se[i] <= 57)
					{
						throw(1);
					}
				}
			}
			catch(int a)
			{
				cout<<"Exception occured...!! Please give correct input...!!"<<endl;
				cout<<"Press any Key..!!"<<endl;
				getch();
				system("cls");
				goto a;
				
			}
			cout<<"Enter Quiz 1 marks:";
			cin>>q1;
			try
			{
				if(q1>=97 && q1<=122)
				{
					throw('a');
				}
				else if(q1>=65 && q1<=90)
				{
					throw('A');
				}
				q1-=48;
			}
			catch(char a)
			{
				cout<<"Exception occured...!! Please give correct input...!!"<<endl;
				cout<<"Press any Key..!!"<<endl;
				getch();
				system("cls");
				goto a;
			}
			cout<<"Enter Quiz 2 marks:";
			cin>>q2;
			try
			{
				if(q2>=97 && q2<=122)
				{
					throw('a');
				}
				else if(q2>=65 && q2<=90)
				{
					throw('A');
				}
				q2-=48;
			}
			catch(char a)
			{
				cout<<"Exception occured...!! Please give correct input...!!"<<endl;
				cout<<"Press any Key..!!"<<endl;
				getch();
				system("cls");
				goto a;
			}
			cout<<"Enter Mid Marks:";
			cin>>mid;
			try
			{
				if(mid>=97 && mid<=122)
				{
					throw('a');
				}
				else if(mid>=65 && mid<=90)
				{
					throw('A');
				}
				mid-=48;
			}
			catch(char a)
			{
				cout<<"Exception occured...!! Please give correct input...!!"<<endl;
				cout<<"Press any Key..!!"<<endl;
				getch();
				system("cls");
				goto a;
			}
			cout<<"Enter Final Marks:";
			cin>>fin;
			try
			{
				if(fin>=97 && fin<=122)
				{
					throw('a');
				}
				else if(fin>=65 && fin<=90)
				{
					throw('A');
				}
				fin-=48;
			}
			catch(char a)
			{
				cout<<"Exception occured...!! Please give correct input...!!"<<endl;
				cout<<"Press any Key..!!"<<endl;
				getch();
				system("cls");
				goto a;
			}
			r.set_data(id,na,se);
			r.set_final(fin);
			r.set_mid(mid);
			r.set_quiz(q1,q2);
			r.add_record();
			cout<<endl<<"Record Set done...!!\nPress any key to go to Main Menu.";
			getch();
			system("cls");
		}
		else if(ch==2)		//Delete Data
		{
			system("cls");
			char del_id;
		b:
			cout<<"Enter I'd of student to delete the record:";
			cin>>del_id;
			try
			{
				if(del_id>=97 && del_id<=122)
				{
					throw('a');
				}
				else if(del_id>=65 && del_id<=90)
				{
					throw('A');
				}
				del_id-=48;
			}
			catch(char a)
			{
				cout<<"Exception occured...!! Please give correct input...!!"<<endl;
				cout<<"Press any Key..!!"<<endl;
				getch();
				system("cls");
				goto a;
			}
			r.delete_record(del_id);
			cout<<endl<<"Record Delete done...!!\nPress any key to go to Main Menu.";
			getch();
			system("cls");
		}
		else if(ch==3)		//Update data
		{
			system("cls");
			char upd_id;
		c:	
			cout<<"Enter I'd of student to Update the record:";
			cin>>upd_id;
			try
			{
				if(upd_id>=97 && upd_id<=122)
				{
					throw('a');
				}
				else if(upd_id>=65 && upd_id<=90)
				{
					throw('A');
				}
				upd_id-=48;
			}
			catch(char a)
			{
				cout<<"Exception occured...!! Please give correct input...!!"<<endl;
				cout<<"Press any Key..!!"<<endl;
				getch();
				system("cls");
				goto a;
			}
			r.UpdateRecord(upd_id);
			cout<<endl<<"Press any key to go to Main Menu.";
			getch();
			system("cls");
		}
		else if(ch==4) //Search by name
		{
			system("cls");
			char search[15];
			cout<<"Enter Name of student to search the record:";cin>>search;
			t=strlen(search);
			try
			{
				for(i=0;i<t;i++)
				{
					if(search[i] >= 48 && search[i] <= 57)
					{
						throw(1);
					}
				}
			}
			catch(int a)
			{
				cout<<"Exception occured...!! Please give correct input...!!"<<endl;
				cout<<"Press any Key..!!"<<endl;
				getch();
				system("cls");
				goto a;
			}
			r.search_by_name(search);
			cout<<endl<<"Press any key to go to Main Menu.";
			getch();
			system("cls");
		}
		else if(ch==5) //Display all data
		{
			system("cls");
			r.displayAll();
			cout<<endl<<"Press any key to go to Main Menu.";
			getch();
			system("cls");
		}
		else if(ch==6) //Average of all Evaluations
		{
			system("cls");
			int i;
			r.average_AllEvaluation();
			i=r.get_count();
			cout<<"Average of Mid Exam is:"<<r.get_avgMid()/i<<endl;
			cout<<"Average of Final Exam is:"<<r.get_avgFinal()/i<<endl;
			cout<<"Average of Quiz Exam is:"<<r.get_avgQuiz()/i<<endl;
			cout<<endl<<"Press any key to go to Main Menu.";
			getch();
			system("cls");
		}
		else if(ch==7)	//Maximum of All Evaluations[
		{
			system("cls");
			r.MaxEeahEv();
			cout<<endl<<"Press any key to go to Main Menu.";
			getch();
			system("cls");
		}
		else if(ch==8)		//Minimum of All ealuations
		{
			system("cls");
			r.MinEeahEv();
			cout<<endl<<"Press any key to go to Main Menu.";
			getch();
			system("cls");
		}
		else if(ch==9)		//total No. records
		{
			system("cls");
			cout<<"Total No. of Records of Student are:"<<r.get_count()<<endl;
			cout<<endl<<"Press any key to go to Main Menu.";
			getch();
			system("cls");
		}
		else if(ch==10) //Descending order in terms of Final exam...
		{
			system("cls");
			DescendingOrder();
			cout<<endl<<"Press any key to go to Main Menu.";
			getch();
			system("cls");
		}
		else if(ch==11)		//Exit the program
		{
			system("cls");
			system("color 6");
			cout<<"\t\t\t\xB2\xB2Thanks for Visiting Our School's Portal\xB2\xB2"<<endl;
			exit(1);
		}
		else		//Else condition
		{
			cout<<"Invalid Choice...!!"<<endl;
			cout<<endl<<"Press any key to go to Main Menu.";
			getch();
			system("cls");
		}
	}
	return 0;
}
void DescendingOrder()
{
	Record rr;
	int k,i=0,j=rr.get_count();
	Record re[j];
	ifstream file;
	file.open("Student Record.txt");
	if(file.is_open())
	{
		// First it will read one by one record from the file and will store
		// it the the array so that all records must be in array before arranging 
		// it for decsending order.
		file.read( (char*)&rr , sizeof(rr) );
		while(!file.eof())
		{
			//storing in array re[i]; i++ will move the pointer of array to next index
			// so that the next record must be stored in next index of the array
			re[i]=rr;
			i++;
			file.read( (char*)&rr , sizeof(rr) );
		}
	}
	else
	{
		cout<<"File doesn't open...!!"<<endl;
	}
	Record temp;  //temp: object so that if final marks are less that next one's final marks
				  //so that it may be temporary stored in that object. 
	for(i=0;i<j;i++)
	{
		for(k=i+1;k<j;k++)
		{
			if(re[i].get_final() < re[k].get_final()) //condition to checks final marks
			{
				temp=re[i];
				re[i]=re[k];
				re[k]=temp;
			}
		}
	}
	//Now all records are stored in descending order in the array re[j];
	//and displaying those records
	cout<<"Display all Records in Descending order in terms of Final Exam Marks."<<endl<<endl;
	for(i=0;i<j;i++)
	{
		re[i].Display();
	}
}
