
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/time.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(ZTime_Helper) {

	ZEPHIR_REGISTER_CLASS(ZTime, Helper, ztime, helper, ztime_helper_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(ZTime_Helper, say) {

	zval *this_ptr = getThis();


	php_printf("%s", "hello world!");

}

PHP_METHOD(ZTime_Helper, before) {

	zend_bool _1, _4, _6, _8, _10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *sec_param = NULL, _0, _2, _12, _3$$4, _5$$5, _7$$6, _9$$7, _11$$8;
	zend_long sec, ZEPHIR_LAST_CALL_STATUS, diff = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sec_param);

	if (UNEXPECTED(Z_TYPE_P(sec_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sec' must be of the type int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	sec = Z_LVAL_P(sec_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_time(&_0);
	_1 = ZEPHIR_LT_LONG(&_0, sec);
	if (!(_1)) {
		_1 = sec < 0;
	}
	if (_1) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_2);
	zephir_time(&_2);
	diff = (zephir_get_numberval(&_2) - sec);
	if (diff <= 60) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_LONG(&_3$$4, diff);
		ZEPHIR_CONCAT_VS(return_value, &_3$$4, "秒前");
		RETURN_MM();
	}
	_4 = diff > 60;
	if (_4) {
		_4 = diff < 3600;
	}
	if (_4) {
		ZVAL_LONG(&_5$$5, diff);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getmin", NULL, 1, &_5$$5);
		zephir_check_call_status();
		RETURN_MM();
	}
	_6 = diff >= 3600;
	if (_6) {
		_6 = diff < 86400;
	}
	if (_6) {
		ZVAL_LONG(&_7$$6, diff);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethour", NULL, 2, &_7$$6);
		zephir_check_call_status();
		RETURN_MM();
	}
	_8 = diff >= 86400;
	if (_8) {
		_8 = diff < 2592000;
	}
	if (_8) {
		ZVAL_LONG(&_9$$7, diff);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getday", NULL, 3, &_9$$7);
		zephir_check_call_status();
		RETURN_MM();
	}
	_10 = diff >= 2592000;
	if (_10) {
		_10 = diff < 31104000;
	}
	if (_10) {
		ZVAL_LONG(&_11$$8, diff);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getmonth", NULL, 4, &_11$$8);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZVAL_LONG(&_12, diff);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getyear", NULL, 5, &_12);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(ZTime_Helper, getMin) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *sec_param = NULL, _0, _3, _1$$4, _2$$4;
	zend_long sec, min;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sec_param);

	if (UNEXPECTED(Z_TYPE_P(sec_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sec' must be of the type int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	sec = Z_LVAL_P(sec_param);


	if (sec == 0) {
		RETURN_MM_STRING("");
	}
	ZVAL_DOUBLE(&_0, zephir_safe_div_long_long(sec, 60 TSRMLS_CC));
	min = zephir_get_intval(&_0);
	sec = (long) (zephir_safe_mod_long_long(sec, 60 TSRMLS_CC));
	if (sec > 0) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_LONG(&_1$$4, min);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_LONG(&_2$$4, sec);
		ZEPHIR_CONCAT_VSVS(return_value, &_1$$4, "分", &_2$$4, "秒前");
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_LONG(&_3, min);
	ZEPHIR_CONCAT_VS(return_value, &_3, "分前");
	RETURN_MM();

}

PHP_METHOD(ZTime_Helper, getHour) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *sec_param = NULL, _0, min, _1, _3, _2$$3;
	zend_long sec, ZEPHIR_LAST_CALL_STATUS, hour, diff;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&min);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sec_param);

	if (UNEXPECTED(Z_TYPE_P(sec_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sec' must be of the type int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	sec = Z_LVAL_P(sec_param);


	ZVAL_DOUBLE(&_0, zephir_safe_div_long_long(sec, 3600 TSRMLS_CC));
	hour = zephir_get_intval(&_0);
	diff = (long) (zephir_safe_mod_long_long(sec, 3600 TSRMLS_CC));
	ZVAL_LONG(&_1, diff);
	ZEPHIR_CALL_METHOD(&min, this_ptr, "getmin", NULL, 1, &_1);
	zephir_check_call_status();
	if (zephir_fast_strlen_ev(&min)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_LONG(&_2$$3, hour);
		ZEPHIR_CONCAT_VSV(return_value, &_2$$3, "小时", &min);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_LONG(&_3, hour);
	ZEPHIR_CONCAT_VS(return_value, &_3, "小时前");
	RETURN_MM();

}

PHP_METHOD(ZTime_Helper, getDay) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *sec_param = NULL, _0, _1;
	zend_long sec, day;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sec_param);

	if (UNEXPECTED(Z_TYPE_P(sec_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sec' must be of the type int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	sec = Z_LVAL_P(sec_param);


	ZVAL_DOUBLE(&_0, zephir_safe_div_long_long(sec, 86400 TSRMLS_CC));
	day = zephir_get_intval(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_1, day);
	ZEPHIR_CONCAT_VS(return_value, &_1, "天前");
	RETURN_MM();

}

PHP_METHOD(ZTime_Helper, getMonth) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *sec_param = NULL, _0, _1;
	zend_long sec, month;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sec_param);

	if (UNEXPECTED(Z_TYPE_P(sec_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sec' must be of the type int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	sec = Z_LVAL_P(sec_param);


	ZVAL_DOUBLE(&_0, zephir_safe_div_long_long(sec, 2592000 TSRMLS_CC));
	month = zephir_get_intval(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_1, month);
	ZEPHIR_CONCAT_VS(return_value, &_1, "月前");
	RETURN_MM();

}

PHP_METHOD(ZTime_Helper, getYear) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *sec_param = NULL, _0, _1;
	zend_long sec, year;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sec_param);

	if (UNEXPECTED(Z_TYPE_P(sec_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sec' must be of the type int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	sec = Z_LVAL_P(sec_param);


	ZVAL_DOUBLE(&_0, zephir_safe_div_double_long(zephir_safe_div_long_long(sec, 2592000 TSRMLS_CC), (double) (365) TSRMLS_CC));
	year = zephir_get_intval(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_1, year);
	ZEPHIR_CONCAT_VS(return_value, &_1, "年前");
	RETURN_MM();

}

