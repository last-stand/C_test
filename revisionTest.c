#include "expr_assert.h"
#include "revision.c"
#include "revision.h"
#include<stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


void test_fibo_should_return_1_if_number_of_terms_is_greater_than_0(){
	int *array = (int*)malloc(sizeof(int)*6);
	assertEqual(fibo(6,array),1);
	assertEqual(fibo(0,array),0);
	assertEqual(fibo(-5,array),0);
}

void test_fibo_should_store_elements_on_the_address_of_array_pointer(){
	int *array = (int*)malloc(sizeof(int)*6);
	fibo(6,array);
	assertEqual(array[0],0);
	assertEqual(array[1],1);
	assertEqual(array[2],1);
	assertEqual(array[3],2);
	assertEqual(array[4],3);
	assertEqual(array[5],5);
}

void test_values_of_concatinated_arrays_should_be_same_as_the_combination_of_both_arrays(){
	int array1[3] = {1,2,3};
	int array2[4] = {4,5,6,7};
	int *result_array = (int*)malloc(sizeof(int)*7);
	concat(array1, 3, array2, 4, result_array);
	assertEqual(array1[0], result_array[0]);
	assertEqual(array1[1], result_array[1]);
	assertEqual(array1[2], result_array[2]);

	assertEqual(array2[0], result_array[3]);
	assertEqual(array2[1], result_array[4]);
	assertEqual(array2[2], result_array[5]);
	assertEqual(array2[3], result_array[6]);
}

void test_filter_filters_array_of_integers_lesser_than_threshold(){
	int array[6] = {10,15,35,24,11,89};
	int *result_array;
	filter(array, 6, 20, &result_array);
	assertEqual(10,result_array[0]);
	assertEqual(15,result_array[1]);
	assertEqual(11,result_array[2]);
}

void test_slice_slices_array_of_integers_in_the_given_range(){
	int array[8] = {1,2,3,4,5,6,7,8};
	int *result_array;
	slice(array,8,2,6,&result_array);
	assertEqual(3,result_array[0]);
	assertEqual(4,result_array[1]);
	assertEqual(5,result_array[2]);
	assertEqual(6,result_array[3]);
}

void test_reverse_2_returns_new_array_with_reverse_order_of_elements_of_given_array(){
	int array[5] = {8,3,2,5,7};
	int *result_array;
}

void test_check_prime_returns_1_if_number_is_prime(){
	assertEqual(check_prime(2),1);
	assertEqual(check_prime(5),1);
	assertEqual(check_prime(29),1);
}

void test_check_prime_returns_o_if_number_is_not_prime(){
	assertEqual(check_prime(15),0);
	assertEqual(check_prime(50),0);
}


void test_prime_should_count_the_number_of_prime_numbers_in_given_range(){
	int *result_array;
	int noOfPrime = prime(1,10,&result_array);
	assertEqual(noOfPrime,4);
}

void test_prime_should_store_prime_numbers_in_given_range(){
	int *result_array;
	int noOfPrime = prime(10,30,&result_array);
	assertEqual(noOfPrime,6);
	assertEqual(11,result_array[0]);
	assertEqual(13,result_array[1]);
	assertEqual(17,result_array[2]);
	assertEqual(19,result_array[3]);
	assertEqual(23,result_array[4]);
	assertEqual(29,result_array[5]);
}

void test_stringlen_returns_length_of_given_string(){
	char *str1 = "Hello";
	char *str2 = "James Bond 007";
	assertEqual(5,stringlen(str1));
	assertEqual(14,stringlen(str2));
}

void test_stringcomp_returns_1_if_both_given_strings_are_same(){
	char *str1 = "Hello";
	char *str2 = "Hello";
	assertEqual(stringcomp(str1, str2),0);
}

void test_stringcomp_returns_first_minus_second_ASCII_value_if_both_given_strings_are_not_same(){
	char *str1 = "Helloo";
	char *str2 = "HelloO";
	char *str3 = "James Bond";
	char *str4 = "James ";
	assertEqual(stringcomp(str1, str2),strcmp(str1,str2));
	assertEqual(stringcomp(str3, str4),strcmp(str3,str4));
}

