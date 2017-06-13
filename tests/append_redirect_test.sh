
>>

echo hello >> hi.txt
echo green >> hi.txt
echo blahblah >> hi.txt
ls >> hi.txt


pwd >> hi.txt
pwd >> hi.txt #comment
pwd >> hi.txt #this is a comment
pwd >> hi.txt                   #comment
pwd >> hi.txt                      #this is a comment


hi.txt >> hi.txt
hi.txt >> hi.txt >> hi.txt
hi.txt >> hi.txt >> hi.txt >> hi.txt
hi.txt >> hi.txt >> hi.txt >> hi.txt >> hi.txt
hi.txt >> hi.txt >> hi.txt >> hi.txt >> hi.txt >> hi.txt

ls>>hi.txt
ls  >>hi.txt
ls  >> hi.txt
ls  >>  hi.txt
ls>>  hi.txt
ls >>  hi.txt
         ls >> hi.txt
         ls>> hi.txt
         ls>>hi.txt

>> hi.txt
hi.txt >>
        hi.txt >> hi.txt
hi.txt               >>hi.txt

cat < existingInputFile | tr A-Z a-z | tee newOutputFile1 | tr a-z A-Z > newOutputFile2
