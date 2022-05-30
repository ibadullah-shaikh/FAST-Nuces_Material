#include <iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;
};

class BubbleSort
{
    Node *head,*tail;

public:
    BubbleSort()
    {
        head = NULL;
        tail = NULL;
    }

    void addnode_end(int m)
    {
        Node *newnode = new Node;
        newnode->data=m;
        newnode->next = NULL;
        if (head==NULL && tail==NULL)
        {
            head = newnode;
            tail = newnode;
        }

        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        
    }

void swap_nodes(Node *n1 , Node *n2){
			Node *temp = n1->next;
			Node *ptr=  head;
			while(ptr->next != n2){
					
				ptr= ptr->next;
			}	
			if(n1 == head && n2 == tail){			//1 2 3 4 5 6
				head = n2;
				tail = n1;
				n2->next = temp;
				n1->next = NULL;
				
				head = n2;
				tail = n1;
				ptr->next = n1;
				return;
			}
			
			if(head == n1){
				Node *temp1= n1->next;
				Node *temp2 = ptr;
				temp2->next = n1;
				Node *t = n2->next;
				n2->next = n1->next;
				n1->next = t;
				head = n2;	
				return;
			}
			if(tail == n2){
				//cout << "s";
				//2 3 4 5
				
				Node *temp2 = n1->next;	
				Node *pt = head;		
				while(pt->next != n1 ){
					pt = pt->next;
				}
				ptr->next = n1;	//3 3
				
				
				
				if(n2 == n1->next){
					//temp2 = n1;
				}else{
					temp2 =  n1->next;
				}
				n1->next = NULL;
				cout << "data1 = "<<  temp2->data <<endl;
				n2->next = temp2;
				
				pt->next = n2;	
								
				
				tail = n1;				
				return;
			}						    //n1     n2
			Node *temp1 = n1->next;		//n2 for adjacnet
			Node *temp2 = n2->next;		//6			// 2 3 4 5 6 7		
			Node *ptr2 = head;			
			while(ptr2->next != n1){
				ptr2 = ptr2->next;
			}
			ptr2->next  =n2;		//ptr2 = 3
			ptr->next = n1;			//ptr = n1
			if(n2 == n1->next){			
					temp1 = n2;		
				}else{
					temp1 =  n1->next;
				}
				
			n1->next = temp2;
			
			n2->next = temp1;
						
			
			
			
} 
    void Bubble_Sort()
    {
        //Conditions:
        //(ptr->data<ptr2->data)Descending (larger to smaller)
        //(ptr->data>ptr2->data)Ascending (smaller to larger)

        Node *ptr = head;
        while(ptr->next!=NULL)
        {
            Node *ptr2 = ptr->next;
            while(ptr2!=NULL)
            {
                if (ptr->data > ptr2->data)                   
                {
                   swap_nodes(ptr,ptr2);
                }
                ptr2 = ptr2->next;
                
            }
            ptr = ptr->next;
        }
    }
    void display()
    {
        Node *ptr = head;
        while(ptr!=NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
};

int main()
{
    system("cls");
    BubbleSort B;
    B.addnode_end(2);
    B.addnode_end(5);
    B.addnode_end(3);
    B.addnode_end(8);
    B.Bubble_Sort();
    cout << "Sorted: ";
    B.display();
}
