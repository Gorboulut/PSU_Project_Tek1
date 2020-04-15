/*
** EPITECH PROJECT, 2020
** navy
** File description:
** connect function for navy
*/
#include "sources/lib/my/my.h"

void handler(int sign, siginfo_t *info, void *ucontext)
{
    UNUSED(ucontext);
    sig.pid = info->si_pid;
    sig.sig1 += (sign == 10) ? 1 : 0;
    sig.sig2 += (sign == 12) ? 1 : 0;
}

void helper_navy(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     first_player_pid: only for the 2nd player. pid of ");
    my_putstr("the first player.\n");
    my_putstr("     navy_positions: file representing the positions of ");
    my_putstr("the ships.\n");
}

void connect_pid(int pid)
{
    struct sigaction sa = { 0 };

    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = &handler;
    sigaction(pid, &sa, NULL);
}
