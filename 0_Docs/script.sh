#!/bin/bash

if [ $# -lt 1 ];
then
	echo "Erro"
	echo "Estrutura do comando:"
	echo "./paa.sh programa_executavel"
	exit 1
fi

LIMIT=7200 #tempo limite (7200s = 2h)
nome_arquivo=$1 #primeiro parametro passado
output=output.txt #fixando output

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
				"norm/3276800norm.txt"  )
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
				"aleat/3276800aleat.txt"  )
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
				"inver/3276800inver.txt"  )
#array de path para arquivos de log de norm
declare -a logNorm=( "norm/logs/10norm.txt"
				"norm/logs/20norm.txt"
				"norm/logs/40norm.txt"
				"norm/logs/80norm.txt"
				"norm/logs/100norm.txt"
				"norm/logs/200norm.txt"
				"norm/logs/400norm.txt"
				"norm/logs/800norm.txt"
				"norm/logs/1600norm.txt"
				"norm/logs/3200norm.txt"
				"norm/logs/6400norm.txt"
				"norm/logs/12800norm.txt"
				"norm/logs/25600norm.txt"
				"norm/logs/51200norm.txt"
				"norm/logs/102400norm.txt"
				"norm/logs/204800norm.txt"
				"norm/logs/409600norm.txt"
				"norm/logs/819200norm.txt"
				"norm/logs/1638400norm.txt"
				"norm/logs/3276800norm.txt"  )
#array de path para arquivos de log de aleat
declare -a logAleat=( "aleat/logs/10aleat.txt"
				"aleat/logs/20aleat.txt"
				"aleat/logs/40aleat.txt"
				"aleat/logs/80aleat.txt"
				"aleat/logs/100aleat.txt"
				"aleat/logs/200aleat.txt"
				"aleat/logs/400aleat.txt"
				"aleat/logs/800aleat.txt"
				"aleat/logs/1600aleat.txt"
				"aleat/logs/3200aleat.txt"
				"aleat/logs/6400aleat.txt"
				"aleat/logs/12800aleat.txt"
				"aleat/logs/25600aleat.txt"
				"aleat/logs/51200aleat.txt"
				"aleat/logs/102400aleat.txt"
				"aleat/logs/204800aleat.txt"
				"aleat/logs/409600aleat.txt"
				"aleat/logs/819200aleat.txt"
				"aleat/logs/1638400aleat.txt"
				"aleat/logs/3276800aleat.txt"  )
#array de path para arquivos de log de inver
declare -a logInver=( "inver/logs/10inver.txt"
				"inver/logs/20inver.txt"
				"inver/logs/40inver.txt"
				"inver/logs/80inver.txt"
				"inver/logs/100inver.txt"
				"inver/logs/200inver.txt"
				"inver/logs/400inver.txt"
				"inver/logs/800inver.txt"
				"inver/logs/1600inver.txt"
				"inver/logs/3200inver.txt"
				"inver/logs/6400inver.txt"
				"inver/logs/12800inver.txt"
				"inver/logs/25600inver.txt"
				"inver/logs/51200inver.txt"
				"inver/logs/102400inver.txt"
				"inver/logs/204800inver.txt"
				"inver/logs/409600inver.txt"
				"inver/logs/819200inver.txt"
				"inver/logs/1638400inver.txt"
				"inver/logs/3276800inver.txt"  )

STARTTIME=$(date +%s) #pega segundos atuais
k=0 #zera contador para pegar elemento de array log
for i in "${norm[@]}"
do
	for j in {0..9}
	do
		{ $(time ./$nome_arquivo 64 < "$i" > $output ) ; } 2>> ${logNorm[k]}
		ENDTIME=$(date +%s)
		DIFF=$(($ENDTIME - $STARTTIME))
		if [ "$DIFF" -ge "$LIMIT" ]
			then
				break
		#else
			#echo "$DIFF"
		fi
		echo "Norm Seconds elapsed: $DIFF"
	done
	if [ "$DIFF" -ge "$LIMIT" ]
			then
				break
	fi
	((k++))
done

STARTTIME=$(date +%s) #pega segundos atuais
k=0 #zera contador para pegar elemento de array log
for i in "${aleat[@]}"
do
	for j in {0..9}
	do
		{ $(time ./$nome_arquivo 64 < "$i" > $output ) ; } 2>> ${logAleat[k]}
		ENDTIME=$(date +%s)
		DIFF=$(($ENDTIME - $STARTTIME))
		if [ "$DIFF" -ge "$LIMIT" ]
			then
				break
		#else
			#echo "$DIFF"
		fi
		echo "Aleat Seconds elapsed: $DIFF"
	done
	if [ "$DIFF" -ge "$LIMIT" ]
			then
				break
	fi
	((k++))
done

STARTTIME=$(date +%s)
k=0
for i in "${inver[@]}"
do
	for j in {0..9}
	do
		{ $(time ./$nome_arquivo 64 < "$i" > $output ) ; } 2>> ${logInver[k]}
		ENDTIME=$(date +%s)

		DIFF=$(($ENDTIME - $STARTTIME))
		if [ "$DIFF" -ge "$LIMIT" ]
			then
				break
		#else
			#echo "$DIFF"
		fi
		echo "Inver Seconds elapsed: $DIFF"
	done
	if [ "$DIFF" -ge "$LIMIT" ]
			then
				break
	fi
	((k++))
done

#ENDTIME=$(date +%s)
echo "It takes $(($ENDTIME - $STARTTIME)) seconds to complete this task..."
