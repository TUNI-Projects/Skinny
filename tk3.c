#include <string.h>
#include <stdio.h>
#include "tk3.h"
#include "skinny.h"


void f_384()
{
    //call for skinny encryption three times and OR them together?

}


    /* TODO */
void init(context *ctx)
{
    memset(ctx->rIV384, 0, 16);
    memset(ctx->cIV384, 0x00, 32);
    ctx->cIV384[0] = 0x01;
    memcpy(ctx->S384, ctx->cIV384, 16);
    memcpy(ctx->S384 + 16, ctx->cIV384, 32);
}

/* TODO */
void update(const unsigned char *a, int len, context *ctx)
{

    // pad a ?
    /*
    int i;
    for (i = 0; i < len; i++) {
        s = f_384( s ^ (a | 0))
    }
    */

}

/* TODO */
void finalize(unsigned char *a, context *ctx)
{
}
