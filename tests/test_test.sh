test
test fakefile

test -e fakefile
test -f fakefile
test -d fakefile

test -e realfile
test -f realfile
test -d realfile

test -e fakedirectory
test -f fakedirectory
test -d fakedirectory

test -e realdirectory
test -f realdirectory
test -d realdirectory


test -e fakefile && echo true
test -f fakefile && echo true
test -d fakefile && echo true

test -e realfile && echo true
test -f realfile && echo true
test -d realfile && echo true


test -e fakefile || echo true
test -f fakefile || echo true
test -d fakefile || echo true

test -e realfile || echo true
test -f realfile || echo true
test -d realfile || echo true

test -e fakedirectory && echo true
test -f fakedirectory && echo true
test -d fakedirectory && echo true

test -e realdirectory && echo true
test -f realdirectory && echo true
test -d realdirectory && echo true

test -e fakedirectory || echo true
test -f fakedirectory || echo true
test -d fakedirectory || echo true

test -e realdirectory || echo true
test -f realdirectory || echo true
test -d realdirectory || echo true

test file1 file2
test -e file1 file2
test -f file1 file2
test -d file1 file2

test directory1 directory2
test -e directory1 directory2
test -f directory1 directory2
test -d directory1 directory2

