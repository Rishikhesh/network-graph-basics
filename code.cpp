#include <stdlib.h>
#include <conio.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

int f =0,i;
int x=0,n,h=0,q=1;

struct friends
{
	string fname;
	struct friends *side;
}*tem,*nwf,*top1,*tem2,*top2;

struct members
{
	string mname;
	int fr;
	struct members *down;
	struct friends *right;
}*top,*bottom,*nw,*temp,*temp2;

struct mutual
{
	string mfname;
	int c;
	struct mutual *nxt;
}*topm=NULL,*bottomm=NULL,*tempm=NULL,*nwm;

void addmember()
{
	temp = top;
	int p=1;
	string newname;
	cout<<" Enter the name of the new member "<<f+1<<" :";
    getline(cin,newname);
	while(temp != NULL)
	{
		if(temp->mname == newname)
	        {
			p = 0;
			break;
		}
		temp=temp->down;
	}
	if(p==1)
	{
		members *nw = new (struct members);
	        nw->mname = newname;
		nw->down = NULL;
		nw->right = NULL;
		nw->fr = 0;
		if(top!=NULL)
		{
			bottom->down = nw;
			bottom = nw;
		}
		else
		{
			top = nw;
			bottom = nw;
		}
		f++;
		h=f;
	}
	else
	{
		cout<<endl<<" ALREADY EXISTING MEMBER\n";
	        h = h-1;
	        i = i-1;
	}
}

void addfriend()
{
	int g=0,e=0;
	string nwname;
	cout<<"Enter the name of the friend "<<x+1<<" :";
	getline(cin,nwname);
	temp2 = top;
	while(temp2 != NULL)
	{
		if(temp2->mname == nwname)
        {
			g = 1;
			break;
		}
		temp2 = temp2->down;
	}
	tem = temp->right;
	while(tem != NULL)
	{
		if(tem->fname == nwname)
		{
			e = 1;
			x = x-1;
			break;
		}
		tem = tem->side;
	}
	if(e == 0)
	{
		if(g == 1)
		{
			if(nwname != temp->mname)
			{
				temp->fr = (temp->fr)+1;
				friends *nwf = new(friends);
				nwf->fname = nwname;
				nwf->side = NULL;
				if(temp->right == NULL)
				{
					temp->right = nwf;
				}
				else
				{
					top1 = temp->right;
					while(top1->side != NULL)
                    {
                        top1 = top1->side;
                    }
                    top1->side = nwf;
				}
			}
			else
			{
				cout<<endl<<" OOPS you have entered the member itself"<<endl;
				x = x-1;
			}
		}
		else
		{
			cout<<endl<<" ****MEMBER NOT FOUND IN THE NETWORK****"<<endl;
			x = x-1;
		}
	}
	else
	{
		cout<<endl<<" ALREADY EXISTING AS A FRIEND"<<endl;
	}
}

void addfriendnew()
{
	int v,i;
    do
	{
		cout<<endl<<" Enter the number of friends of "<<bottom->mname<<" :";
		cin>>v;
		if(v<f)
		{
			temp = bottom;
			cin.ignore();
			for(x=0;x<v;x++)
			{
				addfriend();
			}
			break;
		}
		else
		{
			cout<<endl<<" Number of friends are exceeding number of members left";
		}
	}while(v>=f);
}

void printnetwork()
{
	int g;
	temp=top;
	cout<<endl<<" TOTAL NUMBER OF MEMBERS IN THIS NETWORK ARE :"<<f;
	while(temp != NULL)
	{
		cout<<endl<<" -> "<<temp->mname<<" has "<<temp->fr<<" friends";
		tem=temp->right;
		g=1;
		cout<<endl<<" Friends of "<<temp->mname<<" are ";
		if(tem == NULL)
            cout<<0;
		while(tem != NULL)
		{
			cout<<endl<<"\t"<<g++<<". "<<tem->fname;
			tem = tem->side;
		}
		temp = temp->down;
	}
}

void addmutual()
{
	int h = 1;
	tempm = topm;
	while(tempm != NULL)
	{
		if(tempm->mfname == tem2->fname )
		{
			h=0;
			break;
		}
		tempm = tempm->nxt;
	}

	if(h == 1)
	{
		mutual *nwm = new(struct mutual);
		nwm->mfname = tem2->fname;
		nwm->c = 1;
		nwm->nxt = NULL;
		if(topm == NULL)
		{
			topm=bottomm = nwm;
		}
		else
    		{
			bottomm->nxt = nwm;
			bottomm = nwm;
		}
	}
}

void printmutual()
{
	int b = 0;
	string sname;
	temp = top;
	cout<<endl<<" Enter the person who's mutual to be found:";
	cin.ignore();
	getline(cin,sname);
	tem = NULL;
	while(temp != NULL)
	{
		if(temp->mname == sname)
		{
			tem = temp->right;
			b = 1;
			break;
		}
		temp = temp->down;
	}
	if(b == 1)
	{
		while(tem != NULL)
		{
			temp2 = top;
			while(temp2 != NULL)
			{
				if(temp2->mname == tem->fname)
				{
					tem2 = temp2->right;
					while(tem2 != NULL)
					{
						addmutual();
						tem2 = tem2->side;
                    			}
				}
               			 temp2 = temp2->down;
			}
            		tem = tem->side;
		}
		tem = temp->right;
		while(tem != NULL)
		{
			tempm = topm;
			while(tempm != NULL)
			{
				if(tempm->mfname == tem->fname)
				{
					tempm->c = -1;
					break;
				}
				tempm = tempm->nxt;
			}
			tem = tem->side;
		}

 		tempm = topm;
		cout<<endl<<" Mutual friends of "<<sname<<" are :"<<endl;
		while(tempm != NULL)
		{
			if(sname != tempm->mfname && tempm->c > 0)
			{
					cout<<tempm->mfname<<endl;
            }
			tempm = tempm->nxt;
 		}
 		tempm = topm;
 		while(topm != NULL)
        {
            topm = topm->nxt;
            delete(tempm);
            tempm = topm;
        }
	}
	else
	cout<<endl<<" MEMBER DOES NOT EXIST";
}

