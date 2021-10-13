#1rst arg : nb of tests
#2nd arg : sample size

BOOL=OK
KO="KO"
tests=1
numbers=$2
GREEN='\033[1;32m'
NC='\033[0m'
avg=0
max=0

if [[ $# -ne "2" ]]
then
echo 1st argument is number of tests
echo 2nd argument is sample size
exit
fi

while [[ $BOOL == "OK" ]] ; 
do
	python3 gen_numbers.py $2
	ARGS=$(cat numbers.txt)
	#echo $ARGS
	BOOL=$(../push_swap $ARGS | ../checker_Mac $ARGS)
	nb_of_instructions=$(../push_swap $ARGS | wc -l | tr -d ' ')
	avg=$((nb_of_instructions+avg))
	#echo $nb_of_instructions
	echo -n "test $tests - "
	echo -e $GREEN$BOOL$NC
	tests=$((tests+1))

	if [[ $nb_of_instructions -gt $max ]]; then
		max=$nb_of_instructions
	fi

	if [[ $tests -eq $(($1+1)) ]]; then
		break
	fi

done

if [[ $tests -eq $(($1+1)) ]]
then
echo "NO ERROR :)"
echo
avg=$((avg/($1)))
echo AVERAGE : $avg coups
echo MAX : $max coups
else
echo $ARGS
fi
