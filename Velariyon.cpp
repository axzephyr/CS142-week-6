#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node* left;
    node* right;
    //constructor
    node(int i)
    {
        left=NULL;
        data=i;
        right=NULL;
    }
};

class BiST
{
public:
    node * root;
    BiST()
    {
        root=NULL;
    }
    //the function for the inserting
    void insrt(int value)
    {
        inserthelper(root,value);
    }
    void inserthelper(node * current, int value)
    {
        //the case for the root
        if(current==NULL)
        {
            current=new node(value);
            if (root==NULL)
            {
                root=current;
            }
        }
        //the case for all others
        else if (value<current->data)
        {
            if(current->left==NULL)
            {
                current->left= new node(value);
            }
           else inserthelper(current->left,value);
        }
        else
        {
            if (current->right==NULL)
            {
                current->right=new node(value);
            }
            else inserthelper(current->right,value);
        }

    }

    void display1()
    {
        display2(root);
    }
    void display2(node* current)
    {
        if(current->left!= NULL)
        {
            display2(current->left);
        }
        cout<<current->data<<",";
        if(current->right!= NULL)
        {
            display2(current->right);
        }
    }

    node* search1(int v)
    {
        return search2(root,v);
    }

    node* search2(node* current,int v)
    {
        if (current==NULL)
        {
           cout<<endl;
            cout<<v<<" is not present in the Binary Search Tree! "<<endl;
            return NULL;
        }
        else
        {
              if(v==current->data)
            {
                cout<<endl;
                cout<<v<<" found! "<<endl;
                return current;
            }
            else if(v<current->data)
            {
                return search2(current->left,v);
            }
            else
            {
               return search2(current->right,v);
            }
        }
    }
};


int main()
{

    BiST s1;
    s1.insrt(10);
    s1.insrt(2);
    s1.insrt(12);
    s1.insrt(3);
    s1.insrt(1);
    s1.display1();
    cout<<s1.search1(3);
    cout<<s1.search1(9);
    return 0;
}




