#include<iostream>
#include<conio.h>
using namespace std;
template <class item,int size>
class SetOfItems
{
	item array[size];
	int count,i;
public:
	SetOfItems()  //default constructor to initialize by (i and count) 0
	{
		i=0;
		count=0;
	}
	void set_items(item x)  //setter to set items that user inputs
	{
		array[i]=x;
		i++;
		count++;
	}
	void AddItem(item a)  //function that will add a item to array
	{
		for(int i=0;i<=count;i++)
		{
			if(array[i]==a)
			{
				cout<<"Item already exists...!!"<<endl;
				
				break;
			}
			else if(i==count-1)
			{
				array[count]=a;
				count++;
				cout<<endl<<"Updated List:"<<endl;
				show_set();
				break;
			}
		}
	}
	void RemoveItem(item a)  //function that will remove an item from array
	{
		item arr[count];
		int c=0;
		for (i=0;i<count;i++)
		{
			if(array[i]==a)
			{
				continue;
			}
			else
			{
				arr[c]=array[i];
				c++;
			}
		}
		system("cls");
		cout<<"Updated List:"<<endl;
		for(i=0;i<c;i++)
		{
			cout<<arr[i]<<endl;
		}
	}
	void determine(item a)  // function to determine that user input item is on which position
	{
		int c=0;
		for(i=0;i<count;i++)
		{
			if(a==array[i])
			{
				c=i+1;
			}
			else
			{
				continue;
			}
		}
		if(c>0)
		{
			cout<<"Item "<<a<<" is at Position:"<<c<<endl;
		}
		if(c==0)
		{
			cout<<"No such item found...!!"<<endl;
		}
	}
	int get_count() const   //getter to get count of total array size
	{
		return count;
	}
	void show_set() //function to print array
	{
		cout<<"Total Items in set:"<<endl;
		for (int i=0;i<count;i++)
		{
			cout<<array[i]<<endl;
		}
	}
};
int main()
{
	int n,a;
	
	//For Integers...
	
	cout<<"For Integers...!!"<<endl<<endl;
	cout<<"Enter the size of Integer Array:";  //array size
	cin>>n;
	cout<<"Set items:";
	SetOfItems<int,100>obj;
	for (int i=0;i<n;i++)
	{
		cin>>a;
		obj.set_items(a);  //setting items
	}
	cout<<endl<<"Enter item to be added in Array:";cin>>a; //adding item
	obj.AddItem(a);
	
	cout<<endl<<"Enter item to be removed from Array:";cin>>a; //removing item
	obj.RemoveItem(a);

	cout<<endl<<"Enter item to determine:";cin>>a;  //determining item
	obj.determine(a);
	getch();
	cout<<endl<<"Total no. of Items:"<<obj.get_count()<<endl;  //printing total count of items
	system("cls");
	
	//For Floats...
	
	float b;
	cout<<"For float...!!"<<endl<<endl;
	cout<<"Enter the size of Float Array:";
	cin>>n;
	cout<<"Set items:";
	SetOfItems<float,100>obj1;
	for (int i=0;i<n;i++)
	{
		cin>>b;
		obj1.set_items(b);
	}
	cout<<endl<<"Enter item to be added in Array:";cin>>b;
	obj1.AddItem(b);
	
	cout<<endl<<"Enter item to be removed from Array:";cin>>b;
	obj1.RemoveItem(b);

	cout<<endl<<"Enter item to determine:";cin>>b;
	obj1.determine(b);
	getch();
	cout<<endl<<"Total no. of Items:"<<obj1.get_count()<<endl;
	system("cls");
	
	//For Characters
	char c;
	cout<<"For Character...!!"<<endl<<endl;
	cout<<"Enter the size of Float Array:";
	cin>>n;
	cout<<"Set items:";
	SetOfItems<char,100>ob;
	for (int i=0;i<n;i++)
	{
		cin>>c;
		ob.set_items(c);
	}
	cout<<endl<<"Enter item to be added in Array:";cin>>c;
	ob.AddItem(c);
	
	cout<<endl<<"Enter item to be removed from Array:";cin>>c;
	ob.RemoveItem(c);

	cout<<endl<<"Enter item to determine:";cin>>c;
	ob.determine(c);
	getch();
	cout<<endl<<"Total no. of Items:"<<ob.get_count()<<endl;
	system("cls");

	//For Strings
	string s;
	cout<<"For Strings...!!"<<endl<<endl;
	cout<<"Enter the size of Float Array:";
	cin>>n;
	cout<<"Set items:";
	SetOfItems<string,100>obj2;
	for (int i=0;i<n;i++)
	{
		cin>>s;
		obj2.set_items(s);
	}
	cout<<endl<<"Enter item to be added in Array:";cin>>s;
	obj2.AddItem(s);
	
	cout<<endl<<"Enter item to be removed from Array:";cin>>s;
	obj2.RemoveItem(s);

	cout<<endl<<"Enter item to determine:";cin>>s;
	obj2.determine(s);
	getch();
	cout<<endl<<"Total no. of Items:"<<obj2.get_count()<<endl;
	system("cls");
}
