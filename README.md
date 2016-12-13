# testInRefCounter [![Build Status](https://travis-ci.org/cbkmephisto/testInRefCounter.svg?branch=master)](https://travis-ci.org/cbkmephisto/testInRefCounter)
- This program counts how many entries in TST_file were in REF_file.
- For efficiency, it is strongly recommended to set smaller file as REF, i.e. as 1st parameter.
- If given 2 parameters, the IDs in common will be displayed on screen.

## Compile
```
g++ testInRefCounter.cpp -o testInRefCounter
```
## Install
Copy/move the executable to somewhere in your PATH environment variable.

## Usage example
```
$ testInRefCounter SNP_IDs.abg50kASAno30 SNPxref /Volumes/data/m-maps/map.*
           53034 in REF SNP_IDs.abg50kASAno30
          108402 in TST SNPxref                                         106068     MATCHES  
          325887 in TST /Volumes/data/m-maps/map.100k                   46986      MATCHES  
          452046 in TST /Volumes/data/m-maps/map.150k                   47221      MATCHES  
           79377 in TST /Volumes/data/m-maps/map.26k                    25322      MATCHES  
          175137 in TST /Volumes/data/m-maps/map.50k                    53034      MATCHES  
           20739 in TST /Volumes/data/m-maps/map.7k                     6629       MATCHES  
           26433 in TST /Volumes/data/m-maps/map.9k                     7959       MATCHES  
          326532 in TST /Volumes/data/m-maps/map.BOS1                   0          MATCHES  
          230025 in TST /Volumes/data/m-maps/map.GGPHD                  27675      MATCHES  
          412878 in TST /Volumes/data/m-maps/map.GGPUHD                 40404      MATCHES  
         2335272 in TST /Volumes/data/m-maps/map.HD                     48000      MATCHES  
           77385 in TST /Volumes/data/m-maps/map.SuperLD                8222       MATCHES  
```
