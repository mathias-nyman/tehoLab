#
# MatrixMult1.pl
#
# Created by Jukka Aro on 14.3.2012.
#

sub read_input{
	open FILE, $_[0] or die $!;
	@in_matrix = 0 x ($dim*$dim);
	@lines = <FILE>;

	if($_[1] == 1){
		for($i = 0; $i < $dim; $i++) {
			@tokens = split(' ', $lines[$i]);
			for($j = 0; $j < $dim; $j++) {
				$in_matrix[$dim*$i+$j] = $tokens[$j];
			}
		}
	}
	else{
		for($i = 0; $i < $dim; $i++) {
			@tokens = split(' ', $lines[$i]);
			for($j = 0; $j < $dim; $j++) {
				$in_matrix[$dim*$i+$j] = int($tokens[$j]);
			}
		}
	}
	
	close(FILE);
	@in_matrix;
}

sub multiply_matrix{
	@out_matrix = 0 x ($dim*$dim);

	for($i = 0; $i < $dim; $i++) {
		for($j = 0; $j < $dim; $j++) {
			$res = 0;
			for($k = 0; $k < $dim; $k++) {
				$res += $_[$dim*$i+$k]*$_[$dim*$k+$j];
			}
			$out_matrix[$dim*$i+$j] = $res;
		}
	}
}


#program entry:

if($#ARGV < 1 || $#ARGV > 2){
	die "Illegal number of arguments";
}

$is_float = 0;
if($#ARGV == 2 && $ARGV[2] == "--float"){
	$is_float = 1;
}
$dim = $ARGV[1];

multiply_matrix(read_input($ARGV[0], $is_float));