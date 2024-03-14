#include <thread.h>

#define LOCKED   1
#define UNLOCKED 0

int status = UNLOCKED;

void lock() {
    int expected;
    do {
        // Try compare status with expected.
        // If the comparison succeeded, perform
        // an exchange.
        expected = UNLOCKED;
        asm volatile (
            "lock cmpxchgl %2, %1"
            : "+a" (expected) // Value for comparison.
                              // x86 uses eax/rax.
            : "m" (status),   // Memory location.
              "r" (LOCKED)    // Value to be written if
                              // status == expected
            : "memory", "cc"
        );
    } while (expected != UNLOCKED);
}

void unlock() {
    // To be safer:
    //
    // asm volatile (
    //     "movl %1, %0"
    //     : "=m" (status)
    //     : "r" (UNLOCKED)
    //     : "memory"
    // );

    // But actually we can do this:
    status = UNLOCKED;
}

#define N 10000000

long volatile sum = 0;

void T_sum() {
    for (int i = 0; i < N; i++) {
        lock();
        // This critical section is even longer.
        // We also marked sum as volatile to make
        // sure it is loaded and stored in each
        // loop iteration.
        for (int _ = 0; _ < 10; _++) {
            sum++;
        }
        unlock();
    }
}

int main() {
    create(T_sum);
    create(T_sum);
    create(T_sum);

    join();

    printf("sum  = %ld\n", sum);
    printf("30*n = %ld\n", 30L * N);
}
