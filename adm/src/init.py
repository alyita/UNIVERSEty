#!/bin/bash

import ctypes
import datetime

UNIVERSEty = ctypes.CDLL('./c_lib/shared/UNIVERSIty.so')

def main():
    file_ok = UNIVERSEty.check_file_data()


if __name__ == "__main__":
    main()