void square(int element,int index,int *array){
		array[index] = element*element;
}

void test_forEach_should_do_square_of_all_elements_of_integer_array(){
	int array[5] = {4,5,6,7,8};
	void (*ptr)(int,int,int *);
	ptr = &square;
	forEach(array,5,ptr);
	assertEqual(16,array[0]);
	assertEqual(25,array[1]);
	assertEqual(36,array[2]);
	assertEqual(49,array[3]);
	assertEqual(64,array[4]);
}

void ceil_function(float element,int index,float *array){
	array[index] = ceil(element);
}

void test_forEach_float_should_do_ceil_of_all_elements_of_float_array(){
	float array[5] = {4.27,5.88,6.99,7.01,8.33};
	void (*ptr)(float,int,float *);
	ptr = &ceil_function;
	forEach_float(array,5,ptr);
	assertEqual(ceil(4.27),array[0]);
	assertEqual(ceil(5.88),array[1]);
	assertEqual(ceil(6.99),array[2]);
	assertEqual(ceil(7.01),array[3]);
	assertEqual(ceil(8.33),array[4]);
}

void my_toUpper(char *str,int index,char **array){
	int i=0;
	while(str[i] != 0){
		str[i] = (char)toupper((int)str[i]);
		i++;
	}
}

void test_forEach_string_should_change_all_letters_in_uppercase_of_array_string(){
	char str1[] = "hello", str2[]="James Bond", str3[]="i love my india.";
	char *array[3] = {str1,str2,str3};
	void(*ptr)(char *,int,char **);
	ptr = &my_toUpper;
	forEach_string(array,3,ptr);
	assertEqual(strcmp(str1,"HELLO"),0);
	assertEqual(strcmp(str2,"JAMES BOND"),0);
	assertEqual(strcmp(str3,"I LOVE MY INDIA."),0);
}

int even(int element,int index, int *array){
	return element%2 == 0;
}

void test_filter_int_should_filter_all_even_numbers(){
	int array[6] = {1,3,2,8,7,44};
	int *result_array;
	int (*ptr)(int,int,int *);
	ptr = &even;
	assertEqual(filter_int(array,6,ptr,&result_array),3);
	assertEqual(2,result_array[0]);
	assertEqual(8,result_array[1]);
	assertEqual(44,result_array[2]);
}

int greater_than_10(float element,int index,float *array){
	return element > 10;
}

void test_filter_float_should_filter_all_numbers_greater_than_10(){
	float array[6] = {3.012,11.97,10.1,67.23,88.21,9.9999};
	float *result_array;
	int (*ptr)(float,int,float *);
	ptr = &greater_than_10;
	assertEqual(filter_float(array,6,ptr,&result_array),4);
	assertEqual(result_array[0],array[1]);
	assertEqual(result_array[1],array[2]);
	assertEqual(result_array[2],array[3]);
	assertEqual(result_array[3],array[4]);
}


int alphabets(char element,int index,char *array){
	return ((element >= 'A' && element <= 'Z') || (element >= 'a' && element <= 'z'));
};

void test_filter_char_should_filter_all_albhabets_from_char_array(){
	char array[6] = {'@','a','*','Z','j','^'};
	char *result_array;
	int (*ptr)(char,int,char *);
	ptr = &alphabets;
	assertEqual(filter_char(array,6,ptr,&result_array),3);
	assertEqual(result_array[0],array[1]);
	assertEqual(result_array[1],array[3]);
	assertEqual(result_array[2],array[4]);
}

int start_with_j(char *str,int index,char **array){
	return (str[0] == 'J') || (str[0] == 'j');
}

void test_filter_string_should_filter_strings_start_with_j(){
	char str1[] = "hello", str2[]="James Bond", str3[]="jungle-jungle baat chali hai",str4[]="Big-Bang";
	char *array[4] = {str1,str2,str3,str4};
	char **result_array;
	int(*ptr)(char *,int,char **);
	ptr = &start_with_j;
	assertEqual(filter_string(array,4,ptr,&result_array),2);
	assertEqual(strcmp(result_array[0],array[1]),0);
	assertEqual(strcmp(result_array[1],array[2]),0);
}

