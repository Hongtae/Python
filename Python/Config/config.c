/* Module configuration */

/* This file contains the table of built-in modules.
   See init_builtin() in import.c. */

#include "Python.h"

extern PyObject* PyInit__abc(void);
extern PyObject* PyInit_array(void);
extern PyObject* PyInit_audioop(void);
extern PyObject* PyInit_binascii(void);
extern PyObject* PyInit_cmath(void);
extern PyObject* PyInit_errno(void);
extern PyObject* PyInit_faulthandler(void);
extern PyObject* PyInit__tracemalloc(void);
extern PyObject* PyInit_gc(void);
extern PyObject* PyInit_math(void);
extern PyObject* PyInit__md5(void);

extern PyObject* PyInit__operator(void);
extern PyObject* PyInit__signal(void);
extern PyObject* PyInit__sha1(void);
extern PyObject* PyInit__sha256(void);
extern PyObject* PyInit__sha512(void);
extern PyObject* PyInit__sha3(void);
extern PyObject* PyInit__statistics(void);
extern PyObject* PyInit__blake2(void);
extern PyObject* PyInit_time(void);
extern PyObject* PyInit__thread(void);


extern PyObject* PyInit__codecs(void);
extern PyObject* PyInit__weakref(void);
extern PyObject* PyInit_xxsubtype(void);
extern PyObject* PyInit__xxsubinterpreters(void);
extern PyObject* PyInit__random(void);
extern PyObject* PyInit_itertools(void);
extern PyObject* PyInit__collections(void);
extern PyObject* PyInit__heapq(void);
extern PyObject* PyInit__bisect(void);
extern PyObject* PyInit__symtable(void);
extern PyObject* PyInit_mmap(void);
extern PyObject* PyInit__csv(void);
extern PyObject* PyInit__sre(void);
extern PyObject* PyInit_parser(void);

extern PyObject* PyInit__struct(void);
extern PyObject* PyInit__datetime(void);
extern PyObject* PyInit__functools(void);
extern PyObject* PyInit__json(void);
extern PyObject* PyInit_zlib(void);

/* 2015-01-09 by tiff2766 - BEGIN */
#define DECL_MOD(NAME)  extern PyObject* PyInit_ ## NAME(void)
DECL_MOD(_asyncio);
DECL_MOD(_bz2);
DECL_MOD(_ctypes);
DECL_MOD(_ctypes_test);
DECL_MOD(_decimal);
DECL_MOD(_elementtree);
DECL_MOD(_freeze_importlib);
DECL_MOD(_hashlib);
DECL_MOD(_locale);
DECL_MOD(_multiprocessing);
DECL_MOD(_queue);
DECL_MOD(_socket);
DECL_MOD(_sqlite3);
DECL_MOD(_ssl);
DECL_MOD(_testbuffer);
DECL_MOD(_testcapi);
DECL_MOD(_testimportmultiple);
DECL_MOD(_testinternalcapi);
DECL_MOD(_testmultiphase);
DECL_MOD(pyexpat);
DECL_MOD(select);
DECL_MOD(unicodedata);
#ifdef WIN32
DECL_MOD(nt);
DECL_MOD(msvcrt);
DECL_MOD(winreg);
DECL_MOD(_winapi);
DECL_MOD(_overlapped);
DECL_MOD(_testconsole);
#else
DECL_MOD(posix);
DECL_MOD(_posixsubprocess);
#endif
#undef DECL_MOD
/* 2015-01-09 by tiff2766 - END */

extern PyObject* PyInit__multibytecodec(void);
extern PyObject* PyInit__codecs_cn(void);
extern PyObject* PyInit__codecs_hk(void);
extern PyObject* PyInit__codecs_iso2022(void);
extern PyObject* PyInit__codecs_jp(void);
extern PyObject* PyInit__codecs_kr(void);
extern PyObject* PyInit__codecs_tw(void);

extern PyObject* PyInit__lsprof(void);
extern PyObject* PyInit__ast(void);
extern PyObject* PyInit__io(void);
extern PyObject* PyInit__pickle(void);
extern PyObject* PyInit_atexit(void);
extern PyObject* _PyWarnings_Init(void);
extern PyObject* PyInit__string(void);
extern PyObject* PyInit__stat(void);
extern PyObject* PyInit__opcode(void);

extern PyObject* PyInit__contextvars(void);

/* tools/freeze/makeconfig.py marker for additional "extern" */
/* -- ADDMODULE MARKER 1 -- */

extern PyObject* PyMarshal_Init(void);
extern PyObject* PyInit__imp(void);

