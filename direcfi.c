// Buffer cache.

#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc,char *argv[]){
    char *vir;
    vir = argv[1];
    printf(1,"direccion virtual: %s\n", vir);
    direcfi(vir);
    exit();
}
