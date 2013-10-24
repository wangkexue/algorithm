//#include <iostream>
//#include <sstream>
#include <cstring>
//#include <fstream>
using namespace std;

#include "air_freight.h"

const int r = 1;
const int c = 10;

int main()
{
  int i, j;
  Test test[4];
  int num[4] = {10, 9, 10, 6};
  int* weeks[4];
  int test1[] = {9, 9, 11, 12, 12, 12, 12, 11, 9, 9};
  int test2[] = {7, 6, 10, 20, 15, 17, 8, 14, 20};
  int test3[] = {1, 7, 8, 12, 14, 10, 7, 14, 8, 8};
  int test4[] = {10, 15, 13, 10, 12, 17};
  weeks[0] = test1;
  weeks[1] = test2;
  weeks[2] = test3;
  weeks[3] = test4;
  for(i=0;i<4;i++)
    {
      test[i].num = num[i];
      test[i].weeks = new int[test[i].num];
      for(j=0;j<num[i];j++)
	{
	  test[i].weeks[j] = weeks[i][j];
	}
      //get_test(&(test));
      cout << "Test:" << ' ';
      test[i].printTest();
      Schedule schedule(test[i].num, test[i].weeks, r, c);
      delete []test[i].weeks;      
    }
}

/*
void get_test(Test* test)
{
  string str, cmd;
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
		  test->num = i+1;
		  test->weeks[i] = weeks[i];
		}
	    }
	  //	  getline(in, str);
	}
    }
}
*/
