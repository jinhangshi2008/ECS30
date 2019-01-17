#include <stdio.h>
#include <stdlib.h>
#include <math.h>
FILE* validate_input(int argc, char* argv[]){

	FILE* fp = NULL;
//two arguments are needed include perimeter.out
	if(argc < 2){
		printf("Not enough arguments entered.\nEnding program.\n");
		exit(0);
	}
	else if(argc > 2){
		printf("Too many arguments entered.\nEnding program.\n");
		exit(0);
	}
	
	fp = fopen(argv[1], "r");
//if the file is empty, set everything to default and end the program
	if(fp == NULL){
		printf("Unable to open file: %s\nEnding program.\n", argv[1]);
		exit(0);
	}
	
	return fp;
}
//This function read a file number by number
void read_num(FILE* fp, int*** points, int* num_points){
	int i;
	//read the first number which indicates how many points are in the file
	fread(&(*num_points), sizeof(int), 1, fp);
	*points = (int**) malloc((*num_points) * sizeof(int*));
	//record every point
	for(i=0;i<(*num_points);i++){
		(*points)[i] = (int*)malloc(2*sizeof(int));
		//a point has x and y coordinates
		fread(&(*points)[i][0], sizeof(int), 1, fp);
		fread(&(*points)[i][1], sizeof(int), 1, fp);
	}
}
//calculate the perimeter
double calculate(int** points, int num_points){
	int i;
	double perimeter = 0.0;
	for(i=0;i<(num_points-1);i++){
		perimeter = perimeter + sqrt(pow((points[i+1][0] - points[i][0]), 2) + pow((points[i+1][1] - points[i][1]), 2));
	}
	//add on the distance between the last point and the first point
	perimeter = perimeter + sqrt(pow((points[num_points-1][0] - points[0][0]), 2) + pow((points[num_points-1][1] - points[0][1]), 2));
	return perimeter;
}
void free_points(int** points, int num_points){
	int i;
	
	for(i = 0 ; i < num_points; ++i){
		free(points[i]);
	}
	
	if(points != NULL && num_points > 0){
		free(points);
	}

}
int main(int argc, char* argv[]){
	int** points = NULL;
	int num_points = 0;
	double perimeter;
	FILE* fp = validate_input(argc, argv);
	
	read_num(fp, &points, &num_points);
	perimeter = calculate(points, num_points);
	printf("The perimeter is %.2f ", perimeter);
	free_points(points, num_points);
	fclose(fp);

	return 0;
}