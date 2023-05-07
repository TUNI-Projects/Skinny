#include <string.h>
#include <stdio.h>
#include "tk3.h"
#include "skinny.h"

#define rate 16
#define cap 32
#define tk 16
#define block 16

void f384(unsigned char *input, unsigned char *out, context *ctx);
void pad_message(unsigned char *m, int length, unsigned char *padded_m);

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

    ctx->tk2[1] = 0x01; // 8th bit is 1, so 2nd byte, 1st index
    ctx->tk3[0] = 0x01; // 7th bit is 1, so 1st byte, 0th index probab!
}

void update(const unsigned char *original_message, int len, context *ctx)
{
    int i, j;
    unsigned char padded_message[block]; // <- this is the padded new message.

    for (i = 0; i < len; i += block)
    {
        // memcpy(temp, a + i, block); <- i am not sure about keeping a copy!
        // so padding will happen no matter what.
        pad_message(original_message, i + block < len ? block : len - i, padded_message);
        // TODO: Update the state using the permutation function
        ctx->S384[128] = 0x01; // line 2.

        for (j = 0; j < len; j++)
        {
            // this is the concat part
            unsigned char new_message_array[48]; // i will xor it with S384
            memset(new_message_array, 0, 48);
            memcpy(new_message_array, padded_message, 16);
            memset(new_message_array + 16, 0, 32);

            ctx->S384[j] ^= new_message_array[j]; // this is the input for F384.
            f384(ctx->S384, ctx->S384, ctx);
        }
    }
}

void finalize(unsigned char *a, context *ctx)
{
    unsigned char h0, h1;
    memcpy(h0, ctx->S384, 16);
    f384(ctx->S384, ctx->S384, ctx);
    memcpy(h1, ctx->S384, 16);

    memcpy(a, h0, 16);
    memcpy(a + 16, h1, 16);
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

void pad_message(unsigned char *m, int length, unsigned char *padded_m)
{
    int i;
    memcpy(padded_m, m, length);
    padded_m[length] = 0x01; // Add a single "1" bit
    for (i = length + 1; i < block; i++)
    {
        padded_m[i] = 0x00; // Add zero bits to fill the block
    }
}
