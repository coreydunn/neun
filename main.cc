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

#define INPUT  0
#define HIDDEN 1
#define OUTPUT 2

int main(void)
{
	std::vector<Input>layers[3];
	std::vector<double>inputs;

	srand(time(NULL));
	inputs=csv_read_floats("values.csv");

	for(size_t i=0;i<inputs.size();++i)
		layers[INPUT].push_back(Input{.value=inputs[i],.weight=frand()});

	layer_randomize(layers[INPUT]);
	layer_print(layers[INPUT]);

	printf("%0.2f\n",layer_output(layers[INPUT]));
	printf("%0.2f\n",normalize(layer_output(layers[INPUT])));
}
