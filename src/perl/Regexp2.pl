use strict;
use warnings;

sub main {
    open FH, $ARGV[0];
    my @lines = <FH>;
    close FH;
    my $withOrOperator = ($#ARGV > 0 and $ARGV[1] eq '--with-or-operator') ? 1:0;
    my $amountFound = 0;

    if ($#ARGV > 0 and $ARGV[1] eq '--dry-run') {
        foreach (@lines) { }
        return;
    }
    if ($#ARGV > 1 and $ARGV[2] eq '--dry-run') {
        foreach (@lines) { }
        return;
    }

    my $pattern = qr/\d+/;
    if ($withOrOperator) {
        $pattern = qr/\d+|\w+\d+\./;
    }
    foreach (@lines) {
        $amountFound++ if (/$pattern/);
    }
}

main();

