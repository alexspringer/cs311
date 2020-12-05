#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROW 9
#define COLUMN 15



/*Function prototypes*/
void display_transTable(int transTable[ROW][COLUMN]);
int is_valid(int transTable[ROW][COLUMN], char * string);
int read_string(char * file_name, char * string, FILE * fptr,
	int transTable[ROW][COLUMN]);



int main(int argc, char * argv[]){
	int success = 0;
	char * string = NULL;
	FILE * fptr = NULL;
	int transTable[ROW][COLUMN] =
	{
	  {1,1,1,1,1,1,1,1,1,1,2,2,3,8,8},
	  {1,1,1,1,1,1,1,1,1,1,8,8,7,4,4}, /*accept state*/
	  {1,1,1,1,1,1,1,1,1,1,8,8,3,8,8},
	  {7,7,7,7,7,7,7,7,7,7,8,8,8,8,8},
	  {5,5,5,5,5,5,5,5,5,5,6,6,8,8,8},
	  {5,5,5,5,5,5,5,5,5,5,8,8,8,8,8}, /*accept state*/
	  {5,5,5,5,5,5,5,5,5,5,8,8,8,8,8},
	  {7,7,7,7,7,7,7,7,7,7,8,8,8,4,4}, /*accept state*/
	  {8,8,8,8,8,8,8,8,8,8,8,8,8,8,8}  /*dead state*/
	};
	display_transTable(transTable);
	success = read_string(argv[1], string, fptr, transTable);
	if(success){
		printf("All done! \n");
	}


	return 0;
}



/* THIS FUNCTION READS IN STRINGS */
int read_string(char * file_name, char * string, FILE * fptr,
	int transTable[ROW][COLUMN]){
	int success = 0;
	char temp[100];
	fptr = fopen(file_name, "r");
	if(fptr == NULL){
		printf("Cannot open file \n");
		return 0;
	}
	while(fgets(temp, 100, fptr)){
		string = (char*)malloc(sizeof(char*)*strlen(temp)+1);
		strcpy(string, temp);
		printf("String being tested: %s", string);

		success = is_valid(transTable,string);
		printf("success value: %d \n", success);
		if(success == 1 || success == 5 || success == 7){
			printf("String Accepted. \n \n");
		}
		else{
			printf("String Rejected. \n \n");
		}
		free(string);
	}

	fclose(fptr);

	return 1;
}



/* THIS FUCNTION CHECKS IF THE STRING IS VALID */
int is_valid(int transTable[ROW][COLUMN], char * string){
	int row = 0;
	int column = 0;
	int i = 0;

	while(i < strlen(string) - 1){
		switch(string[i]){
			case '0' :
				column = 0;
				row = transTable[row][column];
				break;
			case '1' :
				column = 1;
				row = transTable[row][column];
				break;
			case '2' :
				column = 2;
				row = transTable[row][column];
				break;
			case '3' :
				column = 3;
				row = transTable[row][column];
				break;
			case '4' :
				column = 4;
				row = transTable[row][column];
				break;
			case '5' :
				column = 5;
				row = transTable[row][column];
				break;
			case '6' :
				column = 6;
				row = transTable[row][column];
				break;		
			case '7' :
				column = 7;
				row = transTable[row][column];
				break;
			case '8' :
				column = 8;
				row = transTable[row][column];
				break;
			case '9' :
				column = 9;
				row = transTable[row][column];
				break;
			case '+' :
				column = 10;
				row = transTable[row][column];
				break;		
			case '-' :
				column = 11;
				row = transTable[row][column];
				break;
			case '.' :
				column = 12;
				row = transTable[row][column];
				break;
			case 'e' :
				column = 13;
				row = transTable[row][column];
				break;
			case 'E' :
				column = 14;
				row = transTable[row][column];
				break;
			default:
				row = 8;
		}

	  ++i;
	}

  return row;
}


/* THIS FUNCTION DISPLAYS THE DFA TRANSITION TABLE */
void display_transTable(int transTable[ROW][COLUMN]){
	int x,y;
	printf("DFA transition table: \n");
	for(x = 0; x < ROW; ++x){
		for(y = 0; y < COLUMN; ++y){
			printf("%i",transTable[x][y]);
			if(y == COLUMN - 1)
				printf("\n");
		}
	}
	printf("\n");
	return;
}
