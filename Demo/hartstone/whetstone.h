#ifndef WHETSTONE_H
#define WHETSTONE_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void PA(double E[], int *J, double T, double T2);
void P0(double E1[], int J, int K, int L);
void P3(double X, double Y, double *Z, double T, double T2);

#define DSIN	sin
#define DCOS	cos
#define DATAN	atan
#define DLOG	log
#define DEXP	exp
#define DSQRT	sqrt
#define IF		if


#define WHETSTONE_CODE(TASK_ID, NKWHETS) \
	long I; \
	long N1, N2, N3, N4, N6, N7, N8, N9, N10, N11; \
	double X1,X2,X3,X4,X,Y,Z,T,T1,T2,E1[5]; \
	int kwhetcount,J,K,L; \
	long LOOP; \
	T  = 0.499975;\
	T1 = 0.50025;\
	T2 = 2.0;\
	LOOP = 10;\
	N1  = 0;\
	N2  = 12 * LOOP / 1000;\
	N3  = 14 * LOOP / 1000;\
	N4  = 345 * LOOP / 1000;\
	N6  = 210 * LOOP / 1000;\
	N7  = 32 * LOOP / 1000;\
	N8  = 899 * LOOP / 1000;\
	N9  = 616 * LOOP / 1000;\
	N10 = 0;\
	N11 = 93 * LOOP / 1000;\
for (kwhetcount = 0;  kwhetcount < NKWHETS ;  kwhetcount++)  {\
	/*\
	C\
	C	Module 1: Simple identifiers\
	C\
	*/\
		X1  =  1.0;\
		X2  = -1.0;\
		X3  = -1.0;\
		X4  = -1.0;\
\
		for (I = 1; I <= N1; I++) {\
			X1 = (X1 + X2 + X3 - X4) * T;\
			X2 = (X1 + X2 - X3 + X4) * T;\
			X3 = (X1 - X2 + X3 + X4) * T;\
			X4 = (-X1+ X2 + X3 + X4) * T;\
		}\
	/*\
	C\
	C	Module 2: Array elements\
	C\
	*/\
		E1[1] =  1.0;\
		E1[2] = -1.0;\
		E1[3] = -1.0;\
		E1[4] = -1.0;\
\
		for (I = 1; I <= N2; I++) {\
			E1[1] = ( E1[1] + E1[2] + E1[3] - E1[4]) * T;\
			E1[2] = ( E1[1] + E1[2] - E1[3] + E1[4]) * T;\
			E1[3] = ( E1[1] - E1[2] + E1[3] + E1[4]) * T;\
			E1[4] = (-E1[1] + E1[2] + E1[3] + E1[4]) * T;\
		}\
	/*\
	C\
	C	Module 3: Array as parameter\
	C\
	*/\
		for (I = 1; I <= N3; I++)\
			PA(E1, &J, K, L);\
	/*\
	C\
	C	Module 4: Conditional jumps\
	C\
	*/\
		J = 1;\
		for (I = 1; I <= N4; I++) {\
			if (J == 1)\
				J = 2;\
			else\
				J = 3;\
			if (J > 2)\
				J = 0;\
			else\
				J = 1;\
			if (J < 1)\
				J = 1;\
			else\
				J = 0;\
		}\
	/*\
	C\
	C	Module 5: Omitted\
	C 	Module 6: Integer arithmetic\
	C\
	*/\
		J = 1;\
		K = 2;\
		L = 3;\
		for (I = 1; I <= N6; I++) {\
			J = J * (K-J) * (L-K);\
			K = L * K - (L-J) * K;\
			L = (L-K) * (K+J);\
			E1[L-1] = J + K + L;\
			E1[K-1] = J * K * L;\
		}\
	/*\
	C\
	C	Module 7: Trigonometric functions\
	C\
	*/\
		X = 0.5;\
		Y = 0.5;\
		for (I = 1; I <= N7; I++) {\
			X = T * DATAN(T2*DSIN(X)*DCOS(X)/(DCOS(X+Y)+DCOS(X-Y)-1.0));\
			Y = T * DATAN(T2*DSIN(Y)*DCOS(Y)/(DCOS(X+Y)+DCOS(X-Y)-1.0));\
		}\
	/*\
	C\
	C	Module 8: Procedure calls\
	C\
	*/\
		X = 1.0;\
		Y = 1.0;\
		Z = 1.0;\
		for (I = 1; I <= N8; I++)\
			P3(X,Y,&Z,T,T2);\
	/*\
	C\
	C	Module 9: Array references\
	C\
	*/\
		J = 1;\
		K = 2;\
		L = 3;\
		E1[1] = 1.0;\
		E1[2] = 2.0;\
		E1[3] = 3.0;\
		for (I = 1; I <= N9; I++)\
			P0(E1, J, K, L);\
	/*\
	C\
	C	Module 10: Integer arithmetic\
	C\
	*/\
		J = 2;\
		K = 3;\
		for (I = 1; I <= N10; I++) {\
			J = J + K;\
			K = J + K;\
			J = K - J;\
			K = K - J - J;\
		}\
	/*\
	C\
	C	Module 11: Standard functions\
	C\
	*/\
		X = 0.75;\
		for (I = 1; I <= N11; I++)\
			X = DSQRT(DEXP(DLOG(X)/T1));\
	}

#endif