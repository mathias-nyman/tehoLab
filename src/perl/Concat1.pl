#
# Concat1.pl
#
# Created by Jukka Aro on 14.3.2012.
#

sub concatenate{
	open FILE, $_[0] or die $!;
	if($_[1] == 0) {
		$res = "";
		while(<FILE>){
			$res .= $_;
		}
	}
	else {
		while(<FILE>){}
	}
	close(FILE);
}

#program entry:

if($#ARGV > 1){
	die "Illegal number of arguments";
}
if($#ARGV == 1 && $ARGV[1] == "--dry-run"){
	$dry_run = 1;
}
else {
	$dry_run = 0;
}
concatenate($ARGV[0], $dry_run);
