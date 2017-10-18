#!/usr/bin/perl
#
# Build DockShootingTest
#

use strict;
use warnings;
use Cwd;

my $CURRENT_DIR = cwd();
my $DOS_TO_UNIX = "dos2unix.pl";
my $OUTPUT_NAME = "main.elf";


printf("rm $OUTPUT_NAME\n");
system(sprintf("rm $OUTPUT_NAME"));
printf("$OUTPUT_NAME deleted!\n\n");

printf("./$DOS_TO_UNIX\n");
system("./$DOS_TO_UNIX");

system(sprintf("make"));
printf("Compilation finished.\n\n");

system("./$OUTPUT_NAME");