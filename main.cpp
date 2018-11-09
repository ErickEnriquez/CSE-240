#include <iostream>
#include "enriquez_linkedList"
using namespace std;



int main()
{
	linkedList<int>* list = new linkedList<int>();
    int p ;
    int k ;
    cout<<"numb of ppl\t";
    cin>>p;
    cout<<"kth person to be killed\t";
    cin>>k;
    
    for(int i = 1 ; i<=p ; i++){
        list->addToEnd(i);
    }
   list->InitializeCurrent();
  // list->printList();
   
   cout<<list->getCurrent();
   
   while(list->length() > 2 ){
       for(int x = 1; x< k+1; x++){
           list->nextNode();
       }
       cout<<list->RemoveCurrent()<<" was killed\n";
   }
   
  cout<<"the winner is in position "<<list->RetrieveFront();
   
	return 0;
}



