#include <assert.h>
#include <stdio.h>

typedef struct {
  char name;
  int pc;
  int n;
  int retval;
} Frame;

#define call_f(...) ({ *(++top) = (Frame){.name = 'f', .pc = 0, __VA_ARGS__}; })
#define call_g(...) ({ *(++top) = (Frame){.name = 'g', .pc = 0, __VA_ARGS__}; })
#define ret(val) ({top--; retval = (val);})

int f(int n) {
  Frame stk[64];
  Frame *top = stk - 1;

  int retval = 0;

  call_f(n);

  while (1) {
    Frame *cur = top;
    if (top < stk) { break; }

    int next_pc = cur->pc + 1;

    if (cur->name == 'f') {

      switch (cur->pc) {
      case 0:
        if (cur->n <= 1) { ret(1); }
        break;
      case 1: call_f(cur->n - 1); break;
      case 2: cur->retval = retval; break;
      case 3: call_g(cur->n - 2); break;
      case 4: ret(cur->retval + retval); break;
      default: assert(0);
      }

    } else {

      switch (cur->pc) {
      case 0:
        if (cur->n <= 1) { ret(1); }
        break;
      case 1: call_f(cur->n + 1); break;
      case 2: cur->retval = retval; break;
      case 3: call_g(cur->n - 1); break;
      case 4: ret(cur->retval + retval); break;
      default: assert(0);
      }
    }

    cur->pc = next_pc;
  }
  return retval;
}

int g(int n) {
  Frame stk[64];
  Frame *top = stk - 1;

  int retval = 0;

  call_g(n);

  while (1) {
    Frame *cur = top;
    if (top < stk) { break; }

    int next_pc = cur->pc + 1;

    if (cur->name == 'f') {

      switch (cur->pc) {
      case 0:
        if (cur->n <= 1) { ret(1); }
        break;
      case 1: call_f(cur->n - 1); break;
      case 2: cur->retval = retval; break;
      case 3: call_g(cur->n - 2); break;
      case 4: ret(cur->retval + retval); break;
      default: assert(0);
      }

    } else {
      switch (cur->pc) {
      case 0:
        if (cur->n <= 1) { ret(1); }
        break;
      case 1: call_f(cur->n + 1); break;
      case 2: cur->retval = retval; break;
      case 3: call_g(cur->n - 1); break;
      case 4: ret(cur->retval + retval); break;
      default: assert(0);
      }
    }

    cur->pc = next_pc;
  }
  return retval;
}

int main() {
  printf("f(3)-%d\n", f(3));
  printf("g(3)-%d\n", g(3));
  return 0;
}