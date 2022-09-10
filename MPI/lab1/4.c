#include "mpi.h"
#include <stdio.h>
#include <locale>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"russian");
    MPI_Init(&argc,&argv);
    double starttime, endtime;
    for(double e = 0.000001; e >= 0.000000001; e *= 0.1){
        double sum = 0;
        starttime = MPI_Wtime();
        for(int i = 0; 1.0/(1 + i) > e ; i++){
            sum += 1.0/(1 + i);
        }
        endtime = MPI_Wtime();
        printf("Предел: %f Сумма: %f Время: %f\n", e, sum, endtime - starttime);
    }
    MPI_Finalize();
    return 0;
}