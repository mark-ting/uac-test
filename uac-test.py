# -*- coding: utf-8 -*-
#
# Sample script to run possible combinations of FF, Mod, and UACs.
# FOR SCIENCE!

import os
import subprocess

prog = 'uac-test.exe'
uacs = ['2', '5', '10', '20']
cycles = 10000

# Module
for i in range(2):
    # Fast Fire
    for j in range(2):
        # UAC Type        
        for uac in uacs:
            args = uac + " " + str(i) + " " + str(j) + " " + str(cycles)
            subprocess.call([prog, str(uac), str(i), str(j), str(cycles)])
            

# Because I didn't add a check for UAC2's not having modules :<
os.remove('UAC2 Mod noFF 10000.csv')
os.remove('UAC2 Mod FF 10000.csv')