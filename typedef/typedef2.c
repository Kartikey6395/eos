
#include <stdio.h>

typedef char* ptr;

int main(int argc, char const *argv[])
{
    ptr a, b, c;

    printf("sizeof a:%lu\n" ,sizeof(a) );
    printf("sizeof b:%lu\n" ,sizeof(b) );
    printf("sizeof c:%lu\n" ,sizeof(c) );

    return 0;
}