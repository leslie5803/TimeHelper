
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_ZTIME_H
#define PHP_ZTIME_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_ZTIME_NAME        "ztime"
#define PHP_ZTIME_VERSION     "0.0.1"
#define PHP_ZTIME_EXTNAME     "ztime"
#define PHP_ZTIME_AUTHOR      "Zephir Team"
#define PHP_ZTIME_ZEPVERSION  "0.12.8-$Id$"
#define PHP_ZTIME_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(ztime)

	int initialized;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(ztime)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(ztime)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(ztime, v)
#else
	#define ZEPHIR_GLOBAL(v) (ztime_globals.v)
#endif

#ifdef ZTS
	void ***tsrm_ls;
	#define ZEPHIR_VGLOBAL ((zend_ztime_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(ztime_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(ztime_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def ztime_globals
#define zend_zephir_globals_def zend_ztime_globals

extern zend_module_entry ztime_module_entry;
#define phpext_ztime_ptr &ztime_module_entry

#endif
