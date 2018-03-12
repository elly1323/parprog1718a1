#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// compile like:  gcc -Wall -O2 -DNROWS=10000 matrix1.c -o matrix1


#define NCOLS 100
#define NROWS 100000

void get_walltime(double *wct) {
  struct timeval tp;
  gettimeofday(&tp,NULL);
  *wct = (double)(tp.tv_sec+tp.tv_usec/1000000.0);
}


int main() {
double *table;
double ts,te;


  table = (double *)malloc(NROWS*NCOLS*sizeof(double)); 
  if (table==NULL) {
    printf("alloc error!\n");
    exit(1);
  }
  
  
  // warmup
int i,j;
double time;
int sum=0;
  // ...your code here...
for (i=0; i<NROWS*NCOLS; i++){
	table[i]=0.0;
}
  // get starting time (double, seconds) 
  get_walltime(&ts);
  
  // workload
for (i=0; i<NROWS;i++){
  	for (j=0; j<NCOLS;j++){
  	table[i,j]=1.0;
	sum++;    
	  }
  }

  // ...your code here...

  // get ending time
  get_walltime(&te);

  // check results
  printf ("Number of accesses: %d\n", sum);
  // ...your code here...
  time= te-ts;
  double prospelaseis=sum/(time*1e6);
  printf ("Maccesses/sec: %f\n", prospelaseis);

  // print time elapsed and/or Maccesses/sec
  printf ("Time elapsed: %f sec", time);
  // ...your code here...  
  
  free(table);

  return 0;
}
