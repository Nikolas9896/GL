/** 
 * @file	util.c
 * @brief	A source file with utility functions
 *
 * 
 * Copyright 2014 by mnxoid,
 * 
 * This software is the confidential and proprietary information
 * of mnxoid ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with mnxoid.
 **/
#include <stdio.h>
#include <string.h>
#define USELIM 1
#define NOLIM 0
#define SUCCESS 0
#define ERROR 1
//------------------C/C++ content-------------------------------
/**
 * @brief       This function flushes stdin
 **/
void CleanInput (  ) 
 {
 	while ( ! ( getchar (  ) =='\n' )  )  continue; 
 }
/**
 * @brief       This function gets user input ( char ) 
 * @param		[in]			*possible - pointer to char array of possible
 *											input values
 * @param		[in/out]		*pc - pointer to char that we input
 * @return		unsigned char 	SUCCESS - success
 * 								ERROR - error
 **/
unsigned char InputChar ( const char *possible, char *pc ) 
 {
 	if  ( possible==NULL ) 
 	 {
 	 	return ERROR; 
 	 } else {
	 	char a; 
	 	scanf ( "%c", &a ) ; 
	 	CleanInput (  ) ; 
	 	char needle[2]; 
	 	needle[0]=a; 
	 	needle[1]='\0'; 
	 	if  ( strstr ( possible, needle ) ==NULL ) 
	 	 {
	 	 	do
	 	 	 {
	 	 		printf ( "Sorry,  try again: " ) ; 
	 	 		scanf ( "%c", &a ) ; 
	 	 		CleanInput (  ) ; 
	 	 		needle[0]=a; 
	 	 	 } while  ( strstr ( possible, needle ) ==NULL ) ; 
	 	 	*pc=a; 
	 	 	return SUCCESS; 
	 	 } else {
	 	 	*pc=a; 
	 	 	//printf ( "%c\n", a ) ; 
	 	 	//printf ( "%s\n", pc ) ; 
	 	 	return SUCCESS; 
	 	 }
	 }
 }
/**
 * @brief       This function inputs an integer
 * @param	[in/out]		*i - pointer to the integer
 * @param   [in]			use - limit usage flag ( USELIM/NOLIM ) 
 *							min - lower bound
 *							upper bound
 * @return	unsigned char		0 - success
 *								1 - error ( null pointer ) 
 **/
unsigned char InputInt ( int *i, unsigned char use, int min, int max ) 
 {
 	if  ( i==NULL )  return ERROR; 
 	int retc, in; 
 	if  ( use==USELIM ) 
 	 {
 	 	retc=scanf ( "%i", &in ) ; 
	 	CleanInput (  ) ; 
	 	if  (  ! (  (  retc > 0  )  &&  (  in > min  )  &&  (  in < max  )  )   ) 
	 	 {
	 	 	do
	 	 	 {
	 	 		printf ( "Sorry,  try again: " ) ; 
	 	 		retc=scanf ( "%u", &in ) ; 
	 	 		CleanInput (  ) ; 
	 	 	 } while  (  ! (  (  retc > 0  )  &&  (  in > min  )  &&  (  in < max  )  )   ) ; 
	 	 }
 	 } else {
 	 	retc=scanf ( "%i", &in ) ; 
	 	CleanInput (  ) ; 
	 	if  (  ! (  retc > 0  )   ) 
	 	 {
	 	 	do
	 	 	 {
	 	 		printf ( "Sorry,  try again: " ) ; 
	 	 		retc=scanf ( "%u", &in ) ; 
	 	 		CleanInput (  ) ; 
	 	 	 } while  (  ! (  retc > 0  )   ) ; 
	 	 }
 	 }
 	*i=in; 
 	return SUCCESS;
 }
//------------------C++ only content----------------------------
#ifdef __CPLUSPLUS
#endif
//------------------End of file---------------------------------