#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#include"csv.hh"
#define CSV_MODE_NORMAL  0x0
#define CSV_MODE_COMMENT 0x1

std::vector<double>csv_read_floats(const char*fname)
{
	FILE*file;
	int mode=CSV_MODE_NORMAL;
	char buffer[65536]={0};
	char float_buffer[1024]={0};
	char*ptr=float_buffer;
	size_t n=0;
	std::vector<double>v;

	file=fopen(fname,"r");
	if(!file)return v;

	n=fread(buffer,1,65536,file);
	for(size_t i=0;i<n;++i)
	{

		switch(mode)
		{

			case CSV_MODE_COMMENT:
				if(buffer[i]=='\n')
					mode=CSV_MODE_NORMAL;
				break;

			case CSV_MODE_NORMAL:
				if(buffer[i]=='#')
					mode=CSV_MODE_COMMENT;
				else if(buffer[i]!=','&&buffer[i]!='\n'&&i<n-1)
					*(ptr++)=buffer[i];
				else
				{
					v.push_back(strtof(float_buffer,NULL));
					ptr=float_buffer;
					memset(float_buffer,0,1024);
				}
				break;

		}

		// if(mode==CSV_MODE_COMMENT)
		// 	if(buffer[i]=='\n')
		// 		mode=CSV_MODE_NORMAL;
		// else if(mode!=CSV_MODE_COMMENT&&buffer[i]=='#')
		// 	mode=CSV_MODE_COMMENT;
		// else if(buffer[i]!=','&&buffer[i]!='\n'&&i<n-1)
		// 	*(ptr++)=buffer[i];
		// else
		// {
		// 	v.push_back(strtof(float_buffer,NULL));
		// 	ptr=float_buffer;
		// 	memset(float_buffer,0,1024);
		// }

	}

	fclose(file);

	return v;
}
