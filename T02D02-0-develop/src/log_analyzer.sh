#!/bin/bash
echo 
read log
if [[ -f $log ]];
	then
	echo 'файл найден'
	else
	echo 'файл не найден'
	exit 1
fi
str=$(wc -l $log)
str=$(echo $str | cut -d " " -f 1)

touch time.tmp
un=$(awk '{print $1}' $log >> time.tmp)
un=$(sort time.tmp | uniq -d | wc -l)
rm time.tmp

touch work.tmp
hash=$(awk '{print $8}' $log >> work.tmp)
hash=$(sort work.tmp | uniq -u | wc -l)
rm work.tmp
echo $str $un $hash


