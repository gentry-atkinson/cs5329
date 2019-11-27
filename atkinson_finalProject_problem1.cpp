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
#include<stdio.h>
#include<time.h>

using namespace std;
using namespace std::chrono;

void insertionSort(int[], int);
void mergeSort(int[], int);
void quickSort(int[], int);
void randomizedQuickSort(int[], int);
void hybridQuickSort(int[], int);
void heapSort(int[], int);
void print_array(const int[], int);
void read_array(int[], const char*, int);
bool check_array(int[], int);

int main(){
    int short_array[SHORT];
    int med_array[MEDIUM];
    int long_array[LONG];
    //short_rand_file.seekg(0);

    cout << "Short arrays contain " << SHORT << " values." << endl;
    cout << "Medium arrays contain " << MEDIUM << " values." << endl;
    cout << "Long arrays contain " << LONG << " values." << endl;
    cout << endl;
    cout << "Random array are uniform at random from 0 up to n." << endl;
    cout << "Random no duplicate arrays contain all values from " << endl;
    cout << "0 to n in randomized order." << endl;
    cout << "Nearly sorted arrays contain all values 0 to n " << endl;
    cout << "with a small number of swaps made." << endl;
    cout << endl;

    //Timing Insertion Sort
    cout << "***********************Insertion Sort*********************" << endl;
    cout << "Loading Random Arrays" << endl;
    read_array(short_array, SHORT_RANDOM_FILE, SHORT);
    read_array(med_array, MEDIUM_RANDOM_FILE, MEDIUM);
    read_array(long_array, LONG_RANDOM_FILE, LONG);
    cout << "Sorting Random Arrays" << endl;

    auto start_short = high_resolution_clock::now();
    insertionSort(short_array, SHORT);
    auto stop_short = high_resolution_clock::now();
	  auto duration_short = duration_cast<microseconds>(stop_short - start_short);
    if(check_array(short_array, SHORT)){
      cout << "Good sort on short array." << endl;
    }
    else{
      cout << "Bad sort on short array." << endl;
    }

    auto start_med = high_resolution_clock::now();
    insertionSort(med_array, MEDIUM);
    auto stop_med = high_resolution_clock::now();
	  auto duration_med = duration_cast<microseconds>(stop_med - start_med);
    if(check_array(med_array, MEDIUM)){
      cout << "Good sort on medium array." << endl;
    }
    else{
      cout << "Bad sort on medium array." << endl;
    }

    auto start_long = high_resolution_clock::now();
    insertionSort(long_array, LONG);
    auto stop_long = high_resolution_clock::now();
	  auto duration_long = duration_cast<microseconds>(stop_long - start_long);
    if(check_array(long_array, MEDIUM)){
      cout << "Good sort on long array." << endl;
    }
    else{
      cout << "Bad sort on long array." << endl;
    }
    cout << "Time to sort short: " << duration_short.count() << "ms" << endl;
    cout << "Time to sort medium: " << duration_med.count() << "ms" << endl;
    cout << "Time to sort long: " << duration_long.count() << "ms" << endl;
    cout << "------------------------------------------" << endl;

    cout << "Loading Random No Duplicate Arrays" << endl;
    read_array(short_array, SHORT_RANDOM_NO_DUP_FILE, SHORT);
    read_array(med_array, MEDIUM_RANDOM_NO_DUP_FILE, MEDIUM);
    read_array(long_array, LONG_RANDOM_NO_DUP_FILE, LONG);
    cout << "Sorting Random No Duplicate Arrays" << endl;

    start_short = high_resolution_clock::now();
    insertionSort(short_array, SHORT);
    stop_short = high_resolution_clock::now();
	  duration_short = duration_cast<microseconds>(stop_short - start_short);
    if(check_array(short_array, SHORT)){
      cout << "Good sort on short array." << endl;
    }
    else{
      cout << "Bad sort on short array." << endl;
    }

    start_med = high_resolution_clock::now();
    insertionSort(med_array, MEDIUM);
    stop_med = high_resolution_clock::now();
	  duration_med = duration_cast<microseconds>(stop_med - start_med);
    if(check_array(med_array, MEDIUM)){
      cout << "Good sort on medium array." << endl;
    }
    else{
      cout << "Bad sort on medium array." << endl;
    }

    start_long = high_resolution_clock::now();
    insertionSort(long_array, LONG);
    stop_long = high_resolution_clock::now();
	  duration_long = duration_cast<microseconds>(stop_long - start_long);
    if(check_array(long_array, MEDIUM)){
      cout << "Good sort on long array." << endl;
    }
    else{
      cout << "Bad sort on long array." << endl;
    }
    cout << "Time to sort short: " << duration_short.count() << "ms" << endl;
    cout << "Time to sort medium: " << duration_med.count() << "ms" << endl;
    cout << "Time to sort long: " << duration_long.count() << "ms" << endl;
    cout << "------------------------------------------" << endl;

    cout << "Loading Nearly Sorted Arrays" << endl;
    read_array(short_array, SHORT_NEAR_SORTED_FILE, SHORT);
    read_array(med_array, MEDIUM_NEAR_SORTED_FILE, MEDIUM);
    read_array(long_array, LONG_NEAR_SORTED_FILE, LONG);
    cout << "Sorting Random No Duplicate Arrays" << endl;

    start_short = high_resolution_clock::now();
    insertionSort(short_array, SHORT);
    stop_short = high_resolution_clock::now();
	  duration_short = duration_cast<microseconds>(stop_short - start_short);
    if(check_array(short_array, SHORT)){
      cout << "Good sort on short array." << endl;
    }
    else{
      cout << "Bad sort on short array." << endl;
    }

    start_med = high_resolution_clock::now();
    insertionSort(med_array, MEDIUM);
    stop_med = high_resolution_clock::now();
	  duration_med = duration_cast<microseconds>(stop_med - start_med);
    if(check_array(med_array, MEDIUM)){
      cout << "Good sort on medium array." << endl;
    }
    else{
      cout << "Bad sort on medium array." << endl;
    }

    start_long = high_resolution_clock::now();
    insertionSort(long_array, LONG);
    stop_long = high_resolution_clock::now();
	  duration_long = duration_cast<microseconds>(stop_long - start_long);
    if(check_array(long_array, MEDIUM)){
      cout << "Good sort on long array." << endl;
    }
    else{
      cout << "Bad sort on long array." << endl;
    }
    cout << "Time to sort short: " << duration_short.count() << "ms" << endl;
    cout << "Time to sort medium: " << duration_med.count() << "ms" << endl;
    cout << "Time to sort long: " << duration_long.count() << "ms" << endl;

    //Timing merge sort
    cout << endl << endl << "***********************Merge Sort*********************" << endl;
    cout << "Loading Random Arrays" << endl;
    read_array(short_array, SHORT_RANDOM_FILE, SHORT);
    read_array(med_array, MEDIUM_RANDOM_FILE, MEDIUM);
    read_array(long_array, LONG_RANDOM_FILE, LONG);
    cout << "Sorting Random Arrays" << endl;

    start_short = high_resolution_clock::now();
    mergeSort(short_array, SHORT);
    stop_short = high_resolution_clock::now();
	  duration_short = duration_cast<microseconds>(stop_short - start_short);
    if(check_array(short_array, SHORT)){
      cout << "Good sort on short array." << endl;
    }
    else{
      cout << "Bad sort on short array." << endl;
    }

    start_med = high_resolution_clock::now();
    mergeSort(med_array, MEDIUM);
    stop_med = high_resolution_clock::now();
	  duration_med = duration_cast<microseconds>(stop_med - start_med);
    if(check_array(med_array, MEDIUM)){
      cout << "Good sort on medium array." << endl;
    }
    else{
      cout << "Bad sort on medium array." << endl;
    }

    start_long = high_resolution_clock::now();
    mergeSort(long_array, LONG);
    stop_long = high_resolution_clock::now();
	  duration_long = duration_cast<microseconds>(stop_long - start_long);
    if(check_array(long_array, MEDIUM)){
      cout << "Good sort on long array." << endl;
    }
    else{
      cout << "Bad sort on long array." << endl;
    }
    cout << "Time to sort short: " << duration_short.count() << "ms" << endl;
    cout << "Time to sort medium: " << duration_med.count() << "ms" << endl;
    cout << "Time to sort long: " << duration_long.count() << "ms" << endl;
    cout << "------------------------------------------" << endl;

    cout << "Loading Random No Duplicate Arrays" << endl;
    read_array(short_array, SHORT_RANDOM_NO_DUP_FILE, SHORT);
    read_array(med_array, MEDIUM_RANDOM_NO_DUP_FILE, MEDIUM);
    read_array(long_array, LONG_RANDOM_NO_DUP_FILE, LONG);
    cout << "Sorting Random No Duplicate Arrays" << endl;

    start_short = high_resolution_clock::now();
    mergeSort(short_array, SHORT);
    stop_short = high_resolution_clock::now();
	  duration_short = duration_cast<microseconds>(stop_short - start_short);
    if(check_array(short_array, SHORT)){
      cout << "Good sort on short array." << endl;
    }
    else{
      cout << "Bad sort on short array." << endl;
    }

    start_med = high_resolution_clock::now();
    mergeSort(med_array, MEDIUM);
    stop_med = high_resolution_clock::now();
	  duration_med = duration_cast<microseconds>(stop_med - start_med);
    if(check_array(med_array, MEDIUM)){
      cout << "Good sort on medium array." << endl;
    }
    else{
      cout << "Bad sort on medium array." << endl;
    }

    start_long = high_resolution_clock::now();
    mergeSort(long_array, LONG);
    stop_long = high_resolution_clock::now();
	  duration_long = duration_cast<microseconds>(stop_long - start_long);
    if(check_array(long_array, MEDIUM)){
      cout << "Good sort on long array." << endl;
    }
    else{
      cout << "Bad sort on long array." << endl;
    }
    cout << "Time to sort short: " << duration_short.count() << "ms" << endl;
    cout << "Time to sort medium: " << duration_med.count() << "ms" << endl;
    cout << "Time to sort long: " << duration_long.count() << "ms" << endl;
    cout << "------------------------------------------" << endl;

    cout << "Loading Nearly Sorted Arrays" << endl;
    read_array(short_array, SHORT_NEAR_SORTED_FILE, SHORT);
    read_array(med_array, MEDIUM_NEAR_SORTED_FILE, MEDIUM);
    read_array(long_array, LONG_NEAR_SORTED_FILE, LONG);
    cout << "Sorting Random No Duplicate Arrays" << endl;

    start_short = high_resolution_clock::now();
    mergeSort(short_array, SHORT);
    stop_short = high_resolution_clock::now();
	  duration_short = duration_cast<microseconds>(stop_short - start_short);
    if(check_array(short_array, SHORT)){
      cout << "Good sort on short array." << endl;
    }
    else{
      cout << "Bad sort on short array." << endl;
    }

    start_med = high_resolution_clock::now();
    mergeSort(med_array, MEDIUM);
    stop_med = high_resolution_clock::now();
	  duration_med = duration_cast<microseconds>(stop_med - start_med);
    if(check_array(med_array, MEDIUM)){
      cout << "Good sort on medium array." << endl;
    }
    else{
      cout << "Bad sort on medium array." << endl;
    }

    start_long = high_resolution_clock::now();
    mergeSort(long_array, LONG);
    stop_long = high_resolution_clock::now();
	  duration_long = duration_cast<microseconds>(stop_long - start_long);
    if(check_array(long_array, MEDIUM)){
      cout << "Good sort on long array." << endl;
    }
    else{
      cout << "Bad sort on long array." << endl;
    }
    cout << "Time to sort short: " << duration_short.count() << "ms" << endl;
    cout << "Time to sort medium: " << duration_med.count() << "ms" << endl;
    cout << "Time to sort long: " << duration_long.count() << "ms" << endl;

    //Timing quicksort
    cout << endl << endl << "***********************Quick Sort*********************" << endl;
    cout << "Loading Random Arrays" << endl;
    read_array(short_array, SHORT_RANDOM_FILE, SHORT);
    read_array(med_array, MEDIUM_RANDOM_FILE, MEDIUM);
    read_array(long_array, LONG_RANDOM_FILE, LONG);
    cout << "Sorting Random Arrays" << endl;

    start_short = high_resolution_clock::now();
    quickSort(short_array, SHORT);
    stop_short = high_resolution_clock::now();
	  duration_short = duration_cast<microseconds>(stop_short - start_short);
    if(check_array(short_array, SHORT)){
      cout << "Good sort on short array." << endl;
    }
    else{
      cout << "Bad sort on short array." << endl;
    }

    start_med = high_resolution_clock::now();
    quickSort(med_array, MEDIUM);
    stop_med = high_resolution_clock::now();
	  duration_med = duration_cast<microseconds>(stop_med - start_med);
    if(check_array(med_array, MEDIUM)){
      cout << "Good sort on medium array." << endl;
    }
    else{
      cout << "Bad sort on medium array." << endl;
    }

    start_long = high_resolution_clock::now();
    quickSort(long_array, LONG);
    stop_long = high_resolution_clock::now();
	  duration_long = duration_cast<microseconds>(stop_long - start_long);
    if(check_array(long_array, MEDIUM)){
      cout << "Good sort on long array." << endl;
    }
    else{
      cout << "Bad sort on long array." << endl;
    }
    cout << "Time to sort short: " << duration_short.count() << "ms" << endl;
    cout << "Time to sort medium: " << duration_med.count() << "ms" << endl;
    cout << "Time to sort long: " << duration_long.count() << "ms" << endl;
    cout << "------------------------------------------" << endl;

    cout << "Loading Random No Duplicate Arrays" << endl;
    read_array(short_array, SHORT_RANDOM_NO_DUP_FILE, SHORT);
    read_array(med_array, MEDIUM_RANDOM_NO_DUP_FILE, MEDIUM);
    read_array(long_array, LONG_RANDOM_NO_DUP_FILE, LONG);
    cout << "Sorting Random No Duplicate Arrays" << endl;

    start_short = high_resolution_clock::now();
    quickSort(short_array, SHORT);
    stop_short = high_resolution_clock::now();
	  duration_short = duration_cast<microseconds>(stop_short - start_short);
    if(check_array(short_array, SHORT)){
      cout << "Good sort on short array." << endl;
    }
    else{
      cout << "Bad sort on short array." << endl;
    }

    start_med = high_resolution_clock::now();
    quickSort(med_array, MEDIUM);
    stop_med = high_resolution_clock::now();
	  duration_med = duration_cast<microseconds>(stop_med - start_med);
    if(check_array(med_array, MEDIUM)){
      cout << "Good sort on medium array." << endl;
    }
    else{
      cout << "Bad sort on medium array." << endl;
    }

    start_long = high_resolution_clock::now();
    quickSort(long_array, LONG);
    stop_long = high_resolution_clock::now();
	  duration_long = duration_cast<microseconds>(stop_long - start_long);
    if(check_array(long_array, MEDIUM)){
      cout << "Good sort on long array." << endl;
    }
    else{
      cout << "Bad sort on long array." << endl;
    }
    cout << "Time to sort short: " << duration_short.count() << "ms" << endl;
    cout << "Time to sort medium: " << duration_med.count() << "ms" << endl;
    cout << "Time to sort long: " << duration_long.count() << "ms" << endl;
    cout << "------------------------------------------" << endl;

    cout << "Loading Nearly Sorted Arrays" << endl;
    read_array(short_array, SHORT_NEAR_SORTED_FILE, SHORT);
    read_array(med_array, MEDIUM_NEAR_SORTED_FILE, MEDIUM);
    read_array(long_array, LONG_NEAR_SORTED_FILE, LONG);
    cout << "Sorting Random No Duplicate Arrays" << endl;

    start_short = high_resolution_clock::now();
    quickSort(short_array, SHORT);
    stop_short = high_resolution_clock::now();
	  duration_short = duration_cast<microseconds>(stop_short - start_short);
    if(check_array(short_array, SHORT)){
      cout << "Good sort on short array." << endl;
    }
    else{
      cout << "Bad sort on short array." << endl;
    }

    start_med = high_resolution_clock::now();
    quickSort(med_array, MEDIUM);
    stop_med = high_resolution_clock::now();
	  duration_med = duration_cast<microseconds>(stop_med - start_med);
    if(check_array(med_array, MEDIUM)){
      cout << "Good sort on medium array." << endl;
    }
    else{
      cout << "Bad sort on medium array." << endl;
    }

    start_long = high_resolution_clock::now();
    quickSort(long_array, LONG);
    stop_long = high_resolution_clock::now();
	  duration_long = duration_cast<microseconds>(stop_long - start_long);
    if(check_array(long_array, MEDIUM)){
      cout << "Good sort on long array." << endl;
    }
    else{
      cout << "Bad sort on long array." << endl;
    }
    cout << "Time to sort short: " << duration_short.count() << "ms" << endl;
    cout << "Time to sort medium: " << duration_med.count() << "ms" << endl;
    cout << "Time to sort long: " << duration_long.count() << "ms" << endl;

    //Timing randomized quicksort
    cout << endl << endl << "**************Randomized Quick Sort***************" << endl;
    cout << "Loading Random Arrays" << endl;
    read_array(short_array, SHORT_RANDOM_FILE, SHORT);
    read_array(med_array, MEDIUM_RANDOM_FILE, MEDIUM);
    read_array(long_array, LONG_RANDOM_FILE, LONG);
    cout << "Sorting Random Arrays" << endl;

    start_short = high_resolution_clock::now();
    randomizedQuickSort(short_array, SHORT);
    stop_short = high_resolution_clock::now();
	  duration_short = duration_cast<microseconds>(stop_short - start_short);
    if(check_array(short_array, SHORT)){
      cout << "Good sort on short array." << endl;
    }
    else{
      cout << "Bad sort on short array." << endl;
    }

    start_med = high_resolution_clock::now();
    randomizedQuickSort(med_array, MEDIUM);
    stop_med = high_resolution_clock::now();
	  duration_med = duration_cast<microseconds>(stop_med - start_med);
    if(check_array(med_array, MEDIUM)){
      cout << "Good sort on medium array." << endl;
    }
    else{
      cout << "Bad sort on medium array." << endl;
    }

    start_long = high_resolution_clock::now();
    randomizedQuickSort(long_array, LONG);
    stop_long = high_resolution_clock::now();
	  duration_long = duration_cast<microseconds>(stop_long - start_long);
    if(check_array(long_array, MEDIUM)){
      cout << "Good sort on long array." << endl;
    }
    else{
      cout << "Bad sort on long array." << endl;
    }
    cout << "Time to sort short: " << duration_short.count() << "ms" << endl;
    cout << "Time to sort medium: " << duration_med.count() << "ms" << endl;
    cout << "Time to sort long: " << duration_long.count() << "ms" << endl;
    cout << "------------------------------------------" << endl;

    cout << "Loading Random No Duplicate Arrays" << endl;
    read_array(short_array, SHORT_RANDOM_NO_DUP_FILE, SHORT);
    read_array(med_array, MEDIUM_RANDOM_NO_DUP_FILE, MEDIUM);
    read_array(long_array, LONG_RANDOM_NO_DUP_FILE, LONG);
    cout << "Sorting Random No Duplicate Arrays" << endl;

    start_short = high_resolution_clock::now();
    randomizedQuickSort(short_array, SHORT);
    stop_short = high_resolution_clock::now();
	  duration_short = duration_cast<microseconds>(stop_short - start_short);
    if(check_array(short_array, SHORT)){
      cout << "Good sort on short array." << endl;
    }
    else{
      cout << "Bad sort on short array." << endl;
    }

    start_med = high_resolution_clock::now();
    randomizedQuickSort(med_array, MEDIUM);
    stop_med = high_resolution_clock::now();
	  duration_med = duration_cast<microseconds>(stop_med - start_med);
    if(check_array(med_array, MEDIUM)){
      cout << "Good sort on medium array." << endl;
    }
    else{
      cout << "Bad sort on medium array." << endl;
    }

    start_long = high_resolution_clock::now();
    randomizedQuickSort(long_array, LONG);
    stop_long = high_resolution_clock::now();
	  duration_long = duration_cast<microseconds>(stop_long - start_long);
    if(check_array(long_array, MEDIUM)){
      cout << "Good sort on long array." << endl;
    }
    else{
      cout << "Bad sort on long array." << endl;
    }
    cout << "Time to sort short: " << duration_short.count() << "ms" << endl;
    cout << "Time to sort medium: " << duration_med.count() << "ms" << endl;
    cout << "Time to sort long: " << duration_long.count() << "ms" << endl;
    cout << "------------------------------------------" << endl;

    cout << "Loading Nearly Sorted Arrays" << endl;
    read_array(short_array, SHORT_NEAR_SORTED_FILE, SHORT);
    read_array(med_array, MEDIUM_NEAR_SORTED_FILE, MEDIUM);
    read_array(long_array, LONG_NEAR_SORTED_FILE, LONG);
    cout << "Sorting Random No Duplicate Arrays" << endl;

    start_short = high_resolution_clock::now();
    randomizedQuickSort(short_array, SHORT);
    stop_short = high_resolution_clock::now();
	  duration_short = duration_cast<microseconds>(stop_short - start_short);
    if(check_array(short_array, SHORT)){
      cout << "Good sort on short array." << endl;
    }
    else{
      cout << "Bad sort on short array." << endl;
    }

    start_med = high_resolution_clock::now();
    randomizedQuickSort(med_array, MEDIUM);
    stop_med = high_resolution_clock::now();
	  duration_med = duration_cast<microseconds>(stop_med - start_med);
    if(check_array(med_array, MEDIUM)){
      cout << "Good sort on medium array." << endl;
    }
    else{
      cout << "Bad sort on medium array." << endl;
    }

    start_long = high_resolution_clock::now();
    randomizedQuickSort(long_array, LONG);
    stop_long = high_resolution_clock::now();
	  duration_long = duration_cast<microseconds>(stop_long - start_long);
    if(check_array(long_array, MEDIUM)){
      cout << "Good sort on long array." << endl;
    }
    else{
      cout << "Bad sort on long array." << endl;
    }
    cout << "Time to sort short: " << duration_short.count() << "ms" << endl;
    cout << "Time to sort medium: " << duration_med.count() << "ms" << endl;
    cout << "Time to sort long: " << duration_long.count() << "ms" << endl;

    //Timing hybrid quicksort
    cout << endl << endl << "**************Hybrid Quick Sort***************" << endl;
    cout << "Loading Random Arrays" << endl;
    read_array(short_array, SHORT_RANDOM_FILE, SHORT);
    read_array(med_array, MEDIUM_RANDOM_FILE, MEDIUM);
    read_array(long_array, LONG_RANDOM_FILE, LONG);
    cout << "Sorting Random Arrays" << endl;

    start_short = high_resolution_clock::now();
    hybridQuickSort(short_array, SHORT);
    stop_short = high_resolution_clock::now();
	  duration_short = duration_cast<microseconds>(stop_short - start_short);
    if(check_array(short_array, SHORT)){
      cout << "Good sort on short array." << endl;
    }
    else{
      cout << "Bad sort on short array." << endl;
    }

    start_med = high_resolution_clock::now();
    hybridQuickSort(med_array, MEDIUM);
    stop_med = high_resolution_clock::now();
	  duration_med = duration_cast<microseconds>(stop_med - start_med);
    if(check_array(med_array, MEDIUM)){
      cout << "Good sort on medium array." << endl;
    }
    else{
      cout << "Bad sort on medium array." << endl;
    }

    start_long = high_resolution_clock::now();
    hybridQuickSort(long_array, LONG);
    stop_long = high_resolution_clock::now();
	  duration_long = duration_cast<microseconds>(stop_long - start_long);
    if(check_array(long_array, MEDIUM)){
      cout << "Good sort on long array." << endl;
    }
    else{
      cout << "Bad sort on long array." << endl;
    }
    cout << "Time to sort short: " << duration_short.count() << "ms" << endl;
    cout << "Time to sort medium: " << duration_med.count() << "ms" << endl;
    cout << "Time to sort long: " << duration_long.count() << "ms" << endl;
    cout << "------------------------------------------" << endl;

    cout << "Loading Random No Duplicate Arrays" << endl;
    read_array(short_array, SHORT_RANDOM_NO_DUP_FILE, SHORT);
    read_array(med_array, MEDIUM_RANDOM_NO_DUP_FILE, MEDIUM);
    read_array(long_array, LONG_RANDOM_NO_DUP_FILE, LONG);
    cout << "Sorting Random No Duplicate Arrays" << endl;

    start_short = high_resolution_clock::now();
    hybridQuickSort(short_array, SHORT);
    stop_short = high_resolution_clock::now();
	  duration_short = duration_cast<microseconds>(stop_short - start_short);
    if(check_array(short_array, SHORT)){
      cout << "Good sort on short array." << endl;
    }
    else{
      cout << "Bad sort on short array." << endl;
    }

    start_med = high_resolution_clock::now();
    hybridQuickSort(med_array, MEDIUM);
    stop_med = high_resolution_clock::now();
	  duration_med = duration_cast<microseconds>(stop_med - start_med);
    if(check_array(med_array, MEDIUM)){
      cout << "Good sort on medium array." << endl;
    }
    else{
      cout << "Bad sort on medium array." << endl;
    }

    start_long = high_resolution_clock::now();
    hybridQuickSort(long_array, LONG);
    stop_long = high_resolution_clock::now();
	  duration_long = duration_cast<microseconds>(stop_long - start_long);
    if(check_array(long_array, MEDIUM)){
      cout << "Good sort on long array." << endl;
    }
    else{
      cout << "Bad sort on long array." << endl;
    }
    cout << "Time to sort short: " << duration_short.count() << "ms" << endl;
    cout << "Time to sort medium: " << duration_med.count() << "ms" << endl;
    cout << "Time to sort long: " << duration_long.count() << "ms" << endl;
    cout << "------------------------------------------" << endl;

    cout << "Loading Nearly Sorted Arrays" << endl;
    read_array(short_array, SHORT_NEAR_SORTED_FILE, SHORT);
    read_array(med_array, MEDIUM_NEAR_SORTED_FILE, MEDIUM);
    read_array(long_array, LONG_NEAR_SORTED_FILE, LONG);
    cout << "Sorting Random No Duplicate Arrays" << endl;

    start_short = high_resolution_clock::now();
    hybridQuickSort(short_array, SHORT);
    stop_short = high_resolution_clock::now();
	  duration_short = duration_cast<microseconds>(stop_short - start_short);
    if(check_array(short_array, SHORT)){
      cout << "Good sort on short array." << endl;
    }
    else{
      cout << "Bad sort on short array." << endl;
    }

    start_med = high_resolution_clock::now();
    hybridQuickSort(med_array, MEDIUM);
    stop_med = high_resolution_clock::now();
	  duration_med = duration_cast<microseconds>(stop_med - start_med);
    if(check_array(med_array, MEDIUM)){
      cout << "Good sort on medium array." << endl;
    }
    else{
      cout << "Bad sort on medium array." << endl;
    }

    start_long = high_resolution_clock::now();
    hybridQuickSort(long_array, LONG);
    stop_long = high_resolution_clock::now();
	  duration_long = duration_cast<microseconds>(stop_long - start_long);
    if(check_array(long_array, MEDIUM)){
      cout << "Good sort on long array." << endl;
    }
    else{
      cout << "Bad sort on long array." << endl;
    }
    cout << "Time to sort short: " << duration_short.count() << "ms" << endl;
    cout << "Time to sort medium: " << duration_med.count() << "ms" << endl;
    cout << "Time to sort long: " << duration_long.count() << "ms" << endl;

    //Timing heap quicksort
    cout << endl << endl << "**************Heap Sort***************" << endl;
    cout << "Loading Random Arrays" << endl;
    read_array(short_array, SHORT_RANDOM_FILE, SHORT);
    read_array(med_array, MEDIUM_RANDOM_FILE, MEDIUM);
    read_array(long_array, LONG_RANDOM_FILE, LONG);
    cout << "Sorting Random Arrays" << endl;

    start_short = high_resolution_clock::now();
    heapSort(short_array, SHORT);
    stop_short = high_resolution_clock::now();
	  duration_short = duration_cast<microseconds>(stop_short - start_short);
    if(check_array(short_array, SHORT)){
      cout << "Good sort on short array." << endl;
    }
    else{
      cout << "Bad sort on short array." << endl;
    }

    start_med = high_resolution_clock::now();
    heapSort(med_array, MEDIUM);
    stop_med = high_resolution_clock::now();
	  duration_med = duration_cast<microseconds>(stop_med - start_med);
    if(check_array(med_array, MEDIUM)){
      cout << "Good sort on medium array." << endl;
    }
    else{
      cout << "Bad sort on medium array." << endl;
    }

    start_long = high_resolution_clock::now();
    heapSort(long_array, LONG);
    stop_long = high_resolution_clock::now();
	  duration_long = duration_cast<microseconds>(stop_long - start_long);
    if(check_array(long_array, MEDIUM)){
      cout << "Good sort on long array." << endl;
    }
    else{
      cout << "Bad sort on long array." << endl;
    }
    cout << "Time to sort short: " << duration_short.count() << "ms" << endl;
    cout << "Time to sort medium: " << duration_med.count() << "ms" << endl;
    cout << "Time to sort long: " << duration_long.count() << "ms" << endl;
    cout << "------------------------------------------" << endl;

    cout << "Loading Random No Duplicate Arrays" << endl;
    read_array(short_array, SHORT_RANDOM_NO_DUP_FILE, SHORT);
    read_array(med_array, MEDIUM_RANDOM_NO_DUP_FILE, MEDIUM);
    read_array(long_array, LONG_RANDOM_NO_DUP_FILE, LONG);
    cout << "Sorting Random No Duplicate Arrays" << endl;

    start_short = high_resolution_clock::now();
    heapSort(short_array, SHORT);
    stop_short = high_resolution_clock::now();
	  duration_short = duration_cast<microseconds>(stop_short - start_short);
    if(check_array(short_array, SHORT)){
      cout << "Good sort on short array." << endl;
    }
    else{
      cout << "Bad sort on short array." << endl;
    }

    start_med = high_resolution_clock::now();
    heapSort(med_array, MEDIUM);
    stop_med = high_resolution_clock::now();
	  duration_med = duration_cast<microseconds>(stop_med - start_med);
    if(check_array(med_array, MEDIUM)){
      cout << "Good sort on medium array." << endl;
    }
    else{
      cout << "Bad sort on medium array." << endl;
    }

    start_long = high_resolution_clock::now();
    heapSort(long_array, LONG);
    stop_long = high_resolution_clock::now();
	  duration_long = duration_cast<microseconds>(stop_long - start_long);
    if(check_array(long_array, MEDIUM)){
      cout << "Good sort on long array." << endl;
    }
    else{
      cout << "Bad sort on long array." << endl;
    }
    cout << "Time to sort short: " << duration_short.count() << "ms" << endl;
    cout << "Time to sort medium: " << duration_med.count() << "ms" << endl;
    cout << "Time to sort long: " << duration_long.count() << "ms" << endl;
    cout << "------------------------------------------" << endl;

    cout << "Loading Nearly Sorted Arrays" << endl;
    read_array(short_array, SHORT_NEAR_SORTED_FILE, SHORT);
    read_array(med_array, MEDIUM_NEAR_SORTED_FILE, MEDIUM);
    read_array(long_array, LONG_NEAR_SORTED_FILE, LONG);
    cout << "Sorting Random No Duplicate Arrays" << endl;

    start_short = high_resolution_clock::now();
    heapSort(short_array, SHORT);
    stop_short = high_resolution_clock::now();
	  duration_short = duration_cast<microseconds>(stop_short - start_short);
    if(check_array(short_array, SHORT)){
      cout << "Good sort on short array." << endl;
    }
    else{
      cout << "Bad sort on short array." << endl;
    }

    start_med = high_resolution_clock::now();
    heapSort(med_array, MEDIUM);
    stop_med = high_resolution_clock::now();
	  duration_med = duration_cast<microseconds>(stop_med - start_med);
    if(check_array(med_array, MEDIUM)){
      cout << "Good sort on medium array." << endl;
    }
    else{
      cout << "Bad sort on medium array." << endl;
    }

    start_long = high_resolution_clock::now();
    heapSort(long_array, LONG);
    stop_long = high_resolution_clock::now();
	  duration_long = duration_cast<microseconds>(stop_long - start_long);
    if(check_array(long_array, MEDIUM)){
      cout << "Good sort on long array." << endl;
    }
    else{
      cout << "Bad sort on long array." << endl;
    }
    cout << "Time to sort short: " << duration_short.count() << "ms" << endl;
    cout << "Time to sort medium: " << duration_med.count() << "ms" << endl;
    cout << "Time to sort long: " << duration_long.count() << "ms" << endl;

    return 0;
}
/*************************************************************
A small collection of helper functions
*************************************************************/
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


