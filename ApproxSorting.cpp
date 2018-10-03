#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
  int NumberOfTestCases;
  cin>>NumberOfTestCases;

  for(;NumberOfTestCases>0;NumberOfTestCases--)
  {
    int NumberOfElements;
    int Input;
    priority_queue < int, deque <int>, greater<int> > H1; //min-heap

    cin>>NumberOfElements;

    if(NumberOfElements<50)
    {
      //push all into the heap
      int pushLoopCount=NumberOfElements;
      for(;pushLoopCount>0;pushLoopCount--)
      {
        cin>>Input;
        H1.push(Input);
      }

      //delete all of them line by line
      int popLoopCount=NumberOfElements;
      int DisplayElement;
      for(;popLoopCount>0;popLoopCount--)
      {
        DisplayElement=H1.top();
        cout<<DisplayElement<<" ";
        H1.pop();
      }

      cout<<endl;
    }
    else
    {
      //push 50 elements into the min heap
      int push50Count;
      for(push50Count=0;push50Count<50;push50Count++)
      {
        cin>>Input;
        H1.push(Input);
      }


      //pop
      int DisplayElement;
      DisplayElement=H1.top();
      H1.pop();
      cout<<DisplayElement<<" ";

      //continue popping till minheap is empty
      for(;push50Count<NumberOfElements;push50Count++)//change to InArray
      {
        cin>>Input;
        H1.push(Input);
        DisplayElement=H1.top();
        H1.pop();
        cout<<DisplayElement<<" ";
      }

      while(!H1.empty())
      {
        DisplayElement=H1.top();
        H1.pop();
        cout<<DisplayElement<<" ";
      }
      cout<<endl;
    }


  }
}
