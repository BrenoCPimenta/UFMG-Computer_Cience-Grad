EXEC=$1
TMP_OUT=$2

for i in {1..10..1}; do
  testname=$(printf "%02d" $i)
  $EXEC < timeTest/comNome/$testname.t > $TMP_OUT
  echo "Medindo tempo com nome $testname"
  time -f %U ./tp2 > /dev/null
done &>tempos_com_nome.csv
rm $TMP_OUT
