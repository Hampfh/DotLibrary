#pragma once
#include "Dot.h"
#include <string>
using namespace std;

class Text
{
//Public functions
public:
	Text();
	~Text();
	void drawText(Dot* startPointer, string text, int textSize);
// Private functions
private:
	string _readInput(char letter);
	void _drawText(Dot* startDot, string letterInstructions);
	
	struct characterList {
		string live;
		string a = "5RRRLLLDDDDUURRRRDDUUUU";
		string b = "5RRRR!DD!LLLLUDDDRRRR!U";
		string c = "5RRRRLLLLDDDDRRRR";
		string d = "5RRRR!DDDD!LLLLUUU";
		string e = "5RRRRLLLLDDRRLLDDRRRR";
		string f = "5RRRRLLLLDDRRRLLLDD";
		string g = "5RRRRLLLLDDDDRRRRUULL";
		string h = "5DDDDUURRRRUUDDDD";
		string i = "1DDDD";
		string j = "4#R!R!RDDDDLLLU";
		string k = "4DDDDUURRDD!RU!U!UU";
		string l = "4DDDDRRR";
		string m = "5DDDDUUURR!DU!RRUDDDD";
		string n = "5DDDDUUURR!DR!DRDUUUU";
		string o = "5RRRRDDDDLLLLUUU";
		string p = "5RRRR!DD!LLLLUDDD";
		string q = "5RRRRDDD!DL!UD!LLLUUU";
		string r = "5RRR!DDLDD!RL!UULLUDDD";
		string s = "5RRRRLLLLDDRRRRDDLLLL";
		string t = "5RRRRLLDDDD";
		string u = "5DDDDRRRRUUUU";
		string v = "5DDD!RD!RR!UR!UUU";
		string w = "5DDDDR!UR!UR!DRDUUUU";
		string x = "5R!DR!DR!DR!DU!LU!LD!LD!LU!RU!RU!RU!R";
		string y = "5R!DR!DU!RU!RD!LD!LDD";
		string z = "5RRRRDD!LLLL!DDRRRR";
	} characters;
};

