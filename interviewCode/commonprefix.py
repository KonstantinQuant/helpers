#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'commonPrefix' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts STRING_ARRAY inputs as parameter.
#
import numpy as np

def getOriginal(string):
    splitted = list()
    for char in string:
        splitted.append(char)
            
    return splitted
    
def commonPrefix(inputs):
    # Write your code here
    
    results = list()
    
    for string in inputs:
        results.append(commonPrefixForOne(getOriginal(string)))
        
    return results
    
def commonPrefixForOne(original):
    total_common_prefix_string = 0
    for i in range(len(original)):
        curr_pre = original[i:]
        curr_suff = original[:i]
        
        #print("Remove to leave suffix", curr_suff)
        #print("Suffix", curr_pre)
        
        common_length = 0
    
        print(curr_pre)
        for k in range(len(curr_pre)):
            if curr_pre[k] == original[k]:
                common_length = common_length + 1
            else:
                break
        
        total_common_prefix_string = total_common_prefix_string + common_length
        
    return total_common_prefix_string
                
        
        

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    inputs_count = int(input().strip())

    inputs = []

    for _ in range(inputs_count):
        inputs_item = input()
        inputs.append(inputs_item)

    result = commonPrefix(inputs)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()

