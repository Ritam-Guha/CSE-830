#include <iostream>
#include <map>
#include <unordered_map>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <iomanip>

template <class T>
double compute_insertion_time(T& container, std::vector<int> inputs){
    container.clear();

    // compute the time required to insert all the elements
    clock_t begin_time = clock();
    for(int i=0; i<inputs.size(); i++){
        container.insert(std::pair<int, int>(i, inputs[i]));
    }
    clock_t end_time = clock();
    double time_required = double(end_time - begin_time) / CLOCKS_PER_SEC;

    return time_required;
}

int main(){

    std::multimap<int, int> bst;
    std::unordered_multimap<int, int> hash;
    std::vector<int> input_vect;
    double time_bst, time_hash;

    std::vector<int> count_elements_vect = { 10, 100, 1000, 10000, 100000, 1000000, 2000000, 3000000 };
    std::ofstream outfile;
    outfile.open("Performance.txt", std::ofstream::out);

    for(int i=0; i< count_elements_vect.size(); i++){
        srand(time(0));
        for(long j=0; j<count_elements_vect[i]; j++){
            input_vect.push_back(rand()%100000 + 1);
        }
        time_bst = compute_insertion_time(bst, input_vect);
        time_hash = compute_insertion_time(hash, input_vect);
        outfile << std::fixed << count_elements_vect[i] << "," << time_bst << "," << time_hash << std::endl;
        
        std::cout << "Current element size: " << count_elements_vect[i] << std::endl;
        std::cout << "Time required by the BST is: " << time_bst << std::endl;
        std::cout << "Time required by the Hash is: " << time_hash << std::endl << std::endl;
    }

    outfile.close();
}
