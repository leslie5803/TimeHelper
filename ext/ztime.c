
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "ztime.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *ztime_helper_ce;

ZEND_DECLARE_MODULE_GLOBALS(ztime)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(ztime)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(ZTime_Helper);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(ztime)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_ztime_globals *ztime_globals TSRMLS_DC)
{
	ztime_globals->initialized = 0;

	/* Cache Enabled */
	ztime_globals->cache_enabled = 1;

	/* Recursive Lock */
	ztime_globals->recursive_lock = 0;

	/* Static cache */
	memset(ztime_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_ztime_globals *ztime_globals TSRMLS_DC)
{
	
}

static PHP_RINIT_FUNCTION(ztime)
{
	zend_ztime_globals *ztime_globals_ptr;
#ifdef ZTS
	tsrm_ls = ts_resource(0);
#endif
	ztime_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(ztime_globals_ptr TSRMLS_CC);
	zephir_initialize_memory(ztime_globals_ptr TSRMLS_CC);

	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(ztime)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(ztime)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_ZTIME_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_ZTIME_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_ZTIME_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_ZTIME_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_ZTIME_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(ztime)
{
	php_zephir_init_globals(ztime_globals TSRMLS_CC);
	php_zephir_init_module_globals(ztime_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(ztime)
{
	
}


zend_function_entry php_ztime_functions[] = {
	ZEND_FE_END

};

static const zend_module_dep php_ztime_deps[] = {
	
	ZEND_MOD_END
};

zend_module_entry ztime_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	php_ztime_deps,
	PHP_ZTIME_EXTNAME,
	php_ztime_functions,
	PHP_MINIT(ztime),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(ztime),
#else
	NULL,
#endif
	PHP_RINIT(ztime),
	PHP_RSHUTDOWN(ztime),
	PHP_MINFO(ztime),
	PHP_ZTIME_VERSION,
	ZEND_MODULE_GLOBALS(ztime),
	PHP_GINIT(ztime),
	PHP_GSHUTDOWN(ztime),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(ztime),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_ZTIME
ZEND_GET_MODULE(ztime)
#endif
