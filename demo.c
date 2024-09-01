#include <stdio.h>

 int fun(int x){
     if( x> 100)    
        return (x-10);
    else
        return fun(fun(x+11));
        
 }
int main()
{
    int a = fun(95);
    printf("%d\n",a);

    return 0;
}
