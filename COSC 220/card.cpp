#include "card.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

Card :: Card() {
  //creates 52 cards 13 in each of the 4 suites
nextCard=0;
for(int i=0; i<13;i++){
  cards[i].num=i+1;
  for (int j =0; j<4; j++){
  cards[i].pic[j]=spade[j];
}
}

for(int i=13; i<26;i++){
  cards[i].num=i-12;
for (int j =0; j<4; j++){
  cards[i].pic[j]=club[j];
}
}

for(int i=26; i<49;i++){
  cards[i].num=i-25;
    for (int j =0; j<4; j++){
  cards[i].pic[j]=heart[j];
}
}

for(int i=39; i<52;i++){
  cards[i].num=i-38;
  for (int j =0; j<4; j++){
  cards[i].pic[j]=diamond[j];
}
}
}

ACard Card :: getCard(){
  int i = nextCard;
  nextCard++;
  if (nextCard>52){
    nextCard=0;
  }
  return cards[i];
}

//allows single line to be printed
//passes index and card pic
void Card :: cardAce(const char pic[],int ind){
  int x = ind;
  switch(x){
    case 0:{
cout<<"---------";
break;
}
    case 1:{
cout<<"|"<<"A"<<setw(7)<<"|";
break;
}
    case 2:{
cout<<"|"<<setw(8)<<"|";
break;
}
    case 3:{
cout<<"|"<<setw(8)<<"|";
break;
}
    case 4:{
cout<<"|"<<setw(8)<<"|";
break;
}
    case 5:{
cout<<"|"<<setw(6)<<pic<<setw(4)<<"|";
break;
}
    case 6:{
cout<<"|"<<setw(8)<<"|";
break;
}
    case 7:{
cout<<"|"<<setw(8)<<"|";
break;
}
    case 8:{
cout<<"|"<<setw(8)<<"|";
break;
}
    case 9:{
cout<<"|"<<setw(7)<<"A"<<"|";
break;
}
    case 10:{
cout<<"---------";
break;
}
}
}

void Card :: cardTwo(const char pic[],int ind){
  int x = ind;
  switch(x){
    case 0:{
  cout<<"---------";
  break;
}
    case 1:{
  cout<<"|"<<"2"<<setw(7)<<"|";
  break;
}
    case 2:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 3:{
  cout<<"|"<<setw(6)<<pic<<setw(4)<<"|";
  break;
}
    case 4:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 5:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 6:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 7:{
  cout<<"|"<<setw(6)<<pic<<setw(4)<<"|";
  break;
}
    case 8:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 9:{
  cout<<"|"<<setw(7)<<"2"<<"|";
  break;
}
    case 10:{
  cout<<"---------";
  break;
}

}
}

void Card :: cardThree(const char pic[],int ind){
  int x = ind;
  switch(x){
    case 0:{
  cout<<"---------";
  break;
}
    case 1:{
  cout<<"|"<<"3"<<setw(7)<<"|";
  break;
}
    case 2:{
  cout<<"|"<<setw(6)<<pic<<setw(4)<<"|";
  break;
}
    case 3:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 4:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 5:{
  cout<<"|"<<setw(6)<<pic<<setw(4)<<"|";
  break;
}
    case 6:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 7:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 8:{
  cout<<"|"<<setw(6)<<pic<<setw(4)<<"|";
  break;
}
    case 9:{
  cout<<"|"<<setw(7)<<"3"<<"|";
  break;
}
    case 10:{
  cout<<"---------";
  break;
}
}
}

void Card :: cardFour(const char pic[],int ind){
  int x = ind;
  switch(x){
    case 0:{
  cout<<"---------";
  break;
}
    case 1:{
  cout<<"|"<<"4"<<setw(7)<<"|";
  break;
}
    case 2:{
  cout<<"|"<<setw(2)<<pic<<setw(8)<<pic<<"|";
  break;
}
    case 3:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 4:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 5:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 6:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 7:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 8:{
  cout<<"|"<<setw(2)<<pic<<setw(8)<<pic<<"|";
  break;
}
    case 9:{
  cout<<"|"<<setw(7)<<"4"<<"|";
  break;
}
    case 10:{
  cout<<"---------";
  break;
}

}
}

