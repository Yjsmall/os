int main() {
    // set FL_IF in the CPU.
    asm volatile("sti");

    // clear FL_IF in the CPU.
    asm volatile("cli");

    while (1);
}
