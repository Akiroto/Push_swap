# Push_swap with a tester (bash script) ^u^

[![lseiller's 42 push_swap Score](https://badge42.vercel.app/api/v2/cl17xe9q2001109mmi4yrqa58/project/2476263)](https://github.com/JaeSeoKim/badge42)

To use the tester follow these step :
1. Download tester.sh in this repo. (using `wget` or `curl`)
2. You need the checker on the intra in the same directory (checker_linux or checker_Mac)
3. Set the permission (`chmod +x checker_linux tester.sh`)
4. Start with `./tester.sh`
5. Check log directory if you want some information ^^

Option :

By default this test will launch only stack with 100 and 500 numbers (and check if your push_swap sort + give your number of operation).

You can set the first number of test and the number of pass :

`./tester.sh no 5 420` <- This will test your push_swap with 5 numbers	 420 times (no valgrind).

Use yes or no if you want to disable/enable valgrind (default is yes, but the test can be very slow)

`./tester.sh no 256 100`

`./tester.sh yes 128 50`

## Bonus
This tester actually use the checker so you can give your checker to the script, compile your checker and rename it to checker_linux or checker_Mac.
While testing your checker should always write OK.
This tester don't do all the test for your checker, so you need to test your checker with incoherent value (KO, error...).


If you need help ask on your left then on your right (else come on discord/slack)
