#!/bin/bash
echo 'Введите путь к файлу' 
read wayfile
if [[ -f $wayfile ]];
	then 
	echo 'файл найден'
	else 
	echo 'файл не найден'
	exit 1
fi

echo 'Введите что хотите изменить'
read word
if grep $word $wayfile;
	then
	echo 'можно менять'
	else 
	echo 'не найдено'
	exit 1
fi
echo 'введите новое значение'
read new

sed -i '' "s/${word}/${new}/g" $wayfile

time=$(date -r $wayfile +"%F %R")
size=$(wc -c $wayfile)
size=$(echo $size | cut -d ' ' -f 1)
size=$(tr -d ' ' <<< "$size")
sha=$(/usr/bin/openssl sha256 "$wayfile")
sha=$(echo "${sha}" | cut -d ' ' -f 2)
log="src/$wayfile - $size - $time - $sha - sha256"
echo $log >>files.log
