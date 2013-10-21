#include <iostream>
#include <sstream>
#include <cstring>
#include <fstream>
using namespace std;

#include "air_freight.h"

const int r = 1;
const int c = 10;

int main()
{
  Test test;
  test.weeks = new int[test.num]; 
  get_test(&test);
  //cout << test.num << endl;
  cout << "Test:" << ' ';
  test.printTest();
  Schedule schedule(test.num, test.weeks, r, c);
  delete []test.weeks;
}

void get_test(Test* test)
{
  string str, cmd;
  //int weeks[10];
  ifstream in;
  in.open("test");
  if(in.is_open())
    {
      getline (in, str);
      while(in)
	{
	  if((str.find_first_not_of(" \t\r\n") != string::npos) && (str[0] != '#'))
	    {
	      stringstream s(str);
	      int i;
	      int* weeks = new int[i];
	      for(i=0;;i++)
		{
		  s >> weeks[i];
		  if(weeks[i]==0)
		    {
		      delete []weeks;
		      break;
		    }
		  //cout << weeks[i] << endl;
		  test->num = i+1;
		  test->weeks[i] = weeks[i];
		  //cout << test->num << '\t';
		  //cout << test->weeks[i] << endl;
		  //test->printTest();
		}
	    }
	  getline(in, str);
	}
    }
}

