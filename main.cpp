#include <iostream>
#include <chrono>
using namespace std::chrono;


//static void Main(string[] args)
//{
//    int[,,] AMD = new int[10,10,10];
//    int res = 0;
//
//    for (int i = 0; i < 10; i++)
//    {
//        for (int j = 0; j < 10; j++)
//        {
//            for (int k = 0; k < 10; k++)
//            {
//                AMD [k, j, i]++;
//            }
//        }
//    }
//
//}

int main(int argc, const char * argv[]) {
    
    int dim = 1000;
    int*** AMD = new int**[dim];
    for(int i = 0; i < dim; ++i) {
        AMD[i] = new int*[dim];
        for(int j = 0; j < dim; ++j) {
            AMD[i][j] = new int[dim];
        }
    }
    for (int times = 0; times < 5; times++) {
        auto start = high_resolution_clock::now();
        for (int i = 0; i < 1000; i++)
        {
            for (int j = 0; j < 1000; j++)
            {
                for (int k = 0; k < 1000; k++)
                {
                    AMD[i,j,k]+1;
                }
            }
        }
        
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        std::cout << duration.count() << '\n';
    }
    

}
