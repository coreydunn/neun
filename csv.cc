#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#include"csv.hh"

std::vector<double>csv_read_floats(const char*fname)
{
	FILE*file;
	std::vector<double>v;
	char buffer[65536]={0};
	size_t n=0;
	char float_buffer[1024]={0};
	char*ptr=float_buffer;

	file=fopen(fname,"r");
	if(!file)return v;

	n=fread(buffer,1,65536,file);
	for(size_t i=0;i<n;++i)
	{

		if(buffer[i]!=','&&buffer[i]!='\n'&&i<n-1)
			*(ptr++)=buffer[i];
		else
		{
			v.push_back(strtof(float_buffer,NULL));
			ptr=float_buffer;
			memset(float_buffer,0,1024);
		}
	}

	fclose(file);

	return v;
}
