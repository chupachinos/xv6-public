#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "spinlock.h"

struct {
    struct spinlock lock;
    struct proc proc[NPROC];
} ptable;

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_getprocs(void)
{
    acquire(&ptable.lock);
    struct proc *p;
    int count = 0;
    for(p = ptable.proc; p < &ptable.proc[NPROC]; p++){
        if((p->state != UNUSED)||(p->state == ZOMBIE))
            count = count + 1;
    }
    release(&ptable.lock);
    return count;
}
int
sys_direcfi(char *vir)
{
    struct proc *process = myproc();
    argstr(0, &vir);
    char *PD;
    pde_t *pagedir,*pagetab,*entry;
    pagedir = process->pgdir;
    pte = &pagetab[PTX(vir)];
    entry = &pagedir[PDX(vir)];
    if(*entry & PTE_P)
    {
        cprintf("...");
    }
    else
    {
        cprintf("La direccion virtual no existe");
        return 1;
    }
    pte_t *pte;
    PD = (char*)V2P(PTE_ADDR(*pte));    
    cprintf("La direccion fisica es: %d\n", PD);
    return 0;
}
