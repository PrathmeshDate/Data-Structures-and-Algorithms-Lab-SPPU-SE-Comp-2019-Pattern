#include<iostream>
using namespace std;
struct treenode
{
    string word,meaning;
    treenode *left,*right;  
};
//End of struct treenode.
class BST
{
	public:
		treenode *root;
		BST()
		{
			root=NULL;
		}
		
		void insert();
     	void inorder(treenode*);
     	void inorder_desc(treenode*);
       	void search(string);
        void deletion(treenode*& root, int item);
        treenode* findMinimum(treenode* cur);
        treenode* deleteword(treenode* root, string key);
        treenode* minimum(treenode* root);
        void update(treenode* root, string key);
 
};
//End of class BST.
void BST::insert()
{
     treenode *curr,*temp;
     curr=new treenode;
     cout <<"\nEnter any word:"<<endl;
     cin >> curr->word;
     cout<<"\nEnter meaning of the word:"<<endl;
     cin>>curr->meaning;
     
     curr->left=curr->right=NULL;
     
     if (root==NULL)
        root=curr;
     else
     {
          temp=root;
          while(1){
          if (curr->word < temp->word)
          {
             if (temp->left == NULL)
             {
                 temp->left=curr;
                 break;
             }
             else
             {
             	temp=temp->left;
             }
          }
          else 
          {
              if (temp->right == NULL)
             {
                 temp->right=curr;break;	//if current word is equal to word searched
              }
             else
             {
             	temp=temp->right;		//if the word to be searched is greater than current word.
             }
          }    
        }
        //End of while loop
     }
     //End of else part.    
}
//End of insert function.
void BST::search(string str)
{
     treenode *curr,*temp;
     temp=root;
     int count=0;
     while(temp != NULL)
     {
          if (str == temp->word)
          {
               cout <<"Word: "<<str<<" Found!"<<endl;
               cout<<"Meaning of the word is:"<<temp->meaning<<endl;
               cout <<"No. of comparisons done: "<<count<<endl;
               return;
          }
          else
            if (str < temp->word)
                temp=temp->left;
            else
                temp=temp->right;
          count++;
     }
     //End of while loop
     cout<<"Word: "<<str<<" not found in Dictionary.";
     
}
//End of insert function
void BST::inorder(treenode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->word << " "<< root->meaning <<endl;
        inorder(root->right);
    }
}
void BST::inorder_desc(treenode *root)
{
    if (root != NULL)
    {
        inorder_desc(root->right);
        cout << root->word << " "<< root->meaning <<endl;
        inorder_desc(root->left);
    }
} 
// function to delete any node from dictionary
treenode* BST::deleteword(treenode* root, string key)
{
	if (root == NULL)
	{
		cout << "Word not found" << endl;
		return root;
	}

	// traversing to find the word
	if (key < root->word)
		root->left = deleteword(root->left, key);
	else if (key > root->word)
		root->right = deleteword(root->right, key);
	else
	{
		// node has no child
		if (root->left == NULL and root->right == NULL)
			return NULL;
		// node with only one child or no child
		else if (root->left == NULL)
		{
			treenode *temp = root->right;
			delete (root);
			cout << "Deleted" << endl;
			return temp;
		}
		else if (root->right == NULL)
		{
			treenode *temp = root->left;
			delete (root);
			cout << "Deleted" << endl;
			return temp;
		}
		// node with two children
		// find the minimum of that subtree
		treenode *temp = minimum(root->right);
		// replace contents from the minimum node to current
		root->word = temp->word;
		root->meaning = temp->meaning;
		// delete that node
		root->right = deleteword(root->right, temp->word);
	}
	return root;
}
// function to find the minimum node in a bst
treenode *BST::minimum(treenode *root)
{
	treenode *temp;
	temp = root;
	// traverse to the left-most element
	while (temp->left != NULL)
		temp = temp->left;
	return temp;
}
// function to update the meaning of a word
void BST::update(treenode* root, string key)
{
	treenode *temp = root;
	// if word not found
	if (temp == NULL)
	{
		cout << "The entered word could not be found. Try Again." << endl;
		return;
	}
	// return if key is equal to word
	if (temp->word == key)
	{
		cout << "Enter its new meaning : " << endl;
		cin >> temp->meaning;
		cout << "Updated" << endl;
		return;
	}
	else
	{
		if (temp->word > key)
		{
			// if key is less than word, change root to root->left
			return update(temp->left, key);
		}
		else
		{
			// if key is greater than word, change root to root->right
			return update(temp->right, key);
		}
	}
}
int main()
{
     BST b;
     int choice;
     string str;
     while(true)
     {
     	cout<<"***Choice Menu***"<<endl;
     	cout<<"(1)Insert a word."<<endl;
     	cout<<"(2)Display complete dictionary in ascending order."<<endl;
     	cout<<"(3)Display complete dictionary in descending order."<<endl;
     	cout<<"(4)Search Meaning of the word."<<endl;
        cout<<"(5)Update meaning of the word."<<endl;
        cout<<"(6)Delete a word from dictionary."<<endl;

     	cout<<"Enter your choice:"<<endl;
     	cin >> choice;
     	
     	if(choice==1)
     	{
     		b.insert();
     	}
     	else if(choice==2)
     	{
     		cout<<"Word"<<"  "<<"Meaning"<<endl;
     		b.inorder(b.root);
     	}
     	else if(choice==3)
     	{
     		cout<<"Word"<<"  "<<"Meaning"<<endl;
     		b.inorder_desc(b.root);
     	}
     	else if(choice==4)
     	{
     		cout<<"Enter word to be searched:"<<endl;
     		cin>>str;
     		b.search(str);
     	}
        else if(choice==5)
        {
            string searchkey;
			cout << "Enter the word whose meaning is to be changed : " << endl;
			cin >> searchkey;
			b.update(b.root, searchkey);
        }
        else if(choice==6)
        {
            string searchkey;
			cout << "Enter the word to be delete from dictionary : " << endl;
			cin >> searchkey;
			b.root = b.deleteword(b.root, searchkey);
        }
     	else
     	{
     		cout<<"Wrong choice entered."<<endl;
     	}
     }
     //End of while     
}
