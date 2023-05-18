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
#include"csv.hh"

typedef struct Node
{
	std::vector<Input>inputs;
	double output;
} Node;

int main(void)
{
	std::vector<Input>layers[3];
	Node node;

	srand(time(NULL));
	for(auto val:csv_read_floats("values.csv"))
		node.inputs.push_back(Input{.value=val,.weight=frand()});

	layer_print(node.inputs);

	printf("output: %0.2f\n",layer_output(node.inputs));
	printf("norm(output): %0.2f\n",normalize(layer_output(node.inputs)));
}