int my_sqrt(int element,int index,int *array){
	return sqrt(element);
}

void test_map_int_should_return_square_of_all_elements_of_int_array(){
	int array[6] = {1,4,9,16,25,36};
	int *result_array;
	int(*ptr)(int,int,int*);
	ptr=&my_sqrt;
	result_array = map_int(array,6,ptr);
	assertEqual(1,result_array[0]);
	assertEqual(2,result_array[1]);
	assertEqual(3,result_array[2]);
	assertEqual(4,result_array[3]);
	assertEqual(5,result_array[4]);
	assertEqual(6,result_array[5]);
}

float my_floor(float element,int length,float *array){
	return floor(element);
}
void test_map_float_should_return_floor_value_of_each_element_of_given_array(){
	float array[5] = {0.000001,11.32456,12.9999,10.0009,88.1152};
	float *result_array;
	float(*ptr)(float,int,float*);
	ptr=&my_floor;
	result_array = map_float(array,5,ptr);
	assertEqual(floor(array[0]),result_array[0]);
	assertEqual(floor(array[1]),result_array[1]);
	assertEqual(floor(array[2]),result_array[2]);
	assertEqual(floor(array[3]),result_array[3]);
	assertEqual(floor(array[4]),result_array[4]);
}

char my_lower(char element,int length,char *array){
	return (char)tolower((int)element);
}

void test_map_char_should_return_lowercase_of_each_char_of_given_array(){
	char array[7] = {'J','a','i','H','i','n','d'};
	char *result_array;
	char(*ptr)(char,int,char*);
	ptr=&my_lower;
	result_array = map_char(array,7,ptr);
	assertEqual('j',result_array[0]);
	assertEqual('a',result_array[1]);
	assertEqual('i',result_array[2]);
	assertEqual('h',result_array[3]);
	assertEqual('i',result_array[4]);
	assertEqual('n',result_array[5]);
	assertEqual('d',result_array[6]);
}

char* my_stringToUpper(char *str,int index,char **array){
	int i=0;
	char *string = (char *)malloc(sizeof(char)*strlen(str)+1);
	while(i != strlen(str)){
		string[i] = (char)toupper((int)str[i]);
		i++;
	}
	return string;
}

void test_map_string_should_return_all_strings_in_uppercase_of_given_array(){
	char str1[]="hello",str2[]="James Bond",str3[]="step";
	char *array[3] = {str1,str2,str3};
	char **result_array;
	char *(*ptr)(char *,int,char **);
	ptr = &my_stringToUpper;
	result_array = map_string(array,3,ptr);
	assertEqual(strcmp("HELLO",result_array[0]),0);
	assertEqual(strcmp(result_array[1],"JAMES BOND"),0);
	assertEqual(strcmp(result_array[2],"STEP"),0);
}

int int_arr_sum(int previousValue,int currentValue,int index,int *array){
	return previousValue + currentValue;
}

void test_reduce_int_should_return_sum_of_all_elements_including_initial_value(){
	int array[5] = {1,2,3,4,5};
	int (*ptr)(int,int,int,int*);
	ptr = &int_arr_sum;
	assertEqual(reduce_int(array,5,ptr,10),25);
}

float float_arr_sum(float previousValue,float currentValue,int index,float *array){
	return previousValue + currentValue;
}

void test_reduce_float_should_return_sum_of_all_elemnts_including_initial_value(){
	float array[5] = {0.000314,2.3412,9.076,99.999,5.8970};
	float (*ptr)(float,float,int,float*);
	ptr = &float_arr_sum;
	assertEqual(reduce_float(array,5,ptr,100.85671),(float)218.170227);
}

char greatest_char(char previousValue,char currentValue,int index,char *array){
	return (previousValue > currentValue) ? previousValue : currentValue;
}

void test_reduce_char_should_return_number_of_spaces_in_the_given_string(){
	char array[] = "Mujhe peene ka shock nahin";
	char (*ptr)(char,char,int,char*);
	ptr = &greatest_char;
	assertEqual(reduce_char(array,strlen(array),ptr,'A'),'u');
}