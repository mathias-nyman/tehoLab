#
# Concat1.pl
#
# Created by Jukka Aro on 14.3.2012.
#

sub concatenate{
	open FILE, $_[0] or die $!;
	$res = "";
	while(<FILE>){
		chomp();
		$res .= $_;
	}
	close(FILE);
}

#program entry:

if($#ARGV != 0){
	die "Illegal number of arguments";
}

concatenate($ARGV[0]);
