#include "lib.h"


float max_side(float* arr, int &number_of_parties)
{
	float temp;
	
	int a, b;
	
	if(number_of_parties==3){
		a=2;
		b=3;
	}
	else{
		a=3;
		b=4;
	}
	
	for(int i=0; i<a; i++){
		for(int j=1; j<b; j++)
		{
			if(arr[j]>arr[i])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	return arr[0];
}

float counting_side_length(float x1, float y1, float x2, float y2)
{
	float side_length;
	side_length=sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));
	return side_length;
}

void scant(char** pp)
{
  if(*pp==NULL) *pp=(char*)calloc(1, sizeof(char));
  else *pp=(char*)realloc(*pp, sizeof(char));
  int i=0;
  
  do
  {
    *(*pp+i)=getch(); //Enter -> 13, 10
    if(*(*pp+i)==13){
    	if(i==0) continue;
		break;
	}
	
    printf("%c", *(*pp+i));
    if(*(*pp+i)==8){ // backspace <-
      printf(" %c", 8);
      i--;
      }
  else{
    i++;
    *pp=(char*)realloc(*pp,(i+1)*sizeof(char));  
    }
  }while(1);
  printf("\n");
  *(*pp+i)=0;  
}

void SetColor(int textColor) 
{ 
	 HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); 
	 SetConsoleTextAttribute(hStdOut, (WORD)(textColor)); 
}
