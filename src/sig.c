#include <stddef.h>
#define _POSIX_C_SOURCE 1
#include <signal.h>

void init_interrupts_set(sigset_t *set) {
    sigemptyset(set);
    sigaddset(set, SIGHUP);
    sigaddset(set, SIGINT);
    sigaddset(set, SIGQUIT);
    sigaddset(set, SIGPIPE);
    sigaddset(set, SIGTERM);
}

void sig_block_interrupts() {
    sigset_t interrupts_set;

    init_interrupts_set(&interrupts_set);
    sigprocmask(SIG_BLOCK, &interrupts_set, NULL);
}

void sig_unblock_interrupts() {
    sigset_t interrupts_set;

    init_interrupts_set(&interrupts_set);
    sigprocmask(SIG_UNBLOCK, &interrupts_set, NULL);
}