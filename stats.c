/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  unsigned char mean = 0 , maximum = 0 , minimum = 0, median = 0 ;
	
  print_array(test,SIZE);	
  mean = find_mean(test,SIZE);
  maximum = find_maximum(test,SIZE);
  minimum = find_minimum(test,SIZE);
  median = find_median(test,SIZE);
  sort_array(test,SIZE);
  print_statistics(test,SIZE,minimum,maximum,mean,median);

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

}
void print_array(unsigned char *ptr,unsigned int length){
	unsigned int i = 0 ;
	while(i<length){
		printf("%d.element: %d\n",i+1,*(ptr+i));
		i++;
	}
	
}
unsigned char find_mean(unsigned char *ptr,unsigned int length){
	unsigned int i = 0,total = 0;
	unsigned char mean = 0;	
	
	while(i<length){
		total += *(ptr+i);
		i++;
	}
	mean = total / length ;
	return mean;
}
unsigned char find_maximum(unsigned char *ptr,unsigned int length){
	unsigned char maximum = 0, i = 0;
	
	for(;i<length;i++){
	    if(*(ptr + i) > maximum){
	    	maximum = *(ptr + i);
		}
		i++;
	} 
	return maximum;
}
unsigned char find_minimum(unsigned char *ptr,unsigned int length){
	unsigned char minimum = 255, i = 0;	
	for(;i<length;i++){
	    if(minimum > *(ptr + i)){
	    	minimum = *(ptr + i);
		}
		i++;
	} 
	return minimum;
}
void sort_array(unsigned char *ptr,unsigned int length){
    unsigned char j = 0, i = 0, h = 0, temp = 0;
    unsigned char sorted[length] ;		
	 
    for (i = 0 ;i < length; i++)  {
        for (j = 0 ;j < length - i ;j++) {
            if (*(ptr + j) < *(ptr + j + 1)) {
	            temp  = *(ptr + j) ;
	            *(ptr + j) = *(ptr + j + 1);
	            *(ptr + j + 1) = temp ;
			}
		}
	}
	
}
unsigned char find_median(unsigned char *ptr,unsigned int length){
	unsigned char median = 0, middle = 0;
	sort_array((unsigned char *)ptr,length);
	
	middle = (length / 2);
	if(length % 2 == 0){
		median = (*(ptr + middle - 1) + *(ptr + middle ) )/ 2; 	
	}
	else{
		median = *(ptr + middle + 1); 		
	}
	return median;
}
void print_statistics(unsigned char *ptr,unsigned int length,unsigned char min,unsigned char max,unsigned char mean,unsigned char median){
	unsigned char i = 0;
	sort_array((unsigned char *)ptr,length);
    for(;i < length ; i++){
		printf("\n%d.Sorted Element %d \n",i+1,*(ptr + i));
	}
	printf("\n*****************\n*****************\n");
	printf("\nMaximum of Array = %d \n",max);
	printf("\nMinimum of Array = %d \n",min);
	printf("\nMean of Array = %d \n",mean);
	printf("\nMedian of Array = %d \n",median);
}

/* Add other Implementation File Code Here */