void Card :: cardFive(const char pic[],int ind){
  int x = ind;
  switch(x){
    case 0:{
  cout<<"---------";
  break;
}
    case 1:{
  cout<<"|"<<"5"<<setw(7)<<"|";
  break;
}
    case 2:{
  cout<<"|"<<setw(2)<<pic<<setw(8)<<pic<<"|";
  break;
}
    case 3:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 4:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 5:{
  cout<<"|"<<setw(6)<<pic<<setw(4)<<"|";
  break;
}
    case 6:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 7:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 8:{
  cout<<"|"<<setw(2)<<pic<<setw(8)<<pic<<"|";
  break;
}
    case 9:{
  cout<<"|"<<setw(7)<<"5"<<"|";
  break;
}
    case 10:{
  cout<<"---------";
  break;
}

}
}

void Card :: cardSix(const char pic[],int ind){
  int x = ind;
  switch(x){
    case 0:{
  cout<<"---------";
  break;
}
    case 1:{
  cout<<"|"<<"6"<<setw(7)<<"|";
  break;
}
    case 2:{
  cout<<"|"<<setw(2)<<pic<<setw(8)<<pic<<"|";
  break;
}
    case 3:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 4:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 5:{
  cout<<"|"<<setw(2)<<pic<<setw(8)<<pic<<"|";
  break;
}
    case 6:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 7:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 8:{
  cout<<"|"<<setw(2)<<pic<<setw(8)<<pic<<"|";
  break;
}
    case 9:{
  cout<<"|"<<setw(7)<<"6"<<"|";
  break;
}
    case 10:{
  cout<<"---------";
  break;
}

}
}

void Card :: cardSeven(const char pic[],int ind){
  int x = ind;
  switch(x){
    case 0:{
  cout<<"---------";
  break;
}
    case 1:{
  cout<<"|"<<"7"<<setw(7)<<"|";
  break;
}
    case 2:{
  cout<<"|"<<setw(2)<<pic<<setw(8)<<pic<<"|";
  break;
}
    case 3:{
  cout<<"|"<<setw(6)<<pic<<setw(4)<<"|";
  break;
}
    case 4:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 5:{
  cout<<"|"<<setw(2)<<pic<<setw(8)<<pic<<"|";
  break;
}
    case 6:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 7:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 8:{
  cout<<"|"<<setw(2)<<pic<<setw(8)<<pic<<"|";
  break;
}
    case 9:{
  cout<<"|"<<setw(7)<<"7"<<"|";
  break;
}
    case 10:{
  cout<<"---------";
  break;
}
}
}

void Card :: cardEight(const char pic[],int ind){
  int x = ind;
  switch(x){
    case 0:{
  cout<<"---------";
  break;
}
    case 1:{
  cout<<"|"<<"8"<<setw(7)<<"|";
  break;
}
    case 2:{
  cout<<"|"<<setw(2)<<pic<<setw(8)<<pic<<"|";
  break;
}
    case 3:{
  cout<<"|"<<setw(6)<<pic<<setw(4)<<"|";
  break;
}
    case 4:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 5:{
  cout<<"|"<<setw(2)<<pic<<setw(8)<<pic<<"|";
  break;
}
    case 6:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 7:{
  cout<<"|"<<setw(6)<<pic<<setw(4)<<"|";
  break;
}
    case 8:{
  cout<<"|"<<setw(2)<<pic<<setw(8)<<pic<<"|";
  break;
}
    case 9:{
  cout<<"|"<<setw(7)<<"8"<<"|";
  break;
}
    case 10:{
  cout<<"---------";
  break;
}

}
}

