#include <iostream>
using namespace std;

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
    cout << endl;
  }
};

class Schedule
{
 public:
  int i;
  char* S;
  int* memo;
 public:
  void OPT(Test test)
  {
  }
  void printS()
  {
  }
};

void get_test(Test*);

