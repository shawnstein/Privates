Privates
====

Release Dates:
  GitHub Tool: 	09-05-2014


GitHub:
git add * && git commit -m "Kommentar" && git push origin master

average compile setup with debug:
cc src/main.c -g -std=c99 -o bin/a.out && gdb ./bin/a.out

average compile setup without debug:
cc src/main.c -g -std=c99 -o bin/a.out && ./bin/a.out 