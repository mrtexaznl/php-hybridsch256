<?php

$i = pack("H*", "01000000f615f7ce3b4fc6b8f61e8f89aedb1d0852507650533a9e3b10b9bbcc30639f279fcaa86746e1ef52d3edb3c4ad8259920d509bd073605c9bf1d59983752a6b06b817bb4ea78e011d012d59d4");

$value=hybrid_scrypt_hash256($i);


echo "hybrid_scrypt_hash256: ".   bin2hex($value)."\n";


?>
