#!/bin/sh

stack(){
	ARG=`ruby -e "puts (1..$1).to_a.shuffle.join(' ')"`
}
push_swap(){
	result=`./push_swap $ARG 2>&1`
}
valou_push_swap(){
	result=`valgrind ./push_swap $ARG 2>&1`
}
line_count(){
	wc=`echo "$result" | wc -l`
}
checker_os(){
	check=`echo "$result" | ./checker_$OS $ARG 2>&1`
	if [ "$result" = "" ]; then
		check="OK"
		wc=0
	fi
	if [ "$check" != "OK" ]; then
			count "\r$i/$pass \e[01;31;5;240mKO"
			warn "\nYour Push Swap don't sort number !\nCheck error.log to see ARG and your output."
			echo "ARG :\n\n"$ARG > log/error.log
			echo "\n\nYour output :" $result >> log/error.log
			echo $worst_test > log/worst_case_${nb}.log
			echo $best_test > log/best_case_${nb}.log
			exit "2"
	fi
}
output(){
    echo '\e[36m'"$1"'\e[0m';
}
output_darker(){
	echo '\e[34m'"$1"'\e[0m'
}
warn(){
    echo '\e[31m'"$1"'\e[0m';
}
info(){
    echo '\e[33m'"$1"'\e[0m';
}
count(){
	echo -n '\e[33m'"$1"'\e[0m';
}

valou_check(){
	i=0
	output "\nLeak test for ${1} x ${2}"
	while [ $i != ${2} ]; do
		stack "${1}"
		valou_push_swap
		valou_grep=`echo $result | grep "All heap blocks were freed -- no leaks are possible"`
		i=$((i+1))
		if [ "$valou_grep" = "" ]; then
			warn "\nMemory Leak !"
			output "Check error.log to see valgrind output"
			echo "Valgrind :\n\n$result" > log/error.log
			exit "2"
		fi
		count "\r$i/${2} \e[01;32;5;240mOK"
	done
}

basic_check(){
	i=0
	best_case=-1
	worst_case=-1
	average=0
	output "Sorting ${nb} numbers x ${pass} time"
	while [ $i != $pass ]; do
		stack "${nb}"
		push_swap
		line_count
		checker_os
		i=$((i+1))
		average=$((average+wc))
		if [ $best_case -eq -1 ] || [ $best_case -gt $wc ]; then
			best_case=$wc
			best_test=$ARG
			echo $best_test > log/best_case_${nb}.log
		fi
		if [ $worst_case -eq -1 ] || [ $worst_case -lt $wc ]; then
			worst_case=$wc
			worst_test=$ARG
			echo $worst_test > log/worst_case_${nb}.log
		fi
		count "\033[2K\r$i/$pass \e[01;32;5;240mOK \e[0mBest: $best_case Average: $((average / i)) Worst: $worst_case"
	done
	if [ "$check" = "OK" ]; then
		info "\033[2K\rBest_case : $best_case"
		info "Worst_case : $worst_case"
		average=$((average / i))
		info "Average : $average"
		echo $worst_test > log/worst_case_${nb}.log
		echo $best_test > log/best_case_${nb}.log
	fi
}

init_check(){
	clear
	output "###############################################"
	output "__________Starting test for Push_swap__________"
	output "###############################################"
	OS="`uname`"
	if [ "$OS" = Linux ]; then
		OS=linux
	elif
	[ "$OS" = Darwin ]; then
		OS=Mac
	else
		warn "You OS is \e[31;1m$OS\e[0m\e[31m, sorry your OS is unsupported...\nThis script support only Linux and MacOS"
		exit "1"
	fi
	rm -Rf log
	mkdir log
}

valou=${1:-yes}
nb=${2:-100}
pass=${3:-100}
init_check
info "___________Basic Check for Push_swap___________"
basic_check
nb=500
basic_check
output_darker "Your Best case and your Worst case are save in log directory"
if [ "$valou" = "yes" ]; then
	info "____________Leak Check for Pushswap____________"
	valou_check "0" "5"
	valou_check "3" "10"
	valou_check "5" "5"
	valou_check "100" "10"
	valou_check "500" "15"
	output_darker "\nYou don't have any Memory leak, but you should check yourself with valgrind."
fi
