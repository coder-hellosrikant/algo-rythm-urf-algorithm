#include <iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;

char str[25]="((a+b)())(\0";          //change the expression here to try (x+(f)(x)y)
char *ch=str;
int count=0,ob=0,cb=0;          //ob=opening bracket & cb=closing bracket

void bracket(char *c){    //c is a character which we are reading
  
  x:
  if((*ch)!='\0')
  {
  if( (*ch) == '(' ){
        count++;
        ob++;
        bracket(++ch);
      }
  else if( (*ch) == ')' )
      {
        count--;
        cb++;
        if(count>=0)
        return;
      }
  else      //executed if it's a normal element
      {
        ch++;   //used goto to avoid recursion for
        goto x;   //normal elements
      }               //end of if else if ladder
  }               
  else
      return;     
      
  // these statements execute only when control returns from bracket recursion 
    ch++;
    goto x;     //goto used for evaluating elemts at the same level of count
}

int main()
{
    cout<<"\n********PAIRED BRACKETS OR NOT********";
  bracket(str);
  cout<<"\n\nEnter an Expression: "<<str;
  cout<<"\nNo.of opening brackets"<<ob<<"\nNo.of closing brackets"<<cb;
  if(count==0)
        cout<<"\nThe brackets are matched";
    else if (count>0)
        cout<<"\nError!! Unmatched brackets: End it with "<<count<<" ')' closing bracket";
    else
      cout<<"\n Error!! Unmatched brackets. Invalid expression: add "<<abs(count)<<" missing open '(' bracket";
  return 0;      
}
