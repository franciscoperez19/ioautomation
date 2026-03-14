#include "io_internal.h"
#include <stdlib.h>

IOContext* io_init() {
    struct IOContext *ctx = malloc(sizeof(struct IOContext));
    ctx->display = XOpenDisplay(NULL);
    ctx->root = DefaultRootWindow(ctx->display);
    return ctx;
}

void io_cleanup(IOContext *ctx) {
    XCloseDisplay(ctx->display);
    free(ctx);
}