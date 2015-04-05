#include <iostream>
#include <string>
#include <stdio.h>
#include <stack>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout); 
	string s;
	cin>>s;
	stack <char> myStack;
	char a,b,c;
	for (int i = s.size()-1; i >= 0; i--){
		if (myStack.size()){
		a = myStack.top();
		if (a == s[i]){
			myStack.pop();
		}
		else myStack.push(s[i]);}
		else myStack.push(s[i]);
	}

	while(myStack.size()){
		cout<<myStack.top();
		myStack.pop();
	}
}