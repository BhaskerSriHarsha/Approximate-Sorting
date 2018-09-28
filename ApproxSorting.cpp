#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>


using namespace std;

int main()
{
  int NumberOfTestCases,NumberOfElements;
  int ArrayOfInputNumbers;
  string e,e2,Input;

  scanf("%d",&NumberOfTestCases);
  getline(cin,e);

  for(;NumberOfTestCases>0;NumberOfTestCases--)
  {
    scanf("%d", &NumberOfElements);
    getline(cin,e2);

    getline(cin, Input);

    int InputIndexPointer,res=0;
    int IndexOfEmptyCell=0;
    int NumberOfElementsInArray=0;
    int array[NumberOfElements];
    priority_queue < int, deque <int>, greater<int> > H1; //min-heap


    for (InputIndexPointer=0;Input[InputIndexPointer]!='\0';)
    {
      if(Input[InputIndexPointer] != ' ' and Input[InputIndexPointer] != '\0' )
      {
        while(Input[InputIndexPointer] != ' ' and Input[InputIndexPointer] != '\0')
        {
         res = (res*10) + (Input[InputIndexPointer]-48);
         InputIndexPointer++;
        }
        array[IndexOfEmptyCell]=res;
        IndexOfEmptyCell++;
        res=0;
      }
      else
      {
        InputIndexPointer++;
      }
    }

    NumberOfElementsInArray=IndexOfEmptyCell;
    int loopCount = NumberOfElementsInArray-1;
    int loopCountForDisplay,DisplayElement;

    if(NumberOfElementsInArray<50)
    {
      for(;loopCount>=0;loopCount--)
      {
        H1.push(array[loopCount]);
      }
      //Display the elements in assending order
      for(loopCountForDisplay=0;loopCountForDisplay<NumberOfElementsInArray;loopCountForDisplay++)
      {
        DisplayElement=H1.top();
        cout<<DisplayElement<<" ";
        H1.pop();
      }
      cout<<endl;


    }
    else
    {
      //push first 50 elements into the heap
      int push50Count;
      for(push50Count=0;push50Count<50;push50Count++)
      {
        H1.push(array[push50Count]);
      }

      DisplayElement=H1.top();
      H1.pop();
      cout<<DisplayElement<<" ";


      for(;push50Count<NumberOfElementsInArray;push50Count++)
      {
        H1.push(array[push50Count]);
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
