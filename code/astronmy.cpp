#include "air_freight.hpp"
#include "astronmy.hpp"

int main()
{
  int i, j;
  Test test[4];
  int num[4] = {11, 10, 11, 9};
  int* coor[4];
  int test1[] = {0, 9, 9, 11, 12, 12, 12, 12, 11, 9, 9};
  int test2[] = {0, 1, -4, -1, 4, 5, -4, 6, 7, -2};
  int test3[] = {0, 1, 7, 8, 12, 14, 10, 7, 14, 8, 8};
  int test4[] = {0, 2, -2, -3, 10, 11, 12, 13, 1};
  coor[0] = test1;
  coor[1] = test2;
  coor[2] = test3;
  coor[3] = test4;
  for(i=0;i<4;i++)
    {
      test[i].num = num[i];
      test[i].weeks = new int[test[i].num];
      for(j=0;j<num[i];j++)
        {
          test[i].weeks[j] = coor[i][j];
        }
      cout << "Event:";
      for(j=0;j<num[i];j++)
	cout << j << " ";
      cout << '\n' << "      ";
      test[i].printTest();
      Event event(test[i].num, test[i].weeks);
      delete []test[i].weeks;
    }
}
