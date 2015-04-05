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
#include <assert.h>
#include <iomanip>


using namespace std;


vector < char > student(25);
vector <char> buf (25, ' ');

void one (int s, int paragraph)
{
   if ((paragraph > 1 &&  paragraph < 2 + s) || (paragraph > s+ 2 && paragraph < s *2 + 3))
      {
         buf[s+1] = '|';
      }  
}

void two (int s, int paragraph)
{
   if (paragraph == 1 ||  paragraph == 2 + s || paragraph == 2*s + 3)
      {
         for (int i = 1; i < s+1; i++)
            buf [i] = '-';
      }
      else if (paragraph > 1 && paragraph < s+2) 
      {
         buf[s+1] = '|';
      }
      else if (paragraph > s+2 && paragraph < 2 * s + 3)
      {
         buf[0] = '|';
      }
   
}

void three(int s, int paragraph)
{
   if (paragraph == 1 ||  paragraph == 2 + s || paragraph == 2*s + 3)
      {
         for (int i = 1; i < s+1; i++)
            buf [i] = '-';
      }
      else if ((paragraph > 1 && paragraph < s+2) || (paragraph > s+2 && paragraph < 2*s+3))
      {
         buf[s+1] = '|';
      }
}

void four (int s, int paragraph)
{
   if (paragraph > 1 && paragraph < s+2)
   {
      buf[0] = '|';
      buf[s+1] = '|';
   }
   if (paragraph == s + 2)
      for (int i = 1; i < s+1; i++)
         buf[i] = '-';
   if (paragraph > s +2 && paragraph < 2* s +3)
   {
      buf[s+1] = '|';
   }
}

void five (int s, int paragraph)
{
   if (paragraph == 1 ||  paragraph == 2 + s || paragraph == 2*s + 3)
      {
         for (int i = 1; i < s+1; i++)
            buf [i] = '-';
      }
      else if (paragraph > 1 && paragraph < s+2)
      {
          buf[0] = '|';
      }
      else if (paragraph > s +2 && paragraph < 2* s +3)
      {
         buf[s+2-1] = '|';
      }
   
}

void six (int s, int paragraph)
{
   if (paragraph == 1 ||  paragraph == 2 + s || paragraph == 2*s + 3)
      {
         for (int i = 1; i < s+1; i++)
            buf [i] = '-';
      }
   if (paragraph > 1 && paragraph < s + 2)
   {
      buf[0] = '|';
   }
   if (paragraph > s+2 && paragraph < 2*s +3)
   {
      buf[0] = '|';
      buf[s+1] = '|';
   }
}

void seven (int s, int paragraph)
{
   if (paragraph == 1)
      for (int i = 1; i< s+1;i++)
         buf[i] = '-';
   if ((paragraph > 1 && paragraph < s +2) || (paragraph > s+2 && paragraph < 2*s +3))
   {
      buf[s+1] = '|';
   } 
}

void eight (int s, int paragraph)
{
   
   if (paragraph == 1 ||  paragraph == 2 + s || paragraph == 2*s + 3)
      {
         for (int i = 1; i < s+1; i++)
            buf [i] = '-';
      }
   if ((paragraph > s+2 && paragraph < 2*s +3) || (paragraph > 1 && paragraph < s + 2))
   {
      buf[0] = '|';
      buf[s+1] = '|';
   }
}

void nine(int s, int paragraph)
{
   if (paragraph == 1 ||  paragraph == 2 + s || paragraph == 2*s + 3)
      {
         for (int i = 1; i < s+1; i++)
            buf [i] = '-';
      }
   if (paragraph > 1 && paragraph < s + 2)
   {
      buf[0] = '|';
      buf[s+1] = '|';
   }
   if (paragraph > s+2 && paragraph < 2*s +3)
   {
      buf[s+1] = '|';
   }
}

void zero (int s, int paragraph)
{
    if (paragraph == 1 ||  paragraph == 2*s + 3)
      {
         for (int i = 1; i < s+1; i++)
            buf [i] = '-';
      }
   if ((paragraph > 1 && paragraph < s +2) || (paragraph >s+2 && paragraph < s * 2 + 3)) 
      {
         buf [0] = '|';
         buf [s+1] = '|';
      }
}

void output (vector <int> number, int s)
{
  
   for (int i = 1; i <= 2*s + 3; i++)
   {
      for (int j = 0; j <= 10; j++)
      {
         if (number[j] >= 0)
         {
            switch (number[j])
         {
            case 1: one(s,i); break;
            case 2: two(s,i); break;
            case 3: three(s,i); break;
            case 4: four(s,i); break;
            case 5: five(s,i); break;
            case 6: six(s,i); break;
            case 7: seven(s,i); break;
            case 8: eight(s,i); break;
            case 9: nine(s,i); break;
            case 0: zero(s,i); break;
         }
         for(int h = 0; h <= s+2; h++)
         {
            if (j == 10 && h == s+2) break;
            cout<<buf[h];
            buf[h] = ' ';
         }
      }
      }
       cout<<endl;
     
   } 
   cout<<endl;
}


void res (int s, int number)
{
   
   vector <int> decimal (11, -1);
   int counter = 10;
   if (number == 0) { decimal[10] = 0;}
   else
   {
   while (number > 0)
   {
      decimal[counter] = number % 10;
      counter--;
      number /= 10;
   }
   }
   output(decimal, s);

}

int main()
{

   // Comment next line to read from console.
   //freopen("input.txt","r",stdin);
   //freopen("outputM.txt","w",stdout);
   //freopen("output.txt","w",stdout);
   int s,number;
   while (cin>>s>>number) 
   {
     if (s == 0) break;
      res(s,number);    
   }

   return 0;
}
