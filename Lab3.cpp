#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>


int main (int argc, char *argv[]){

	bool use_h = false;
	bool use_v = false;
	bool use_s = false;
	bool use_S = false;

	const char* short_options = "hvs::S::";

	const struct option long_options[] = {
		{"help",no_argument,NULL,'h'},
		{"version",no_argument,NULL,'v'},
		{"set",optional_argument,NULL,'s'},
		{"string",optional_argument,NULL,'S'}
	};

	int result;
	int option_index = -1;

	while ((result=getopt_long(argc,argv,short_options,
		long_options,&option_index))!=-1){

		switch(result){
			case 'h': {
				if (!use_h)
					printf("Argument: Help\n");
				use_h = true;
				break;
			};
			case 's': {
				if (!use_s)
					if (option_index > 0)
						if (optarg != NULL)
							printf("Argument: Set, Elements of set: %s\n", optarg);
						else
						printf("Argument of set: List\n");
					else
						printf("Argument of set: List\n");
				use_s = true;
				break;
			};
			case 'v': {
				if (!use_v)
					printf("Argument: Version\n");
				use_v = true;
				break;
			};
			case 'S': {
				if (!use_S)
					if (optarg != NULL)
						printf("Argument String, Value of string: %s\n", optarg);
					else
						printf("Argument String: \n");
				use_S = true;
				break;
			};
		};
		option_index = -1;
	};
	return 0;
};