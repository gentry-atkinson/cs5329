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

void insertionSort(int[], int);
void mergeSort(int[], int);
void quickSort(int[], int);
void randomizedQuickSort(int[], int);
void hybridQuickSort(intp[], int);
void heapSort(int[], int);
