/*
 * Copyright (c) 2024 Arm Limited
 *
 * The license below extends only to copyright in the software and shall
 * not be construed as granting a license to any other intellectual
 * property including but not limited to intellectual property relating
 * to a hardware implementation of the functionality of the software
 * licensed hereunder.  You may use the software subject to the license
 * terms below provided that you ensure that this notice is replicated
 * unmodified and in its entirety in all distributions of the software,
 * modified or unmodified, in source code or in binary form.
 *
 * Copyright 2020 Google Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met: redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer;
 * redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution;
 * neither the name of the copyright holders nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <sys/syscall.h>

#include "arch/x86/linux/linux.hh"
#include "arch/x86/linux/se_workload.hh"
#include "arch/x86/linux/syscalls.hh"
#include "sim/syscall_emul.hh"

namespace gem5
{

namespace X86ISA
{

SyscallDescTable<EmuLinux::SyscallABI32> EmuLinux::syscallDescs32 = {
    {   0, "restart_syscall" },
    {   1, "exit", exitFunc },
    {   2, "fork" },
    {   3, "read", readFunc<X86Linux32> },
    {   4, "write", writeFunc<X86Linux32> },
    {   5, "open", openFunc<X86Linux32> },
    {   6, "close", closeFunc },
    {   7, "waitpid" },
    {   8, "creat" },
    {   9, "link" },
    {  10, "unlink" },
    {  11, "execve", execveFunc<X86Linux32> },
    {  12, "chdir", chdirFunc },
    {  13, "time", timeFunc<X86Linux32> },
    {  14, "mknod", mknodFunc },
    {  15, "chmod" },
    {  16, "lchown" },
    {  17, "break" },
    {  18, "oldstat" },
    {  19, "lseek", lseekFunc<X86Linux32> },
    {  20, "getpid", getpidFunc },
    {  21, "mount" },
    {  22, "umount" },
    {  23, "setuid" },
    {  24, "getuid", getuidFunc },
    {  25, "stime" },
    {  26, "ptrace" },
    {  27, "alarm" },
    {  28, "oldfstat" },
    {  29, "pause" },
    {  30, "utime" },
    {  31, "stty" },
    {  32, "gtty" },
    {  33, "access", ignoreFunc },
    {  34, "nice" },
    {  35, "ftime" },
    {  36, "sync" },
    {  37, "kill" },
    {  38, "rename" },
    {  39, "mkdir", mkdirFunc },
    {  40, "rmdir", mkdirFunc },
    {  41, "dup", dupFunc },
    {  42, "pipe", pipeFunc },
    {  43, "times", timesFunc<X86Linux32> },
    {  44, "prof" },
    {  45, "brk", brkFunc },
    {  46, "setgid" },
    {  47, "getgid", getgidFunc },
    {  48, "signal" },
    {  49, "geteuid", geteuidFunc },
    {  50, "getegid", getegidFunc },
    {  51, "acct" },
    {  52, "umount2" },
    {  53, "lock" },
    {  54, "ioctl", ioctlFunc<X86Linux32> },
    {  55, "fcntl", fcntlFunc },
    {  56, "mpx" },
    {  57, "setpgid", setpgidFunc },
    {  58, "ulimit" },
    {  59, "oldolduname" },
    {  60, "umask", umaskFunc },
    {  61, "chroot" },
    {  62, "ustat" },
    {  63, "dup2", dup2Func },
    {  64, "getppid" },
    {  65, "getpgrp" },
    {  66, "setsid" },
    {  67, "sigaction" },
    {  68, "sgetmask" },
    {  69, "ssetmask" },
    {  70, "setreuid" },
    {  71, "setregid" },
    {  72, "sigsuspend" },
    {  73, "sigpending" },
    {  74, "sethostname" },
    {  75, "setrlimit", ignoreFunc },
    {  76, "getrlimit", getrlimitFunc<X86Linux32> },
    {  77, "getrusage", getrusageFunc<X86Linux32> },
    {  78, "gettimeofday" },
    {  79, "settimeofday" },
    {  80, "getgroups" },
    {  81, "setgroups" },
    {  82, "select", selectFunc<X86Linux32> },
    {  83, "symlink" },
    {  84, "oldlstat" },
    {  85, "readlink", readlinkFunc<X86Linux32> },
    {  86, "uselib" },
    {  87, "swapon" },
    {  88, "reboot" },
    {  89, "readdir" },
    {  90, "mmap" },
    {  91, "munmap", munmapFunc<X86Linux32> },
    {  92, "truncate", truncateFunc<X86Linux32> },
    {  93, "ftruncate", ftruncateFunc<X86Linux32> },
    {  94, "fchmod" },
    {  95, "fchown" },
    {  96, "getpriority" },
    {  97, "setpriority", ignoreFunc },
    {  98, "profil" },
    {  99, "statfs", ignoreFunc },
    { 100, "fstatfs" },
    { 101, "ioperm" },
    { 102, "socketcall" },
    { 103, "syslog" },
    { 104, "setitimer" },
    { 105, "getitimer" },
    { 106, "stat" },
    { 107, "lstat" },
    { 108, "fstat" },
    { 109, "olduname" },
    { 110, "iopl" },
    { 111, "vhangup" },
    { 112, "idle" },
    { 113, "vm86old" },
    { 114, "wait4", wait4Func<X86Linux32> },
    { 115, "swapoff" },
    { 116, "sysinfo", sysinfoFunc<X86Linux32> },
    { 117, "ipc" },
    { 118, "fsync" },
    { 119, "sigreturn" },
    { 120, "clone", cloneFunc<X86Linux32> },
    { 121, "setdomainname" },
    { 122, "uname", unameFunc },
    { 123, "modify_ldt" },
    { 124, "adjtimex" },
    { 125, "mprotect", ignoreFunc },
    { 126, "sigprocmask" },
    { 127, "create_module" },
    { 128, "init_module" },
    { 129, "delete_module" },
    { 130, "get_kernel_syms" },
    { 131, "quotactl" },
    { 132, "getpgid" },
    { 133, "fchdir" },
    { 134, "bdflush" },
    { 135, "sysfs" },
    { 136, "personality" },
    { 137, "afs_syscall" },
    { 138, "setfsuid" },
    { 139, "setfsgid" },
    { 140, "_llseek", _llseekFunc },
#if defined(SYS_getdents)
    { 141, "getdents", getdentsFunc },
#else
    { 141, "getdents" },
#endif
    { 142, "_newselect" },
    { 143, "flock" },
    { 144, "msync" },
    { 145, "readv", readvFunc<X86Linux32> },
    { 146, "writev", writevFunc<X86Linux32> },
    { 147, "getsid" },
    { 148, "fdatasync" },
    { 149, "_sysctl" },
    { 150, "mlock" },
    { 151, "munlock" },
    { 152, "mlockall" },
    { 153, "munlockall" },
    { 154, "sched_setparam" },
    { 155, "sched_getparam", sched_getparamFunc },
    { 156, "sched_setscheduler" },
    { 157, "sched_getscheduler" },
    { 158, "sched_yield", ignoreFunc },
    { 159, "sched_get_priority_max" },
    { 160, "sched_get_priority_min" },
    { 161, "sched_rr_get_interval" },
    { 162, "nanosleep", ignoreFunc },
    { 163, "mremap" },
    { 164, "setresuid", ignoreFunc },
    { 165, "getresuid" },
    { 166, "vm86" },
    { 167, "query_module" },
    { 168, "poll", pollFunc<X86Linux32> },
    { 169, "nfsservctl" },
    { 170, "setresgid" },
    { 171, "getresgid" },
    { 172, "prctl" },
    { 173, "rt_sigreturn" },
    { 174, "rt_sigaction", ignoreFunc },
    { 175, "rt_sigprocmask", ignoreFunc },
    { 176, "rt_sigpending" },
    { 177, "rt_sigtimedwait" },
    { 178, "rt_sigqueueinfo" },
    { 179, "rt_sigsuspend" },
    { 180, "pread64", pread64Func<X86Linux64> },
    { 181, "pwrite64", pwrite64Func<X86Linux64> },
    { 182, "chown" },
    { 183, "getcwd", getcwdFunc<X86Linux32> },
    { 184, "capget" },
    { 185, "capset" },
    { 186, "sigaltstack" },
    { 187, "sendfile" },
    { 188, "getpmsg" },
    { 189, "putpmsg" },
    { 190, "vfork" },
    { 191, "ugetrlimit", ignoreFunc },
    { 192, "mmap2", mmap2Func<X86Linux32> },
    { 193, "truncate64", truncate64Func },
    { 194, "ftruncate64", ftruncate64Func },
    { 195, "stat64", stat64Func<X86Linux32> },
    { 196, "lstat64" },
    { 197, "fstat64", fstat64Func<X86Linux32> },
    { 198, "lchown32" },
    { 199, "getuid32", getuidFunc },
    { 200, "getgid32", getgidFunc },
    { 201, "geteuid32", geteuidFunc },
    { 202, "getegid32", getegidFunc },
    { 203, "setreuid32" },
    { 204, "setregid32" },
    { 205, "getgroups32" },
    { 206, "setgroups32" },
    { 207, "fchown32" },
    { 208, "setresuid32" },
    { 209, "getresuid32" },
    { 210, "setresgid32" },
    { 211, "getresgid32" },
    { 212, "chown32" },
    { 213, "setuid32" },
    { 214, "setgid32" },
    { 215, "setfsuid32" },
    { 216, "setfsgid32" },
    { 217, "pivot_root" },
    { 218, "mincore" },
    { 219, "madvise", ignoreFunc },
    { 220, "madvise1" },
#if defined(SYS_getdents64)
    { 221, "getdents64", getdents64Func },
#else
    { 221, "getdents64" },
#endif
    { 222, "fcntl64" },
    { 223, "unused" },
    { 224, "gettid", gettidFunc },
    { 225, "readahead" },
    { 226, "setxattr" },
    { 227, "lsetxattr" },
    { 228, "fsetxattr" },
    { 229, "getxattr" },
    { 230, "lgetxattr" },
    { 231, "fgetxattr" },
    { 232, "listxattr" },
    { 233, "llistxattr" },
    { 234, "flistxattr" },
    { 235, "removexattr" },
    { 236, "lremovexattr" },
    { 237, "fremovexattr" },
    { 238, "tkill" },
    { 239, "sendfile64" },
    { 240, "futex" },
    { 241, "sched_setaffinity", ignoreFunc },
    { 242, "sched_getaffinity", ignoreFunc },
    { 243, "set_thread_area", setThreadArea32Func },
    { 244, "get_thread_area" },
    { 245, "io_setup" },
    { 246, "io_destroy" },
    { 247, "io_getevents" },
    { 248, "io_submit" },
    { 249, "io_cancel" },
    { 250, "fadvise64" },
    { 251, "unused" },
    { 252, "exit_group", exitFunc },
    { 253, "lookup_dcookie" },
    { 254, "epoll_create" },
    { 255, "epoll_ctl" },
    { 256, "epoll_wait" },
    { 257, "remap_file_pages" },
    { 258, "set_tid_address", setTidAddressFunc },
    { 259, "timer_create" },
    { 260, "timer_settime" },
    { 261, "timer_gettime" },
    { 262, "timer_getoverrun" },
    { 263, "timer_delete" },
    { 264, "clock_settime" },
    { 265, "clock_gettime", clock_gettimeFunc<X86Linux32> },
    { 266, "clock_getres" },
    { 267, "clock_nanosleep" },
    { 268, "statfs64" },
    { 269, "fstatfs64" },
    { 270, "tgkill", tgkillFunc<X86Linux32> },
    { 271, "utimes" },
    { 272, "fadvise64_64" },
    { 273, "vserver" },
    { 274, "mbind" },
    { 275, "get_mempolicy", ignoreFunc },
    { 276, "set_mempolicy" },
    { 277, "mq_open" },
    { 278, "mq_unlink" },
    { 279, "mq_timedsend" },
    { 280, "mq_timedreceive" },
    { 281, "mq_notify" },
    { 282, "mq_getsetattr" },
    { 283, "kexec_load" },
    { 284, "waitid" },
    { 285, "sys_setaltroot" },
    { 286, "add_key" },
    { 287, "request_key" },
    { 288, "keyctl" },
    { 289, "ioprio_set" },
    { 290, "ioprio_get" },
    { 291, "inotify_init" },
    { 292, "inotify_add_watch" },
    { 293, "inotify_rm_watch" },
    { 294, "migrate_pages" },
    { 295, "openat", openatFunc<X86Linux32> },
    { 296, "mkdirat" },
    { 297, "mknodat" },
    { 298, "fchownat" },
    { 299, "futimesat" },
    { 300, "fstatat64" },
    { 301, "unlinkat" },
    { 302, "renameat" },
    { 303, "linkat" },
    { 304, "symlinkat" },
    { 305, "readlinkat", readlinkFunc<X86Linux32> },
    { 306, "fchmodat" },
    { 307, "faccessat" },
    { 308, "pselect6" },
    { 309, "ppoll" },
    { 310, "unshare" },
    { 311, "set_robust_list", ignoreFunc },
    { 312, "get_robust_list", ignoreFunc },
    { 313, "splice" },
    { 314, "sync_file_range" },
    { 315, "tee" },
    { 316, "vmsplice" },
    { 317, "move_pages" },
    { 318, "getcpu", getcpuFunc },
    { 319, "epoll_pwait" },
    { 320, "utimensat" },
    { 321, "signalfd" },
    { 322, "timerfd" },
    { 323, "eventfd", eventfdFunc<X86Linux32> },
    { 355, "getrandom", getrandomFunc<X86Linux32>}
};

} // namespace X86ISA
} // namespace gem5
