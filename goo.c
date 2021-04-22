#include <omp.h>
#include <stdio.h>

int main()
{

  int count = 0;
  int arraysize = 0;
  int searchIndex = 0;

  printf("Enter your arraysize: ");
  scanf("%d", &arraysize);

  printf("Enter the number you are searching for: ");
  scanf("%d", &searchIndex);

  int a[arraysize][arraysize];
  int end, start;
  start = omp_get_wtime();
#pragma omp parallel for
  for (int i = 0; i < arraysize; i++)
  {
    for (int j = 0; j < arraysize; j++)
    {
      a[i][j] = rand() % 10;
      printf("%d \n ", a[i][j]);
    }
  }

#pragma omp parallel for
  for (int i = 0; i < arraysize; i++)
  {
    for (int j = 0; j < arraysize; j++)
    {

      if (a[i][j] == searchIndex)
      {
        count++;
      }
    }
  }
  end = omp_get_wtime();
  printf("Work took %d second\n", end - start);
  printf("count -- %d \n ", count);
}
