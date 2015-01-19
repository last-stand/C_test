#include <stdio.h>
#include <stdlib.h>
#include "revision.h"

int fibo(int numberOfTerms,int *array){
	int first = 0,second = 1,temp,i;
	if(numberOfTerms < 1){
		return 0;
	}
	array[0] = 0;
	array[1] = 1;
	for(i=2;i<numberOfTerms;i++){
		temp = first+second;
		array[i] = temp;
		first = second;
		second = temp;
	}
	return 1;
}

int concat(int *array1, int len_of_array1, int *array2, int len_of_array2, int *result_array){
	int lengthOfResultArray = len_of_array1 + len_of_array2;
	int i,j=0;
	for(i=0;i<lengthOfResultArray;i++){
		if(i < len_of_array1)
			result_array[i] = array1[i];
		else
		   if(j < len_of_array2){
				result_array[i] = array2[j];
				j++;
			}
	}
	return 1;
}

int filter(int *array, int length, int threshold, int **result_array){
	int i,j=0,temp[length];
	for(i=0;i<length;i++){
		if(array[i] < threshold){
			temp[j] = array[i];
			j++;
		}
	}
	*result_array = (int *)malloc(sizeof(int)*j);
	for(i=0;i<j;i++){
		(*result_array)[i] = temp[i];
	}
	return j;
}

int slice(int *array,int len_of_array,int start_index, int end_index, int **result_array){
	int i,j = 0,length_of_result_arr = end_index - start_index;
	*result_array = (int *)malloc(sizeof(int)*length_of_result_arr); 
	for(i=0;i<len_of_array;i++){
		if(i>= start_index && i<end_index){
			(*result_array)[j] = array[i];
			j++;
		}
	}
	return length_of_result_arr;
}

int check_prime(int number){
	int i,half=number/2;
	int flag = 1;
	for(i=3; i<=half; i+=2){
		if(number%i == 0)
			flag = 0;
	}
	return flag;
}

int reverse_2(int *array, int length, int *result_array){
	int i,j=0;
	result_array = (int*)malloc(sizeof(int)*length); 
	for(i=length-1;i>=0;i--){
		result_array[j] = array[i];
		j++;
	}
	return 1;
}

int prime(int start_range,int end_range,int **result_array){
	int i, count=0,temp[end_range-start_range];
	for(i=start_range;i<=end_range;i++){
		if(i == 2 || i==3 || i==5 || i==7){
			temp[count] = i;
			count ++;
		}
		if(i != 1 && i%2!=0 && i%3!=0 && i%5!=0 && i%7!=0){
			if(check_prime(i) == 1){
				temp[count] = i;
				count++;
			}
		}
	}
	*result_array = (int *)malloc(sizeof(int)*count);
	for(i=0;i<count;i++){
		(*result_array)[i] = temp[i];
	}
	return count;
}

int stringlen(char *str){
	int count=0;
	while(str[count] != 0){
		++count;
	}
	return count;
}

int stringcomp(char *str1, char *str2){
	int i=0;
	int len1=stringlen(str1), len2=stringlen(str2);
	int greater=(len1>len2)?len1:len2;
	do{
		if(str1[i] != str2[i]){
			return str1[i] - str2[i];
		}
		++i;
	}while(i!=greater);
	return 0;
}

int forEach(int *array,int length,void (*function_ptr)(int,int,int *)){
	int i; 
	for(i=0;i<length;i++){
		function_ptr(array[i],i,array);
	}
	return 1;
}

int forEach_float(float *array,int length,void (*function_ptr)(float,int,float *)){
	int i; 
	for(i=0;i<length;i++){
		function_ptr(array[i],i,array);
	}
	return 1;
}

int forEach_string(char **array,int length,void (*function_ptr)(char *,int,char **)){
	int i; 
	for(i=0;i<length;i++){
		function_ptr((array)[i],i,array);
	}
	return 1;
}

