extern int buf[];
int *bufp0 = &buf[0];
int *bufp1;

boid swap(){
  int temp;
  bufp1 = &buf[1];
  temp = *bufp0;
  *bufp0 = *bufp1;
  *bufp1 = temp;
}