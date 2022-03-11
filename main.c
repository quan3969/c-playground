
#include "my_function.h"  
#include "test_function.h"
#include "driver_info.h"

int main( int argc, char *argv[], char **envp )
{
    // tf_test();

    store_driver_info_fgets();

    system ( "pause" );

    return 0;
}
