echo "|||||||||||||||||||| TEST |||||||||||||||||||\n\n\n\n"
gcc -Wall -Werror -Wextra printfaux/*.c *.c -o myprintf
gcc testfolder/testfile.c -o systemprintf
echo "my printf:"
./myprintf
echo "\n\nstd printf:"
./systemprintf
echo "\n\n\n\n||||||||||||||||||||||||||||||||||||||||||||||"
