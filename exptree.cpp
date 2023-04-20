#include<iostream>
#include<stack>
using namespace std;

struct treenode
{
	char data;
	treenode *left;
	treenode *right;
};//End of structure treenode

class exptree
{
	public:
		treenode *root;
		void construct();
		void inorder(treenode* root);
		void nonRecursiveInorder();
		void nonRecursivePreorder();
		void nonRecursivePostorder();
		void deleteEntireTree(treenode* root);
};//End of class expression tree

void exptree::construct()
{
	stack<treenode *>S;
	treenode *current,* temp1,* temp2;
	string preFixExp;
	char ch;
	cout<<"Enter any Prefix Expression:"<<endl;
	cin>>preFixExp;
	
	int L = preFixExp.size();
	
	for(int i=L-1;i>=0;i--)
	{
		ch=preFixExp[i];
		current = new treenode;
		current->data = ch;
		current->left = current->right;
		
		if(ch>='a' && ch<='z')
		{
			S.push(current);
		}//End of if
		else
		{
			temp1 = S.top();
			S.pop();
			
			temp2 = S.top();
			S.pop();
			
			current->left=temp1;
			current->right=temp2;
			
			S.push(current);
		}//End of else
		
	}//End of for loop
	
	root = S.top();
		
}//End of function construct

void exptree::inorder(treenode *root)
{
	if (root!=NULL)
	{
		inorder(root->left);
		cout<<root->data;
		inorder(root->right);
	}
}//End of function exptree

void exptree::nonRecursiveInorder()
{
	stack<treenode *>S;
	treenode *temp = root;
	do
	{
		while(temp!=NULL)
		{
			S.push(temp);
			temp = temp->left;
		
		}
		if(!S.empty())
		{
			temp = S.top();
			S.pop();
			
			cout<<temp->data;
			
			temp = temp->right;
		}
		
		else
		{
			break;
		}
		
	}while(1);
	
}//End of nonRecursiveInorder

void exptree::nonRecursivePreorder()
{
	stack<treenode *>S;
	treenode *temp = root;
	do
	{
		while(temp!=NULL)
		{
			cout<<temp->data;
			S.push(temp);
			temp = temp->left;
		
		}
		if(!S.empty())
		{
			temp = S.top();
			S.pop();
			
			temp = temp->right;
		}
		
		else
		{
			break;
		}
		
	}while(1);
	
}//End of nonRecursivePreorder


void exptree::nonRecursivePostorder()
{
	stack<treenode *>S;
	stack<char >S1;
	
	treenode *temp = root;
	
	do
	{
		while(temp!=NULL)
		{
			S.push(temp);
			S1.push('l');
			temp = temp->left;
		}
		if(!S.empty())
		{
			temp=S.top();
			S.pop();
			char ret=S1.top();
			S1.pop();
			if(ret=='l')
			{
				S.push(temp);
				S1.push('r');
				temp = temp->right;
			}
			else
			{
				cout<<temp->data;
				temp=NULL;
			}
		}
		else
		{
			break;
		}
	}while(1);
}		
void deleteEntireTree(treenode* root)
{
    if (root == NULL) return;
 
    /* first delete both subtrees */
    deleteEntireTree(root->left);
    deleteEntireTree(root->right);
     
    /* then delete the node */
    cout << "\n Deleting node: " << root->data;
    delete root;
}
//End of function deleteEntireTree	
int main()
{
    
    exptree E;
    while(true)
    {
    	cout<<"\nChoice Menu"<<endl;
    	cout<<"(1)Construct a tree(Enter any prefix expression)."<<endl;
    	cout<<"(2)Inorder traversal."<<endl;
    	cout<<"(3)Non Reccursive Inorder traversal."<<endl;
    	cout<<"(4)Non Recursive Preorder traversal."<<endl;
    	cout<<"(5)Non Recursive Postorder traversal."<<endl;
    	cout<<"(6)Delete entire tree node by node."<<endl;
    	
    	
    	int ch;
    	cout<<"Enter your choice:"<<endl;
    	cin>>ch;
    	if(ch==1)
    	{
    		E.construct();
    	}
    	else if(ch==2)
    	{
    		E.inorder(E.root);
    	}
    	else if(ch==3)
    	{
    		E.nonRecursiveInorder();
    	}
    	else if(ch==4)
    	{
    		E.nonRecursivePreorder();
    	}
    	else if(ch==5)
    	{
    		E.nonRecursivePostorder();
    	}
		else if(ch==6)
		{
			deleteEntireTree(E.root);
			cout<<"\n\n Deleted entire tree using postorder traversal."<<endl;
		}
		else if(ch==7)
		{
			exit(0);
			cout<<"Exiting the program."<<endl;
		}
		else
		{
			cout<<"Wrong choice entered! Enter correct choice."<<endl;
		}
    }
    return 0;
}
