#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "php.h"

#include "crypto/hybrid.h"
 
#define PHP_MY_EXTENSION_VERSION "1.0"
#define PHP_MY_EXTENSION_EXTNAME "hybridsch256"
 
extern zend_module_entry hybridsch256_module_entry;
#define phpext_hybridsch256_ptr &hybridsch256_module_entry
 
// declaration of a custom hybrid_scrypt_hash256()
PHP_FUNCTION(hybrid_scrypt_hash256);
 
// list of custom PHP functions provided by this extension
// set {NULL, NULL, NULL} as the last record to mark the end of list
static function_entry hybridsch256_functions[] = {
    PHP_FE(hybrid_scrypt_hash256, NULL)
    {NULL, NULL, NULL}
};
 
// the following code creates an entry for the module and registers it with Zend.
zend_module_entry hybridsch256_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_MY_EXTENSION_EXTNAME,
    hybridsch256_functions,
    NULL, // name of the MINIT function or NULL if not applicable
    NULL, // name of the MSHUTDOWN function or NULL if not applicable
    NULL, // name of the RINIT function or NULL if not applicable
    NULL, // name of the RSHUTDOWN function or NULL if not applicable
    NULL, // name of the MINFO function or NULL if not applicable
#if ZEND_MODULE_API_NO >= 20010901
    PHP_MY_EXTENSION_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};
 
ZEND_GET_MODULE(hybridsch256)
 
// implementation of a custom hybrid_scrypt_hash256()


/* {{{ proto string hybrid_scrypt_hash256(string input)
* Returns the hybrid_scrypt_hash256 hash for the given input.
*
* Where;
* string $input The input, must be of length 80
*
* This function will return a hex encoded version of the binary hash.
*/

PHP_FUNCTION(hybrid_scrypt_hash256)
{

    unsigned char *input;
    int input_len;

    /* Output variables */
    char *hex;
    unsigned char *buf;

    if (zend_parse_parameters(
            ZEND_NUM_ARGS() TSRMLS_CC, "s",
            &input, &input_len
        ) == FAILURE)
    {
        return;
    }

    if (input_len != 80) {
        input_len = -1;
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "Input length must be 80");

    }

    if (input_len < 0) {
        RETURN_FALSE;
    }

    buf = (unsigned char*)safe_emalloc(1, 32, 1);

    hybridScryptHash256((const char *)input, (char *)buf);

    buf[32] = '\0';

    RETURN_STRINGL((char *)buf, 32, 0);
 
}