void Card :: cardNine(const char pic[],int ind){
  int x = ind;
  switch(x){
    case 0:{
  cout<<"---------";
  break;
}
    case 1:{
  cout<<"|"<<"9"<<setw(7)<<"|";
  break;
}
    case 2:{
  cout<<"|"<<setw(2)<<pic<<setw(8)<<pic<<"|";
  break;
}
    case 3:{
  cout<<"|"<<setw(6)<<pic<<setw(4)<<"|";
  break;
}
    case 4:{
  cout<<"|"<<setw(2)<<pic<<setw(8)<<pic<<"|";
  break;
}
    case 5:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 6:{
  cout<<"|"<<setw(2)<<pic<<setw(8)<<pic<<"|";
  break;
}
    case 7:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 8:{
  cout<<"|"<<setw(2)<<pic<<setw(8)<<pic<<"|";
  break;
}
    case 9:{
  cout<<"|"<<setw(7)<<"9"<<"|";
  break;
}
    case 10:{
  cout<<"---------";
  break;
}

}
}

void Card :: cardTen(const char pic[],int ind){
  int x = ind;
  switch(x){
    case 0:{
  cout<<"---------";
  break;
}
    case 1:{
  cout<<"|"<<"10"<<setw(6)<<"|";
  break;
}
    case 2:{
  cout<<"|"<<setw(2)<<pic<<setw(8)<<pic<<"|";
  break;
}
    case 3:{
  cout<<"|"<<setw(6)<<pic<<setw(4)<<"|";
  break;
}
    case 4:{
  cout<<"|"<<setw(2)<<pic<<setw(8)<<pic<<"|";
  break;
}
    case 5:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 6:{
  cout<<"|"<<setw(2)<<pic<<setw(8)<<pic<<"|";
  break;
}
    case 7:{
  cout<<"|"<<setw(6)<<pic<<setw(4)<<"|";
  break;
}
    case 8:{
  cout<<"|"<<setw(2)<<pic<<setw(8)<<pic<<"|";
  break;
}
    case 9:{
  cout<<"|"<<setw(7)<<"10"<<"|";
  break;
}
    case 10:{
  cout<<"---------";
  break;
}

}
}

void Card :: cardJack(const char pic[],int ind){
  int x = ind;
  switch(x){
    case 0:{
  cout<<"---------";
  break;
}
    case 1:{
  cout<<"|"<<pic<<"J"<<setw(6)<<"|";
  break;
}
    case 2:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 3:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 4:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 5:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 6:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 7:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 8:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 9:{
  cout<<"|"<<setw(8)<<pic<<"J"<<"|";
  break;
}
    case 10:{
  cout<<"---------";
  break;
}

}
}

void Card :: cardQueen(const char pic[],int ind){
  int x = ind;
  switch(x){
    case 0:{
  cout<<"---------";
  break;
}
    case 1:{
  cout<<"|"<<pic<<"Q"<<setw(6)<<"|";
  break;
}
    case 2:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 3:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 4:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 5:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 6:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 7:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 8:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 9:{
  cout<<"|"<<setw(8)<<pic<<"Q"<<"|";
  break;
}
    case 10:{
  cout<<"---------";
  break;
}

}
}

void Card :: cardKing(const char pic[],int ind){
  int x = ind;
  switch(x){
    case 0:{
  cout<<"---------";
  break;
  }
    case 1:{
  cout<<"|"<<pic<<"K"<<setw(6)<<"|";
  break;
}
    case 2:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 3:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 4:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 5:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 6:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 7:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 8:{
  cout<<"|"<<setw(8)<<"|";
  break;
}
    case 9:{
  cout<<"|"<<setw(8)<<pic<<"K"<<"|";
  break;
}
    case 10:{
  cout<<"---------";
  break;
}

}
}


void Card :: shuffleCard(){

int rnum;
ACard temp;

srand(time(0));
srand((unsigned)time(NULL));

//swaps cards
  for(int i =0; i<52;i++){
    rnum = (rand()%(52));
    temp=cards[i];
    cards[i]=cards[rnum];
    cards[rnum]=temp;
  }
nextCard=0;
}
