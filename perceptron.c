#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float ReLU(float sum);
void updateValues(
    float* w1, float* w2, float* b,
    float x1, float x2, int y,
    float expected
);

int main() {
    int solutions[4][3] = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 0, 0},
        {1, 1, 1}
    }; 

    float w1, w2, b, y; 


    srand(time(NULL));
    w1 = ((rand() % 10000) / 10000.0);
    w2 = ((rand() % 10000) / 10000.0);
    b = ((rand() % 10000) / 10000.0);


    // training
    for (int i = 0; i < 1000; i++) {
        int index = rand() % 4;
        int x1 = solutions[index][0];
        int x2 = solutions[index][1];
        int expected = solutions[index][2];

        float sum = (w1 * x1) + (w2 * x2) + b;

        int result = sum >= 1 ? 1 : 0;

        updateValues(&w1, &w2, &b, x1, x2, result, expected);
    }

    int first, second;

    while(first != -1 && second != -1) {
        printf("Enter two numbers: ");
        scanf("%d %d", &first, &second);
        printf("numbers: %d %d\n", first, second);

        float sum = (w1 * first) + (w2 * second) + b;
        y = ReLU(sum);
        int result = y >= 1 ? 1 : 0;

        printf("Result: %d\n", result);
        printf("actual: %f\n", y);
    }

    return 0;
}


float ReLU(float sum)
{
    return sum > 0 ? sum : 0;
}

void updateValues(
        float* w1, float* w2, float* b, 
        float x1, float x2, int y,
        float expected
) {
    float learningRate = 0.05;
    *w1 = *w1 + learningRate * (expected - y) * x1;
    *w2 = *w2 + learningRate * (expected - y) * x2;
    *b = *w2 + learningRate * (expected - y); 
}


// julia flux
