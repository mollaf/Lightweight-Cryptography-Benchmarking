echo "folder, file, flash, flash_total, ram, ram_total"

find "./outputs" -name "*-AEAD*-out.txt" | grep "/size/" | sort | while read fn 
do 
    echo $(echo $fn | sed 's/\.\/outputs\///' | sed 's/size\///' | sed 's/\//,/'), \
         $(cat $fn | grep "Flash:" | sed 's/Flash: \[=* *\].*(used //' | sed 's/ bytes from .* bytes).*//'), \
         $(cat $fn | grep "Flash:" | sed 's/Flash:.*(used.*bytes from //' | sed 's/ bytes).*//'), \
         $(cat $fn | grep "RAM:" | sed 's/RAM: *\[=* *\].*(used //' | sed 's/ bytes from .* bytes).*//'), \
         $(cat $fn | grep "RAM:" | sed 's/RAM:.*(used.*bytes from //' | sed 's/ bytes).*//')
    
done