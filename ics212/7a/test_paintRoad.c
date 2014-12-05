#include <stdio.h>

int costofpainting(double);


int main(int argc, char *argv[])
{
    int cost = costofpainting(2.0);
    printf("Cost to paint 2mi: %d\n", cost);
    cost = costofpainting(3.0);
    printf("Cost to paint 3mi: %d\n", cost);
    cost = costofpainting(7.0);
    printf("Cost to paint 7mi: %d\n", cost);
    cost = costofpainting(70.0);
    printf("Cost to paint 70mi: %d\n", cost);
    cost = costofpainting(-7.0);
    printf("Cost to paint -7mi: %d\n", cost);
    return 0;
}
