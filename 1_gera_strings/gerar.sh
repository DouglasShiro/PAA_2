#!/bin/bash

#Nome do arquivo executavel que gera as strings
executavel=gera

#array de path para arquivos norm
declare -a norm=( "norm/10norm.txt"
		"norm/20norm.txt"
		"norm/40norm.txt"
		"norm/80norm.txt"
		"norm/100norm.txt"
		"norm/200norm.txt"
		"norm/400norm.txt"
		"norm/800norm.txt"
		"norm/1600norm.txt"
		"norm/3200norm.txt"
		"norm/6400norm.txt"
		"norm/12800norm.txt"
		"norm/25600norm.txt"
		"norm/51200norm.txt"
		"norm/102400norm.txt"
		"norm/204800norm.txt"
		"norm/409600norm.txt"
		"norm/819200norm.txt"
		"norm/1638400norm.txt"
		"norm/3276800norm.txt" )

#array de path para arquivos inver
declare -a inver=( "inver/10inver.txt"
		"inver/20inver.txt"
		"inver/40inver.txt"
		"inver/80inver.txt"
		"inver/100inver.txt"
		"inver/200inver.txt"
		"inver/400inver.txt"
		"inver/800inver.txt"
		"inver/1600inver.txt"
		"inver/3200inver.txt"
		"inver/6400inver.txt"
		"inver/12800inver.txt"
		"inver/25600inver.txt"
		"inver/51200inver.txt"
		"inver/102400inver.txt"
		"inver/204800inver.txt"
		"inver/409600inver.txt"
		"inver/819200inver.txt"
		"inver/1638400inver.txt"
		"inver/3276800inver.txt" )

#array de path para arquivos aleat
declare -a aleat=( "aleat/10aleat.txt"
		"aleat/20aleat.txt"
		"aleat/40aleat.txt"
		"aleat/80aleat.txt"
		"aleat/100aleat.txt"
		"aleat/200aleat.txt"
		"aleat/400aleat.txt"
		"aleat/800aleat.txt"
		"aleat/1600aleat.txt"
		"aleat/3200aleat.txt"
		"aleat/6400aleat.txt"
		"aleat/12800aleat.txt"
		"aleat/25600aleat.txt"
		"aleat/51200aleat.txt"
		"aleat/102400aleat.txt"
		"aleat/204800aleat.txt"
		"aleat/409600aleat.txt"
		"aleat/819200aleat.txt"
		"aleat/1638400aleat.txt"
		"aleat/3276800aleat.txt" )

#Cria arquivos norm

k=10
for i in "${norm[@]}"
do
	$(./$executavel $k norm > $i)
	case $k in
	"10")
		k=20
		;;
	"20")
		k=40
		;;
	"40")
		k=80
		;;
	"80")
		k=100
		;;
	"100")
		k=200
		;;
	"200")
		k=400
		;;
	"400")
		k=800
		;;
	"800")
		k=1600
		;;
	"1600")
		k=3200
		;;
	"3200")
		k=6400
		;;
	"6400")
		k=12800
		;;
	"12800")
		k=25600
		;;
	"25600")
		k=51200
		;;
	"51200")
		k=102400
		;;
	"102400")
		k=204800
		;;
	"204800")
		k=409600
		;;
	"409600")
		k=819200
		;;
	"819200")
		k=1638400
		;;
	"1638400")
		k=3276800
		;;
	esac
done

#Cria arquivos inver

k=10

for i in "${inver[@]}"
do
	$(./$executavel $k inver > $i)
	case $k in
	"10")
		k=20
		;;
	"20")
		k=40
		;;
	"40")
		k=80
		;;
	"80")
		k=100
		;;
	"100")
		k=200
		;;
	"200")
		k=400
		;;
	"400")
		k=800
		;;
	"800")
		k=1600
		;;
	"1600")
		k=3200
		;;
	"3200")
		k=6400
		;;
	"6400")
		k=12800
		;;
	"12800")
		k=25600
		;;
	"25600")
		k=51200
		;;
	"51200")
		k=102400
		;;
	"102400")
		k=204800
		;;
	"204800")
		k=409600
		;;
	"409600")
		k=819200
		;;
	"819200")
		k=1638400
		;;
	"1638400")
		k=3276800
		;;
	esac
done

#Cria arquivos aleat

k=10

for i in "${aleat[@]}"
do
	$(./$executavel $k aleat > $i)
	case $k in
	"10")
		k=20
		;;
	"20")
		k=40
		;;
	"40")
		k=80
		;;
	"80")
		k=100
		;;
	"100")
		k=200
		;;
	"200")
		k=400
		;;
	"400")
		k=800
		;;
	"800")
		k=1600
		;;
	"1600")
		k=3200
		;;
	"3200")
		k=6400
		;;
	"6400")
		k=12800
		;;
	"12800")
		k=25600
		;;
	"25600")
		k=51200
		;;
	"51200")
		k=102400
		;;
	"102400")
		k=204800
		;;
	"204800")
		k=409600
		;;
	"409600")
		k=819200
		;;
	"819200")
		k=1638400
		;;
	"1638400")
		k=3276800
		;;
	esac
done