void read_array(int a[], const char* f, int s){
    ifstream file(f);
    for (int i = 0; i < s; ++i){
        file >> a[i];
    }
    file.close();
}

bool check_array(int a[], int s){
  for(int i = 1; i < s; ++i){
    if (a[i] < a[i-1])
     return false;
  }
  return true;
}

/*************************************************************
Insertion Sort
*************************************************************/
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

/*************************************************************
Merge Sort
*************************************************************/
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

/*************************************************************
Quick Sort
*************************************************************/
int part(int a[], int low, int hi){
  int pivot = a[hi-1];
  int small = low -1;
  for(int i = low; i < hi-1; ++i){
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

/*************************************************************
Quick Sort with Randomization
*************************************************************/
void qs_r(int a[], int low, int hi){
  if(hi-low > 1){
    int array_size = hi-low;
    swap(a, low+rand()%array_size, hi-1);
    int p = part(a, low, hi);
    qs_r(a, low, p);
    qs_r(a, p+1, hi);
  }
  return;
}
void randomizedQuickSort(int a[], int s){
  srand(time(NULL));
  qs_r(a, 0, s);
  return;
}

/*************************************************************
Quick Sort with Hybridization
*************************************************************/

void qs_h(int a[], int low, int hi, int threshold){
  if(hi-low > threshold){
    int array_size = hi-low;
    swap(a, low+rand()%array_size, hi-1);
    int p = part(a, low, hi);
    qs_r(a, low, p);
    qs_r(a, p+1, hi);
  }
  else{
    insertionSort(a+low, hi);
  }
  return;
}
void hybridQuickSort(int a[], int s){
  qs_h(a, 0, s, 10);
  return;
}

/*************************************************************
Heapsort
*************************************************************/
int lchild(int i){
  return 2*i + 1;
}
int rchild(int i){
  return 2*i + 2;
}
int parent(int i){
  return i/2;
}
void heapify(int a[], int s, int root){
  int left = lchild(root);
  int right = rchild(root);
  int largest = root;
  if(left<s && a[left] > a[largest]){
    largest = left;
  }
  if(right<s && a[right] >a[largest]){
    largest = right;
  }
  if(largest != root){
    swap(a, root, largest);
    heapify(a, s, largest);
  }
}
void heapSort(int a[], int s){
  for(int i = parent(s-1); i>=0; --i){
    heapify(a, s, i);
  }
  for(int i = s-1; i>= 0; --i){
    swap(a, 0, i);
    heapify(a, i, 0);
  }
  return;
}
