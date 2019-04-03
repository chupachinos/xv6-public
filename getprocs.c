// Buffer cache.

#include "types.h"
#include "defs.h"
#include "stat.h"
#include "user.h"
#include "proc.h"

int main(){
    printf("El numero de procesos corriendo en el sistema es de: %d\n", getprocs());
    exit();
}
