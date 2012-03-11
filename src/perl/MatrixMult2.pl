use strict;
use warnings;
use Time::HiRes;

sub main {
    open FH, $ARGV[0];
    my @lines = <FH>;
    close FH;
    my $dimension = $ARGV[1];
    my $itemType = ($#ARGV > 1 and $ARGV[2] eq '--float') ? 1:0;

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

    my @result = ();
    for my $i (0 .. $dimension - 1) {
        for my $j (0 .. $dimension - 1) {
            for my $k (0 .. $dimension - 1) {
                $result[$i][$j] = $result[$i][$j] + $matrix[$i][$k] * $matrix[$k][$j];
            }
        }
    }
}

my $start = Time::HiRes::gettimeofday();
main();
my $end = Time::HiRes::gettimeofday();
my ($user, $system, $child_user, $child_system) = times;
print join ' ', ($user, $system, $child_user, $child_system, ($end - $start)), "\n"

