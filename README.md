# MemWorkOptimizationOS5
It is important for a software developer to understand memory hierarchy, because it greatly influances the performance of applications. With this knowledge it will be possible to create applications that use higher levels of memory in a hierarchy,so that the CPU gets access to them more quickly. It is also important to think about the localization. There are 2 types of localization:
*Time localization – when we try to access the same block in the memory very often
*Space localization - when we try to access blocks of memory located near the previous accessed block

To optimize memory work we need to focus on the following:


* Inner cycles. They usually do the most calculations and memory accesses.
* Maximize space localization. Read objects sequentialy, as they are located in memory.
* Maximize time localization. Use objects as often as you can after thay were read from memory.

### Given program:

```c++
static void Main(string[] args)
{
    int[,,] AMD = new int[1000,1000,1000];
    int res = 0;

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            for (int k = 0; k < 1000; k++)
            {
                AMD [k, j, i]++;
            }
        }
    }

}
```
### Execution time for program with no modifications
There were 10 test runs. With this code the times of executions were the following (in microseconds):
1. 1557564
2. 1556025
3. 1553267
4. 1557812
5. 1556812
6. 1587130
7. 1597900
8. 1650691
9. 1636565
10. 1666208

### Modifications to optimize memory work
In this case all we need is to think about the space localization. 
We were adressing our values from the 3-dimensional array through columns first. This is not how it is located in the memory.
The execution time would be better if we adressed memory blocks in rows.

### Modified code
```c++
int main(int argc, const char * argv[]) {
    
    int dim = 1000;
    int*** AMD = new int**[dim];
    for(int i = 0; i < dim; ++i) {
        AMD[i] = new int*[dim];
        for(int j = 0; j < dim; ++j) {
            AMD[i][j] = new int[dim];
        }
    }
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
```

### Execution time for program with no modifications
There were 10 test runs. With this code the times of executions were the following (in microseconds):
1. 1555623
2. 1554711
3. 1556365
4. 1552232
5. 1554672
6. 1626857
7. 1579924
8. 1573226
9. 1612383
10. 1634001
### Analysis
To help compare the execution times (in microseconds) of both programs a graph was built.
![graph](https://github.com/Starlight13/MemWorkOptimizationOS5/blob/main/graph.png)
It can be seen that the execution time was slightly improved by the modifications.
