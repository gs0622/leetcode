#!/bin/bash
declare -A mymap
while IFS='' read -r line || [[ -n "$line" ]]; do
    words=$(echo $line|tr " " "\n")
    for word in $words; do
        mymap[$word]++
    done
done < "$1"

for i in "${mymap}"; do
    echo $i ":" ${mymap[$i]}
done
