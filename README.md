php-hybridsch256
================

PHP extension module for HybridScryptHash256 algorithm


Build From Source
=================

Unix/OSX
--------

1. `phpize`
2. If on OSX; `export CFLAGS='-arch i386 -arch x86_64'`
3. `./configure --enable-hybridsch256`
4. `make`
5. `make install`
6. Add the extension to your php.ini

````
    ; Enable scrypt extension module
    extension=hybridsch256.so
````
