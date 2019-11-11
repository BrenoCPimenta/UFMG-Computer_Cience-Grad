EXEC=$1
TMP_OUT=$2

for i in {1..10..1}; do
  testname=$(printf "%02d" $i)
  $EXEC < timeTest/semNome/$testname.t > $TMP_OUT
  echo "Medindo tempo sem nome $testname"
  time -f %U ./tp2 > /dev/null
done &>tempos_sem_nome.csv
rm $TMP_OUT
