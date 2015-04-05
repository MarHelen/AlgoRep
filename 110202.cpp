#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <math.h>
#include <map>
#include <set>
#include <memory.h>
#include <numeric>
#include <ctype.h>

using namespace std;

vector < pair<char, char> > blackHand(6);
vector < pair<char, char> > whiteHand(6);

string cards = "23456789TJQKA";

void sorting (vector < pair<char, char> > &s)
{
	int iterators [6];
	for (int i = 1; i < 6; i++)
	{
		s[i].first = toupper(s[i].first);
		s[i].second = toupper(s[i].second);
		iterators[i] = cards.find(s[i].first);
	}
	for (int i = 1; i < 5; i++)
	{
		for (int j = i+1; j < 6; j++)
		{
			if (iterators[i] > iterators[j])
				{swap(s[i].first,s[j].first);
				swap(s[i].second,s[j].second);
				swap(iterators[i],iterators[j]);}	
		}
	}

}

int flash(set <char> &s)
{
	if (s.size() == 1)
		return 1;
	return 0;
}

int street (string &s)
{
	if (cards.find(s) != string::npos)
		return 1;
	if (s[0] == 'A' && s[1] == '2' && s[2] == '3' & s[3] == '4' && s[4] == '5')
		return 1;

	return 0;
}

int whoOlder(string &black, string &white)
{	for (int i = 4; i > 0; i--)
	{
		if (cards.find(black[i]) > cards.find(white[i]) )
				return 1; //black wins
			else if (cards.find(black[i]) < cards.find(white[i]))
				return 0; // white wins
	}
	return 3;
}

char care(set <char> &c, string &s)
{
	if (c.size() == 2 && s[1]==s[2] && s[2] == s[3])
		return s[3];
	return ' ';
}

char three(string &s)
{
	//cout<<"tree"<<endl;
	//char av = s[2];
	int first = s.find(s[2]);
	int last = s.find_last_of(s[2]);
	if (last - first == 2)
		return s[2];
	//cout<<"nothing in tree"<<endl;
	return ' ';
}

string two(string s)
{
	string res;
	res.empty();
	char av; 
	if (s.find_last_of(s[1]) - s.find(s[1]) == 1)
		{ res += s[1];}
	if (s.find_last_of(s[3]) - s.find(s[3]) == 1)
		{ res += s[3];}
	//cout<<res;
	return res;
}

int whoOlder(char black, char white)
{
	if (cards.find(black) > cards.find(white))
		return 1;
	else if (cards.find(black) < cards.find(white))
		return 0;
	return 3;
}

int result ()
{
	set <char> blackValue;
	set  <char> blackSuit;
	set <char> whiteValue;
	set  <char> whiteSuit;
	int res = 3;
	string blackString, whiteString;
	sorting(blackHand);
	sorting(whiteHand);
	for (int i = 1; i < 6; i++)
	{
		blackValue.insert(blackHand[i].first);
		blackSuit.insert(blackHand[i].second);
		whiteValue.insert(whiteHand[i].first);
		whiteSuit.insert(whiteHand[i].second);
		blackString += blackHand[i].first;
		whiteString += whiteHand[i].first;
	}
	//cout<<blackString<<' '<<whiteString<<endl;
	//street flash
	//cout<<flash(whiteSuit)<<" whiteFlashVal"<<endl;
	//cout<<street(whiteString)<<" whiteStreetVal"<<endl;	
	if (flash(blackSuit) && street(blackString))
	{
		if (flash(whiteSuit) && street(whiteString))
		{
			return whoOlder(blackString,whiteString);
		}
		else return 1; //black wins
	}
	if (flash(whiteSuit) && street(whiteString))
	{
		return 0; //white wins
	}

	//care
	char c1 = care(blackValue, blackString);
	char c2 = care(whiteValue, whiteString);
	//cout<<c1;
	//cout<<c2;
	//cout<<whoOlder(c1,c2)<<endl;
	if (c1 != ' ')
	{
		if (c2 != ' ')
			return whoOlder(c1,c2); 
		else return 1; //black wins
	}
	if (c2 != ' ')
		return 0; //white wins
	//three
	c1 = three(blackString);
	c2 = three(whiteString);
	int buf;
	string c3 = two(blackString);
	string c4 = two(whiteString);
	if (c1 != ' ' && c3.size() == 1)
	{
		if (c2 != ' ' && c4.size() == 1)
		{
			buf = whoOlder(c1,c2);
			if (buf == 3)
			{
				buf = whoOlder(c3[0],c4[0]);
				return buf;
			} 
			else return buf;
		}
		else return 1; //black wins
	}
		//flash
	if (c2 != ' ' && c4.size() == 1)
		return 0;
	if (flash(blackSuit))
	{
		if (flash(whiteSuit))
			return whoOlder(blackString,whiteString);
		else return 1;
	}
	 //black wuns
	if (flash(whiteSuit)) return 0; //white wins
	//street
	if (street(blackString))
	{
		if (street(whiteString))
			return whoOlder(blackString,whiteString);
		else return 1;
	}
	
	if (street(whiteString)) return 0;
	//three
	if (c1 != ' ')
	{
		if (c2 != ' ')
			{
				buf = whoOlder(c1,c2);
				if (buf == 3)
					return whoOlder(blackString,whiteString);
				else return buf;
			}
			else return 1;
	}
	if (c2 != ' ')
		return 0;
	//two pair
	if (c3.size() == 2)
	{
		if (c4.size() == 2)
		{
			cout<<"two pair both";
			if (cards.find(c3[0]) > cards.find(c4[0]))
			{
				if (whoOlder(c3[1],c4[0]) == 3)
				return whoOlder(c3[0],c4[1]);
				else return whoOlder(c3[1],c4[0]);
			}
		else if (whoOlder(c3[0],c4[1]) == 3)
				return whoOlder(c3[1],c4[0]);
				else return whoOlder(c3[0],c4[1]);
		}
	else return 1;
	}
	if (c4.size() == 2) return 0;
	//pair
	if (c3.size() == 1)
	{
		if(c4.size() == 1)
		{
			return whoOlder(c3,c4);
		}
		else return 1;
	}
	//older
	return whoOlder(blackString,whiteString);
}

int main()
{
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string c;
    int counter;
    while (getline(cin,c))
    {
    	//getline(cin,c);
    	if (c.size() == 0) break;
    	int j = 1;
    	int i = 0;
    	while (j < 11)
    	{
    		if (j > 10) break;
    		if (c[i] != ' ')
    		{
    			if (j < 6)
    			{
    			blackHand[j].first = c[i];
    			blackHand[j].second = c[i+1];
    			//cout<<blackHand[j].first;
    			//cout<<blackHand[j].second<<' ';
    			}
    			else if (j > 5 && j < 11)
    			{
    			whiteHand[j-5].first = c[i];
    			whiteHand[j-5].second = c[i+1];
    			//cout<<whiteHand[j-5].first;
    			//cout<<whiteHand[j-5].second<<' ';
    			}
    			j++; i++;
    		}
    		i++;
    	}
    	//cout<<endl;
    	int res = result();
    	if (res == 1) cout<<"Black wins."<<endl;
    		else if (!res) cout<<"White wins."<<endl;
    			else cout<<"Tie."<<endl;
    	//cout<<endl;
    }
	return 0;
}