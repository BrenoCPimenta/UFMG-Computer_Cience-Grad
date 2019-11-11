EXEC=$1
TMP_OUT=$2

for i in {1..10..1}; do
  testname=$(printf "%02d" $i)
  $EXEC < timeTest/semNome/$testname.t > $TMP_OUT
  #if ! diff -qwB tests/$testname.out $TMP_OUT &>/dev/null; then
  echo "Medindo tempo sem nome $testname"
  /usr/bin/time -f %U ./tp2 > /dev/null
  #else
  #  echo "Test $testname passed"
  #fi
done &>tempos_sem_nome.csv
rm $TMP_OUT
