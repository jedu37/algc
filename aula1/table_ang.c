#include<stdio.h>
#include<math.h>

int main(void)
{
    int min_ang,max_ang;
    double sin_s, cos_s, rad;

    puts("Minimum Angle ( 0 is the lowest):");
    scanf("%d",&min_ang);

    puts("Maximum Angle ( 00 is the lowest)");
    scanf("%d",&max_ang);

    puts("ang sin(ang) cos(ang)");
    puts("--- ------------- -------------");

    for(int i=min_ang;i<max_ang+1;i++){

        rad = (M_PI/180)*i;
        sin_s = sin(rad);
        cos_s = cos(rad);

        printf("%3d %1.10f %1.10f\n",i,sin_s,cos_s);
    }

    return 0;
}