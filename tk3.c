#include <string.h>
#include <stdio.h>
#include "tk3.h"
#include "skinny.h"

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
    
}

/* TODO */
void finalize(unsigned char *a, context *ctx)
{
}
