[  0] = {"restart_syscall"               , ""                              , 0, 0, 0},
[  1] = {"exit"                          , "%i"                            , 0, 0, 0},
[  2] = {"fork"                          , ""                              , 0, 0, 0},
[  3] = {"read"                          , "%u, %p, %lu"                   , 0, 0, 0},
[  4] = {"write"                         , "%u, %p, %lu"                   , 0, 0, 0},
[  5] = {"open"                          , "%p, %i, %i"                    , 0, 0, 0},
[  6] = {"close"                         , "%u"                            , 0, 0, 0},
[  7] = {"waitpid"                       , "%i, %p, %i"                    , 0, 0, 0},
[  8] = {"creat"                         , "%p, %i"                        , 0, 0, 0},
[  9] = {"link"                          , "%p, %p"                        , 0, 0, 0},
[ 10] = {"unlink"                        , "%p"                            , 0, 0, 0},
[ 11] = {"execve"                        , "%p, %p, %p"                    , 0, 0, 0},
[ 12] = {"chdir"                         , "%p"                            , 0, 0, 0},
[ 13] = {"time"                          , "%p"                            , 0, 0, 0},
[ 14] = {"mknod"                         , "%p, %i, %u"                    , 0, 0, 0},
[ 15] = {"chmod"                         , "%p, %i"                        , 0, 0, 0},
[ 16] = {"lchown16"                      , "%p, %i, %i"                    , 0, 0, 0},
[ 18] = {"stat"                          , "%p, %p"                        , 0, 0, 0},
[ 19] = {"lseek"                         , "%u, %i, %u"                    , 0, 0, 0},
[ 20] = {"getpid"                        , ""                              , 0, 0, 0},
[ 21] = {"mount"                         , "%p, %p, %p, %lu, %p"           , 0, 0, 0},
[ 22] = {"oldumount"                     , "%p"                            , 0, 0, 0},
[ 23] = {"setuid16"                      , "%i"                            , 0, 0, 0},
[ 24] = {"getuid16"                      , ""                              , 0, 0, 0},
[ 25] = {"stime"                         , "%p"                            , 0, 0, 0},
[ 26] = {"ptrace"                        , "%li, %li, %lu, %lu"            , 0, 0, 0},
[ 27] = {"alarm"                         , "%u"                            , 0, 0, 0},
[ 28] = {"fstat"                         , "%u, %p"                        , 0, 0, 0},
[ 29] = {"pause"                         , ""                              , 0, 0, 0},
[ 30] = {"utime"                         , "%p, %p"                        , 0, 0, 0},
[ 33] = {"access"                        , "%p, %i"                        , 0, 0, 0},
[ 34] = {"nice"                          , "%i"                            , 0, 0, 0},
[ 36] = {"sync"                          , ""                              , 0, 0, 0},
[ 37] = {"kill"                          , "%i, %i"                        , 0, 0, 0},
[ 38] = {"rename"                        , "%p, %p"                        , 0, 0, 0},
[ 39] = {"mkdir"                         , "%p, %i"                        , 0, 0, 0},
[ 40] = {"rmdir"                         , "%p"                            , 0, 0, 0},
[ 41] = {"dup"                           , "%u"                            , 0, 0, 0},
[ 42] = {"pipe"                          , "%p"                            , 0, 0, 0},
[ 43] = {"times"                         , "%p"                            , 0, 0, 0},
[ 45] = {"brk"                           , "%lu"                           , 0, 0, 0},
[ 46] = {"setgid16"                      , "%i"                            , 0, 0, 0},
[ 47] = {"getgid16"                      , ""                              , 0, 0, 0},
[ 48] = {"signal"                        , "%i, %i"                        , 0, 0, 0},
[ 49] = {"geteuid16"                     , ""                              , 0, 0, 0},
[ 50] = {"getegid16"                     , ""                              , 0, 0, 0},
[ 51] = {"acct"                          , "%p"                            , 0, 0, 0},
[ 52] = {"umount"                        , "%p, %i"                        , 0, 0, 0},
[ 54] = {"ioctl"                         , "%u, %u, %lu"                   , 0, 0, 0},
[ 55] = {"fcntl"                         , "%u, %u, %lu"                   , 0, 0, 0},
[ 57] = {"setpgid"                       , "%i, %i"                        , 0, 0, 0},
[ 59] = {"olduname"                      , "%p"                            , 0, 0, 0},
[ 60] = {"umask"                         , "%i"                            , 0, 0, 0},
[ 61] = {"chroot"                        , "%p"                            , 0, 0, 0},
[ 62] = {"ustat"                         , "%u, %p"                        , 0, 0, 0},
[ 63] = {"dup2"                          , "%u, %u"                        , 0, 0, 0},
[ 64] = {"getppid"                       , ""                              , 0, 0, 0},
[ 65] = {"getpgrp"                       , ""                              , 0, 0, 0},
[ 66] = {"setsid"                        , ""                              , 0, 0, 0},
[ 67] = {"sigaction"                     , "%i, %p, %p"                    , 0, 0, 0},
[ 68] = {"sgetmask"                      , ""                              , 0, 0, 0},
[ 69] = {"ssetmask"                      , "%i"                            , 0, 0, 0},
[ 70] = {"setreuid16"                    , "%i, %i"                        , 0, 0, 0},
[ 71] = {"setregid16"                    , "%i, %i"                        , 0, 0, 0},
[ 72] = {"sigsuspend"                    , "%i, %i, %i"                    , 0, 0, 0},
[ 73] = {"sigpending"                    , "%p"                            , 0, 0, 0},
[ 74] = {"sethostname"                   , "%p, %i"                        , 0, 0, 0},
[ 75] = {"setrlimit"                     , "%u, %p"                        , 0, 0, 0},
[ 76] = {"getrlimit"                     , "%u, %p"                        , 0, 0, 0},
[ 77] = {"getrusage"                     , "%i, %p"                        , 0, 0, 0},
[ 78] = {"gettimeofday"                  , "%p, %p"                        , 0, 0, 0},
[ 79] = {"settimeofday"                  , "%p, %p"                        , 0, 0, 0},
[ 80] = {"getgroups16"                   , "%i, %p"                        , 0, 0, 0},
[ 81] = {"setgroups16"                   , "%i, %p"                        , 0, 0, 0},
[ 82] = {"select"                        , "%p"                            , 0, 0, 0},
[ 83] = {"symlink"                       , "%p, %p"                        , 0, 0, 0},
[ 84] = {"lstat"                         , "%p, %p"                        , 0, 0, 0},
[ 85] = {"readlink"                      , "%p, %p, %i"                    , 0, 0, 0},
[ 86] = {"uselib"                        , "%p"                            , 0, 0, 0},
[ 87] = {"swapon"                        , "%p, %i"                        , 0, 0, 0},
[ 88] = {"reboot"                        , "%i, %i, %u, %p"                , 0, 0, 0},
[ 89] = {"readdir"                       , "%u, %p, %u"                    , 0, 0, 0},
[ 90] = {"mmap"                          , "%p"                            , 0, 0, 0},
[ 91] = {"munmap"                        , "%lu, %lu"                      , 0, 0, 0},
[ 92] = {"truncate"                      , "%p, %li"                       , 0, 0, 0},
[ 93] = {"ftruncate"                     , "%u, %lu"                       , 0, 0, 0},
[ 94] = {"fchmod"                        , "%u, %i"                        , 0, 0, 0},
[ 95] = {"fchown16"                      , "%u, %i, %i"                    , 0, 0, 0},
[ 96] = {"getpriority"                   , "%i, %i"                        , 0, 0, 0},
[ 97] = {"setpriority"                   , "%i, %i, %i"                    , 0, 0, 0},
[ 99] = {"statfs"                        , "%p, %p"                        , 0, 0, 0},
[100] = {"fstatfs"                       , "%u, %p"                        , 0, 0, 0},
[101] = {"ioperm"                        , "%lu, %lu, %i"                  , 0, 0, 0},
[102] = {"socketcall"                    , "%i, %p"                        , 0, 0, 0},
[103] = {"syslog"                        , "%i, %p, %i"                    , 0, 0, 0},
[104] = {"setitimer"                     , "%i, %p, %p"                    , 0, 0, 0},
[105] = {"getitimer"                     , "%i, %p"                        , 0, 0, 0},
[106] = {"newstat"                       , "%p, %p"                        , 0, 0, 0},
[107] = {"newlstat"                      , "%p, %p"                        , 0, 0, 0},
[108] = {"newfstat"                      , "%u, %p"                        , 0, 0, 0},
[109] = {"uname"                         , "%p"                            , 0, 0, 0},
[110] = {"iopl"                          , "%u"                            , 0, 0, 0},
[111] = {"vhangup"                       , ""                              , 0, 0, 0},
[113] = {"vm86old"                       , "%p"                            , 0, 0, 0},
[114] = {"wait4"                         , "%i, %p, %i, %p"                , 0, 0, 0},
[115] = {"swapoff"                       , "%p"                            , 0, 0, 0},
[116] = {"sysinfo"                       , "%p"                            , 0, 0, 0},
[117] = {"ipc"                           , "%u, %i, %lu, %lu, %p, %li"     , 0, 0, 0},
[118] = {"fsync"                         , "%u"                            , 0, 0, 0},
[119] = {"sigreturn"                     , ""                              , 0, 0, 0},
[120] = {"clone"                         , "%lu, %lu, %p, %lu, %p"         , 0, 0, 0},
[121] = {"setdomainname"                 , "%p, %i"                        , 0, 0, 0},
[122] = {"newuname"                      , "%p"                            , 0, 0, 0},
[123] = {"modify_ldt"                    , "%i, %p, %lu"                   , 0, 0, 0},
[124] = {"adjtimex"                      , "%p"                            , 0, 0, 0},
[125] = {"mprotect"                      , "%lu, %lu, %lu"                 , 0, 0, 0},
[126] = {"sigprocmask"                   , "%i, %p, %p"                    , 0, 0, 0},
[128] = {"init_module"                   , "%p, %lu, %p"                   , 0, 0, 0},
[129] = {"delete_module"                 , "%p, %u"                        , 0, 0, 0},
[131] = {"quotactl"                      , "%u, %p, %i, %p"                , 0, 0, 0},
[132] = {"getpgid"                       , "%i"                            , 0, 0, 0},
[133] = {"fchdir"                        , "%u"                            , 0, 0, 0},
[135] = {"sysfs"                         , "%i, %lu, %lu"                  , 0, 0, 0},
[136] = {"personality"                   , "%u"                            , 0, 0, 0},
[138] = {"setfsuid16"                    , "%i"                            , 0, 0, 0},
[139] = {"setfsgid16"                    , "%i"                            , 0, 0, 0},
[140] = {"llseek"                        , "%u, %lu, %lu, %p, %u"          , 0, 0, 0},
[141] = {"getdents"                      , "%u, %p, %u"                    , 0, 0, 0},
[142] = {"select"                        , "%i, %p, %p, %p, %p"            , 0, 0, 0},
[143] = {"flock"                         , "%u, %u"                        , 0, 0, 0},
[144] = {"msync"                         , "%lu, %lu, %i"                  , 0, 0, 0},
[145] = {"readv"                         , "%lu, %p, %lu"                  , 0, 0, 0},
[146] = {"writev"                        , "%lu, %p, %lu"                  , 0, 0, 0},
[147] = {"getsid"                        , "%i"                            , 0, 0, 0},
[148] = {"fdatasync"                     , "%u"                            , 0, 0, 0},
[150] = {"mlock"                         , "%lu, %lu"                      , 0, 0, 0},
[151] = {"munlock"                       , "%lu, %lu"                      , 0, 0, 0},
[152] = {"mlockall"                      , "%i"                            , 0, 0, 0},
[153] = {"munlockall"                    , ""                              , 0, 0, 0},
[154] = {"sched_setparam"                , "%i, %p"                        , 0, 0, 0},
[155] = {"sched_getparam"                , "%i, %p"                        , 0, 0, 0},
[156] = {"sched_setscheduler"            , "%i, %i, %p"                    , 0, 0, 0},
[157] = {"sched_getscheduler"            , "%i"                            , 0, 0, 0},
[158] = {"sched_yield"                   , ""                              , 0, 0, 0},
[159] = {"sched_get_priority_max"        , "%i"                            , 0, 0, 0},
[160] = {"sched_get_priority_min"        , "%i"                            , 0, 0, 0},
[161] = {"sched_rr_get_interval"         , "%i, %p"                        , 0, 0, 0},
[162] = {"nanosleep"                     , "%p, %p"                        , 0, 0, 0},
[163] = {"mremap"                        , "%lu, %lu, %lu, %lu, %lu"       , 0, 0, 0},
[164] = {"setresuid16"                   , "%i, %i, %i"                    , 0, 0, 0},
[165] = {"getresuid16"                   , "%p, %p, %p"                    , 0, 0, 0},
[166] = {"vm86"                          , "%lu, %lu"                      , 0, 0, 0},
[168] = {"poll"                          , "%p, %u, %i"                    , 0, 0, 0},
[170] = {"setresgid16"                   , "%i, %i, %i"                    , 0, 0, 0},
[171] = {"getresgid16"                   , "%p, %p, %p"                    , 0, 0, 0},
[172] = {"prctl"                         , "%i, %lu, %lu, %lu, %lu"        , 0, 0, 0},
[173] = {"rt_sigreturn"                  , ""                              , 0, 0, 0},
[174] = {"rt_sigaction"                  , "%i, %p, %p, %lu"               , 0, 0, 0},
[175] = {"rt_sigprocmask"                , "%i, %p, %p, %lu"               , 0, 0, 0},
[176] = {"rt_sigpending"                 , "%p, %lu"                       , 0, 0, 0},
[177] = {"rt_sigtimedwait"               , "%p, %p, %p, %lu"               , 0, 0, 0},
[178] = {"rt_sigqueueinfo"               , "%i, %i, %p"                    , 0, 0, 0},
[179] = {"rt_sigsuspend"                 , "%p, %lu"                       , 0, 0, 0},
[180] = {"pread64"                       , "%u, %p, %u, %u, %u"            , 0, 0, 0},
[181] = {"pwrite64"                      , "%u, %p, %u, %u, %u"            , 0, 0, 0},
[182] = {"chown16"                       , "%p, %i, %i"                    , 0, 0, 0},
[183] = {"getcwd"                        , "%p, %lu"                       , 0, 0, 0},
[184] = {"capget"                        , "%i, %i"                        , 0, 0, 0},
[185] = {"capset"                        , "%i, %i"                        , 0, 0, 0},
[186] = {"sigaltstack"                   , "%p, %p"                        , 0, 0, 0},
[187] = {"sendfile"                      , "%i, %i, %p, %lu"               , 0, 0, 0},
[190] = {"vfork"                         , ""                              , 0, 0, 0},
[191] = {"getrlimit"                     , "%u, %p"                        , 0, 0, 0},
[192] = {"mmap_pgoff"                    , "%lu, %lu, %lu, %lu, %lu, %lu"  , 0, 0, 0},
[193] = {"truncate64"                    , "%p, %lu, %lu"                  , 0, 0, 0},
[194] = {"ftruncate64"                   , "%u, %lu, %lu"                  , 0, 0, 0},
[195] = {"stat64"                        , "%p, %p"                        , 0, 0, 0},
[196] = {"lstat64"                       , "%p, %p"                        , 0, 0, 0},
[197] = {"fstat64"                       , "%lu, %p"                       , 0, 0, 0},
[198] = {"lchown"                        , "%p, %i, %i"                    , 0, 0, 0},
[199] = {"getuid"                        , ""                              , 0, 0, 0},
[200] = {"getgid"                        , ""                              , 0, 0, 0},
[201] = {"geteuid"                       , ""                              , 0, 0, 0},
[202] = {"getegid"                       , ""                              , 0, 0, 0},
[203] = {"setreuid"                      , "%i, %i"                        , 0, 0, 0},
[204] = {"setregid"                      , "%i, %i"                        , 0, 0, 0},
[205] = {"getgroups"                     , "%i, %p"                        , 0, 0, 0},
[206] = {"setgroups"                     , "%i, %p"                        , 0, 0, 0},
[207] = {"fchown"                        , "%u, %i, %i"                    , 0, 0, 0},
[208] = {"setresuid"                     , "%i, %i, %i"                    , 0, 0, 0},
[209] = {"getresuid"                     , "%p, %p, %p"                    , 0, 0, 0},
[210] = {"setresgid"                     , "%i, %i, %i"                    , 0, 0, 0},
[211] = {"getresgid"                     , "%p, %p, %p"                    , 0, 0, 0},
[212] = {"chown"                         , "%p, %i, %i"                    , 0, 0, 0},
[213] = {"setuid"                        , "%i"                            , 0, 0, 0},
[214] = {"setgid"                        , "%i"                            , 0, 0, 0},
[215] = {"setfsuid"                      , "%i"                            , 0, 0, 0},
[216] = {"setfsgid"                      , "%i"                            , 0, 0, 0},
[217] = {"pivot_root"                    , "%p, %p"                        , 0, 0, 0},
[218] = {"mincore"                       , "%lu, %lu, %p"                  , 0, 0, 0},
[219] = {"madvise"                       , "%lu, %lu, %i"                  , 0, 0, 0},
[220] = {"getdents64"                    , "%u, %p, %u"                    , 0, 0, 0},
[221] = {"fcntl64"                       , "%u, %u, %lu"                   , 0, 0, 0},
[224] = {"gettid"                        , ""                              , 0, 0, 0},
[225] = {"readahead"                     , "%i, %u, %u, %lu"               , 0, 0, 0},
[226] = {"setxattr"                      , "%p, %p, %p, %lu, %i"           , 0, 0, 0},
[227] = {"lsetxattr"                     , "%p, %p, %p, %lu, %i"           , 0, 0, 0},
[228] = {"fsetxattr"                     , "%i, %p, %p, %lu, %i"           , 0, 0, 0},
[229] = {"getxattr"                      , "%p, %p, %p, %lu"               , 0, 0, 0},
[230] = {"lgetxattr"                     , "%p, %p, %p, %lu"               , 0, 0, 0},
[231] = {"fgetxattr"                     , "%i, %p, %p, %lu"               , 0, 0, 0},
[232] = {"listxattr"                     , "%p, %p, %lu"                   , 0, 0, 0},
[233] = {"llistxattr"                    , "%p, %p, %lu"                   , 0, 0, 0},
[234] = {"flistxattr"                    , "%i, %p, %lu"                   , 0, 0, 0},
[235] = {"removexattr"                   , "%p, %p"                        , 0, 0, 0},
[236] = {"lremovexattr"                  , "%p, %p"                        , 0, 0, 0},
[237] = {"fremovexattr"                  , "%i, %p"                        , 0, 0, 0},
[238] = {"tkill"                         , "%i, %i"                        , 0, 0, 0},
[239] = {"sendfile64"                    , "%i, %i, %p, %lu"               , 0, 0, 0},
[240] = {"futex"                         , "%p, %i, %u, %p, %p, %u"        , 0, 0, 0},
[241] = {"sched_setaffinity"             , "%i, %u, %p"                    , 0, 0, 0},
[242] = {"sched_getaffinity"             , "%i, %u, %p"                    , 0, 0, 0},
[243] = {"set_thread_area"               , "%p"                            , 0, 0, 0},
[244] = {"get_thread_area"               , "%p"                            , 0, 0, 0},
[245] = {"io_setup"                      , "%u, %p"                        , 0, 0, 0},
[246] = {"io_destroy"                    , "%i"                            , 0, 0, 0},
[247] = {"io_getevents"                  , "%u, %i, %i, %p, %p"            , 0, 0, 0},
[248] = {"io_submit"                     , "%i, %li, %p"                   , 0, 0, 0},
[249] = {"io_cancel"                     , "%i, %p, %p"                    , 0, 0, 0},
[250] = {"fadvise64"                     , "%i, %u, %u, %lu, %i"           , 0, 0, 0},
[252] = {"exit_group"                    , "%i"                            , 0, 0, 0},
[254] = {"epoll_create"                  , "%i"                            , 0, 0, 0},
[255] = {"epoll_ctl"                     , "%i, %i, %i, %p"                , 0, 0, 0},
[256] = {"epoll_wait"                    , "%i, %p, %i, %i"                , 0, 0, 0},
[257] = {"remap_file_pages"              , "%lu, %lu, %lu, %lu, %lu"       , 0, 0, 0},
[258] = {"set_tid_address"               , "%p"                            , 0, 0, 0},
[259] = {"timer_create"                  , "%i, %p, %p"                    , 0, 0, 0},
[260] = {"timer_settime"                 , "%i, %i, %p, %p"                , 0, 0, 0},
[261] = {"timer_gettime"                 , "%i, %p"                        , 0, 0, 0},
[262] = {"timer_getoverrun"              , "%i"                            , 0, 0, 0},
[263] = {"timer_delete"                  , "%i"                            , 0, 0, 0},
[264] = {"clock_settime"                 , "%i, %p"                        , 0, 0, 0},
[265] = {"clock_gettime"                 , "%i, %p"                        , 0, 0, 0},
[266] = {"clock_getres"                  , "%i, %p"                        , 0, 0, 0},
[267] = {"clock_nanosleep"               , "%i, %i, %p, %p"                , 0, 0, 0},
[268] = {"statfs64"                      , "%p, %lu, %p"                   , 0, 0, 0},
[269] = {"fstatfs64"                     , "%u, %lu, %p"                   , 0, 0, 0},
[270] = {"tgkill"                        , "%i, %i, %i"                    , 0, 0, 0},
[271] = {"utimes"                        , "%p, %p"                        , 0, 0, 0},
[272] = {"fadvise64_64"                  , "%i, %u, %u, %u, %u, %i"        , 0, 0, 0},
[274] = {"mbind"                         , "%lu, %lu, %lu, %p, %lu, %u"    , 0, 0, 0},
[275] = {"get_mempolicy"                 , "%p, %p, %lu, %lu, %lu"         , 0, 0, 0},
[276] = {"set_mempolicy"                 , "%i, %p, %lu"                   , 0, 0, 0},
[277] = {"mq_open"                       , "%p, %i, %i, %p"                , 0, 0, 0},
[278] = {"mq_unlink"                     , "%p"                            , 0, 0, 0},
[279] = {"mq_timedsend"                  , "%i, %p, %u, %u, %p"            , 0, 0, 0},
[280] = {"mq_timedreceive"               , "%i, %p, %u, %p, %p"            , 0, 0, 0},
[281] = {"mq_notify"                     , "%i, %p"                        , 0, 0, 0},
[282] = {"mq_getsetattr"                 , "%i, %p, %p"                    , 0, 0, 0},
[283] = {"kexec_load"                    , "%lu, %lu, %p, %lu"             , 0, 0, 0},
[284] = {"waitid"                        , "%i, %i, %p, %i, %p"            , 0, 0, 0},
[286] = {"add_key"                       , "%p, %p, %p, %lu, %i"           , 0, 0, 0},
[287] = {"request_key"                   , "%p, %p, %p, %i"                , 0, 0, 0},
[288] = {"keyctl"                        , "%i, %lu, %lu, %lu, %lu"        , 0, 0, 0},
[289] = {"ioprio_set"                    , "%i, %i, %i"                    , 0, 0, 0},
[290] = {"ioprio_get"                    , "%i, %i"                        , 0, 0, 0},
[291] = {"inotify_init"                  , ""                              , 0, 0, 0},
[292] = {"inotify_add_watch"             , "%i, %p, %u"                    , 0, 0, 0},
[293] = {"inotify_rm_watch"              , "%i, %i"                        , 0, 0, 0},
[294] = {"migrate_pages"                 , "%i, %lu, %p, %p"               , 0, 0, 0},
[295] = {"openat"                        , "%i, %p, %i, %i"                , 0, 0, 0},
[296] = {"mkdirat"                       , "%i, %p, %i"                    , 0, 0, 0},
[297] = {"mknodat"                       , "%i, %p, %i, %u"                , 0, 0, 0},
[298] = {"fchownat"                      , "%i, %p, %i, %i, %i"            , 0, 0, 0},
[299] = {"futimesat"                     , "%u, %p, %p"                    , 0, 0, 0},
[300] = {"fstatat64"                     , "%i, %p, %p, %i"                , 0, 0, 0},
[301] = {"unlinkat"                      , "%i, %p, %i"                    , 0, 0, 0},
[302] = {"renameat"                      , "%i, %p, %i, %p"                , 0, 0, 0},
[303] = {"linkat"                        , "%i, %p, %i, %p, %i"            , 0, 0, 0},
[304] = {"symlinkat"                     , "%p, %i, %p"                    , 0, 0, 0},
[305] = {"readlinkat"                    , "%i, %p, %p, %i"                , 0, 0, 0},
[306] = {"fchmodat"                      , "%i, %p, %i"                    , 0, 0, 0},
[307] = {"faccessat"                     , "%i, %p, %i"                    , 0, 0, 0},
[308] = {"pselect6"                      , "%i, %p, %p, %p, %p, %p"        , 0, 0, 0},
[309] = {"ppoll"                         , "%p, %u, %p, %p, %lu"           , 0, 0, 0},
[310] = {"unshare"                       , "%lu"                           , 0, 0, 0},
[311] = {"set_robust_list"               , "%p, %lu"                       , 0, 0, 0},
[312] = {"get_robust_list"               , "%i, %p, %p"                    , 0, 0, 0},
[313] = {"splice"                        , "%i, %p, %i, %p, %lu, %u"       , 0, 0, 0},
[314] = {"sync_file_range"               , "%i, %u, %u, %u, %u, %i"        , 0, 0, 0},
[315] = {"tee"                           , "%i, %i, %lu, %u"               , 0, 0, 0},
[316] = {"vmsplice"                      , "%i, %p, %lu, %u"               , 0, 0, 0},
[317] = {"move_pages"                    , "%i, %lu, %p, %p, %p, %i"       , 0, 0, 0},
[318] = {"getcpu"                        , "%p, %p, %p"                    , 0, 0, 0},
[319] = {"epoll_pwait"                   , "%i, %p, %i, %i, %p, %lu"       , 0, 0, 0},
[320] = {"utimensat"                     , "%u, %p, %p, %i"                , 0, 0, 0},
[321] = {"signalfd"                      , "%i, %p, %lu"                   , 0, 0, 0},
[322] = {"timerfd_create"                , "%i, %i"                        , 0, 0, 0},
[323] = {"eventfd"                       , "%u"                            , 0, 0, 0},
[324] = {"fallocate"                     , "%i, %i, %u, %u, %u, %u"        , 0, 0, 0},
[325] = {"timerfd_settime"               , "%i, %i, %p, %p"                , 0, 0, 0},
[326] = {"timerfd_gettime"               , "%i, %p"                        , 0, 0, 0},
[327] = {"signalfd4"                     , "%i, %p, %lu, %i"               , 0, 0, 0},
[328] = {"eventfd2"                      , "%u, %i"                        , 0, 0, 0},
[329] = {"epoll_create1"                 , "%i"                            , 0, 0, 0},
[330] = {"dup3"                          , "%u, %u, %i"                    , 0, 0, 0},
[331] = {"pipe2"                         , "%p, %i"                        , 0, 0, 0},
[332] = {"inotify_init1"                 , "%i"                            , 0, 0, 0},
[333] = {"preadv"                        , "%lu, %p, %lu, %lu, %lu"        , 0, 0, 0},
[334] = {"pwritev"                       , "%lu, %p, %lu, %lu, %lu"        , 0, 0, 0},
[335] = {"rt_tgsigqueueinfo"             , "%i, %i, %i, %p"                , 0, 0, 0},
[336] = {"perf_event_open"               , "%p, %i, %i, %i, %lu"           , 0, 0, 0},
[337] = {"recvmmsg"                      , "%i, %p, %u, %u, %p"            , 0, 0, 0},
[338] = {"fanotify_init"                 , "%u, %u"                        , 0, 0, 0},
[339] = {"fanotify_mark"                 , "%i, %u, %u, %u, %i, %p"        , 0, 0, 0},
[340] = {"prlimit64"                     , "%i, %u, %p, %p"                , 0, 0, 0},
[341] = {"name_to_handle_at"             , "%i, %p, %p, %p, %i"            , 0, 0, 0},
[342] = {"open_by_handle_at"             , "%i, %p, %i"                    , 0, 0, 0},
[343] = {"clock_adjtime"                 , "%i, %p"                        , 0, 0, 0},
[344] = {"syncfs"                        , "%i"                            , 0, 0, 0},
[345] = {"sendmmsg"                      , "%i, %p, %u, %u"                , 0, 0, 0},
[346] = {"setns"                         , "%i, %i"                        , 0, 0, 0},
[347] = {"process_vm_readv"              , "%i, %p, %lu, %p, %lu, %lu"     , 0, 0, 0},
[348] = {"process_vm_writev"             , "%i, %p, %lu, %p, %lu, %lu"     , 0, 0, 0},
[349] = {"kcmp"                          , "%i, %i, %i, %lu, %lu"          , 0, 0, 0},
[350] = {"finit_module"                  , "%i, %p, %i"                    , 0, 0, 0},
[351] = {"sched_setattr"                 , "%i, %p, %u"                    , 0, 0, 0},
[352] = {"sched_getattr"                 , "%i, %p, %u, %u"                , 0, 0, 0},
[353] = {"renameat2"                     , "%i, %p, %i, %p, %u"            , 0, 0, 0},
[354] = {"seccomp"                       , "%u, %u, %p"                    , 0, 0, 0},
[355] = {"getrandom"                     , "%p, %lu, %u"                   , 0, 0, 0},
[356] = {"memfd_create"                  , "%p, %u"                        , 0, 0, 0},
[357] = {"bpf"                           , "%i, %p, %u"                    , 0, 0, 0},
[358] = {"execveat"                      , "%i, %p, %p, %p, %i"            , 0, 0, 0},
[359] = {"socket"                        , "%i, %i, %i"                    , 0, 0, 0},
[360] = {"socketpair"                    , "%i, %i, %i, %p"                , 0, 0, 0},
[361] = {"bind"                          , "%i, %p, %i"                    , 0, 0, 0},
[362] = {"connect"                       , "%i, %p, %i"                    , 0, 0, 0},
[363] = {"listen"                        , "%i, %i"                        , 0, 0, 0},
[364] = {"accept4"                       , "%i, %p, %p, %i"                , 0, 0, 0},
[365] = {"getsockopt"                    , "%i, %i, %i, %p, %p"            , 0, 0, 0},
[366] = {"setsockopt"                    , "%i, %i, %i, %p, %i"            , 0, 0, 0},
[367] = {"getsockname"                   , "%i, %p, %p"                    , 0, 0, 0},
[368] = {"getpeername"                   , "%i, %p, %p"                    , 0, 0, 0},
[369] = {"sendto"                        , "%i, %p, %lu, %u, %p, %i"       , 0, 0, 0},
[370] = {"sendmsg"                       , "%i, %p, %u"                    , 0, 0, 0},
[371] = {"recvfrom"                      , "%i, %p, %lu, %u, %p, %p"       , 0, 0, 0},
[372] = {"recvmsg"                       , "%i, %p, %u"                    , 0, 0, 0},
[373] = {"shutdown"                      , "%i, %i"                        , 0, 0, 0},
[374] = {"userfaultfd"                   , "%i"                            , 0, 0, 0},
[375] = {"membarrier"                    , "%i, %u, %i"                    , 0, 0, 0},
[376] = {"mlock2"                        , "%lu, %lu, %i"                  , 0, 0, 0},
[377] = {"copy_file_range"               , "%i, %p, %i, %p, %lu, %u"       , 0, 0, 0},
[378] = {"preadv2"                       , "%lu, %p, %lu, %lu, %lu, %i"    , 0, 0, 0},
[379] = {"pwritev2"                      , "%lu, %p, %lu, %lu, %lu, %i"    , 0, 0, 0},
[383] = {"statx"                         , "%i, %p, %u, %u, %p"            , 0, 0, 0},
[384] = {"arch_prctl"                    , "%i, %lu"                       , 0, 0, 0},
[385] = {"io_pgetevents"                 , "%i, %li, %li, %p, %p, %p"      , 0, 0, 0},
[386] = {"rseq"                          , "%p, %u, %i, %u"                , 0, 0, 0},
[393] = {"semget"                        , "%i, %i, %i"                    , 0, 0, 0},
[394] = {"semctl"                        , "%i, %i, %i, %lu"               , 0, 0, 0},
[395] = {"shmget"                        , "%i, %lu, %i"                   , 0, 0, 0},
[396] = {"shmctl"                        , "%i, %i, %p"                    , 0, 0, 0},
[397] = {"shmat"                         , "%i, %p, %i"                    , 0, 0, 0},
[398] = {"shmdt"                         , "%p"                            , 0, 0, 0},
[399] = {"msgget"                        , "%i, %i"                        , 0, 0, 0},
[400] = {"msgsnd"                        , "%i, %p, %lu, %i"               , 0, 0, 0},
[401] = {"msgrcv"                        , "%i, %p, %lu, %li, %i"          , 0, 0, 0},
[402] = {"msgctl"                        , "%i, %i, %p"                    , 0, 0, 0},
[403] = {"clock_gettime"                 , "%i, %p"                        , 0, 0, 0},
[404] = {"clock_settime"                 , "%i, %p"                        , 0, 0, 0},
[405] = {"clock_adjtime"                 , "%i, %p"                        , 0, 0, 0},
[406] = {"clock_getres"                  , "%i, %p"                        , 0, 0, 0},
[407] = {"clock_nanosleep"               , "%i, %i, %p, %p"                , 0, 0, 0},
[408] = {"timer_gettime"                 , "%i, %p"                        , 0, 0, 0},
[409] = {"timer_settime"                 , "%i, %i, %p, %p"                , 0, 0, 0},
[410] = {"timerfd_gettime"               , "%i, %p"                        , 0, 0, 0},
[411] = {"timerfd_settime"               , "%i, %i, %p, %p"                , 0, 0, 0},
[412] = {"utimensat"                     , "%i, %p, %p, %i"                , 0, 0, 0},
[413] = {"pselect6"                      , "%i, %p, %p, %p, %p, %p"        , 0, 0, 0},
[414] = {"ppoll"                         , "%p, %u, %p, %p, %lu"           , 0, 0, 0},
[416] = {"io_pgetevents"                 , "%i, %li, %li, %p, %p, %p"      , 0, 0, 0},
[417] = {"recvmmsg"                      , "%i, %p, %u, %u, %p"            , 0, 0, 0},
[418] = {"mq_timedsend"                  , "%i, %p, %lu, %u, %p"           , 0, 0, 0},
[419] = {"mq_timedreceive"               , "%i, %p, %lu, %p, %p"           , 0, 0, 0},
[420] = {"semtimedop"                    , "%i, %p, %u, %p"                , 0, 0, 0},
[421] = {"rt_sigtimedwait"               , "%p, %p, %p, %lu"               , 0, 0, 0},
[422] = {"futex"                         , "%p, %i, %u, %p, %p, %u"        , 0, 0, 0},
[423] = {"sched_rr_get_interval"         , "%i, %p"                        , 0, 0, 0},
[424] = {"pidfd_send_signal"             , "%i, %i, %p, %u"                , 0, 0, 0},
[425] = {"io_uring_setup"                , "%u, %p"                        , 0, 0, 0},
[426] = {"io_uring_enter"                , "%u, %u, %u, %u, %p, %lu"       , 0, 0, 0},
[427] = {"io_uring_register"             , "%u, %u, %p, %u"                , 0, 0, 0},
[428] = {"open_tree"                     , "%i, %p, %u"                    , 0, 0, 0},
[429] = {"move_mount"                    , "%i, %p, %i, %p, %u"            , 0, 0, 0},
[430] = {"fsopen"                        , "%p, %u"                        , 0, 0, 0},
[431] = {"fsconfig"                      , "%i, %u, %p, %p, %i"            , 0, 0, 0},
[432] = {"fsmount"                       , "%i, %u, %u"                    , 0, 0, 0},
[433] = {"fspick"                        , "%i, %p, %u"                    , 0, 0, 0},
[434] = {"pidfd_open"                    , "%i, %u"                        , 0, 0, 0},
[435] = {"clone3"                        , "%p, %lu"                       , 0, 0, 0},
[436] = {"close_range"                   , "%u, %u, %u"                    , 0, 0, 0},
[437] = {"openat2"                       , "%i, %p, %p, %lu"               , 0, 0, 0},
[438] = {"pidfd_getfd"                   , "%i, %i, %u"                    , 0, 0, 0},
[439] = {"faccessat2"                    , "%i, %p, %i, %i"                , 0, 0, 0},
[440] = {"process_madvise"               , "%i, %p, %lu, %i, %u"           , 0, 0, 0},
[441] = {"epoll_pwait2"                  , "%i, %p, %i, %p, %p, %lu"       , 0, 0, 0},
[442] = {"mount_setattr"                 , "%i, %p, %u, %p, %lu"           , 0, 0, 0},
[443] = {"quotactl_fd"                   , "%u, %u, %i, %p"                , 0, 0, 0},
[444] = {"landlock_create_ruleset"       , "%p, %lu, %u"                   , 0, 0, 0},
[445] = {"landlock_add_rule"             , "%i, %i, %p, %u"                , 0, 0, 0},
[446] = {"landlock_restrict_self"        , "%i, %u"                        , 0, 0, 0},
[447] = {"memfd_secret"                  , "%u"                            , 0, 0, 0},
[448] = {"process_mrelease"              , "%i, %u"                        , 0, 0, 0},
[449] = {"futex_waitv"                   , "%p, %u, %u, %p, %i"            , 0, 0, 0},
[450] = {"set_mempolicy_home_node"       , "%lu, %lu, %lu, %lu"            , 0, 0, 0},
[451] = {"cachestat"                     , "%u, %p, %p, %u"                , 0, 0, 0},
[452] = {"fchmodat2"                     , "%i, %p, %i, %u"                , 0, 0, 0},
[454] = {"futex_wake"                    , "%p, %lu, %i, %u"               , 0, 0, 0},
[455] = {"futex_wait"                    , "%p, %lu, %lu, %u, %p, %i"      , 0, 0, 0},
[456] = {"futex_requeue"                 , "%p, %u, %i, %i"                , 0, 0, 0},
[457] = {"statmount"                     , "%p, %p, %lu, %u"               , 0, 0, 0},
[458] = {"listmount"                     , "%p, %p, %lu, %u"               , 0, 0, 0},
[459] = {"lsm_get_self_attr"             , "%u, %p, %p, %u"                , 0, 0, 0},
[460] = {"lsm_set_self_attr"             , "%u, %p, %u, %u"                , 0, 0, 0},
[461] = {"lsm_list_modules"              , "%p, %p, %u"                    , 0, 0, 0},