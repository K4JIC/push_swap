#! /bin/bash

touch testfile.c
"" > testfile.c
cat $@ | grep '#include' | sort | uniq >> testfile.c
echo "int	main(void){" >> testfile.c
for f in $@; do
	echo $f
	cat $f | grep -vE "(/|return|{|}|main|#include)" >> testfile.c
done
echo "}" >> testfile.c
