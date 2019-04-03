// Buffer cache.

#include "types.h"
#include "defs.h"
#include "stat.h"
#include "user.h"
#include "proc.h"

int main(void){
    printf(1,"El numero de procesos corriendo en el sistema es de: %d\n", getprocs());
    exit();
}
