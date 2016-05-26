#!/usr/bin/env pypy

import re, os, sys

def extract_input(cmsbooklet=False, chr='@%&'): # chr sono caratteri non presenti negli input
    t = '\n'.join(open(os.path.join('testo','italian.tex'), "r").readlines())
    t = re.sub('['+chr+']','',t)
    t = re.sub('\\\}',chr[0],t)
    t = re.sub(('\exmp' if cmsbooklet else '\esempio') + '{([^}]*)}',chr[1:] + '\\1' + chr[1],t)
    t = re.sub(chr[1] + '[^' + chr[2] + ']*' + chr[1], '', chr[1] + t + chr[1])
    t = re.sub(chr[0],'}',t)
    t = re.sub('\\\{','{',t)
    t = re.sub('(['+chr[2]+'\n])\n*','\\1',t)
    t = re.sub('  *',' ',t)
    return t[1:].split(chr[2])
