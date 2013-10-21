#include <iostream>
using namespace std;

class Test
{
 public:
  int num;
  int* weeks;
 public:
  ~Test()
  {
    //delete []weeks;
  }
  void printTest()
  {
    int i;
    for(i=0;i<num;i++)
      {
	cout << weeks[i] << ' ';
      }
    cout << endl;
  }
};

class Schedule
{
 public:
  int n;
  char* S;
  int* p;
  int* OPT;
  int c;
  int r;
 public:
  Schedule(int num, int* weeks, int inr, int inc)
  {
    n = num;
    c = inc;
    r = inr;
    S = new char[n+1];
    p = new int[n+1];
    OPT = new int[n+1];
    getP();
    getOPT(weeks);
    printS();
  }
  ~Schedule()
  {
    delete []S;
    delete []p;
    delete []OPT;
  }
  void getP()
  {
    int i;
    for(i=0;i<n+1;i++)
      {
	if(i<4)
	  p[i] = 0;
	else
	  p[i] = i - 4;
      }
  }
  void getOPT(int* weeks)
  {
    int i, j;
    OPT[0] = 0;
    for(i=1;i<n+1;i++)
      {
	if(4*c + OPT[p[i]] <= weeks[i-1] + OPT[i-1])
	  {
	    OPT[i] = 4*c + OPT[p[i]];
	    for(j=p[i];j<=i;j++)
	      {
		S[j] = 'B';
	      }
	  }
	else
	  {
	    OPT[i] = r*weeks[i-1] + OPT[i-1];
	    S[i] = 'A';
	  }
      }
  }
  void printS()
  {
    int i;
    cout << "      ";
    for(i=1;i<n+1;i++)
      {
	cout  << S[i] << "  ";
      }
    cout <<"cost:" << OPT[i-1] << endl;
  }
};

void get_test(Test*);

