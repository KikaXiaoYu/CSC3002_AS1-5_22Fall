@REM g++ testing_shino.cpp lib.cpp -o testing_shino
@REM testing_shino.exe
@REM make p2
@REM p2.exe < q2_sample_input.txt
@REM p2.exe < xiaoyu_input.txt
@REM p2.exe < xiaoyu_input.txt >xiaoyu_output.txt
@REM p2.exe

@REM p3.exe < AirlineGraph.txt > xiaoyu_output1.txt
@REM p3.exe < AirlineGraph.txt > xiaoyu_output2.txt
@REM p3.exe < AirlineGraph.txt > xiaoyu_output3.txt
@REM p3.exe < AirlineGraph.txt > xiaoyu_output4.txt

@REM g++ pqueue.cpp lib.cpp -o out
@REM g++ stringmap.cpp lib.cpp tokenscanner.cpp -o out
g++ tttt.cpp lib.cpp simplegraph.cpp -o out
out.exe < AirlineGraph.txt > xiaoyu_output1.txt