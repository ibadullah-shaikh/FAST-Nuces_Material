#include<iostream>
#include<string.h>
#include<fstream>
#define STACK 80
using namespace std;
struct Stack
{
	int top, items[STACK];
}ptr;
class PostFix_PreFix
{
	string exp;
	int exp_count;
public:
	PostFix_PreFix()
	{
		exp_count=0;
	}
	void set_Exp()
	{
		ifstream file;
		file.open("inputA2P3.txt");
		if(!file)
		{
			cout<<"File not found...!!"<<endl;
			exit(1);
		}
		file>>exp;
		file.close();
		exp_count=exp.length();
	}
	void InfixToPostfix()
	{
		string postfix;
		int count=0;
		int i;
		for(i=0;i<exp_count;i++)
		{
			if((exp[i]>='a' && exp[i]<='z') || (exp[i]>='A' && exp[i]<='Z') || (exp[i]>=49 && exp[i]<=57))
			{
				postfix+=exp[i];
				count++;
			}
			else if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
			{
				Push(exp[i]);
			}
			else if(exp[i]==')' || exp[i]==']' || exp[i]=='}')
			{
				while( (peek()!='(' || peek()=='[' || peek()=='{') && (!Empty()) )
				{
					char temp=peek();
					postfix+=temp;
					count++;
					Pop();
				}
			}
			else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='^' || exp[i]=='/')
			{				
				if(Empty())
				{
					Push(exp[i]);
				}
				else
				{
					if(Precedence(exp[i])>Precedence(peek()))
					{
						Push(exp[i]);
					}
					else if( (Precedence(exp[i])==Precedence(peek())) &&  (exp[i]=='^') )
					{
						Push(exp[i]);
					}
					else
					{
						while( (!Empty()) && (Precedence(exp[i])<= Precedence(peek()) ) )
						{
							char temp=peek();
							postfix+=temp;
							count++;
							Pop();
						}
						Push(exp[i]);
					}
				}
			}
		}
		while((!Empty()))
		{
			char temp=peek();
			postfix+=temp;
			count++;
			Pop();
		}
		ofstream file;
		file.open("outputA2P3.txt",ios::trunc);
		file<<"Postfix: ";
		for(i=0;i<count;i++)
		{
			if(postfix[i]=='(' || postfix[i]=='[' || postfix[i]=='{')
			{
				continue;
			}
			file<<postfix[i];
			cout<<postfix[i]<<" ";
		}
		cout<<endl;
		file<<endl<<endl;
		file.close();
	}
	void InfixToPrefix()
	{
		string prefix;
		int count=0,i;
		for(i=0;i<exp_count;i++)
		{
			if(exp[i]=='(')
			{
				exp[i]=')';
			}
			if(exp[i]=='{')
			{
				exp[i]='}';
			}
			if(exp[i]=='[')
			{
				exp[i]=']';
			}
			if(exp[i]==')')
			{
				exp[i]='(';
			}
			if(exp[i]=='}')
			{
				exp[i]='{';
			}
			if(exp[i]==']')
			{
				exp[i]='[';
			}
		}
		for(i=0;i<exp_count;i++)
		{
			if((exp[i]>='a' && exp[i]<='z') || (exp[i]>='A' && exp[i]<='Z') || (exp[i]>=49 && exp[i]<=57))
			{
				prefix+=exp[i];
				count++;
			}	
			else if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
			{
				Push(exp[i]);
			}
			else if(exp[i]==')' || exp[i]==']' || exp[i]=='}')
			{
				while( (peek()!='(' || peek()=='[' || peek()=='{') && (!Empty()) )
				{
					char temp=peek();
					prefix+=temp;
					count++;
					Pop();
				}
			}
			else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='^' || exp[i]=='/')
			{				
				bool ans=false;
				while(ans==false)
				{
					ans=true;
					if(Empty())
					{
						Push(exp[i]);
					}
					else if(Precedence(exp[i])>=Precedence(peek()))
					{
						Push(exp[i]);
						ans=true;
					}
					else
					{
						prefix+=peek();
						count++;
						Pop();
						ans=false;
					}
				}
			}
		}
		while((!Empty()))
		{
			char temp=peek();
			prefix+=temp;
			count++;
			Pop();
		}
		char temp;
		for(i=0;i<count/2;i++)
		{
			temp=prefix[i];
			prefix[i]=prefix[count-i-1];
			prefix[count-i-1]=temp;
		}
		ofstream file;
		file.open("outputA2P3.txt", ios::app);
		file<<"Prefix: ";
		for(i=0;i<count;i++)
		{
			if(prefix[i]=='(' || prefix[i]=='[' || prefix[i]=='{')
			{
				continue;
			}
			file<<prefix[i];
			cout<<prefix[i]<<" ";
		}
		cout<<endl;
		file.close();
	}
	void reverse()
	{
		int i;
		char temp;
		for(i=0;i<exp_count/2;i++)
		{
			temp=exp[i];
			exp[i]=exp[exp_count-i-1];
			exp[exp_count-i-1]=temp;
		}
	}
	int Precedence(char a)
	{
		if(a=='^')
		{
			return 3;
		}
		else if(a=='*' || a=='/')
		{
			return 2;
		}
		else if(a=='+' || a=='-')
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	int peek()
	{
		return ptr.items[ptr.top];
	}
	void Push(int a)
	{
		if(Full())
		{
			cout<<"Stack Overflow."<<endl;
			
		}
		else
		{
			ptr.items[++ptr.top]=a;
		}
	}
	void Pop()
	{
		if(Empty())
		{
			cout<<"Stack underflow"<<endl;
		}
		else
		{
			ptr.items[ptr.top--];
		}
	}
	bool Full()
	{
		if(ptr.top==STACK)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool Empty()
	{
		if(ptr.top==0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void Display()
	{
		int i;
		for(i=0;i<exp_count;i++)
		{
			cout<<exp[i]<<" ";
		}
		cout<<endl<<endl;
	}
};
int main()
{
	PostFix_PreFix exp;
	exp.set_Exp();
	system("cls");
	cout<<"Expression: ";
	exp.Display();
	cout<<"Postfix: ";
	exp.InfixToPostfix();
	exp.reverse();
	cout<<"Prefix: ";
	exp.InfixToPrefix();
//	exp.reverse();
}