void addfriendalone()
{
	int g=1;
	string nam;
	cout<<endl<<" Enter the name of the member for whom new friend should be added:";
	cin.ignore();
	getline(cin,nam);
	temp = top;
	x = 0;
	while(temp != NULL)
	{
		if(nam == temp->mname)
		{
			top1 = temp->right;
			top2 = temp->right;
			g = 0;
			break;
		}
		temp = temp->down;
	}
	while(top2 != NULL)
	{
		top2 = top2->side;
		x = x+1;
	}
	if(x < f-1)
	{
		if(g==0)
            addfriend();
        cout<<endl<<"Friend added for "<<temp->mname<<" successfully !!";
	}
	else
	cout<<endl<<" MEMBER HAS MAXIMUM NUMBER OF FRIENDS";
	if(g==1)
	{
		cout<<"\n***MEMBER NOT FOUND***\n";
	}
}

void deletefriend()
{
	int g=0,h=0;
	string dname,dnam;
	cout<<endl<<" Enter the name from which you should delete:";
	cin.ignore();
	getline(cin,dname);
	temp = top;
	while(temp != NULL)
	{
		if(temp->mname == dname)
		{
			tem = temp->right;
			if(temp->right == NULL)
			{
				cout<<endl<<" there are no friends for "<<temp->mname;
				h = 1;
			}
			tem2 = tem;
			g = 1;
			break;
		}
		temp = temp->down;
	}
	if(g==0)
	{
		cout<<endl<<"\t***MEMBER not found***";
		h=2;
	}
	if(g==1 && h==0)
	{
		cout<<endl<<" Enter the friend to be removed:";
		getline(cin,dnam);
		while(tem != NULL)
		{
			if(tem->side != NULL)
			{
				if(tem->side->fname == dnam)
				{
					tem2 = tem2->side;
					tem->side = tem2->side;
					delete(tem2);
					h=3;
					break;
				}
				else if(tem->fname == dnam)
				{
					temp->right = tem->side;
					h = 3;
					break;
				}
				tem = tem->side;
				tem2 = tem2->side;
			}
			else
			{
				if(tem->fname == dnam)
				{
					temp->right=NULL;
					tem=NULL;
					h=3;
					break;
				}
          			else
				{
					tem=tem->side;
					h=4;
				}
			}
		}
	}
	if(h==4)
	cout<<endl<<dnam<<" is not a friend of "<<dname;
	if(g==1 && h==3)
	{
		cout<<endl<<" DELETED SUCCESSFULLY";
		temp->fr = temp->fr-1;
	}

}
int main()
{
	
	int l=0,choice;
	top=NULL;
	top1=NULL;
	bottom=NULL;
	temp=NULL;
	temp2=NULL;
	cout<<endl<<"\t\t\t\t\t\t\t***LETS CREATE A NETWORK TO BEGIN*** \n\nEnter the number of members at the beginning of the network:";
	cin>>n;
	cin.ignore();
	for(i=0;i<n;i++)
	{
		addmember();
	}
	temp=top;
	while(temp!=NULL)
	{
		do
		{
			cout<<endl<<" Enter the number of friends of "<<temp->mname<<" (should be less than number of members in the network):";
			cin>>l;
		}while(l>=f);
		cin.ignore();
		for(x=0;x<l;x++)
		{
			addfriend();
		}
		cout<<endl<<" FRIENDS ADDED FOR "<<temp->mname<<" SUCCESSFULLY";
		temp = temp->down;
	}
	cout<<endl<<endl<<"*****NOW THE NETWORK HAS BEEN SUCCESSFULLY CREATED*****";
	getch();
	do
	{
        system("cls");
        cout<<endl<<" Now select the action to be performed in this network :";
		cout<<endl<<" 1. Add a member to the network"<<endl<<" 2. Show friend suggestion for a member";
		cout<<endl<<" 3. Add a friend to existing member "<<endl<<" 4. Delete a friend of existing member"<<endl<<" 5. Display the network"<<endl<<" 6. Exit"<<endl<<" Enter your choice:";
        cin>>choice;
		switch (choice)
		{
			case 1:
			    cin.ignore();
				do
				{
					addmember();
				}while(h<f);
				cout<<"\nMEMBER ADDED SUCCESSFULLY IN THIS NETWORK";
				addfriendnew();
				cout<<"\n FRIENDS ADDED SUCCESSFULLY FOR THE NEW MEMBER";
				getch();
				break;
			case 2:
				printmutual();
				q=q+1;
				getch();
				break;
			case 3:
				addfriendalone();
				getch();
				break;
			case 4:
				deletefriend();
				getch();
				break;
			case 5:
				printnetwork();
				getch();
				break;
			default:
				break;
		}
	}while(choice<=5);
	return 0;
}
