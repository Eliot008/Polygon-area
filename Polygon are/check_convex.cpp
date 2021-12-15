#include "lib.h"


bool checkis_angle(float** arr_coordinates, int &number_of_parties)
{
	float bpx, bpy, epx, epy, bp_ep, abs_bpep, angle, sum_angle=0, n_angle;
	for(int i=0; i<number_of_parties; i++)
	{
		if(i==number_of_parties-1){
			bpx=arr_coordinates[i-1][0]-arr_coordinates[i][0];
			bpy=arr_coordinates[i-1][1]-arr_coordinates[i][1];
			epx=arr_coordinates[0][0]-arr_coordinates[i][0];
			epy=arr_coordinates[0][1]-arr_coordinates[i][1];
		}
		else if(i==0)
		{
			bpx=arr_coordinates[number_of_parties-1][0]-arr_coordinates[i][0];
			bpy=arr_coordinates[number_of_parties-1][1]-arr_coordinates[i][1];
			epx=arr_coordinates[i+1][0]-arr_coordinates[i][0];
			epy=arr_coordinates[i+1][1]-arr_coordinates[i][1];
		}
		else{
			bpx=arr_coordinates[i-1][0]-arr_coordinates[i][0];
			bpy=arr_coordinates[i-1][1]-arr_coordinates[i][1];
			epx=arr_coordinates[i+1][0]-arr_coordinates[i][0];
			epy=arr_coordinates[i+1][1]-arr_coordinates[i][1];
		}
		
		
		bp_ep=bpx*epx+bpy*epy;		
		abs_bpep=(sqrt(pow(bpx, 2) + pow(bpy, 2))) * (sqrt(pow(epx, 2) + pow(epy, 2)));
		angle=acos((bp_ep)/(abs_bpep))*180/pi;
		sum_angle+=angle;
	}
	n_angle=180*(number_of_parties-2);
	if(sum_angle!=n_angle) return 0;
	else return 1;
}

bool checkis_convex_polygon_point(float** arr_coordinates, int &number_of_parties)
{
	int flag_checkpoint=0;
	for(int i=0; i<number_of_parties-1; i++){
		if(arr_coordinates[i][0]==arr_coordinates[i+1][0] && arr_coordinates[i][1]==arr_coordinates[i+1][1]) flag_checkpoint++;		
	}
	
	if(flag_checkpoint>0) return 0;
	else return 1;
	
}


bool checkis_convex_polygon_side(float** &arr_coordinates, int &number_of_parties, float* arr_side_length)
{
	if(number_of_parties-3==0)
	{
		float sum=0;
		float *value_parties = (float*)malloc(3*sizeof(float));
		for(int i=0; i<3; i++)
		{
			if (i==2) value_parties[i]=counting_side_length(arr_coordinates[2][0], arr_coordinates[2][1], arr_coordinates[0][0], arr_coordinates[0][1]);
			else value_parties[i]=counting_side_length(arr_coordinates[i][0], arr_coordinates[i][1], arr_coordinates[i+1][0], arr_coordinates[i+1][1]);	
		}
		for(int i=0; i<3; i++) arr_side_length[i]=value_parties[i];
		
		float num_max_side = max_side(value_parties, number_of_parties);
		for(int i=0; i<3; i++) sum+=value_parties[i];
		if(num_max_side>sum-num_max_side) return 0;
		else return 1;
	}
	
	else if(number_of_parties-3>0)
	{
		float num_max_side, sum = 0;
		int flag_convex, n=0;
		int count = number_of_parties-3;
		float *value_parties = (float*)malloc(4*sizeof(float));
		for(int j=0; j<number_of_parties-3; j++)
		{
			for(int i=j; i<j+4; i++)
			{
				if (i==j+3) value_parties[n]=counting_side_length(arr_coordinates[i][0], arr_coordinates[i][1], arr_coordinates[j][0], arr_coordinates[j][1]);
				else value_parties[n]=counting_side_length(arr_coordinates[i][0], arr_coordinates[i][1], arr_coordinates[i+1][0], arr_coordinates[i+1][1]);	
				n++;
			}
				
			for(int i=0; i<number_of_parties; i++) arr_side_length[i]=value_parties[i];
				
			num_max_side = max_side(value_parties, number_of_parties);
			
			
		    for(int i=0; i<4; i++) sum+=value_parties[i];
		    if(num_max_side>(sum-num_max_side)){
		    	flag_convex=1;
		    	break;
			}
			else flag_convex=0;
			sum=0;
		}
			
		if(flag_convex==1) return 0;
		else return 1;
		
	}

}
