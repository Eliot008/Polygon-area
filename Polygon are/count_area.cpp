#include "lib.h"

float area_calculation(float** arr_coordinates, int &number_of_parties)
{
	float S_area, sum_l_r=0, sum_r_l=0;
	
	for(int i = 0; i<number_of_parties; i++){
		if(i==number_of_parties-1) sum_l_r+=arr_coordinates[i][0]*arr_coordinates[0][1];
		else sum_l_r+=arr_coordinates[i][0]*arr_coordinates[i+1][1];
	}
	
	for(int i = 0; i<number_of_parties; i++){
		if(i==number_of_parties-1) sum_r_l+=arr_coordinates[i][1]*arr_coordinates[0][0];
		else sum_r_l+=arr_coordinates[i][1]*arr_coordinates[i+1][0];
	}
	
	S_area=(abs(sum_l_r-sum_r_l))/2;
	return S_area;	
}
