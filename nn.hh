#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<math.h>
#include<time.h>

#include<vector>
#include<iostream>

#define frand() (2.0*((double)rand()/(double)RAND_MAX)-1.0)
#define layer_output(l) (layer_sum(l))

typedef struct Input
{
	double value;
	double weight;
} Input;

double layer_sum(std::vector<Input>layer);
double normalize(double value);
void layer_print(std::vector<Input>layer);
void layer_randomize(std::vector<Input>&layer);
