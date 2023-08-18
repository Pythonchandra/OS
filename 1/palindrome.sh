#!/bin/bash
echo "enter a string to reverse"
echo
read str1
echo "The reverse of the string using inbuilt fuction is:"
echo $str1|rev
length=${#str1}

# Generic reversal method through looping to find the reverse of string

for((i=$length-1;i>=0;i--))
do
Rev=$Rev${str1:$i:1}
done
echo "the reverse of the string using loop is"
echo $Rev
echo "to check whether the input string is palindrome or not"
if [[ $str1 = $Rev ]];
then echo "$str1 is a palindrome"
else
echo "$str1 is not a palindrome"
fi
