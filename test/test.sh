#! /bin/bash

BLACK=$(tput setaf 0)
RED=$(tput setaf 1)
GREEN=$(tput setaf 2)
YELLOW=$(tput setaf 3)
LIME_YELLOW=$(tput setaf 190)
POWDER_BLUE=$(tput setaf 153)
BLUE=$(tput setaf 4)
MAGENTA=$(tput setaf 5)
CYAN=$(tput setaf 6)
WHITE=$(tput setaf 7)
BRIGHT=$(tput bold)
NORMAL=$(tput sgr0)
BLINK=$(tput blink)
REVERSE=$(tput smso)
UNDERLINE=$(tput smul)

if [[ "$(uname)" == "Linux" ]]; then
	CHECKER="./checker_linux"
else
	CHECKER="./checker_Mac"
fi

n_lines_tot=0

while IFS= read -r line; do
	line=$(echo "$line" | xargs)
	if [[ "${line:0:1}" == "#" ]]; then
		continue
	fi
	n_lines=$(./push_swap "$line" | wc -l | xargs)
	n_lines_tot=$(($n_lines_tot + $n_lines))
	sorted_ok=$(./push_swap "$line" | $CHECKER "$line" 2>&1)
	if [[ "$sorted_ok" == "KO" ]]; then
		sorted_ok="${RED}KO${NORMAL}"
	elif [[ "$sorted_ok" == "OK" ]]; then
		sorted_ok="${GREEN}OK${NORMAL}"
	elif [[ "$sorted_ok" == "Error" ]]; then
		sorted_ok="${YELLOW}ERROR${NORMAL}"
	fi
	printf "%5d %15s %s\n" $n_lines "$line" "$sorted_ok"
done < "test/values.txt"

printf "N total of lines: %d\n" $n_lines_tot
