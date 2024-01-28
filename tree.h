#include <iostream>
#include <iomanip>
using namespace std;


#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

struct node{
    int value;
    node *left,*right;
};

void insertt(node *&root,int value){
    if(root==nullptr){
        root = new node{value,nullptr,nullptr};
    }  else if(value< root->value){
        insertt(root->left,value);
    }else{
    insertt(root->right,value);}
}

void preorder(node* Node){
    if(Node != nullptr){
        cout <<Node->value<<" ";
        preorder(Node->left);
        preorder(Node->right);
    }
}
void inorder(node* Node){
     if(Node != nullptr){
        preorder(Node->left);
        cout <<Node->value<<" ";
        preorder(Node->right);
    }

}
void postorder(node* Node){
     if(Node != nullptr){
        preorder(Node->left);
        preorder(Node->right);
        cout <<Node->value<<" ";
    }

}

void menu1(){
    system("pause");
    system("cls");
    cout<<"1- for Table"<<endl;
    cout<<"2- for Tree"<<endl;
    cout<<"3- for Linkedlist"<<endl;
    cout<<"What's your choice? "<<endl;
}
#endif // TREE_H_INCLUDED
