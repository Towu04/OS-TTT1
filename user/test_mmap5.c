#include "user/user.h"
#include "kernel/memlayout.h"

#define MEM 0x0000000baddad000
#define MAXMAPPAGES 10
#define PERM (PTE_R | PTE_W);

int mmap() __attribute__((weak));

// Properly checks whether there is still space in `mmap_pages` **and abort sanely**
int main(int argc, char **argv) {
  int perm = PERM;
  for(int i = 0; i < MAXMAPPAGES; ++i) {
    if (mmap(MEM+(i*PGSIZE), perm, 0) != 0) {
      printf("Error: mmap should have succedded\n");
      return -1;
    }
  }
  if (mmap(MEM+(MAXMAPPAGES*PGSIZE), perm, 1) == 0) {
    printf("Error: mmap should have failed\n");
    return -1;
  }
  printf("SUCCESS\n");
  return 0;
}