#include "types.h"
#include "bitmap.h"
#include "proc.h"
#include "defs.h"
#include "syscall.h"
#include "syscallfilter.h"

// Blocks the system call corresponding to the number provided in the first system-call argument.
// Returns 0 on success or -1 if the system call number argument is invalid.
uint64 sys_syscallfilter(void)
{
  int num;
  argint(0, &num);

  if(num < 1 || num > 27) {
    return -1;
  }

  myproc()->bitmap = clear_bit(myproc()->bitmap, num);
  return 0;
}