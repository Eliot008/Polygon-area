#include "lib.h"



int main()
{
	int number_of_parties=0, Check_convex_side, Check_convex_point;
	char *checking_numbers_from_the_array=NULL;
	
	int number_flag_check_numbers=0;
	float number_check_numbers=0, S_area=0;
	
	char Exit;
	
	
	while(1)
	{
		SetColor(13);
		printf(" ------------------------------------------\n| Enter the number of sides of the polygon | : ");
		scant(&checking_numbers_from_the_array);
		number_of_parties=check_int_numbers_positive317(checking_numbers_from_the_array);
		while(1)
		{
			if(number_of_parties==0){
				SetColor(13);
				printf(" ------------------------------------------\n| Enter the number of sides of the polygon | : ");
				scant(&checking_numbers_from_the_array);
				number_of_parties=check_int_numbers_positive317(checking_numbers_from_the_array);
			}
			else break;
		}
		*checking_numbers_from_the_array=NULL;
		
		float **Coordinates_arr = (float **)malloc(number_of_parties*sizeof(float *));
		for(int i = 0; i < number_of_parties; i++) {
			Coordinates_arr[i] = (float *)malloc(2*sizeof(float));
		}
		
		for(int i=0; i<number_of_parties; i++)
		{
			for(int j=0; j<2; j++)
			{
				while(1)
				{
					SetColor(3);
					number_check_numbers=0;
					if(j==0) printf("x%i=", i+1);
			        else if (j==1) printf("y%i=", i+1);
					scant(&checking_numbers_from_the_array);
				    check_numbers(checking_numbers_from_the_array, number_flag_check_numbers, number_check_numbers);
				    if(number_flag_check_numbers==1) Coordinates_arr[i][j]=number_check_numbers;
					
					*checking_numbers_from_the_array=NULL;
					if(number_flag_check_numbers==1) break;
				}
			}
		}
		
		float *arr_side_length = (float *)malloc(number_of_parties*sizeof(float));
		
		Check_convex_side = checkis_convex_polygon_side(Coordinates_arr, number_of_parties, arr_side_length);
		Check_convex_point = checkis_convex_polygon_point(Coordinates_arr, number_of_parties);
		int Check_angle = checkis_angle(Coordinates_arr, number_of_parties);
		
		S_area=area_calculation(Coordinates_arr, number_of_parties);
		SetColor(10);
		if(Check_convex_side==1 && S_area>0 && Check_convex_point==1 && Check_angle==1){
			for(int i=0; i<number_of_parties; i++){
				printf("Side length |%i| : %g\n",i+1, arr_side_length[i]);
			}
			printf("---------\n| Area: %g |\n ---------", S_area);	
		}
		else if(Check_convex_side==0 || Check_convex_point==0 || S_area==0 || Check_angle==0) printf("This polygon is not convex! It is impossible to determine the area!");	
		
		SetColor(11);
		printf("\nExit - push Esc; otherwise, press any key\n\n");
		Exit=getch();
		
		if(Exit==27) exit(0);
		else continue;
		
		
		for(int i = 0; i < number_of_parties; i++) {
			free(Coordinates_arr[i]);
		}
		free(Coordinates_arr);	
	}
	
}
