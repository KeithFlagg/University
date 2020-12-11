#ifndef CARD_H
#define CARD_H

using namespace std;

struct ACard{
  int num;
  char pic[4];
};

const char spade[4] = "\xe2\x99\xa0";
const char club[4] = "\xe2\x99\xa3";
const char heart[4] = "\xe2\x99\xa5";
const char diamond[4] = "\xe2\x99\xa6";

class Card
{
private:
ACard cards[52];
int nextCard;

public:
Card();
void shuffleCard();
ACard getCard();


void cardAce(const char pic[],int);
void cardTwo(const char pic[],int);
void cardThree(const char pic[],int);
void cardFour(const char pic[],int);
void cardFive(const char pic[],int);
void cardSix(const char pic[],int);
void cardSeven(const char pic[],int);
void cardEight(const char pic[],int);
void cardNine(const char pic[],int);
void cardTen(const char pic[],int);
void cardJack(const char pic[],int);
void cardQueen(const char pic[],int);
void cardKing(const char pic[],int);

};
#endif
