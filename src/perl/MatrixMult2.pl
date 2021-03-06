use strict;
use warnings;

sub main {
    open FH, $ARGV[0];
    my @lines = <FH>;
    close FH;
    my $dimension = $ARGV[1];
    my $itemType = ($#ARGV > 2 and $ARGV[2] eq '--float') ? 1:0;

    my @matrix = ();
    my $rowNum = 1;
    if ($itemType == 0) {
        foreach (@lines) {
            chomp();
            my @row = map { int } split /\s+/;
            push @matrix, [@row[0 .. $dimension - 1]];
            if ($rowNum++ == $dimension) { last; }
        }
    }
    else {
        foreach (@lines) {
            chomp();
            my @row = split /\s+/;
            push @matrix, [@row[0 .. $dimension - 1]];
            if ($rowNum++ == $dimension) { last; }
        }
    }

    #NOTE: Initializing the result matrix does not work like this:
    #        my @result = ([(0) * $dimension]) * $dimension;
    #      Although it should, shouldn't it?
    my @result = ();
    for my $i (0 .. $dimension -1) {
        for my $j (0 .. $dimension -1) {
            push @{$result[$i]}, 0;
        }
    }

    if ($#ARGV > 1 and $ARGV[2] eq '--dry-run') {
        return;
    }
    if ($#ARGV > 2 and $ARGV[3] eq '--dry-run') {
        return;
    }

    for my $i (0 .. $dimension - 1) {
        for my $j (0 .. $dimension - 1) {
            for my $k (0 .. $dimension - 1) {
                $result[$i][$j] = $result[$i][$j] + $matrix[$i][$k] * $matrix[$k][$j];
            }
        }
    }
}

main();

