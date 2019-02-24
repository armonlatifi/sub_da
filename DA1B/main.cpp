#include <iostream>
#include <cmath>
using namespace std;

int main(){

int x[99]; //initialize array with 99 values
int r, y, z, val; //remainder, y sums, z sums, value
int index = 0;

for (int i = 11; i <= (11+99); i++){ //for-loop to store every sequential number
  x[index] = i;                      //into array
  index++;
}

y = 0;
z = 0;

for (int i = 0; i <= 98; i++){
  val = x[i];
  r = val % 3; //check if value is divisble by three

  if (r == 0){ //value IS divisble by three
    y = y + val;

  }

  if (r != 0){
    z = z + val;
  }
}

cout << "Number Sum divisble by 3: " << y << endl;
cout << "Number Sum not divisible by 3: " << z << endl;

return 0;
}
