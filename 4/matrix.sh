#!/bin/bash
matrix1=()
matrix2=()
read -p "Enter the number of rows:" rows
read -p "enter the number of columnss:" columns
echo "Enter the first matrix"
for ((i=0;i<rows;i++))
do
for ((j=0;j<columns;j++))
do
read ele
matrix1+=($ele)
done
done
echo
echo "Enter the second matrix"
for ((i=0;i<rows;i++))
do
for ((j=0;j<columns;j++))
do
read ele
matrix2+=($ele)
done
done
echo
echo "First matrix"
for ((i=0;i<rows;i++))
do
for ((j=0;j<columns;j++))
do
index=$((i*columns+j))
echo -ne "${matrix1[index]}\t"
done
echo
done
echo
echo "second matrix"
for((i=0;i<rows;i++))
do
for((j=0;j<columns;j++))
do
index=$((i*columns+j))
echo -ne "${matrix2[index]}\t"
done
echo
done
echo
k=0
matrix3=()
for((i=0;i<rows;i++))
do
for((j=0;j<columns;j++))
do
index=$((i*columns+j))
matrix3[k]=$(( ${matrix1[index]} + ${matrix2[index]} ))
k=$((k+1))
done
done
echo
echo "Addition matrix"
for((i=0;i<rows;i++))
do
for((j=0;j<columns;j++))
do
index=$((i*columns+j))
echo -ne "${matrix3[index]}\t"
done
echo
done
echo
