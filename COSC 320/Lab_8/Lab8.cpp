#include <iostream>
#include "BST.h"
#include <chrono>
#include <iomanip>

using namespace std;

int main(){
//seed for rand
srand(time(0));
int sizes[12] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000};
auto start = std::chrono::system_clock::now();
auto end = std::chrono::system_clock::now();
std::chrono::duration<double> elapsed_seconds = end-start;
std::chrono::duration<double> avr = elapsed_seconds;
std::time_t end_time = std::chrono::system_clock::to_time_t(end);

BST *tree = new BST;

cout << endl << "-----------------------------------------"<< endl;
cout << "testing insert..." << endl;
cout << "Inserting 8,12,45,9,13,6..." << endl;
tree->insert(8);
tree->insert(12);
tree->insert(45);
tree->insert(9);
tree->insert(13);
tree->insert(6);

cout << "Inorder traversal: "<< endl;
tree->inOrder(tree->getRoot());
cout << endl;

cout << endl << "-----------------------------------------"<< endl;
cout <<"Testing search function: " << endl;
cout << "searching for 8.." << endl;
cout << "Printing value..." << endl;
tree->printNode(tree->searchNode(8));

cout << "Searching for 1..." << endl;
tree->printNode(tree->searchNode(1));
cout<<"Not found" << endl;

cout << endl << "-----------------------------------------"<< endl;
cout <<"Testing Maximum..." << endl;
cout << tree->max(tree->getRoot()) << " is the maximum value of the tree!" << endl;

cout << endl << "-----------------------------------------"<< endl;
cout <<"Testing Minimum..." << endl;
cout << tree->min(tree->getRoot()) << " is the minimum value of the tree!" << endl;

cout << endl << "-----------------------------------------"<< endl;
cout << "Testing successor..." << endl;
cout << "Printing in order..." << endl;
tree->inOrder(tree->getRoot());
cout << endl;
cout << "successor of 6 is " << tree->success(tree->searchNode(6)) << endl;
cout << "successor of 12 is " << tree->success(tree->searchNode(12)) << endl;
cout << "successor of 45 is " << tree->success(tree->searchNode(9)) << endl;

cout << endl << "-----------------------------------------"<< endl;
cout << "Testing delete..." << endl;
cout << "In order traversal..." << endl;
tree->inOrder(tree->getRoot());
cout << endl;

cout << "Deleting 12..." << endl;
tree->deleteNode(12);
cout << "Displaying the new tree in order..."<<endl;
tree->inOrder(tree->getRoot());
cout << endl;

cout << "Deleting 45..." << endl;
tree->deleteNode(45);
cout << "Displaying the new tree in order..."<<endl;
tree->inOrder(tree->getRoot());
cout << endl;

cout << "Deleting 1..." << endl;
tree->deleteNode(1);
cout << "Displaying the new tree in order..."<<endl;
tree->inOrder(tree->getRoot());
cout << endl;

cout << endl << "-----------------------------------------"<< endl;
cout << "Timing insert function..." << endl;

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
for(int j = 0; j<sizes[i]; j++){
c->searchNode(1+rand()%100);
}
end = std::chrono::system_clock::now();
elapsed_seconds = end - start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at: " <<ctime(&end_time)<< "elapsed time: " <<elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl<<endl;
delete c;
}

delete tree;
  return 0;
}
