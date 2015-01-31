#War Games
> "A strange game. The only winning move is not to play."

This project is defined in project1.txt

Because our score is calculated as (path length)*(exec time), I've
found that returning a random path is the best way get a high score.

So, accordingly this program finds 3 random paths and returns the
shortest.

I chose 3 as the number of threads to run because the server that our
program is tested on doubled the execution time for threads > 3.

To Build:
```bash
git clone https://github.com/Gwydir8/WarGames.git ~/WarGames
cd ~/WarGames
make all
```
Note: you need a version of g++ that supports -std=c++14. On OS X use homebrew.

To Test:
```bash
time ./a.out < test/1000.txt
```
