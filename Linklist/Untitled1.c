#include <stdio.h>

void fun(int n) {
    if (n<=0)
        return ;
        n=n-1;
        fun(n);
         printf(" %d", n);

}

int main() {
   fun(5);

}
