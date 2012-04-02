use strict;
use warnings;

sub main {
    open FH, $ARGV[0];
    my @lines = <FH>;
    close FH;
    if ($#ARGV > 0 and $ARGV[1]) {
        return;
    }
    my $concatenated = join '', @lines;
}

main();

