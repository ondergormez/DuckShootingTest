#!/usr/bin/perl
#
# Convert line ending to unix format
# for DockShootingTest project files

use strict;
use warnings;

system(sprintf("dos2unix ../main.cc"));
system(sprintf("dos2unix ../DuckShootingTest.cc"));
system(sprintf("dos2unix ../Utility/src/Utility.cc"));
system(sprintf("dos2unix ../Utility/src/prng_uniform.cc"));

printf("\n");
system(sprintf("dos2unix ../DuckShootingTest.hh"));
system(sprintf("dos2unix ../Utility/inc/Utility.hh"));
system(sprintf("dos2unix ../Utility/inc/prng_uniform.hh"));

printf("Dos2Unix Operation finished.\n\n");
