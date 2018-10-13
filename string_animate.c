#include <stdio.h>
#include  <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>

void sleep_ms(long ms){
	struct timespec t;
	t.tv_sec=ms/1000; //number of seconds to sleep (1000m per sec) -> ms/1000=sec
	t.tv_nsec=(ms%1000)*1000000; //remainder value from the calculation of #seconds, *1000000 to convert to MS. 
	nanosleep(&t, NULL);
}

void clear_terminal(){
	//write(STDIN_FILENO, "\033[2J", 4);
	system("clear");
}

void create_string(char* str){
	int length=strlen(str);
	int i,j;
	for(i=0; i<length; i++){
		clear_terminal();

		for(j=0; j<length; j++){
			if(j==i-1 || (i==length-1 && j==length-1)){
				if(i==length-1 && j==length-1){
					str[j]-=j;
				} else {
					str[j]-=j+1;
				}
			} else if(j>=i){
				str[j]+=1;
			}
		}
		printf("%s \n", str);
		sleep_ms(100);
	}
}

int main(int argc, char** argv){
	if(argc!=2){
		printf("Pass a string as the second argument");
		exit(0);
	}
	char str1[20]="Programming";
	//clear_terminal();
	//sleep_ms(3000);
	create_string(argv[1]);
}