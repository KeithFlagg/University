#include <iostream>
#include "Node.h"
#include "Linkedlist.h"
void menu();
using namespace std;

int main(){
menu();

  return 0;
}

void menu(){

  Linkedlist list;
  char choice=0;
  int id=0;
  //user id selection
    do{
      cout<<"Please select an option:"<<endl;
      //menu options
      cout<<"1. Insert a node"<<endl<<"2. Delete a node"<<endl<<"3. Print List"<<endl<<"4. Search ID"<<endl<<"5. Quit"<<endl;
      cin>>choice;

    switch (choice){
      case '1':
      //inserting a node
      {
        list.insertNode();
        break;
  }
      case '2':
      //deleting
      {
        cout<<"Enter the id you wish to delete:"<<endl;
      cin >> id;
      list.deleteNode(id);
      break;
  }
    case '3':
    //printing the linked list
    {
      cout<<"All students in list: "<<endl;
      list.printList();
      break;
  }
    case '4':
    //searching the list
    {
      list.searchNode();
      break;
  }
    case '5':{
      //quits program
      cout<<"Thank you!"<<endl;
      break;
  }
  default:
  cout<<"Not a valid menu option!"<<endl;
  break;
    }
  }while (choice!='5');

}
