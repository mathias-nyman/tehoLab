use strict;
use warnings;
use Time::HiRes;

sub main {
    open FH, $ARGV[0];
    my @lines = <FH>;
    close FH;
    my $withOrOperator = ($#ARGV > 0 and $ARGV[1] eq '--with-or-operator') ? 1:0;
    my $amountFound = 0;
    if ($withOrOperator) {
        foreach (@lines) {
            my $n = m/\d+|\w+\d+\./g;
            $amountFound += $n;
        }
    }
    else {
        foreach (@lines) {
            my $n = m/\d+|\w+\d+\./g;
            $amountFound += $n;
        }
    }
}

my $start = Time::HiRes::gettimeofday();
main();
my $end = Time::HiRes::gettimeofday();
my ($user, $system, $child_user, $child_system) = times;
print join ' ', ($user, $system, $child_user, $child_system, ($end - $start)), "\n"

