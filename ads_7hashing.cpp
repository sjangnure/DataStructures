#include<iostream>
using namespace std;
class hashing
{
	int max;
	int tablekey[20];
	int tablechain[20];
	int i,j;
	int loc;
public:
	hashing(int max)
	{
		this->max=max;
		for(i=0;i<max;i++)
		{
			tablekey[i]=0;
		}
		for(i=0;i<max;i++)
		{
			tablechain[i]=-1;
		}
	}
	void hash1(int);
	void hash2(int);
	void hash3(int);
	void display();
};
void hashing::hash1(int key)	//linear probing
{
	 loc=key%max;
	 while(tablekey[loc]!=0)
		 {
			 loc=loc+1;
			 if(loc==max)
				 loc=0;
		 }
		 tablekey[loc]=key;
}
void hashing::hash2(int key)	//linear probing with chaining
{
	loc=key%max;	//for keys
	int loc1;		//for chains
	loc1=loc;
	if(tablekey[loc]==0)
		tablekey[loc]=key;
	else
	{
		while(tablekey[loc]!=0)
		{
			if(tablechain[loc]==-1)
			{
				loc=loc+1;
				if(loc==max)
				loc=0;
			}
			else
			{
				loc=tablechain[loc];
				loc1=loc;
			}	
		}
		tablechain[loc1]=loc;
		tablekey[loc]=key;
	}
}
void hashing::hash3(int key)
{
	loc=key%max;	//for keys
	int loc1,loc2;		//for chains
	loc1=loc;
	loc2=loc;
	if(tablekey[loc]==0)		//case 1:hash location is empty
		tablekey[loc]=key;
	else if(tablekey[loc]%max==loc)/*case 2:location has a synonym*/
	{
		while(tablechain[loc]!=-1)	//traverse the chains
		{
			loc=tablechain[loc];	
		}
		loc1=loc;
		while(tablekey[loc]!=0)	//search for next free location
		{
			loc=(loc+1)%max;
		}
		tablekey[loc]=key;
		tablechain[loc1]=loc;
		/*	while(tablekey[loc]!=0)
		{
			if(tablechain[loc]==-1)
			{
				loc=loc+1;
				if(loc==max)
				loc=0;
			}
			else
			{
				loc=tablechain[loc];
				loc1=loc;
			}	
		}
		tablechain[loc1]=loc;
		tablekey[loc]=key;*/
	
	}
	else 
	{
		/*loc1=tablekey[loc]%max;
		loc1=tablechain[loc1];*/
		for(int i=0;i<max;i++)
		{
			if(tablechain[i]==loc)
			{
				loc1=i;
				break;
			}
		}
		tablechain[loc1]=tablechain[loc];
		while(tablechain[loc1]!=-1)	//traverse the chains
		{
			loc1=tablechain[loc1];	
		}
		while(tablekey[loc]!=0)	//search for next free location
		{
			loc=(loc+1)%max;
		}
		tablechain[loc1]=loc;
		tablekey[loc]=tablekey[loc2];
		tablechain[loc2]=-1;
		tablekey[loc2]=key;
	}
}
void hashing::display()
{
	for(i=0;i<max;i++)
	{
		cout<<tablekey[i]<<"\t"<<tablechain[i]<<endl;
	}
}
int main()
{
	int key,max;
	static int track;
	char choice;
	int ch;
	cout<<"Enter the size of hash table";
	cin>>max;
	hashing obj(max);
	cout<<"Enter your choice\n1.Linear probling\n2.Linear probilng with chaining";
	cout<<"\n3.Linear probing with chaining with replacement";
	cin>>ch;
		switch (ch)
		{
		case 1:
			{
				track=0;
			do{
				
				cout<<"Enter the numbers";
				cin>>key;
				track++;
				obj.hash1(key);
					if(track==max)
					{
						cout<<"hash table size out of bounds";
						break;
					}
					cout<<"Do you want to continue?";
					cin>>choice;
			}while(choice!='n');
			obj.display();
			break;
			}
		case 2:
			do {
				track=0;	
				cout<<"Enter the numbers";
				cin>>key;
				track++;
				obj.hash2(key);
				if(track==max)
					{
						cout<<"hash table size out of bounds";
						break;
					}
						cout<<"Do you want to continue?";
						cin>>choice;
				}while(choice!='n');
				obj.display();
			break;
		
		case 3:
			do {
				track=0;	
				cout<<"Enter the numbers";
				cin>>key;
				track++;
				obj.hash3(key);
				if(track==max)
					{
						cout<<"hash table size out of bounds";
						break;
					}
						cout<<"Do you want to continue?";
						cin>>choice;
				}while(choice!='n');
				obj.display();
			break;
		default:
			cout<<"Invalid choice";
		}
	return 0;
}