int filter_int(int *array, int length, int (*function_ptr)(int,int,int *),int **result_array){
	int i,count=0,temp[length];
	for(i=0;i<length;i++){
		if(function_ptr(array[i],i,array)){
			temp[count] = array[i];
			++count;
		}
	}
	*result_array = (int *)malloc(sizeof(int)*count);
	for(i=0;i<count;i++){
		(*result_array)[i] = temp[i];
	};
	return count;
}

int filter_float(float *array, int length, int (*function_ptr)(float,int,float *),float **result_array){
	int i,count=0;
	float temp[length];
	for(i=0;i<length;i++){
		if(function_ptr(array[i],i,array)){
			temp[count] = array[i];
			++count;
		}
	}
	*result_array = (float *)malloc(sizeof(float)*count);
	for(i=0;i<count;i++){
		(*result_array)[i] = temp[i];
	};
	return count;
}

int filter_char(char *array,int length,int (*function_ptr)(char,int,char *),char **result_array){
	int i,count=0;
	char temp[length];
	for(i=0;i<length;i++){
		if(function_ptr(array[i],i,array)){
			temp[count] = array[i];
			++count;
		}
	}
	*result_array = (char *)malloc(sizeof(char)*count);
	for(i=0;i<count;i++){
		(*result_array)[i] = temp[i];
	};
	return count;
}

int filter_string(char **array,int length,int (*function_ptr)(char *,int,char **),char ***result_array){
	int i,count=0,temp[length];
	for(i=0 ; i<length;i++){
		if(function_ptr(array[i],i,array)){
			temp[count] = i;
			count++; 
		}
	}
	*result_array = (char **)malloc(sizeof(char*)*count);
	for(i=0;i<count;i++){
		(*result_array)[i] = array[temp[i]];
	};
	return count;
}

int * map_int(int *array,int length,int (*function_ptr)(int,int,int*)){
	int i,*result_array;
	result_array = (int *)malloc(sizeof(int)*length);
	for(i=0;i<length;i++){
		result_array[i] = function_ptr(array[i],i,array);
	}
	return result_array;
};

float * map_float(float *array,int length,float (*function_ptr)(float,int,float*)){
	int i;
	float *result_array;
	result_array = (float *)malloc(sizeof(float)*length);
	for(i=0;i<length;i++){
		result_array[i] = function_ptr(array[i],i,array);
	}
	return result_array;
}

char * map_char(char *array,int length,char (*function_ptr)(char,int,char *)){
	int i;
	char *result_array;
	result_array = (char *)malloc(sizeof(char)*length);
	for(i=0;i<length;i++){
		result_array[i] = function_ptr(array[i],i,array);
	}
	return result_array;
};

char ** map_string(char **array,int length,char *(*function_ptr)(char *,int,char **)){
	int i;
	char **result_array;
	result_array = (char **)malloc(sizeof(char*)*length);
	for(i=0;i<length;i++){
		(result_array)[i] = function_ptr(array[i],i,array);
	}
	return result_array;
}

int reduce_int(int *array,int length,int (*function_ptr)(int ,int ,int ,int *),int initial_value){
	int i;
	int previousValue = initial_value, currentValue;
	for(i=0;i<length;i++){
		currentValue = array[i];
		previousValue = function_ptr(previousValue,currentValue,i,array);
	}
	return previousValue;
}

float reduce_float(float *array,int length,float (*function_ptr)(float ,float ,int ,float *),float initial_value){
	int i;
	float previousValue = initial_value, currentValue;
	for(i=0;i<length;i++){
		currentValue = array[i];
		previousValue = function_ptr(previousValue,currentValue,i,array);
	}
	return previousValue;
}

char reduce_char(char *array,int length,char (*function_ptr)(char ,char ,int ,char *),char initial_value){
	int i;
	char previousValue = initial_value, currentValue;
	for(i=0;i<length;i++){
		currentValue = array[i];
		previousValue = function_ptr(previousValue,currentValue,i,array);
	}
	return previousValue;
}

