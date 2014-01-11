PHP_ARG_ENABLE(hybridsch256, whether to enable HybridScryptHash256 (hybridsch256) support,
[ --enable-hybridsch256, Enable HybridScryptHash256 (hybridsch256) support])

if test $PHP_HYBRIDSCH256 != "no"; then

    PHP_REQUIRE_CXX()

    PHP_SUBST(HYBRIDSCH256_SHARED_LIBADD)
    PHP_ADD_LIBRARY(stdc++, 1, HYBRIDSCH256_SHARED_LIBADD)

    PHP_ADD_INCLUDE(crypto)
    PHP_ADD_BUILD_DIR(crypto)

    AC_DEFINE(HAVE_HYBRIDSCH256, 1, [Whether you have hybridsch256])
    PHP_NEW_EXTENSION(hybridsch256, hybridsch256_extension.c  crypto/hybrid.cpp, $ext_shared)

fi
