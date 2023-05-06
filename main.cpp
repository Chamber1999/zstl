#include <iostream>
#include "include/zvector.h"
int main()
{    
    zstl::zvector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    v.print_reverse();
    return 0;
}
