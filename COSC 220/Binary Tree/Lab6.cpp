#include <iostream>
#include "TNode.h"
#include "BST.h"

using namespace std;

int main(){
char choice = '0';
int insert = 0;
int val = 0;
int c = 0;

cout<<"Welcome to your binary tree! Please select an option:"<<endl;

BST *tree = new BST;

do{
  cout<<endl;
  cout<<"1.) insert an element into your tree."<<endl<<"2.) Delete an element from the tree."<<endl<<"3.) Display your binary tree."<<endl<<"4.) Quit"<<endl<<endl;
  cin>>choice;
  cout<<endl;

    if (choice == '1'){
      cout<<"Please enter an integer to insert into your binary tree:"<<endl;
      cin>>insert;
      if (tree->searchNode(insert)){
      cout<<"cannot insert duplicates!"<<endl;
    }
    else
    tree->createNode(insert);
    }
    else if (choice == '2'){
      cout<<"Please enter a value to delete from your tree:"<<endl;
      cin>>val;
      if (tree->searchNode(val)){
      tree->remove(val);
    }
    else
    cout <<"Not a valid integer!"<<endl;
    }

    else if (choice == '3'){
      cout<<"Please choose the order to display the tree:"<<endl;
      cout<<"1.) in order"<<endl<<"2.) pre order"<<endl<<"3.) post order"<<endl;
      cin>>c;

      if (c==1){
        cout<<endl;
        //passes root into in order search
        tree->inOrder(tree->getRoot());
        cout<<endl;
      }
      else if(c==2){
        cout<<endl;
        //passes root into pre order search
        tree->preOrder(tree->getRoot());
        cout<<endl;
      }
      else if (c==3){
        cout<<endl;
        //passes root into post order search 
        tree->postOrder(tree->getRoot());
        cout<<endl;
      }
      else
      cout<<"Enter a value (1-3)"<<endl;
    }

    else if (choice!='4'){
      cout<<"Please select a valid menu option!"<<endl;
    }


}while (choice!='4');

cout<<"Thank You!"<<endl;
delete tree;

  return 0;
}
