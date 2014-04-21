LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := PythonCore
LOCAL_ARM_NEON := true
LOCAL_CFLAGS := -std=c99 -fvisibility=hidden -mfloat-abi=softfp -mfpu=neon -DNDEBUG=1 -D_NDEBUG=1
LOCAL_CFLAGS += -DPy_BUILD_CORE -DPy_NO_ENABLE_SHARED -DHAVE_MEMMOVE -DHAVE_EXPAT_H -DXML_STATIC -D_FILE_OFFSET_BITS=64

LOCAL_C_INCLUDES := \
	$(LOCAL_PATH)/Include \
	$(LOCAL_PATH)/Python \
	$(LOCAL_PATH)/Modules/expat \
	$(LOCAL_PATH)/Modules/_ctypes/libffi_arm_linux/include \
	$(LOCAL_PATH)/../ExtDeps/zlib \
	$(LOCAL_PATH)/../ExtDeps/bzip2 \
	$(LOCAL_PATH)/../ExtDeps/sqlite \
	$(LOCAL_PATH)/../OpenSSL/include

MODULES_SRC := \
	Modules/_bisectmodule.c \
	Modules/_bz2module.c \
	Modules/_codecsmodule.c \
	Modules/_collectionsmodule.c \
	Modules/_csv.c \
	Modules/_datetimemodule.c \
	Modules/_elementtree.c \
	Modules/_functoolsmodule.c \
	Modules/_hashopenssl.c \
	Modules/_heapqmodule.c \
	Modules/_json.c \
	Modules/_localemodule.c \
	Modules/_lsprof.c \
	Modules/_math.c \
	Modules/_pickle.c \
	Modules/_posixsubprocess.c \
	Modules/_randommodule.c \
	Modules/_sre.c \
	Modules/_ssl.c \
	Modules/_struct.c \
	Modules/_testbuffer.c \
	Modules/_testcapimodule.c \
	Modules/_testembed.c \
	Modules/_threadmodule.c \
	Modules/_weakref.c \
	Modules/arraymodule.c \
	Modules/atexitmodule.c \
	Modules/audioop.c \
	Modules/binascii.c \
	Modules/cmathmodule.c \
	Modules/errnomodule.c \
	Modules/faulthandler.c \
	Modules/gcmodule.c \
	Modules/getbuildinfo.c \
	Modules/getpath.c \
	Modules/itertoolsmodule.c \
	Modules/main.c \
	Modules/mathmodule.c \
	Modules/md5module.c \
	Modules/mmapmodule.c \
	Modules/operator.c \
	Modules/parsermodule.c \
	Modules/posixmodule.c \
	Modules/pyexpat.c \
	Modules/rotatingtree.c \
	Modules/selectmodule.c \
	Modules/sha1module.c \
	Modules/sha256module.c \
	Modules/sha512module.c \
	Modules/signalmodule.c \
	Modules/socketmodule.c \
	Modules/symtablemodule.c \
	Modules/timemodule.c \
	Modules/unicodedata.c \
	Modules/xxsubtype.c \
	Modules/zipimport.c \
	Modules/zlibmodule.c \
	Modules/_ctypes/_ctypes.c \
	Modules/_ctypes/_ctypes_test.c \
	Modules/_ctypes/callbacks.c \
	Modules/_ctypes/callproc.c \
	Modules/_ctypes/cfield.c \
	Modules/_ctypes/malloc_closure.c \
	Modules/_ctypes/stgdict.c \
	Modules/_ctypes/libffi_arm_linux/src/prep_cif.c \
	Modules/_ctypes/libffi_arm_linux/src/arm/ffi.c \
	Modules/_ctypes/libffi_arm_linux/src/arm/sysv.S \
	Modules/_ctypes/libffi_arm_linux/src/arm/trampoline.S \
	Modules/_decimal/_decimal.c \
	Modules/_decimal/libmpdec/basearith.c \
	Modules/_decimal/libmpdec/constants.c \
	Modules/_decimal/libmpdec/context.c \
	Modules/_decimal/libmpdec/convolute.c \
	Modules/_decimal/libmpdec/crt.c \
	Modules/_decimal/libmpdec/difradix2.c \
	Modules/_decimal/libmpdec/fnt.c \
	Modules/_decimal/libmpdec/fourstep.c \
	Modules/_decimal/libmpdec/io.c \
	Modules/_decimal/libmpdec/memory.c \
	Modules/_decimal/libmpdec/mpdecimal.c \
	Modules/_decimal/libmpdec/numbertheory.c \
	Modules/_decimal/libmpdec/sixstep.c \
	Modules/_decimal/libmpdec/transpose.c \
	Modules/_io/_iomodule.c \
	Modules/_io/bufferedio.c \
	Modules/_io/bytesio.c \
	Modules/_io/fileio.c \
	Modules/_io/iobase.c \
	Modules/_io/stringio.c \
	Modules/_io/textio.c \
	Modules/_multiprocessing/multiprocessing.c \
	Modules/_multiprocessing/semaphore.c \
	Modules/_sqlite/cache.c \
	Modules/_sqlite/connection.c \
	Modules/_sqlite/cursor.c \
	Modules/_sqlite/microprotocols.c \
	Modules/_sqlite/module.c \
	Modules/_sqlite/prepare_protocol.c \
	Modules/_sqlite/row.c \
	Modules/_sqlite/statement.c \
	Modules/_sqlite/util.c \
	Modules/cjkcodecs/_codecs_cn.c \
	Modules/cjkcodecs/_codecs_hk.c \
	Modules/cjkcodecs/_codecs_iso2022.c \
	Modules/cjkcodecs/_codecs_jp.c \
	Modules/cjkcodecs/_codecs_kr.c \
	Modules/cjkcodecs/_codecs_tw.c \
	Modules/cjkcodecs/multibytecodec.c \
	Modules/expat/xmlparse.c \
	Modules/expat/xmlrole.c \
	Modules/expat/xmltok.c

