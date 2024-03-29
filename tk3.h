/**
 * This is your SKINNY-tk3-Hash instance context, i.e., hash state.
 * You could put the following stuff inside here:
 * - chaining value
 * - chaining value offsets
 * - buffer offsets
 * - leprechaun gold
 * - ...
 */
typedef struct
{
    unsigned char rIV384[16];
    unsigned char cIV384[32];
    unsigned char S384[48];
    unsigned char tk1[16];
    unsigned char tk2[16];
    unsigned char tk3[16];
} context;

/* Implement the F function using skinny */
void f384(unsigned char *input, unsigned char *out, context *ctx);

/**
 * Implement the following API.
 * You can add your own functions above, but don't modify below this line.
 */

/* Initialize fresh context ctx. */
void init(context *ctx);

/* Under context ctx, incrementally process len bytes at a. */
void update(const unsigned char *a, int len, context *ctx);

/* Under context ctx, finalize the hash and place the digest at a. */
void finalize(unsigned char *a, context *ctx);
