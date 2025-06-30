#include <stdio.h>

#define combine(a, b, c, d, e, f, g) c ## d ## e ## f
#define start combine(m, a, i, n, p, r, o)


int start()
{
    printf("Did you figure it out?\n");
    return 0;
}

// Macro definition using the Token-pasting operator
#define concat(a, b) a##b
int main(void) {
    int xy = 30;

    // Printing the concatenated value of x and y
    printf("%d", concat(x, y));

    start();
    return 0;
}