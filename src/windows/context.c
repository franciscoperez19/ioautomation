#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0A00
#endif
#include "../io_internal.h"


IOContext* io_init() {
    struct IOContext *ctx = malloc(sizeof(struct IOContext));
    if(ctx == NULL) return NULL;
    if (!SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2)){
        ctx->lasterror = GetLastError();
    }
    else ctx->lasterror = 0;
    
    return ctx;
}

void io_cleanup(IOContext *ctx) {
    free(ctx);
}