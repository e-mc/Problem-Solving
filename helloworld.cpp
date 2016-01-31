/* Problem solution from 2016 Algorithms Hackathon */
/* We're given a garbled string containing the words "hello"
and "world", and possibly junk characters. We must
count all occurrences of the substring beginning with "hello"
and ending with "world".
ex. helloewiopehelloenncvworld would output 2
*/

#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(int argc, char *argv[]){

  string search_string;                   // holds the garbled string
  cin >> search_string;
  queue<long long int> worlds;            // holds position of substring "world" in search_string
  long long int hello_pos, world_pos = 0; // counters for finding "hello"'s and "world"'s
  long long int substr_count = 0;         // length of substring may exceed int max

  while (world_pos != search_string.length()){
    if (search_string.substr(world_pos, 5) == "world"){
      worlds.push(world_pos);
    } // if "world" is found, push the start position onto the worlds queue
    world_pos++;
  } // find all occurrences of "world", could increment world_pos by 4 each time
  
  while (hello_pos != search_string.length() && !worlds.empty()){
    if (search_string.substr(hello_pos, 5) == "hello"){
      if (worlds.front() > hello_pos){
        substr_count += worlds.size();
      } // if we find "hello", it can match with all occurrences
        // of "world" after it
      else {
        worlds.pop();
        hello_pos--;
      } // if "hello" is passed the first occurrence of "world"
        // on the queue, pop it and try again
    } // do while we're not at the end of the string, and there are still worlds
    
    hello_pos++;
  } // count occurrences of desired substring

  cout << substr_count << endl;
  
} //helloworld main
