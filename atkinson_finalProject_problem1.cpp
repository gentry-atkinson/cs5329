/********************************************
*Author: Gentry Atkinson
*Date: 5 November, 2019
*Class: CS5329 Fall 2019
*Description: times several sorting algorithms
********************************************/
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

#include<fstream>
#include<iostream>
#include<chrono>

using namespace std;

void insertionSort(int[], int);
void mergeSort(int[], int);
void quickSort(int[], int);
void randomizedQuickSort(int[], int);
void hybridQuickSort(int[], int);
void heapSort(int[], int);
void print_array(const int[], int);
void read_array(int[], ifstream&, int);

int main(){
    int short_rand[SHORT];
    ifstream short_rand_file(SHORT_RANDOM_FILE);
    cout << "*************** Insertion *****************" << endl;
    read_array(short_rand, short_rand_file, SHORT);
    print_array(short_rand, SHORT);
    insertionSort(short_rand, SHORT);
    print_array(short_rand, SHORT);

    cout << endl << "*************** Merge *****************" << endl;
    short_rand_file.seekg(0);
    read_array(short_rand, short_rand_file, SHORT);
    print_array(short_rand, SHORT);
    mergeSort(short_rand, SHORT);
    print_array(short_rand, SHORT);

    cout << endl << "*************** Quick *****************" << endl;
    short_rand_file.seekg(0);
    read_array(short_rand, short_rand_file, SHORT);
    print_array(short_rand, SHORT);
    quickSort(short_rand, SHORT);
    print_array(short_rand, SHORT);
  return 0;
}

void swap(int a[], int i, int j){
  if (i==j) return;
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
  return;
}

void print_array(const int a[], int s){
    for (int i = 0; i < s; ++i){
        cout << a[i] << " ";
    }
    cout << endl;
}


void read_array(int a[], ifstream& f, int s){
    for (int i = 0; i < s; ++i){
        f >> a[i];
    }
}

void insertionSort(int a[], int size){
  for (int i = 1; i < size; ++i){
        int j = i - 1, compare = a[i];
        while (j >= 0 && a[j] > compare){
          a[j+1] = a[j];
          j -= 1;
        }
        a[j+1] = compare;
  }
  return;
}

void merge(int a[], int l, int m, int r){
  int left_size = m-l;
  int right_size = r-m;
  if(left_size == 0 || right_size == 0){
    cerr << "Size of 0 in merge" << endl;
  }
  int left_array[left_size];
  int right_array[right_size];
  int lp = l;
  for(int i = 0; i<left_size; ++i, ++lp){
    left_array[i] = a[lp];
  }
  int rp = m;
  for(int i = 0; i<right_size; ++i, ++rp){
    right_array[i] = a[rp];
  }
  lp = 0;
  rp = 0;
  int ap = l;
  while(lp<left_size && rp<right_size){
    if(left_array[lp]<right_array[rp]){
      a[ap] = left_array[lp];
      lp++;
    }
    else{
      a[ap] = right_array[rp];
      rp++;
    }
    ap++;
  }
  while(lp<left_size){
    a[ap] = left_array[lp];
    ap++;
    lp++;
  }
  while(rp<right_size){
    a[ap] = right_array[rp];
    ap++;
    rp++;
  }
  return;
}

void ms(int a[], int l, int r){
  if(r-l>1){
    int middle = (l+r)/2;
    ms(a, l, middle);
    ms(a, middle, r);
    merge(a, l, middle, r);
  }
  return;
}

void mergeSort(int a[], int s){
  ms(a, 0, s);
  return;
}

int part(int a[], int low, int hi){
  int pivot = a[hi-1];
  int small = low -1;
  //cout << "partition from " << low << " to " << hi << endl;
  for(int i = low; i < hi; ++i){
    if (a[i] < pivot){
      small += 1;
      swap(a, small, i);
    }
  }
  swap(a, small+1, hi-1);
  return(small+1);
}
void qs(int a[], int low, int hi){
  if(hi-low > 1){
    int p = part(a, low, hi);
    qs(a, low, p);
    qs(a, p+1, hi);
  }
  return;
}
void quickSort(int a[], int s){
  qs(a, 0, s);
  return;
}
