EXEC=$1
TMP_OUT=tp3.out

echo "Teste:"
for i in {1..18..1}; do
  testIN=$(printf "%02d" $i)
  testOUT=$(printf "%02d" $i)
  $EXEC < tests/$testIN.in > tests/$testOUT.ou
done
