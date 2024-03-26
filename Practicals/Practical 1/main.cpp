#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

/*
	stringToInt is a helper function that will 
	take a string called line and return the integer value
*/
int stringToInt(string line){
	stringstream s1(line);
	int temp = 0;
	s1 >> temp;
	return temp;
}

int main() {
	//2d array size number of line - 1 / 2 due to format
	//then determine number of items in each line and add to columns
	//easy peasy right?
}

/*
Expected output with the given building.txt:

Sunil,Alok,Kamilah,Pratik
Tamera,Zanetta,Keyundra,Alexzander,Nickalaus,Nathania,Annamaria,Ransen,Thuy,Yousef       
Jeffry,Shira,Sereena
Janna,Shaleen,Josi,Ndidi,Indalecio,Charlotta
Kejuan,Matricia,Takiya,Karalyn,Charls
Rebbecca
Kailyn,Kenda
Katheryne,Coury,Timithy,Melisssa,Clara,Lucus,Brittony,Makoto,Latona,Rudolph
*/

