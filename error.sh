

file1="1_arround_E.ber"
file2=first_line_isnt_wall_of_1.ber
file3=incorrect_symbol.ber
file4=incorrect_symbol2.ber
file5=no_consume_collect.ber
file6=no_deplacement_of_P.ber
file7=no_E_C_P.ber
file8=no_exit_way.ber
file9=no_exit_way2.ber
file10=no_rectangle.ber
file11=no_rectangle_wall_of_1.ber
file12=side_left_and_right_without_1.ber

rm final.txt

echo "******* 1 $file1" >> final.txt
valgrind ./so_long maps/bad/$file1 2> result.txt
grep "total heap" ./result.txt >> ./final.txt
grep "All heap blocks were freed" ./result.txt >> ./final.txt
grep "ERROR SUMMARY" ./result.txt >> ./final.txt
echo "" >> final.txt
echo "" >> final.txt

echo "******* 2 $file2" >> final.txt
valgrind ./so_long maps/bad/$file2 2> result.txt
grep "total heap" ./result.txt >> ./final.txt
grep "All heap blocks were freed" ./result.txt >> ./final.txt
grep "ERROR SUMMARY" ./result.txt >> ./final.txt
echo "" >> final.txt
echo "" >> final.txt

echo "******* 3 $file3" >> final.txt
valgrind ./so_long maps/bad/$file3 2> result.txt
grep "total heap" ./result.txt >> ./final.txt
grep "All heap blocks were freed" ./result.txt >> ./final.txt
grep "ERROR SUMMARY" ./result.txt >> ./final.txt
echo "" >> final.txt
echo "" >> final.txt

echo "******* 4 $file4" >> final.txt
valgrind ./so_long maps/bad/$file4 2> result.txt
grep "total heap" ./result.txt >> ./final.txt
grep "All heap blocks were freed" ./result.txt >> ./final.txt
grep "ERROR SUMMARY" ./result.txt >> ./final.txt
echo "" >> final.txt
echo "" >> final.txt

echo "******* 5 $file5" >> final.txt
valgrind ./so_long maps/bad/$file5 2> result.txt
grep "total heap" ./result.txt >> ./final.txt
grep "All heap blocks were freed" ./result.txt >> ./final.txt
grep "ERROR SUMMARY" ./result.txt >> ./final.txt
echo "" >> final.txt
echo "" >> final.txt

echo "******* 6 $file6" >> final.txt
valgrind ./so_long maps/bad/$file6 2> result.txt
grep "total heap" ./result.txt >> ./final.txt
grep "All heap blocks were freed" ./result.txt >> ./final.txt
grep "ERROR SUMMARY" ./result.txt >> ./final.txt
echo "" >> final.txt
echo "" >> final.txt

echo "******* 7 $file7" >> final.txt
valgrind ./so_long maps/bad/$file7 2> result.txt
grep "total heap" ./result.txt >> ./final.txt
grep "All heap blocks were freed" ./result.txt >> ./final.txt
grep "ERROR SUMMARY" ./result.txt >> ./final.txt
echo "" >> final.txt
echo "" >> final.txt

echo "******* 8 $file8" >> final.txt
valgrind ./so_long maps/bad/$file8 2> result.txt
grep "total heap" ./result.txt >> ./final.txt
grep "All heap blocks were freed" ./result.txt >> ./final.txt
grep "ERROR SUMMARY" ./result.txt >> ./final.txt
echo "" >> final.txt
echo "" >> final.txt

echo "******* 9 $file9" >> final.txt
valgrind ./so_long maps/bad/$file9 2> result.txt
grep "total heap" ./result.txt >> ./final.txt
grep "All heap blocks were freed" ./result.txt >> ./final.txt
grep "ERROR SUMMARY" ./result.txt >> ./final.txt
echo "" >> final.txt
echo "" >> final.txt

echo "******* 10 $file10" >> final.txt
valgrind ./so_long maps/bad/$file10 2> result.txt
grep "total heap" ./result.txt >> ./final.txt
grep "All heap blocks were freed" ./result.txt >> ./final.txt
grep "ERROR SUMMARY" ./result.txt >> ./final.txt
echo "" >> final.txt
echo "" >> final.txt

echo "******* 11 $file11" >> final.txt
valgrind ./so_long maps/bad/$file11 2> result.txt
grep "total heap" ./result.txt >> ./final.txt
grep "All heap blocks were freed" ./result.txt >> ./final.txt
grep "ERROR SUMMARY" ./result.txt >> ./final.txt
echo "" >> final.txt
echo "" >> final.txt

echo "******* 12 $file12" >> final.txt
valgrind ./so_long maps/bad/$file12 2> result.txt
grep "total heap" ./result.txt >> ./final.txt
grep "All heap blocks were freed" ./result.txt >> ./final.txt
grep "ERROR SUMMARY" ./result.txt >> ./final.txt
echo "" >> final.txt

echo "final.txt done."
echo ""

rm result.txt
