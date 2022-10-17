#include <iostream>
#include <cstring>


struct SCow {
    int weight;
    int milkPerDay;
};


void bad_sort(int* arr, size_t size) {
    for(int i = 0; i < size; ++i) {
        for(int j = i + 1; j < size; ++j) {
            if((arr[i] > arr[j])) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}


int comp(const void* a, const void* b) {
    return *(const int*)a - *(const int*)b;
}


int compForDouble(const void* a, const void* b) {
     return *(const double*)a - *(const double*)b;
}


int compForCow(const void* a, const void* b) {
    SCow* pa = (SCow*)a;
    SCow* pb = (SCow*)b;

    return pa->weight - pb->weight;
}


void swap(int8_t* a, int8_t* b, size_t size) {
    for(size_t i = 0; i < size; ++i) {
        int8_t tmp = *(a + i);
        *(a + i) = *(b + i);
        *(b + i) = tmp;
    }
}

void sort(
    void* base,
    size_t size,
    size_t sizeOfElemnt,
    int (*comp)(const void*,const void*)
) { // 3
    int8_t* arr = (int8_t*)base;

    for(int i = 0; i < size; ++i) {
        for(int j = i + 1; j < size; ++j) {
            if(comp(arr + i * sizeOfElemnt, arr + j * sizeOfElemnt) > 0) { // 2
                swap(arr + i * sizeOfElemnt, arr + j * sizeOfElemnt, sizeOfElemnt);
            }
        }
    }
}

int main(int, char**) {

    int arr[] = { 5, 4, 7, 2, 1};
    double arr2[] = { 5.0, 4.0, 3.0, 2.0, 1.0};
    SCow herd[] = {{200, 10}, {150, 19}, {140, 18}};


//    sort(arr, sizeof(arr)/sizeof(int), sizeof(int), comp);
//    sort(arr2, 5, sizeof(double),compForDouble);
//    sort(herd, 3, sizeof(SCow), compForCow);

    uint8_t* arr3 = (uint8_t*)arr2;

    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 8; ++j) {
            int value = *(arr3 + i * 8 + j);
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    std::cout << sizeof(int) << " " << sizeof(double) << std::endl;
    bad_sort((int*)arr2, 5);

    std::cout <<  "------------------------------------------\n";

    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 8; ++j) {
            int value = *(arr3 + i * 8 + j);
            std::cout << value << " ";
        }

        std::cout << std::endl;
    }

    // for(int i = 0; i < 5; ++i)
    //     std::cout << arr[i]  << " ";
    // std::cout << std::endl;

    // for(int i = 0; i < 5; ++i)
    //     std::cout << arr2[i]  << " ";
    // std::cout << std::endl;

    return 0;
}
