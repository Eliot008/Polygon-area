#include "lib.h"

void check_numbers(char* &check_arr, int &number_flag_check_numbers, float &number_check_numbers)
{
	int point_check_symbol=0, check_symbol=0, minus_check_symbol=0, index_minus=0;
	
	for(int i=0; i<(strlen(check_arr)); i++){
		if(check_arr[i]>=32 && check_arr[i]<45 || check_arr[i]==47 || check_arr[i]>=58 && check_arr[i]<=127) check_symbol++;
		
		else if(check_arr[i]==45){
			minus_check_symbol++;
			index_minus=i;
		}
		else if(check_arr[i]==46) point_check_symbol++;
		
		if(minus_check_symbol>0 && check_arr[1]==0) number_flag_check_numbers=0;
		
	}
	
	if(minus_check_symbol==0 && check_symbol==0 && point_check_symbol<2) number_flag_check_numbers=1;
	else if(minus_check_symbol==1 && index_minus==0 && (check_arr[1]>=48 && check_arr[1]<=57) && check_symbol==0 && point_check_symbol<2) number_flag_check_numbers=1;
	else if(check_symbol>0 || point_check_symbol>1 || minus_check_symbol>1) number_flag_check_numbers=0;
	
	minus_check_symbol=0;
	point_check_symbol=0;
	check_symbol=0;	
	
	if(number_flag_check_numbers==1 ) sscanf(check_arr, "%f", &number_check_numbers);
	
}



int check_int_numbers_positive317(char* &check_arr)
{
	int number_from_array=0, check_symbol=0;

			    
    for(int i=0; i<(strlen(check_arr)); i++){
    	if(check_arr[i]>=32 && check_arr[i]<=46 || check_arr[i]==47 || check_arr[i]>=58 && check_arr[i]<=127){
    		check_symbol++;
		}	
	}
	if(check_symbol>0) number_from_array=0;
	else sscanf(check_arr, "%d", &number_from_array);
	
	if(number_from_array<=2 || number_from_array>=18) number_from_array=0;
	check_symbol=0;
	return number_from_array;
}
