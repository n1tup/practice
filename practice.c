#include <math.h>
#include <locale.h>
#include <stdio.h>
#define MAX 100
 struct Coordinates 
{ 
   double x, y; 
};

double distance(int n, struct Coordinates Coords[MAX],double per ){
 double dis = 0;
 int ver = 1;
 while(ver <= n) {
    if(ver < n){
        dis = sqrt (((Coords[ver ].x - Coords[ver - 1].x) * (Coords[ver].x - Coords[ver - 1].x)) 
        + ((Coords[ver ].y - Coords[ver - 1].y) * (Coords[ver].y - Coords[ver- 1].y)));}
    if (ver == n){
        dis = sqrt (((Coords[0 ].x - Coords[ver - 1].x) * (Coords[0].x - Coords[ver - 1].x))
        + ((Coords[0 ].y - Coords[ver - 1].y) * (Coords[0].y - Coords[ver - 1].y)));}
    per += dis;
    ver++;
 }
    return per;
}

int main()
{
    int n, i=0;
    
    double per = 0;
    struct Coordinates Coords[MAX];
    setlocale(LC_ALL, "Rus");
    for(;;){
        printf("Введите кол-во вершин:");
        scanf("%d",&n);
        if(n>2  && n < 16) break;
        printf("Периметр многоугольника может быть подсчитан от 3 до 15 координат.\n");}
    printf("Введите координаты каждой вершины(х у):");
    for(int i=0;i<n;i++){
        scanf("%lf%lf",&Coords[i].x,&Coords[i].y);}
    per = distance( n, Coords ,per);
    printf("Периметр многоугольника равняется %lf условных единиц",per);
    
    return 0;
}
