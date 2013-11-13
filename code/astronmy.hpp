#include <iostream>
using std::cout;

class Event
{
 public:
  int n;
  int* OPT;
 public:
  Event(int num, int* weeks)
    {
      n = num;
      OPT = new int[n+1];
      getOPT(weeks);
      printS();
    }
  ~Event()
    {
      delete []OPT;
    }
  void getOPT(int* weeks)
  {
    int i, j;
    OPT[0] = 0;
    for(i=1;i<n;i++)
      {
	int max = 0;
	if(weeks[i]*weeks[i] > i*i)
	  {
	    OPT[i] = 0;
	    continue;
	  }
	for(j=1;j<i;j++)
	  {
	    if((weeks[j]-weeks[i])*(weeks[j]-weeks[i]) <= (j-i)*(j-i))
	      {
		if(OPT[j]>max)
		  max = OPT[j];
	      }
	  }
	  OPT[i] = 1 + max;
      }
  }
  void printS()
  {
    int i;
    cout << "      ";
    for(i=0;i<n;i++)
      cout << OPT[i] << ' ';
    cout << "   " <<"max events:" << OPT[n-1] << '\n';
  }
};
