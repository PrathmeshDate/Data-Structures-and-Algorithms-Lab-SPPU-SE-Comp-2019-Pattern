#include <iostream>
using namespace std;
struct treenode
{
	int data;
	treenode *left, *right;
};
//End of struct treenode
class BST
{
	public:
		treenode *root;
		BST()
		{
			root=NULL;
		}
		treenode *create();
		int minValue(struct treenode* root);
		int maxValue(struct treenode* root);
		void inorder_rec(treenode *root);
		void preorder_rec(treenode *root);
		void postorder_rec(treenode *root);
		int search(int key);
		int maxDepth(treenode* root);
		treenode *insert(treenode *root, int num);
};
//End of class BST
treenode *BST::create()
{
	treenode *current, *temp;
	char ans;
	do
	{
		current=new treenode;
		cout<<"Enter a value to add in BST : "<<endl;
		cin>>current->data;

		if (root==NULL)
		{
			root=current;
		}
		else
		{
			temp=root;
			while(1)
			{
				if(current->data < temp->data)
				{
					if (temp->left==NULL)
					{
						temp->left=current;
						break;
					}
					else
					{
						temp=temp->left;
					}
				}
				else
				{
					if (temp->right==NULL)
					{
						temp->right=current;
						break;
					}
					else
					{
						temp=temp->right;
					}
				}
			}
		}
		cout<<"Do you want to add more nodes?"<<endl;
		cin>>ans;
	}while(ans=='y' || ans=='Y');
	return root;
}
//End of function create.
void BST::inorder_rec(treenode *root)
{
	if (root!=NULL)
	{
		inorder_rec(root->left);
		cout<<root->data<<" ";
		inorder_rec(root->right);
	}
}
//End of function inorder recursive traversal.
void BST::preorder_rec(treenode *root)
{
	if (root!=NULL)
	{
		cout<<root->data<<" ";
		preorder_rec(root->left);
		preorder_rec(root->right);
	}
}
//End of function preorder recursive traversal.
void BST::postorder_rec(treenode *root)
{
	if (root!=NULL)
	{
		postorder_rec(root->left);
		postorder_rec(root->right);
		cout<<root->data<<" ";
	}
}
//End of function postorder recursive traversal.
int BST::search(int key)
{
	treenode* temp;
	temp=root;
	while(temp!=NULL)
	{
		if(temp->data==key)
		{
			return 1;
		}
		else
		{
			if(key<temp->data)
			{
				temp=temp->left;
			}
			else
			{
				temp=temp->right;
			}
		}
	}
	return 0;
}
//End of function search
int BST::minValue(struct treenode* root)
{
	struct treenode* current = root;
	
	while (current->left != NULL)
	{
    	current = current->left;
	}
	return(current->data);
}
//End of function minValue.
int BST::maxValue(struct treenode* root)
{
	struct treenode* current = root;
	
	while (current->right != NULL)
	{
    	current = current->right;
	}
	return(current->data);
}
//End of function maxValue.
int BST::maxDepth(treenode* root)
{
    if (root == NULL)
        return 0;
    else
    {
     
        int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);
     
        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
}
//End of function maxDept to find the number of nodes in the longest path from the root.
treenode *BST::insert(treenode *root, int num)
{
	treenode *current, *temp;
	current=new treenode;
	current->data=num;
	if (root==NULL)
	{
		root=current;
	}
	else
	{
		temp=root;
			while(1)
			{
				if(current->data < temp->data)
				{
					if (temp->left==NULL)
					{
						temp->left=current;
						break;
					}
					else
					{
						temp=temp->left;
					}
				}
				else
				{
					if (temp->right==NULL)
					{
						temp->right=current;
						break;
					}
					else
					{
						temp=temp->right;
					}
				}
			}
	}
	return root;
}
//End of insert function.
void mirror(struct treenode* root)
{
    if (root == NULL)
        return;
    else
    {
        struct treenode* temp;
         
        /* do the subtrees */
        mirror(root->left);
        mirror(root->right);
     
        /* swap the pointers in this node */
        temp     = root->left;
        root->left = root->right;
        root->right = temp;
    }
}
//End of mirror function.
int main()
{
	BST b;
	treenode *addofroot=b.create();
	int choice;
	while(true)
	{
		cout<<"\n \t\t\t***Choice Menu***"<<endl;
		cout<<"(1)Inorder Recursive Traversal."<<endl;
		cout<<"(2)Preorder Recursive Traversal."<<endl;
		cout<<"(3)Postorder Recursive Traversal."<<endl;
		cout<<"(4)Insert a node in BST."<<endl;
		cout<<"(5)Search a node in BST."<<endl;
		cout<<"(6)Maximum and minimum value node in BST."<<endl;
		cout<<"(7)Find number of nodes in longest path from root."<<endl;
		cout<<"(8)Change a tree so that the roles of the left and right pointers are swapped at every node."<<endl;
		cout<<"(9)Exit the program."<<endl;

		cout<<"Enter your choice:"<<endl;
		cin>>choice;
	
		if(choice==1)
		{
			cout<<"Inorder traversal(Recursive):"<<endl;
			b.inorder_rec(addofroot);
		}
		else if(choice==2)
		{
			cout<<"\nPreorder traversal(Recursive):"<<endl;
			b.preorder_rec(addofroot);
		}
		else if(choice==3)
		{
			cout<<"\nPostorder traversal(Recursive):"<<endl;
			b.postorder_rec(addofroot);
		}
		else if(choice==4)
		{
			int num;
			cout<<"Enter number which you want to insert:"<<endl;
			cin>>num;
			b.insert(addofroot,num);			
		}
		else if(choice==5)
		{
			int node_search;
			cout<<"\nEnter node which you want to search:"<<endl;
			cin>>node_search;
			int res=b.search(node_search);
			if(res==1)
			{
				cout<<"Node is present in BST."<<endl;
			}
			else
			{
				cout<<"Node is not present in BST."<<endl;
			}
		}
		else if(choice==6)
		{
			cout<<"\nThe minimum value in BST is:"<<b.minValue(addofroot);
			cout<<"\nThe maximum value in BST is:"<<b.maxValue(addofroot);
		}
		else if(choice==7)
		{
			cout<<"\nThe number of nodes in longest path from root: "<<b.maxDepth(addofroot)<<endl;
		}
		else if(choice==8)
		{
			mirror(addofroot);
			cout<<"Successifuly created mirror of given tree.(To chcek do inorder traversal)."<<endl;
		}
		else if(choice==9)
		{
			cout<<"Exiting the program!"<<endl;
		}  
		else
		{
			cout<<"Wrong choice entered! Enter correct choice again."<<endl;
		}
	}
	
	return 0;
}
//End of main function.
