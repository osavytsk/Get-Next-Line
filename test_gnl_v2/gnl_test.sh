#!/bin/sh

PROJ_NAME=get_next_line
PROJ_DIR=~/gnl/

RED=$(tput setaf 1)
GREEN=$(tput setaf 2)
NORMAL=$(tput sgr0)

make re

#\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\#
#\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ BASIC TESTS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\#
#\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\#

for i in `seq 1 5`;
do
	echo '\ntest_'$i
	./test_gnl test_$i 0
	if [[ $(diff ".tmp_dir/test_"$i"_res" ".resfiles/test_"$i) = "" ]]; then
		echo ${GREEN}"OK"${NORMAL}
	else
		echo ${RED}"Error"${NORMAL}
	fi
done

#///////////////////////////////////////////////////////////////////////////////#
#///////////////////////// P2P EVALUATION PART 1 ///////////////////////////////#
#///////////////////////////////////////////////////////////////////////////////#

echo '\n--P2P_Tests--'

echo '\ntest_6'
cat ./tests/test_6 | ./test_gnl test_6 1 0
if [[ $(diff ".tmp_dir/test_6_res" ".resfiles/test_6") = "" ]]; then
	echo ${GREEN}"OK"${NORMAL}
else
	echo ${RED}"Error"${NORMAL}
fi

echo '\ntest_7'
cat ./tests/test_6 | ./test_gnl test_7 2 0
if [[ $(diff ".tmp_dir/test_7_res" ".resfiles/test_7") = "" ]]; then
	echo ${GREEN}"OK"${NORMAL}
else
	echo ${RED}"Error"${NORMAL}
fi

echo '\ntest_8'
cat ./tests/test_6 | ./test_gnl test_8 10 0
if [[ $(diff ".tmp_dir/test_8_res" ".resfiles/test_8") = "" ]]; then
	echo ${GREEN}"OK"${NORMAL}
else
	echo ${RED}"Error"${NORMAL}
fi

echo '\ntest_9'
cat ./tests/test_6 | ./test_gnl test_9 20 0
if [[ $(diff ".tmp_dir/test_9_res" ".resfiles/test_9") = "" ]]; then
	echo ${GREEN}"OK"${NORMAL}
else
	echo ${RED}"Error"${NORMAL}
fi

echo '\ntest_10'
cat ./tests/test_6 | ./test_gnl test_10 22 0
if [[ $(diff ".tmp_dir/test_10_res" ".resfiles/test_10") = "" ]]; then
	echo ${GREEN}"OK"${NORMAL}
else
	echo ${RED}"Error"${NORMAL}
fi

echo '\ntest_11'
./test_gnl test_11 1
if [[ $(diff ".tmp_dir/test_11_res" ".resfiles/test_6") = "" ]]; then
	echo ${GREEN}"OK"${NORMAL}
else
	echo ${RED}"Error"${NORMAL}
fi

echo '\ntest_12'
./test_gnl test_12 2
if [[ $(diff ".tmp_dir/test_12_res" ".resfiles/test_7") = "" ]]; then
	echo ${GREEN}"OK"${NORMAL}
else
	echo ${RED}"Error"${NORMAL}
fi

echo '\ntest_13'
./test_gnl test_13 10
if [[ $(diff ".tmp_dir/test_13_res" ".resfiles/test_8") = "" ]]; then
	echo ${GREEN}"OK"${NORMAL}
else
	echo ${RED}"Error"${NORMAL}
fi

echo '\ntest_14'
./test_gnl test_14 20
if [[ $(diff ".tmp_dir/test_14_res" ".resfiles/test_9") = "" ]]; then
	echo ${GREEN}"OK"${NORMAL}
else
	echo ${RED}"Error"${NORMAL}
fi

echo '\ntest_15'
./test_gnl test_15 22
if [[ $(diff ".tmp_dir/test_15_res" ".resfiles/test_10") = "" ]]; then
	echo ${GREEN}"OK"${NORMAL}
else
	echo ${RED}"Error"${NORMAL}
fi

#\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\#
#\\\\\\\\\\\\\\\\\\\\\\\\\ P2P EVALUATION PART 2 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\#
#\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\#

echo '\n--P2P_Middle_Tests--'

echo '\ntest_16'
cat ./tests/test_16 | ./test_gnl test_16 1 0
if [[ $(diff ".tmp_dir/test_16_res" ".resfiles/test_16") = "" ]]; then
	echo ${GREEN}"OK"${NORMAL}
else
	echo ${RED}"Error"${NORMAL}
fi

echo '\ntest_17'
cat ./tests/test_16 | ./test_gnl test_17 2 0
if [[ $(diff ".tmp_dir/test_17_res" ".resfiles/test_17") = "" ]]; then
	echo ${GREEN}"OK"${NORMAL}
else
	echo ${RED}"Error"${NORMAL}
fi

echo '\ntest_18'
cat ./tests/test_16 | ./test_gnl test_18 10 0
if [[ $(diff ".tmp_dir/test_18_res" ".resfiles/test_18") = "" ]]; then
	echo ${GREEN}"OK"${NORMAL}
else
	echo ${RED}"Error"${NORMAL}
fi

