#!/bin/bash

import ctypes
import datetime
from model.CollegeClass import CollegeClass


UNIVERSEty = ctypes.CDLL('./c_lib/shared/UNIVERSIty.so')

rooms, timelines,  teachers, college_classes = [], [], [], []
matriz_data = []
file_name = "import/cc.uni"


def load_file():
    try:
        with open(file_name) as file_data:
            len_insert = 0
            for line in file_data:
                parts = line.strip().split(',')
                if len(parts) == 4:
                    college_classes.append(CollegeClass(*parts[0:3]))
                    teachers.append(parts[3])
                    len_insert+=1
                elif len(parts)!=1:
                    print(f"line {len_insert} error (should be 4 elements comma separated)")
                    raise Exception("file format exception")

            print(f"{len_insert} itens loaded!")


    except FileNotFoundError:
        print('File ' + file_name + 'does not exist.')
    except Exception as e:
        print(e)


def main():
    print("Loading file...")
    load_file()
    print("[NOTE] this app verion assumes that there is a room for each class")


if __name__ == "__main__":
    main()
