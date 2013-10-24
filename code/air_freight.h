#include <iostream>
using std::cout;

class Test
{
 public:
  int num;
  int* weeks;
 public:
  void printTest()
  {
    int i;
    for(i=0;i<num;i++)
      {
	cout << weeks[i] << ' ';
      }
    cout << '\n';
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
    int i, j, k;
    OPT[0] = 0;
    for(i=1;i<n+1;i++)
      {
	if(4*c + OPT[p[i]] <= r*weeks[i-1] + OPT[i-1])
	  {
	    OPT[i] = 4*c + OPT[p[i]];
	  }
	else
	  {
	    OPT[i] = r*weeks[i-1] + OPT[i-1];
	  }
      }
    i = n;
    while(i)
      {
	S[i] = 'A';
	if(OPT[i]==4*c+OPT[p[i]]&&OPT[i]!=OPT[i-1]+r*weeks[i-1])
	  {
	    for(j=p[i]+1;j<=i;j++)
	      S[j] = 'B';
	    i = p[i];
	    continue;
	  }
	i--;
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
    cout <<"cost:" << OPT[i-1] << '\n';
  }
};

//void get_test(Test*);

