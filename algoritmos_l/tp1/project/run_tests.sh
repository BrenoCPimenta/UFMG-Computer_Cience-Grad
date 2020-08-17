EXEC=$1
TMP_OUT=tp3.out

for i in {1..2..1}; do
  testIN=$(printf "%02d" $i)
  testOUT=$(printf "%02d" $i)
  $EXEC < tests/$testIN.in > $TMP_OUT 
  if ! diff -qwB tests/$testOUT.ou $TMP_OUT &>/dev/null; then
    echo "Test $testIN failed"
  else
    echo "Test $testIN  passed"
  fi
done
rm $TMP_OUT
rm tp1
