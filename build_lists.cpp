/********************************************
*Author: Gentry Atkinson
*Date: 5 November, 2019
*Description: outputs several files of random numbers
********************************************/

#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int SHORT = 100;
const int MEDIUM = 1000;
const int LONG = 10000;

const char* SHORT_RANDOM_FILE = "short_random.txt";
const char* MEDIUM_RANDOM_FILE = "medium_random.txt";
const char* LONG_RANDOM_FILE = "long_random.txt";

const char* SHORT_RANDOM_NO_DUP_FILE = "short_ND_random.txt";
const char* MEDIUM_RANDOM_NO_DUP_FILE = "medium_ND_random.txt";
const char* LONG_RANDOM_NO_DUP_FILE = "long_ND_random.txt";

const char* SHORT_NEAR_SORTED_FILE = "short_near_sorted.txt";
const char* MEDIUM_NEAR_SORTED_FILE = "medium_near_sorted.txt";
const char* LONG_NEAR_SORTED_FILE = "long_near_sorted.txt";

void writeRandom(int,const char*);
void writeRandomNoDuplicates(int, int,const char*);
void writeNearSorted(int,const char*);
void swap(int[], int, int);

int main(){
  printf("Printing random files...\n");
  writeRandom(SHORT, SHORT_RANDOM_FILE);
  writeRandom(MEDIUM, MEDIUM_RANDOM_FILE);
  writeRandom(LONG, LONG_RANDOM_FILE);

  printf("Printing random, no duplicate files...\n");
  writeRandomNoDuplicates(SHORT, 2*SHORT, SHORT_RANDOM_NO_DUP_FILE);
  writeRandomNoDuplicates(MEDIUM, 2*MEDIUM, MEDIUM_RANDOM_NO_DUP_FILE);
  writeRandomNoDuplicates(LONG, 2*LONG, LONG_RANDOM_NO_DUP_FILE);

  printf("Printing near sorted files...\n");
  writeNearSorted(SHORT, SHORT_NEAR_SORTED_FILE);
  writeNearSorted(MEDIUM, MEDIUM_NEAR_SORTED_FILE);
  writeNearSorted(LONG, LONG_NEAR_SORTED_FILE);
  return 0;
}

void writeRandom(int numValues, const char* filename){
  srand(time(NULL));
  ofstream outFile(filename);
  for(int i = 0; i < numValues; ++i)
    outFile << rand() % numValues << endl;
  return;
}

void writeRandomNoDuplicates(int numValues, int numSwaps, const char* filename){
  int values[numValues];
  srand(time(NULL));
  for(int i = 0; i < numValues; ++i)
    values[i] = i;
  ofstream outFile(filename);
  for(int i = 0; i<numSwaps; ++i)
    swap(values, rand() % numValues, rand() % numValues);
  for(int i = 0; i<numValues; ++i)
    outFile << values[i] << endl;
  return;
}

void writeNearSorted(int numValues, const char* filename){
  writeRandomNoDuplicates(numValues, numValues/10, filename);
  return;
}

void swap(int a[], int i, int j){
  if (i==j) return;
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
  return;
}