OBJECTS_SRC := \
	Objects/abstract.c \
	Objects/accu.c \
	Objects/boolobject.c \
	Objects/bytearrayobject.c \
	Objects/bytes_methods.c \
	Objects/bytesobject.c \
	Objects/capsule.c \
	Objects/cellobject.c \
	Objects/classobject.c \
	Objects/codeobject.c \
	Objects/complexobject.c \
	Objects/descrobject.c \
	Objects/dictobject.c \
	Objects/enumobject.c \
	Objects/exceptions.c \
	Objects/fileobject.c \
	Objects/floatobject.c \
	Objects/frameobject.c \
	Objects/funcobject.c \
	Objects/genobject.c \
	Objects/iterobject.c \
	Objects/listobject.c \
	Objects/longobject.c \
	Objects/memoryobject.c \
	Objects/methodobject.c \
	Objects/moduleobject.c \
	Objects/namespaceobject.c \
	Objects/object.c \
	Objects/obmalloc.c \
	Objects/rangeobject.c \
	Objects/setobject.c \
	Objects/sliceobject.c \
	Objects/structseq.c \
	Objects/tupleobject.c \
	Objects/typeobject.c \
	Objects/unicodectype.c \
	Objects/unicodeobject.c \
	Objects/weakrefobject.c

PARSER_SRC := \
	Parser/acceler.c \
	Parser/bitset.c \
	Parser/firstsets.c \
	Parser/grammar.c \
	Parser/grammar1.c \
	Parser/listnode.c \
	Parser/metagrammar.c \
	Parser/myreadline.c \
	Parser/node.c \
	Parser/parser.c \
	Parser/parsetok.c \
	Parser/tokenizer.c

PYTHON_SRC := \
	Python/_warnings.c \
	Python/asdl.c \
	Python/ast.c \
	Python/bltinmodule.c \
	Python/ceval.c \
	Python/codecs.c \
	Python/compile.c \
	Python/dtoa.c \
	Python/dynamic_annotations.c \
	Python/dynload_shlib.c \
	Python/errors.c \
	Python/fileutils.c \
	Python/formatter_unicode.c \
	Python/frozen.c \
	Python/frozenmain.c \
	Python/future.c \
	Python/getargs.c \
	Python/getcompiler.c \
	Python/getcopyright.c \
	Python/getopt.c \
	Python/getplatform.c \
	Python/getversion.c \
	Python/graminit.c \
	Python/import.c \
	Python/importdl.c \
	Python/marshal.c \
	Python/modsupport.c \
	Python/mysnprintf.c \
	Python/mystrtoul.c \
	Python/peephole.c \
	Python/pyarena.c \
	Python/pyctype.c \
	Python/pyfpe.c \
	Python/pymath.c \
	Python/pystate.c \
	Python/pystrcmp.c \
	Python/pystrtod.c \
	Python/Python-ast.c \
	Python/pythonrun.c \
	Python/pytime.c \
	Python/random.c \
	Python/structmember.c \
	Python/symtable.c \
	Python/sysmodule.c \
	Python/thread.c \
	Python/traceback.c

LOCAL_SRC_FILES := $(MODULES_SRC) + $(OBJECTS_SRC) + $(PARSER_SRC) + $(PYTHON_SRC)
LOCAL_SRC_FILES += config.c android.c

include $(BUILD_STATIC_LIBRARY)
