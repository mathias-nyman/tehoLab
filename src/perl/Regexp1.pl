#
# Regexp1.pl
#
# Created by Jukka Aro on 14.3.2012.
#

sub regexp_match{
	open FILE, $_[0] or die $!;
	if($_[1] == 1){
		$regexp = qr/\d+|\w+\d+\./;
	}
	else{
		$regexp = qr/\d+/;
	}
	$count = 0;
	while(<FILE>){
		if(/$regexp/){
			$count++;
		}
	}
	close(FILE);
	print $count;
}

#program entry:

if($#ARGV > 1){
	die "Illegal number of arguments";
}
$or = 0;
if($#ARGV == 1 && $ARGV[1] == "--with-or-operator"){
	$or = 1;
}

regexp_match($ARGV[0], $or);
