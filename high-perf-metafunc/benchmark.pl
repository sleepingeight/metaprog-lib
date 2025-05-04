#!/usr/bin/perl

use strict;
use warnings;

if ($#ARGV < 0) {
    print STDERR "specify the number of compilations";
    print STDERR "#ARGV:".$#ARGV;
    exit 1;
}

my $n_compilations = $ARGV[0];
my $input = $ARGV[1];

sub trim {
    my $str = shift;
    $str =~ s/^\s+|\s+$//;
    return $str;
}


sub benchmark {
    my $compiler = shift;
    my ($baseline, $eager, $lazy, $composed, 
        $composed_fasttrack, $composed_defaults,
        $composed_selection, $composed_selection1024);

	print("========= $compiler x $n_compilations ==========\n");
	eval "\$baseline = ".trim(`/usr/bin/time --format "%U + %S" ./build_$compiler.sh main.cpp $n_compilations 0 $input 2>&1`);
	printf("baseline: %.3fs\n", $baseline);

	# eval "\$eager = ".trim(`/usr/bin/time --format "%U + %S" ./build_$compiler.sh main.cpp $n_compilations 1 $input 2>&1`);
	# printf("eager - baseline: %.3fs\n",$eager-$baseline);

	eval "\$lazy = ".trim(`/usr/bin/time --format "%U + %S" ./build_$compiler.sh main.cpp $n_compilations 2 $input 2>&1`);
	printf("lazy - baseline: %.3fs\n",$lazy-$baseline);

    # eval "\$composed = ".trim(`/usr/bin/time --format "%U + %S" ./build_$compiler.sh main.cpp $n_compilations 3 $input 2>&1`);
	# printf("composed - baseline: %.3fs\n",$composed-$baseline);

    # eval "\$composed_fasttrack = ".trim(`/usr/bin/time --format "%U + %S" ./build_$compiler.sh main.cpp $n_compilations 4 $input 2>&1`);
	# printf("composed_fasttrack - baseline: %.3fs\n",$composed_fasttrack-$baseline);

    # eval "\$composed_defaults = ".trim(`/usr/bin/time --format "%U + %S" ./build_$compiler.sh main.cpp $n_compilations 5 $input 2>&1`);
	# printf("composed_defaults - baseline: %.3fs\n",$composed_defaults-$baseline);

    # eval "\$composed_selection = ".trim(`/usr/bin/time --format "%U + %S" ./build_$compiler.sh main.cpp $n_compilations 6 $input 2>&1`);
	# printf("composed_selection - baseline: %.3fs\n",$composed_selection-$baseline);

    eval "\$composed_selection1024 = ".trim(`/usr/bin/time --format "%U + %S" ./build_$compiler.sh main.cpp $n_compilations 7 $input 2>&1`);
	printf("composed_selection1024 - baseline: %.3fs\n",$composed_selection1024-$baseline);

}


benchmark("gcc");
# benchmark("clang");

`rm a.out`
