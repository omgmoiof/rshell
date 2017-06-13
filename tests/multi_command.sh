
ls && ls
echo hi && ls
touch readme && echo hi

nonsense && echo hi

nonsense || echo hi
ls || touch readme

ls; echo hi
touch readme; echo killme
echo a || echo b && echo c

sort < hi.txt; ls; pwd
sort < hi.txt; sort < hi.txt; sort < hi.txt;
