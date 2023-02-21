/*
 * matchpt2.c
 *
 *  Created on: Feb 20, 2023
 *      Author: b527h871
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

int main(){

	int pref[N*2][N], d1=0,d2=0,d3=0,d4=0,d5=0;
	int num_location(int prog,int num){
			int location=0;
			for(int i=0; i<N; i++){
				if (pref[i+5][prog-1] == num){
					location =i;
					return location;
				}}
		}

	FILE *fileptr;
	fileptr = fopen("input.txt","r");
	for(int i=0;i<N*2;i++){
		fscanf(fileptr,"%d %d %d %d %d", &pref[i][0],&pref[i][1],&pref[i][2],&pref[i][3],&pref[i][4]);
		}

	for (int i =1; i<N;i++){
		if (pref[0][i]==pref[0][0]){
			if(num_location(pref[0][0],1)<num_location(pref[0][0],i+1)){
				d1 = pref[0][0];
			}
		}
	}
	printf("Department #1 will get Programmer #%d.\n", d1);
	for (int i=2; i<N; i++){
		if (pref[0][1] == d1){
			if (pref[0][i] == pref[1][1]){
				if(num_location(pref[1][1],2)<num_location(pref[1][1],i+1)){
					d2 = pref[1][1];
				}
		}
		}
		else{
			if(pref[0][i]==pref[0][1]){
				if(num_location(pref[0][1],2)<num_location(pref[0][1],i+1)){
					d2 = pref[0][1];
				}
		}
		}
	}
	printf("Department #2 will get Programmer #%d.\n", d2);
	for (int i=3; i<N; i++){
		if ((pref[0][2] == d1)||(pref[0][2]==d2)){
			if ((pref[1][2] == d1)||(pref[1][2]==d2)){
				if(pref[0][i] == pref[2][2]){

					if(num_location(pref[2][2],3)<num_location(pref[2][2],i+1)){
						d3 = pref[2][2];
					}
				}
			}
			else if(pref[0][i]==pref[1][2]){

				if(num_location(pref[1][2],3)<num_location(pref[1][2], i+1)){
					d3 = pref[1][2];
				}
			}
			else if(pref[4][i] == pref[3][2]){
				if (num_location(pref[3][2],3)<num_location(pref[3][2],i+1)){
					d3 = pref[3][2];
				}
			}
		}
		else{
			if(pref[0][i]==pref[0][2]){
				if(num_location(pref[0][2],3)<num_location(pref[0][2],i+1)){
					d3 = pref[0][2];
				}
		}
		}
	}
	printf("Department #3 will get Programmer #%d.\n", d3);
	for (int i=4; i<N; i++){
		if ((pref[0][3] == d1)||(pref[0][3]==d2)||(pref[0][3]==d3)){
			if ((pref[1][3] == d1)||(pref[1][3]==d2)||(pref[1][3]==d3)){
				if ((pref[2][3] == d1)||(pref[2][3]==d2)||(pref[2][3]==d3)){
					if (pref[0][i] == pref[3][3]){
						if (num_location(pref[3][3],4)<num_location(pref[3][3],i+1)){
							d4 = pref[3][3];
						}
					}
				}
				else if((pref[0][i]== pref[2][3])||(pref[3][i]== pref[2][3])){
					if(num_location(pref[2][3],4)<num_location(pref[2][3], i+1)){
						d4 = pref[2][3];
				}
				}
			}else if(pref[0][i] == pref[1][3]){
				if(num_location(pref[1][3],4)<num_location(pref[1][3], i+1)){
					d4 = pref[1][3];
				}
			}
		}
		else{
			if(pref[0][i]==pref[0][3]){
				if(num_location(pref[0][3],4)<num_location(pref[0][3],i+1)){
					d4 = pref[0][3];
				}
			}
		}
	}
	printf("Department #4 will get Programmer #%d.\n", d4);
	for(int i =0; i<N; i++){
		if ((d1!=pref[i][4])&&(d2!=pref[i][4])&&(d3!=pref[i][4])&&(d4!=pref[i][4])){
			d5 = pref[i][4];
			break;
		}
	}
	printf("Department #5 will get Programmer #%d.\n",d5);


}