echo '\ntest_19'
cat ./tests/test_16 | ./test_gnl test_19 20 0
if [[ $(diff ".tmp_dir/test_19_res" ".resfiles/test_19") = "" ]]; then
	echo ${GREEN}"OK"${NORMAL}
else
	echo ${RED}"Error"${NORMAL}
fi

echo '\ntest_20'
cat ./tests/test_16 | ./test_gnl test_20 22 0
if [[ $(diff ".tmp_dir/test_20_res" ".resfiles/test_20") = "" ]]; then
	echo ${GREEN}"OK"${NORMAL}
else
	echo ${RED}"Error"${NORMAL}
fi

echo '\ntest_21'
./test_gnl test_21 1
if [[ $(diff ".tmp_dir/test_21_res" ".resfiles/test_16") = "" ]]; then
	echo ${GREEN}"OK"${NORMAL}
else
	echo ${RED}"Error"${NORMAL}
fi

echo '\ntest_22'
./test_gnl test_22 2
if [[ $(diff ".tmp_dir/test_22_res" ".resfiles/test_17") = "" ]]; then
	echo ${GREEN}"OK"${NORMAL}
else
	echo ${RED}"Error"${NORMAL}
fi

echo '\ntest_23'
./test_gnl test_23 10
if [[ $(diff ".tmp_dir/test_23_res" ".resfiles/test_18") = "" ]]; then
	echo ${GREEN}"OK"${NORMAL}
else
	echo ${RED}"Error"${NORMAL}
fi

echo '\ntest_24'
./test_gnl test_24 20
if [[ $(diff ".tmp_dir/test_24_res" ".resfiles/test_19") = "" ]]; then
	echo ${GREEN}"OK"${NORMAL}
else
	echo ${RED}"Error"${NORMAL}
fi

echo '\ntest_25'
./test_gnl test_25 22
if [[ $(diff ".tmp_dir/test_25_res" ".resfiles/test_20") = "" ]]; then
	echo ${GREEN}"OK"${NORMAL}
else
	echo ${RED}"Error"${NORMAL}
fi

#///////////////////////////////////////////////////////////////////////////////#
#///////////////////////// P2P EVALUATION PART 3 ///////////////////////////////#
#///////////////////////////////////////////////////////////////////////////////#

echo '\n--P2P_Advanced_Tests--'

echo '\ntest_26'
./test_gnl test_26 22
if [[ $(diff ".tmp_dir/test_26_res" ".resfiles/test_26") = "" ]]; then
	echo ${GREEN}"OK"${NORMAL}
else
	echo ${RED}"Error"${NORMAL}
fi

echo '\ntest_27'
cat ./tests/test_26 | ./test_gnl test_27 1 0
if [[ $(diff ".tmp_dir/test_27_res" ".resfiles/test_27") = "" ]]; then
	echo ${GREEN}"OK"${NORMAL}
else
	echo ${RED}"Error"${NORMAL}
fi

echo '\ntest_28'
cat ./tests/test_26 | ./test_gnl test_28 2 0
if [[ $(diff ".tmp_dir/test_28_res" ".resfiles/test_28") = "" ]]; then
	echo ${GREEN}"OK"${NORMAL}
else
	echo ${RED}"Error"${NORMAL}
fi

echo '\ntest_29'
cat ./tests/test_26 | ./test_gnl test_29 22 0
if [[ $(diff ".tmp_dir/test_29_res" ".resfiles/test_29") = "" ]]; then
	echo ${GREEN}"OK"${NORMAL}
else
	echo ${RED}"Error"${NORMAL}
fi

for i in `seq 30 33`;
do
	echo '\ntest_'$i
	./test_gnl test_$i 0
	if [[ $(diff ".tmp_dir/test_"$i"_res" ".resfiles/test_"$i) = "" ]]; then
		echo ${GREEN}"OK"${NORMAL}
	else
		echo ${RED}"Error"${NORMAL}
	fi
done

#\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\#
#\\\\\\\\\\\\\\\\\\\\\\\\\ P2P EVALUATION PART 4 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\#
#\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\#

echo '\n--P2P_Error_Management--'

./return_test_gnl

#///////////////////////////////////////////////////////////////////////////////#
#///////////////////////// P2P EVALUATION PART 5 ///////////////////////////////#
#///////////////////////////////////////////////////////////////////////////////#

echo '\n--BONUS_Multiple_Fd_check--'

./multiple_fd_test
if [[ $(diff ".tmp_dir/multiple_fd_test" ".resfiles/multiple_fd_test_res") = "" ]]; then
	echo ${GREEN}"OK"${NORMAL}
else
	echo ${RED}"Error"${NORMAL}
fi

#\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\#
#\\\\\\\\\\\\\\\\\\\\\\\\\ P2P EVALUATION PART 6 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\#
#\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\#

echo "\n--BONUS_Static_Variables--"
cat ${PROJ_DIR}${PROJ_NAME}.c | grep 'static*' | tr "\t" " " | sed 's/ //1'
printf "%s" "total: "
STAT=$(cat ${PROJ_DIR}${PROJ_NAME}.c | grep 'static*' | wc -l | sed 's/ //g')
if [[ ${STAT} = '1' ]]; then
	echo ${GREEN}"1"${NORMAL}
else
	echo ${RED}${STAT}${NORMAL}
fi
