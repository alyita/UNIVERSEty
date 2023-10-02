#!/bin/bash

import ctypes
import datetime


UNIVERSEty = ctypes.CDLL('./c_lib/shared/UNIVERSIty.so')

rooms, timelines,  teachers, college_classes = [], [], [], []
#matriz_data = []
file_name = "data.txt"


def load_file():
    try:
        with open(file_name) as file_data
        for line in file_data:
            parts = line.strip().split(',')
            if len(parts) == 4:
                college_classes.append(CollegeClass(parts[0:3]))
                teachers.append(parts[1])
                teachers.append(parts[2])
                teachers.append(parts[3])
            else:
                print("(should be 4 elements comma separated):", line.strip())


    except FileNotFoundError:
        print('File ' + file_name + 'does not exist.')
    except Exception as e:
        print(e)


def main():
    load_file()
    if len(matriz_data) == 0:
        print("no data loaded from file. wanna insert manually the data?")
        return

    #for line in matriz_data:


    
            


if __name__ == "__main__":
    main()
