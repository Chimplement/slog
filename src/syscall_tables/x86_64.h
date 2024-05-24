[  0] = {"read"                          , "%u, %p, %lu"                   },
[  1] = {"write"                         , "%u, %p, %lu"                   },
[  2] = {"open"                          , "%p, %i, %i"                    },
[  3] = {"close"                         , "%u"                            },
[  4] = {"newstat"                       , "%p, %p"                        },
[  5] = {"newfstat"                      , "%u, %p"                        },
[  6] = {"newlstat"                      , "%p, %p"                        },
[  7] = {"poll"                          , "%p, %u, %i"                    },
[  8] = {"lseek"                         , "%u, %i, %u"                    },
[  9] = {"mmap"                          , "%lu, %lu, %lu, %lu, %lu, %lu"  },
[ 10] = {"mprotect"                      , "%lu, %lu, %lu"                 },
[ 11] = {"munmap"                        , "%lu, %lu"                      },
[ 12] = {"brk"                           , "%lu"                           },
[ 13] = {"rt_sigaction"                  , "%i, %p, %p, %lu"               },
[ 14] = {"rt_sigprocmask"                , "%i, %p, %p, %lu"               },
[ 15] = {"rt_sigreturn"                  , ""                              },
[ 16] = {"ioctl"                         , "%u, %u, %lu"                   },
[ 17] = {"pread64"                       , "%u, %p, %lu, %i"               },
[ 18] = {"pwrite64"                      , "%u, %p, %lu, %i"               },
[ 19] = {"readv"                         , "%lu, %p, %lu"                  },
[ 20] = {"writev"                        , "%lu, %p, %lu"                  },
[ 21] = {"access"                        , "%p, %i"                        },
[ 22] = {"pipe"                          , "%p"                            },
[ 23] = {"select"                        , "%i, %p, %p, %p, %p"            },
[ 24] = {"sched_yield"                   , ""                              },
[ 25] = {"mremap"                        , "%lu, %lu, %lu, %lu, %lu"       },
[ 26] = {"msync"                         , "%lu, %lu, %i"                  },
[ 27] = {"mincore"                       , "%lu, %lu, %p"                  },
[ 28] = {"madvise"                       , "%lu, %lu, %i"                  },
[ 29] = {"shmget"                        , "%i, %lu, %i"                   },
[ 30] = {"shmat"                         , "%i, %p, %i"                    },
[ 31] = {"shmctl"                        , "%i, %i, %p"                    },
[ 32] = {"dup"                           , "%u"                            },
[ 33] = {"dup2"                          , "%u, %u"                        },
[ 34] = {"pause"                         , ""                              },
[ 35] = {"nanosleep"                     , "%p, %p"                        },
[ 36] = {"getitimer"                     , "%i, %p"                        },
[ 37] = {"alarm"                         , "%u"                            },
[ 38] = {"setitimer"                     , "%i, %p, %p"                    },
[ 39] = {"getpid"                        , ""                              },
[ 40] = {"sendfile64"                    , "%i, %i, %p, %lu"               },
[ 41] = {"socket"                        , "%i, %i, %i"                    },
[ 42] = {"connect"                       , "%i, %p, %i"                    },
[ 43] = {"accept"                        , "%i, %p, %p"                    },
[ 44] = {"sendto"                        , "%i, %p, %lu, %u, %p, %i"       },
[ 45] = {"recvfrom"                      , "%i, %p, %lu, %u, %p, %p"       },
[ 46] = {"sendmsg"                       , "%i, %p, %u"                    },
[ 47] = {"recvmsg"                       , "%i, %p, %u"                    },
[ 48] = {"shutdown"                      , "%i, %i"                        },
[ 49] = {"bind"                          , "%i, %p, %i"                    },
[ 50] = {"listen"                        , "%i, %i"                        },
[ 51] = {"getsockname"                   , "%i, %p, %p"                    },
[ 52] = {"getpeername"                   , "%i, %p, %p"                    },
[ 53] = {"socketpair"                    , "%i, %i, %i, %p"                },
[ 54] = {"setsockopt"                    , "%i, %i, %i, %p, %i"            },
[ 55] = {"getsockopt"                    , "%i, %i, %i, %p, %p"            },
[ 56] = {"clone"                         , "%lu, %lu, %p, %p, %lu"         },
[ 57] = {"fork"                          , ""                              },
[ 58] = {"vfork"                         , ""                              },
[ 59] = {"execve"                        , "%p, %p, %p"                    },
[ 60] = {"exit"                          , "%i"                            },
[ 61] = {"wait4"                         , "%i, %p, %i, %p"                },
[ 62] = {"kill"                          , "%i, %i"                        },
[ 63] = {"newuname"                      , "%p"                            },
[ 64] = {"semget"                        , "%i, %i, %i"                    },
[ 65] = {"semop"                         , "%i, %p, %u"                    },
[ 66] = {"semctl"                        , "%i, %i, %i, %lu"               },
[ 67] = {"shmdt"                         , "%p"                            },
[ 68] = {"msgget"                        , "%i, %i"                        },
[ 69] = {"msgsnd"                        , "%i, %p, %lu, %i"               },
[ 70] = {"msgrcv"                        , "%i, %p, %lu, %li, %i"          },
[ 71] = {"msgctl"                        , "%i, %i, %p"                    },
[ 72] = {"fcntl"                         , "%u, %u, %lu"                   },
[ 73] = {"flock"                         , "%u, %u"                        },
[ 74] = {"fsync"                         , "%u"                            },
[ 75] = {"fdatasync"                     , "%u"                            },
[ 76] = {"truncate"                      , "%p, %li"                       },
[ 77] = {"ftruncate"                     , "%u, %lu"                       },
[ 78] = {"getdents"                      , "%u, %p, %u"                    },
[ 79] = {"getcwd"                        , "%p, %lu"                       },
[ 80] = {"chdir"                         , "%p"                            },
[ 81] = {"fchdir"                        , "%u"                            },
[ 82] = {"rename"                        , "%p, %p"                        },
[ 83] = {"mkdir"                         , "%p, %i"                        },
[ 84] = {"rmdir"                         , "%p"                            },
[ 85] = {"creat"                         , "%p, %i"                        },
[ 86] = {"link"                          , "%p, %p"                        },
[ 87] = {"unlink"                        , "%p"                            },
[ 88] = {"symlink"                       , "%p, %p"                        },
[ 89] = {"readlink"                      , "%p, %p, %i"                    },
[ 90] = {"chmod"                         , "%p, %i"                        },
[ 91] = {"fchmod"                        , "%u, %i"                        },
[ 92] = {"chown"                         , "%p, %i, %i"                    },
[ 93] = {"fchown"                        , "%u, %i, %i"                    },
[ 94] = {"lchown"                        , "%p, %i, %i"                    },
[ 95] = {"umask"                         , "%i"                            },
[ 96] = {"gettimeofday"                  , "%p, %p"                        },
[ 97] = {"getrlimit"                     , "%u, %p"                        },
[ 98] = {"getrusage"                     , "%i, %p"                        },
[ 99] = {"sysinfo"                       , "%p"                            },
[100] = {"times"                         , "%p"                            },
[101] = {"ptrace"                        , "%li, %li, %lu, %lu"            },
[102] = {"getuid"                        , ""                              },
[103] = {"syslog"                        , "%i, %p, %i"                    },
[104] = {"getgid"                        , ""                              },
[105] = {"setuid"                        , "%i"                            },
[106] = {"setgid"                        , "%i"                            },
[107] = {"geteuid"                       , ""                              },
[108] = {"getegid"                       , ""                              },
[109] = {"setpgid"                       , "%i, %i"                        },
[110] = {"getppid"                       , ""                              },
[111] = {"getpgrp"                       , ""                              },
[112] = {"setsid"                        , ""                              },
[113] = {"setreuid"                      , "%i, %i"                        },
[114] = {"setregid"                      , "%i, %i"                        },
[115] = {"getgroups"                     , "%i, %p"                        },
[116] = {"setgroups"                     , "%i, %p"                        },
[117] = {"setresuid"                     , "%i, %i, %i"                    },
[118] = {"getresuid"                     , "%p, %p, %p"                    },
[119] = {"setresgid"                     , "%i, %i, %i"                    },
[120] = {"getresgid"                     , "%p, %p, %p"                    },
[121] = {"getpgid"                       , "%i"                            },
[122] = {"setfsuid"                      , "%i"                            },
[123] = {"setfsgid"                      , "%i"                            },
[124] = {"getsid"                        , "%i"                            },
[125] = {"capget"                        , "%i, %i"                        },
[126] = {"capset"                        , "%i, %i"                        },
[127] = {"rt_sigpending"                 , "%p, %lu"                       },
[128] = {"rt_sigtimedwait"               , "%p, %p, %p, %lu"               },
[129] = {"rt_sigqueueinfo"               , "%i, %i, %p"                    },
[130] = {"rt_sigsuspend"                 , "%p, %lu"                       },
[131] = {"sigaltstack"                   , "%p, %p"                        },
[132] = {"utime"                         , "%p, %p"                        },
[133] = {"mknod"                         , "%p, %i, %u"                    },
[135] = {"personality"                   , "%u"                            },
[136] = {"ustat"                         , "%u, %p"                        },
[137] = {"statfs"                        , "%p, %p"                        },
[138] = {"fstatfs"                       , "%u, %p"                        },
[139] = {"sysfs"                         , "%i, %lu, %lu"                  },
[140] = {"getpriority"                   , "%i, %i"                        },
[141] = {"setpriority"                   , "%i, %i, %i"                    },
[142] = {"sched_setparam"                , "%i, %p"                        },
[143] = {"sched_getparam"                , "%i, %p"                        },
[144] = {"sched_setscheduler"            , "%i, %i, %p"                    },
[145] = {"sched_getscheduler"            , "%i"                            },
[146] = {"sched_get_priority_max"        , "%i"                            },
[147] = {"sched_get_priority_min"        , "%i"                            },
[148] = {"sched_rr_get_interval"         , "%i, %p"                        },
[149] = {"mlock"                         , "%lu, %lu"                      },
[150] = {"munlock"                       , "%lu, %lu"                      },
[151] = {"mlockall"                      , "%i"                            },
[152] = {"munlockall"                    , ""                              },
[153] = {"vhangup"                       , ""                              },
[154] = {"modify_ldt"                    , "%i, %p, %lu"                   },
[155] = {"pivot_root"                    , "%p, %p"                        },
[157] = {"prctl"                         , "%i, %lu, %lu, %lu, %lu"        },
[158] = {"arch_prctl"                    , "%i, %lu"                       },
[159] = {"adjtimex"                      , "%p"                            },
[160] = {"setrlimit"                     , "%u, %p"                        },
[161] = {"chroot"                        , "%p"                            },
[162] = {"sync"                          , ""                              },
[163] = {"acct"                          , "%p"                            },
[164] = {"settimeofday"                  , "%p, %p"                        },
[165] = {"mount"                         , "%p, %p, %p, %lu, %p"           },
[166] = {"umount"                        , "%p, %i"                        },
[167] = {"swapon"                        , "%p, %i"                        },
[168] = {"swapoff"                       , "%p"                            },
[169] = {"reboot"                        , "%i, %i, %u, %p"                },
[170] = {"sethostname"                   , "%p, %i"                        },
[171] = {"setdomainname"                 , "%p, %i"                        },
[172] = {"iopl"                          , "%u"                            },
[173] = {"ioperm"                        , "%lu, %lu, %i"                  },
[175] = {"init_module"                   , "%p, %lu, %p"                   },
[176] = {"delete_module"                 , "%p, %u"                        },
[179] = {"quotactl"                      , "%u, %p, %i, %p"                },
[186] = {"gettid"                        , ""                              },
[187] = {"readahead"                     , "%i, %i, %lu"                   },
[188] = {"setxattr"                      , "%p, %p, %p, %lu, %i"           },
[189] = {"lsetxattr"                     , "%p, %p, %p, %lu, %i"           },
[190] = {"fsetxattr"                     , "%i, %p, %p, %lu, %i"           },
[191] = {"getxattr"                      , "%p, %p, %p, %lu"               },
[192] = {"lgetxattr"                     , "%p, %p, %p, %lu"               },
[193] = {"fgetxattr"                     , "%i, %p, %p, %lu"               },
[194] = {"listxattr"                     , "%p, %p, %lu"                   },
[195] = {"llistxattr"                    , "%p, %p, %lu"                   },
[196] = {"flistxattr"                    , "%i, %p, %lu"                   },
[197] = {"removexattr"                   , "%p, %p"                        },
[198] = {"lremovexattr"                  , "%p, %p"                        },
[199] = {"fremovexattr"                  , "%i, %p"                        },
[200] = {"tkill"                         , "%i, %i"                        },
[201] = {"time"                          , "%p"                            },
[202] = {"futex"                         , "%p, %i, %u, %p, %p, %u"        },
[203] = {"sched_setaffinity"             , "%i, %u, %p"                    },
[204] = {"sched_getaffinity"             , "%i, %u, %p"                    },
[206] = {"io_setup"                      , "%u, %p"                        },
[207] = {"io_destroy"                    , "%i"                            },
[208] = {"io_getevents"                  , "%i, %li, %li, %p, %p"          },
[209] = {"io_submit"                     , "%i, %li, %p"                   },
[210] = {"io_cancel"                     , "%i, %p, %p"                    },
[213] = {"epoll_create"                  , "%i"                            },
[216] = {"remap_file_pages"              , "%lu, %lu, %lu, %lu, %lu"       },
[217] = {"getdents64"                    , "%u, %p, %u"                    },
[218] = {"set_tid_address"               , "%p"                            },
[219] = {"restart_syscall"               , ""                              },
[220] = {"semtimedop"                    , "%i, %p, %u, %p"                },
[221] = {"fadvise64"                     , "%i, %i, %i, %i"                },
[222] = {"timer_create"                  , "%i, %p, %p"                    },
[223] = {"timer_settime"                 , "%i, %i, %p, %p"                },
[224] = {"timer_gettime"                 , "%i, %p"                        },
[225] = {"timer_getoverrun"              , "%i"                            },
[226] = {"timer_delete"                  , "%i"                            },
[227] = {"clock_settime"                 , "%i, %p"                        },
[228] = {"clock_gettime"                 , "%i, %p"                        },
[229] = {"clock_getres"                  , "%i, %p"                        },
[230] = {"clock_nanosleep"               , "%i, %i, %p, %p"                },
[231] = {"exit_group"                    , "%i"                            },
[232] = {"epoll_wait"                    , "%i, %p, %i, %i"                },
[233] = {"epoll_ctl"                     , "%i, %i, %i, %p"                },
[234] = {"tgkill"                        , "%i, %i, %i"                    },
[235] = {"utimes"                        , "%p, %p"                        },
[237] = {"mbind"                         , "%lu, %lu, %lu, %p, %lu, %u"    },
[238] = {"set_mempolicy"                 , "%i, %p, %lu"                   },
[239] = {"get_mempolicy"                 , "%p, %p, %lu, %lu, %lu"         },
[240] = {"mq_open"                       , "%p, %i, %i, %p"                },
[241] = {"mq_unlink"                     , "%p"                            },
[242] = {"mq_timedsend"                  , "%i, %p, %lu, %u, %p"           },
[243] = {"mq_timedreceive"               , "%i, %p, %lu, %p, %p"           },
[244] = {"mq_notify"                     , "%i, %p"                        },
[245] = {"mq_getsetattr"                 , "%i, %p, %p"                    },
[246] = {"kexec_load"                    , "%lu, %lu, %p, %lu"             },
[247] = {"waitid"                        , "%i, %i, %p, %i, %p"            },
[248] = {"add_key"                       , "%p, %p, %p, %lu, %i"           },
[249] = {"request_key"                   , "%p, %p, %p, %i"                },
[250] = {"keyctl"                        , "%i, %lu, %lu, %lu, %lu"        },
[251] = {"ioprio_set"                    , "%i, %i, %i"                    },
[252] = {"ioprio_get"                    , "%i, %i"                        },
[253] = {"inotify_init"                  , ""                              },
[254] = {"inotify_add_watch"             , "%i, %p, %u"                    },
[255] = {"inotify_rm_watch"              , "%i, %i"                        },
[256] = {"migrate_pages"                 , "%i, %lu, %p, %p"               },
[257] = {"openat"                        , "%i, %p, %i, %i"                },
[258] = {"mkdirat"                       , "%i, %p, %i"                    },
[259] = {"mknodat"                       , "%i, %p, %i, %u"                },
[260] = {"fchownat"                      , "%i, %p, %i, %i, %i"            },
[261] = {"futimesat"                     , "%i, %p, %p"                    },
[262] = {"newfstatat"                    , "%i, %p, %p, %i"                },
[263] = {"unlinkat"                      , "%i, %p, %i"                    },
[264] = {"renameat"                      , "%i, %p, %i, %p"                },
[265] = {"linkat"                        , "%i, %p, %i, %p, %i"            },
[266] = {"symlinkat"                     , "%p, %i, %p"                    },
[267] = {"readlinkat"                    , "%i, %p, %p, %i"                },
[268] = {"fchmodat"                      , "%i, %p, %i"                    },
[269] = {"faccessat"                     , "%i, %p, %i"                    },
[270] = {"pselect6"                      , "%i, %p, %p, %p, %p, %p"        },
[271] = {"ppoll"                         , "%p, %u, %p, %p, %lu"           },
[272] = {"unshare"                       , "%lu"                           },
[273] = {"set_robust_list"               , "%p, %lu"                       },
[274] = {"get_robust_list"               , "%i, %p, %p"                    },
[275] = {"splice"                        , "%i, %p, %i, %p, %lu, %u"       },
[276] = {"tee"                           , "%i, %i, %lu, %u"               },
[277] = {"sync_file_range"               , "%i, %i, %i, %u"                },
[278] = {"vmsplice"                      , "%i, %p, %lu, %u"               },
[279] = {"move_pages"                    , "%i, %lu, %p, %p, %p, %i"       },
[280] = {"utimensat"                     , "%i, %p, %p, %i"                },
[281] = {"epoll_pwait"                   , "%i, %p, %i, %i, %p, %lu"       },
[282] = {"signalfd"                      , "%i, %p, %lu"                   },
[283] = {"timerfd_create"                , "%i, %i"                        },
[284] = {"eventfd"                       , "%u"                            },
[285] = {"fallocate"                     , "%i, %i, %i, %i"                },
[286] = {"timerfd_settime"               , "%i, %i, %p, %p"                },
[287] = {"timerfd_gettime"               , "%i, %p"                        },
[288] = {"accept4"                       , "%i, %p, %p, %i"                },
[289] = {"signalfd4"                     , "%i, %p, %lu, %i"               },
[290] = {"eventfd2"                      , "%u, %i"                        },
[291] = {"epoll_create1"                 , "%i"                            },
[292] = {"dup3"                          , "%u, %u, %i"                    },
[293] = {"pipe2"                         , "%p, %i"                        },
[294] = {"inotify_init1"                 , "%i"                            },
[295] = {"preadv"                        , "%lu, %p, %lu, %lu, %lu"        },
[296] = {"pwritev"                       , "%lu, %p, %lu, %lu, %lu"        },
[297] = {"rt_tgsigqueueinfo"             , "%i, %i, %i, %p"                },
[298] = {"perf_event_open"               , "%p, %i, %i, %i, %lu"           },
[299] = {"recvmmsg"                      , "%i, %p, %u, %u, %p"            },
[300] = {"fanotify_init"                 , "%u, %u"                        },
[301] = {"fanotify_mark"                 , "%i, %u, %lu, %i, %p"           },
[302] = {"prlimit64"                     , "%i, %u, %p, %p"                },
[303] = {"name_to_handle_at"             , "%i, %p, %p, %p, %i"            },
[304] = {"open_by_handle_at"             , "%i, %p, %i"                    },
[305] = {"clock_adjtime"                 , "%i, %p"                        },
[306] = {"syncfs"                        , "%i"                            },
[307] = {"sendmmsg"                      , "%i, %p, %u, %u"                },
[308] = {"setns"                         , "%i, %i"                        },
[309] = {"getcpu"                        , "%p, %p, %p"                    },
[310] = {"process_vm_readv"              , "%i, %p, %lu, %p, %lu, %lu"     },
[311] = {"process_vm_writev"             , "%i, %p, %lu, %p, %lu, %lu"     },
[312] = {"kcmp"                          , "%i, %i, %i, %lu, %lu"          },
[313] = {"finit_module"                  , "%i, %p, %i"                    },
[314] = {"sched_setattr"                 , "%i, %p, %u"                    },
[315] = {"sched_getattr"                 , "%i, %p, %u, %u"                },
[316] = {"renameat2"                     , "%i, %p, %i, %p, %u"            },
[317] = {"seccomp"                       , "%u, %u, %p"                    },
[318] = {"getrandom"                     , "%p, %lu, %u"                   },
[319] = {"memfd_create"                  , "%p, %u"                        },
[320] = {"kexec_file_load"               , "%i, %i, %lu, %p, %lu"          },
[321] = {"bpf"                           , "%i, %p, %u"                    },
[322] = {"execveat"                      , "%i, %p, %p, %p, %i"            },
[323] = {"userfaultfd"                   , "%i"                            },
[324] = {"membarrier"                    , "%i, %u, %i"                    },
[325] = {"mlock2"                        , "%lu, %lu, %i"                  },
[326] = {"copy_file_range"               , "%i, %p, %i, %p, %lu, %u"       },
[327] = {"preadv2"                       , "%lu, %p, %lu, %lu, %lu, %i"    },
[328] = {"pwritev2"                      , "%lu, %p, %lu, %lu, %lu, %i"    },
[329] = {"pkey_mprotect"                 , "%lu, %lu, %lu, %i"             },
[330] = {"pkey_alloc"                    , "%lu, %lu"                      },
[331] = {"pkey_free"                     , "%i"                            },
[332] = {"statx"                         , "%i, %p, %u, %u, %p"            },
[333] = {"io_pgetevents"                 , "%i, %li, %li, %p, %p, %p"      },
[334] = {"rseq"                          , "%p, %u, %i, %u"                },
[424] = {"pidfd_send_signal"             , "%i, %i, %p, %u"                },
[425] = {"io_uring_setup"                , "%u, %p"                        },
[426] = {"io_uring_enter"                , "%u, %u, %u, %u, %p, %lu"       },
[427] = {"io_uring_register"             , "%u, %u, %p, %u"                },
[428] = {"open_tree"                     , "%i, %p, %u"                    },
[429] = {"move_mount"                    , "%i, %p, %i, %p, %u"            },
[430] = {"fsopen"                        , "%p, %u"                        },
[431] = {"fsconfig"                      , "%i, %u, %p, %p, %i"            },
[432] = {"fsmount"                       , "%i, %u, %u"                    },
[433] = {"fspick"                        , "%i, %p, %u"                    },
[434] = {"pidfd_open"                    , "%i, %u"                        },
[435] = {"clone3"                        , "%p, %lu"                       },
[436] = {"close_range"                   , "%u, %u, %u"                    },
[437] = {"openat2"                       , "%i, %p, %p, %lu"               },
[438] = {"pidfd_getfd"                   , "%i, %i, %u"                    },
[439] = {"faccessat2"                    , "%i, %p, %i, %i"                },
[440] = {"process_madvise"               , "%i, %p, %lu, %i, %u"           },
[441] = {"epoll_pwait2"                  , "%i, %p, %i, %p, %p, %lu"       },
[442] = {"mount_setattr"                 , "%i, %p, %u, %p, %lu"           },
[443] = {"quotactl_fd"                   , "%u, %u, %i, %p"                },
[444] = {"landlock_create_ruleset"       , "%p, %lu, %u"                   },
[445] = {"landlock_add_rule"             , "%i, %i, %p, %u"                },
[446] = {"landlock_restrict_self"        , "%i, %u"                        },
[447] = {"memfd_secret"                  , "%u"                            },
[448] = {"process_mrelease"              , "%i, %u"                        },
[449] = {"futex_waitv"                   , "%p, %u, %u, %p, %i"            },
[450] = {"set_mempolicy_home_node"       , "%lu, %lu, %lu, %lu"            },
[451] = {"cachestat"                     , "%u, %p, %p, %u"                },
[452] = {"fchmodat2"                     , "%i, %p, %i, %u"                },
[453] = {"map_shadow_stack"              , "%lu, %lu, %u"                  },
[454] = {"futex_wake"                    , "%p, %lu, %i, %u"               },
[455] = {"futex_wait"                    , "%p, %lu, %lu, %u, %p, %i"      },
[456] = {"futex_requeue"                 , "%p, %u, %i, %i"                },
[457] = {"statmount"                     , "%p, %p, %lu, %u"               },
[458] = {"listmount"                     , "%p, %p, %lu, %u"               },
[459] = {"lsm_get_self_attr"             , "%u, %p, %p, %u"                },
[460] = {"lsm_set_self_attr"             , "%u, %p, %u, %u"                },
[461] = {"lsm_list_modules"              , "%p, %p, %u"                    },
