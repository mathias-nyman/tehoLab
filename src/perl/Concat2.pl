use strict;
use warnings;
use Time::HiRes;

sub main {
    open FH, $ARGV[0];
    my @lines = <FH>;
    close FH;
    if ($#ARGV > 1 and $ARGV[1]) {
        return;
    }
    my $concatenated = join '', @lines;
}

my $start = Time::HiRes::gettimeofday();
main();
my $end = Time::HiRes::gettimeofday();
my ($user, $system, $child_user, $child_system) = times;
print join ' ', ($user, $system, $child_user, $child_system, ($end - $start)), "\n"

