#include <sys/syscall.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

#ifndef __linux__
#error "Target platform must be linux"
#endif
#ifndef __ANDROID__
#error "This file must be compiled for Android"
#endif

struct android_lconv
{
	char	*decimal_point;
	char	*thousands_sep;
	char	*grouping;
	char	*int_curr_symbol;
	char	*currency_symbol;
	char	*mon_decimal_point;
	char	*mon_thousands_sep;
	char	*mon_grouping;
	char	*positive_sign;
	char	*negative_sign;
	char	int_frac_digits;
	char	frac_digits;
	char	p_cs_precedes;
	char	p_sep_by_space;
	char	n_cs_precedes;
	char	n_sep_by_space;
	char	p_sign_posn;
	char	n_sign_posn;
	char	int_p_cs_precedes;
	char	int_n_cs_precedes;
	char	int_p_sep_by_space;
	char	int_n_sep_by_space;
	char	int_p_sign_posn;
	char	int_n_sign_posn;
};

struct android_lconv* android_localeconv(void)
{
	static struct android_lconv lc;
	lc.decimal_point = ".";
	lc.thousands_sep = "";
	lc.grouping = "";
	lc.int_curr_symbol = "";
	lc.currency_symbol = "";
	lc.mon_decimal_point = "";
	lc.mon_thousands_sep = "";
	lc.mon_grouping = "";
	lc.positive_sign = "";
	lc.negative_sign = "";
	lc.int_frac_digits = 0x7f;
	lc.frac_digits = 0x7f;
	lc.p_cs_precedes = 0x7f;
	lc.p_sep_by_space = 0x7f;
	lc.n_cs_precedes = 0x7f;
	lc.n_sep_by_space = 0x7f;
	lc.p_sign_posn = 0x7f;
	lc.n_sign_posn = 0x7f;
	lc.int_p_cs_precedes = 0x7f;
	lc.int_n_cs_precedes = 0x7f;
	lc.int_p_sep_by_space = 0x7f;
	lc.int_n_sep_by_space = 0x7f;
	lc.int_p_sign_posn = 0x7f;
	lc.int_n_sign_posn = 0x7f;
	return &lc;
}

pid_t getsid(pid_t pid)
{
	return syscall(__NR_getsid, pid);
}

char* ctermid(char* buf)
{
	if (buf)
	{
		strcpy(buf, "/dev/tty");
		return buf;
	}
	return "/dev/tty";
}

char* ctermid_r(char* buf)
{
	if (buf)
	{
		strcpy(buf, "/dev/tty");
		return buf;
	}
	return NULL;
}

int readlinkat(int dirfd, const char *pathname,
			   char *buf, size_t bufsiz)
{
	return syscall(__NR_readlinkat, dirfd, pathname, buf, bufsiz);
}

int symlinkat(const char *oldpath, int newdirfd, const char *newpath)
{
	return syscall(__NR_symlinkat, oldpath, newdirfd, newpath);
}

int futimes(int fd, const struct timeval tv[2]) {
	if (tv == NULL)
		return syscall(__NR_utimensat, fd, NULL, NULL, 0);

	if (tv[0].tv_usec < 0 || tv[0].tv_usec >= 1000000 ||
		tv[1].tv_usec < 0 || tv[1].tv_usec >= 1000000) {
		errno = EINVAL;
		return -1;
	}

	// Convert timeval to timespec.
	struct timespec ts[2];
	ts[0].tv_sec = tv[0].tv_sec;
	ts[0].tv_nsec = tv[0].tv_usec * 1000;
	ts[1].tv_sec = tv[1].tv_sec;
	ts[1].tv_nsec = tv[1].tv_usec * 1000;
	return syscall(__NR_utimensat, fd, NULL, ts, 0);
}

#define F_ULOCK         0      /* unlock locked section */
#define	F_LOCK          1      /* lock a section for exclusive use */
#define	F_TLOCK         2      /* test and lock a section for exclusive use */
#define	F_TEST          3      /* test a section for locks by other procs */

int lockf (int fd, int cmd, off_t len)
{
	struct flock fl;

	switch (cmd)
    {
		case F_TEST:
			/* Test the lock: return 0 if FD is unlocked or locked by this process;
			 return -1, set errno to EACCES, if another process holds the lock.  */
			if (fcntl (fd, F_GETLK, &fl) < 0)
				return -1;
			if (fl.l_type == F_UNLCK || fl.l_pid == getpid ())
				return 0;
			errno = EACCES;
			return -1;

		case F_ULOCK:
			fl.l_type = F_UNLCK;
			cmd = F_SETLK;
			break;
		case F_LOCK:
			fl.l_type = F_WRLCK;
			cmd = F_SETLKW;
			break;
		case F_TLOCK:
			fl.l_type = F_WRLCK;
			cmd = F_SETLK;
			break;

		default:
			errno = EINVAL;
			return -1;
    }

	/* lockf is always relative to the current file position.  */
	fl.l_whence = SEEK_CUR;
	fl.l_start = 0;

	fl.l_len = len;

	return fcntl (fd, cmd, &fl);
}

int utimensat(int dirfd, const char *pathname, const struct timespec times[2], int flags)
{
	return syscall(__NR_utimensat, dirfd, pathname, times, flags);
}

int epoll_create1(int flags)
{
	return syscall(__NR_epoll_create1, flags);
}

int __rt_sigtimedwait(const sigset_t* uthese, siginfo_t* uinfo, const struct timespec* uts, size_t sigsetsize);
int sigtimedwait(const sigset_t *set, siginfo_t *info, const struct timespec *timeout)
{
	//return syscall(__NR_rt_sigtimedwait, set, info, timeout, sizeof(sigset_t));
	return __rt_sigtimedwait(set, info, timeout, sizeof(sigset_t));
}

int sethostname(const char *name, size_t len)
{
	return syscall(__NR_sethostname, name, len);
}
