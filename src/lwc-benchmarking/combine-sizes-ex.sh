submissions=(ace ascon)
# submissions=(ace ascon comet drygascon elephant estate forkae gift-cofb gimli grain128aead hyena isap knot lotus-locus mixfeed orange oribatida photon-beetle pyjamask _reference_ romulus saeaes saturnin skinny sparkle spix spoc spook subterranean sundae-gift tinyjambu wage xoodyak)
configs=(os o1 o2 o3)
builds=(ENCRYPT DECRYPT BOTH)

path="./outputs/nodemcuv2/size" 
path="./outputs/uno/size" 


echo "submission,config,flash,,ram,,"
echo ",,encrypt,decrypt,both,encrypt,decrypt,both"

for submission in "${submissions[@]}"
do

    find $path -name "${submission}*-release-os-AEAD_ENCRYPT-out.txt" | sort | while read fn; do echo $fn; done;
    

    # for config in "${configs[@]}"
    # do 

    #     FLASHSIZE=""
    #     MEMORYSIZE=""

    #     for build in "${builds[@]}"
    #     do


    #         for fn in $(find $path -name "${submission}*release-${config}-AEAD_${build}-out.txt" | sort)
    #         do  
    #             fs=$(cat $fn | grep "Flash:" | sed 's/Flash: \[=* *\].*(used //' | sed 's/ bytes from .* bytes)//')
    #             FLASHSIZE="${FLASHSIZE},${fs}"
    #         done

    #         for fn in $(find $path -name "${submission}*release-${config}-AEAD_${build}-out.txt" | sort)
    #         do  
    #             fs=$(cat $fn | grep "RAM:" | sed 's/RAM: *\[=* *\].*(used //' | sed 's/ bytes from .* bytes)//')
    #             MEMORYSIZE="${MEMORYSIZE},${fs}"
    #         done

    #     done

    #     echo "${submission},${config}${FLASHSIZE}${MEMORYSIZE}"

    # done

done
