#
# Regexp1.pl
#
# Created by Jukka Aro on 14.3.2012.
#

sub regexp_match{
	open FILE, $_[0] or die $!;
	if($_[2] == 0){
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
	}
	else{
		while(<FILE>){}
	}
	close(FILE);
}

#program entry:

if($#ARGV > 2){
	die "Illegal number of arguments";
}

$or = 0;
$dry_run = 0;

if($#ARGV == 1){
	if($ARGV[1] eq "--with-or-operator"){
		$or = 1;
	}
	elsif($ARGV[1] eq "--dry-run"){
		$dry_run = 1;
	}
	else{
		die "Illegal argument: ".$ARGV[1];
	}
}
if($#ARGV == 2){
	if($ARGV[1] eq "--with-or-operator" && $ARGV[2] eq "--dry-run"){
		$or = 1;
		$dry_run = 1;
	}
	else{
		die "Illegal arguments: ".$ARGV[1]." ".$ARGV[2];
	}
}

regexp_match($ARGV[0], $or, $dry_run);
