#include <string.h>
#include <stdio.h>
#include "tk3.h"
#include "skinny.h"

#define rate 16
#define cap 32
#define tk 16
#define block 16

/* TODO */
void init(context *ctx)
{
    memset(ctx->rIV384, 0, rate);
    memset(ctx->cIV384, 0x00, cap);
    ctx->cIV384[0] = 0x01;
    memcpy(ctx->S384, ctx->cIV384, rate);
    memcpy(ctx->S384 + rate, ctx->cIV384, cap);

    memset(ctx->tk1, 0, tk);
    memset(ctx->tk2, 0, tk);
    memset(ctx->tk3, 0, tk);

    ctx->tk2[1] = 0x01; //8th bit is 1, so 2nd byte, 1st index
    ctx->tk3[0] = 0x01; //7th bit is 1, so 1st byte, 0th index probab!
}

/* TODO */
void update(const unsigned char *a, int len, context *ctx)
{
    int i, j;
    unsigned char temp[rate];

    for (i = 0; i < len; i += rate)
    {
        // absorb
        for (j = 0; j < rate; j++)
        {
            if (i + j < len)
            {
                ctx->S384[j] ^= a[i + j];
            }
            else
            {
                ctx->S384[j] ^= 0x80;
            }
        }

        // update F384
        for (j = 0; j < cap; j += 16)
        {
            memcpy(temp, ctx->S384 + rate, 16);
            memcpy(ctx->S384 + rate, ctx->S384, rate);
            memcpy(ctx->S384, )
        }
    }
}

/* TODO */
void finalize(unsigned char *a, context *ctx)
{
}

void f384(unsigned char *input, unsigned char *out, context *ctx)
{
    unsigned char temp[block] = {0};
    skinny(temp, input, ctx->tk1);
    memset(out, temp, 16);

    skinny(temp, input, ctx->tk2);
    memset(out + 16, temp, 16);
    
    skinny(temp, input, ctx->tk3);
    memset(out + 32, temp, 16);
}