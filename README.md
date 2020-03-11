# Spotify Music Sorter

Project that sorts music by Artist and then by music name made in C for UFJF Data Structures class.

## Getting Started

- Create folder data
- Insert top2018.csv file in it so the path looks like ../data/top2018.csv
- Open folder src 
- Execute command gcc main.c -o main
- Execute ./main to run the sorters

A hundred instances of Music will be created and then sorted by Insertion sort and Mergesort. By the end of each execution a file will be created on the data folder as follows:
- data/spotify_nameofthesorter.csv

The whole proccess can be observed as it also prints all the steps of reading, sorting and writing on the command line interface.

## Downsides
- This work doesn't work with CSV elements with multi-valued attributes. This will result in bugs on the parsing of the CSV elements.

## Author

* **Jonas Gabriel Maia**