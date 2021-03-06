
extern zend_class_entry *ztime_helper_ce;

ZEPHIR_INIT_CLASS(ZTime_Helper);

PHP_METHOD(ZTime_Helper, say);
PHP_METHOD(ZTime_Helper, before);
PHP_METHOD(ZTime_Helper, getMin);
PHP_METHOD(ZTime_Helper, getHour);
PHP_METHOD(ZTime_Helper, getDay);
PHP_METHOD(ZTime_Helper, getMonth);
PHP_METHOD(ZTime_Helper, getYear);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ztime_helper_before, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sec, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, sec)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ztime_helper_getmin, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ztime_helper_getmin, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sec, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, sec)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ztime_helper_gethour, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ztime_helper_gethour, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sec, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, sec)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ztime_helper_getday, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ztime_helper_getday, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sec, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, sec)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ztime_helper_getmonth, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ztime_helper_getmonth, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sec, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, sec)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ztime_helper_getyear, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ztime_helper_getyear, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sec, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, sec)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ztime_helper_method_entry) {
	PHP_ME(ZTime_Helper, say, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZTime_Helper, before, arginfo_ztime_helper_before, ZEND_ACC_PUBLIC)
	PHP_ME(ZTime_Helper, getMin, arginfo_ztime_helper_getmin, ZEND_ACC_PRIVATE)
	PHP_ME(ZTime_Helper, getHour, arginfo_ztime_helper_gethour, ZEND_ACC_PRIVATE)
	PHP_ME(ZTime_Helper, getDay, arginfo_ztime_helper_getday, ZEND_ACC_PRIVATE)
	PHP_ME(ZTime_Helper, getMonth, arginfo_ztime_helper_getmonth, ZEND_ACC_PRIVATE)
	PHP_ME(ZTime_Helper, getYear, arginfo_ztime_helper_getyear, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
