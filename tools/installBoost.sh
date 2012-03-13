#!/bin/bash

#--------------------------------------------#
# This script will install Boost v 1.47.0
# Only the following libs will be installed:
#     -regex
#--------------------------------------------#

# Variables
boost_install_dir=../ext/boost/
script_dir="$(pwd)"
tmp_dir=/tmp/$USER-boost-install
rm -rf $tmp_dir
dl_url='http://downloads.sourceforge.net/project/boost/boost/1.47.0/boost_1_47_0.tar.bz2?r=http%3A%2F%2Fwww.boost.org%2Fusers%2Fhistory%2Fversion_1_47_0.html&ts=1316593388&use_mirror=ignum'
boost_name='boost_1_47_0'
boost_tarball="$boost_name.tar.bz2"

# Download and extract
mkdir -p $tmp_dir
wget $dl_url -O $tmp_dir/$boost_tarball
cd $tmp_dir
tar --bzip2 -xvf $tmp_dir/$boost_tarball

# Configure installation
rm -rf $script_dir/$boost_install_dir
mkdir -p $script_dir/$boost_install_dir
cd $boost_name
./bootstrap.sh --prefix=$script_dir/$boost_install_dir

# Install boost
echo "NOTE: This might stall here a bit!"
./b2 --with-regex install

# Done.
exit $?

