#include <stdlib.h>
#include <stdio.h>
#define N 500000

int main(){
    float a = 1, b = -2, c = -1, x, y;
    float score, pull, step_size;
    int i, label, length, iter;

    float data[6][2] = {
        { 1.2, 0.7},
        {-0.3, 0.5},
        {  -3,  -1},
        { 0.1, 1.0},
        { 3.0, 1.1},
        { 2.1,  -3}
    };
    int labels[6] = {
        1,
        -1,
        1,
        -1,
        -1,
        1
    };
    for (iter = 0; iter < N; iter++){
        i = rand() % 6;
        x = data[i][0];
        y = data[i][1];
        label = labels[i];

        // compute pull
        score = a*x + b*y + c;
        pull = 0.0;
        if(label == 1 && score < 1) pull = 1;
        if(label == -1 && score > -1) pull = -1;

        // compute gradient and update parameters
        step_size = 0.01;
        a += step_size * (x * pull - a); // -a is from the regularization
        b += step_size * (y * pull - b); // -b is from the regularization
        c += step_size * (1 * pull);

    }
    printf("%f %f %f\n", a, b, c);
    return 0;

}