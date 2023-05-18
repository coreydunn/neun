#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<math.h>
#include<time.h>

#include<vector>
#include<iostream>

#include"nn.hh"

double normalize(double value)
{
	return 1.0/(1.0+pow(M_E,-value));
}

double layer_sum(std::vector<Input>layer)
{
	double value=0.0f;

	for(Input n:layer)
		value+=normalize(n.value*n.weight);

	return value;
}

void layer_print(std::vector<Input>layer)
{
	printf("[");
	for(size_t i=0;i<layer.size();++i)
	{
		printf("(v:%0.2f,w:%0.2f)",layer[i].value,layer[i].weight);
		if(i<layer.size()-1)
			printf(", ");
	}
	printf("]\n");
}

void layer_randomize(std::vector<Input>&layer)
{
	for(size_t i=0;i<layer.size();++i)
		layer[i].weight=frand();
}
