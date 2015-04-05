#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <set>

//typedef map <string, string> myMap;

using namespace std;

map < string, string > u;

void regist()
{
	string s1,s2;
	cin>>s1>>s2;
	if (u.find(s1) != u.end())
		cout<<"fail: user already exists"<<endl;
	else { u.insert(pair < string, string > (s1,s2)); cout<<"success: new user added"<<endl; }
}

void login( set <string> &l)
{
	string s1,s2;
	cin>>s1>>s2;
	if ( u.find(s1) != u.end() ){
		if ( u[s1] == s2) {
			if (l.find(s1) != l.end()) cout<<"fail: already logged in"<<endl;
			else { cout<<"success: user logged in"<<endl; l.insert(s1); } }
		else cout<<"fail: incorrect password"<<endl;
	}
	else cout<<"fail: no such user"<<endl;
}

void logout( set <string> &l)
{
	string s1;
	cin>>s1;
	if (u.find(s1) == u.end()) {
		cout<<"fail: no such user"<<endl;
	}
	else { if (l.find(s1) != l.end()) { cout<<"success: user logged out"<<endl; l.erase(s1); }
	else cout<<"fail: already logged out"<<endl; }
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	//map < string, string > user;
	set <string> logined;
	string s;
	int n;
	cin>>n;
	for (int i = 0; i < n; i++) {
		cin>>s;
		if (s == "register") regist();
		else if (s == "login") login(logined);
		else if (s == "logout") logout(logined);
	}
}