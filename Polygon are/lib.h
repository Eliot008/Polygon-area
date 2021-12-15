#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>

#define pi 3.1415926

void scant(char** pp);
int check_int_numbers_positive317(char* &check_arr);
void check_numbers(char* &check_arr, int &number_flag_check_numbers, float &number_check_numbers);
float counting_side_length(float x1, float y1, float x2, float y2);
bool checkis_convex_polygon_side(float** &arr_coordinates, int &number_of_parties, float* arr_side_length);
float max_side(float* arr,int &number_of_parties);
bool checkis_convex_polygon_point(float** arr_coordinates, int &number_of_parties);
float area_calculation(float** arr_coordinates, int &number_of_parties);
bool checkis_angle(float** arr_coordinates, int &number_of_parties);
void SetColor(int textColor);
