#!/bin/bash
echo "Enter the value of N "
read n
flag=0
echo "The prime numbers from 1 to $n are"
echo
for((i=2;i<=n;i++))
do
for((j=2;j<=$((i/2));j++))
do
if [[ $((i%j)) == 0 ]];
then 
flag=1
break
fi
done
if [[ $flag == 0 ]];
then echo -ne "$i\t"
fi
flag=0
done
echo
