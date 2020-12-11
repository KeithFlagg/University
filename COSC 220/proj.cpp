#include <iostream>
#include "card.h"

using namespace std;

int main(){
//creates card deck
Card deck;

//creates player hand
ACard hand[5];

char choice = '0';

do {
cout <<endl<<"choose the amount of cards to display: (2-5)"<<endl<<"Press 6 to Quit"<<endl<<endl;;
cin>>choice;


//shuffles deck
if (choice!='6'){
cout<<"Shuffling..."<<endl;
deck.shuffleCard();

//initializes player hand each time a new number is selected
cout<<"dealing you a new hand..."<<endl;
for (int i =0; i<5; i++){
  hand[i]=deck.getCard();
}
}

switch (choice)
{
  //prints out each line line of cards 2,3,4,5
  case '2':{
    for(int i = 0; i < 11; i++){

      switch (hand[0].num){
          case 1:{
          deck.cardAce(hand[0].pic,i);
          break;
        }
        case 2:{
          deck.cardTwo(hand[0].pic,i);
          break;
        }
        case 3:{
          deck.cardThree(hand[0].pic,i);
          break;
        }
        case 4:{
          deck.cardFour(hand[0].pic,i);
          break;
        }
        case 5:{
          deck.cardFive(hand[0].pic,i);
          break;
        }
        case 6:{
          deck.cardSix(hand[0].pic,i);
          break;
        }
        case 7:{
          deck.cardSeven(hand[0].pic,i);
          break;
        }
        case 8:{
          deck.cardEight(hand[0].pic,i);
          break;
        }
        case 9:{
          deck.cardNine(hand[0].pic,i);
          break;
        }
        case 10:{
          deck.cardTen(hand[0].pic,i);
          break;
        }
        case 11:{
          deck.cardJack(hand[0].pic,i);
          break;
        }
        case 12:{
          deck.cardQueen(hand[0].pic,i);
          break;
        }
        case 13:{
          deck.cardKing(hand[0].pic,i);
          break;
        }
    }

    switch (hand[1].num){
        case 1:{
        deck.cardAce(hand[1].pic,i);
        break;
      }
      case 2:{
        deck.cardTwo(hand[1].pic,i);
        break;
      }
      case 3:{
        deck.cardThree(hand[1].pic,i);
        break;
      }
      case 4:{
        deck.cardFour(hand[1].pic,i);
        break;
      }
      case 5:{
        deck.cardFive(hand[1].pic,i);
        break;
      }
      case 6:{
        deck.cardSix(hand[1].pic,i);
        break;
      }
      case 7:{
        deck.cardSeven(hand[1].pic,i);
        break;
      }
      case 8:{
        deck.cardEight(hand[1].pic,i);
        break;
      }
      case 9:{
        deck.cardNine(hand[1].pic,i);
        break;
      }
      case 10:{
        deck.cardTen(hand[1].pic,i);
        break;
      }
      case 11:{
        deck.cardJack(hand[1].pic,i);
        break;
      }
      case 12:{
        deck.cardQueen(hand[1].pic,i);
        break;
      }
      case 13:{
        deck.cardKing(hand[1].pic,i);
        break;
      }
  }

  cout<<endl;

}
break;
}
    case '3':{
      for(int i = 0; i < 11; i++){

        switch (hand[0].num){
            case 1:{
            deck.cardAce(hand[0].pic,i);
            break;
          }
          case 2:{
            deck.cardTwo(hand[0].pic,i);
            break;
          }
          case 3:{
            deck.cardThree(hand[0].pic,i);
            break;
          }
          case 4:{
            deck.cardFour(hand[0].pic,i);
            break;
          }
          case 5:{
            deck.cardFive(hand[0].pic,i);
            break;
          }
          case 6:{
            deck.cardSix(hand[0].pic,i);
            break;
          }
          case 7:{
            deck.cardSeven(hand[0].pic,i);
            break;
          }
          case 8:{
            deck.cardEight(hand[0].pic,i);
            break;
          }
          case 9:{
            deck.cardNine(hand[0].pic,i);
            break;
          }
          case 10:{
            deck.cardTen(hand[0].pic,i);
            break;
          }
          case 11:{
            deck.cardJack(hand[0].pic,i);
            break;
          }
          case 12:{
            deck.cardQueen(hand[0].pic,i);
            break;
          }
          case 13:{
            deck.cardKing(hand[0].pic,i);
            break;
          }
      }

      switch (hand[1].num){
          case 1:{
          deck.cardAce(hand[1].pic,i);
          break;
        }
        case 2:{
          deck.cardTwo(hand[1].pic,i);
          break;
        }
        case 3:{
          deck.cardThree(hand[1].pic,i);
          break;
        }
        case 4:{
          deck.cardFour(hand[1].pic,i);
          break;
        }
        case 5:{
          deck.cardFive(hand[1].pic,i);
          break;
        }
        case 6:{
          deck.cardSix(hand[1].pic,i);
          break;
        }
        case 7:{
          deck.cardSeven(hand[1].pic,i);
          break;
        }
        case 8:{
          deck.cardEight(hand[1].pic,i);
          break;
        }
        case 9:{
          deck.cardNine(hand[1].pic,i);
          break;
        }
        case 10:{
          deck.cardTen(hand[1].pic,i);
          break;
        }
        case 11:{
          deck.cardJack(hand[1].pic,i);
          break;
        }
        case 12:{
          deck.cardQueen(hand[1].pic,i);
          break;
        }
        case 13:{
          deck.cardKing(hand[1].pic,i);
          break;
        }
      }

      switch (hand[2].num){
          case 1:{
          deck.cardAce(hand[2].pic,i);
          break;
        }
        case 2:{
          deck.cardTwo(hand[2].pic,i);
          break;
        }
        case 3:{
          deck.cardThree(hand[2].pic,i);
          break;
        }
        case 4:{
          deck.cardFour(hand[2].pic,i);
          break;
        }
        case 5:{
          deck.cardFive(hand[2].pic,i);
          break;
        }
        case 6:{
          deck.cardSix(hand[2].pic,i);
          break;
        }
        case 7:{
          deck.cardSeven(hand[2].pic,i);
          break;
        }
        case 8:{
          deck.cardEight(hand[2].pic,i);
          break;
        }
        case 9:{
          deck.cardNine(hand[2].pic,i);
          break;
        }
        case 10:{
          deck.cardTen(hand[2].pic,i);
          break;
        }
        case 11:{
          deck.cardJack(hand[2].pic,i);
          break;
        }
        case 12:{
          deck.cardQueen(hand[2].pic,i);
          break;
        }
        case 13:{
          deck.cardKing(hand[2].pic,i);
          break;
        }
      }
      cout<<endl;

      }
      break;
    }
    case '4':{
      for(int i = 0; i < 11; i++){

        switch (hand[0].num){
            case 1:{
            deck.cardAce(hand[0].pic,i);
            break;
          }
          case 2:{
            deck.cardTwo(hand[0].pic,i);
            break;
          }
          case 3:{
            deck.cardThree(hand[0].pic,i);
            break;
          }
          case 4:{
            deck.cardFour(hand[0].pic,i);
            break;
          }
          case 5:{
            deck.cardFive(hand[0].pic,i);
            break;
          }
          case 6:{
            deck.cardSix(hand[0].pic,i);
            break;
          }
          case 7:{
            deck.cardSeven(hand[0].pic,i);
            break;
          }
          case 8:{
            deck.cardEight(hand[0].pic,i);
            break;
          }
          case 9:{
            deck.cardNine(hand[0].pic,i);
            break;
          }
          case 10:{
            deck.cardTen(hand[0].pic,i);
            break;
          }
          case 11:{
            deck.cardJack(hand[0].pic,i);
            break;
          }
          case 12:{
            deck.cardQueen(hand[0].pic,i);
            break;
          }
          case 13:{
            deck.cardKing(hand[0].pic,i);
            break;
          }
      }

      switch (hand[1].num){
          case 1:{
          deck.cardAce(hand[1].pic,i);
          break;
        }
        case 2:{
          deck.cardTwo(hand[1].pic,i);
          break;
        }
        case 3:{
          deck.cardThree(hand[1].pic,i);
          break;
        }
        case 4:{
          deck.cardFour(hand[1].pic,i);
          break;
        }
        case 5:{
          deck.cardFive(hand[1].pic,i);
          break;
        }
        case 6:{
          deck.cardSix(hand[1].pic,i);
          break;
        }
        case 7:{
          deck.cardSeven(hand[1].pic,i);
          break;
        }
        case 8:{
          deck.cardEight(hand[1].pic,i);
          break;
        }
        case 9:{
          deck.cardNine(hand[1].pic,i);
          break;
        }
        case 10:{
          deck.cardTen(hand[1].pic,i);
          break;
        }
        case 11:{
          deck.cardJack(hand[1].pic,i);
          break;
        }
        case 12:{
          deck.cardQueen(hand[1].pic,i);
          break;
        }
        case 13:{
          deck.cardKing(hand[1].pic,i);
          break;
        }
      }

      switch (hand[2].num){
          case 1:{
          deck.cardAce(hand[2].pic,i);
          break;
        }
        case 2:{
          deck.cardTwo(hand[2].pic,i);
          break;
        }
        case 3:{
          deck.cardThree(hand[2].pic,i);
          break;
        }
        case 4:{
          deck.cardFour(hand[2].pic,i);
          break;
        }
        case 5:{
          deck.cardFive(hand[2].pic,i);
          break;
        }
        case 6:{
          deck.cardSix(hand[2].pic,i);
          break;
        }
        case 7:{
          deck.cardSeven(hand[2].pic,i);
          break;
        }
        case 8:{
          deck.cardEight(hand[2].pic,i);
          break;
        }
        case 9:{
          deck.cardNine(hand[2].pic,i);
          break;
        }
        case 10:{
          deck.cardTen(hand[2].pic,i);
          break;
        }
        case 11:{
          deck.cardJack(hand[2].pic,i);
          break;
        }
        case 12:{
          deck.cardQueen(hand[2].pic,i);
          break;
        }
        case 13:{
          deck.cardKing(hand[2].pic,i);
          break;
        }
      }

      switch (hand[3].num){
          case 1:{
          deck.cardAce(hand[3].pic,i);
          break;
        }
        case 2:{
          deck.cardTwo(hand[3].pic,i);
          break;
        }
        case 3:{
          deck.cardThree(hand[3].pic,i);
          break;
        }
        case 4:{
          deck.cardFour(hand[3].pic,i);
          break;
        }
        case 5:{
          deck.cardFive(hand[3].pic,i);
          break;
        }
        case 6:{
          deck.cardSix(hand[3].pic,i);
          break;
        }
        case 7:{
          deck.cardSeven(hand[3].pic,i);
          break;
        }
        case 8:{
          deck.cardEight(hand[3].pic,i);
          break;
        }
        case 9:{
          deck.cardNine(hand[3].pic,i);
          break;
        }
        case 10:{
          deck.cardTen(hand[3].pic,i);
          break;
        }
        case 11:{
          deck.cardJack(hand[3].pic,i);
          break;
        }
        case 12:{
          deck.cardQueen(hand[3].pic,i);
          break;
        }
        case 13:{
          deck.cardKing(hand[3].pic,i);
          break;
        }
      }
      cout<<endl;
      }

      break;
    }
    case '5':{
      for(int i = 0; i < 11; i++){

        switch (hand[0].num){
            case 1:{
            deck.cardAce(hand[0].pic,i);
            break;
          }
          case 2:{
            deck.cardTwo(hand[0].pic,i);
            break;
          }
          case 3:{
            deck.cardThree(hand[0].pic,i);
            break;
          }
          case 4:{
            deck.cardFour(hand[0].pic,i);
            break;
          }
          case 5:{
            deck.cardFive(hand[0].pic,i);
            break;
          }
          case 6:{
            deck.cardSix(hand[0].pic,i);
            break;
          }
          case 7:{
            deck.cardSeven(hand[0].pic,i);
            break;
          }
          case 8:{
            deck.cardEight(hand[0].pic,i);
            break;
          }
          case 9:{
            deck.cardNine(hand[0].pic,i);
            break;
          }
          case 10:{
            deck.cardTen(hand[0].pic,i);
            break;
          }
          case 11:{
            deck.cardJack(hand[0].pic,i);
            break;
          }
          case 12:{
            deck.cardQueen(hand[0].pic,i);
            break;
          }
          case 13:{
            deck.cardKing(hand[0].pic,i);
            break;
          }
      }

      switch (hand[1].num){
          case 1:{
          deck.cardAce(hand[1].pic,i);
          break;
        }
        case 2:{
          deck.cardTwo(hand[1].pic,i);
          break;
        }
        case 3:{
          deck.cardThree(hand[1].pic,i);
          break;
        }
        case 4:{
          deck.cardFour(hand[1].pic,i);
          break;
        }
        case 5:{
          deck.cardFive(hand[1].pic,i);
          break;
        }
        case 6:{
          deck.cardSix(hand[1].pic,i);
          break;
        }
        case 7:{
          deck.cardSeven(hand[1].pic,i);
          break;
        }
        case 8:{
          deck.cardEight(hand[1].pic,i);
          break;
        }
        case 9:{
          deck.cardNine(hand[1].pic,i);
          break;
        }
        case 10:{
          deck.cardTen(hand[1].pic,i);
          break;
        }
        case 11:{
          deck.cardJack(hand[1].pic,i);
          break;
        }
        case 12:{
          deck.cardQueen(hand[1].pic,i);
          break;
        }
        case 13:{
          deck.cardKing(hand[1].pic,i);
          break;
        }
      }

      switch (hand[2].num){
          case 1:{
          deck.cardAce(hand[2].pic,i);
          break;
        }
        case 2:{
          deck.cardTwo(hand[2].pic,i);
          break;
        }
        case 3:{
          deck.cardThree(hand[2].pic,i);
          break;
        }
        case 4:{
          deck.cardFour(hand[2].pic,i);
          break;
        }
        case 5:{
          deck.cardFive(hand[2].pic,i);
          break;
        }
        case 6:{
          deck.cardSix(hand[2].pic,i);
          break;
        }
        case 7:{
          deck.cardSeven(hand[2].pic,i);
          break;
        }
        case 8:{
          deck.cardEight(hand[2].pic,i);
          break;
        }
        case 9:{
          deck.cardNine(hand[2].pic,i);
          break;
        }
        case 10:{
          deck.cardTen(hand[2].pic,i);
          break;
        }
        case 11:{
          deck.cardJack(hand[2].pic,i);
          break;
        }
        case 12:{
          deck.cardQueen(hand[2].pic,i);
          break;
        }
        case 13:{
          deck.cardKing(hand[2].pic,i);
          break;
        }
      }

      switch (hand[3].num){
          case 1:{
          deck.cardAce(hand[3].pic,i);
          break;
        }
        case 2:{
          deck.cardTwo(hand[3].pic,i);
          break;
        }
        case 3:{
          deck.cardThree(hand[3].pic,i);
          break;
        }
        case 4:{
          deck.cardFour(hand[3].pic,i);
          break;
        }
        case 5:{
          deck.cardFive(hand[3].pic,i);
          break;
        }
        case 6:{
          deck.cardSix(hand[3].pic,i);
          break;
        }
        case 7:{
          deck.cardSeven(hand[3].pic,i);
          break;
        }
        case 8:{
          deck.cardEight(hand[3].pic,i);
          break;
        }
        case 9:{
          deck.cardNine(hand[3].pic,i);
          break;
        }
        case 10:{
          deck.cardTen(hand[3].pic,i);
          break;
        }
        case 11:{
          deck.cardJack(hand[3].pic,i);
          break;
        }
        case 12:{
          deck.cardQueen(hand[3].pic,i);
          break;
        }
        case 13:{
          deck.cardKing(hand[3].pic,i);
          break;
        }
      }

      switch (hand[4].num){
          case 1:{
          deck.cardAce(hand[4].pic,i);
          break;
        }
        case 2:{
          deck.cardTwo(hand[4].pic,i);
          break;
        }
        case 3:{
          deck.cardThree(hand[4].pic,i);
          break;
        }
        case 4:{
          deck.cardFour(hand[4].pic,i);
          break;
        }
        case 5:{
          deck.cardFive(hand[4].pic,i);
          break;
        }
        case 6:{
          deck.cardSix(hand[4].pic,i);
          break;
        }
        case 7:{
          deck.cardSeven(hand[4].pic,i);
          break;
        }
        case 8:{
          deck.cardEight(hand[4].pic,i);
          break;
        }
        case 9:{
          deck.cardNine(hand[4].pic,i);
          break;
        }
        case 10:{
          deck.cardTen(hand[4].pic,i);
          break;
        }
        case 11:{
          deck.cardJack(hand[4].pic,i);
          break;
        }
        case 12:{
          deck.cardQueen(hand[4].pic,i);
          break;
        }
        case 13:{
          deck.cardKing(hand[4].pic,i);
          break;
        }
      }
      cout<<endl;
      }
      break;
    }
    case '6':{
      break;
    }
    default:{
      cerr<<"Enter a valid menu option!"<<endl;
    }
  }
}while (choice!='6');

cout<<"Thank You for playing!"<<endl;

return 0;
}
