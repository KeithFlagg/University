#include "RBT.h"
#include "BST.h"
#include <iostream>
#include <chrono>
#include <time.h>

using namespace std;

int main(){
  //seeds rand
  srand(time(NULL));
  int sizes[12] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000};
  auto start = std::chrono::system_clock::now();
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::chrono::duration<double> avr = elapsed_seconds;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);

  BST *tree = new BST;
  RBT *tree2 = new RBT;

  cout << endl << "-----------------------------------------"<< endl;
  cout << "testing insert..." << endl;
  cout << "Inserting 8,12,45,9,13,6..." << endl;
  tree2->insert(8);
  tree2->insert(12);
  tree2->insert(45);
  tree2->insert(9);
  tree2->insert(13);
  tree2->insert(6);

  cout << "Inorder traversal: "<< endl;
  tree2->printInOrder();
  cout << endl;

  cout << "Preorder traversal: "<< endl;
  tree2->printPreOrder();
  cout << endl;

  cout << "Postorder traversal: "<< endl;
  tree2->printPostOrder();
  cout << endl;

  cout << endl << "-----------------------------------------"<< endl;
  cout <<"Testing search function: " << endl;
  cout << "searching for 8.." << endl;
  cout << "Printing value..." << endl;
  cout<<tree2->search(8)<<endl;

  cout << "Searching for 1..." << endl;
  cout<<tree2->search(1);
  cout<<" Not found" << endl;

  cout << endl << "-----------------------------------------"<< endl;
  cout <<"Testing Maximum..." << endl;
  cout << tree2->max() << " is the maximum value of the tree!" << endl;

  cout << endl << "-----------------------------------------"<< endl;
  cout <<"Testing Minimum..." << endl;
  cout << tree2->min() << " is the minimum value of the tree!" << endl;

  cout << endl << "-----------------------------------------"<< endl;
  cout << "Testing successor..." << endl;
  cout << "Printing in order..." << endl;
  tree2->printInOrder();
  cout << endl;
  cout << "successor of 6 is " << tree2->success(6) << endl;
  cout << "successor of 12 is " << tree2->success(12) << endl;
  cout << "successor of 45 is " << tree2->success(45) << endl;

  cout << endl << "-----------------------------------------"<< endl;
  cout << "Testing delete..." << endl;
  cout << "In order traversal..." << endl;
  tree2->printInOrder();
  cout << endl;

  cout << "Deleting 12..." << endl;
  tree2->deleteNode(12);
  cout << "Displaying the new tree in order..."<<endl;
  tree2->printInOrder();
  cout << endl;

  cout << "Deleting 45..." << endl;
  tree2->deleteNode(45);
  cout << "Displaying the new tree in order..."<<endl;
  tree2->printInOrder();
  cout << endl;

  cout << "Deleting 1..." << endl;
  tree2->deleteNode(1);
  cout << "Displaying the new tree in order..."<<endl;
  tree2->printInOrder();
  cout << endl;

  cout << endl << "-----------------------------------------"<< endl;
  cout << "Timing insert function (RBT)..." << endl;

  //timing insert
  for(int i = 0; i<12; i++){

  RBT *a = new RBT;
  cout << "Inserting " << sizes[i] << " elements!" << endl;

  start = std::chrono::system_clock::now();
  for(int j = 0; j<sizes[i]; j++){
  a->insert(1+rand()%100);
  }
  end = std::chrono::system_clock::now();
  elapsed_seconds = end - start;
  end_time = std::chrono::system_clock::to_time_t(end);
  cout << "finished at: " <<ctime(&end_time)<< "elapsed time: " <<elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl<<endl;

  delete a;
  }

  //timing delete
  for(int i = 0; i<12; i++){

  RBT *b = new RBT;
  cout << "Deleting " << sizes[i] << " elements!" << endl;

  for(int j = 0; j<sizes[i]; j++){
  b->insert(1+rand()%100);
  }

  start = std::chrono::system_clock::now();
  //deletes all nodes
  delete b;
  end = std::chrono::system_clock::now();
  elapsed_seconds = end - start;
  end_time = std::chrono::system_clock::to_time_t(end);
  cout << "finished at: " <<ctime(&end_time)<< "elapsed time: " <<elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl<<endl;
  }

  //timing Search
  for(int i = 0; i<12; i++){

  RBT *c = new RBT;
  cout << "Searching for " << sizes[i] << " elements!" << endl;

  for(int j = 0; j<sizes[i]; j++){
  c->insert(1+rand()%100);
  }

  start = std::chrono::system_clock::now();

  c->search(1+rand()%100);

  end = std::chrono::system_clock::now();
  elapsed_seconds = end - start;
  end_time = std::chrono::system_clock::to_time_t(end);
  cout << "finished at: " <<ctime(&end_time)<< "elapsed time: " <<elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl<<endl;
  delete c;
  }

  cout << endl << "-----------------------------------------"<< endl;
  cout << "Timing insert function (BST)..." << endl;

  //timing insert
  for(int i = 0; i<12; i++){

  BST *a = new BST;
  cout << "Inserting " << sizes[i] << " elements!" << endl;

  start = std::chrono::system_clock::now();
  for(int j = 0; j<sizes[i]; j++){
  a->insert(1+rand()%100);
  }
  end = std::chrono::system_clock::now();
  elapsed_seconds = end - start;
  end_time = std::chrono::system_clock::to_time_t(end);
  cout << "finished at: " <<ctime(&end_time)<< "elapsed time: " <<elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl<<endl;

  delete a;
  }

  //timing delete
  for(int i = 0; i<12; i++){

  BST *b = new BST;
  cout << "Deleting " << sizes[i] << " elements!" << endl;

  for(int j = 0; j<sizes[i]; j++){
  b->insert(1+rand()%100);
  }

  start = std::chrono::system_clock::now();
  //deletes all nodes
  delete b;
  end = std::chrono::system_clock::now();
  elapsed_seconds = end - start;
  end_time = std::chrono::system_clock::to_time_t(end);
  cout << "finished at: " <<ctime(&end_time)<< "elapsed time: " <<elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl<<endl;
  }

  //timing Search
  for(int i = 0; i<12; i++){

  BST *c = new BST;
  cout << "Searching for " << sizes[i] << " elements!" << endl;

  for(int j = 0; j<sizes[i]; j++){
  c->insert(1+rand()%100);
  }

  start = std::chrono::system_clock::now();

  c->searchNode(1+rand()%100);

  end = std::chrono::system_clock::now();
  elapsed_seconds = end - start;
  end_time = std::chrono::system_clock::to_time_t(end);
  cout << "finished at: " <<ctime(&end_time)<< "elapsed time: " <<elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl<<endl;
  delete c;
  }



  delete tree;
  tree2->deleteNil();
  delete tree2;
  return 0;
}
