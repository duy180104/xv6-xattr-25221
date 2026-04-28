#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(void) {
  printf("Dang goi syscall procdump...\n");
  procdump();
  exit(0);
}
