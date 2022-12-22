


#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
typedef struct {
    int outlet;
    int lampInd;
} outLamp;

int getItemIndex(vector <int> lampArr, int outlet)
{
   int maxCount = lampArr.size();
   for (int i=0; i < maxCount; i++)
   {
      if (lampArr.at(i) == outlet)
      return i;
   }
   return -1;
}
int getElemenCount(){
  int count;
  
  while(true){

   cout << "enter total count of element: " ;
        cin >> count;
        if(count>0 && count <=50){
          return count;
        }else{
          cout<<"Entered invalid item count"<<endl;
        }
  }
}



vector<outLamp> combineArray(vector <int>vOutlet, vector<int>vLamp)
{
   vector<outLamp> combined;
   int elementCount = vOutlet.size();
   outLamp tRec;
   for (int i=0; i < elementCount; i++)
   {
      tRec.outlet = vOutlet.at(i);
      tRec.lampInd = getItemIndex(vLamp, tRec.outlet);
      combined.push_back(tRec);
   }
 //  cout << "Size of combined : " << combined.size() << endl;
   return combined;
}

void findIncreasingMaxSubS(vector <outLamp> inpArr, int pos, vector<outLamp>& selection)
{
  int count = inpArr.size();
  vector <outLamp> currSel;
   currSel.clear();
   currSel.push_back(inpArr.at(pos));
   for (int i=pos+1; i < count; i++)
   {
     if (currSel.at(currSel.size()-1).lampInd > inpArr.at(i).lampInd) break;
     currSel.push_back(inpArr.at(i));  
   }
 
   if (selection.empty() || selection.size() < currSel.size())
    {
      selection.clear();
      for (int j=0; j < currSel.size(); j++)
        selection.push_back(currSel.at(j));     
    }
   
   if ( pos < count-1)
  {
    pos++;
   
    findIncreasingMaxSubS(inpArr, pos, selection);
  }
}
int main ()
{
  clock_t time_req;
  vector <int> outletArr;
  vector <int> lampArr;
  vector <outLamp> combinedArr;
  vector <outLamp> retArr;
	int value;
        int count=0;
        count=getElemenCount();
        
        for (int i=0; i < count; i++)
        {
	   cout << "Enter hex for outlet value:";
	   cin >> hex >> value;
           if(value>0 && value <=255){
           outletArr.push_back(value);
        }else{
          cout<<"Invalid hex error"<<endl;
          return -1;
        }

        }

        for (int i=0; i < count; i++)
        {
	   cout << "Enter hex for Lamp value:";
	   cin >> hex >> value;
           lampArr.push_back(value);
        }
        if (lampArr.size() != outletArr.size())
        {
           cout << "outlet element size must be equal to lamp element size" << endl;
           return -1;
        }
        combinedArr = combineArray(outletArr, lampArr);

        time_req = clock();

        findIncreasingMaxSubS(combinedArr,0,retArr);
        cout << retArr.size() << endl;
 
       for (int k=0; k < retArr.size(); k++)
          cout <<uppercase <<hex<<retArr.at(k).outlet;  
       cout << endl;
}
