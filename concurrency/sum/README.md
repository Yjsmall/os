**并发 1 + 1**：如果两个线程，每个线程都执行 `N` 次 `sum++`，最终会得到什么结果？即便我们强制使用一条汇编指令完成 `sum++`，依然无法保证最终得到 `2N` 的结果。在共享内存上实现并发控制是一个相当困难的问题。
