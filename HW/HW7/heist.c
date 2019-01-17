#include <stdio.h>
#include <stdlib.h>
//this program calculates the most net you can get from the items you rob from a jewelry store
void input(int *num_item, int *bag_weight, int*** list){
    int i;
    printf("Enter the maximum amount of weight that your bag can hold: ");
    scanf("%d", &(*bag_weight));
    printf("Enter the number of items that are in the jewelry store: ");
    scanf("%d", &(*num_item));
    printf("Enter your items, one per line (value weight): \n");
    //malloc a 2d array to store the information of the list of items
    *list = (int**)malloc((*num_item)*sizeof(int));
    for(i=0; i<*num_item;i++){
        (*list)[i] = (int*)malloc(2*sizeof(int));
        scanf("%d %d", &((*list)[i][0]), &((*list)[i][1]));
    }
}
//free everything in the end
void free_list(int** list, int num_item){
	int i;
	for(i = 0 ; i < num_item; ++i){
		free(list[i]);
	}
	
	if(list != NULL && num_item > 0){
		free(list);
	}
}
//when the current value is greater than the last best value, we reassign the best value to current value
int max(int best_value, int curr_value){
    if(best_value < curr_value){
        best_value = curr_value;
    }
    return best_value;
}
//this function directly returns the best value by comparing the outcome of each combination
int pack_comb(int num_item, int bag_weight, int** list, int curr_value, int best_value){
    int i;
    for(i=0;i<num_item;i++){
        if(list[i][1]<=bag_weight){
            best_value = max(pack_comb(num_item - i - 1, bag_weight - list[i][1], list + i + 1, curr_value + list[i][0], best_value), curr_value + list[i][0]);
        }
    }
    return best_value;
}
int main(){
    int num_item;
    int bag_weight;
    int** list;
    int curr_value = 0;
    int best_value = 0;
    input(&num_item, &bag_weight, &list);
    best_value = pack_comb(num_item, bag_weight, list, curr_value, best_value);
    printf("They most profitable heist will net you $%d in total. ", best_value);
    free_list(list, num_item);
}