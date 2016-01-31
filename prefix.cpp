/* Problem solution from 2016 Algorithms Hackathon */
/* We're given a list of phone numbers of up to 20 digits each
and must find the length of the prefix shared by each number.
ex. 12345 and 12366 have a common prefix of length 3.
All numbers must have the common prefix, so we can compare every
number to the first one.
*/
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *arg[]){
  long long int numbers; // total number of #s may exceed int's max
  long long int i = 1;   // i is a counter that could have value <= numbers
  char first_number[20]; // each number has a max of 20 digits
  int min_common = 20;   // numbers could have up to 20 digits in common
  cin >> numbers;        // read in number of #s
  cin >> first_number;   // get the first number
  
  while (i < numbers){
    char next_number[20];       // we compare all subsequent numbers to the first number
    int counter, new_min = 0;   // new_min will hold the new minimum number of common digits
    cin >> next_number;
    i++;
    
    while (counter < min_common && next_number[counter] == first_number[counter]){
      new_min++;
      counter++;
    } // increment while prefixes match and 
      //counter is less than the min in common

    if (new_min < min_common)
      min_common = new_min;
  } // always choose the lowest min
  
  cout << min_common << endl;
} // prefix main
