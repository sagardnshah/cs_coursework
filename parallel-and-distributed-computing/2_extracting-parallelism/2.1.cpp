//this is just pseudo code, it is not going to compile 


int num_p=4;
int array = {1, 2, 4, 5, 10, 13, 35, 68};

int partial_result[array.length/p]

int reduce (int* array , size_t n) {
    int work_for_each_p = array.length()/num_p;
    int current_p_num=0;
    int ending_index_for_current_p = work_for_each_p - 1;
    #i=the index of the array to start at
    for(int i=0; i<array.length(); i+=work_for_each_p){
        for(j=i; j<ending_index_for_current_p; j++){
            partial_result[current_p_num] += array[j];
        }
        current_p_num++;
        ending_index_for_current_p+=work_for_each_p;
    }

    int result;
    for(int z=0; z<partial_result.length(); ++z){
        result+=partial_result[z];
    }
    return result;
}