#include <stdio.h>

#define ERROR(...) \
    do{ \
    printf("\x1b[31m %s ERROR:",__FUNCTION__); \
    printf(__VA_ARGS__); \
    printf("\x1b[0m"); \
} while(0)

#define SUCCESS(...) do {\
    printf("\x1b[32m %s SUCCESS:", __FUNCTION__); \
    printf(__VA_ARGS__); \
    printf("\x1b[0m"); \
} while(0)


int main() {
    SUCCESS("Wow, this is cool %i\n", 10);
}
