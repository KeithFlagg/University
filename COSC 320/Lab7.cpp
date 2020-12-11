//Keith Flagg
//Dr. Anderson
//COSC 320

#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>


//hashes an integer
size_t hash(size_t);
//hashes strings
size_t strHash(std::string);
size_t strHash2(std::string);

//converts hash to hex
void convHex(size_t);


int main(){
size_t num1 = 0;
size_t num2 = 0;
size_t hi1 = 0;
size_t hi2 = 0;

std::cout << "Hashing integers using the multiplication method: " << std::endl;
std::cout << "Testing 10: \n";
convHex(hash(10));
std::cout << "---------------------------------------------------------" << std::endl<<std::endl;

std::cout << "Testing 100: \n";
convHex(hash(100));
std::cout << "---------------------------------------------------------" << std::endl<<std::endl;

std::cout << "Testing 314159265359: \n";
convHex(hash(314159265359));
std::cout << "---------------------------------------------------------" << std::endl<<std::endl;

std::cout << "Testing if 25 has the same hash as 25:  \n";

num1 = hash(25);
num2 = hash(25);

  if(hi1 == hi2){
    std::cout<<"25's hash is equal to 25's hash: \n";
    convHex(num1);
    convHex(num2);
  }
  else{
    std::cerr << "The hash values are not equal!\n";
    convHex(num1);
    convHex(num2);
  }


std::cout << std::endl << std::endl << "Hashing strings using method 1: " << std::endl;

std::cout << "Testing hi:  \n";
convHex(strHash("hi"));
std::cout << "---------------------------------------------------------" << std::endl<<std::endl;

std::cout << "Testing Hi:  \n";
convHex(strHash("Hi"));
std::cout << "---------------------------------------------------------" << std::endl<<std::endl;

std::cout << "Testing the U.S constitution preamble:  \n";
convHex(strHash("We the People of the United States, in Order to form a more perfect Union, establish Justice, insure domestic Tranquility, provide for the common defence, promote the general Welfare, and secure the Blessings of Liberty to ourselves and our Posterity, do ordain and establish this Constitution for the United States of America."));
std::cout << "---------------------------------------------------------" << std::endl<<std::endl;

std::cout << "Testing if hi has the same hash as hi:  \n";

hi1 = strHash("hi");
hi2 = strHash("hi");

  if(hi1 == hi2){
    std::cout<<"hi's hash is equal to hi's hash: \n";
    convHex(hi1);
    convHex(hi2);
  }
  else{
    std::cerr << "The hash values are not equal!\n";
    convHex(hi1);
    convHex(hi2);
  }

std::cout << "---------------------------------------------------------" << std::endl<<std::endl;


std::cout << "Hashing strings using method 2: " << std::endl;

std::cout << "Testing hi:  \n";
convHex(strHash2("hi"));
std::cout << "---------------------------------------------------------" << std::endl<<std::endl;

std::cout << "Testing Hi:  \n";
convHex(strHash2("Hi"));
std::cout << "---------------------------------------------------------" << std::endl<<std::endl;

std::cout << "Testing the U.S constitution preamble:  \n";
convHex(strHash2("We the People of the United States, in Order to form a more perfect Union, establish Justice, insure domestic Tranquility, provide for the common defence, promote the general Welfare, and secure the Blessings of Liberty to ourselves and our Posterity, do ordain and establish this Constitution for the United States of America."));
std::cout << "---------------------------------------------------------" << std::endl<<std::endl;

std::cout << "Testing if hi has the same hash as hi:  \n";

hi1 = strHash2("hi");
hi2 = strHash2("hi");

  if(hi1 == hi2){
    std::cout<<"hi's hash is equal to hi's hash: \n";
    convHex(hi1);
    convHex(hi2);
  }
  else{
    std::cerr << "The hash values are not equal!\n";
    convHex(hi1);
    convHex(hi2);
  }

std::cout << "---------------------------------------------------------" << std::endl<<std::endl;


  return 0;
}


size_t hash(size_t x){
  size_t W = pow(2,32);
  size_t p = 17;
  size_t a = 1500450271;

return (a * x % W) / pow(2,(32 - p));
}

size_t strHash(std::string str){
size_t num = 0;

  for(size_t i = 0; i < str.length(); i++){
    num += (int)str[i];
  }
return hash(num);
}


size_t strHash2(std::string str){
size_t num = 0;
size_t prime = 1046527;

  for(size_t i = 0; i < str.length(); i++){
    num += (num * prime) + (int)str[i];
  }

return hash(num);
}


void convHex(size_t n){
  std::cout << "Hash: " << std::hex << n << std::endl;
}
