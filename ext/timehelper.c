
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "timehelper.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *timehelper_helper_ce;

ZEND_DECLARE_MODULE_GLOBALS(timehelper)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(timehelper)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(TimeHelper_Helper);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(timehelper)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_timehelper_globals *timehelper_globals TSRMLS_DC)
{
	timehelper_globals->initialized = 0;

	/* Cache Enabled */
	timehelper_globals->cache_enabled = 1;

	/* Recursive Lock */
	timehelper_globals->recursive_lock = 0;

	/* Static cache */
	memset(timehelper_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_timehelper_globals *timehelper_globals TSRMLS_DC)
{
	
}

static PHP_RINIT_FUNCTION(timehelper)
{
	zend_timehelper_globals *timehelper_globals_ptr;
#ifdef ZTS
	tsrm_ls = ts_resource(0);
#endif
	timehelper_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(timehelper_globals_ptr TSRMLS_CC);
	zephir_initialize_memory(timehelper_globals_ptr TSRMLS_CC);

	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(timehelper)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(timehelper)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_TIMEHELPER_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_TIMEHELPER_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_TIMEHELPER_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_TIMEHELPER_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_TIMEHELPER_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(timehelper)
{
	php_zephir_init_globals(timehelper_globals TSRMLS_CC);
	php_zephir_init_module_globals(timehelper_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(timehelper)
{
	
}


zend_function_entry php_timehelper_functions[] = {
	ZEND_FE_END

};

static const zend_module_dep php_timehelper_deps[] = {
	
	ZEND_MOD_END
};

zend_module_entry timehelper_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	php_timehelper_deps,
	PHP_TIMEHELPER_EXTNAME,
	php_timehelper_functions,
	PHP_MINIT(timehelper),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(timehelper),
#else
	NULL,
#endif
	PHP_RINIT(timehelper),
	PHP_RSHUTDOWN(timehelper),
	PHP_MINFO(timehelper),
	PHP_TIMEHELPER_VERSION,
	ZEND_MODULE_GLOBALS(timehelper),
	PHP_GINIT(timehelper),
	PHP_GSHUTDOWN(timehelper),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(timehelper),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_TIMEHELPER
ZEND_GET_MODULE(timehelper)
#endif
