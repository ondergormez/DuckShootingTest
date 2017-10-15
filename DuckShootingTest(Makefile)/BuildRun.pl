#!/usr/bin/perl
#
# Build DockShootingTest
#

use strict;
use warnings;
use Config;
use Cwd;

my $CURRENT_DIR = cwd();
my $COMPILER = "g++";
my $LIBRARIES = "-pthread";
my $FILE_TO_COMPILED = "mutex_recrusive.cpp";
my $OUTPUT_NAME = "mutex_recrusive";

my $cmd = sprintf("$COMPILER $LIBRARIES $FILE_TO_COMPILED -o $OUTPUT_NAME");
printf("$cmd\n");
system($cmd);
printf("\nCompilation Successful. Running Application.\n\n");
system("$CURRENT_DIR/$OUTPUT_NAME");