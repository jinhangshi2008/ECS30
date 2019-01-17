#include <stdio.h>
#include <string.h>
int pack_comb(ITEM* items, int num_items, int max_weight, int curr_value){
    /*if(num_items = 0){
        return curr_value;
    }
    else if(max_weight <= 0){
        return curr_value;
    }*/
    else{
        for(i=0;i<num_items;++i){
            if(items[i].weight <= max_weight){
                best_value = max(pack_comb(items + i +1, num_items - i- 1, max.weight -items[i].weight, curr_val +items[i].value))
            }
        }
    }
    return best_value;
}