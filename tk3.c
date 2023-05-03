#include <string.h>
#include <stdio.h>
#include "tk3.h"
#include "skinny.h"


/*TODO*/
void f_384()
{
}

/* TODO 
Is this suppose to happen here? Also what is the initial state of the context?
We need to define the strucutre in tk3.h ? Is the context the S value in the papaer?
*/
void init(context *ctx)
{

    unsigned char iv_r = 0;
    unsigned char iv_c = 0; // How to set value to 10²⁵⁵ ?

    unsigned char S = iv_r | iv_c; //previous values are ORed?
}

/* TODO */
void update(const unsigned char *a, int len, context *ctx) {

}

/* TODO */
void finalize(unsigned char *a, context *ctx) {

}