struct _inittab _PyImport_Inittab[] = {

    {"_abc", PyInit__abc},
    {"array", PyInit_array},
    {"_ast", PyInit__ast},
    {"audioop", PyInit_audioop},
    {"binascii", PyInit_binascii},
    {"cmath", PyInit_cmath},
    {"errno", PyInit_errno},
    {"faulthandler", PyInit_faulthandler},
    {"gc", PyInit_gc},
    {"math", PyInit_math},

    {"_operator", PyInit__operator},
    {"_signal", PyInit__signal},
    {"_md5", PyInit__md5},
    {"_sha1", PyInit__sha1},
    {"_sha256", PyInit__sha256},
    {"_sha512", PyInit__sha512},
    {"_sha3", PyInit__sha3},
    {"_blake2", PyInit__blake2},
    {"time", PyInit_time},
    {"_thread", PyInit__thread},
    {"_statistics", PyInit__statistics},

	{"_tracemalloc", PyInit__tracemalloc},

	{"_codecs", PyInit__codecs},
    {"_weakref", PyInit__weakref},
    {"_random", PyInit__random},
    {"_bisect", PyInit__bisect},
    {"_heapq", PyInit__heapq},
    {"_lsprof", PyInit__lsprof},
    {"itertools", PyInit_itertools},
    {"_collections", PyInit__collections},
    {"_symtable", PyInit__symtable},
    {"mmap", PyInit_mmap},
    {"_csv", PyInit__csv},
    {"_sre", PyInit__sre},
    {"parser", PyInit_parser},

    {"_struct", PyInit__struct},
    {"_datetime", PyInit__datetime},
    {"_functools", PyInit__functools},
    {"_json", PyInit__json},

    {"xxsubtype", PyInit_xxsubtype},
    {"_xxsubinterpreters", PyInit__xxsubinterpreters},
    {"zlib", PyInit_zlib},

	/* 2013-01-18 by tiff - BEGIN */
#define INIT_MOD(NAME)   { #NAME, PyInit_ ## NAME }
    INIT_MOD(_asyncio),
    INIT_MOD(_bz2),
    INIT_MOD(_ctypes),
    INIT_MOD(_ctypes_test),
    INIT_MOD(_decimal),
    INIT_MOD(_elementtree),
    INIT_MOD(_hashlib),
    INIT_MOD(_locale),
    INIT_MOD(_multiprocessing),
    INIT_MOD(_queue),
    INIT_MOD(_socket),
    INIT_MOD(_sqlite3),
    INIT_MOD(_ssl),
    INIT_MOD(_testbuffer),
    INIT_MOD(_testcapi),
    INIT_MOD(_testimportmultiple),
    INIT_MOD(_testinternalcapi),
    INIT_MOD(_testmultiphase),
    INIT_MOD(pyexpat),
    INIT_MOD(select),
    INIT_MOD(unicodedata),

#ifdef WIN32
    INIT_MOD(nt), /* Use the NT os functions, not posix */
    INIT_MOD(_winapi),
    INIT_MOD(msvcrt),
    INIT_MOD(winreg),
    INIT_MOD(_overlapped),
#else
    INIT_MOD(posix),
    INIT_MOD(_posixsubprocess),
#endif
#undef INIT_MOD
	/* 2013-01-18 by tiff - END */

    /* CJK codecs */
    {"_multibytecodec", PyInit__multibytecodec},
    {"_codecs_cn", PyInit__codecs_cn},
    {"_codecs_hk", PyInit__codecs_hk},
    {"_codecs_iso2022", PyInit__codecs_iso2022},
    {"_codecs_jp", PyInit__codecs_jp},
    {"_codecs_kr", PyInit__codecs_kr},
    {"_codecs_tw", PyInit__codecs_tw},

/* tools/freeze/makeconfig.py marker for additional "_inittab" entries */
/* -- ADDMODULE MARKER 2 -- */

    /* This module "lives in" with marshal.c */
    {"marshal", PyMarshal_Init},

    /* This lives it with import.c */
    {"_imp", PyInit__imp},

    /* These entries are here for sys.builtin_module_names */
    {"builtins", NULL},
    {"sys", NULL},
    {"_warnings", _PyWarnings_Init},
    {"_string", PyInit__string},

    {"_io", PyInit__io},
    {"_pickle", PyInit__pickle},
    {"atexit", PyInit_atexit},
	{"_stat", PyInit__stat},
	{"_opcode", PyInit__opcode},

    { "_contextvars", PyInit__contextvars },

    /* Sentinel */
    {0, 0}
};
